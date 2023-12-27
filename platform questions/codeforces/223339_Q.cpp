#include<iostream>
using namespace std;
int ans(int n, int count){
    if (n == 1) {
        count++;
        return count;
    }
    if(n % 2 == 0){ // n is even
        count++;
        return ans(n/2, count);
    }
    else{
        count++;
        return ans(3*n+1, count);
    }
    return count;

}
int main(){
    int n;
    cin>>n;
    cout<<ans(n,0);
    return 0;
}