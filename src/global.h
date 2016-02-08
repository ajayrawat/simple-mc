#include "header.h"

#define TRUE 1
#define FALSE 0

// Constants
#define PI 3.1415926535898
#define D_INF DBL_MAX

// Geometry boundary conditions
#define VACUUM 0
#define REFLECT 1
#define PERIODIC 2

// Reaction types
#define TOTAL 0
#define ABSORPTION 1
#define SCATTER 2
#define FISSION 3

// Surfaces
#define X0 0
#define X1 1
#define Y0 2
#define Y1 3
#define Z0 4
#define Z1 5

// RNG streams
#define N_STREAMS 3
#define STREAM_INIT 0
#define STREAM_TRACK 1
#define STREAM_OTHER 2

// Declare main structures used throughout simulation
extern Parameters *params; // user defined parameters
extern Geometry *g; // homogenous cube geometry
extern Material *m; // problem material
extern Tally *t; // scalar flux tally
extern Bank *source_bank; // bank for particle source sites
extern Bank *fission_bank; // bank for particle fission sites

// Declare OpenMP specific variables
#ifdef _OPENMP
extern int thread_id;
extern int n_threads; // number of OpenMP threads
extern Bank *master_fission_bank; // bank for collecting fission sites from threads
#pragma omp threadprivate(fission_bank, thread_id)
#endif