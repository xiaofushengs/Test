
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void get_next(string t, int *next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i<t.size() - 1)
	{
		if (j == 0 || t[i] == t[j])//t[i]表示后缀的单个字符，t[j]表示前缀的单个字符
		{
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];			//若字符不相同，则j值回溯
	}
} 

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

int main(){
    string pattern = "abab";
    vector<int> partialMatchTable = buildPartialMatchTable(pattern);
    for (int i = 0; i < partialMatchTable.size(); ++i) {
        cout << partialMatchTable[i] << " ";
    }
    cout<<endl;
    return 0;
}
