#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<fstream>
#include<numeric>
#include<deque>

using namespace std;
class Speaker{
    public:
        string name;
        double score[2];
};

class SpeakerManager{
    public:
        //���캯��
        SpeakerManager();
        //��������
        ~SpeakerManager();
        //�˵���ʾ
        void showMenu();
        //�˳�ϵͳ
        void exitSystem();
        //12��
        vector<int> v1;
        //����
        vector<int> v2;
        //����ʤ����
        vector<int> v3;
        //��Ա��ϸ����
        map<int,Speaker> m_speaker;
        //�ڼ���
        int m_index;
        //��ʼ��
        void initSpeaker();
        //��������
        void createSpeaker();
        //��ʼ����
        void startSpeech();
        //��ǩ
        void speechDraw();
        //����
        void speechContest();
        //��ʾ�������
        void showSpeechRank();
        //�������
        void saveScore();
        //��ȡ��¼
        void loadRecord();
        //�ļ�Ϊ�յı�־
        bool m_fileIsEmpty;
        //�����¼
        map<int,vector<string>> m_record;
        //��ʾ����
        void showScore();
        //��ձ�����¼
        void clearRecord();


};

SpeakerManager::SpeakerManager(){
    this->initSpeaker();
    this->createSpeaker();
    this->loadRecord();
}

SpeakerManager::~SpeakerManager(){

}

void SpeakerManager::showMenu(){
    cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeakerManager::exitSystem(){
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}

void SpeakerManager::initSpeaker(){
    this->m_index = 1;
    this->v1.clear();
    this->v2.clear();
    this->v3.clear();
    this->m_speaker.clear();
    this->m_record.clear();
}

void SpeakerManager::createSpeaker(){
    string seedname="ABCDEFGHIJKL";
    for(int i=0;i<seedname.size();i++){
        string name="ѡ��_";
        name+=seedname[i];
        Speaker s;
        s.name=name;
        for(int j=0;j<2;j++){
            s.score[j]=0;
        }
        this->v1.push_back(i+101);
        this->m_speaker.insert(make_pair(i+101,s));
    }
}

void SpeakerManager::startSpeech(){
    //��һ�ֱ���
	//1����ǩ
	speechDraw();
	//2������
    speechContest();
   

	//3����ʾ�������
    showSpeechRank();

	//�ڶ��ֱ���
    this->m_index++;

	//1����ǩ
    speechDraw();
    //2������
    speechContest();
    //3����ʾ�������
    showSpeechRank();
	//�������
    saveScore();

    this->initSpeaker();
    this->createSpeaker();
    this->loadRecord();

    cout << "��������" << endl;
    system("pause");
    cout << endl;
    

}

void SpeakerManager::speechDraw(){
    cout << "��" << this->m_index << "�ֱ���" << endl;
    cout << "��ǩ��..." << endl;
    if(this->m_index==1){
        random_shuffle(this->v1.begin(),this->v1.end());
        for(int i=0;i<this->v1.size();i++){
            cout<<v1[i]<<" ";
        }
    }
    else{
        random_shuffle(this->v2.begin(),this->v2.end());
        for(int i=0;i<this->v2.size();i++){
            cout<<v2[i]<<" ";
        }
    }
    cout<<"--------------"<<endl;
    system("pause");
    cout << endl;
}

void SpeakerManager::speechContest(){
    cout << "����������..." << endl;
    multimap<double,int,greater<double>> mul;
    vector<int> v;
    int num=0;
    if(this->m_index==1){
        v=this->v1;
    }
    else{
        v=this->v2;
    }
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        num++;
        deque<double> d;
        for(int i=0;i<10;i++){
            double score=(rand()%401+600)/10.f;
            d.push_back(score);
        }
        sort(d.begin(),d.end());
        d.pop_front();
        d.pop_back();
        double avg=accumulate(d.begin(),d.end(),0.0)/d.size();
        this->m_speaker[*it].score[this->m_index-1]=avg;
        mul.insert(make_pair(avg,*it));
        if(num%6==0){
            cout << "��" << num/6 << "����������" << endl;
            for(multimap<double,int,greater<double>>::iterator it=mul.begin();it!=mul.end();it++){
                cout<<"���:"<<it->second<<" ����:"<<this->m_speaker[it->second].name<<" �÷�:"<<this->m_speaker[it->second].score[this->m_index-1]<<endl;
            }
            int count=0;
            for(multimap<double,int,greater<double>>::iterator it=mul.begin();it!=mul.end()&&count<3;it++,count++){
                if(this->m_index==1){
                    this->v2.push_back(it->second);
                }
                else{
                    this->v3.push_back(it->second);
                }

            }
            mul.clear();
            cout << endl;
        }

    }
    cout << "��������" << endl;
    system("pause");
    cout << endl;

}

