#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeNums(vector<int>& nums, int val) {
    int slow = 0; // ��ָ���ʼ��Ϊ0
    for (int fast = 0; fast < nums.size(); fast++) { // ��ָ�������������
        if (val != nums[fast]) { // �����ǰԪ�ز�����val
            nums[slow++] = nums[fast]; // ��Ԫ�ظ��Ƶ���ָ��λ�ã�������ָ���1
        }
    }
    return slow; // �����µ����鳤��
}

int main() {
    vector<int> ll = {2, 2, 2, 3, 3, 3}; // ��ʼ������
    int val = 2; // Ҫ�Ƴ���ֵ
    cout << "Starting removeNums function..." << endl; // ��ӵ�����Ϣ
    int result = removeNums(ll, val); // ����removeNums����
    cout << "Result: " << result << endl; // ����µ����鳤��

    
    for (int i = 0; i < result; i++) {
        cout << ll[i] << " ";
    }

    cout << endl;
    return 0;
}
