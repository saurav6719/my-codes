#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int ans = 0;
    for(int i = 0; i<n;i++){
        int count=0;
        while(input[i] >0){
            int last = input[i] % 10;
            if(last == 4 or last == 7) count++;
            input[i]/=10;
        }
        if(count<=k) ans++;
    }

    cout<<ans;
    return 0;
}
