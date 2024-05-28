#include "Manager.h"
#include<iostream>

StudentManager::StudentManager(){
   this->initialize();
}

StudentManager::~StudentManager(){

}

void StudentManager::showMenu(){
    std::cout<<"Welcome to Student Manager System\n";
    std::cout<<"1. Add student\n";
    std::cout<<"2. Delete student\n";
    std::cout<<"3. Modify student\n";
    std::cout<<"4. Search student\n";
    std::cout<<"5. Display all students\n";
    std::cout<<"6. Exit\n";
}
void StudentManager::exitSystem(){
    cout<<"Exiting System..."<<endl;
    exit(0);
}
void StudentManager::initialize(){
    this->v.clear();
    this->m_students.clear();
}

void StudentManager::addStudent(){
    cout<<"Add student..."<<endl;
    string name_seed="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i=0;i<name_seed.size();i++){
         Student stu;
         string name="student_";
         name+=name_seed[i];
         stu.m_name=name;
         
         int age=rand()%19+12;
         stu.m_age=age;
         int sex=rand()%2;
         stu.m_sex=sex;
         for(int j=0;j<2;j++){
             double chinese=(rand()%601+400)/10.0;
             stu.m_chinese[j]=chinese;
             double math=(rand()%601+400)/10.0;
             stu.m_math[j]=math;
             double english=(rand()%601+400)/10.0;
             stu.m_english[j]=english;
             double total=chinese+math+english;
             stu.m_total[j]=total;

             double average=total/3.0;
             stu.m_average[j]=average;
             
         }
         this->v.push_back(i+101);
         this->m_students.insert(pair<int,Student>(i+101,stu));
         
    }
    cout<<"Add student success!"<<endl;
    this->showMenu();
    this->saveStudent();
    system("pause");
    system("cls");
}
    

void StudentManager::saveStudent(){
    cout<<"Save student..."<<endl;
    ofstream ofs("student.txt",ios::out);
    if(ofs.is_open()){
        for(auto it=this->m_students.begin();it!=this->m_students.end();it++){
            ofs<<it->first<<" "<<it->second.m_name<<" "<<it->second.m_age<<" "<<it->second.m_sex<<" "<<it->second.m_chinese[0]<<" "<<it->second.m_math[0]<<" "<<it->second.m_english[0]<<" "<<it->second.m_total[0]<<" "<<it->second.m_average[0]<<" "<<it->second.m_chinese[1]<<" "<<it->second.m_math[1]<<" "<<it->second.m_english[1]<<" "<<it->second.m_total[1]<<" "<<it->second.m_average[1]<<endl;
        }
        cout<<"Save student success!"<<endl;
    }
    else{

        cout<<"Save student failed!"<<endl;
    }
    system("pause");
    system("cls");
}

void StudentManager::printStudent(){
     this->m_students.clear();
     ifstream ifs;
     ifs.open("student.txt",ios::in);
     if(!ifs.is_open()){
         cout<<"Open file failed!"<<endl;
         return;
     }
     int id;
     string name;
     int age;
     int sex;
     double chinese[2];
     double math[2];
     double english[2];
     double total[2];
     double average[2];
     while(ifs>>id>>name>>age>>sex>>chinese[0]>>math[0]>>english[0]>>total[0]>>average[0]>>chinese[1]>>math[1]>>english[1]>>total[1]>>average[1]){
         Student stu;
         stu.m_name=name;
         stu.m_age=age;
         stu.m_sex=sex;
         stu.m_chinese[0]=chinese[0];
         stu.m_math[0]=math[0];
         stu.m_english[0]=english[0];
         stu.m_total[0]=total[0];
         stu.m_average[0]=average[0];
         stu.m_chinese[1]=chinese[1];
         stu.m_math[1]=math[1];
         stu.m_english[1]=english[1];
         stu.m_total[1]=total[1];
         stu.m_average[1]=average[1];
         this->m_students.insert(pair<int,Student>(id,stu));
     }
     ifs.close();
     for(auto it=m_students.begin(); it!=m_students.end(); it++){
         cout<<"学号"<<it->first
         <<" 姓名："<<it->second.m_name<<" 年龄："<<it->second.m_age
         <<" 性别："<<it->second.m_sex<<" 期中中文成绩："<<it->second.m_chinese[0]
         <<" 期中数学成绩："<<it->second.m_math[0]
         <<" 期中英语成绩："<<it->second.m_english[0]
         <<" 期中总分："<<it->second.m_total[0]
         <<" 期中平均分："<<it->second.m_average[0]
         <<" 期末中文成绩："<<it->second.m_chinese[1]
         <<" 期末数学成绩："<<it->second.m_math[1]
         <<" 期末英语成绩："<<it->second.m_english[1]
         <<" 总分："<<it->second.m_total[1]
         <<" 平均分："<<it->second.m_average[1]<<endl;
     }
}

