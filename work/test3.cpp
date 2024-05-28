#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<map>

using namespace std;

class Student{
    public:
        Student(){

        }
        Student(int id, string name, int age){
            this->id = id;
            this->name = name;
            this->age = age;
        }
   
        int id;
        string name;
        int age;
};
void student_input(){
   
    multimap<int,Student> m;
    string seed_name="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < seed_name.size(); i++)
    {
        Student s;
        string name="Student_";
        name+=seed_name[i];
        int age=rand()%21+10;
        s.id=i+101;
        s.name=name;
        s.age=age;
        m.insert(pair<int,Student>(i+101,s));
        
    }
    for (multimap<int,Student>::iterator it=m.begin();it!=m.end();it++){
        cout<<it->second.id<<" "<<it->second.name<<" "<<it->second.age<<endl;
    }
    ofstream ofs;
    ofs.open("student.txt",ios::out|ios::app);
    for (multimap<int,Student>::iterator it=m.begin();it!=m.end();it++){
        ofs<<it->second.id<<","<<it->second.name<<","<<it->second.age<<","<<endl;

    }
   
    ofs.close();
    cout<<"save successful"<<endl;

    

}
void student_output(){
    ifstream ifs;
    ifs.open("student.txt",ios::in);
    if(!ifs.is_open()){
        cout<<"open failed"<<endl;
        return;
    }
    string line;
    int pos=-1;
    int start=0;

    while(getline(ifs,line)){
        
        Student s;
        int pos=-1;
        int start=0;
        for(int i=0;i<line.size();i++){
            
           
			pos = line.find(",", start); //从0开始查找 ','
            int id=stoi(line.substr(start, pos-start));

            start=pos+1;
            pos = line.find(",", start);
            string name=line.substr(start, pos-start);

            start=pos+1;
            pos = line.find(",", start);
            int age=stoi(line.substr(start, pos-start)); 
            
            s.id=id;
            s.name=name;
            s.age=age;
            
		}
         cout<<s.id<<" "<<s.name<<" "<<s.age<<endl;
        
       
        

    }
    ifs.close();
}

int main(){
    student_output();
    return 0;
}