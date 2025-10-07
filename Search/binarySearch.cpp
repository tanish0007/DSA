#include <iostream>
using namespace std;

int MAX = 50;

int binarySearch(int *array, int start, int end, int target){
    if(start > end) return -1;

    int mid = (start + end) / 2;
    if(array[mid] == target) return mid;
    else if(array[mid] > target) binarySearch(array, start, mid-1, target);
    else binarySearch(array, mid+1, end, target);
}

int main() {
    int array[MAX], size, target;

    cout << "Enter the size of array you want: ";
    cin >> size;

    cout << "------------- Enter array elements (ordered way) -------------" << endl;
    for(int i=1; i<=size; i++){
        cout << "Enter " << i << "th element: ";
        cin >> array[i];
    }

    cout << "Enter the element you want to search: ";
    cin >> target;

     cout << binarySearch(array, 1, size, target) << "th position";

    return 0;
}