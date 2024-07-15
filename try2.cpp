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
string countOfAtoms(string formula) {
        int n = formula.size();
        vector<int> index(n,0);

        vector<pair<int,int> > bracks;
        int curr = 0;

        stack<int> st;
        int i = 0;

        while(i<n){
            if(isupper(formula[i])){
                curr = i;
                index[curr] = 1;
            }
            if(isdigit(formula[i]) and curr!=-1){
                string xx = "";
                while(i<n and isdigit(formula[i]) ){
                    xx += formula[i];
                    i++;
                }
                index[curr] = stoi(xx);
                i--;
            }

            if(formula[i] == '('){
                st.push(i);
            }

            if(formula[i] == ')'){
                curr = -1;
                int xx = st.top();
                st.pop();
                bracks.push_back({xx, i});
            }
            i++;
        }

        //print(index);

        `
        for(int i = 0; i<bracks.size(); i++){
            pair<int,int> a = bracks[i];   
            int start = a.first;
            int end = a.second;
            
            int tomul ;
            string xx ="";
            int y = end+1;
            if(!isdigit(formula[y])) continue;
            while(y<n and isdigit(formula[y])){
                xx += formula[y];
                y++;
            }

            tomul = stoi(xx);
            for(int j = start; j<end; j++){
                index[j] *= tomul;
            }
        }

        //print(index);


        vector<string> mapping(n, "");
        int curr2 = 0;
        for(int i = 0; i<n; i++){
            if(isupper(formula[i])){
                curr2 = i;
                mapping[curr2] += formula[i];
            }
            if(islower(formula[i])){
                mapping[curr2] += formula[i];
            }
        }

        //print(mapping);
        map<string, int> mp;


        for(int i =0 ;i<n; i++){
            if(mapping[i] != ""){
                //print(mapping[i]);
                //debug(index[i]);
                int xx = index[i];                
                mp[mapping[i]] += xx;
            }
        }

        // for(auto ele : mp){
        //     cout<<ele.first<<ele.second<<endl;
        // }
        // cout<<endl;

        string ans = "";
        for(auto ele: mp){
            ans += ele.first;

            if(ele.second > 1) ans += to_string(ele.second);
        }

        

        return ans;
}

void solve(){
    string str;
    cin>>str;
    cout<<countOfAtoms(str);
}
/* logic ends */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("Error.txt" , "w" , stderr);
    #endif
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
return 0;
}

