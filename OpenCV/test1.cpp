#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/opencv.hpp>
 
#define Usage() {std::cerr<<"usage: ./showpic FILE"<<std::endl;}
int main (int argc, char* argv[])
{
  if(argc !=2) Usage();
  cv::Mat img=cv::imread("w.jpeg");
  cv::imshow("window",img);
  cv::waitKey(0);
  return 0;
}

