#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// sort //对容器内元素进行排序
// random_shuffle //洗牌 指定范围内的元素随机调整次序
// merge  // 容器元素合并，并存储到另一容器中
// reverse // 反转指定范围的元素


// sort //对容器内元素进行排序
void print(int val){
    cout << val << " ";
}
void test(){
    vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
    sort(v.begin(),v.end());
    for_each(v.begin(),v.end(),print);
    cout<<endl;
    sort(v.begin(),v.end(),greater<int>());
    for_each(v.begin(),v.end(),print);
    cout<<endl;
   
}

// random_shuffle //洗牌 指定范围内的元素随机调整次序

void test2(){
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);
    for_each(v.begin(),v.end(),print);
    cout<<endl;
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(),print);
    cout<<endl;
}

// merge  // 容器元素合并，并存储到另一容器中

void test3(){
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<5;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int>  vtarget;
    vtarget.resize(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vtarget.begin());
    for_each(vtarget.begin(),vtarget.end(),print);
    cout<<endl;

}

// reverse // 反转指定范围的元素

void test4(){
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);
    for_each(v.begin(),v.end(),print);
    cout<<endl;
    reverse(v.begin(),v.end());
    for_each(v.begin(),v.end(),print);
    cout<<endl;
}
int main(){
    test4();
    return 0;

}