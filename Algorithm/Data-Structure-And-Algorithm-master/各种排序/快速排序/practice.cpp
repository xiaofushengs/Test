#include <iostream>
#include <vector>

using namespace std;

// �Զ��� swap ����
template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// ��������
template<typename T>
int partition(T *arr, int low, int high) {
    T pivot = arr[low];  // ѡ���һ��Ԫ����Ϊ��׼ֵ
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

// ����������
template<typename T>
void quickSort(T *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // ��ȡ��׼ֵ������
        quickSort(arr, low, pi - 1);         // �Ի�׼ֵ�����еݹ�����
        quickSort(arr, pi + 1, high);        // �Ի�׼ֵ�Ҳ���еݹ�����
    }
}

int main() {
    int num;
    cout << "�����������Ԫ�صĸ�����";
    cin >> num;

    vector<int> arr(num);
    cout << "������������" << num << "��Ԫ�أ�����Ϊ��������";
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    quickSort(arr.data(), 0, num - 1);

    cout << "����������˳��";
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
