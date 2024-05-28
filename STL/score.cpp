#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;


class Person{
    public:
        Person(string name,int score){
            this->m_name=name;
            this->m_score=score;
        }
        string m_name;
        int m_score;
};
void createPerson(vector<Person> &v){
    string nameseed="ABCDE";
    for(int i=0;i<5;i++){
        string name="TOM";
        name+=nameseed[i];
        int score=0;
        Person p(name,score);
        v.push_back(p);
    }

}
void setScore(vector<Person> &v){
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
        // it->m_score=rand()%61;
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
             int sroce=rand()%41+60;
             d.push_back(sroce);
        }
        sort(d.begin(),d.end());
        d.pop_front();
        d.pop_back();
        int sum=0;
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++){
            sum+=*dit;
        }
        int avg=sum/d.size();
        it->m_score=avg;
        
    }
}

void showPerson(vector<Person> &v){
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
        cout<<"name:"<<it->m_name<<" "<<"score:"<<it->m_score<<endl;
    }
}

int main() {
    vector<Person> v;
    createPerson(v);
    // for(vector<Person>::iterator it=v.begin();it!=v.end();it++){
    //     cout<<(*it).m_name<<" "<<(*it).m_score<<endl;
    // }
    setScore(v);
    showPerson(v);
    
    return 0;
}