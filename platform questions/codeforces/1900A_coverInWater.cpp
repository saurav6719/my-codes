#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans = 0;
        int count = 0;
        int hashCount = 0;
        int consDotCount = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '#') {
                hashCount++;
                consDotCount = 0;
            }
            else{
                consDotCount++;
                count = max(count , consDotCount);
            }
        }
        if(count > 2) ans = 2;
        else{
            ans = n - hashCount;
        }
        cout<<ans<<endl;

    }
    return 0;

}
