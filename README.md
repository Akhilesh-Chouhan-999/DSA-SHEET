# DSA-SHEET

A comprehensive collection of Data Structure and Algorithm (DSA) solutions in C++.

## Overview

This repository contains optimized C++ implementations of various data structure and algorithm problems, organized by problem categories and techniques.

## Directory Structure

```
DSA-SHEET/
├── 2-POINTER/
│   ├── 2-POINTER-ARRAY/
│   │   ├── ApplyOperationsToArray.cpp
│   │   ├── ContainerWithMostWater.cpp
│   │   ├── FindAllKDistantIndicesInArray.cpp
│   │   ├── FourSum.cpp
│   │   ├── MergeSortedArray.cpp
│   │   ├── MergeTwo2DArrays.cpp
│   │   ├── NextGreaterElementIII.cpp
│   │   ├── NextPermutation.cpp
│   │   ├── PartitionArrayAccordingToGivenPivot.cpp
│   │   ├── RearrangeArrayElementsBySign.cpp
│   │   ├── RemoveDuplicatesFromSortedArray.cpp
│   │   ├── RemoveElement.cpp
│   │   ├── RotateArray.cpp
│   │   ├── SortArrayByParity.cpp
│   │   ├── SortArrayByParityII.cpp
│   │   ├── SortColors.cpp
│   │   ├── ThreeSum.cpp
│   │   ├── ThreeSumClosest.cpp
│   │   ├── TwoSum.cpp
│   │   └── WateringPlantsII.cpp
│   └── 2-POINTER-STRING/
└── README.md
```

## Topics Covered

### Two Pointer Technique

- Array problems using two pointer approach
- String manipulation problems
- Container and water trapping problems
- Sum problems (2Sum, 3Sum, 4Sum)
- Array sorting and rearrangement

## Key Problems

### Array Problems

- **TwoSum**: Find two numbers that add up to a target
- **ThreeSum**: Find triplets that sum to zero
- **FourSum**: Find quadruplets that sum to target
- **ContainerWithMostWater**: Maximize water container area
- **MergeSortedArray**: Merge two sorted arrays
- **RotateArray**: Rotate array by k positions
- **RemoveDuplicates**: Remove duplicates from sorted array
- **SortColors**: Sort array with three distinct values
- **NextPermutation**: Find the next lexicographic permutation

## How to Use

1. Clone the repository:

```bash
git clone https://github.com/Akhilesh-Chouhan-999/DSA-SHEET.git
cd DSA-SHEET
```

2. Compile any C++ file:

```bash
g++ -o output filename.cpp
./output
```

3. Run with optimizations:

```bash
g++ -O2 -o output filename.cpp
./output
```

## Compilation Requirements

- C++11 or later
- GCC/Clang compiler (or any C++ compiler supporting C++11)
- Standard Template Library (STL)

## File Format

Each file typically contains:

- A `Solution` class with the main algorithm
- Input/output handling
- Test cases to verify correctness
- Time and space complexity implications

## Example: ThreeSum.cpp

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // Implementation using two-pointer technique
        // Time Complexity: O(n²)
        // Space Complexity: O(1)
    }
};
```

## Time & Space Complexity

Most problems in this sheet are optimized for:

- **Minimal time complexity** using efficient algorithms
- **Optimal space complexity** to avoid unnecessary memory usage

## Contributing

Feel free to submit issues and pull requests for:

- Bug fixes
- Optimizations
- New DSA problems
- Documentation improvements

## License

This project is open source and available for educational purposes.

## Author

**Akhilesh Chouhan**

---

Last Updated: March 2026
