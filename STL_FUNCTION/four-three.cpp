#include<iostream>
#include<string>
#include<vector>
#include<functional>

using namespace std;


// template<class T> T plus<T> //加法仿函数
// template<class T> T minus<T> //减法仿函数
// template<class T> T multiplies<T> //乘法仿函数
// template<class T> T divides<T> //除法仿函数
// template<class T> T modulus<T> //取模仿函数
// template<class T> T negate<T> //取反仿函数
void test(){
    negate<int> n;
    cout<<n(10)<<endl;

    plus<int> p;
    cout<<p(10,20)<<endl;

    minus<int> m;
    cout<<m(10,20)<<endl;

    multiplies<int> mp;
    cout<<mp(10,20)<<endl;

    divides<int> d;
    cout<<d(40,20)<<endl;

    modulus<int> mod;
    cout<<mod(25,20)<<endl;
}


// template<class T> bool equal_to<T> //等于
// template<class T> bool not_equal_to<T> //不等于
// template<class T> bool greater<T> //大于
// template<class T> bool greater_equal<T> //大于等于
// template<class T> bool less<T> //小于
// template<class T> bool less_equal<T> //小于等于


void test2(){
    
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    sort(v.begin(),v.end(),less<int>());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    sort(v.begin(),v.end(),greater<int>());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

}


// template<class T> bool logical_and<T> //逻辑与
// template<class T> bool logical_or<T> //逻辑或
// template<class T> bool logical_not<T> //逻辑非

void test3(){
    vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin();it!= v.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//逻辑非  将v容器搬运到v2中，并执行逻辑非运算
	vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(),  v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

    
}
int main(){
    test3();
    return 0;

}