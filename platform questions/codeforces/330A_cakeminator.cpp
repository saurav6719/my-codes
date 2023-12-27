#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
    int r;
    cin>>r;
    int c;
    cin>>c;
    unordered_set<char> row;
    unordered_set<char> column;
    vector<vector<char> > input(r,vector<char> (c));
    for(int i = 0;i<r; i++){
        for(int j = 0 ; j<c; j++){
            char a;
            cin>>a;
            input[i][j] = a;
        }
    }

    for(int i = 0;i<r; i++){
        for(int j = 0 ; j<c; j++){
            if(input[i][j] == 'S'){
                row.insert(i);
                column.insert(j);
            }
        }
    }

    int ans = 0 ;

    for(int i= 0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(!row.count(i) ){
                if(input[i][j] == '.'){
                    ans++;
                    input[i][j] = ',';
                }
            }
        }
    }

    for(int i= 0; i<c; i++){
        for(int j = 0; j<r; j++){
            if(!column.count(i) ){
                if(input[j][i] == '.'){
                    ans++;    
                    input[j][i] = ',';
                }
            }
        }
    }

    cout<<ans;

    return 0;

}