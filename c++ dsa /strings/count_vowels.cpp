#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    char str[n];
    for(int i=0;i<n;i++){
        cin >> str[i];

    }
    int count=0;
    int i=0;
    while ((str[i] !=0)){
    
    
        if (str[i] == 'a' or str[i] == 'e' or str[i] == 'i' or str[i] == 'o' or str[i] == 'u'){
            count ++;
        }
        i++;
       
    }
     cout<<count;
}