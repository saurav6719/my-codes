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
// Function to find the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find the least common multiple (LCM)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}


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
    int n;
    int x;
    int y;
    cin>>n>>x>>y;
    int divibyx = n/x;
    int divibyy = n/y;
    int lccm = lcm(x,y);
    int divibylcm = n/lccm;
    int solex = divibyx - divibylcm;
    int soley = divibyy - divibylcm;
    // find sum from 1 to soley
    // soley(soley+1)/2
    vector<int> tos;
    tos.push_back(1);
    multiply(tos,soley);
    multiply(tos,soley+1);
    vector<int> toss = divide(tos,2);

    // for(int i = 0; i<toss.size(); i++){
    //     cout<<toss[i];
    // }
    // cout<<endl;

    //find sum from n to n-solex;

    int xx = n-solex;

    vector<int> tosss;
    tosss.push_back(1);
    multiply(tosss,xx);
    multiply(tosss,xx+1);
    vector<int> tossss = divide(tosss,2);



    vector<int> saurav;
    saurav.push_back(1);
    multiply(saurav,n);
    multiply(saurav, n+1);
    vector<int> notsaurav = divide(saurav,2);

    vector<int> ans1 = subtract(notsaurav, tossss);
    bool isneg = false;
    
    // for(int i = 0; i<ans1.size(); i++){
    //     cout<<ans1[i];
    // }
    // cout<<endl;


    
    if(toss.size() > ans1.size()) isneg = true;

    if(toss.size() == ans1.size()){
        for(int i = 0; i<ans1.size(); i++){
            if(toss[i] < ans1[i]){
                break;
            }
            if(toss[i] > ans1[i]){
                isneg = true;
                break;
            }

        }
    }

    vector<int> ans;

    if(!isneg) ans = subtract(ans1, toss);
    else ans = subtract(toss,ans1);
    //cout<<isneg<<endl;
    if(!isneg){
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i];
        }
    }

    else{
        cout<<'-';
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i];
        }
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
    for(int i = 1; i<=t; i++){
        solve();
        
    }
return 0;
}

