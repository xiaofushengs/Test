#include "speakerManage.h"


int main(){
    SpeakerManager sp;
    
    int choice = 0;
    while (true)
    {
        sp.show_menu();
        cout << "Please enter your choice"<<endl;
        cin >> choice;
        switch (choice){
            case 1:
                sp.startSpeech();
                break;
            case 2:
                
                break;
            case 3:
             
                break;
            case 0:
                sp.quit_system();
                break;
            default:
                break;
        }

    }
    

    return 0;
}