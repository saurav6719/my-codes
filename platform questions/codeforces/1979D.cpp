/**
 *    author: Saurav
 *    created: 2024.10.18 16:33:28
 **/

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

void solvee(){
    int n;
    int k;
    cin>>n>>k;
    string str;
    cin>>str;

    cout<<n<<"-"<<k<<"-"<<str<<endl;
}
void solve(){
    int n;
    int k;
    cin>>n>>k;
    string str;
    cin>>str;

    set<char> st;
    for(auto x : str){
        st.insert(x);
    }

    if(st.size() == 1){
        if(k != n){
            cout<<-1<<endl;
            return;
        }
        cout<<k<<endl;
        return;
    }

    int block = 1;

    for(int i = n-2; i>=0; i--){
        if(str[i] != str[i+1]){
            break;
        }
        block++;
    }

    if(block > k){
        cout<<-1<<endl;
        return;
    }

    int required = k - block;
    debug(required);

    if(required == 0){

        int p = -1;

        for(int i = 0; i<n; i++){
            int idx = i;
            
            int cnt = 1;
            while(i+1<n && str[i] == str[i+1]){
                i++;
                cnt++;
            }

            debug(idx);
            debug(cnt);
            if(cnt != 2*k and cnt != k){
                cout<<-1<<endl;
                return;
            }
            if(cnt == 2*k){
                p = idx + k- 1;
                break;
            }
        }

        debug(p);

        if(p==-1){
            for(int i = 0; i<n; i++){
                if(str[i] == str.back()) continue;
                p = i;
                break;
            }

            p+= k-1;

        }

        string str2 = "";

        for(int i = 0; i<=p; i++){
            str2 += str[i];
        }

        reverse(str2.begin(), str2.end());

        string str3 = str.substr(p+1);

        print(str2);
        print(str3);

        string ans = str3 + str2;

        print(ans);

        for(int i = 0; i<n; i++){
            int idx = i;

            
            
            int cnt = 1;
            while(i+1<n && ans[i] == ans[i+1]){
                i++;
                cnt++;
            }
            if(cnt != k){
                cout<<-1<<endl;
                return;
            }
            
        }

        cout<<p + 1<<endl;
        return;

    }
    else{
        char ch = str.back();

        int p = -1;

        // i need consecutive ch required times 
        

        for(int i = 0; i<n; i++){
            int idx = i;
            if(str[i] == ch){
                int cnt = 1;
                while(i+1<n && str[i] == str[i+1]){
                    i++;
                    cnt++;
                }

                if(cnt == required) {
                    p = idx;
                    break;
                }

                if(cnt > k){
                    p = idx;
                    break;
                }

            }
        }

        debug(p);

        if(p == -1){
            cout<<-1<<endl;
            return;
        }

        string str2 = "";

        for(int i = 0; i<p+required; i++){
            str2 += str[i];
        }
 
        reverse(str2.begin(), str2.end());

        string str3 = str.substr(p+required);

        print(str2);
        print(str3);

        string ans = str3 + str2;

        print(ans);

        for(int i = 0; i<n; i++){
            int idx = i;
            
            int cnt = 1;
            while(i+1<n && ans[i] == ans[i+1]){
                i++;
                cnt++;
            }
            if(cnt != k){
                cout<<-1<<endl;
                return;
            }
            
        }

        cout<<p + required<<endl;
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
        //cout<<"Case #"<<i<<": ";
        if(i==2346) solvee();
        else solve();
        
    }
return 0;
}

