#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<int> input(n);
    for(int i = 0; i<n ; i++){
        int a;
        cin>>a;
        input[i]=a;
    }
    int even_count = 0;
    int odd_count = 0;
    for(int i = 0 ; i<n ; i++){
        if(input[i] % 2 == 0) even_count ++;

        else odd_count++;
    }

    if(even_count == 1){
        for(int i = 0; i<n ; i++){
            if(input[i] % 2 == 0){
                cout<<i+1;
                break;
            }
        }
    }
    else if(odd_count == 1){
        for(int i = 0; i<n ; i++){
            if(input[i] % 2 == 1){
                cout<<i+1;
                break;
            }
        }
    }



    return 0;
}