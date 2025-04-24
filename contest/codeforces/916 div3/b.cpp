#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        int k;
        cin>>n;
        cin>>k;
        vector<int> output(n);
        int start = n-k;
        for(int i = 0; i<=k ; i++){   
            output[i] = start;
            start++;
            if(i==n) break;
        }
        start =output[0]-1;
        int start_copy = start;
        for(int i = k+1; i< (k+1) + start_copy ; i++){   
            output[i] = start;
            start--;
            if(i==n) break;
        }

        for(int i = 0; i<n; i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}