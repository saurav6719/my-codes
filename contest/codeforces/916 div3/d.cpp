#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

#define mx(a,b,c) max(a,max(b,c));
using namespace std;
bool cmp(pair<int,int> &a,pair<int,int> &b){
    return a.first>b.first;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count = 0;
        vector<pair<int,int> > first(n);
        vector<pair<int,int> > second(n);
        vector<pair<int,int> > third(n);
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            first[i] ={a,i};

        }
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            second[i] ={a,i};
        }
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            third[i] ={a,i};
        }
        
        sort(first.begin() , first.end(), cmp);
        sort(second.begin() , second.end(),cmp);
        sort(third.begin() , third.end(),cmp);

        int ans= 0;
        for(int i = 0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(first[i].second != second[j].second and first[i].second != third[k].second and third[k].second != second[j].second){
                        ans = max(ans,first[i].first + second[j].first + third[k].first);
                    }
                }
            }
        }

        cout<<ans<<endl;

    }

}