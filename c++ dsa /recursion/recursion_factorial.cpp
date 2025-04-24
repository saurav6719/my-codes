#include <iostream>
using namespace std;
int factorial(int n){
    if (n==1){
        return 1;     //base case scenerio   
    }
    return n * factorial(n-1);
}
int main(){
    int num;
    cout << "enter number"<<endl;
    cin >> num;
    int result = factorial(num);
    cout << result;
    return 0;

}