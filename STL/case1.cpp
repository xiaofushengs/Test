#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
#include<ctime>

/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入  key(部门编号) value(员工)
- 分部门显示员工信息
*/

#define CEHUA  0
#define MEISHU 1
#define YANFA  2

class Employee{
    public:
        Employee(string name,int salary){
            this->m_Name = name;
            this->m_Salary = salary;
        }
        string m_Name;
        int m_Salary;
};

void CreateEmployee(vector<Employee> &v){
    string nameSeed = "ABCDEFGHIJ";
    for(int i=0;i<10;i++){
        string name = "Person_";
        name += nameSeed[i];
        int salary = rand()%10000+10000;
        Employee emp(name,salary);
        v.push_back(emp);
    }
}

void setDepartment(vector<Employee> &v,multimap<int,Employee> &m){
   for(vector<Employee>::iterator it = v.begin();it!=v.end();it++){
        int deptId = rand()%3;
        m.insert(make_pair(deptId,*it));
   }
}

void showInfo(multimap<int,Employee> &m){
    cout<<"ce hua :"<<endl;
    multimap<int,Employee>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA);
    int index = 0;
    while(pos!=m.end() && index<count){
        cout<<"name:"<<pos->second.m_Name<<" salary:"<<pos->second.m_Salary<<endl;
        pos++;
        index++;
    }
    cout<<"---------------------------"<<endl;

    cout<<"mei shu :"<<endl;
    multimap<int,Employee>::iterator pos2 = m.find(MEISHU);
    int count2 = m.count(MEISHU);
    int index2 = 0;
    while(pos2!=m.end() && index2<count2){
        cout<<"name:"<<pos2->second.m_Name<<" salary:"<<pos2->second.m_Salary<<endl;
        pos2++;
        index2++;
    }
    cout<<"---------------------------"<<endl;

    cout<<"yan fa :"<<endl;
    multimap<int,Employee>::iterator pos3 = m.find(YANFA);
    int count3 = m.count(YANFA);
    int index3 = 0;
    while(pos3!=m.end() && index3<count3){
        cout<<"name:"<<pos3->second.m_Name<<" salary:"<<pos3->second.m_Salary<<endl;
        pos3++;
        index3++;
    }
    cout<<"---------------------------"<<endl;
}


int main(){
    vector<Employee> v;
    CreateEmployee(v);

    multimap<int,Employee> m;
    setDepartment(v,m);

    showInfo(m);


    return 0;
}
