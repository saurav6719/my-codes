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
    int k1;
    cin>>k1;
    int k2;
    cin>>k2;

    vector<int> input1(n);
    vector<int> input2(n);
    for(int i = 0; i<n; i++){
        cin>>input1[i];
    }

    for(int i = 0; i<n;i++){
        cin>>input2[i];
    }

    vector<int> v(n);
    for(int i = 0; i<n; i++){
        v[i] = abs(input1[i] - input2[i]);
    }

    int op = k1+k2;

    if(n==1){
        int xx = v[0];
        int diff = xx;
        if(diff >= op){
            xx -= op;
            cout<<xx*xx<<endl;
            return;
        }
        else{
            op -= diff;
            if(op & 1){
                cout<<1<<endl;
                return;
            }
            cout<<0<<endl;
            return;
        }
    }

    priority_queue<int, vector<int>  > pq;

    for(auto ele : v){
        pq.push(ele);
    }

    debug(pq.top());

    
    while(op>0){
        int p1 = pq.top(); 
        pq.pop();
        int p2 = pq.top();

        int diff = p1-p2;

        if(diff == 0){
            if(p1 == p2 and p1 == 0){
                if(op & 1){
                    p1--;
                    pq.push(p1);
                    break;
                }
                else{
                    pq.push(p1);
                    break;                
                }
            }
            else{
                if(op >= 2){
                    p1--;
                    pq.pop();
                    p2--;
                    pq.push(p1);
                    pq.push(p2);
                    op-=2;
                    continue;
                }
                else{
                    p1--;
                    pq.push(p1);
                    break;
                }
            }

        }

        if(op >= diff){
            p1 -= diff;
            pq.push(p1);
            op -= diff;
            if(op == 0){
                break;
            }
        }
        else{
            p1 -= op;
            pq.push(p1);
            break;
        }
    }

    int ans = 0;
    while(!pq.empty()){
        int p1 = pq.top();
        pq.pop();
        ans+= (p1*p1);
    }

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
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

