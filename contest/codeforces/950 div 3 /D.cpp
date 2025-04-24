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


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }


    vector<int> b;

    for(int i = 1; i<n; i++){
        b.push_back(gcd(input[i], input[i-1]));
    }

   //print(b);

    int reqidx = -1;

    

    for(int i = 1; i<b.size(); i++){
        if(b[i] < b[i-1]){
            reqidx = i;
            break;
        }
    }

    //debug(reqidx);

    if(reqidx == -1 or reqidx == b.size() - 1){
        cout<<"YES"<<endl;
        return;
    }

    vector<int> b_new;
    for(int i = 0; i<reqidx; i++){
        b_new.push_back(b[i]);
    }

    //print(b_new);

    int newgcd = gcd(input[reqidx], input[reqidx+2]);
    //debug(newgcd);

    b_new.push_back(newgcd);

    for(int i = reqidx+2; i<b.size(); i++){
        b_new.push_back(b[i]);
    }

   // print(b_new);

    bool check1 = true;


    for(int i = 1; i<b_new.size(); i++){
        if(b_new[i] < b_new[i-1]){
            check1 = false;
            break;
        }
    }

    vector<int> c_new;

    for(int i = 0; i<reqidx-1; i++){
        c_new.push_back(b[i]);
    }

   // print(c_new);

    int nngcd = gcd(input[reqidx - 1], input[reqidx+1]);

    c_new.push_back(nngcd);

    for(int i = reqidx + 1; i<b.size(); i++){
        c_new.push_back(b[i]);
    }

    //print(c_new);

    vector<int> d_new;



    for(int i = 0; i<reqidx-2; i++){
        d_new.push_back(b[i]);
    }

   // print(d_new);
    int nnngcd;
    if(reqidx >=2) nnngcd = gcd(input[reqidx - 2], input[reqidx]);
    

    if(reqidx >= 2) d_new.push_back(nnngcd);
    //print(d_new);

    for(int i = reqidx; i<b.size(); i++){
        d_new.push_back(b[i]);
    }

   // print(d_new);



    bool final = false;
    bool check2 = true;

    bool check3 = true;

    for(int i = 1; i<c_new.size(); i++){
        if(c_new[i] < c_new[i-1]){
            check2 = false;
            break;
        }
    }

    for(int i = 1; i<d_new.size(); i++){
        if(d_new[i] < d_new[i-1]){
            check3 = false;
            break;
        }
    }


    // print(b_new);
    // print(c_new);
    print(d_new);


    final = check1 or check2 or check3;

    if(!final){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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

