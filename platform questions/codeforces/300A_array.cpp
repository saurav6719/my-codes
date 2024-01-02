#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    for(int i = 0 ; i<n;i++){
        cin>>input[i];
    }
    
    vector<int> negative;
    vector<int> zero;
    vector<int> positive;
    bool negative_flag = false;
    bool zero_flag = false;
    int negative_count = 0;
    int positive_count = 0;

    for(int i = 0; i<n; i++){
        if(input[i]< 0) negative_count++;
        else if(input[i] > 0) positive_count++;
    }

 
    for(int  i = 0; i<n;i++){
        if(input[i] < 0 and negative_flag == false){
            negative_flag = true;
            negative.push_back(input[i]);
        }
        else if(positive_count == 0 and positive.size() < 2 and input[i] < 0){
            positive.push_back(input[i]);
        }
        else if(input[i] < 0 and negative_flag == true and negative_count % 2 == 0){
            zero.push_back(input[i]);
        }
        else if(input[i] == 0){
            zero_flag = true;
            zero.push_back(input[i]);
        }
        else if(negative_flag and zero_flag){
            positive.push_back(input[i]);
        }
        else if(negative_flag and input[i]!= 0){
            positive.push_back(input[i]);
        }
        else if(input[i]>0) positive.push_back(input[i]);
    }
 
    cout<<negative.size()<<" ";
    for(int i = 0; i< negative.size(); i++){
        cout<<negative[i]<<" ";
    }
    cout<<endl;
 
    cout<<positive.size()<<" ";
    for(int i = 0; i< positive.size(); i++){
        cout<<positive[i]<<" ";
    }
    
    cout<<endl;
 
    cout<<zero.size()<<" ";
    for(int i = 0; i< zero.size(); i++){
        cout<<zero[i]<<" ";
    }
 


    return 0;
}