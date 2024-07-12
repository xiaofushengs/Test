#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    // ����ͼƬ·��
    std::string imagePath;
    
    imagePath="1.png";

    // ��ȡͼƬ
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);

    // ���ͼƬ�Ƿ�ɹ���ȡ
    if (image.empty()) {
        std::cerr << "�޷��򿪻��ȡͼƬ: " << imagePath << std::endl;
        return -1;
    }

    // ���ͼƬ�Ļ�����Ϣ
    std::cout << "ͼƬ���: " << image.cols << std::endl;
    std::cout << "ͼƬ�߶�: " << image.rows << std::endl;
    std::cout << "ͨ����: " << image.channels() << std::endl;

    // ��ʾͼƬ
    cv::imshow("��ʾͼƬ", image);
    cv::waitKey(0);

    return 0;
}
