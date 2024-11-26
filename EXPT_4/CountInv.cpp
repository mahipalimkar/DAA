#include <iostream>
using namespace std;

// Function to merge two halves and count inversions
int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    int inv_count = 0;

    // Merge the two halves while counting inversions
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid + 1 - i); // Count inversions
        }
    }

    // Copy remaining elements of left subarray
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements of right subarray
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy the sorted subarray into the original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Function to divide the array into two halves and count inversions
int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (left < right) {
        mid = (left + right) / 2;

        // Recursively divide the array and count inversions
        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        // Merge the two halves and add inversion counts
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int arr[6];
    bool invalid_input = false;  // Flag to track invalid input
    
    cout << "Enter 6 course codes in order of preference :" << endl;
    
    // Input all elements
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
        // Set flag if any element is invalid
        if (arr[i] < 1) {
            invalid_input = true;  // Flag for invalid input
        }
    }

    // Check if any invalid input was found
    if (invalid_input) {
        cout << "Error: Please enter positive integers only." << endl;
        return -1;  // Exit if invalid input
    }

    // Proceed if all inputs are valid
    int temp[6]; // Temporary array for merging
    int inv_count = mergeSortAndCount(arr, temp, 0, 5);

    cout << "Number of inversions: " << inv_count << endl;

    return 0;
}
