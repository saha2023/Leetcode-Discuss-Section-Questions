#include <iostream>
using namespace std;

int minimum_ops(int arr[], int n) {
    int diff = 0;
    int mid = n/2;
    // 1 2 3 4
    int i, j;
    if(n%2){
        //odd
        i = mid-1;
        j = mid+1;
    }
    else{
        //even
        i = mid-1;
        j = mid;
    }
    int opp = 0;
    while(i>=0){
        opp += (arr[j]-arr[i]-diff);
        diff += (arr[j]-arr[i]);
        i--, j++;
    }
    return opp;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minimum_ops(arr, n) << endl;
    return 0;
}