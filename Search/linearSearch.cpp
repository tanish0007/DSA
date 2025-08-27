#include <iostream>
using namespace std;

int MAX = 50;

void linearSearch (int *array, int size, int target) {
    for(int i=0; i<size; i++){
        if(array[i] == target){
            cout << "Elment is found at position: " << size+1 << endl;
            return;
        }
    }
    cout << "----- Elment not found -----" << endl;
}

int main() {
    int array[MAX], n, target;

    cout << "Enter size of array you want: ";
    cin >> n;

    cout << "------------- Enter array elements -------------" << endl;
    for(int i=0; i<n; i++){
        cout << "Enter " << i+1 << "th element: ";
        cin >> array[i];
    }

    cout << "Enter the element you want to search: ";
    cin >> target;

    linearSearch(array, n, target);
    return 0;
}