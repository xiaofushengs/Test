#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class GreaterFive{
    public:
        bool operator()(int x){
            return x>5;
        }
};
void test(){
    vector<int> v;
    for(int i=0; i<20; i++){
        v.push_back(i);
    }

    auto it=find_if(v.begin(), v.end(),GreaterFive());
    if(it!=v.end()){
        cout << "Elements greater than 5: ";
        for(; it!=v.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    else{
        cout<<"No element greater than 5 found"<<endl;
    }


}
//¶þÔªÎ½´Ê
class mycompare{
    public:
        bool operator()(int x, int y){
            return x>y;
        }
};

void test1(){
    vector<int> v;
    for(int i=6; i>0; i--){
        int m=rand()%51+50;
        v.push_back(m);
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    sort(v.begin(), v.end(),mycompare());
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}

int main(){
    test1();
    return 0;
}