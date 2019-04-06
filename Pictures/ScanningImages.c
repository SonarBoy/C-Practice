#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <sstream>


using namespace cv;

static void help()
{
    std::cout
        << "\n--------------------------------------------------------------------------" << std::endl
        << "This program shows how to scan image objects in OpenCV (cv::Mat). As use case"
        << " we take an input image and divide the native color palette (255) with the "  << std::endl
        << "input. Shows C operator[] method, iterators and at function for on-the-fly item address calculation."<< std::endl
        << "Usage:"                                                                       << std::endl
        << "./how_to_scan_images <imageNameToUse> <divideWith> [G]"                       << std::endl
        << "if you add a G parameter the image is processed in gray scale"                << std::endl
        << "--------------------------------------------------------------------------"   << std::endl
        << std::endl;
}

Mat& ScanImageAndReduceC(Mat& I, const uchar* table);
Mat& ScanImageAndReduceIterator(Mat& I, const uchar* table);
Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar * table);

int main( int argc, char* argv[])
{   

    //Print Out the help and do a basic validation for parameters.
    help();
    if (argc < 3)
    {
        std::cout << "Not enough parameters" << std::endl;
        return -1;
    }


    //Read the images being put in
    Mat I, J;
    if( argc == 4 && !strcmp(argv[3],"G") )
        I = imread(argv[1], IMREAD_GRAYSCALE);
    else
        I = imread(argv[1], IMREAD_COLOR);

    if (I.empty())
    {
        std::cout << "The image" << argv[1] << " could not be loaded." << std::endl;
        return -1;
    }

    
    //! [dividewith]
    int divideWith = 0; // convert our input string to number - C++ style
    std::stringstream s;
    s << argv[2];
    s >> divideWith;
    if (!s || !divideWith)
    {
        std::cout << "Invalid number entered for dividing. " << std::endl;
        return -1;
    }

    //Creation of the lookup table from text to an integer format.


    uchar table[256];
    for (int i = 0; i < 256; ++i)
       table[i] = (uchar)(divideWith * (i/divideWith));
    //! [dividewith]






    const int times = 100;
    double t;

    t = (double)getTickCount();

    for (int i = 0; i < times; ++i)
    {
        cv::Mat clone_i = I.clone();
        J = ScanImageAndReduceC(clone_i, table);
    }

    t = 1000*((double)getTickCount() - t)/getTickFrequency();
    t /= times;

    std::cout << "Time of reducing with the C operator [] (averaged for "
         << times << " runs): " << t << " milliseconds."<< std::endl;

    t = (double)getTickCount();




    for (int i = 0; i < times; ++i)
    {
        cv::Mat clone_i = I.clone();
        J = ScanImageAndReduceIterator(clone_i, table);
    }

    t = 1000*((double)getTickCount() - t)/getTickFrequency();
    t /= times;

    std::cout << "Time of reducing with the iterator (averaged for "
        << times << " runs): " << t << " milliseconds."<< std::endl;

    t = (double)getTickCount();





    for (int i = 0; i < times; ++i)
    {
        cv::Mat clone_i = I.clone();
        ScanImageAndReduceRandomAccess(clone_i, table);
    }

    t = 1000*((double)getTickCount() - t)/getTickFrequency();
    t /= times;

    std::cout << "Time of reducing with the on-the-fly address generation - at function (averaged for "
        << times << " runs): " << t << " milliseconds."<< std::endl;






    //! [table-init]
    Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for( int i = 0; i < 256; ++i)
        p[i] = table[i];
    //! [table-init]

    t = (double)getTickCount();

    for (int i = 0; i < times; ++i)
        //! [table-use]
        LUT(I, lookUpTable, J);
        //! [table-use]

    t = 1000*((double)getTickCount() - t)/getTickFrequency();
    t /= times;

    std::cout << "Time of reducing with the LUT function (averaged for "
        << times << " runs): " << t << " milliseconds."<< std::endl;
    return 0; 
}


