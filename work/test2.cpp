#include "speakerManage.h"

int main(){
    SpeakerManager sp;
    for(map<int, Speaker>::iterator it = sp.m_Speaker.begin(); it!= sp.m_Speaker.end(); ++it){
        cout << it->first << " " << it->second.name << " " << it->second.score[0] << " " << it->second.score[1] << endl;
    }
    
    return 0;
}