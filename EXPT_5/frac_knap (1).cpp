#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item
{
  double weight;
  double shelfLife;

  // Constructor
  Item(double w, double s) : weight(w), shelfLife(s) {}
};

// Comparator function to sort items based on shelf life (shorter shelf life first)
bool compare(Item a, Item b)
{
  return a.shelfLife < b.shelfLife;
}

// Function to solve the Fractional Knapsack problem based on shelf life
double fractionalKnapsack(vector<Item> &items, double capacity)
{
  // Sort items based on shelf life
  sort(items.begin(), items.end(), compare);

  double totalWeight = 0.0;
  int itemCount = 0;

  for (auto &item : items)
  {
    // If the entire item can be taken
    if (capacity >= item.weight)
    {
      capacity -= item.weight;
      totalWeight += item.weight;
      itemCount++;
    }
    // Take a fraction of the item if it can't fit entirely
    else
    {
      totalWeight += capacity; // Remaining capacity is used for a fraction of the item
      break;                   // The knapsack is full
    }
  }

  cout << "\nTotal number of items shipped: " << itemCount << endl;
  return totalWeight;
}

int main()
{
  int n;
  double capacity;

  // Input the number of items and the capacity of the vehicle
  cout << "Enter the number of items: ";
  cin >> n;

  cout << "Enter the capacity of the transport vehicle (in tons): ";
  cin >> capacity;

  vector<Item> items;

  // Input the weight and shelf life of each item
  for (int i = 0; i < n; ++i)
  {
    double weight, shelfLife;
    cout << "Enter weight and value for item " << i + 1 << ": ";
    cin >> weight >> shelfLife;
    items.push_back(Item(weight, shelfLife));
  }

  // Calculate the maximum weight of goods that can be shipped
  double maxWeight = fractionalKnapsack(items, capacity);

  cout << "\nTotal weight of goods shipped: " << maxWeight << " tons" << endl;

  return 0;
}
