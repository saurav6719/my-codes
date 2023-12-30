#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int> > input(n, vector<int> (2));
    for(int i = 0; i<n; i++){
        cin>>input[i][0]>>input[i][1];
    }
    int count = 0;
    for(int i = 0; i<n; i++){
        int x = input[i][0];
        int y = input[i][1];
        bool left = false;
        bool right = false;
        bool up = false;
        bool down = false;
        for(int j = 0; j<n;j++){
            if(input[j][1] == y and input[j][0] < x ){
                left = true;
            }
            else if(input[j][1] == y and input[j][0] > x){
                right = true;
            }
            else if(input[j][0] == x and input[j][1] > y){
                up = true;
            }
            else if(input[j][0] == x and input[j][1] < y){
                down = true;
            }
        }
        if(left and right and up and down) count++;
    }
    cout<<count;
    return 0;
}