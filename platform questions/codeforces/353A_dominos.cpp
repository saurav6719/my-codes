#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int> > input(n, vector<int> (2));
    for(int i = 0; i<n; i++){
        for(int j = 0 ; j<2; j++){
            cin>>input[i][j];
        }
    }

    int sum1 = 0;
    int sum2 = 0;

    for(int j = 0; j<2; j++){
        for(int i = 0 ; i<n; i++){
            if(j==0) sum1 += input[i][j];
            else sum2 += input[i][j];
        }
    }
    // cout<<sum1<<" "<<sum2;
    int ans = -1;
    bool flag_odd = false;
    if(sum1 % 2 == 0 and sum2 % 2 == 0) cout<<"0";
    else if(sum1 % 2 != 0 and sum2 % 2 != 0){
        for(int i = 0 ; i<n; i++){ 
            for(int j = 0; j<2; j++){
                if((input[i][0] % 2 == 0 and input[i][1] % 2 != 0) or (input[i][0] % 2 != 0 and input[i][1] % 2 == 0)){
                     ans = 1;
                    flag_odd = true;
                    break;
                }
            }
            if(flag_odd) break;
        }
        cout<<ans;
    }
    else if((sum1 % 2 != 0 and sum2 % 2 == 0) or (sum1 % 2 == 0 and sum2 % 2 != 0)){
        cout<<"-1";
    }
    return 0;
}