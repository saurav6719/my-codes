#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<char>> input(n, vector<char>(n));
    for(int i = 0; i<n; i++){
        for(int j= 0; j<n ;j++){
            cin>>input[i][j];
        }
    }

    char a = input[0][0];
    char b = input[0][1];
    bool check = true;
    if(a == b) check = false;
    bool flag = true;
    for(int i = 0; i<n; i++){
        for(int j = 0  ;j<n ; j++){
            if(i==j or (i+j == n-1)){ // diagonal checking
                if(input[i][j] != a) {
                    flag = false;
                    break;
                }
            }
            else{
                if(input[i][j] != b){
                    flag = false;
                    break;
                }
            }
        }
    }

    if(flag and check) cout<<"YES";
    else cout<<"NO";
    return 0;
}