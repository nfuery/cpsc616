CS 616: High Performance Computing
Fall 2023
Assignment 2: Fun with OpenMP
October 8th 2023

Table of Contents:
1. Introduction
2. Matrix Multiplication
   2.1 Serial Implementation
   2.2 Parallel Implementation
   2.3 Performance Analysis
3. Matrix Transposition
   3.1 Serial Implementation
   3.2 Parallel Implementation
   3.3 Performance Analysis
4. Overall Performance Analysis
5. Conclusion
6. Appendices
   6.1 Source Code
   6.2 Graphs
   6.3 README for Compilation and Execution
7. References

----------------
# 1. Introduction
This assignment seeks to utilize parallel programming through the use of OpenMP to demonstrate the performance benefits, as well as the potential drawbacks, when compared to serial programming. Two different programs were created, one performing matrix multiplication and one performing matrix transposition.

-------------------------
# 2. Matrix Multiplication
2.1 Serial Implementation
   The serial matrix multiplication code defines a function serialMult that performs matrix multiplication sequentially. It uses three nested loops to iterate through the rows of mat1, the columns of mat2, and the common dimension k. For each element (i, j) in the result matrix, it accumulates the result of the dot product of the corresponding rows and columns from mat1 and mat2.

2.2 Parallel Implementation
   The parallel implementation is exactly the same as the serial code except for the #prgama omp parallel for directive. The #pragma omp parallel for directive is used to parallelize the outer loop, which iterates through the rows of the result matrix. Inside the parallel region, each thread works on a subset of the rows, and then there are nested loops for the columns and the common dimension k. Each thread accumulates its partial results in the result matrix. The timer measures the execution time, and the result is printed to the console.

2.3 Performance Analysis
   Present the results of your experiments, including execution times, speedup, and efficiency for different scenarios. Discuss the impact of workload distribution and scheduling on performance.
   ![GitHub Logo](https://github.githubassets.com/images/modules/logos_page/GitHub-Mark.png)

-------------------------
# 3. Matrix Transposition
3.1 Serial Implementation
   Describe the implementation of the serial matrix transposition algorithm.

3.2 Parallel Implementation
   Explain how you parallelized the matrix transposition algorithm using OpenMP. Address race conditions and correctness.

3.3 Performance Analysis
   Present the results of your experiments for matrix transposition, similar to section 2.3.

-------------------------------
# 4. Overall Performance Analysis
Provide an overall analysis of both matrix multiplication and transposition. Discuss common trends and insights from your experiments.

-------------
# 5. Conclusion
Summarize your findings, lessons learned, and conclusions. Discuss the significance of the performance analysis results.