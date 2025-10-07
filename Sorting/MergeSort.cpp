#include <iostream>
using namespace std;

void Merge(int *array, int start, int mid, int end){

    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1], right[n2];
    // Merging these two arrays;

    

    // cout << "Merging" << endl;

    // for(int i=start; i<=mid; i++) {
    //     cout << array[i] << " ";
    // }

    // cout << " -- & -- ";
    // for(int i=mid+1; i<=end; i++) {
    //     cout << array[i] << " ";
    // }

    // cout << endl << endl;
}

void MergeSort(int *array, int start, int end){
    if(start < end) {
        int mid = (start + end) / 2;
        MergeSort(array, start, mid);
        MergeSort(array, mid+1, end);
        Merge(array, start, mid, end);
    }
}

int main(){
    int array[] = { 34, 62, 9, 24, 99 };
    MergeSort(array, 0, 4);

    return 0;
}

// #include <iostream>
// using namespace std;

// void Merge (int *array, int start, int mid, int end) {
//     int n1 = mid - start + 1;
//     int n2 = end - mid;

//     int L[n1+1];
//     int R[n2+1];

//     for(int i=1; i<n1; i++)
//         L[i] = array[start+i-1];

//     for(int j=1; j<n2; j++)
//         R[j] = array[mid+j];

//     L[n1+1] = INT32_MAX;
//     R[n2+1] = INT32_MAX;

//     int i = 1;
//     int j = 1;

//     for(int k=start; k<end; k++){
//         if(L[i] <= R[j]){
//             array[k] = L[i];
//             i = i+1;
//         }
//         else {
//             array[k] = R[j];
//         }
//     }
// }

// void MergeSort(int *array, int start, int end) {
//     if(start < end){
//         int mid = (start + end) / 2;
//         MergeSort(array, start, mid);
//         MergeSort(array, mid+1, end);
//         Merge(array, start, mid, end);
//     }
// }

// int main() {
//     int arr[] = { 0, 34, 56, 10, 67, 29, 43, 33, 66 };

//     MergeSort(arr, 1, 8);
    
//     for(int i=0; i<9; i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }