import pandas as pd
import matplotlib.pyplot as plt



# Read data from the .txt file
df = pd.read_csv("results2.txt", delimiter=' ')

# Define the number of categories and columns per category
num_categories = len(df.columns[1:]) // 4
columns_per_category = 4

# Create separate plots for each category
for category_num in range(num_categories):
    plt.figure(figsize=(10, 6))
    
    # Select columns for the current category
    start_idx = 1 + (category_num * columns_per_category)
    end_idx = start_idx + columns_per_category
    category_columns = df.columns[start_idx:end_idx]
    
    for col in category_columns:
        plt.plot(df['Size'], df[col], label=col)
    
    plt.xlabel('Size')
    plt.ylabel('Values')
    plt.title(f'Comparison of Category {category_num + 1} Sorting Algorithms')
    plt.legend()
    plt.savefig(f'category_{category_num + 1}_plot.png')  # Save each plot to a separate file
    plt.show()