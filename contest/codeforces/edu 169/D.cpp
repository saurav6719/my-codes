#include <bits/stdc++.h>
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

std::vector<int> findClosestNumbers(const std::vector<int>& vec, int target) {
    std::vector<int> result;

    if (vec.size() == 0) {
        return result; // Return empty if vector size is zero
    }

    if (vec.size() == 1) {
        result.push_back(vec[0]); // Return the only element if vector size is one
        return result;
    }

    // Find the lower bound for the target
    auto it = std::lower_bound(vec.begin(), vec.end(), target);

    int leftIndex = it - vec.begin() - 1; // Element to the left
    int rightIndex = it - vec.begin();    // Element to the right

    // Check closest elements around the lower bound
    int closestLeft = (leftIndex >= 0) ? vec[leftIndex] : INT_MAX;
    int closestRight = (rightIndex < vec.size()) ? vec[rightIndex] : INT_MAX;

    // Determine the closest elements
    if (closestLeft == INT_MAX) {
        result.push_back(closestRight);
    } else if (closestRight == INT_MAX) {
        result.push_back(closestLeft);
    } else {
        
            result.push_back(closestLeft);
            result.push_back(closestRight);
        
    }

    return result;
}

void processCombination(const vector<int>& positions, int l, int r, set<int>& st2) {
    vector<int> v1 = findClosestNumbers(positions, l);
    vector<int> v2 = findClosestNumbers(positions, r);
    
    for(auto ele : v1) st2.insert(ele);
    for(auto ele : v2) st2.insert(ele);
}

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> bg, br, by, gr, gy, ry;
    vector<string> input(n+1);

    for(int i = 0; i < n; i++){
        string str;
        cin>>str;

        if(str == "BG") bg.push_back(i+1);
        if(str == "BR") br.push_back(i+1);
        if(str == "BY") by.push_back(i+1);
        if(str == "GR") gr.push_back(i+1);
        if(str == "GY") gy.push_back(i+1);
        if(str == "RY") ry.push_back(i+1);

        input[i+1]= str;
    }

    print(gr);

    while(q--){
        int l, r;
        cin>>l>>r;

        if(l == r){
            cout<<0<<endl;
            continue;
        }

        char ch1 = input[l][0];
        char ch2 = input[l][1];
        char ch3 = input[r][0];
        char ch4 = input[r][1];

        set<char> st = {ch1, ch2, ch3, ch4};

        if(st.size() < 4){
            cout << abs(l - r) << endl;
            continue;
        }

        set<int> st2;

        string ss1 = ""; ss1 += ch1; ss1 += ch3;
        string ss2 = ""; ss2 += ch1; ss2 += ch4;
        string ss3 = ""; ss3 += ch2; ss3 += ch3;
        string ss4 = ""; ss4 += ch2; ss4 += ch4;
        print(ss1);
        print(ss2);
        print(ss3);
        print(ss4);

        if(ss1 == "BG" || ss1 == "GB") processCombination(bg, l, r, st2);
        if(ss1 == "BR" || ss1 == "RB") processCombination(br, l, r, st2);
        if(ss1 == "BY" || ss1 == "YB") processCombination(by, l, r, st2);
        if(ss1 == "GR" || ss1 == "RG") processCombination(gr, l, r, st2);
        if(ss1 == "GY" || ss1 == "YG") processCombination(gy, l, r, st2);
        if(ss1 == "RY" || ss1 == "YR") processCombination(ry, l, r, st2);

        if(ss2 == "BG" || ss2 == "GB") processCombination(bg, l, r, st2);
        if(ss2 == "BR" || ss2 == "RB") processCombination(br, l, r, st2);
        if(ss2 == "BY" || ss2 == "YB") processCombination(by, l, r, st2);
        if(ss2 == "GR" || ss2 == "RG") processCombination(gr, l, r, st2);
        if(ss2 == "GY" || ss2 == "YG") processCombination(gy, l, r, st2);
        if(ss2 == "RY" || ss2 == "YR") processCombination(ry, l, r, st2);

        if(ss3 == "BG" || ss3 == "GB") processCombination(bg, l, r, st2);
        if(ss3 == "BR" || ss3 == "RB") processCombination(br, l, r, st2);
        if(ss3 == "BY" || ss3 == "YB") processCombination(by, l, r, st2);
        if(ss3 == "GR" || ss3 == "RG") processCombination(gr, l, r, st2);
        if(ss3 == "GY" || ss3 == "YG") processCombination(gy, l, r, st2);
        if(ss3 == "RY" || ss3 == "YR") processCombination(ry, l, r, st2);

        if(ss4 == "BG" || ss4 == "GB") processCombination(bg, l, r, st2);
        if(ss4 == "BR" || ss4 == "RB") processCombination(br, l, r, st2);
        if(ss4 == "BY" || ss4 == "YB") processCombination(by, l, r, st2);
        if(ss4 == "GR" || ss4 == "RG") processCombination(gr, l, r, st2);
        if(ss4 == "GY" || ss4 == "YG") processCombination(gy, l, r, st2);
        if(ss4 == "RY" || ss4 == "YR") processCombination(ry, l, r, st2);

        int ans = INT_MAX;
        for(auto ele : st2){
            ans = min(ans , abs(l-ele) + abs(r-ele));
        }

        debug(st2.size());

        if(st2.size() == 0){
            cout<<-1<<endl;
            continue;
        }
        else cout<<ans<<endl;
        continue;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
