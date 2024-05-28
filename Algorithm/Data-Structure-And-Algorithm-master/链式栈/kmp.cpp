#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 构建部分匹配表
vector<int> buildPartialMatchTable(const string& pattern) {
    int m = pattern.size();
    vector<int> partialMatchTable(m, 0);
    int j = 0; // 长度最长的相同前后缀

    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = partialMatchTable[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        partialMatchTable[i] = j;
    }

    return partialMatchTable;
}

// KMP字符串匹配算法
vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> result;
    if (pattern.empty()) return result;

    int n = text.size();
    int m = pattern.size();
    vector<int> partialMatchTable = buildPartialMatchTable(pattern);
    int j = 0; // pattern的指针

    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = partialMatchTable[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            result.push_back(i - m + 1); // 找到一个匹配
            j = partialMatchTable[j - 1];
        }
    }

    return result;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    vector<int> matches = kmpSearch(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : matches) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
