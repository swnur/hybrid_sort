import matplotlib.pyplot as plt
import pandas as pd

# Insertion Heap Quick RadixLSD Hybrid
# InsertionSorted HeapSorted QuickSorted RadixLSDSorted HybridSorted
# InsertionEqual HeapEqual QuickEqual RadixLSDEqual HybridEqual
# InsertionReversed HeapReversed QuickReversed RadixLSDReversed Hybrid Reversed
with open("final_results2.txt", "r") as file:
    for _ in range(5):
        print(file.readline())

data = pd.read_csv("partially_sorted.txt", delimiter=' ')
data = data.set_index("Size")

print("Loaded data:")
print(data.head())

data[["Insertion", "Heap", "Quick", "RadixLSD", "Hybrid"]].plot(linewidth=4)
plt.title("Partially sorted array")
plt.savefig("partially_sorted.png")

# data[["Insertion", "Heap", "Quick", "RadixLSD", "Hybrid"]].plot(linewidth=4)
# plt.title("Randomly generated array")
# plt.savefig("full.png")


# data[["Heap", "Quick", "RadixLSD", "Hybrid"]].plot(linewidth=4)
# plt.title("Randomly generated closer look without Insertion Sort")
# plt.savefig("full2.png")

# data[["InsertionSorted", "HeapSorted", "QuickSorted", "RadixLSDSorted", "HybridSorted"]].plot(linewidth=4)
# plt.title("Sorted array")
# plt.savefig("full_sorted.png")

# data[["InsertionReversed", "HeapReversed", "QuickReversed", "RadixLSDReversed", "HybridReversed"]].plot(linewidth=4)
# plt.title("Reversed array")
# plt.savefig("full_reversed.png")

# data[["HeapReversed", "QuickReversed", "RadixLSDReversed", "HybridReversed"]].plot(linewidth=4)
# plt.title("Reversed array closer look")
# plt.savefig("reversed2.png")