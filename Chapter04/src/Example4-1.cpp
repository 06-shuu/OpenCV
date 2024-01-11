//Example 4-1 page 82
//Summation of a multidimensional array, done plane by plane
#include "opencv2/opencv.hpp"
#include <iostream>


int main()
{
    const int n_mat_size = 5; //3d mat size
    const int n_mat_sz[] = { n_mat_size, n_mat_size, n_mat_size }; //n_mat_sz[5,5,5]
    cv::Mat n_mat(3, n_mat_sz, CV_32FC1); //3(number of dimentions)
    cv::RNG rng; //RNG = random number generator 
    rng.fill(n_mat, cv::RNG::UNIFORM, 0.f, 1.f); //we fill n_mat with random numbers between 0 and 1
    const cv::Mat* arrays[] = { &n_mat, 0 }; //arrays containing a pointer to the n_mat matrix and a null pointer (0)
    cv::Mat my_planes[1];//of size 1
    cv::NAryMatIterator it(arrays, my_planes);

    // On each iteration, it.planes[i] will be the current plane of the
    // i-th array from 'arrays'.
     
    float s = 0.f; // Total sum over all planes
    int n = 0; // Total number of planes
    for (int p = 0; p < it.nplanes; p++, ++it) {
        s += cv::sum(it.planes[0])[0];
        n++;
    }

    std::cout << "Total sum over all planes: " << s << std::endl;
    std::cout << "Total number of planes: " << n << std::endl;

    return 0;
}