#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin>>n;
	int m;
	cin>>m;
    vector<int> arr(n+10,0);
	for(int i = 0; i<m; i++){
		int a,b;
        cin>>a>>b;
        arr[a]++;
        arr[b+1]--;
	}
	
    //prefix sum
    for(int i = 1; i<arr.size();i++){
        arr[i] += arr[i-1];
    }

	vector<int> newarr(10000005,0);
	for(int i = 0; i<=n;i++){
		newarr[arr[i]]++;
	}

	// suffix sum

    for(int i=newarr.size()-2; i>=0 ; i--){
        newarr[i] = newarr[i] + newarr[i+1];
    }

    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<newarr[num]<<endl;
    }

	

	return 0;
}