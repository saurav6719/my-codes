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
    bitset<40> b(x);
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
    if(m==0){
        cout<<n<<endl;
        return;
    }
    int ff;
    if(n>0)ff = (n | n-1 | n-2);
    else ff = (n|n+1);
    int xx = ff;
    debug(xx);
    // while(true){
        string str = getbinary(xx);
        print(str);
        string str2 = setBitsTillFirstUnset(str);
        print(str2);

        int yy = binaryToDecimal(str2);
        debug(yy);
        int ans = xx;
        if(yy - n <= m){
            string str3  = setBitsTillFirstSet(str2);
            ans = binaryToDecimal(str3);
        }

        else {
            cout<<ans<<endl;
            return;
        }
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

