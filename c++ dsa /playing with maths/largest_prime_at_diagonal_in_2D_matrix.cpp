    #include<iostream>
    using namespace std;
    bool isPrime(int n){
        if (n==1) return false;
        for(int i=2; i<=sqrt(n) ; i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int largestPrime(vector<vector<int> > &v){
        int mx=INT_MIN;
        int n=v.size();
        for(int i=0;i<n;i++){
            if(isPrime(v[i][i])){
                mx=max(mx,v[i][i]);

            }
            if(isPrime(v[i][n-i-1])){
                mx=max(mx,v[i][n-i-1]);
                
            }
        }
        return mx;
    }
    int main(){
        vector<vector<int> > v(3,vector<int>(3));
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>v[i][j];
            }
        }
        cout<<largestPrime(v);
        
        return 0;
    }