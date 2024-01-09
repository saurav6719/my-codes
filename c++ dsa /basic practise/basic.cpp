#include<iostream>
using namespace std;
int main(){
    int m;
    //cout<<"Enter row : ";
    cin>>m;
    int n;
    //cout<<"Enter column : ";
    cin>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i!=1 and  i!=m and j>2 ){
            cout<<" ";
            }
            else
            cout<<"*";
        }
       cout<<endl;
    }
    return 0;
}