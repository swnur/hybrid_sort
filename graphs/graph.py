import matplotlib.pyplot as plt
import pandas as pd

# Insertion Heap Quick RadixLSD
# InsertionSorted HeapSorted QuickSorted RadixLSDSorted 
# InsertionEqual HeapEqual QuickEqual RadixLSDEqual 
# InsertionReversed HeapReversed QuickReversed RadixLSDReversed
with open("final_results.txt", "r") as file:
    for _ in range(5):  # Print the first 5 lines
        print(file.readline())

data = pd.read_csv("final_results.txt", delimiter=' ')
data = data.set_index("Size")

print("Loaded data:")
print(data.head())


data[["Insertion", "Heap", "Quick", "RadixLSD"]].plot(linewidth=4)
plt.title("Randomly generated array")
plt.savefig("random_full.png")

data[["Heap", "Quick", "RadixLSD"]].plot(linewidth=4)
plt.title("Randomly generated closer look without Insertion sort")
plt.savefig("random_closer.png")

data[["InsertionSorted", "HeapSorted", "QuickSorted", "RadixLSDSorted"]].plot(linewidth=4)
plt.title("Sorted array")
plt.savefig("sorted_full.png")

data[["InsertionEqual", "HeapEqual", "QuickEqual", "RadixLSDEqual"]].plot(linewidth=4)
plt.title("Duplicated array")
plt.savefig("equal_full.png")

data[["InsertionReversed", "HeapReversed", "QuickReversed", "RadixLSDReversed"]].plot(linewidth=4)
plt.title("Reversed array")
plt.savefig("reversed_full.png")

data[["HeapReversed", "QuickReversed", "RadixLSDReversed"]].plot(linewidth=4)
plt.title("Reversed array closer look")
plt.savefig("reversed_closer.png")

small = data[:5]

small[["Insertion", "Heap", "Quick", "RadixLSD"]].plot(linewidth=4)
plt.savefig("small2.png")

