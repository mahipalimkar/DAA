import pandas as pd

# Function to find min and max using divide and conquer
def find_min_max(arr, low, high):
    # If the array has only one element
    if low == high:
        return arr[low], arr[low]

    # If the array has two elements
    elif high == low + 1:
        if arr[low] < arr[high]:
            return arr[low], arr[high]
        else:
            return arr[high], arr[low]

    # If the array has more than two elements
    else:
        mid = (low + high) // 2
        min1, max1 = find_min_max(arr, low, mid)
        min2, max2 = find_min_max(arr, mid + 1, high)
        return min(min1, min2), max(max1, max2)

# Function to find the min and max net salary in the CSV file
def min_max_net_salary(input_file):
    # Read the CSV file
    df = pd.read_csv("C:\\Users\\Mahi\\OneDrive\\Desktop\\daa_assignment###\\employees_data\\employees_data_5_with_salaries_20240831_230046.csv")
    
    # Extract the Net Salary column
    net_salaries = df['Net Salary'].tolist()
    
    # Find the minimum and maximum net salary using divide and conquer
    min_salary, max_salary = find_min_max(net_salaries, 0, len(net_salaries) - 1)
    
    return min_salary, max_salary

# Example usage
input_file = r"C:\Users\Mahi\OneDrive\Desktop\daa_assignment###\employees_data\employees_data_1_with_salaries.csv"  # Replace with your input file path
min_salary, max_salary = min_max_net_salary(input_file)
print(f"Minimum Net Salary: {min_salary}")
print(f"Maximum Net Salary: {max_salary}")
