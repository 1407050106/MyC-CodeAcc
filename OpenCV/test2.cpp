#include <opencv2/opencv.hpp>

int main()
{
    // 读取图片
    cv::Mat img = cv::imread("./w.jpeg");

    // 创建窗口并显示图片
    cv::namedWindow("Image", cv::WINDOW_NORMAL);
    cv::imshow("Image", img);

    // 等待用户按下任意键退出程序
    cv::waitKey(0);

    return 0;
}