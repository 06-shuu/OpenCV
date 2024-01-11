//Example 4-2. page:83
//Summation of two arrays using the N-ary operator
#include "opencv2/opencv.hpp"
#include <iostream>

int main() {
	const int n_mat_size = 5;
	const int n_mat_sz[] = { n_mat_size, n_mat_size, n_mat_size };
	cv::Mat n_mat0(3, n_mat_sz, CV_32FC1);
	cv::Mat n_mat1(3, n_mat_sz, CV_32FC1);
	cv::RNG rng;
	rng.fill(n_mat0, cv::RNG::UNIFORM, 0.f, 1.f);
	rng.fill(n_mat1, cv::RNG::UNIFORM, 0.f, 1.f);
	const cv::Mat* arrays[] = { &n_mat0, &n_mat1, 0 }; //ok!
	cv::Mat my_planes[2];//ok! (2 planes)
	cv::NAryMatIterator it(arrays, my_planes);
	float s = 0.f; // Total sum over all planes in both arrays
	int n = 0; // Total number of planes
	for (int p = 0; p < it.nplanes; p++, ++it) {
		s += cv::sum(it.planes[0])[0];
		s += cv::sum(it.planes[1])[0];
		n++;

		/*float* ptrs[3] = { it.planes[0].ptr<float>(), it.planes[1].ptr<float>(), my_planes[0].ptr<float>() };
		for (size_t j = 0; j < it.size; j++) {
			ptrs[2][j] = std::pow(ptrs[0][j], ptrs[1][j]);
		}*/
	}

	std::cout << "Total sum over all planes in both arrays: " << s << std::endl;
	//std::cout << "Total number of planes: " << n << std::endl;
	return 0;
}