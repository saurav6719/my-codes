#include<iostream>
#include<vector>
using namespace std;
int main(){
    int k;
    cin>>k;
    vector<vector<char> >input(4,vector<char>(4));
    for(int i =0 ;i<4;i++){
        for(int j=0; j<4 ; j++){
            cin>>input[i][j];
        }
    }

    vector<int> freq(16,0);
    for(int i = 0 ;i<4;i++){
        for(int j= 0;j<4;j++){
            if(input[i][j] == '.' ) continue;
            else {
                freq[input[i][j] - '0']++;
            }
        }
    }

    bool flag = true;

    for(int i = 0; i<16;i++){
        if(freq[i] > 2*k){
            flag = false;
            break;
        }
    }

    if(flag) cout<<"YES";
    else cout<<"NO";
    
    return 0;
}