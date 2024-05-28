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
    cout << "请输入数组元素个数：" << endl;
    int n;
    cin >> n;
    vector<int> v(n);
    cout << "请输入数组元素" << n << "具体值: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << "未排序数组：" << endl;
    for_each(v.begin(), v.end(), [](int x) { cout << x << " "; });
    cout << endl;

    Quicksort(v.data(), 0, n - 1, true);
    cout << "排序后数组（升序）：" << endl;
    for_each(v.begin(), v.end(), [](int x) { cout << x << " "; });
    cout << endl;

    Quicksort(v.data(), 0, n - 1, false);
    cout << "排序后数组（降序）：" << endl;
    for_each(v.begin(), v.end(), [](int x) { cout << x << " "; });
    cout << endl;

    return 0;
}
