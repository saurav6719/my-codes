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
vector<int> add(vector<int> x, vector<int> y){
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int len = min(x.size(), y.size());
    vector<int> ans;
    int carry = 0;
    for(int i = 0; i<len; i++){
        int val = x[i] + y[i] + carry;
        carry = val / 10;
        ans.push_back(val % 10);
    }
    if(x.size() > len){
        for(int i = len; i<x.size(); i++){
            int val = x[i] + carry;
            carry = val / 10;
            ans.push_back(val % 10);
        }
    }

    if(y.size() > len){
        for(int i = len; i<y.size(); i++){
            int val = y[i] + carry;
            carry = val / 10;
            ans.push_back(val % 10);
        }
    }
    while(carry){
        ans.push_back(carry % 10);
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void multiply(vector<int> &ans, int num){
    //multiplying big num by small num
    reverse(ans.begin(), ans.end());
    int carry = 0;
    for(int i = 0; i<ans.size(); i++){
        int prod = ans[i] * num + carry;
        carry = prod / 10;
        ans[i] = prod % 10;
    }

    while(carry){
        ans.push_back(carry% 10);
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
}

vector<int> subtract(vector<int> x, vector<int> y){
    //subtracting y from x
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    vector<int> ans;
    int len = y.size();
    for(int i = 0; i<len; i++){
        if(x[i] < y[i]){
            x[i+1]--;
            ans.push_back(10 + x[i] - y[i]);
        }
        else{
            ans.push_back(x[i] - y[i]);
        }
    }
    if(x.size() > len){
        for(int i = len ; i<x.size(); i++){
            if(x[i] < 0){
                x[i+1]--;
                ans.push_back(10 + x[i]);
            }
            else{
                ans.push_back(x[i]);
            }
        }
    }
    reverse(ans.begin(), ans.end());

    //remove trailing zeroes
    vector<int> result;
    int i = 0;
    while(ans[i] == 0){
        i++;
    }
    for(; i<ans.size(); i++){
        result.push_back(ans[i]);
    }
    if(result.size() == 0){
        result.push_back(0);
    }
    return result;
}

vector<int>  divide(vector<int> x, int num){
    vector<int> ans;
    int rem =0;
    for(int i = 0; i<x.size(); i++){
        if(rem){
            rem = rem * 10 + x[i];
            ans.push_back(rem / num);
            rem = rem % num;
        }
        else{
            if(x[i] < num){
                rem += x[i];
                ans.push_back(0);
            }
            else{
                rem = x[i] % num;
                ans.push_back(x[i]/num);
            }
        }
    }
    //remove trailing zeroes
    vector<int> res;
    int i = 0;

    while(ans[i] == 0){
        i++;
    }
    for(; i<ans.size(); i++){
        res.push_back(ans[i]);
    }
    return res;
}

vector<int>  modulo(vector<int> x,  int num){
    //modulo x with num
    vector<int> divi = divide(x,num);
    multiply(divi, num);
    vector<int> ans = subtract(x,divi);
    return ans;
}


void solve(){

    //ans = n(n+1)(2n+1)/6 + m(m+1)(2m+1)/6 + m(m+1)/2;
    int n;
    cin>>n;
    int m = n-1;
    vector<int> ans;
    ans.push_back(1);
    multiply(ans, n);
    multiply(ans, n+1);
    multiply(ans, 2*n+1);
    ans = divide(ans, 6);
    // print(ans);
    vector<int> ans2;
    ans2.push_back(1);
    multiply(ans2,m);
    multiply(ans2, m+1);
    multiply(ans2,2*m+1);
    ans2 = divide(ans2, 6);
    vector<int> ans3;
    ans3.push_back(1);
    multiply(ans3,m);
    multiply(ans3, m+1);
    ans3 = divide(ans3, 2);

    ans = add(ans, ans2);
    ans = add(ans, ans3);

    multiply(ans, 2022);

    ans = modulo(ans , mod);

    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i];
    }
    cout<<endl;

    
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

