#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include<fstream>
#include<numeric>
#include<deque>
#include<functional>

using namespace std;

class Speaker{
    public:
        string name;
        double score[2];
};

class SpeakerManager{
    public:
        SpeakerManager();

        void show_menu();

        void quit_system();

        ~SpeakerManager()=default;

        	//����ѡ�� ����  12��
        vector<int>v1;

        //��һ�ֽ�������  6��
        vector<int>v2;

        //ʤ��ǰ��������  3��
        vector<int>vVictory;

        //��ű�� �Լ���Ӧ�� ����ѡ�� ����
        map<int, Speaker> m_Speaker;
        //�ڼ����ֱ���
        int m_index;

        //��ʼ������
	    void init_Speaker();
        //��ʼ������12��ѡ��
	    void createSpeaker();
        //��ʼ���� - �������̿���
	    void startSpeech();
        //��ǩ
	    void speechDraw();
        //����
        void speechContest();
        //��ʾ�������
        void showSpeechResult();
        //�����¼
        void saveRecord();
      
        
};

SpeakerManager::SpeakerManager(){
     this->init_Speaker();
     this->createSpeaker();
}

void SpeakerManager::quit_system() {
    cout<<"ByeBye"<<endl;
    exit(0);
}

void SpeakerManager::show_menu(){
    cout<<"**************************"<<endl;
    cout<<"**1.contest begin**"<<endl;
    cout<<"**2.show winner**"<<endl;
    cout<<"**3.delete file**"<<endl;
    cout<<"**0.quit system**"<<endl;
    cout<<"**************************"<<endl;
}

void SpeakerManager::init_Speaker(){
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();
    this->m_index = 1;
}

void SpeakerManager::createSpeaker(){
    string nameSeed = "ABCDEFGHIJKL";
    for(int i = 0; i < 12; i++){
        string name="Person_";
        name+=nameSeed[i];
        Speaker sp;
        sp.name = name;
        for(int j = 0; j < 2; j++){

            
            if(j == 0){
                sp.score[j] = 0;
            }
            else{
                sp.score[j] = 1;
            }
        }
        this->v1.push_back(i+101);
        m_Speaker.insert(make_pair(i+101, sp));
    }
    
}

void SpeakerManager::startSpeech(){
    //��һ�ֱ���
	//1����ǩ
	speechDraw();
	//2������
    speechContest();
	//3����ʾ�������
    showSpeechResult();
	//�ڶ��ֱ���
    this->m_index ++;
	//1����ǩ
    speechDraw();
	//2������
    speechContest();
	//3����ʾ���ս��
    showSpeechResult();
	//4���������
    saveRecord();
    cout<<"game over"<<endl;
    system("pause");
    system("cls");
}

void SpeakerManager::speechDraw(){
    cout<<"The "<<this->m_index<<"round contestants are drawing lots."<<endl;
    if(this->m_index == 1){
        random_shuffle(v1.begin(), v1.end());
        for(int i = 0; i < v1.size(); i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
    }
    else{
        random_shuffle(v2.begin(), v2.end());
        for(int i = 0; i < v2.size(); i++){
            cout<<v2[i]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    system("cls");
}

void SpeakerManager::speechContest(){
    cout<<"The "<<this->m_index<<"round contestants are contest."<<endl;
    multimap<double,int,greater<int>> groupscore;
    int num = 0;
    vector<int> temp;
    if(this->m_index == 1){
        
        temp = v1;
    }
    else{
        temp = v2;
    }

    for(vector<int>::iterator it = temp.begin(); it!= temp.end(); it++){
        num++;
        deque<double> dq;
        for(int i = 0; i < 10; i++){
            double score=(rand() % 401+600)/10.f;
            dq.push_back(score);
        }
        sort(dq.begin(), dq.end(),greater<double>());
        double sum = accumulate(dq.begin(), dq.end(), 0.0f);
        double avg = sum/dq.size();
        this->m_Speaker[*it].score[this->m_index-1] = avg;
        groupscore.insert(make_pair(avg, *it));

        if(num%6==0){
            cout<<"The"<<num/6<<"group"<<endl;
            for(multimap<double,int,greater<int>>::iterator it = groupscore.begin(); it!= groupscore.end(); it++){
                cout<<"bianhao:"<<it->second<<" name:"<<this->m_Speaker[it->second].name<<" score:"<<this->m_Speaker[it->second].score[m_index-1]<<endl;
            }
            int count = 0;
            for(multimap<double,int,greater<int>>::iterator it = groupscore.begin(); it!= groupscore.end()&&count<3; it++, count++){
                if(this->m_index == 1){
                    this->v2.push_back(it->second);
                }
                else{
                    this->vVictory.push_back(it->second);
                }
            }
            groupscore.clear();
            cout<<endl;
        }



        
    }
    system("pause");
   
}

void SpeakerManager::showSpeechResult(){
    cout<<"The "<<this->m_index<<"round contestants are show."<<endl;
    vector<int> v;
    if(this->m_index == 1){
        v = this->v2;
    }
    else
    {
        v = this->vVictory;
    }
    for(vector<int>::iterator it = v.begin(); it!= v.end(); it++){
        cout<<"bianhao:"<<*it<<" name:"<<this->m_Speaker[*it].name<<" score:"<<this->m_Speaker[*it].score[m_index-1]<<endl;
    }
    cout<<endl;


    system("pause");
    system("cls");
    this->show_menu();
    
}

void SpeakerManager::saveRecord(){
    ofstream ofs;
    ofs.open("record.csv", ios::out|ios::app);

    for(vector<int>::iterator it = vVictory.begin(); it!= vVictory.end(); it++){
        ofs<<*it<<","<<m_Speaker[*it].score[1]<<",";
    }
    ofs<<endl;
    ofs.close();
    cout<<"save success"<<endl;
   
   
}