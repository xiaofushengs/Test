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

        // ʹ�ö��ֲ����ҵ�����λ��
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // ������key��Ԫ������ƶ�
        for (int j = i - 1; j >= low; --j) {
            arr[j + 1] = arr[j];
        }

        // ����key
        arr[low] = key;
    }
}

int main() {
    int len;
    cout << "���������鳤�ȣ�" << endl;
    cin >> len;

    // ��̬��������
    double* arr = new double[len];

    // ��ʼ�����������
    srand(static_cast<unsigned int>(time(nullptr)));

    // �����������
    for (int i = 0; i < len; ++i) {
        double random = (rand() % 101) / 10.0;
        arr[i] = random;
    }

    cout << "����ǰ��" << endl;
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // �����۰��������
    Binary_Insertion_Sort(arr, len);

    cout << "�����" << endl;
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // �ͷŶ�̬���������
    delete[] arr;

    return 0;
}
