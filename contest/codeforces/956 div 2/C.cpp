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
    vector<int> a;
    vector<int> b;
    vector<int> c;
    int sum = 0;
    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        sum+= ele;
        a.push_back(ele);
    }
    //print(a);
    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        b.push_back(ele);
    }


    for(int i = 0; i<n; i++){
        int ele;
        cin>>ele;
        c.push_back(ele);
    }

    vector<int> prfa(n+1);
    vector<int> prfb(n+1);
    vector<int> prfc(n+1);

    prfa[0] =0;
    prfb[0] =0;
    prfc[0] =0;

    for(int i = 1; i<=n; i++){
        prfa[i] = prfa[i-1] + a[i-1];
        prfb[i] = prfb[i-1] + b[i-1];
        prfc[i] = prfc[i-1] + c[i-1];
    }

    int k = sum/3;
    if(sum % 3 != 0){
        k++;
    }

   //print(prfa);

    
    map<int,int> ma;
    map<int,int> mb;
    map<int,int> mc;

    for(int i = 1; i<=n; i++){
        int ele1 = prfa[i-1];
        //debug(ele1);
        int rem = k+ele1;
       ///debug(rem);
        int xx = lower_bound(prfa.begin(), prfa.end(), rem) - prfa.begin();
        //debug(xx);
        if(xx <= n){
            ma[i] = xx;
        }
    }

    for(int i = 1; i<=n; i++){
        int ele1 = prfb[i-1];
        //debug(ele1);
        int rem = k+ele1;
        //debug(rem);
        int xx = lower_bound(prfb.begin(), prfb.end(), rem) - prfb.begin();
        //debug(xx);
        if(xx <= n){
            mb[i] = xx;
        }
    }

    for(int i = 1; i<=n; i++){
        int ele1 = prfc[i-1];
        //debug(ele1);
        int rem = k+ele1;
        //debug(rem);
        int xx = lower_bound(prfc.begin(), prfc.end(), rem) - prfc.begin();
        //debug(xx);
        if(xx <= n){
            mc[i] = xx;
        }
    }

    if(ma.count(1)){
        int aa = ma[1];
        if(mb.count(aa+1)){
            int bb = mb[aa+1];
            if(mc.count(bb+1)){
                cout<<1<<" "<<aa<<" "<<aa+1<<" "<<bb<<" "<<bb+1<<" "<<n<<endl;
                return;
            }
        }

        if(mc.count(aa+1)){
            int cc = mc[aa+1];
            if(mb.count(cc+1)){
                cout<<1<<" "<<aa<<" "<<cc+1<<" "<<n<<" "<<aa+1<<" "<<cc<<endl;
                return;
            }
        }
    }

    if(mb.count(1)){
        int aa = mb[1];
        if(ma.count(aa+1)){
            int bb = ma[aa+1];
            if(mc.count(bb+1)){
                cout<<aa+1<<" "<<bb<<" "<<1<<" "<<aa<<" "<<bb+1<<" "<<n<<endl;
                return;
            }
        }

        if(mc.count(aa+1)){
            int cc = mc[aa+1];
            if(ma.count(cc+1)){
                cout<<cc+1<<" "<<n<<" "<<1<<" "<<aa<<" "<<aa+1<<" "<<cc<<endl;
                return;
            }
        }
    }

    if(mc.count(1)){
        int aa = mc[1];
        if(ma.count(aa+1)){
            int bb = ma[aa+1];
            if(mb.count(bb+1)){
                cout<<aa+1<<" "<<bb<<" "<<bb+1<<" "<<n<<" "<<1<<" "<<aa<<endl;
                return;
            }
        }

        if(mb.count(aa+1)){
            int cc = mb[aa+1];
            if(ma.count(cc+1)){
                cout<<cc+1<<" "<<n<<" "<<aa+1<<" "<<cc<<" "<<1<<" "<<aa<<endl;
                return;
            }
        }
    }

    cout<<-1<<endl;
    

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

