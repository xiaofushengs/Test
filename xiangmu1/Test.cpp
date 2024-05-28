#include "Manager.h"

int main(){
    StudentManager s;
    int choice=0;
    while(true){
        s.showMenu();
        cin>>choice;
        switch(choice){
            case 1:
                s.addStudent();
                break;
            case 2:
                
                break;
            case 3:
               
                break;
            case 4:
               
                break;
            case 5:
               
                break;
            case 6:
            
                s.exitSystem();
                break;
            default:
                cout<<"Invalid choice!"<<endl;
                break;
        }
    }
    system("pause");
    return 0;
}
