#include<iostream>
#include<vector>
using namespace std;
bool cp(int x , int y){
    return x>y;
}
int minCost( vector<int> &x, vector<int> &y){
    sort(x.begin(), x.end(), cp);
    sort(y.begin(),y.end(), cp);
    int hc = 1;
    int vc = 1;
    int h= 0;
    int v= 0;
    int cost = 0;
    while(h<y.size() and v< x.size()){
        if(y[h] > x[v]){
            
            cost += y[h]*hc;
            vc++;
            h++;
        }
        else{
            
            cost+= x[v]*vc;
            hc++;
            v++;
        }
    }
    while(h<y.size()){
        
        cost+= y[h]*hc;
        vc++;
        h++;
    }
     while(v<x.size()){
        
        cost+= x[v]*vc;
        hc++;
        v++;
    }
    return cost;

}
int main(){
    vector<int> x ;
    x.push_back(2);
    x.push_back(1);
    x.push_back(3);
    x.push_back(1);
    x.push_back(4);
    vector<int> y;
    y.push_back(4);
    y.push_back(1);
    y.push_back(2);
    cout<<minCost(x,y)<<endl;
    return 0;

}