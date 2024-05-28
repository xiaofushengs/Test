#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//一元谓词  
struct GreaterFive{
    bool operator()(int val){
        return val > 5;
    }
};
void test01(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }
    //查找第一个大于5的元素
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if(it!= v.end()){
        cout << *it << endl;
    }else{
        cout << "no found" << endl;
    }
}

//二元谓词
class GreaterFive2{
    public:
        bool operator()(int val1, int val2){
            return val1 > val2;
        }
};

void test02(){
    vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

    for(vector<int>::iterator it = v.begin(); it!= v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    sort(v.begin(), v.end());
    for(vector<int>::iterator it = v.begin(); it!= v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), GreaterFive2());
    for(vector<int>::iterator it = v.begin(); it!= v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    test02();
    return 0;
}