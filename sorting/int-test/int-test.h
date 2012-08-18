#ifndef INT_TEST_H
#define INT_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <dlfcn.h>
#include <string.h>
#include <stdint.h>

int *get_array(size_t n);
void write_to_file(size_t n, double t, char *f);
double run(int *a, size_t n, int *(*sort)(int *,size_t));

#define NUM_SETS_PER_SIZE 30
#define TRIALS_PER_SET 3

#define FSTART "#   N          T          "
#define LSTART "    "
#define LSEP   "    "
#define LIBFILE "libsorting.so"
#define USAGE   "USAGE:\nint-test -l [library path (opt)] -f [function name] -o [output file (opt)]\n"

#endif
