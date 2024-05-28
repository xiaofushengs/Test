#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<ctime>

using namespace std;

class Student{
    public:

       Student(string n, int a, double h){
         this->name = n;
         this->age = a;
         this->height = h;
       }
       string name;
       int age;
       double height;
};

void test(){
    vector<Student>  v;
    string name_seed="ADVERTISEMENT";
    for(int i = 0; i <name_seed.size(); i++){
        string name="Student_";
        name+=name_seed[i];

        int age=rand()%13+18;
        double height=rand()%11+170;
        Student s(name,age,height);
        v.push_back(s);
    }
    sort(v.begin(),v.end(),[](Student &a, Student &b){
        if(a.age==b.age){
            return a.height>b.height;
        }
        return a.age>b.age;
    });
    for(int i = 0; i <v.size(); i++){
        cout<<v[i].name<<" "<<v[i].age<<" "<<v[i].height<<endl;
    }
    cout<<"-------------------"<<endl;
    random_shuffle(v.begin(),v.end());
    for(int i = 0; i <v.size(); i++){
        cout<<v[i].name<<" "<<v[i].age<<" "<<v[i].height<<endl;
    }
    cout<<"-------------------"<<endl;
    sort(v.begin(),v.end(),[](Student &a, Student &b){
         return a.height<b.height;
    });
    for(int i = 0; i <v.size(); i++){
        cout<<v[i].name<<" "<<v[i].age<<" "<<v[i].height<<endl;
    }
    cout<<"-------------------"<<endl;
    reverse(v.begin(),v.end());
    for(int i = 0; i <v.size(); i++){
        cout<<v[i].name<<" "<<v[i].age<<" "<<v[i].height<<endl;
    }
}

void test1(){
    vector<int> v1,v2;
    for(int i = 0; i <10; i++){
        v1.push_back(i);
        v2.push_back(i+100);
    }
    vector<int>  vtarge;
    vtarge.resize(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vtarge.begin());
    for(int i = 0; i <vtarge.size(); i++){
        cout<<vtarge[i]<<" ";
    }
    cout<<endl;
}
int main()
{   
    // srand(time(nullptr)); // 设置随机数种子
    // srand(12345);
    // test();


    test1();
    return 0;
}