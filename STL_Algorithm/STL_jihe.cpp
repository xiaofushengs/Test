#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  

void printvector(vector<int> v){
    for (vector<int>::iterator it = v.begin(); it!= v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test01(){
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i + 5);
    }
    printvector(v1);
    printvector(v2);

    vector<int> v3;
    v3.resize(min(v1.size(), v2.size()));
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    cout << "交集 "<<endl;
    printvector(v3);

    vector<int> v4;
    v4.resize(v1.size()+ v2.size());
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
    cout << "并集 "<<endl;
    for_each(v4.begin(), v4.end(), [](int x) { cout << x << " "; });
    cout << endl;

    vector<int> v5;
    auto v5=set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v5.begin());
    cout << "差集 "<<endl;
    for_each(v5.begin(), v5.end(), [](int x) { cout << x << " "; });
    cout << endl;

}

int main() {
    test01();
    return 0;
}