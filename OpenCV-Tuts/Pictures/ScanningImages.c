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
    Mat inputImage, outputImage;
    if( argc == 4 && !strcmp(argv[3],"G") )
        inputImage = imread(argv[1], IMREAD_GRAYSCALE);
    else
        inputImage = imread(argv[1], IMREAD_COLOR);

    if (inputImage.empty())
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






    const int TIMES = 100;
    double  ticks ;

    ticks = (double)getTickCount();

    for (int i = 0; i < TIMES; ++i)
    {
        cv::Mat clone_i = inputImage.clone();
        outputImage = ScanImageAndReduceC(clone_i, table);
    }

    ticks = 1000*((double)getTickCount() - ticks )/getTickFrequency();
    ticks /= TIMES;

    std::cout << "Time of reducing with the C operator [] (averaged for "
         << TIMES << " runs): " << ticks << " milliseconds."<< std::endl;

    ticks = (double)getTickCount();




    for (int i = 0; i < TIMES; ++i)
    {
        cv::Mat clone_i = inputImage.clone();
        outputImage = ScanImageAndReduceIterator(clone_i, table);
    }

    ticks = 1000*((double)getTickCount() - ticks )/getTickFrequency();
    ticks /= TIMES;

    std::cout << "Time of reducing with the iterator (averaged for "
        << TIMES << " runs): " << ticks << " milliseconds."<< std::endl;

    ticks = (double)getTickCount();





    for (int i = 0; i < TIMES; ++i)
    {
        cv::Mat clone_i = inputImage.clone();
        ScanImageAndReduceRandomAccess(clone_i, table);
    }

    ticks = 1000*((double)getTickCount() - ticks)/getTickFrequency();
    ticks /= TIMES;

    std::cout << "Time of reducing with the on-the-fly address generation - at function (averaged for "
        << TIMES << " runs): " << ticks << " milliseconds."<< std::endl;






    //! [table-init]
    Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for( int runner = 0; runner < 256; ++runner)
        p[runner] = table[runner];
    //! [table-init]

    ticks = (double)getTickCount();

    for (int runner = 0; runner < TIMES; ++runner)
        //! [table-use]
        LUT(inputImage, lookUpTable, outputImage);
        //! [table-use]

    ticks = 1000*((double)getTickCount() - ticks )/getTickFrequency();
    ticks /= TIMES;

    std::cout << "Time of reducing with the LUT function (averaged for "
        << TIMES << " runs): " << ticks << " milliseconds."<< std::endl;
    return 0; 
}


//! [scan-c]
Mat& ScanImageAndReduceC(Mat& inputImageRC , const uchar* const table)
{   

    //Depth = Returns the depth of a sparse matrix element. (Numerical Values used to represent colors)
    /*
    The method returns the identifier of the matrix element depth (the type of each individual channel). 
    For example, for a 16-bit signed 3-channel array, the method returns CV_16S
    CV_8U - 8-bit unsigned integers ( 0..255 )
    */
    // accept only char type matrices
    CV_Assert(inputImageRC.depth() == CV_8U);


    //Returns the number of matrix channels. (Color Chanels see 
    //https://docs.opencv.org/3.4.0/d6/d6d/tutorial_mat_the_basic_image_container.html) STORAGE METHODS!
    int channels = inputImageRC.channels();

    int nRows = inputImageRC.rows;
    int nCols = inputImageRC.cols * channels;

    if (inputImageRC.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int rowRunner,columRunner;
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
    for( rowRunner = 0; rowRunner < nRows; ++rowRunner)
    {
        p = inputImageRC.ptr<uchar>(rowRunner);
        for ( columRunner = 0; columRunner < nCols; ++columRunner)
        {
            p[columRunner] = table[p[columRunner]];
        }
    }
    return inputImageRC;
}
//! [scan-c]

//! [scan-iterator]
Mat& ScanImageAndReduceIterator(Mat& inputImageRI, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(inputImageRI.depth() == CV_8U);


    //Returns the number of matrix channels. (Color Chanels see 
    //https://docs.opencv.org/3.4.0/d6/d6d/tutorial_mat_the_basic_image_container.html) STORAGE METHODS!
    const int channels = inputImageRI.channels();
    switch(channels)
    {
    case 1:
        {
            //Single Iterator for gray scale 
            MatIterator_<uchar> it_G, end_G;
            for( it_G = inputImageRI.begin<uchar>(), end_G = inputImageRI.end<uchar>(); it_G != end_G; ++it_G)
                *it_G = table[*it_G];
            break;
        }
    case 3:
        {   //Multi Iterator for multiple colors
            MatIterator_<Vec3b> it_C, end_C;
            for( it_C = inputImageRI.begin<Vec3b>(), end_C = inputImageRI.end<Vec3b>(); it_C != end_C; ++it_C)
            {
                (*it_C)[0] = table[(*it_C)[0]];
                (*it_C)[1] = table[(*it_C)[1]];
                (*it_C)[2] = table[(*it_C)[2]];
            }
        }

        //begin
        /*Returns the matrix iterator and sets it to the first matrix element.
        C++: template<typename _Tp> MatIterator_<_Tp> Mat::begin()*/

        //end
        /*Returns the matrix iterator and sets it to the after-last matrix element.
        C++: template<typename _Tp> MatIterator_<_Tp> Mat::end()*/

    }

    return inputImageRI;
}
//! [scan-iterator]

//! [scan-random]
Mat& ScanImageAndReduceRandomAccess(Mat& inputImageRA, const uchar* const table)
{
    // accept only char type matrices
    CV_Assert(inputImageRA.depth() == CV_8U);

    const int channels = inputImageRA.channels();
    switch(channels)
    {
    case 1:
        {
            for( int rowsRunner = 0; rowsRunner < inputImageRA.rows; ++rowsRunner)
                for( int columnRunner = 0; columnRunner < inputImageRA.cols; ++columnRunner )
                    inputImageRA.at<uchar>(rowsRunner,columnRunner) = table[inputImageRA.at<uchar>(rowsRunner,columnRunner)];
            break;
        }
    case 3:
        {
         Mat_<Vec3b> _I = inputImageRA;

         for( int rowsRunner = 0; rowsRunner < inputImageRA.rows; ++rowsRunner)
            for( int columnRunner = 0; columnRunner < inputImageRA.cols; ++columnRunner )
               {
                   _I(rowsRunner,columnRunner)[0] = table[_I(rowsRunner,columnRunner)[0]];
                   _I(rowsRunner,columnRunner)[1] = table[_I(rowsRunner,columnRunner)[1]];
                   _I(rowsRunner,columnRunner)[2] = table[_I(rowsRunner,columnRunner)[2]];
            }
         inputImageRA = _I;
         break;
        }
    }

    return inputImageRA;
}
//! [scan-random]
