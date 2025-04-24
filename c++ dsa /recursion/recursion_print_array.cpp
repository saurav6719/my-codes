#include<iostream>
using namespace std;
void print(int *array,int index,int length){
    if(index == length){
        return;
    }
    else{
    cout<<array[index]<<endl;
    
    print(array,index+1,length );
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    print(arr,0,5);
    return 0;
}