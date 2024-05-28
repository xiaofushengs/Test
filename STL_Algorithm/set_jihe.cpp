#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// set_intersection // 求两个容器的交集
class print{
    public:
        void operator()(int elem){
            cout << elem << " ";
        }
};

void test01(){
    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    for(int i = 5; i < 15; i++){
        v2.push_back(i);
    }
    vector<int> vTarget;
    vTarget.resize(min(v1.size(), v2.size()));
    vector<int>::iterator itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itend, print());
    cout << endl;
}


// set_union // 求两个容器的并集
void test02(){
    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    for(int i = 5; i < 15; i++){
        v2.push_back(i);
    }
    vector<int> vTarget;
    vTarget.resize(v1.size() + v2.size());
    vector<int>::iterator itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itend, print());
    cout << endl;
}
// set_difference  // 求两个容器的差集

void test03(){
    vector<int> v1;
    vector<int> v2;
    for(int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    for(int i = 5; i < 15; i++){
        v2.push_back(i);
    }
    vector<int> vTarget;
    vTarget.resize(max(v1.size(), v2.size()));
    vector<int>::iterator itend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
    for_each(vTarget.begin(), itend, print());
    cout << endl;
    cout<<vTarget.capacity() << endl;
    cout<<vTarget.size() << endl;
}


int main() {
     test03();
     return 0;
}



// set_intersection // 求两个容器的交集

// set_union // 求两个容器的并集

// set_difference  // 求两个容器的差集