#include "speakerManager.h"

int main(){
    srand((unsigned int)time(NULL));
    SpeakerManager sp;
    int choice=0;
    while(true){
        sp.showMenu();
        cout<<"����������ѡ��";
        cin>>choice;
        switch(choice){
            case 1:
                sp.startSpeech();
                break;
            case 2:
                sp.showScore();
                break;
            case 3:
                sp.clearRecord();
                break;
            case 0:
                sp.exitSystem();
                break;
            default:
                
                cout<<"����������������������"<<endl;
                break;
        }
    }

}