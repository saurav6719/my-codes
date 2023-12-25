#include<iostream>
using namespace std;
int main(){
    bool flag = true;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int x3,y3,x4,y4;
    if(x1 == x2) flag = false;
    if(y1 == y2) flag = false;
    if(abs(x1-x2) == abs(y1-y2)) flag = false;
    if(flag ==  true) cout<<"-1";
    else{
        if(x1 == x2){
            x3 = x2 + abs(y2-y1);
            y3 = y2;
            x4 = x3;
            y4 = y1;
        }
        else if(y1 == y2){
            x3 = x2;
            x4 = x1;
            y3 = y2 + abs(x2-x1);
            y4 = y3;
        }
        else{
            x3 = x1;
            y3 = y2;
            x4 = x2;
            y4 = y1;

        }
        cout<<x3<<" "<<y3<<" "<<x4<<" "<<y4;    
    }
    
    return 0;
}