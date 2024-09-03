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
#define print2d(v) do { \
                    cout << "vect-- starts" << endl; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "[" << " "; \
                        for (int j = 0; j < v[i].size(); j++) { \
                            cout << v[i][j] << " "; \
                        } \
                        cout << "]" << endl; \
                    } \
                    cout << "vect-- ends" << endl; \
                } while(0)
#define printmap(m) do { \
                    cout << "map-- starts" << endl; \
                    for (auto it = m.begin(); it != m.end(); ++it) { \
                        cout << it->first << " -> " << it->second << endl; \
                    } \
                    cout << "map-- ends" << endl; \
                } while(0)

#define printpp(v) do { \
                    cout << "vect--" << " = [ "; \
                    for (int i = 0; i < v.size(); i++) { \
                        cout << "(" << v[i].first << ", " << v[i].second << ") "; \
                    } \
                    cout << " ]" << endl; \
                } while(0)
#else
#define debug(x)
#define print(v)
#define print2d(v)
#define printmap(m)
#define printpp(v)
#endif
#define endl "\n"
#define int long long int
#define mod 1000000007
#define mn(a,b,c) min(a,min(b,c))
#define mx(a,b,c) max(a,max(b,c))
#define pp pair<int,int>
using namespace std;

/* write core logic here */
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    vector<int> prf(n+1);
    prf[0] = input[0];
    for(int i = 1; i<n; i++){
        prf[i] = input[i] + prf[i-1];
    }
    // print(prf);

    int tsum= prf[n-1];
    debug(tsum);
    prf[n] = prf[n-1];

    vector<int> twoinput = input;
    for(auto ele : input){
        twoinput.push_back(ele);
    }

    vector<int> twoprf((2*n)+5);

    twoprf[0] = twoinput[0];

    for(int i = 1; i<2*n; i++){
        twoprf[i] = twoprf[i-1] + twoinput[i];
    }



    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        l--;
        r--;

        debug(l);
        debug(r);

        // if(l<0) l= 0;

        int xx = l/n;
        debug(xx);
        int suml = tsum * xx;
        debug(suml);
        int last = (n * (xx) )- 1;
        if(last<0) last = -1;
        debug(last);
        int req = l - last;
        debug(req);
        int kahanse = xx;
        int leftsum = kahanse-1 >=0 ? twoprf[kahanse-1] : 0;
        debug(leftsum);
        debug(twoprf[kahanse+req-1]);
        if(req-1>=0) suml += (twoprf[kahanse+req-1] - leftsum);
        debug(suml);

        if(l<0){
            suml = 0;
        }
        debug(suml);

        int yy = r/n;
        debug(yy);
        int sumr = tsum * (yy);
        debug(sumr);
        int lasty = (n * (yy)) - 1 ;
        debug(lasty);
        int kahansey = yy;

        int reqy = r - lasty;
        int leftsumy = yy-1 >= 0 ? twoprf[yy-1] : 0;
        debug(leftsumy);
        debug(reqy);
        debug(twoprf[yy + reqy - 1]);
        sumr += twoprf[yy + reqy - 1] - leftsumy;
        cout<<sumr - suml<<endl;
    }

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

