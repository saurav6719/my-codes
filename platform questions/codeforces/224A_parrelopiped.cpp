#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int a,b,c;
    vector<int> input(3);
    for(int i = 0; i<3; i++){
        cin>>input[i];
    }
    sort(input.begin(), input.end());
    vector<int> divisors;
    for(int i = 1; i<=input[0]; i++){
        if(input[0] % i == 0 and input[1] % i == 0){
            divisors.push_back(i);
        }
    }
    int d = 0,e = 0,f = 0;
    for(int i = 0; i<divisors.size(); i++){
        d = input[0] / divisors[i];
        e = input[1] / divisors[i];
        if(d*e == input[2]) {
            f = divisors[i];
            break;
        }
    }
    cout<< 4 * (d+e+f);
    return 0;
}