
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int processResult(int N, const vector<int>& maleHeights, const vector<int>& femaleHeights) {
    vector<int>a,b,c,d;
    for(int i=0;i<N;i++){
        int x=maleHeights[i];
        if(x>0) a.push_back(x);
        else    b.push_back(-x);
    }
    for(int i=0;i<N;i++){
        int x=femaleHeights[i];
        if(x>0) c.push_back(x);
        else    d.push_back(-x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    int i=0,j=0,r=0;
    while(i<a.size()&&j<d.size()){
        if(d[j]>a[i]){ r++; i++; j++; }
        else j++;
    }
    i=0; j=0;
    while(i<b.size()&&j<c.size()){
        if(b[i]>c[j]){ r++; i++; j++; }
        else i++;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin>>N;
    vector<int> M(N), F(N);
    for(int i=0;i<N;i++) cin>>M[i];
    for(int i=0;i<N;i++) cin>>F[i];
    cout<<processResult(N, M, F);
    return 0;
}