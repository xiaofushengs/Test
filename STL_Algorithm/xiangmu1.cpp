#include<iostream>
#include<vector>
#include<map>
#include<ctime>
#include<string>

using namespace std;

#define CEHUA 0
#define MEISHUA 1
#define YANFA 2
#define HOUQIN 3

class Worker{
    public:
        Worker(string name, int age, int sex, double salary){
           this->m_name = name;
           this->m_age = age;
           this->m_sex = sex;
           this->m_salary = salary;
        }
        string m_name;
        int m_age;
        int m_sex;
        double m_salary;
};



void createWorker(vector<Worker>& workers){
    string name_seed="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0; i<name_seed.size(); i++){
         string name = "员工";
         name += name_seed[i];
         int age = rand()%50+18;
         int sex = rand()%2;
         double salary = rand()%20000+10000;
         Worker worker(name, age, sex, salary);
         workers.push_back(worker);
    }
}
void setGroup(vector<Worker>& workers,multimap<int, Worker>& m){
    for(auto it=workers.begin(); it!=workers.end(); it++){
        int depID=rand()%4;
        m.insert(make_pair(depID, *it));
    }
}

void showWorker(multimap<int, Worker>& m){
    cout<<"策划部门："<<endl;
    auto pos=m.find(CEHUA);
    int count=m.count(CEHUA);
    int index=0;
    for(;pos!=m.end()&&index<count; pos++,index++){
        cout<<"姓名："<<pos->second.m_name<<"  年龄："<<pos->second.m_age<<"  性别："<<(pos->second.m_sex?"男":"女")<<"  薪资："<<pos->second.m_salary<<endl;
    }
    cout<<"------------"<<endl;
    cout<<"美术部门："<<endl;
    pos=m.find(MEISHUA);
    count=m.count(MEISHUA);
    index=0;
    for(;pos!=m.end()&&index<count; pos++,index++){
        cout<<"姓名："<<pos->second.m_name<<"  年龄："<<pos->second.m_age<<"  性别："<<(pos->second.m_sex?"男":"女")<<"  薪资："<<pos->second.m_salary<<endl;
    }
    cout<<"------------"<<endl;
    cout<<"研发部门："<<endl;
    pos=m.find(YANFA);
    count=m.count(YANFA);
    index=0;
    for(;pos!=m.end()&&index<count; pos++,index++){
        cout<<"姓名："<<pos->second.m_name<<"  年龄："<<pos->second.m_age<<"  性别："<<(pos->second.m_sex?"男":"女")<<"  薪资："<<pos->second.m_salary<<endl;
    }
    cout<<"------------"<<endl;
    cout<<"后勤部门："<<endl;
    pos=m.find(HOUQIN);
    count=m.count(HOUQIN);
    index=0;
    for(;pos!=m.end()&&index<count; pos++,index++){
        cout<<"姓名："<<pos->second.m_name<<"  年龄："<<pos->second.m_age<<"  性别："<<(pos->second.m_sex?"男":"女")<<"  薪资："<<pos->second.m_salary<<endl;
    }
}

int main(){
    srand((unsigned int)time(NULL));
    vector<Worker> workers;
    createWorker(workers);
    multimap<int, Worker> m;
    setGroup(workers, m);
    showWorker(m);
    return 0;
}
