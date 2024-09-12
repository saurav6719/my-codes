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


int left(int i, vector<int> &input, vector<int> &visited){
    int ans = 0;
    

    for(int index = i; index>=0; index--){
        if(visited[index] == 1){
            return ans;
        }
        if(input[index] == 0){
            ans++;
            break;
        }
    }

    return ans;
}

int right(int i, vector<int> &input, vector<int> &visited){
    int ans = 0;
    

    for(int index = i; index<input.size(); index++){
        if(visited[index] == 1){
            return ans;
        }
        if(input[index] == 0){
            ans++;
            break;
        }
    }

    return ans;
}


void solve(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    vector<int> input_copy ;

    input_copy.push_back(input[0]);


    for(int i = 1; i<n; i++){
        if(input[i]== 1 and input[i-1] == 1){
            continue;
        }
        if(input[i] == 1 and input[i-1] == 2){
            continue;
        }
        if(input[i] == 2 and input[i-1] == 2){
            continue;
        }

        input_copy.push_back(input[i]);
    }

    n = input_copy.size();

    input = input_copy;

    print(input);

    set<int> twos;
    set<int> ones;
    set<int> zeroes;

    for(int i = 0; i<n; i++){
        if(input[i] == 1) ones.insert(i);
        else if(input[i] == 2) twos.insert(i);
        else zeroes.insert(i);
    }

    int twoscount = 0;
    int ans = 0;
    int xx = twos.size();

    vector<int> visited(n, 0);
    while(twoscount < xx){
        debug(twoscount);
        int currtwo = *(twos.begin());
        debug(currtwo);
        ans++;
        int index = currtwo;
        //goint left;
        for(int i = index; i>=0; i--){
            if(visited[i] == 1) break;
            debug(i);
            if(input[i] == 0) {
                zeroes.erase(i);
                visited[i] = 1;
                break;
            }
            else if(input[i] == 1){
                ones.erase(i);
                visited[i] = 1;
            }
            else{
                twos.erase(i);
                visited[i] = 1;
                twoscount++;
            }
        }

        //going right

        for(int i = index+1; i<n; i++){
            if(visited[i] == 1) break;
            debug(i);
            if(input[i] == 0) {
                zeroes.erase(i);
                visited[i] = 1;
                break;
            }
            else if(input[i] == 1){
                ones.erase(i);
                visited[i] = 1;
            }
            else{
                twos.erase(i);
                visited[i] = 1;
                twoscount++;
            }
        }
    }

    

    print(visited);

    int onescount = 0;
    int yy = ones.size();
    debug(yy);
    while(onescount < yy){
        ans++;
        int currone = *(ones.begin());
        debug(currone);

        if(currone - 1>=0 and visited[currone - 1] == 0){
            visited[currone] = 1;
            visited[currone-1] = 1;
            ones.erase(currone);
            if(zeroes.count(currone - 1)){
                zeroes.erase(currone - 1);
            }
            onescount++;
            continue;
        }

        else if(currone + 1 < n and visited[currone + 1] == 0){
            visited[currone] = 1;
            visited[currone+1] = 1;
            ones.erase(currone);
            if(zeroes.count(currone + 1)){
                zeroes.erase(currone + 1);
            }
            onescount++;
            continue;
        }

        else {
            visited[currone] = 1;
            ones.erase(currone);
            onescount++;
        }
    }

    

    ans += zeroes.size();
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

