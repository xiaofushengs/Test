#include <iostream>
#include <utility> // ���� std::swap

using namespace std;

template<typename T>
void Bubble_Sort(T* arr, int len) {
    int select = 0;
    cout << "���ʰ��մ�С���������ǴӴ�С����(1/2)" << endl;
    cout << "1 ��С��������" << endl;
    cout << "2 �Ӵ�С����" << endl;
    cin >> select;

    for (int i = 0; i < len - 1; ++i) {
        bool flag = false; // ÿ���ڲ�ѭ����ʼʱ���� flag
        for (int j = 0; j < len - 1 - i; ++j) {
            if (select == 1) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]); // ʹ�� std::swap
                    flag = true;
                }
            } else if (select == 2) {
                if (arr[j] < arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]); // ʹ�� std::swap
                    flag = true;
                }
            }
        }
        if (!flag) break; // ���û�н�����Ԫ�أ�˵���������
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
