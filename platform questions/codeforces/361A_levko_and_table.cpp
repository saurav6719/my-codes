#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    int k;
    cin>>n;
    cin>>k;
    vector<vector<int> > output(n,vector<int> (n,0));
    for(int i = 0; i<n; i++){
        output[i][i] = k;
    }

    for(int i = 0; i<n; i++){
        for(int j= 0; j<n;j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}