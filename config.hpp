// Coupler: OnePointCoupler
#define COUPLER OnePointCoupler

// FitnessCalculator: AbsoluteFitnessCalculator
#define FITNESS_CALCULATOR AbsoluteFitnessCalculator

// InitialGenerator: RandomInitialGenerator
#define INITIAL_GENERATOR RandomInitialGenerator
#define POPULATION_SIZE 100

// MutationMaker: NoMutationMaker
#define MUTATION_MAKER NoMutationMaker

// ParentChooser: RandomParentChooser
#define PARENT_CHOOSER RandomParentChooser
#define PARENT_COUNT 50

// SolutionKiller: WorstSolutionKiller
#define SOLUTION_KILLER WorstSolutionKiller

// Stopper: TimeStopper, IterationStopper
#define STOPPER IterationStopper
#define STOPPER_DURATION 1000