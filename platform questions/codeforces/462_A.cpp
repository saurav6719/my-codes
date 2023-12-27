#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<char> > input(n,vector<char> (n));
    for(int i = 0; i<n ; i++){
        for(int j = 0; j<n ; j++){
            char a;
            cin>>a;
            input[i][j] = a;
        }
    }
    bool flag = true;

    for(int i = 0; i<n ; i++){
        if(flag == false) break;
        for(int j = 0 ; j<n ; j++){
            int ans = 0;
            //checking up 
            if(i>0 and input[i-1][j] == 'o') ans++;
            //checking down 
            if(i<n-1 and input[i+1][j] == 'o') ans++;
            //checking right 
            if(j<n-1 and input[i][j+1] == 'o') ans++;
            //checking left 
            if(j>0 and input[i][j-1] == 'o') ans++;
            if(ans % 2 != 0) {
                flag = false;
                break;
            }
        }
    }

    if(flag) cout<<"YES";
    else cout<<"NO";

    return 0;
}