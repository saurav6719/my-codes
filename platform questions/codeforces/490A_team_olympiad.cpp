#include<iostream>
#include<vector>
#include<algorithm>
#define mn(a,b,c) min(a,min(b,c))
using namespace std;
int main(){
    int n ;
    cin>>n;
    vector<int> input(n);
    for(int i = 0 ; i< n ; i++){
        int a;
        cin>>a;
        input[i] = a; 
    }
    vector<int> ones;
    vector<int> twos;
    vector<int> threes;
    for(int i = 0; i< n ; i++){
        if(input[i] == 1) ones.push_back(i+1);
        if(input[i] == 2) twos.push_back(i+1);
        if(input[i] == 3) threes.push_back(i+1);
    }
    int answer = mn(ones.size(), twos.size(), threes.size());
    cout<<answer<<endl;
    for(int i = 0; i<answer; i++){
        cout<<ones[i]<<" "<<twos[i]<<" "<<threes[i]<<endl;
    }
    return 0;

}