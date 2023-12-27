#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    bool flag = true;
    vector<vector<char> > ans(n,vector<char> (m));
    for(int i = 0; i<n ; i+=2){
        for(int j = 0 ; j< m ; j++){
            if(i%2 == 0) ans[i][j] = '#';
        }
    }
    for(int i = 1; i<n; i+=4){
        for(int j = 0; j<m-1; j++){
            ans[i][j] = '.';
        }
        ans[i][m-1] = '#';
    }
    for(int i = 3; i<n; i+=4){
        for(int j = 1; j<m; j++){
            ans[i][j] = '.';
        }
        ans[i][0] = '#';
    }
    for(int i = 0; i<n ; i++){
        for(int j = 0 ; j< m ; j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }


    return 0;
}