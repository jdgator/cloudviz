#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

Mat img, res, element;

int main(int argc, char** argv)
{
	
    //stat the window and grab user-supplied picture
    img = imread( argv[1] );

    //if there is no picture
    if ( !img.data )
    {
        printf("No image data \n");
        return -1;
    }

    //show original image
    namedWindow( "Original image", 0 );
    imshow( "Original image", img );


    //do gassian blur
    GaussianBlur(img, img, Size(5,5), 2, 2);

    //do meanshift fliter
    pyrMeanShiftFiltering( img, res, 20, 45, 3);
    imwrite("meanshift.png", res);

    //output results
    namedWindow("color segmentation", 0 );
    imshow("color segmentation", res);
 
    //do canny edge detection
    Mat gray, edge, draw;
    cvtColor(res, gray, CV_BGR2GRAY);
 
    Canny( gray, edge, 50, 150, 3);
 
    edge.convertTo(draw, CV_8U);
    namedWindow("canny edge detection", 0 );
    imshow("canny edge detection", draw);

   waitKey();

   return 0;
}