void SpeakerManager::showSpeechRank(){
    cout << "��" << this->m_index << "�ֽ�������" << endl;
    vector<int> v;
    if(this->m_index==1){
        v=this->v2;
    }
    else{
        v=this->v3;
    }
    for(int i=0;i<v.size();i++){
        cout<<"���:"<<v[i]<<" ����:"<<this->m_speaker[v[i]].name<<" �÷�:"<<this->m_speaker[v[i]].score[this->m_index-1]<<endl;
    }
    cout << endl;
    system("pause");
    system("cls");
    this->showMenu();
    
}
void SpeakerManager::saveScore(){
    ofstream ofs;
    ofs.open("score.txt",ios::out);
    if(!ofs.is_open()){
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    for(vector<int>::iterator it=this->v3.begin();it!=this->v3.end();it++){
        ofs<<*it<<","<<this->m_speaker[*it].score[this->m_index-1]<<",";
    }
    ofs<<endl;
    ofs.close();
    cout << "����ɹ�" << endl;
    this->m_fileIsEmpty=false;
    system("pause");
    system("cls");
    
}

void SpeakerManager::loadRecord(){
    ifstream ifs;
    ifs.open("score.txt",ios::in);
    if(!ifs.is_open()){
        cout << "�ļ���ʧ��" << endl;
        this->m_fileIsEmpty=true;
        return;
    }
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        cout << "�ļ�Ϊ��" << endl;
        this->m_fileIsEmpty=true;
        return;
    }
    this->m_fileIsEmpty=false;
    ifs.putback(ch);

    string data;
    int index=0;
    while(ifs>>data){
        vector<string> v;
        int start=0;
        int pos=-1;
        while (true)
        {
            pos=data.find(",",start);
            if(pos==-1){
                break;
            }
            string temp=data.substr(start,pos-start);
            v.push_back(temp);
            start=pos+1;
        }
        this->m_record.insert(make_pair(index,v));
        index++;
        
    }
    ifs.close();
}

void SpeakerManager::showScore(){
    if(this->m_fileIsEmpty){
        cout << "�ļ�Ϊ��" << endl;
    }
    else{
        for(map<int,vector<string>>::iterator it=this->m_record.begin();it!=this->m_record.end();it++){
            cout << "��" << it->first+1 << "�ֱ���" << endl;
            for(int i=0;i<it->second.size();i++){
                cout << it->second[i] << " ";
            }
            cout << endl;
        }
    }
    system("pause");
    system("cls");
    
}

void SpeakerManager::clearRecord(){
    cout << "ȷ����ձ�����¼��" << endl;
    cout << "1.ȷ��" << endl;
    cout << "2.ȡ��" << endl;
    int select=0;
    cin >> select;
    if(select==1){
        ofstream ofs("score.txt",ios::trunc);
        ofs.close();
        this->initSpeaker();
        this->createSpeaker();
        this->loadRecord();
        cout << "������¼�����" << endl;
        this->m_fileIsEmpty=true;
    }
    system("pause");
    system("cls");
}


