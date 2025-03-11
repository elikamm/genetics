CONFIGS = {
    'SEED':                 [ '42' ],
    'COUPLER':              [ 'OnePointCoupler', 'OrderCoupler', 'OrderBasedCoupler', ],
    'FITNESS_CALCULATOR':   [ 'AbsoluteFitnessCalculator', 'RelativeFitnessCalculator', ],
    'INITIAL_GENERATOR':    [ 'RandomInitialGenerator', 'HeuristicInitialGenerator', 'FixedInitialGenerator', ],
    'POPULATION_SIZE':      [ '100', ],
    'MUTATION_MAKER':       [ 'NoMutationMaker', 'SwapMutationMaker', ],
    'PARENT_CHOOSER':       [ 'RandomParentChooser', 'RouletteParentChooser', 'RankedParentChooser', ],
    'PARENT_COUNT':         [ '50', ],
    'SOLUTION_KILLER':      [ 'WorstSolutionKiller', 'WorseThanBestSolutionKiller', ],
    'STOPPER':              [ 'IterationStopper', ], # 'TimeStopper', ],
    'STOPPER_DURATION':     [ '10', ],
}

##########################################

import sys
import atexit
import itertools
import re
import time
import subprocess

def info(message):
    print('\x1b[1;34minfo:   \x1b[0;34m{}\x1b[0m'.format(message))

def error(message):
    print('\x1b[1;31merror:  \x1b[0;31m{}\x1b[0m'.format(message))

def result(message):
    print('\x1b[1;32mresult: \x1b[0;32m{}\x1b[0m'.format(message))

stored_config_file = ""

def store_config_file():
    global stored_config_file
    config_file = open('config.hpp', 'r')

    while True:
        buffer = config_file.read(1024)
        if not buffer:
            break
        stored_config_file += buffer

    config_file.close()

def restore_config_file():
    global stored_config_file
    config_file = open('config.hpp', 'w')

    config_file.write(stored_config_file)

    config_file.close()

def main(args):
    if len(args) < 2:
        error('missing instance')
        return
    instance_path = args[1]

    store_config_file()
    atexit.register(restore_config_file)

    results_file = open('results.txt', 'w')

    total_combinations = 1
    current_combination = 0
    for config in CONFIGS:
        total_combinations *= len(CONFIGS[config])

    combinations = itertools.product(*CONFIGS.values())

    for combination in combinations:
        current_combination += 1
        info(
            'testing config {}/{} ({}%)'.format(
                current_combination,
                total_combinations,
                round(current_combination / total_combinations * 100)
            )
        )

        test(dict(zip(CONFIGS.keys(), combination)), instance_path, results_file)

        time.sleep(1)

    results_file.close()

def test(combination, instance_path, results_file):
    results_file.write('==========================================\n')

    config_file = open('config.hpp', 'w')

    for config in combination:
        config_file.write('#define {} {}\n'.format(config, combination[config]))
        results_file.write('  {}: {}\n'.format(config, combination[config]))

    config_file.close()

    make_process = subprocess.run(
        [ 'make' ],
        capture_output = True,
        text = True
    )

    line_indicator = 'x'
    process_output = make_process.stdout + make_process.stderr

    if make_process.returncode != 0:
        error('compilation failed')
    else:
        solver_process = subprocess.run(
            [ 'bin/solver', instance_path ],
            capture_output = True,
            text = True
        )

        process_output = solver_process.stdout + solver_process.stderr

        if solver_process.returncode != 0:
            error('test failed')
        else:
            result('test succeeded')
            line_indicator = '>'
    
    new_line = '\n    {} '.format(line_indicator)
    process_output = re.sub(r'\x1b[^m]*m', '', process_output)
    process_output = re.sub(r'\n(?!$)', new_line, process_output)

    results_file.write('    {} {}\n'.format(line_indicator, process_output))
    results_file.flush()

if __name__ == '__main__':
    main(sys.argv)