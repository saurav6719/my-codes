#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<bool> sieve(n+5, 1); // 1 represents prime
    sieve[0] = 0;
    sieve[1] = 0;

    for(int i = 2; i * i<=n; i++){
        if(sieve[i] == 0) continue;
        for(int j = i * i; j<=n; j+=i){    // complexity O(n log(log n)) for n queries 
            sieve[j] = 0;
        }
    }
    for(int i = 0; i<=n;i++){
        cout<<i<<": ";
        if(sieve[i] == 0) cout<<"not prime"<<endl;
        else cout<<"prime"<<endl;
    }

}