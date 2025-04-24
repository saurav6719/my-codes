#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
    vector<int> result;
    unordered_set<int> st;
    vector<int> answer;
    int n;
    cin>>n;
    int v;
    cin>>v;
    for(int i = 1; i<=n; i++){
        int a;
        cin>>a;
        for(int j = 0; j<a; j++){
            int value;
            cin>>value;
            if(v>value) answer.push_back(i);
        }
    }

    for(int i= 0; i< answer.size() ; i++){
        if(!st.count(answer[i])) result.push_back(answer[i]);
        st.insert(answer[i]);
    }

    cout<<result.size()<<endl;

    for(int i = 0; i< result.size(); i++){
        cout<<result[i]<<" ";
    }
    
    return 0;
}