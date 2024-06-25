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

void countSubmatrix(const vector<vector<int>>& matrix, int startRow, int startCol, int k, vector<int>& count0, vector<int>& count1) {
    count0[startRow - 1] = 0;
    count1[startRow - 1] = 0;
    for (int i = 0; i < k; ++i) {
        count0[startRow - 1] += (matrix[startRow - 1][startCol + i] == 0);
        count1[startRow - 1] += (matrix[startRow - 1][startCol + i] == 1);
    }
}


void traverseSubmatrices(const vector<vector<int>>& matrix, int n, int m, int k, set<int> &st) {
    vector<int> count0(n, 0); // Vector to store count of 0s in each row
    vector<int> count1(n, 0); // Vector to store count of 1s in each row

    for (int i = 0; i <= n - k; ++i) {
        for (int j = 0; j <= m - k; ++j) {
            // Count 0s and 1s for the first submatrix in the row
            if (j == 0) {
                for (int x = 0; x < k; ++x) {
                    for (int y = 0; y < k; ++y) {
                        count0[i + x] += (matrix[i + x][j + y] == 0);
                        count1[i + x] += (matrix[i + x][j + y] == 1);
                    }
                }
            } else {
                // Adjust counts by removing the leftmost column and adding the rightmost column
                for (int x = 0; x < k; ++x) {
                    count0[i + x] -= (matrix[i + x][j - 1] == 0);
                    count1[i + x] -= (matrix[i + x][j - 1] == 1);
                    count0[i + x] += (matrix[i + x][j + k - 1] == 0);
                    count1[i + x] += (matrix[i + x][j + k - 1] == 1);
                }
            }

            // Sum up counts for the current submatrix
            int total0 = 0, total1 = 0;
            for (int x = 0; x < k; ++x) {
                total0 += count0[i + x];
                total1 += count1[i + x];
            }

            st.insert(abs(total0 - total1));
            
        }
        // Reset the counts for the next row of submatrices
        fill(count0.begin(), count0.end(), 0);
        fill(count1.begin(), count1.end(), 0);
    }
}



void solve(){
    int n;
    int m;
    int k;
    cin>>n>>m>>k;
    vector<vector<int> > input(n, vector<int> (m));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>input[i][j];
        }
    }

    vector<vector<int> > input2(n ,vector<int> (m));

    for(int i = 0; i<n; i++){
        string str;
        cin>>str;

        for(int j = 0; j<m; j++){
            input2[i][j] = str[j] - '0';
        }
    }


    int red = 0;
    int blue = 0;


    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(input2[i][j] == 0){
                red += input[i][j];
            }

            else {
                blue += input[i][j];
            }
        }
    }

    int diff = abs(red - blue);

    if(diff == 0){
        cout<<"YES"<<endl;
        return;
    }

    debug(diff);

    set<int> st;


    for(auto ele: st){
        cout<<ele<<" ";
    }

    cout<<endl;


    traverseSubmatrices(input2, n,m,k,st);

    if(st.size() > 1){
        cout<<"YES"<<endl;
        return;
    }

    else{
        for(auto ele : st){
            if(ele == 0){
                cout<<"NO"<<endl;
                return;
            }
            if(diff % ele == 0){
                cout<<"YES"<<endl;
                return;
            }
            else{
                cout<<"NO"<<endl;
                return;
            }
        }
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
    while(t--){
        solve();
    }
return 0;
}

