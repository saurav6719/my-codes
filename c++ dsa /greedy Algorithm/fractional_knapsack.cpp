#include<iostream>
#include<vector>
using namespace std;

bool cmp(pair<int, int> &p1, pair<int, int> &p2){
    double r1 = (p1.first)/(p1.second);
    double r2 = (p2.first)/(p2.second);
    return r1 > r2;
}



double knapsack(vector<int> &value, vector<int> weight, int n, int w){
    vector<pair<int, int> > arr;
    double result = 0;
    for(int i = 0; i< n ; i++){
        pair<int, int> p ;
        p.first = value[i];
        p.second = weight[i];
        arr.push_back(p);
    }
    // sort according to value / weight ratio

    sort(arr.begin(), arr.end(), cmp);

    // fill in knapsack
    int x = 0;
    while(w > 0){
        if(arr[x].second < w){ // full pick
            result += arr[x].first;
            w -= arr[x].second;
        }
        else{ // partial pick
            result += (arr[x].first) / (arr[x].second) * w;
            w = 0;
        }
        x++;
    }
    return result;
}

int main(){
    vector<int> value;
    value.push_back(60);
    value.push_back(100);
    value.push_back(120);
    vector<int> weight;
    weight.push_back(10);
    weight.push_back(20);
    weight.push_back(30);
    int w = 50;
    int n = 3;
    cout<<knapsack(value,weight,n,w)<<endl;
}