void StudentManager::deleteStudent(){
    cout<<"Delete student..."<<endl;
    int id;
    cout<<"Please enter the student id you want to delete:";
    cin>>id;
    auto it=this->m_students.find(id);
    if(it!=this->m_students.end()){
        this->m_students.erase(it);
        cout<<"Delete student success!"<<endl;
    }
    else{
        cout<<"Delete student failed!"<<endl;
    }
    system("pause");
    system("cls");  

}

void StudentManager::queryStudent(){
    cout<<"Query student..."<<endl;
    int id;
    cout<<"Please enter the student id you want to query:";
    cin>>id;
    auto it=this->m_students.find(id);
    if(it!=this->m_students.end()){
        cout<<"学号"<<it->first
        <<" 姓名："<<it->second.m_name<<" 年龄："<<it->second.m_age
        <<" 性别："<<it->second.m_sex<<" 期中中文成绩："<<it->second.m_chinese[0]
        <<" 期中数学成绩："<<it->second.m_math[0]
        <<" 期中英语成绩："<<it->second.m_english[0]
        <<" 期中总分："<<it->second.m_total[0]
        <<" 期中平均分："<<it->second.m_average[0]
        <<" 期末中文成绩："<<it->second.m_chinese[1]
        <<" 期末数学成绩："<<it->second.m_math[1]
        <<" 期末英语成绩："<<it->second.m_english[1]
        <<" 总分："<<it->second.m_total[1]
        <<" 平均分："<<it->second.m_average[1]<<endl;
    }
}

void StudentManager::modifyStudent(){

    cout<<"Modify student..."<<endl;
    int id;
    cout<<"Please enter the student id you want to modify:";
    cin>>id;
    auto it=this->m_students.find(id);
    if(it!=this->m_students.end()){
        cout<<"Modify student success!"<<endl;
        string name;
        int age;
        int sex;
        double chinese[2];
        double math[2];
        double english[2];
        double total[2];
        double average[2];
        cout<<"Please enter the new name:";
        cin>>name;
        cout<<"Please enter the new age:";
        cin>>age;
        cout<<"Please enter the new sex(0 for male, 1 for female):";
        cin>>sex;
        cout<<"Please enter the new chinese score of the first term:";
        cin>>chinese[0];
        cout<<"Please enter the new math score of the first term:";
        cin>>math[0];
        cout<<"Please enter the new english score of the first term:";
        cin>>english[0];
        cout<<"Please enter the new total score of the first term:";
        cin>>total[0];
        cout<<"Please enter the new average score of the first term:";
        cin>>average[0];
        cout<<"Please enter the new chinese score of the second term:";
        cin>>chinese[1];
        cout<<"Please enter the new math score of the second term:";
        cin>>math[1];
        cout<<"Please enter the new english score of the second term:";
        cin>>english[1];
        cout<<"Please enter the new total score of the second term:";
        cin>>total[1];
        cout<<"Please enter the new average score of the second term:";
        cin>>average[1];
        it->second.m_name=name;
        it->second.m_age=age;
        it->second.m_sex=sex;
        it->second.m_chinese[0]=chinese[0];
        it->second.m_math[0]=math[0];
        it->second.m_english[0]=english[0];
        it->second.m_total[0]=total[0];
        it->second.m_average[0]=average[0];
        it->second.m_chinese[1]=chinese[1];
        it->second.m_math[1]=math[1];
        it->second.m_english[1]=english[1];
        it->second.m_total[1]=total[1];
        it->second.m_average[1]=average[1];
    }
    else{
        cout<<"Modify student failed!"<<endl;
    }
    system("pause");
    system("cls");  
}






