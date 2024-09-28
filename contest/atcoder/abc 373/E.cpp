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
int findJustSmallerElement(const vector<int>& arr, int x) {
    // Find the first element that is not less than x
    int it = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    

    if(it != arr.size()-1){
        if(arr[it+1] == arr[it]) return arr[it+1];
    }
    // If iterator points to the first element, no smaller element exists
    if (it == 0) {
        return 0; // No smaller element exists
    }


    
    // Move back to get the just smaller element
    --it;
    return arr[it];
}
bool comparator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;  // Sort in ascending order based on the first element
}

void solve(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<int> input(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin>>input[i];
        sum += input[i];
    }

    int bachavote = k - sum;

    debug(bachavote);

    vector<pp> inputidx;

    for(int i = 0; i < n; i++){
        inputidx.push_back({input[i], i});
    }

    sort(inputidx.begin(), inputidx.end(), comparator);

    for(auto ele : inputidx){
        cout<<ele.first<<" "<<ele.second<<endl;
    }

    vector<int> ans(n);

    vector<int> input_copy = input;

    sort(input_copy.begin(), input_copy.end());

    int secondmax = 0;
    int i = n-1;
    while(i>=0 and input_copy[i] == input_copy[n-1])i--;

    if(i>=0) secondmax = input_copy[i];
    debug(secondmax);


    int pahuchna = input_copy[n-m];
    debug(pahuchna);

    for(int i = 0; i<n; i++){
        int xx = pahuchna - inputidx[i].first;
        debug(xx);
        if(xx > bachavote) {
            ans[inputidx[i].second] = -1;
            continue;
        }
        int bach = bachavote - xx;
        debug(bach);
        int toadd = bach / 2+ bach % 2;
        ans[inputidx[i].second] = xx + toadd;

        if(xx<0) xx=0;


        if(xx==0){
            int zz = findJustSmallerElement(input_copy, inputidx[i].first);
            debug(zz);
            int diff = inputidx[i].first - zz;
            debug(diff);
            int bach = bachavote - diff;
            int toadd = bach / 2+ bach % 2;
            ans[inputidx[i].second] = xx + toadd;
        }
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
    // cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

