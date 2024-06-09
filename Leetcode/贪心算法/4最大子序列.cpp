#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> maxSubArray(vector<int>& v) {
    int result = INT_MIN;  // ��ʼ��Ϊ��С����
    vector<int> v1, maxSubArray;
    int count = 0;

    for (int i = 0; i < v.size(); i++) {
        count += v[i];
        v1.push_back(v[i]);
        
        if (count > result) {
            result = count;
            maxSubArray = v1;  // �������������
        } 
        if (count <= 0) {
            count = 0;
            v1.clear();
        }
    }
    return maxSubArray;
}

int main() {
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> result = maxSubArray(v);
    cout << "���������: ";
    for_each(result.begin(), result.end(), [](int val) {
        cout << val << " ";
    });
    cout << endl;
    cout << "�ܺ�: " << accumulate(result.begin(), result.end(), 0) << endl;
    
    return 0;
}
