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
        //构造函数
        SpeakerManager();
        //析构函数
        ~SpeakerManager();
        //菜单显示
        void showMenu();
        //退出系统
        void exitSystem();
        //12人
        vector<int> v1;
        //六人
        vector<int> v2;
        //最终胜利者
        vector<int> v3;
        //成员详细数据
        map<int,Speaker> m_speaker;
        //第几轮
        int m_index;
        //初始化
        void initSpeaker();
        //创造人数
        void createSpeaker();
        //开始比赛
        void startSpeech();
        //抽签
        void speechDraw();
        //比赛
        void speechContest();
        //显示比赛结果
        void showSpeechRank();
        //保存分数
        void saveScore();
        //读取记录
        void loadRecord();
        //文件为空的标志
        bool m_fileIsEmpty;
        //往届记录
        map<int,vector<string>> m_record;
        //显示分数
        void showScore();
        //清空比赛记录
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
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeakerManager::exitSystem(){
    cout << "欢迎下次使用" << endl;
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
        string name="选手_";
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
    //第一轮比赛
	//1、抽签
	speechDraw();
	//2、比赛
    speechContest();
   

	//3、显示晋级结果
    showSpeechRank();

	//第二轮比赛
    this->m_index++;

	//1、抽签
    speechDraw();
    //2、比赛
    speechContest();
    //3、显示晋级结果
    showSpeechRank();
	//保存分数
    saveScore();

    this->initSpeaker();
    this->createSpeaker();
    this->loadRecord();

    cout << "比赛结束" << endl;
    system("pause");
    cout << endl;
    

}

void SpeakerManager::speechDraw(){
    cout << "第" << this->m_index << "轮比赛" << endl;
    cout << "抽签中..." << endl;
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
    cout << "比赛进行中..." << endl;
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
            cout << "第" << num/6 << "场比赛结束" << endl;
            for(multimap<double,int,greater<double>>::iterator it=mul.begin();it!=mul.end();it++){
                cout<<"编号:"<<it->second<<" 姓名:"<<this->m_speaker[it->second].name<<" 得分:"<<this->m_speaker[it->second].score[this->m_index-1]<<endl;
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
    cout << "比赛结束" << endl;
    system("pause");
    cout << endl;

}

void SpeakerManager::showSpeechRank(){
    cout << "第" << this->m_index << "轮晋级名单" << endl;
    vector<int> v;
    if(this->m_index==1){
        v=this->v2;
    }
    else{
        v=this->v3;
    }
    for(int i=0;i<v.size();i++){
        cout<<"编号:"<<v[i]<<" 姓名:"<<this->m_speaker[v[i]].name<<" 得分:"<<this->m_speaker[v[i]].score[this->m_index-1]<<endl;
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
        cout << "文件打开失败" << endl;
        return;
    }
    for(vector<int>::iterator it=this->v3.begin();it!=this->v3.end();it++){
        ofs<<*it<<","<<this->m_speaker[*it].score[this->m_index-1]<<",";
    }
    ofs<<endl;
    ofs.close();
    cout << "保存成功" << endl;
    this->m_fileIsEmpty=false;
    system("pause");
    system("cls");
    
}

void SpeakerManager::loadRecord(){
    ifstream ifs;
    ifs.open("score.txt",ios::in);
    if(!ifs.is_open()){
        cout << "文件打开失败" << endl;
        this->m_fileIsEmpty=true;
        return;
    }
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        cout << "文件为空" << endl;
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
        cout << "文件为空" << endl;
    }
    else{
        for(map<int,vector<string>>::iterator it=this->m_record.begin();it!=this->m_record.end();it++){
            cout << "第" << it->first+1 << "轮比赛" << endl;
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
    cout << "确定清空比赛记录吗？" << endl;
    cout << "1.确定" << endl;
    cout << "2.取消" << endl;
    int select=0;
    cin >> select;
    if(select==1){
        ofstream ofs("score.txt",ios::trunc);
        ofs.close();
        this->initSpeaker();
        this->createSpeaker();
        this->loadRecord();
        cout << "比赛记录已清空" << endl;
        this->m_fileIsEmpty=true;
    }
    system("pause");
    system("cls");
}


