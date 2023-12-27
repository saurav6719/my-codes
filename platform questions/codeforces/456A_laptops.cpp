#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool flag = false;
    vector<pair<int,int> > input(n);
    for(int i = 0; i<n; i++){
        cin>>input[i].first;
        cin>>input[i].second;
    }
    sort(input.begin(), input.end());
    for(int i = 1; i<n; i++){
        if(input[i].second < input[i-1].second){
            cout<<"Happy Alex";
            flag = true;
            break;
        }
        else if(input[i].second == input[i-1].second){
            if(input[i].first != input[i-1].first){
                cout<<"Happy Alex";
                flag = true;
                break;
            }
        }
    }
    if(!flag) cout<<"Poor Alex";
    return 0;
}