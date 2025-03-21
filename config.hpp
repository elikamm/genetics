// Seed: CURRENT_TIME, 1, 2, ...
#define SEED CURRENT_TIME

// Coupler: OnePointCoupler, OrderCoupler, OrderBasedCoupler
#define COUPLER OnePointCoupler

// FitnessCalculator: AbsoluteFitnessCalculator, RelativeFitnessCalculator
#define FITNESS_CALCULATOR RelativeFitnessCalculator

// InitialGenerator: RandomInitialGenerator, HeuristicInitialGenerator, FixedInitialGenerator
#define INITIAL_GENERATOR HeuristicInitialGenerator
#define POPULATION_SIZE 100

// MutationMaker: NoMutationMaker, SwapMutationMaker
#define MUTATION_MAKER SwapMutationMaker

// ParentChooser: RandomParentChooser, RouletteParentChooser, RankedParentChooser
#define PARENT_CHOOSER RandomParentChooser
#define PARENT_COUNT 100

// SolutionKiller: WorstSolutionKiller, WorseThanBestSolutionKiller
#define SOLUTION_KILLER WorstSolutionKiller

// Stopper: TimeStopper, IterationStopper
#define STOPPER IterationStopper
#define STOPPER_DURATION 1000