//! [scan-c]
Mat& ScanImageAndReduceC(Mat& I, const uchar* const table)
{   

    //Depth = Returns the depth of a sparse matrix element. (Numerical Values used to represent colors)
    /*
    The method returns the identifier of the matrix element depth (the type of each individual channel). 
    For example, for a 16-bit signed 3-channel array, the method returns CV_16S
    CV_8U - 8-bit unsigned integers ( 0..255 )
    */
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);


    //Returns the number of matrix channels. (Color Chanels see 
    //https://docs.opencv.org/3.4.0/d6/d6d/tutorial_mat_the_basic_image_container.html) STORAGE METHODS!
    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i,j;
    uchar* p;

    //Cycles through all the rows and colums of the input MAT
    //While using the ptr or pointer function 
    /*
    Low-level element-access functions, special variants for 1D, 2D, 3D cases, and the generic one for n-D case.

    C++: uchar* SparseMat::ptr(int i0, bool createMissing, size_t* hashval=0)¶
    C++: uchar* SparseMat::ptr(int i0, int i1, bool createMissing, size_t* hashval=0)
    C++: uchar* SparseMat::ptr(int i0, int i1, int i2, bool createMissing, size_t* hashval=0)
    C++: uchar* SparseMat::ptr(const int* idx, bool createMissing, size_t* hashval=0)

    Parameters: 
    i0 – The first dimension index.
    i1 – The second dimension index.
    i2 – The third dimension index.
    idx – Array of element indices for multidimensional matices.
    
    createMissing – Create new element with 0 value if it does not exist in SparseMat.
    Return pointer to the matrix element. If the element is there (it is non-zero), the pointer to it is returned.
    If it is not there and createMissing=false, NULL pointer is returned. If it is not there and createMissing=true, 
    the new elementis created and initialized with 0. Pointer to it is returned. If the optional hashval pointer is not NULL, 
    the element hash value is not computed but hashval is taken instead.
    */
    for( i = 0; i < nRows; ++i)
    {
        p = I.ptr<uchar>(i);
        for ( j = 0; j < nCols; ++j)
        {
            p[j] = table[p[j]];
        }
    }
    return I;
}
//! [scan-c]

//! [scan-iterator]
Mat& ScanImageAndReduceIterator(Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);


    //Returns the number of matrix channels. (Color Chanels see 
    //https://docs.opencv.org/3.4.0/d6/d6d/tutorial_mat_the_basic_image_container.html) STORAGE METHODS!
    const int channels = I.channels();
    switch(channels)
    {
    case 1:
        {
            //Single Iterator for gray scale 
            MatIterator_<uchar> it, end;
            for( it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
                *it = table[*it];
            break;
        }
    case 3:
        {   //Multi Iterator for multiple colors
            MatIterator_<Vec3b> it, end;
            for( it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end; ++it)
            {
                (*it)[0] = table[(*it)[0]];
                (*it)[1] = table[(*it)[1]];
                (*it)[2] = table[(*it)[2]];
            }
        }

        //begin
        /*Returns the matrix iterator and sets it to the first matrix element.
        C++: template<typename _Tp> MatIterator_<_Tp> Mat::begin()*/

        //end
        /*Returns the matrix iterator and sets it to the after-last matrix element.
        C++: template<typename _Tp> MatIterator_<_Tp> Mat::end()*/

    }

    return I;
}
//! [scan-iterator]

//! [scan-random]
Mat& ScanImageAndReduceRandomAccess(Mat& I, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(I.depth() == CV_8U);

    const int channels = I.channels();
    switch(channels)
    {
    case 1:
        {
            for( int i = 0; i < I.rows; ++i)
                for( int j = 0; j < I.cols; ++j )
                    I.at<uchar>(i,j) = table[I.at<uchar>(i,j)];
            break;
        }
    case 3:
        {
         Mat_<Vec3b> _I = I;

         for( int i = 0; i < I.rows; ++i)
            for( int j = 0; j < I.cols; ++j )
               {
                   _I(i,j)[0] = table[_I(i,j)[0]];
                   _I(i,j)[1] = table[_I(i,j)[1]];
                   _I(i,j)[2] = table[_I(i,j)[2]];
            }
         I = _I;
         break;
        }
    }

    return I;
}
//! [scan-random]
