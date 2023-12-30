#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int p = (3*a) / 10;
    int q = a-((a/250)*c);

    int misha = max(p,q);

    int r = (3*b) / 10;
    int s = b-((b/250)*d); 

    int vasya = max(r,s);

    if(misha > vasya) cout<<"Misha";
    else if(misha < vasya) cout<<"Vasya";
    else cout<<"Tie";


}