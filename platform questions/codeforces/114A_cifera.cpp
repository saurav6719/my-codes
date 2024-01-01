#include<iostream>
using namespace std;
int main(){
    int k;
    int l;
    cin>>k>>l;
    int count = -1;
    while(l % k == 0){
        l /= k;
        count++;
    }
    if(count >= 0 and l == 1){
        cout<<"YES"<<endl;
        cout<<count;
    }
    else cout<<"NO";
    return 0;
}