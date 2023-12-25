#include<iostream>
using namespace std;
class dynamicArray{
    int *data;
    int nextIndex;
    int capacity;
    public:

    dynamicArray(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }
    void insert(int element){
        if(nextIndex == capacity){
            int *newdata = new int[capacity * 2];
            for(int i =0 ; i<capacity ; i++){
                newdata[i] = data[i];
            }
            
            delete [] data;   //deallocating data integer
            data = newdata;
            capacity *= 2;
        }
        data[nextIndex] = element;

        nextIndex++;
    }
    void insert(int i , int element){
        if(i<nextIndex){
            data[i] = element;
        }
        if(i == nextIndex){
            insert(element);
        }
        else{
            return;
        }
    }
    // printing data
    int get(int i){
        if(i < nextIndex){
            return data[i];
        }
        else{
            return -1;
        }
    }
    
    void print(){
        for(int i=0;i<nextIndex;i++){
            cout<<data[i]<<" ";

        }
        cout<<endl;
    }
    
};
int main(){
    dynamicArray d1;
    d1.insert(10);
    d1.insert(20);
    d1.insert(30);
    d1.insert(40);
    d1.insert(50);
    d1.insert(60);
    d1.print();


    dynamicArray d2(d1); //copy constructor 
    d1.insert(0,100);
    d1.print();
    d2.print(); //shallow copy


    dynamicArray d3;
    d3 = d1;
    d3.print(); //shallow copy

    return 0;
}