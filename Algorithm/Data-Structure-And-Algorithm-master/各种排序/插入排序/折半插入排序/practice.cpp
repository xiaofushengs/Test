#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T>
void Binary_Insertion_Sort(T* arr, int len) {
    for (int i = 1; i < len; ++i) {
        T key = arr[i];
        int low = 0, high = i - 1;

        // 使用二分查找找到插入位置
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // 将大于key的元素向后移动
        for (int j = i - 1; j >= low; --j) {
            arr[j + 1] = arr[j];
        }

        // 插入key
        arr[low] = key;
    }
}

int main() {
    int len;
    cout << "请输入数组长度：" << endl;
    cin >> len;

    // 动态分配数组
    double* arr = new double[len];

    // 初始化随机数种子
    srand(static_cast<unsigned int>(time(nullptr)));

    // 生成随机数组
    for (int i = 0; i < len; ++i) {
        double random = (rand() % 101) / 10.0;
        arr[i] = random;
    }

    cout << "排序前：" << endl;
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 进行折半插入排序
    Binary_Insertion_Sort(arr, len);

    cout << "排序后：" << endl;
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 释放动态分配的数组
    delete[] arr;

    return 0;
}
