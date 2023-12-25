#include <iostream>
using namespace std;
int f(int *array, int index, int lenght){
    if(index == (lenght-1)) return array[index];
    return (array[index] + f(array, index+1 , lenght));
    
}
int main(){
    int arr[]={1,2,3,4,5};
    cout<<f(arr, 0, 5);
}