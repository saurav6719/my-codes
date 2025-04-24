#include<iostream>
#include<vector>
using namespace std;
 
void f(vector<vector<int> > &matrixA , vector<vector<int> > &matrixB, vector<vector<int> > &sum , int i, int j, int r, int c , vector<vector<int> >& visited){
    // base case 
    if(i >=r or j>= c) return;
    if(visited[i][j] == 1) return;
 
    sum[i][j] = matrixA[i][j] + matrixB[i][j];
    visited[i][j] = 1;
 
    f(matrixA,matrixB,sum,i+1,0,r,c, visited);
    // move to next column 
    f(matrixA,matrixB,sum,i,j+1,r,c, visited);
 
}
int main(){
    int r;
    cin>>r;
    int c;
    cin>>c;
    vector<vector<int> > matrixA(r, vector<int> (c));
    vector<vector<int> > matrixB(r, vector<int> (c));
    vector<vector<int> > sum(r, vector<int> (c));
    vector<vector<int> > visited(r, vector<int> (c , 0));
    for(int i = 0;  i<r; i++){
        for(int j = 0; j<c; j++){
            int a;
            cin>>a;
            matrixA[i][j] = a;
        }
    }
 
    for(int i = 0;  i<r; i++){
        for(int j = 0; j<c; j++){
            int a;
            cin>>a;
            matrixB[i][j] = a;
        }
    }
 
    f(matrixA,matrixB,sum,0,0,r,c, visited);
 
    for(int i = 0;  i<r; i++){
        for(int j = 0; j<c; j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}