#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>

using namespace std;

//copy
void test01(){
   vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());

	for_each(v2.begin(), v2.end(), [](int v){ cout << v <<" ";});
	cout << endl;
}

//replace(iterator beg, iterator end, oldvalue, newvalue); 
void test02(){
    vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	replace(v1.begin(), v1.end(), 5, 100);
    for_each(v1.begin(), v1.end(), [](int v){ cout << v <<" ";});
    cout << endl;
}

//replace_if(iterator beg, iterator end, _pred, newvalue);  

// 按条件替换元素，满足条件的替换成指定元素

// beg 开始迭代器

// end 结束迭代器

// _pred 谓词

// newvalue 替换的新元素
void test03(){
    vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
    }
    for_each(v1.begin(), v1.end(), [](int v){ cout << v <<" ";});
    cout << endl;

    replace_if(v1.begin(),v1.end(),[](int v){ return v%2==0; }, 100);
    for_each(v1.begin(), v1.end(), [](int v){ cout << v <<" ";});
    cout << endl;
}
//swap
void test04(){
    vector<int> v1,v2;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i + 1);
        v2.push_back(i + 10);
    }
    for_each(v1.begin(), v1.end(), [](int v){ cout << v <<" ";});
    cout << endl;
    for_each(v2.begin(), v2.end(), [](int v){ cout << v <<" ";});
    cout << endl;
    swap(v1,v2);
    cout << "after swap:" << endl;
    for_each(v1.begin(), v1.end(), [](int v){ cout << v <<" ";});
    cout << endl;
    for_each(v2.begin(), v2.end(), [](int v){ cout << v <<" ";});
    cout << endl;
}
    

//accumulate
void test05(){
    vector<int> v1;
    for (int i = 1; i <= 100; i++)
    {
         v1.push_back(i);
    }
    int total=accumulate(v1.begin(),v1.end(),0);
    cout<<"total:"<<total<<endl;
    
}
//fill
void test06(){
    vector<int> v1(10,0);
    fill(v1.begin(),v1.end(),1);
    for_each(v1.begin(),v1.end(),[](int v){cout<<v<<" ";});
    cout<<endl;
}


int main(){
    test06();
    return 0;
}