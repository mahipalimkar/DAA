#include <iostream>
using namespace std;

int binarySearch(int arr[], int key, int low, int high);

int main()
{
  cout << "Enter the size of the array" << endl;
  int n;
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cout << "Enter element number" << i << "(make sure array is sorted)" << endl;
    cin >> arr[i];
  }

  cout << "Enter the key to be searched " << endl;
  int key;
  cin >> key;

  int low = 0;
  int high = n - 1;

  int answer = binarySearch(arr, key, low, high);
  cout << "Key found at " << answer << endl;
}

int binarySearch(int arr[], int key, int low, int high)
{

  if (low <= high)
  {
    int mid = (low + high) / 2;

    if (arr[mid] == key)
    {
      return mid;
    }

    else if (arr[mid] < key)
    {
      return binarySearch(arr, key, mid + 1, high);
    }

    else
    {
      return binarySearch(arr, key, low, mid - 1);
    }
  }
  else
  {
    return -1;
  }
}