# High-Performance-Computing-Assignments
CS301- High Performance Computing assignments,  DA-IICT.
#Conway's Game of life
Implemented and optimized game of life.
#Assignment-1
1.	Take any of your code (with some reasonable no. of functions and subroutines) and do the profiling as discussed in the class. Understand the output. Nothing to be included in the report on this exercise. 
2.	Use timer function for measuring elapsed time. Figure out what is the best available function for serial and Openmp. Nothing to be included in the report on this exercise. 

3.	Write a parallel code (openMP) for integration using trapezoidal rule. Serial code was discussed in the class. 
Use the parallel code to calculate PI (lecture 5, slide 29) and verify the implementation. In addition to 10 points discussed above, make comments about your observations and the most optimized implementation.
Start with a naïve implementation, and gradually improve it as discussed during the class (using critical, reduction etc.).
Report about the min. no changes required to convert the serial code to parallel.
Measure performance in MFLOPS/sec. 


#Assignment-2
Write a serial code and parallel code for the following (using openMP) (discussed during today’s lecture).:
1.	Calculation of pi using series (take large value of “N” for summation)
2.	Multiplication of Two vectors followed by summation. (serial and parallel comparison for accuracy of results)
3.	Matrix Multiplication (starting with simple implementation – gradually implement Block algorithm as discussed during the lecture, create n x n matrix; take n in multiples of 2 while increasing the size of matrix (go up to 528 and 1024); change size of block to see the effect.)
In addition to 10 points discussed above, make comments about your observations and the most optimized implementation.

#Assignment-3
a)	Write a serial code for twist transformation/ image warping of an image as discussed in the class (lecture-10, case study-3). Write a parallel version of this using openMP. Change the image dimension (same image) and compare the serial vs. parallel implementation.
Image Format (recommended  PPM  an acronym derived from "Portable Pixel Map". Take help of TAs if you cannot figure out the following within an hour)
You can create own input images by exporting image into PPM images. The easiest way to create image is via external tools (read the link). On Linux, look at “bmptoppm” and “convert” for conversions.


b) 	Filtering: Consider an image neighborhood surrounding each pixel is defined, and the median value (filter in this case) of this neighborhood is calculated and is used to replace the original pixel in the output image by using the following filter:
Imed [x,y] = median (Iorig [i, j] ; i, j belongs to nbor [x,y])

If you choose a square neighborhood around each pixel, defined using the half-width of the neighborhood, i.e., for a half-width of n, the number of pixels in the neighborhood would be (2n+1)^2. Any neighbors that lie outside the image domain are assigned to be that of the nearest pixel within the image boundary for calculation of median.

To start with - choose a half-width of 3 and an image of 256 x256.

Choose by yourself the important dimensions (which you feel will impact the overall speedup; e.g. image size, filter size) and show the effect of these dimensions on performance. Show your observations using plots, and support you observations with proper explanations.
In addition to 10 points discussed above, make comments about your observations and the most optimized implementation.

#Assignment-4
Write a serial code and parallel code for the following (using openMP):
·         Calculation of pi using random numbers.
·         Reduction.

In addition to 10 points discussed above, make comments about your observations and the most optimized implementation.
First use the random function of the C library for random number generations and then understand the problem of parallel random number generations using OpenMP, and what are the main issues. Report on it briefly.

#Assignment-5
Compute the inclusive prefix sum (scan) from an input array; store results in output array for different lengths of N (size of the input array). Convert the same code into an exclusive scan (e.g. option-1 – inclusive scan; option-2 exclusive scan). 

Develop a parallel version of scan using openMP. (hint: serial- Work: O(n), Span: O(n); parallel - Work: O(n), Span: 2log n )

Problem [efficient parallel filter] (do the following with both serial and parallel implementation using the above implementations):
Given an array input, produce an array output containing only elements such that filter(element) is true
Example: input [17, 4, 6, 8, 11, 5, 13, 19, 0, 24]
filter: is element > 10
output [17, 11, 13, 19, 24]
Choose an Input with length (>10^6); fill the vector with random numbers (integer) between 0-100, and do the above operation.

Things to note
– Finding elements for the output
– And also getting them in the right place.
In addition to 9 points discussed above, make comments about your observations and the most optimized implementation.

#Assignment-6
(i) Write a parallel code (using MPI directives) for integration using trapezoidal rule. Serial code and OpenMP code has been already implemented.
Use the MPI version to calculate PI and verify the implementation.  (take enough number of trapezoids to study the effect of speedup)
Run the MPI version on 4, 8 and 16 cores and compare the timings with a serial, and OpenMP version for same accuracy of PI. Which is the best implementation and what are the important observations.


