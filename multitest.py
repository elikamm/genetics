TESTS = {
    'COUPLER':              [ 'OnePointCoupler', ],
    'FITNESS_CALCULATOR':   [ 'AbsoluteFitnessCalculator', ],
    'INITIAL_GENERATOR':    [ 'RandomInitialGenerator', ],
    'POPULATION_SIZE':      [ '100', ],
    'MUTATION_MAKER':       [ 'NoMutationMaker', ],
    'PARENT_CHOOSER':       [ 'RandomParentChooser', ],
    'PARENT_COUNT':         [ '50', ],
    'SOLUTION_KILLER':      [ 'WorstSolutionKiller', ],
    'STOPPER':              [ 'TimeStopper', 'IterationStopper', ],
    'STOPPER_DURATION':     [ '10', ],
}

INSTANCE = 'tests/a280.txt'

##########################################

import itertools
import re
import time
import subprocess

def main():
    results = open('results.txt', 'w')

    combinations = itertools.product(*TESTS.values())

    for combination in combinations:
        test(dict(zip(TESTS.keys(), combination)), results)
        time.sleep(1)

    results.close()

def test(combination, results):
    with open('config.hpp', 'w') as config:
        for setting in combination:
            config.write('#define ' + setting + ' ' + combination[setting] + '\n')

    subprocess.run([ 'make' ])

    solver = subprocess.run(
        [ 'bin/solver', INSTANCE ],
        capture_output = True,
        text = True
    )

    results.write('==========================================\n')
    for setting in combination:
        results.write('  ' + setting + ': ' + combination[setting] + '\n')

    output = solver.stdout + solver.stderr
    output = re.sub(r'\x1b[^m]*m', '', output)
    output = re.sub(r'\n(?!$)', '\n    > ', output)

    results.write('    > ' + output + '\n')
    results.flush()

if __name__ == '__main__':
    main()