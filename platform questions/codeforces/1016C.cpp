/**
 *    author: Saurav
 *    created: 2024.10.17 23:20:00
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
void solve(){
    int n;
    cin>>n;
    vector<vector<int> > input(2, vector<int> (n));
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            cin>>input[i][j];
        }
    }

    vector<int> lefttorightfirst(n);
    lefttorightfirst[0] = 0;
    int cnt = 1;
    for(int i = 1; i<n; i++){
        lefttorightfirst[i] = lefttorightfirst[i-1] + input[0][i] * cnt;
        cnt++;
    }
    print(lefttorightfirst);

    vector<int> lefttorightsecond(n);
    lefttorightsecond[0] = 0;
    cnt = 1;
    for(int i = 1; i<n; i++){
        lefttorightsecond[i] = lefttorightsecond[i-1] + input[1][i] * cnt;
        cnt++;
    }
    print(lefttorightsecond);

    vector<int> righttoleftfirst(n);
    righttoleftfirst[n-1] = 0;
    cnt = 1;
    for(int i = n-2; i>=0; i--){
        righttoleftfirst[i] = righttoleftfirst[i+1] + input[0][i] * cnt;
        cnt++;
    }
    print(righttoleftfirst);
    vector<int> righttoleftsecond(n);
    righttoleftsecond[n-1] = 0;
    cnt = 1;
    for(int i = n-2; i>=0; i--){
        righttoleftsecond[i] = righttoleftsecond[i+1] + input[1][i] * cnt;
        cnt++;
    }
    print(righttoleftsecond);

    vector<vector<int> > pahuchnatime(2, vector<int> (n));
    cnt = 0;
    for(int i = 0; i<n; i++){
        int start;
        if(i%2 == 0) start = 0;
        else start = 1;
        pahuchnatime[start][i] = cnt;
        cnt++;
        pahuchnatime[start ^ 1][i] = cnt;
        cnt++;
    }

    print2d(pahuchnatime);

    vector<int> prefixfirst(n);
    vector<int> prefixsecond(n);

    prefixfirst[0] = input[0][0];
    prefixsecond[0] = input[1][0];
    for(int i = 1; i<n; i++){
        prefixfirst[i] = prefixfirst[i-1] + input[0][i];
        prefixsecond[i] = prefixsecond[i-1] + input[1][i];
    }

    vector<int> suffixfirst(n);
    vector<int> suffixsecond(n);

    suffixfirst[n-1] = input[0][n-1];
    suffixsecond[n-1] = input[1][n-1];
    for(int i = n-2; i>=0; i--){
        suffixfirst[i] = suffixfirst[i+1] + input[0][i];
        suffixsecond[i] = suffixsecond[i+1] + input[1][i];
    }
    print(prefixfirst);
    print(prefixsecond);
    print(suffixfirst);
    print(suffixsecond);


    vector<vector<int> >ans(2, vector<int> (n, -1));

    int start = 1;
    for(int i = 0; i<n; i++){
        ans[start][i] = 0;
        start = (start ^ 1);
    }

    print2d(ans);

    vector<vector<int> > abhitak(2, vector<int> (n, 0));

    cnt = 1;

    for(int i = 1; i<n; i++){
        if(i%2 == 0){

            abhitak[0][i] = abhitak[0][i-1] + input[0][i-1] * cnt;
            cnt++;
            abhitak[1][i] = abhitak[0][i] + input[0][i] * cnt;
            cnt++;
        }
        else{

            abhitak[1][i] = abhitak[1][i-1] + input[1][i-1] * cnt;
            cnt++;
            abhitak[0][i] = abhitak[1][i] + input[1][i] * cnt;
            cnt++;
        }
    }

    print2d(abhitak);


    for(int i = 0; i<2; i++){
        for(int j = 0; j<n; j++){
            if(ans[i][j] == -1){
                int res = abhitak[i][j];

                if(i==1 and j== 1){
                    debug(res);
                }

                if(i == 1){
                    if(i==1 and j==1){
                        debug(lefttorightsecond[n-1]);
                        debug(lefttorightsecond[j-1]);
                    }

                    res += lefttorightsecond[n-1] - ((j-1>=0) ?lefttorightsecond[j-1] : 0);
                    if(i==1 and j== 1){
                        // cout<<"YWA"<<endl;
                        debug(res);
                    }

                    // yeh tab hota agar hum time = j par yahan pahucte but hmm time = pahuchne time par pahuch hai
                    // toh suffix sum jitna bhi hai utna se multipy remainnig time me 
                    // remaining time = pahuchnetime[i][j] - j

                    res += suffixsecond[j] * (pahuchnatime[i][j] - j);
                    if(i==1 and j== 1){
                        // cout<<"akjfh"<<endl;
                        debug(res);
                    }

                    // now ab hum upr wale row me last se j tak aayenge 
                    // upr wale row ke last element par pahuchne kaa time hoga pahuchnetime[i][j] + n-1 -j + 1

                    // agar upr wale ke last element pe time = 0 pe pahuchte toh res me add hota righttoleftfirst[j] 
                    // but ham time =  pahuchnetime[i][j] + n-1 -j + 1 par pahuche hai toh pahuchnetime[i][j] + n-1 -j + 1 
                    // me multiply krna pdega suffixfirst[j] ko

                    res += righttoleftfirst[j];
                    if(i==1 and j== 1){
                        // cout<<"hadf"<<endl;
                        debug(res);
                    }
                    res += suffixfirst[j] * (pahuchnatime[i][j] + n-1 - j + 1);
                    if(i==1 and j== 1){
                        // cout<<"afd"<<endl;
                        debug(res);
                    }
                    ans[i][j] = res;
                }
                else{
                    res += lefttorightfirst[n-1] - ((j-1>=0) ?lefttorightfirst[j-1] : 0);
                    res += suffixfirst[j] * (pahuchnatime[i][j] - j);
                    res += righttoleftsecond[j];
                    res += suffixsecond[j] * (pahuchnatime[i][j] + n-1 - j + 1);
                    ans[i][j] = res;
                }
            }
        }
    }

    print2d(ans);

    int toprint = 0;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<n; j++){
            toprint = max(toprint, ans[i][j]);
        }
    }

    cout<<toprint<<endl;
    
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

