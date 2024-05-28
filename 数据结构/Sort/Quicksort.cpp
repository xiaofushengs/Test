#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename T>
int partion(T *arr, int low, int high, bool flag) {
    T pivot = arr[low];
    while (low < high) {
        if (flag) { // Ascending order
            while (low < high && arr[high] >= pivot) {
                high--;
            }
            arr[low] = arr[high];
            while (low < high && arr[low] <= pivot) {
                low++;
            }
            arr[high] = arr[low];
        } else { // Descending order
            while (low < high && arr[high] <= pivot) {
                high--;
            }
            arr[low] = arr[high];
            while (low < high && arr[low] >= pivot) {
                low++;
            }
            arr[high] = arr[low];
        }
    }
    arr[low] = pivot;
    return low;
}

template<typename T>
void Quicksort(T *arr, int low, int high, bool flag) {
    if (low < high) {
        int pivot = partion(arr, low, high, flag);
        Quicksort(arr, low, pivot - 1, flag);
        Quicksort(arr, pivot + 1, high, flag);
    }
}

int main() {
    cout << "����������Ԫ�ظ�����" << endl;
    int n;
    cin >> n;
    vector<int> v(n);
    cout << "����������Ԫ��" << n << "����ֵ: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "δ�������飺" << endl;
    for_each(v.begin(), v.end(), [](int x) { cout << x << " "; });
    cout << endl;

    Quicksort(v.data(), 0, n - 1, true);
    cout << "��������飨���򣩣�" << endl;
    for_each(v.begin(), v.end(), [](int x) { cout << x << " "; });
    cout << endl;

    Quicksort(v.data(), 0, n - 1, false);
    cout << "��������飨���򣩣�" << endl;
    for_each(v.begin(), v.end(), [](int x) { cout << x << " "; });
    cout << endl;

    return 0;
}
