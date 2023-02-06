/**
 * Given array of integers as arr, We have two kind of queries
type 1: given value,update array elements less than value to value;
type 2: given index and value, update index of array to value
E,g arr=[1,2,3,4,5];
query type 1:value=3 now arr =[3,3,3,4,5];
query type 2:idx=2 and value=1 now arr=[3,3,1,4,5];
query type 1: value=2 now arr=[3,3,2,4,5]

so final arr will be [3,3,2,4,5]...............Anyone have any idea how to solve this type of questions,...I think this can be link to any standard algorithm.!!
*/

#include <iostream>
using namespace std;
void file_i_o(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}
void update(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] < value) {
            arr[i] = value;
        }
    }
}

int main() {
    file_i_o();
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int q, type, value, idx;
    cin >> q;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> value;
            update(arr, n, value);
        } 
        else if (type == 2) {
            cin >> idx >> value;
            arr[idx] = value;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
