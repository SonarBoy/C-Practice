#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
//http://answers.opencv.org/question/1/how-can-i-get-frames-from-my-webcam/


int main(int argc, char** argv)
{

  // All Point to the same Data matrix.
  // Different Headders.
  // Modifications are felt over all objects.

    Mat A, C;

    A = imread(argv[1],IMREAD_COLOR);
    std::cout << "A = " << std::endl << " " << A << std::endl << " " << std::endl;



    Mat B(A);

    C = A;

    Mat D (A, Rect(10, 10, 100, 100) ); // using a rectangle
    Mat E = A(Range::all(), Range(1,3)); // using row and column boundaries

    // Clean up is done by the last object that used it. 

    Mat F = A.clone();
    Mat G;
    A.copyTo(G);

    /* Now modifying F or G will not affect the matrix pointed by the Mat header. What you need to remember 
    forom all this is that:

    Output image allocation for OpenCV functions is automatic (unless specified otherwise).
    You do not need to think about memory management with OpenCVs C++ interface.
    The assignment operator and the copy constructor only copies the header.
    The underlying matrix of an image may be copied using the cv::Mat::clone() and cv::Mat::copyTo() functions. */

    Mat M(7,2, CV_8UC3, Scalar(0,0,255)); 
    //ROW AND COLOUM COMBONATION.
    //The way the data type is created: CV_[The number of bits per item][Signed or Unsigned][Type Prefix]C[The channel number]
    //UC3 = Unsigned Char Type 8 Bits Long each pixel has 3 for each of the three channels. 
    std::cout << "M = " << std::endl << " " << M << std::endl << " " << std::endl;


    int sz[3] = {2,2,2};
    Mat L(3,sz, CV_8UC(1), Scalar::all(0));
    //The upper example shows how to create a matrix with more than two dimensions. 
    //Specify its dimension, then pass a pointer containing the size for each dimension and the rest remains the same

    
    M.create(3,4, CV_8UC(2));
    std::cout << "M = "<< std::endl << " "  << M << std::endl << std::endl;


    //You cannot initialize the matrix values with this construction. It will only reallocate 
    //its matrix data memory if the new size will not fit into the old one.

    Mat Test = Mat::eye(4, 4, CV_64F);
    std::cout << "E = " << std::endl << " " << Test << std::endl << std::endl;
    Mat O = Mat::ones(2, 2, CV_32F);
    std::cout << "O = " << std::endl << " " << O << std::endl << std::endl;
    Mat Z = Mat::zeros(3,3, CV_8UC1);
    std::cout << "Z = " << std::endl << " " << Z << std::endl << std::endl;

    std::cout << "Basics";
}