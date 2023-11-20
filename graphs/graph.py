import matplotlib.pyplot as plt
import pandas as pd

# Insertion Heap Quick RadixLSD
# InsertionSorted HeapSorted QuickSorted RadixLSDSorted 
# InsertionEqual HeapEqual QuickEqual RadixLSDEqual 
# InsertionReversed HeapReversed QuickReversed RadixLSDReversed
with open("final_results2.txt", "r") as file:
    for _ in range(5):  # Print the first 5 lines
        print(file.readline())

data = pd.read_csv("final_results2.txt", delimiter=' ')
data = data.set_index("Size")

print("Loaded data:")
print(data.head())

data[["Insertion", "Heap", "Quick", "RadixLSD"]].plot(linewidth=4)
plt.title("Randomly generated array")
plt.savefig("random_full.png")

data[["Heap", "Quick", "RadixLSD"]].plot(linewidth=4)
plt.savefig("random_closer.png")

data[["InsertionSorted", "HeapSorted", "QuickSorted", "RadixLSDSorted"]].plot(linewidth=4)
plt.savefig("sorted_full.png")

data[["InsertionEqual", "HeapEqual", "QuickEqual", "RadixLSDEqual"]].plot(linewidth=4)
plt.savefig("equal_full.png")

data[["InsertionReversed", "HeapReversed", "QuickReversed", "RadixLSDReversed"]].plot(linewidth=4)
plt.savefig("reversed_full.png")

data[["HeapReversed", "QuickReversed", "RadixLSDReversed"]].plot(linewidth=4)
plt.savefig("reversed_closer.png")

# data[["Insertion", "Heap", "Quick", "RadixLSD", "Hybrid"]].plot(linewidth=4)
# plt.savefig("full.png")


# data[["Heap", "Quick", "RadixLSD", "Hybrid"]].plot(linewidth=4)
# plt.savefig("full2.png")

# data[["InsertionSorted", "HeapSorted", "QuickSorted", "RadixLSDSorted", "HybridSorted"]].plot(linewidth=4)
# plt.savefig("full_sorted.png")

# data[["InsertionEqual", "HeapEqual", "QuickEqual", "RadixLSDEqual", "HybridEqual"]].plot(linewidth=4)
# plt.savefig("full_equal.png")

# data[["InsertionReversed", "HeapReversed", "QuickReversed", "RadixLSDReversed", "HybridReversed"]].plot(linewidth=4)
# plt.savefig("full_reversed.png")

# data[["HeapReversed", "QuickReversed", "RadixLSDReversed", "HybridReversed"]].plot(linewidth=4)
# plt.savefig("reversed2.png")

# small = data[:15]

# small[["bubble", "insertion", "selection"]].plot(linewidth=4)

# plt.savefig("small.png")

# small[["bubble_sorted", "insertion_sorted", "selection_sorted"]].plot(linewidth=4)

# plt.savefig("small_sorted.png")
