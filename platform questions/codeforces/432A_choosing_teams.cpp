#include<iostream>
#include<vector>


using namespace std;

int combination(int n){
    return (n * (n-1) * (n-2)) / 6;
}
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> input(n);
    for(int i = 0; i< n ; i++){
        int a;
        cin>>a;
        input[i] = a;
    }
    int barrieer = 5-k;
    int n_copy = n;
    for(int i = 0; i< n ; i++){
        if(input[i] > barrieer) n_copy--;
    }

    if(n_copy < 3) cout<<0;
    else cout<<(n_copy) / 3;

    return 0;   

}