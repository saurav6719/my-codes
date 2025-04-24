#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    if(n == 4 or n == 7 or n == 44 or n == 47 or n == 74 or n == 77 or n == 444 or n == 447 or n == 474 or n == 477 or n == 744 or n == 747 or n == 774 or n == 777) cout<<"YES";
    
    else if(n % 4 == 0 or n % 7 == 0 or n % 44 == 0 or n % 47 == 0 or n % 74 == 0 or n % 77 == 0 or n % 444 == 0 or n % 447 == 0 or n % 474 == 0 or n % 477  == 0 or n % 744 == 0 or n % 747  == 0 or n % 774 == 0 or n % 777 == 0) cout<<"YES";
    else cout<<"NO";
    return 0;
}