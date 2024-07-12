#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // 输入图片路径
    std::string imagePath;
    
    imagePath="1.png";

    // 读取图片
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);

    // 检查图片是否成功读取
    if (image.empty()) {
        std::cerr << "无法打开或读取图片: " << imagePath << std::endl;
        return -1;
    }

    // 输出图片的基本信息
    std::cout << "图片宽度: " << image.cols << std::endl;
    std::cout << "图片高度: " << image.rows << std::endl;
    std::cout << "通道数: " << image.channels() << std::endl;

    // 显示图片
    cv::imshow("显示图片", image);
    cv::waitKey(0);

    return 0;
}
