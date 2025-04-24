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
    int m;
    cin>>n>>m;
    int n_copy = n;
    int m_copy = m;
    vector<int> p(n+m+1);
    vector<int> t(n+m+1);

    vector<int> tester;
    vector<int> programmer;
    for(int i= 0; i<n+m+1; i++){
        cin>>p[i];
    }

    for(int i= 0; i<n+m+1; i++){
        cin>>t[i];
    }
    print(p);
    print(t);

    for(int i = 0; i<n+m+1; i++){
        if(p[i] > t[i]){
            programmer.push_back(i);
        }
        else tester.push_back(i);
    }

    vector<int> ans;
    vector<char> store(n+m+1);
    store[0]= 'a';
    for(int i = 1; i<n+m+1; i++){
        if(p[i] > t[i] and n_copy>0){
            store[i] = 'p';
            n_copy--;
        }
        else if(t[i] > p[i] and m_copy > 0){
            store[i] = 't';
            m_copy --;
        }
        else {
            if(n_copy > 0){
                store[i] = 'p';
                n_copy --;
            }
            else if(m_copy > 0){
                store[i] = 't';
                m_copy --;
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i<n+m+1; i++){
        if(store[i] == 'p'){
            cnt += p[i];
        }
        else cnt+= t[i];
    }
    //debug(cnt);

    if(p[0] > t[0]){
        store[0] ='p';
    }
    else store[0] = 't';

    set<int> pset;
    set<int> tset;

    for(int i = 1; i<n+m+1; i++){
        if(store[i] == 'p'){
            pset.insert(i);
        }
        else tset.insert(i);
    }



    ans.push_back(cnt);
    for(int i = 1; i<n+m+1; i++){
        if(store[i] == store[i-1]){
            if(store[i] == 't'){
                cnt -= t[i];
                tset.erase(i);
                cnt += t[i-1];
                tset.insert(i-1);
            }
            else {
                cnt -= p[i];
                pset.erase(i);
                cnt += p[i-1];
                pset.insert(i-1);
            }
        }

        else if(store [i] == 't' and store[0] == 't'){
            ans -= 
        }
        else if(store[i] == 't' and store[i-1] == 'p'){
            cnt -= t[i];
            tset.erase(i);
            cnt += p[i-1];
            pset.insert(i-1);
            auto it = tset.end();
            it--;
            int ele = *it;
            int xx = lower_bound(tester.begin(), tester.end(), ele) - tester.begin();
            if(xx <= tester.size()-2){
                xx = tester[xx];
                xx++;
            }
            debug(xx);
            cnt -= p[xx];
            pset.erase(xx);
            store[xx] = 't';
            cnt += t[xx];
            tset.insert(xx);
        }

        else if(store[i] == 'p' and store[i-1] == 't'){
            cnt -= p[i];
            pset.erase(i);
            cnt += t[i-1];
            tset.insert(i-1);
            auto it = pset.end();
            it--;
            int ele = *it;
            int xx = lower_bound(programmer.begin(), programmer.end(), ele) - programmer.begin();
            if(xx <= programmer.size()-2){
                xx = programmer[xx];
                xx++;
            }
            cnt -= t[xx];
            tset.erase(xx);
            store[xx] = 'p';
            cnt += p[xx];
            pset.insert(xx);
        }
        debug(i);
        print(store);

        ans.push_back(cnt);
    }

    print(ans);


    


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

