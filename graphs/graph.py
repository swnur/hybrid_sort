import matplotlib.pyplot as plt
import pandas as pd

# Insertion Heap Quick RadixLSD
# InsertionSorted HeapSorted QuickSorted RadixLSDSorted 
# InsertionEqual HeapEqual QuickEqual RadixLSDEqual 
# InsertionReversed HeapReversed QuickReversed RadixLSDReversed
with open("data", "r") as file:
    for _ in range(5):  # Print the first 5 lines
        print(file.readline())

data = pd.read_csv("data", delimiter=' ')
data = data.set_index("N")

print("Loaded data:")
print(data.head())

# data[["Insertion", "Heap", "Quick", "RadixLSD"]].plot(linewidth=4)

# plt.savefig("full.png")

# data[["InsertionSorted", "HeapSorted", "QuickSorted", "RadixLSDSorted"]].plot(linewidth=4)

# plt.savefig("full_sorted.png")

# data[["InsertionEqual", "HeapEqual", "QuickEqual", "RadixLSDEqual"]].plot(linewidth=4)

# plt.savefig("full_equal.png")

# data[["InsertionReversed", "HeapReversed", "QuickReversed", "RadixLSDReversed"]].plot(linewidth=4)

# plt.savefig("full_reversed.png")

# small = data[:15]

# small[["bubble", "insertion", "selection"]].plot(linewidth=4)

# plt.savefig("small.png")

# small[["bubble_sorted", "insertion_sorted", "selection_sorted"]].plot(linewidth=4)

# plt.savefig("small_sorted.png")
