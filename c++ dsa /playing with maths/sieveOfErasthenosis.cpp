#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<bool> sieve(n+5, 0); // 0 represnets composite
    sieve[0] = 0;
    sieve[1] = 0;

    for(int i = 2; i * i<=n; i++){
        if(sieve[i] == 0) continue;
        for(int j = i * i; j<=n; j+=i){    // complexity O(n log(log n)) for n queries 
            sieve[j] = 0;
        }
    }
    
    if(sieve[n] == 0) cout<<"not prime";  
    else cout<<"prime";
    return 0;

}