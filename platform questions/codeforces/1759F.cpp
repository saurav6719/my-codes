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
vector<int> f(vector<int> &input, int p){
    print(input);
    debug(p);
    vector<int> ans;
    ans.push_back(0);
    for(auto ele : input){
        ans.push_back(ele);
    }
    int carry = 0;
    for(int i = ans.size() - 1; i>=0; i--){
        int &ele = ans[i];
        debug(ele);
        ele += carry;
        if(i==ans.size() - 1){
            ele++;
        }
        debug(ele);
        if(ele >= p){
            carry = 1;
            ele = 0;
        }
        else{
            carry = 0;
        }
    }   
    return ans;
}
void solvee(){
    int n,p;
    cin>>n>>p;
    vector<int> input(n);
    set<int> s;
    for(int i =0; i<n; i++){
        cin>>input[i];
        s.insert(input[i]);
    }

    cout<<n<<"->"<<p<<"->";

    for(auto x : input){
        cout<<x<<"->";
    }
    cout<<endl;

}
void solve(){
    int n,p;
    cin>>n>>p;
    vector<int> input(n);
    set<int> s;
    for(int i =0; i<n; i++){
        cin>>input[i];
        s.insert(input[i]);
    }

    bool piche = false;

    int last = input.back();
    for(int i = 0; i<last; i++){
        if(s.find(i) == s.end()){
            piche = true;
            break;
        }
    }

    if(piche){
        int ans = 0;
        ans += p-last;
        vector<int> newinput = input;
        newinput[n-1] = p-1;
        print(newinput);

        vector<int> newans = f(newinput, p);

        for(auto ele : newans){
            s.insert(ele);
        }

        print(newans);

        int tocheckfrom = last-1;
        int kahantak = 0;

        for(int i = tocheckfrom; i>=0; i--){
            if(s.find(i) == s.end()){
                kahantak = i;
                break;
            }
        }

        ans += kahantak;
        cout<<ans<<endl;
        return;
    }
    else{
        int tocheckfrom = p-1;
        int kahantak = last;
        for(int i = tocheckfrom; i>=last; i--){
            if(s.find(i) == s.end()){
                kahantak = i;
                break;
            }
        }

        int ans = 0;

        ans += kahantak - last;
        cout<<ans<<endl;
        return;
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
    for(int i = 1; i<=t; i++){
        if(i==64){
            solvee();
        }
        else solve();
    }
return 0;
}

