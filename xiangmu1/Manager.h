
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
        //�޲ι��캯��
        StudentManager();
        //��������
        ~StudentManager();
        //�˵�
        void showMenu();
        //�˳�ϵͳ
        void exitSystem();
        //���
        vector <int>  v;
        //ѧ����Ϣ
        map<int, Student> m_students;
        //��ʼ��
        void initialize();
        //���ѧ��
        void addStudent();
        //����ѧ����Ϣ
        void saveStudent();
        
        //�����Ƿ����
        int isExist(int id);
        //ɾ��ѧ��
        void deleteStudent();
        //�޸�ѧ����Ϣ
        void modifyStudent();
        //��ѯѧ����Ϣ
        void queryStudent();
        //��ӡѧ����Ϣ
        void printStudent();
        


           
};




