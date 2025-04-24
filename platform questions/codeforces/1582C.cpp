/*
  ------------------------------------------
 |                                        |
 |      Code Crafted by Saurav     |
 |                                        |
  ------------------------------------------
    \        ,     ,        /
      \      |     |      /
         \   \___/   /
           \  -----  /
             \_____/
  
  Happy coding! 
*/

/* includes and all */

#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout<<"errr----  "<< #x <<" " <<x<<endl 
#define print(v) do { \
                    cout << "vect--" << #v << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << v[i] << " "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
using namespace std;

/* write core logic here */
void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int i = 0;
    int j = n-1;
    char ch1;
    char ch2;
    int cnt1 = 0;
    int cnt2= 0;
    
    while(i<n and j>=0 and str[i] == str[j]){
        i++;
        j--;
    }


    if(i>=j){
        cout<<0<<endl;
        return;
    }

    int ic = i;
    int jc = j;
    debug(i);
    debug(j);
        ch1 = str[i];
        ch2 = str[j];
        debug(ch1);
        debug(ch2);
        while(i<=j){
            if(i<n and j>=0 and str[i] == str[j]){
                i++;j--;
            }
            else{
                if(str[i] == ch1){
                    i++;
                    cnt1++;
                }
                else if(str[j] == ch1){
                    j--;
                    cnt1++;
                }
                else{
                    cnt1 = INT_MAX;
                    break;
                }
            }
        }

        while(ic<=jc){
            if(ic<n and jc>=0 and str[ic] == str[jc]){
                ic++;jc--;
            }
            else{
                if(str[ic] == ch2){
                    ic++;
                    cnt2++;
                }
                else if(str[jc] == ch2){
                    jc--;
                    cnt2++;
                }
                else{
                    cnt2 = INT_MAX;
                    break;
                }
            }
        }

        debug(cnt1);
        debug(cnt2);
        int ans = min(cnt1,cnt2);
        if(ans >= INT_MAX-1000) ans = -1;
        cout<<ans<<endl;
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
return 0;
}

