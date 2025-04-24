#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> > input(n, vector<char>(m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>input[i][j];
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(input[i][j] == '-') continue;
            if((i+j) % 2 == 0) input[i][j] = 'B';
            else input[i][j] = 'W';
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<input[i][j];
        }
        cout<<endl;
    }
    return 0;
}