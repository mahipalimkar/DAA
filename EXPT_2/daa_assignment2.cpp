#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return the index of the found key
        }
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    int size;
    
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key to search for: ";
    cin >> key;

    int result = linearSearch(arr, size, key);

    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    } else {
        cout << "Key not found." << endl;
    }

    return 0;
}
