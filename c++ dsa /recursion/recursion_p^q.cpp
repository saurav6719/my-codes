#include<iostream>
using namespace std;
//finding p to the power q
int f(int p, int q){
    if (q==0) return 1;
    return p * f(p,q-1);
}
int main(){
    cout<<f(4,0);
    return 0;
}

//time complexity = O(q)
// space complexity = O(q)





