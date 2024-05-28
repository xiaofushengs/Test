
#include<iostream>
#include<string> 
#include<vector>
#include<map>   
#include<fstream>
using namespace std;

class Student{
    public:
        string m_name;
        int m_age;
        int m_sex;
        double m_chinese[2];
        double m_math[2];
        double m_english[2];
        double m_total[2];
        double m_average[2];
};
class StudentManager{
    public:
        //无参构造函数
        StudentManager();
        //析构函数
        ~StudentManager();
        //菜单
        void showMenu();
        //退出系统
        void exitSystem();
        //编号
        vector <int>  v;
        //学生信息
        map<int, Student> m_students;
        //初始化
        void initialize();
        //添加学生
        void addStudent();
        //保存学生信息
        void saveStudent();
        
        //该生是否存在
        int isExist(int id);
        //删除学生
        void deleteStudent();
        //修改学生信息
        void modifyStudent();
        //查询学生信息
        void queryStudent();
        //打印学生信息
        void printStudent();
        


           
};




