#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> >input(n,vector<int>(m));
    vector<string> marks(n);
    for(int i = 0; i<n; i++){
        cin>>marks[i];
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            input[i][j] = int(marks[i][j]);
        }
    }
    vector<int> subjectMax(m,-1);
    vector<int> bestt(n,0);
    for(int j = 0; j<m ; j++){
        int best = 0;
        for(int i  = 0; i<n ; i++){
            best = max(best,input[i][j]);
        }
        for(int i  = 0; i<n ; i++){
            if(input[i][j] == best) bestt[i] = 1;
        }
    }
    cout<<count(bestt.begin(),bestt.end(),1);
    return 0;
}