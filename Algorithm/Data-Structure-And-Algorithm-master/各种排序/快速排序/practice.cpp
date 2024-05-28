#include <iostream>
#include <vector>

using namespace std;

// 自定义 swap 函数
template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// 分区函数
template<typename T>
int partition(T *arr, int low, int high) {
    T pivot = arr[low];  // 选择第一个元素作为基准值
    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

// 快速排序函数
template<typename T>
void quickSort(T *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // 获取基准值的索引
        quickSort(arr, low, pi - 1);         // 对基准值左侧进行递归排序
        quickSort(arr, pi + 1, high);        // 对基准值右侧进行递归排序
    }
}

int main() {
    int num;
    cout << "请输入排序的元素的个数：";
    cin >> num;

    vector<int> arr(num);
    cout << "请依次输入这" << num << "个元素（必须为整数）：";
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    quickSort(arr.data(), 0, num - 1);

    cout << "快速排序后的顺序：";
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
