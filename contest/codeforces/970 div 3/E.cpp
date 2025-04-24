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
int charToIndex(char c) {
    return c - 'a';
}

char findMostFrequent(const vector<int>& counts) {
    int max_count = 0;
    char most_frequent = '#';
    for (int i = 0; i < 26; ++i) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            most_frequent = 'a' + i;
        }
    }
    return most_frequent;
}


void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    str = '#' + str;

    print(str);
    if(n==1){
        cout<<1<<endl;
        return;
    }

    if(n%2==0){
        map<char,int> mpodd;
        map<char,int> mpeven;
        for(int i = 1; i<=n; i++){
            if(i&1){
                mpodd[str[i]]++;
            }
            else mpeven[str[i]]++;
        }

        int numodd = n/2;
        int numeven = n/2;
        int maxiodd = 0;
        int maxieven = 0;

        for(auto ele : mpodd){
            maxiodd = max(maxiodd, ele.second);
        }

        for(auto ele : mpeven){
            maxieven = max(maxieven , ele.second);
        }

        cout<<numodd - maxiodd + numeven - maxieven<<endl;
        return;
    }


    vector<vector<int>> prefix_even(n + 5, vector<int>(26, 0));
    vector<vector<int>> prefix_odd(n + 5, vector<int>(26, 0));

    for (int i = 1; i <= n; i++) {
        char ch = str[i];
        if (i % 2 == 0) {
            prefix_even[i + 1] = prefix_even[i];
            prefix_even[i + 1][charToIndex(ch)]++;
            prefix_odd[i + 1] = prefix_odd[i];
        } else {
            prefix_odd[i + 1] = prefix_odd[i];
            prefix_odd[i + 1][charToIndex(ch)]++;
            prefix_even[i + 1] = prefix_even[i];
        }
    }

    vector<vector<int>> suffix_even(n + 5, vector<int>(26, 0));
vector<vector<int>> suffix_odd(n + 5, vector<int>(26, 0));

// Traverse from right to left
for (int i = n; i >= 1; i--) {
    char ch = str[i];

    if (i % 2 == 0) {
        // Update even suffix count for character at index `i`
        suffix_even[i-1] = suffix_even[i];
        suffix_even[i-1][charToIndex(ch)]++;
        suffix_odd[i-1] = suffix_odd[i];
    } else {
        // Update odd suffix count for character at index `i`
        suffix_odd[i-1] = suffix_odd[i];
        suffix_odd[i-1][charToIndex(ch)]++;
        suffix_even[i-1] = suffix_even[i];
    }
}

    print2d(prefix_even);
    print2d(prefix_odd);
    print2d(suffix_even);
    print2d(suffix_odd);

    int opreq ;

    string newstr = str.substr(2);
    newstr = '#'+ newstr;

    print(newstr);
    
    map<char,int> mpodd;
    map<char,int> mpeven;
    for(int i = 1; i<=newstr.size(); i++){
        if(i&1){
            mpodd[newstr[i]]++;
        }
        else mpeven[newstr[i]]++;
    }

    int numodd = newstr.size() /2;
    int numeven = newstr.size()/2;
    int maxiodd = 0;
    int maxieven = 0;

    for(auto ele : mpodd){
        maxiodd = max(maxiodd, ele.second);
    }

    for(auto ele : mpeven){
        maxieven = max(maxieven , ele.second);
    }

    debug(maxiodd);
    debug(maxieven);

    opreq = numodd - maxiodd + numeven - maxieven;
    debug(opreq);

    for(int i = 2; i<=n; i++){
        vector<int> neweven(26,0);
        vector<int> newodd(26,0);

        for(int j = 0; j < 26; j++) {
        neweven[j] = prefix_even[i][j] + suffix_odd[i][j];
    }

    // Update `newodd` with values from `prefix_odd` and `suffix_even`
    for(int j = 0; j < 26; j++) {
        newodd[j] = prefix_odd[i][j] + suffix_even[i][j];
    }
        int curropreq = 0;

        int countOfprefixeven = (i-1)/2;

        int countOfprefixeodd = (i-1)/2 +(i-1)%2;

        int countOfsuffixEven = (n-i) / 2 + (n-i)%2;

        int countOfsuffixOdd = (n-i) / 2;

        int countofeven = countOfprefixeven + countOfsuffixEven;
        int countofodd = countOfprefixeodd + countOfsuffixOdd;

        print(neweven);
        print(newodd);

        debug(countOfprefixeven);
        debug(countOfsuffixEven);
        debug(countOfprefixeodd);
        debug(countOfsuffixOdd);

        int xx = *max_element(neweven.begin(), neweven.end());
        debug(xx);

        int yy = *max_element(newodd.begin(), newodd.end());
        debug(yy);

        curropreq =countofeven - xx + countofodd - yy;
        debug(i);
        debug(curropreq);

        opreq = min(opreq , curropreq);
    }

    cout<<opreq+1<<endl;

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
    while(t--){
        solve();
    }
return 0;
}

