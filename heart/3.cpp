#include<iostream>
#include<string>
using namespace std;

class Point{
    public:
        Point(int x, int y){
            this->point_x = x;
            this->point_y = y;
        }

        int point_x;
        int point_y;
};
class Circle{
    public:
        Circle(int x, int y,int r){
            this->x = x;
            this->y = y;
            this->r = r;
        }
        int x;
        int y;
        int r;
};
void guanxi(Point& p,Circle &r){
    if((p.point_x-r.x)*(p.point_x-r.x)+(p.point_y-r.y)*(p.point_y-r.y)<r.r*r.r){
        cout<<"在圆内"<<endl;
    }else if((p.point_x-r.x)*(p.point_x-r.x)+(p.point_y-r.y)*(p.point_y-r.y)==r.r*r.r){
        cout<<"在圆上"<<endl;
    }
    else{
        cout<<"在圆外"<<endl;
    }
}


int main(){
    Point p(0,11);
    Circle c(0,0,10);
    guanxi(p,c);
    return 0;
}