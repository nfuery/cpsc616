/******************************************************************************
* FILE: omp_getEnvInfo.c
* DESCRIPTION:
*   OpenMP Example - Get Environment Information - C/C++ Version
*   The master thread queries and prints selected environment information.
* AUTHOR: Blaise Barney  7/06
* LAST REVISED: 07/12/06
******************************************************************************/

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
int nthreads, tid, procs, maxt, inpar, dynamic, nested;

/* Start parallel region */
#pragma omp parallel private(nthreads, tid)
  {

  /* Obtain thread number */
  tid = omp_get_thread_num();

  /* Only master thread does this */
  if (tid == 0) 
    {
    printf("Thread %d getting environment info...\n", tid);

//  Here we introduce a series of omp function calls which retrieve
//  configuration nformation about the OMP parameters/set up:
    /* Get environment information */
//  this gets the total number of processors
    procs    = omp_get_num_procs();
//  this gets the total number of current threads
    nthreads = omp_get_num_threads();
//  this gets the maximum number of available threads
    maxt     = omp_get_max_threads();
//  this reports whether the current section of code is parallelized or not
    inpar    = omp_in_parallel();
//  this reports whether or not the number of threads can be dynamically
//  adjusted during run-time
    dynamic  = omp_get_dynamic();
//  this reports whether or not nested parallelism is enabled
    nested   = omp_get_nested();

    /* Print environment information */
    printf("Number of processors = %d\n", procs);
    printf("Number of threads = %d\n", nthreads);
    printf("Max threads = %d\n", maxt);
    printf("In parallel? = %d\n", inpar);
    printf("Dynamic threads enabled? = %d\n", dynamic);
    printf("Nested parallelism enabled? = %d\n", nested);

    }

  }  /* Done */

}
