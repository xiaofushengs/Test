#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

vector<vector<int>> generateMatrix(int n){
    vector<vector<int>>  result(n,vector<int>(n,0));
    int startX=0,startY=0;
    int circleNum=n/2;
    int mid=n/2;
    int offset=1;
    int count=1;
    while (circleNum--)
    {
        int i=startX;
        int j=startY;

        for (j; j < n-offset; j++)
        {
            result[i][j]=count++;
        }

        for(i;i<n-offset;i++)
        {
            result[i][j]=count++;
        }

        for(;j>startX;j--)
        {
            result[i][j]=count++;
        }
        for(;i>startX;i--)
        {
            result[i][j]=count++;
        }
        startX++;
        startY++;
        offset++;
    }

    if(n%2){
        result[startX][startY]=count;
    }

    return result;
    
}

int main(){
    cout<<"ÇëÊäÈë¼¸Î»¾ØÕó"<<endl;
    int len=0;
    cin>>len;
    vector<vector<int>> v=generateMatrix(len);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j= 0; j < v.size(); j++)
        {
            cout<<setw(4)<<v[i][j]<<" ";
        }
        cout<<endl; 
    }
    
    

    return 0;
}

