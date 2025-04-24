#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> input(20,0);
    for(int i = 0; i<n;i++){
        cin>>input[i];
    }
    int chest = 0;
    int biceps = 0;
    int back = 0;
    for(int i = 0;i<20;i+=3){
        chest += input[i];
    }
    for(int i = 1;i<20;i+=3){
        biceps += input[i];
    }
    for(int i = 2;i<20;i+=3){
        back += input[i];
    }

    if(chest > biceps and chest > back) cout<<"chest";
    if(biceps > chest and biceps > back) cout<<"biceps";
    if(back > biceps and back > chest) cout<<"back";

    return 0;

}