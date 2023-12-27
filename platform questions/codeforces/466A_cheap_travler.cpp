#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int answer = 0;
    if((float(b)/float(m)) > a){
        answer += n*a;
    }
    else{
        int x = n % m;
        answer += ((n-x) * b)/m;
        answer += min(b,x * a);
    }
    cout<<answer;

    return 0;
}