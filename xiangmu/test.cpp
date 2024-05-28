#include "speakerManager.h"

int main(){
    srand((unsigned int)time(NULL));
    SpeakerManager sp;
    int choice=0;
    while(true){
        sp.showMenu();
        cout<<"请输入您的选择：";
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
                
                cout<<"您的输入有误，请重新输入"<<endl;
                break;
        }
    }

}