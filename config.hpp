// Coupler: OnePointCoupler, OrderCoupler, OrderBasedCoupler
#define COUPLER OnePointCoupler

// FitnessCalculator: AbsoluteFitnessCalculator, RelativeFitnessCalculator
#define FITNESS_CALCULATOR AbsoluteFitnessCalculator

// InitialGenerator: RandomInitialGenerator, HeuristicInitialGenerator, FixedInitialGenerator
#define INITIAL_GENERATOR RandomInitialGenerator
#define POPULATION_SIZE 100

// MutationMaker: NoMutationMaker, SwapMutationMaker
#define MUTATION_MAKER NoMutationMaker

// ParentChooser: RandomParentChooser, RouletteParentChooser, RankedParentChooser
#define PARENT_CHOOSER RandomParentChooser
#define PARENT_COUNT 50

// SolutionKiller: WorstSolutionKiller, WorseThanBestSolutionKiller
#define SOLUTION_KILLER WorstSolutionKiller

// Stopper: TimeStopper, IterationStopper
#define STOPPER IterationStopper
#define STOPPER_DURATION 1000