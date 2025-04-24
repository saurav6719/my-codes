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
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    vector<int> pichlakapichla(n,-1);
    int x = -1;
    int y = -1;
    for(int i =0; i<n; i++){
        if(input[i] > 0) continue;
        if(x==-1){
            x = i;
            continue;
        }
        if(y==-1){
            y=i;
            continue;
        }
        pichlakapichla[i] = x;
        x=y;
        y=i;
    }

    vector<int> pichla(n,-1);
    int z  = -1;
    for(int i = 0; i<n; i++){
        if(input[i] >0)continue;
        if(z==-1){
            z=i;
            continue;
        }
        pichla[i] = z;
        z=i;
    }

    print(pichla);
    print(pichlakapichla);

    vector<int> pos(n+5);
    vector<int> neg(n+5);

    for(int i=0;i<n; i++){
        if(input[i] > 0){
            pos[i] = 1;
            neg[i] = 0;
            break;
        }
        pos[i] = 0;
        neg[i] = 1;
        break;
    }
     
    



    for(int i= 1; i<n; i++){
        if(input[i] > 0){
            pos[i] = pos[i-1]+1;
        }
        else{
            int cnt = 0;
            int pkp = pichlakapichla[i];
            if(pkp != -1){
                cnt += pos[pkp];
            }
            int p = pichla[i];
            if(p!=-1){
                if(pkp != -1){
                    cnt += (p - pkp - 1);
                    cnt++;
                }
                else{
                    cnt += p;
                    cnt++;
                }
            }
            pos[i] = cnt;
        }
    }

    for(int i= 1; i<n; i++){
        if(input[i] > 0){
            neg[i] = neg[i-1];
        }
        else{
            int cnt = 0;
            int pkp = pichlakapichla[i];
            if(pkp != -1){
                cnt += neg[pkp];
            }
            int p = pichla[i];
            if(p==-1){
                neg[i] = i+1;
                continue;
            }

            if(p!=-1){
                cnt += i-p-1;

            }
            cnt++;
            neg[i] = cnt;
        }
    }

    int ans1 = 0;
    int ans2 = 0;

    print(pos);
    print(neg);

    for(int i = 0; i<n; i++){
        ans1 += pos[i];
        ans2 += neg[i];
    }

    cout<<ans2<<" "<<ans1;







}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

