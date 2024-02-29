#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        // take 2 binary strings as input 
        string a1,a2;
        cin>>a1>>a2;    

        string ans="";
        ans+=a1[0];

        bool f=false;
        int i=1,j=0;
        while(i<n && j<n){
            if(a1[i]=='1' && a2[j]=='0'){
                f=true;
                break;
            }
            if(!f){
                ans+=a1[i];
                i++;
                j++;
            }
        }

        if(f)
            ans+=a2.substr(j,n-j);
            debug(ans);
        
        vector<string>v(n,"");

        for(int k=n-2;k>=0;k--){
            string s="";
            s+=a2[k+1];
            s+=v[k+1];
            v[k]+=s;
        }

        vector<string>v1(n,"");

        for(int k=n-2;k>=0;k--){
            string s="";
            s+=ans[k+1];
            s+=v1[k+1];
            v1[k]+=s;
        } 

        int count=0;
        for(int i=0;i<n;i++){
            if(a1[i+1]==a2[i]){
                if(v1[i+1]==v[i])
                    count++;
            }
        }
        cout<<ans<<endl;
        cout<<count<<endl;
        
    }
}