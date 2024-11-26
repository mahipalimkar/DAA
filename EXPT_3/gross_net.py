import pandas as pd
import datetime

# Function to calculate gross and net salaries
def calculate_salaries(input_file):
    # Read the input CSV file
    df = pd.read_csv("C:\\Users\\Mahi\\OneDrive\\Desktop\\daa_assignment###\\negative_test_employee_data_5.csv")
    
    # Check for negative values
    df['Negative Values Present'] = df[['Basic Salary', 'Bonus', 'HRA', 'TA', 'TDS', 'PPF']].apply(lambda x: (x < 0).any(), axis=1)
    
    # Calculate Gross Salary
    df['Gross Salary'] = df['Basic Salary'] + df['Bonus'] + df['HRA'] + df['TA']
    
    # Calculate Net Salary
    df['Net Salary'] = df['Gross Salary'] - df['TDS'] - df['PPF']
    
    # Generate a unique output file name using timestamp
    timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    output_file = f"{input_file.split('.')[0]}_with_salaries_{timestamp}.csv"
    
    # Save the output to a new CSV file
    df.to_csv(output_file, index=False)
    print(f"Output file saved as: {output_file}")

# Example usage
input_file = r"C:\Users\Mahi\OneDrive\Desktop\daa_assignment###\employees_data\employees_data_1.csv"  # Replace with your input file path
calculate_salaries(input_file)
