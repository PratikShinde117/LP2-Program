#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){

    int minIndex=0;
    int arr[] = {3,2,1,5,6};
    int n = 6;
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    
    for(int i=0; i<n-1; i++){
        minIndex = i;
        
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}
