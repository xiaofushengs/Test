#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeNums(vector<int>& nums, int val) {
    int slow = 0; // 慢指针初始化为0
    for (int fast = 0; fast < nums.size(); fast++) { // 快指针遍历整个数组
        if (val != nums[fast]) { // 如果当前元素不等于val
            nums[slow++] = nums[fast]; // 将元素复制到慢指针位置，并将慢指针加1
        }
    }
    return slow; // 返回新的数组长度
}

int main() {
    vector<int> ll = {2, 2, 2, 3, 3, 3}; // 初始化数组
    int val = 2; // 要移除的值
    cout << "Starting removeNums function..." << endl; // 添加调试信息
    int result = removeNums(ll, val); // 调用removeNums函数
    cout << "Result: " << result << endl; // 输出新的数组长度

    
    for (int i = 0; i < result; i++) {
        cout << ll[i] << " ";
    }

    cout << endl;
    return 0;
}
