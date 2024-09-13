#include <iostream>

using namespace std;

int arr[10] = {6,1,5,8,9,7,3,4,2,14};
int sortedArray[10];

//Ascending order
void bubbleSort(){
    int temp;
    for(int i=0; i<10; i++){
        for(int j=i+1; j<10; j++){
            if(arr[j] < arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//Descending order
void bubbleSort2(){
    int temp;
    for(int i=0; i<10; i++){
        for(int j=i+1; j<10; j++){
            if(arr[j] > arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//selection sort
void selection(){
    int temp, minimum;
    for(int i=0; i<10; i++){
        minimum = i;
        for(int j=i+1; j<10; j++){
             if(arr[j] < arr[minimum]){
                minimum = j;
             }
        }
        temp = arr[i];
        arr[i] = arr[minimum];
        arr[minimum] = temp;
    }
}

//insertion sort
void insertion(){
    for(int i=1; i<10; i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}


int main(){
    cout<< "Sorted array: "<<endl;
    for(int i = 0; i<10; i++){
        cout<<arr[i]<< "  ";
    }
    return 0;
}
