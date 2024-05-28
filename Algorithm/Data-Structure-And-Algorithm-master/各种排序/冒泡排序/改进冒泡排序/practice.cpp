#include <iostream>
#include <utility> // 包含 std::swap

using namespace std;

template<typename T>
void Bubble_Sort(T* arr, int len) {
    int select = 0;
    cout << "请问按照从小到大排序还是从大到小排序？(1/2)" << endl;
    cout << "1 从小到大排序" << endl;
    cout << "2 从大到小排序" << endl;
    cin >> select;

    for (int i = 0; i < len - 1; ++i) {
        bool flag = false; // 每次内层循环开始时重置 flag
        for (int j = 0; j < len - 1 - i; ++j) {
            if (select == 1) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]); // 使用 std::swap
                    flag = true;
                }
            } else if (select == 2) {
                if (arr[j] < arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]); // 使用 std::swap
                    flag = true;
                }
            }
        }
        if (!flag) break; // 如果没有交换过元素，说明排序完成
    }
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Bubble_Sort(arr, 10);
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
