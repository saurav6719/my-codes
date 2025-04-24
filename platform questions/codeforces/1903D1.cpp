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
    // debug(1<<10);
    // int xx = (1<<10);
    // debug(xx);

    vector<int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }

    vector<int> allset(62);
    for(int i = 0; i<62; i++){
        allset[i] = 1;
        for(int j = 0; j<n; j++){
            int xxx = pow(2, i);
            if((input[j] & (xxx)) == 0){
                allset[i] = 0;
                break;
            }
        }
        
    }
    // reverse(allset.begin(), allset.end());

    print(allset);


    vector<vector<int> > v;


    for(int l = 61; l>= 0; l--){
        vector<int> input_copy2 = input;
        // print(input_copy2);
        int cnt = 0;
        vector<int> xx;
        int abtak = 0;

        for(int i = l; i>=0; i--){
            vector<int> input_copy = input_copy2;
            
            for(int j = 0; j<n; j++){
                input_copy[j] &= ((1<<(l+1))-1);
            }
            // print(input_copy);
            int tomake = (pow(2, i));
            // debug(i);
            // debug(tomake);
            // debug(1<<61);
            // debug(1<<5);
            int sum = 0;
            
            for(int j = 0; j<n; j++){
                int ele = input_copy[j];
                if((tomake & ele)){
                    // cnt++;
                    continue;
                }
                // debug(ele);
                // debug(abtak);
                if(ele > tomake and xx.size() > 0 and xx[0] != 0) ele -= abtak;
                if(ele > tomake and xx.size() > 0 and xx[0] == 0) {
                    ele &= ((1<<(i+1))-1);
                }
                // debug(ele);
                int diff = tomake - (ele);
                // debug(j);
                // debug(diff);

                sum += diff;

                if(cnt==0) input_copy2[j] = tomake;
            }
            if(cnt ==0 ) abtak += (1<<i);
            cnt++;
            xx.push_back(sum);
            // debug(sum);
            // print(xx);
        }
        // sort(xx.begin(), xx.end());
        v.push_back(xx);

    }

    print2d(v);
    while(q--){
        int k;
        cin>>k;
        int ans =0;
        int i = 0;
        bool first = false;

        for(int j = 0; j<v.size(); j++){
            if(k>=v[j][0]){
                i = j;
                k-= v[j][0];

                debug(v[j][0]);
                ans += (pow(2,(v.size() -  j - 1)));

                int yy = v.size() -  j - 1;
                debug(yy);

                if(allset[yy] == 0){
                    first = true;
                }
                break;
            }
        }
        debug(first);

        //576460752302423488
        //576460752302423488

        debug(i);
        debug(ans);
        debug(k);


        while(k>0 and i<v.size()){
            int previ = i;
            for(int j = 1; j<v[i].size(); j++){

                // debug(i);
                // debug(j);
                debug(k);
                debug(ans);
                debug(first);
                // debug(ans);
//110111100000101101101011001110100111011100011100100010000101
//110111100000101101101011001110100111011100100000000000000000

                if(first == true){
                    if(k >= n* pow(2,(v[i].size() -  j - 1))){
                        debug(i);
                        debug(j);
                        debug(k);
                        debug(v[i][j]);
                        ans += (pow(2,(v[i].size() -  j - 1)));
                        debug(pow(2,(v[i].size() -  j - 1)));
                        // debug(ans);
                        k-= pow(2,(v[i].size() -  j - 1));
                        i += j;
                        // debug(k);
                        int yy = v[i].size() -  j - 1;
                        if(allset[yy] == 0){
                            first = true;
                        }

                        break;
                    }
                }
                else{
                    if(k >= v[i][j]){
                        ans += (pow(2,(v[i].size() -  j - 1)));
                        // debug(ans);
                        k-= v[i][j];
                        i += j;

                        int yy = v[i].size() -  j - 1;

                        if(allset[yy] == 0){
                            first = true;
                        }
                        // debug(k);
                        break;
                    }
                }
            }

            if(i==previ and k>0){
                break;
            }

        } 

        cout<<ans<<endl;



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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

