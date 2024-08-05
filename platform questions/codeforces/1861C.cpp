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

bool f(int l1, int r1, int l2, int r2){

    if(l1 > r1) swap(l1, r1);
    if(l2 > r2) swap(l2, r2);
    debug(l1);
    debug(r1);
    debug(l2);
    debug(r2);
    return max(l1, l2) <= min(r1, r2);
}
void solvee(){
    string str;
    cin>>str;
    cout<<str;
}

void solve(){
    string str;
    cin>>str;
    vector<int> v;
    set<int> zero;
    set<int> one;

    pp onne;
    pp zerro;
    int n = str.size();

    if(str[0] == '0'){
        cout<<"NO"<<endl;
        return;
    }

    int zc = 0;
    for(int i = 0; i<n; i++){
        if(str[i] == '0') zc++;
    }

    if(zc == 0){
        cout<<"YES"<<endl;
        return;
    }

    for(int i = 0; i<n; i++){
        if(zero.size() == 1 and zero.count(0)){
            zero.clear();
        }
        if(one.size() ==1 and one.count(0)){
            one.clear();
        }
        if(str[i] == '+'){
            v.push_back(i);
        }
        if(str[i] == '-'){
            int xx = v.back();
            int yy = v[0];
            v.pop_back();
            if(v.empty()){
                zero.clear();
                one.clear();
                continue;
            }
            int newxx = v.back();
            if(zero.count(xx) and one.count(xx)){
                cout<<"NO"<<endl;
                return;
            }
            if(zero.count(xx)){
                zero.erase(xx);
            }
            if(one.count(xx)){
                // cout<<i<<endl;
                one.clear();
                one.insert(newxx);
                one.insert(yy);
            }
        }

        if(str[i] == '1'){

            // debug(*zero.begin());
            // debug(*zero.rbegin());

            if(v.size() == 0){
                continue;
            }

            int xx = v.back();
            int yy = v[0];

            if(zero.size() == 0){
                one.clear();
                one.insert(xx);
                one.insert(yy);
                continue;
            }

            int yyy = *(zero.rbegin());
            int xxx = *(zero.begin());
            int l1 = xx;
            int r1 = yy;
            int l2 = xxx;
            int r2 = yyy;

            
            if(f(l1,r1,l2,r2)){

                cout<<"NO"<<endl;
                return;
            }

            one.clear();
            one.insert(xx);
            one.insert(yy);
        }
        if(str[i] == '0'){
            if(v.size() <= 1){
                cout<<"NO"<<endl;
                return;
            }

            int xx = v.back();
            
            
            if(one.size() == 0){

                zero.insert(xx);
                continue;
            }

            int yyy = *(one.rbegin());
            int xxx = *(one.begin());
            int l1 = xx;
            int r1 = xx;
            int l2 = xxx;
            int r2 = yyy;

            

            if(f(l1,r1,l2,r2)){
                cout<<"NO"<<endl;
                return;
            }

            zero.insert(xx);
        }
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
    // t = 1;
    for(int i = 1; i<=t ; i++){
        // if(i==2638){
        //     solvee();
        // }
        // else solve();
        solve();
    }
return 0;
}

