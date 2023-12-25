#include<iostream>
#include<algorithm>
#include<math.h>
#include<climits>
#define mx(a,b,c,d,e,f,g) max(max(max(a,max(b,c)) , max(d,e)),max(f,g))
using namespace std;
int main(){
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    int exp1 = a+b+c;
    int exp2 = a+b*c;
    int exp3 = a*b+c;
    int exp4 = a*b*c;
    int exp5 = (a+b)*c;
    int exp6 = a*(b+c);
    int result = INT_MIN;
    result = mx(result,exp1,exp2,exp3,exp4,exp5,exp6);
    cout<<result;
    return 0;
}