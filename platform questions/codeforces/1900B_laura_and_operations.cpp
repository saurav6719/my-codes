#include<iostream>
#include<vector>
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> result(3,0);
        int a,b,c; 
        cin>>a>>b>>c;
        // checking for b 
        int x = abs(a - c);
        if (x % 2 == 0) result[1] = 1;

        // checking for a 
        x = abs(b - c);
        if (x % 2 == 0) result[0] = 1;

        // checking for c
        x = abs(a - b);
        if (x % 2 == 0) result[2] = 1;

        cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<endl;
    }
    return 0;
}