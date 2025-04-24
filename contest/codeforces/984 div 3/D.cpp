/**
 *    author: Saurav
 *    created: 2024.11.02 20:03:55
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
int spiralTraverse(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    int ans =0;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        string str= "";
        // Traverse top row (left to right)
        for (int i = left; i <= right; i++) {
            str +=( matrix[top][i] + '0');
        }
        top++;

        // Traverse right column (top to bottom)
        for (int i = top; i <= bottom; i++) {
            str += (matrix[i][right] + '0');
        }
        right--;

        // Traverse bottom row (right to left)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                str += (matrix[bottom][i] + '0');
            }
            bottom--;
        }

        // Traverse left column (bottom to top)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                str += (matrix[i][left] + '0');
            }
            left++;
        }

        print(str);

        for(int i = 0; i < str.size(); i++){
            string s = "";
            s += str[i];
            s += str[(i + 1) % str.size()];  // Corrected
            s += str[(i + 2) % str.size()];  // Corrected
            s += str[(i + 3) % str.size()];  // Corrected

            print(s);
            if(s == "1543"){
                ans++;
            }
        }

    }

    return ans;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> input(n, vector<int> (m));
    for(int i = 0; i<n; i++){
            string s;
            cin>>s;
        for(int j = 0; j<m; j++){
            input[i][j] = s[j] - '0';
            
        }
    }

    print2d(input);

    cout << spiralTraverse(input) << endl;
    
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

