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

string getbinary(int x){
    bitset<35> b(x);
    return b.to_string();
}

int binaryToDecimal( std::string& binaryString) {
    int decimal = 0;
    int power = 1; // Represents 2^0 initially

    // Iterate through the binary string from right to left
    for (int i = binaryString.length() - 1; i >= 0; --i) {
        if (binaryString[i] == '1') {
            decimal += power;
        }
        power *= 2; // Increase the power of 2 for the next bit
    }

    return decimal;
}


std::string setBitsTillFirstSet(std::string binaryString) {
    int setIndex = binaryString.find('1'); // Find index of first set bit

    // If there are no set bits, return the same string
    if (setIndex == -1)
        return binaryString;

    // Set all bits to the left of the first set bit to '1'
    for (int i = 0; i < setIndex; ++i) {
        binaryString[i] = '1';
    }

    return binaryString;
}



std::string setBitsTillFirstUnset(std::string binaryString) {
    int unsetIndex = binaryString.find('0'); // Find index of first unset bit

    // If there are no unset bits, return the same string
    if (unsetIndex == -1)
        return binaryString;

    // Set all bits to the right of the first unset bit to '1'
    for (int i = unsetIndex - 1; i >= 0; --i) {
        binaryString[i] = '1';
    }

    return binaryString;
}



void solve(){
    int n;
    int m;
    cin>>n>>m;
    int X = max(0ll, n-m);
    int Y = n+m;
    string str1 = getbinary(X);
    string str2 = getbinary(Y);
    string ans = "";
    // print(str1);
    // print(str2);
    bool check = false;
    for(int i = 0; i<str1.size(); i++){
        if(str1[i] == str2[i] and !check){
            ans += str1[i];
        }
        else if(str1[i] != str2[i] and !check){
            check = true;
            ans += '1';
        }
        else ans += '1';
    }


    int res = 0;
    int j = 0;
    for(int i = ans.size() - 1; i>=0; i--){
        if(ans[i] == '1'){
            res += (1<<j);
        }
        j++;
    }
    //print(ans);

    cout<<res<<endl;

    

    //}

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

