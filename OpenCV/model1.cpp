#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

#define ROWS 100
#define COLS 100 

int main()
{
    // 读取图片
    cv::Mat img = cv::imread("./2.jpeg");
    int height=img.rows, width=img.cols;
    cout<<img.size()<<" "<<height<<" "<<width<<endl;

    // 图像缩放
    Mat resized_img;
    Size newsize(ROWS,COLS);
    resize(img,resized_img,newsize); 
    cout<<resized_img.size()<<endl;
    printf("\n");

    //自定义图片
    //Mat mym(ROWS, COLS, CV_8UC3, (0,255,255)); // pblue

    // 创建窗口并显示图片
    cv::namedWindow("Image", cv::WINDOW_NORMAL);
    cv::imshow("Image", img);
    imshow("RImage", resized_img);

    // 获取像素点上的信息,有了这个就可以为所欲为了！
    Vec3b pixel;
    for (int i=0; i<ROWS; i++)
    {
        for (int j=0; j<COLS; j++)
        {
            pixel = resized_img.at<Vec3b>(i,j);
            // 0-b 1-g 2-r
            cout<<"("<<pixel[0]-'0'<<","<<pixel[1]-'0'<<","<<pixel[2]-'0'<<")"<<" ";
            resized_img.at<Vec3b>(i,j) = Vec3b(0,255,255);
        }
        printf("\n");
    }
    imshow("RRImage", resized_img);

    // 等待用户按下任意键退出程序
    cv::waitKey(0);

    return 0;
}