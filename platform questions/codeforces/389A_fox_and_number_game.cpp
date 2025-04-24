#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findHCF(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int n;
    cin>>n;
    vector <int> input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i];
    }
    int hcf = input[0];
    for (int i = 1; i < n; i++) {
        hcf = findHCF(hcf, input[i]);
    }

    cout<<n*hcf;
    return 0;
}