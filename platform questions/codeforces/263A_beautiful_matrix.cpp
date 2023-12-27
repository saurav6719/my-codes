#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<vector<int> > matrix(5,vector<int> (5));
    for(int i = 1 ;i<=5; i++){
        for(int j = 1; j<=5; j++){
            int a;
            cin>>a;
            matrix[i-1][j-1] = a;
        }
    }
    int row =0; 
    int col = 0;
    for(int i = 0; i<5; i++){
        for(int j = 0; j< 5; j++){
            if(matrix[i][j] == 1){
                row = i+1;
                col = j+1;
            }
        }
    }
    int ans = 0;
    ans+= abs(row - 3);
    ans += abs(col -3);
    cout<<ans;
    return 0;
}