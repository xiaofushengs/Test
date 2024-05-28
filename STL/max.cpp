#include <iostream>
#include<string>
#include <vector>
#include<deque>
#include<algorithm>

using namespace std;

class Person{
    public:
        Person(string name,int chinese_score,int math_score,int english_score,int total_score){
            this->name=name;
            this->chinese_score=chinese_score;
            this->math_score=math_score;
            this->english_score=english_score;
            this->total_score=total_score;
        }
        string name;
        int chinese_score;
        int math_score;
        int english_score;
        int total_score;
};

void CreatePerson(vector<Person> &p){
    string s="ABCDEFG";
    for(int i=0;i<s.size();i++){
        string name="TOM ";
        name+=s[i];
        
        int chinese_score=0;
        int math_score=0;
        int english_score=0;
        int total_score=0;
        Person pp(name,chinese_score,math_score,english_score,total_score);
        p.push_back(pp);
        
    }
}

void Set_score(vector<Person> &p){
    for(int i=0;i<p.size();i++){
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int score=rand()%41+60;
            d.push_back(score);
        }
        sort(d.begin(),d.end());
        d.pop_front();
        d.pop_back();
        int sum1=0;
        for(int i=0;i<d.size();i++){
            sum1+=d[i];
        }
        int ave1=sum1/d.size();
        p[i].chinese_score=ave1;

        d.erase(d.begin(),d.end());
        for (int i = 0; i < 10; i++){
            int score=rand()%41+60;
            d.push_back(score);
        }
        sort(d.begin(),d.end());
        d.pop_front();
        d.pop_back();
        int sum2=0;
        for(int i=0;i<d.size();i++){
            sum2+=d[i];
        }
        int ave2=sum2/d.size();
        p[i].math_score=ave2;

        d.erase(d.begin(),d.end());
        for (int i = 0; i < 10; i++){
            int score=rand()%41+60;
            d.push_back(score);
        }
        sort(d.begin(),d.end());
        d.pop_front();
        d.pop_back();
        int sum3=0;
        for(int i=0;i<d.size();i++){
            sum3+=d[i];
        }
        int ave3=sum3/d.size();
        p[i].english_score=ave3;

        p[i].total_score=p[i].chinese_score+p[i].math_score+p[i].english_score;
        
          
    }
}

int main() {
    vector<Person> v;
    CreatePerson(v);
    Set_score(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i].name<<" "<<v[i].chinese_score<<" "<<v[i].math_score<<" "<<v[i].english_score<<" "<<v[i].total_score<<endl;
    }
    return 0;
}
