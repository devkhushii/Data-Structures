# The Ultimate Sorting Algorithms Handbook

*A complete, from-first-principles guide to sorting — for beginners, placement prep, online assessments, competitive programming, and technical interviews.*

**Sample array used throughout this handbook for dry runs:**
```
A = [64, 34, 25, 12, 22, 11, 90]
```

---

## Table of Contents

1. [Introduction to Sorting](#section-1-introduction-to-sorting)
2. [Fundamental Concepts](#section-2-fundamental-concepts)
3. [Complexity Analysis](#section-3-complexity-analysis)
4. [Basic Sorting Algorithms (Bubble, Selection, Insertion)](#section-4-basic-sorting-algorithms)
5. [Divide and Conquer Sorting (Merge, Quick)](#section-5-divide-and-conquer-sorting)
6. [Heap Sort](#section-6-heap-sort)
7. [Linear Time Sorting (Counting, Radix, Bucket)](#section-7-linear-time-sorting)
8. [Advanced Sorting Algorithms (Shell, Tim, Intro, Tree, Cocktail, Comb, Gnome, Pancake, Cycle, Sleep)](#section-8-advanced-sorting-algorithms)
9. [STL Sorting in C++](#section-9-stl-sorting-in-c)
10. [Custom Sorting (Comparators)](#section-10-custom-sorting-comparators)
11. [Sorting Patterns](#section-11-sorting-patterns)
12. [Important Sorting Applications](#section-12-important-sorting-applications)
13. [Special Sorting Topics](#section-13-special-sorting-topics)
14. [Interview Decision Framework](#section-14-interview-decision-framework)
15. [Common Tricks](#section-15-common-tricks)
16. [Common Mistakes](#section-16-common-mistakes)
17. [Curated Practice Question List](#section-17-curated-practice-question-list)
18. [Master Comparison Table](#section-18-master-comparison-table)
19. [Revision Cheat Sheet](#section-19-revision-cheat-sheet)
20. [Final Roadmap](#section-20-final-sorting-roadmap)

---

# SECTION 1: Introduction to Sorting

## What is Sorting?

Sorting is the process of rearranging a collection of elements (an array, list, or other sequence) into a specific order — usually ascending or descending — based on a comparison key or a derived value.

```
Before: [64, 34, 25, 12, 22, 11, 90]
After:  [11, 12, 22, 25, 34, 64, 90]
```

Sorting is one of the oldest and most studied problems in computer science because so many other algorithms (searching, deduplication, scheduling, compression) become trivial or much faster once data is sorted.

## Why Sorting is Important

- Enables **binary search** (O(log n) lookups instead of O(n)).
- Makes **duplicate detection** and **frequency counting** easier.
- Required for **greedy algorithms** (interval scheduling, activity selection).
- Used internally by databases (ORDER BY, indexing, merge joins).
- Used in **operating systems** (process scheduling by priority).
- Foundation for **order statistics** (median, kth smallest/largest).

## Real World Applications

| Domain | Use of Sorting |
|---|---|
| Databases | Index building, ORDER BY, JOIN optimization |
| Search Engines | Ranking results by relevance score |
| E-commerce | Sorting products by price/rating |
| Operating Systems | Job/process scheduling |
| Networking | Packet prioritization |
| Computational Geometry | Sorting points by angle/coordinate |
| Compilers | Sorting symbol tables |
| Compression | Burrows-Wheeler Transform (sorting rotations) |

## Internal vs External Sorting

| Type | Description | Example |
|---|---|---|
| **Internal Sorting** | All data fits in main memory (RAM) | Sorting an array of 10,000 ints |
| **External Sorting** | Data too large for RAM, resides on disk | Sorting a 100 GB log file using external merge sort |

## Stable vs Unstable Sorting

A sort is **stable** if it preserves the relative order of elements with equal keys.

```
Input (key, label): (3,A) (1,B) (3,C) (2,D)

Stable sort output:   (1,B) (2,D) (3,A) (3,C)   -> A still appears before C
Unstable sort output: (1,B) (2,D) (3,C) (3,A)   -> order of equal keys changed
```

Stability matters when you sort by one key, then need to sort by another key while keeping the first ordering intact (multi-key sort).

## In-place vs Out-of-place Sorting

| Type | Extra Space | Example |
|---|---|---|
| In-place | O(1) or O(log n) auxiliary | Bubble, Insertion, Selection, Quick, Heap |
| Out-of-place | O(n) or more auxiliary | Merge Sort, Counting Sort, Radix Sort |

## Adaptive vs Non-adaptive Sorting

- **Adaptive**: Takes advantage of existing order in input; runs faster on nearly-sorted data (e.g., Insertion Sort, Bubble Sort with early-exit, TimSort).
- **Non-adaptive**: Runtime doesn't change based on existing order (e.g., Selection Sort, Heap Sort).

## Comparison-based vs Non-comparison-based Sorting

| Type | Lower Bound | Examples |
|---|---|---|
| Comparison-based | Ω(n log n) | Bubble, Insertion, Selection, Merge, Quick, Heap |
| Non-comparison-based | Can beat O(n log n) | Counting, Radix, Bucket Sort |

```
Comparison Sorting Lower Bound (Decision Tree Argument)
--------------------------------------------------------
n! possible permutations -> need log2(n!) ≈ n log n comparisons minimum
to distinguish all orderings.
```

---

# SECTION 2: Fundamental Concepts

## Swapping

The atomic operation behind most in-place sorts.

```cpp
void swap_vals(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
// Or simply: std::swap(a, b);
```

## Comparing

Sorting needs a comparator: a function/operator that decides the relative order of two elements (`<`, `>`, or custom lambda).

## Partitioning (Quick Sort core idea)

Rearranging an array around a **pivot** so that elements smaller than pivot are on the left, larger on the right.

```
Array: [5, 3, 8, 4, 2, 7]   pivot = 4

After partition: [3, 2, 4, 8, 5, 7]
                        ^pivot is now in its final sorted position
```

## Merging (Merge Sort core idea)

Combining two already-sorted sequences into one sorted sequence.

```
Left:  [2, 5, 8]
Right: [3, 4, 9]

Merge step by step:
compare 2,3 -> take 2   : [2]
compare 5,3 -> take 3   : [2,3]
compare 5,4 -> take 4   : [2,3,4]
compare 5,9 -> take 5   : [2,3,4,5]
compare 8,9 -> take 8   : [2,3,4,5,8]
remaining   -> take 9   : [2,3,4,5,8,9]
```

## Pivot Selection Strategies

| Strategy | Description | Risk |
|---|---|---|
| First element | Simplest | Worst case on sorted input |
| Last element | Common (Lomuto) | Worst case on sorted input |
| Random element | Avoids adversarial input | Tiny overhead |
| Median-of-three | first/mid/last median | Good general performance |

## Recursion in Sorting

Merge Sort, Quick Sort, and Tree Sort rely on recursion to break a problem into smaller subproblems (Divide and Conquer).

## Divide and Conquer Paradigm

```
            Divide
               |
   Split problem into sub-problems
               |
            Conquer
               |
   Solve sub-problems recursively
               |
            Combine
               |
   Merge solutions into final answer
```

## Incremental Sorting

Insertion Sort builds the sorted array one element at a time, inserting each new element into its correct position among already-sorted elements — similar to how people sort playing cards in hand.

## Heap Property

A **max-heap** satisfies: `parent >= children` for every node. A **min-heap** satisfies the reverse. Heap Sort uses this property to repeatedly extract the maximum.

## Counting Frequencies

Counting Sort works by counting how many times each value occurs, then using these counts to place elements directly into their sorted position.

## Bucket Distribution

Bucket Sort spreads elements into several "buckets" based on value ranges, sorts each bucket individually (often with Insertion Sort), then concatenates.

## Radix Processing

Radix Sort sorts numbers digit by digit (least significant to most significant), using a stable sort (usually Counting Sort) as a subroutine at each digit position.


---

# SECTION 3: Complexity Analysis

## Best, Average, Worst Case

| Case | Meaning | Example (Quick Sort) |
|---|---|---|
| Best Case | Most favorable input | Balanced partitions every time -> O(n log n) |
| Average Case | Expected over random inputs | O(n log n) |
| Worst Case | Most unfavorable input | Already sorted with bad pivot -> O(n²) |

## Space Complexity

Total memory used by the algorithm, including input.

## Auxiliary Space

Extra memory used **excluding** input storage (e.g., temporary arrays, recursion stack).

## Recursion Depth

For recursive sorts, recursion depth contributes to space complexity via the call stack:

```
Merge Sort recursion depth   : O(log n) — balanced splits
Quick Sort recursion depth   : O(log n) average, O(n) worst case (unbalanced splits)
```

## Stability Analysis Summary

| Stable | Unstable |
|---|---|
| Bubble, Insertion, Merge, Counting, Radix, Bucket, TimSort | Selection, Quick, Heap, Shell, IntroSort |

## In-place Analysis Summary

| In-place (O(1) extra) | Not In-place |
|---|---|
| Bubble, Selection, Insertion, Quick, Heap, Shell, Cycle, Comb, Gnome | Merge, Counting, Radix, Bucket |

---

# SECTION 4: Basic Sorting Algorithms

## 4.1 Bubble Sort

### 1. Definition
Bubble Sort repeatedly steps through the array, compares adjacent elements, and swaps them if they are in the wrong order. The largest unsorted element "bubbles up" to its correct position at the end of each pass.

### 2. Why it Exists
It's the simplest possible sorting algorithm to teach the concept of comparison and swapping — a pedagogical starting point, not a production algorithm.

### 3. Intuition
Imagine bubbles rising in water — heavier (larger) elements sink to the bottom of each pass, lighter (smaller) ones rise up over multiple passes.

### 4. Visual Explanation
```
Pass moves the largest unsorted element to the right end:
[5,1,4,2,8] -> compare(5,1) swap -> [1,5,4,2,8]
            -> compare(5,4) swap -> [1,4,5,2,8]
            -> compare(5,2) swap -> [1,4,2,5,8]
            -> compare(5,8) no   -> [1,4,2,5,8]
End of Pass 1: 8 is in final position.
```

### 5. Working Principle
For each pass `i` from 0 to n-1, compare each adjacent pair `(j, j+1)` from 0 to `n-i-2`, swapping if `a[j] > a[j+1]`.

### 6. Step-by-Step Dry Run on A = [64, 34, 25, 12, 22, 11, 90]

```
Pass 1:
[64,34,25,12,22,11,90] compare 64,34 -> swap -> [34,64,25,12,22,11,90]
                        compare 64,25 -> swap -> [34,25,64,12,22,11,90]
                        compare 64,12 -> swap -> [34,25,12,64,22,11,90]
                        compare 64,22 -> swap -> [34,25,12,22,64,11,90]
                        compare 64,11 -> swap -> [34,25,12,22,11,64,90]
                        compare 64,90 -> no    -> [34,25,12,22,11,64,90]
After Pass 1: [34,25,12,22,11,64,90]   (90 fixed)

Pass 2:
compare 34,25 -> swap -> [25,34,12,22,11,64,90]
compare 34,12 -> swap -> [25,12,34,22,11,64,90]
compare 34,22 -> swap -> [25,12,22,34,11,64,90]
compare 34,11 -> swap -> [25,12,22,11,34,64,90]
compare 34,64 -> no
After Pass 2: [25,12,22,11,34,64,90]   (64,90 fixed)

Pass 3:
compare 25,12 -> swap -> [12,25,22,11,34,64,90]
compare 25,22 -> swap -> [12,22,25,11,34,64,90]
compare 25,11 -> swap -> [12,22,11,25,34,64,90]
compare 25,34 -> no
After Pass 3: [12,22,11,25,34,64,90]

Pass 4:
compare 12,22 -> no
compare 22,11 -> swap -> [12,11,22,25,34,64,90]
compare 22,25 -> no
After Pass 4: [12,11,22,25,34,64,90]

Pass 5:
compare 12,11 -> swap -> [11,12,22,25,34,64,90]
compare 12,22 -> no
After Pass 5: [11,12,22,25,34,64,90]   -> already sorted, optimized version stops here

Pass 6: no swaps -> array confirmed sorted
Final: [11,12,22,25,34,64,90]
```

### 7. Pseudocode
```
BubbleSort(A, n):
    for i = 0 to n-2:
        swapped = false
        for j = 0 to n-i-2:
            if A[j] > A[j+1]:
                swap(A[j], A[j+1])
                swapped = true
        if not swapped: break   // optimized early exit
```

### 8. C++ Implementation
```cpp
void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // optimization: array already sorted
    }
}
```

### 9–13. Properties
| Property | Value |
|---|---|
| Best Time | O(n) (optimized, already sorted) |
| Average Time | O(n²) |
| Worst Time | O(n²) |
| Space | O(1) |
| Stable | Yes |
| In-place | Yes |
| Adaptive | Yes (with early-exit optimization) |
| Recursive/Iterative | Iterative |

### 14. Advantages
Extremely simple to implement and understand; stable; detects already-sorted arrays in O(n) with optimization.

### 15. Disadvantages
Very slow on large datasets; O(n²) comparisons and swaps in worst/average case.

### 16. Best Use Cases
Teaching purposes; very small arrays; nearly-sorted data with optimized version.

### 17. Common Mistakes
- Forgetting the early-exit `swapped` flag (loses adaptiveness).
- Off-by-one errors in inner loop bound (`n-i-1` vs `n-i`).
- Not reducing the inner loop range each pass (redundant comparisons).

### 18. Interview Notes
Rarely asked to implement directly, but used to test understanding of basic complexity analysis and the meaning of "stable" and "adaptive" sorting.

### 19. Practice Questions
- Implement Bubble Sort and count total swaps performed.
- Detect if array is sorted using Bubble Sort's swapped flag.
- Sort a nearly-sorted array and analyze actual comparisons made.

---

## 4.2 Selection Sort

### 1. Definition
Selection Sort divides the array into a sorted and an unsorted part, and repeatedly selects the minimum element from the unsorted part, placing it at the end of the sorted part.

### 2. Why it Exists
Minimizes the number of **swaps** (only n-1 swaps total), useful when swap cost is high (e.g., flash memory writes).

### 3. Intuition
Think of repeatedly picking the smallest card from a pile and placing it in a growing sorted line.

### 4. Visual Explanation
```
[64,25,12,22,11] -> find min(11) at index 4 -> swap with index 0
[11,25,12,22,64] -> find min(12) in remaining [25,12,22,64] -> swap with index 1
[11,12,25,22,64] -> find min(22) in remaining [25,22,64] -> swap with index 2
[11,12,22,25,64] -> sorted
```

### 5. Working Principle
For each index `i`, find the minimum element in `A[i..n-1]` and swap it with `A[i]`.

### 6. Step-by-Step Dry Run on A = [64, 34, 25, 12, 22, 11, 90]

```
i=0: search min in [64,34,25,12,22,11,90] -> min=11 at idx5 -> swap(0,5)
     [11,34,25,12,22,64,90]
i=1: search min in [34,25,12,22,64,90]    -> min=12 at idx3 -> swap(1,3)
     [11,12,25,34,22,64,90]
i=2: search min in [25,34,22,64,90]       -> min=22 at idx4 -> swap(2,4)
     [11,12,22,34,25,64,90]
i=3: search min in [34,25,64,90]          -> min=25 at idx4 -> swap(3,4)
     [11,12,22,25,34,64,90]
i=4: search min in [34,64,90]             -> min=34 (already in place) -> no swap
     [11,12,22,25,34,64,90]
i=5: search min in [64,90]                -> min=64 (already in place) -> no swap
     [11,12,22,25,34,64,90]
Final: [11,12,22,25,34,64,90]
```

### 7. Pseudocode
```
SelectionSort(A, n):
    for i = 0 to n-2:
        minIdx = i
        for j = i+1 to n-1:
            if A[j] < A[minIdx]:
                minIdx = j
        swap(A[i], A[minIdx])
```

### 8. C++ Implementation
```cpp
void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
}
```

### 9–13. Properties
| Property | Value |
|---|---|
| Best Time | O(n²) |
| Average Time | O(n²) |
| Worst Time | O(n²) |
| Space | O(1) |
| Stable | No (standard version; swap can break order of equal keys) |
| In-place | Yes |
| Adaptive | No |
| Recursive/Iterative | Iterative |

### 14. Advantages
Minimizes number of swaps (exactly n-1); simple; useful when write operations are expensive.

### 15. Disadvantages
Always O(n²) regardless of input order (not adaptive); unstable.

### 16. Best Use Cases
Small arrays; situations where memory write/swap cost dominates over comparison cost.

### 17. Common Mistakes
- Swapping inside the inner loop instead of after finding the true minimum (extra unnecessary swaps).
- Forgetting that standard Selection Sort is unstable.

### 18. Interview Notes
Frequently used to explain why "fewer swaps" doesn't mean "faster algorithm" — interviewers test if you understand swap-cost vs comparison-cost tradeoffs.

### 19. Practice Questions
- Modify Selection Sort to be stable (insert instead of swap).
- Find kth smallest element using a partial Selection Sort.
- Sort an array of objects by selecting max instead of min (descending).

---

## 4.3 Insertion Sort

### 1. Definition
Insertion Sort builds the final sorted array one item at a time, taking each new element and inserting it into its correct position relative to already-sorted elements.

### 2. Why it Exists
Mirrors how humans naturally sort playing cards in hand; extremely efficient for small or nearly-sorted datasets.

### 3. Intuition
Maintain a sorted "hand" of cards on the left; pick up the next card and insert it into the correct spot among the sorted cards.

### 4. Visual Explanation
```
[5, 2, 4, 6, 1]
key=2: shift 5 right -> [5,5,4,6,1] -> insert 2 -> [2,5,4,6,1]
key=4: shift 5 right -> [2,5,5,6,1] -> insert 4 -> [2,4,5,6,1]
key=6: 6>5, no shift  -> [2,4,5,6,1]
key=1: shift 6,5,4,2  -> insert 1   -> [1,2,4,5,6]
```

### 5. Working Principle
For each index `i` from 1 to n-1, store `A[i]` as `key`, then shift all elements in `A[0..i-1]` greater than `key` one position right, and place `key` in the gap.

### 6. Step-by-Step Dry Run on A = [64, 34, 25, 12, 22, 11, 90]

```
i=1: key=34. A[0]=64>34 -> shift -> [64,64,25,12,22,11,90] -> insert at 0 -> [34,64,25,12,22,11,90]
i=2: key=25. 64>25 shift, 34>25 shift -> [34,64,64,12,22,11,90] -> wait carefully:
     [34,64,25,...] -> compare 64>25 shift -> [34,_,64,12,22,11,90]
     compare 34>25 shift -> [_,34,64,12,22,11,90] -> insert 25 at 0
     -> [25,34,64,12,22,11,90]
i=3: key=12. 64>12 shift, 34>12 shift, 25>12 shift -> insert at 0
     -> [12,25,34,64,22,11,90]
i=4: key=22. 64>22 shift, 34>22 shift, 25>22 shift, 12<22 stop -> insert at idx1
     -> [12,22,25,34,64,11,90]
i=5: key=11. 64,34,25,22,12 all >11, shift all -> insert at idx0
     -> [11,12,22,25,34,64,90]
i=6: key=90. 64<90, no shift -> [11,12,22,25,34,64,90]
Final: [11,12,22,25,34,64,90]
```

### 7. Pseudocode
```
InsertionSort(A, n):
    for i = 1 to n-1:
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j+1] = A[j]
            j = j - 1
        A[j+1] = key
```

### 8. C++ Implementation
```cpp
void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
```

### 9–13. Properties
| Property | Value |
|---|---|
| Best Time | O(n) (already sorted) |
| Average Time | O(n²) |
| Worst Time | O(n²) (reverse sorted) |
| Space | O(1) |
| Stable | Yes |
| In-place | Yes |
| Adaptive | Yes |
| Recursive/Iterative | Iterative (recursive variant exists) |

### 14. Advantages
Very fast on small or nearly-sorted arrays; stable; simple; adaptive; online (can sort data as it arrives).

### 15. Disadvantages
O(n²) on large random/reverse-sorted arrays; many shift operations.

### 16. Best Use Cases
Small arrays (often used as base case in Quick/Merge Sort hybrids, and inside TimSort for small runs); nearly sorted data; online/streaming sort.

### 17. Common Mistakes
- Using `>=` instead of `>` in the while condition (breaks stability).
- Off-by-one in starting index (should start at 1, not 0).
- Forgetting to handle empty/single-element arrays.

### 18. Interview Notes
A very common "explain and code from scratch" question; interviewers often follow up by asking to make it work on a linked list, or to find the insertion point via binary search (Binary Insertion Sort) for fewer comparisons (but same O(n) shifts).

### 19. Practice Questions
- Implement Binary Insertion Sort.
- Sort a nearly-sorted array (each element at most k positions away) efficiently.
- Implement Insertion Sort for a linked list.


---

# SECTION 5: Divide and Conquer Sorting

## 5.1 Merge Sort

### 1. Definition
Merge Sort recursively splits the array into halves until each sub-array has one element, then merges sorted sub-arrays back together to produce the fully sorted array.

### 2. Why it Exists
Provides guaranteed O(n log n) performance in all cases (best, average, worst) — unlike Quick Sort which can degrade to O(n²).

### 3. Intuition
Two already-sorted piles of cards can be merged into one sorted pile by repeatedly taking the smaller top card. Recursively sort smaller halves, then merge.

### 4. Visual Explanation (Recursive Tree)
```
                [64,34,25,12,22,11,90]
                  /                \
       [64,34,25,12]              [22,11,90]
        /        \                  /      \
   [64,34]      [25,12]          [22]    [11,90]
    /   \        /   \                    /    \
 [64]  [34]   [25]  [12]                [11]   [90]

Merge upward:
[64]+[34] -> [34,64]
[25]+[12] -> [12,25]
[34,64]+[12,25] -> [12,25,34,64]
[22] stays
[11]+[90] -> [11,90]
[22]+[11,90] -> [11,22,90]
[12,25,34,64] + [11,22,90] -> [11,12,22,25,34,64,90]
```

### 5. Working Principle
`mergeSort(A, l, r)`: if `l < r`, find `mid`, recursively sort `[l, mid]` and `[mid+1, r]`, then merge the two sorted halves.

### 6. Step-by-Step Dry Run
```
Split: [64,34,25,12,22,11,90]
   -> [64,34,25,12] | [22,11,90]
Split [64,34,25,12] -> [64,34] | [25,12]
Split [64,34] -> [64] | [34]        -> merge -> [34,64]
Split [25,12] -> [25] | [12]        -> merge -> [12,25]
Merge [34,64] + [12,25]:
  compare 34,12 -> take 12 -> [12]
  compare 34,25 -> take 25 -> [12,25]
  remaining 34,64           -> [12,25,34,64]
Split [22,11,90] -> [22] | [11,90]
Split [11,90] -> [11] | [90]        -> merge -> [11,90]
Merge [22] + [11,90]:
  compare 22,11 -> take 11 -> [11]
  compare 22,90 -> take 22 -> [11,22]
  remaining 90               -> [11,22,90]
Final Merge [12,25,34,64] + [11,22,90]:
  compare 12,11 -> take 11 -> [11]
  compare 12,22 -> take 12 -> [11,12]
  compare 25,22 -> take 22 -> [11,12,22]
  compare 25,90 -> take 25 -> [11,12,22,25]
  compare 34,90 -> take 34 -> [11,12,22,25,34]
  compare 64,90 -> take 64 -> [11,12,22,25,34,64]
  remaining 90               -> [11,12,22,25,34,64,90]
Final: [11,12,22,25,34,64,90]
```

### 7. Pseudocode
```
MergeSort(A, l, r):
    if l < r:
        mid = (l + r) / 2
        MergeSort(A, l, mid)
        MergeSort(A, mid+1, r)
        Merge(A, l, mid, r)

Merge(A, l, mid, r):
    create temp arrays Left = A[l..mid], Right = A[mid+1..r]
    i=0, j=0, k=l
    while i < len(Left) and j < len(Right):
        if Left[i] <= Right[j]: A[k++] = Left[i++]
        else: A[k++] = Right[j++]
    copy remaining elements of Left and Right into A
```

### 8. C++ Implementation
```cpp
void merge(vector<int>& a, int l, int mid, int r) {
    vector<int> left(a.begin() + l, a.begin() + mid + 1);
    vector<int> right(a.begin() + mid + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < (int)left.size() && j < (int)right.size()) {
        if (left[i] <= right[j]) a[k++] = left[i++]; // <= keeps it stable
        else a[k++] = right[j++];
    }
    while (i < (int)left.size()) a[k++] = left[i++];
    while (j < (int)right.size()) a[k++] = right[j++];
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, mid, r);
}
```

### 9–13. Properties
| Property | Value |
|---|---|
| Best Time | O(n log n) |
| Average Time | O(n log n) |
| Worst Time | O(n log n) |
| Space | O(n) auxiliary |
| Stable | Yes (with `<=` in merge) |
| In-place | No (standard version) |
| Adaptive | No (standard version; natural merge sort variant is) |
| Recursive/Iterative | Recursive (iterative bottom-up version exists) |

### 14. Advantages
Guaranteed O(n log n) in all cases; stable; works extremely well for linked lists and external sorting (sequential access).

### 15. Disadvantages
Requires O(n) extra space; more overhead than Quick Sort in practice for in-memory arrays due to copying.

### 16. Best Use Cases
Sorting linked lists; external sorting (huge files); when stability is required; when worst-case guarantees matter.

### 17. Common Mistakes
- Integer overflow computing `mid = (l + r) / 2` for huge arrays — use `l + (r - l) / 2`.
- Using `<` instead of `<=` in the merge comparison, which breaks stability.
- Forgetting base case `l >= r`, causing infinite recursion.

### 18. Interview Notes
Classic question: "Merge Sort a Linked List" (no extra array needed, O(1) extra space possible). Also commonly extended to count inversions in an array using the merge step.

### 19. Practice Questions
- Count inversions in an array using Merge Sort.
- Merge Sort a singly linked list.
- Merge k sorted arrays/lists.

---

## 5.2 Quick Sort

### 1. Definition
Quick Sort picks a pivot element, partitions the array so smaller elements go left and larger go right of the pivot, then recursively sorts the partitions.

### 2. Why it Exists
Extremely fast in practice (best constant factors among comparison sorts), in-place, and cache-friendly — the default general-purpose sort in many languages/runtimes (often combined into IntroSort).

### 3. Intuition
Place one element ("pivot") in its final correct position by ensuring everything smaller is to its left and everything bigger is to its right, then recurse on each side.

### 4. Visual Explanation (Lomuto Partition, pivot = last element)
```
[10, 80, 30, 90, 40] pivot = 40
i = -1
j=0: 10<=40 -> i=0, swap(0,0)  [10,80,30,90,40]
j=1: 80<=40? no
j=2: 30<=40 -> i=1, swap(1,2)  [10,30,80,90,40]
j=3: 90<=40? no
swap(i+1, pivotIndex) -> swap(2,4) -> [10,30,40,90,80]
pivot 40 now at index 2 (final position)
Recurse left [10,30], right [90,80]
```

### 5. Working Principle
`quickSort(A, low, high)`: choose pivot, partition array around it (pivot lands at its final sorted index `p`), recursively sort `A[low..p-1]` and `A[p+1..high]`.

### 6. Step-by-Step Dry Run on A = [64, 34, 25, 12, 22, 11, 90] (Lomuto, pivot = last element)

```
Call quickSort(0,6), pivot=A[6]=90
 i=-1
 j=0: 64<=90 -> i=0 swap(0,0) [64,34,25,12,22,11,90]
 j=1: 34<=90 -> i=1 swap(1,1) [64,34,25,12,22,11,90]
 j=2: 25<=90 -> i=2 swap(2,2) [64,34,25,12,22,11,90]
 j=3: 12<=90 -> i=3 swap(3,3) [64,34,25,12,22,11,90]
 j=4: 22<=90 -> i=4 swap(4,4) [64,34,25,12,22,11,90]
 j=5: 11<=90 -> i=5 swap(5,5) [64,34,25,12,22,11,90]
 swap(i+1=6, pivotIdx=6)      [64,34,25,12,22,11,90]   pivot 90 fixed at idx6

Call quickSort(0,5), pivot=A[5]=11
 i=-1
 j=0: 64<=11? no
 j=1: 34<=11? no
 j=2: 25<=11? no
 j=3: 12<=11? no
 j=4: 22<=11? no
 swap(i+1=0, pivotIdx=5) -> [11,34,25,12,22,64,90]   pivot 11 fixed at idx0

Call quickSort(1,5), pivot=A[5]=64
 i=0
 j=1: 34<=64 -> i=1 swap(1,1) [11,34,25,12,22,64,90]
 j=2: 25<=64 -> i=2 swap(2,2) [11,34,25,12,22,64,90]
 j=3: 12<=64 -> i=3 swap(3,3) [11,34,25,12,22,64,90]
 j=4: 22<=64 -> i=4 swap(4,4) [11,34,25,12,22,64,90]
 swap(i+1=5, pivotIdx=5)      [11,34,25,12,22,64,90]  pivot 64 fixed at idx5

Call quickSort(1,4), pivot=A[4]=22
 i=0
 j=1: 34<=22? no
 j=2: 25<=22? no
 j=3: 12<=22 -> i=1 swap(1,3) -> [11,12,25,34,22,64,90]
 swap(i+1=2, pivotIdx=4) -> [11,12,22,34,25,64,90]   pivot 22 fixed at idx2

Call quickSort(1,1) -> single element, base case ([12])
Call quickSort(3,4), pivot=A[4]=25
 i=2
 j=3: 34<=25? no
 swap(i+1=3, pivotIdx=4) -> [11,12,22,25,34,64,90]   pivot 25 fixed at idx3

Remaining single-element calls are base cases.
Final: [11,12,22,25,34,64,90]
```

### 7. Pseudocode (Lomuto Partition)
```
QuickSort(A, low, high):
    if low < high:
        p = Partition(A, low, high)
        QuickSort(A, low, p-1)
        QuickSort(A, p+1, high)

Partition(A, low, high):
    pivot = A[high]
    i = low - 1
    for j = low to high-1:
        if A[j] <= pivot:
            i++
            swap(A[i], A[j])
    swap(A[i+1], A[high])
    return i+1
```

### Lomuto vs Hoare Partition

| Aspect | Lomuto | Hoare |
|---|---|---|
| Pivot choice | Usually last element | Usually first element |
| Pointers | Single index `i` | Two pointers from both ends |
| Swaps | More swaps | Fewer swaps |
| Pivot final position | Guaranteed correct | NOT guaranteed at returned index |
| Performance | Slightly slower | Generally faster in practice |

```cpp
// Hoare Partition
int hoarePartition(vector<int>& a, int low, int high) {
    int pivot = a[low];
    int i = low - 1, j = high + 1;
    while (true) {
        do { i++; } while (a[i] < pivot);
        do { j--; } while (a[j] > pivot);
        if (i >= j) return j;
        swap(a[i], a[j]);
    }
}
```

### Randomized Pivot & Median-of-Three
```cpp
// Randomized pivot: swap a random element into the 'high' slot before Lomuto partition
int randomizedPartition(vector<int>& a, int low, int high) {
    int randIdx = low + rand() % (high - low + 1);
    swap(a[randIdx], a[high]);
    return /* call standard Lomuto partition here */ 0;
}

// Median-of-three: pick median of a[low], a[mid], a[high] as pivot to avoid worst-case on sorted/reverse-sorted input
```

### 8. C++ Implementation (full, Lomuto + randomized pivot)
```cpp
int partition(vector<int>& a, int low, int high) {
    int randIdx = low + rand() % (high - low + 1);
    swap(a[randIdx], a[high]); // randomize to avoid worst-case on sorted input
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}
```

### 9–13. Properties
| Property | Value |
|---|---|
| Best Time | O(n log n) |
| Average Time | O(n log n) |
| Worst Time | O(n²) (bad pivot choices, e.g. sorted array with last-element pivot) |
| Space | O(log n) (recursion stack, average); O(n) worst case |
| Stable | No |
| In-place | Yes |
| Adaptive | No |
| Recursive/Iterative | Recursive (iterative version with explicit stack exists) |

### 14. Advantages
Fastest in practice among comparison sorts for arrays (excellent cache locality, low constant factor); in-place; tail-call optimizable.

### 15. Disadvantages
Worst case O(n²); unstable; performance heavily depends on pivot choice; not ideal for linked lists or already-sorted data without randomization.

### 16. Best Use Cases
General-purpose in-memory array sorting; default `std::sort`/`qsort` base (combined with IntroSort/Heap Sort fallback).

### 17. Common Mistakes
- Choosing pivot as first/last element without randomization → O(n²) on sorted/reverse-sorted arrays.
- Infinite recursion if partition function doesn't make progress (e.g., wrong bounds in Hoare partition recursive calls — must use `low, j` and `j+1, high`, NOT `p-1`/`p+1` as in Lomuto).
- Stack overflow on worst-case recursion depth without tail-call optimization or recursing on the smaller partition first.

### 18. Interview Notes
A top-tier interview topic. Be ready to: explain why worst case is O(n²), explain Lomuto vs Hoare, implement an iterative version, and explain how randomization helps avoid adversarial worst-case inputs. Often paired with "find kth largest element" (Quickselect).

### 19. Practice Questions
- Implement Quickselect to find the kth smallest/largest element in O(n) average time.
- Sort an array of 0s, 1s, and 2s using a 3-way (Dutch National Flag) partition — this is "Quick Sort with 3-way partitioning."
- Convert recursive Quick Sort to iterative using an explicit stack.


---

# SECTION 6: Heap Sort

## Heap Basics (Only as Required for Heap Sort)

A **binary heap** is a complete binary tree stored in an array, where for any index `i`:
- Left child = `2*i + 1`
- Right child = `2*i + 2`
- Parent = `(i-1)/2`

A **Max Heap** satisfies `A[parent] >= A[child]` for all nodes — the maximum element is always at the root (index 0).

```
Array: [90, 64, 25, 12, 22, 11, 34]   represents this tree:

                90
              /    \
            64      25
           /  \     /  \
         12   22   11  34
```

### Heapify

`heapify(A, n, i)` assumes the subtrees rooted at the children of `i` are already valid max-heaps, and fixes the heap property at `i` by sinking it down if needed.

### Build Heap

Calling `heapify` on every non-leaf node from the last non-leaf node down to the root converts an arbitrary array into a valid max-heap in O(n) total time.

## Heap Sort Algorithm

### 1. Definition
Heap Sort builds a max-heap from the input array, then repeatedly swaps the root (maximum element) with the last element of the heap and reduces heap size by one, restoring heap order each time.

### 2. Why it Exists
Combines the in-place property of Quick Sort with the worst-case guarantee of Merge Sort — guaranteed O(n log n) with O(1) extra space.

### 3. Intuition
Repeatedly extract the maximum from a max-heap and place it at the end of the array — like repeatedly picking the tallest person out of a line and seating them from the back.

### 4. Visual Explanation
```
Build max-heap from [64,34,25,12,22,11,90]:
Result heap array: [90,34,64,12,22,11,25]   (one valid heap arrangement)

Extract max (90), swap with last element (25):
[25,34,64,12,22,11,90] -> heap size = 6, heapify root
-> [64,34,25,12,22,11,90]

Extract max (64), swap with last active element (11):
[11,34,25,12,22,64,90] -> heap size = 5, heapify root
-> [34,22,25,12,11,64,90]

...continue until heap size = 1
```

### 5. Working Principle
1. Build a max-heap from the array — O(n).
2. Repeat n-1 times: swap root with last element of the (shrinking) heap, reduce heap size, heapify the root — O(log n) each, O(n log n) total.

### 6. Step-by-Step Dry Run on A = [64, 34, 25, 12, 22, 11, 90]

```
Initial array as tree (indices 0-6): [64,34,25,12,22,11,90]
Build Max-Heap (heapify from last non-leaf node, index 2, down to 0):

heapify(i=2): node 25, children 11(5),90(6) -> largest=90 -> swap(2,6)
  -> [64,34,90,12,22,11,25]
heapify(i=1): node 34, children 12(3),22(4) -> largest=34, no swap
heapify(i=0): node 64, children 34(1),90(2) -> largest=90 -> swap(0,2)
  -> [90,34,64,12,22,11,25]
  recurse heapify(i=2 i.e. new position of 64): children 11(5),25(6) -> largest=64, no swap
Heap built: [90,34,64,12,22,11,25]

Extract 1: swap(0,6) -> [25,34,64,12,22,11,90], heap size=6
  heapify(0): node 25, children 34(1),64(2) -> largest=64 -> swap(0,2)
  -> [64,34,25,12,22,11,90]
  heapify(2): node 25, children 11(5) only (within size 6) -> largest=25, no swap
  Sorted so far (from back): [...,90]

Extract 2: swap(0,5) -> [11,34,25,12,22,64,90], heap size=5
  heapify(0): children 34(1),25(2) -> largest=34 -> swap(0,1)
  -> [34,11,25,12,22,64,90]
  heapify(1): children 12(3),22(4) -> largest=22 -> swap(1,4)
  -> [34,22,25,12,11,64,90]
  Sorted so far: [...,64,90]

Extract 3: swap(0,4) -> [11,22,25,12,34,64,90], heap size=4
  heapify(0): children 22(1),25(2) -> largest=25 -> swap(0,2)
  -> [25,22,11,12,34,64,90]
  heapify(2): no children within size4, done
  Sorted so far: [...,34,64,90]

Extract 4: swap(0,3) -> [12,22,11,25,34,64,90], heap size=3
  heapify(0): children 22(1),11(2) -> largest=22 -> swap(0,1)
  -> [22,12,11,25,34,64,90]
  Sorted so far: [...,25,34,64,90]

Extract 5: swap(0,2) -> [11,12,22,25,34,64,90], heap size=2
  heapify(0): child 12(1) -> largest=12 -> swap(0,1)
  -> [12,11,22,25,34,64,90]
  Sorted so far: [...,22,25,34,64,90]

Extract 6: swap(0,1) -> [11,12,22,25,34,64,90], heap size=1
Final: [11,12,22,25,34,64,90]
```

### 7. Pseudocode
```
HeapSort(A, n):
    BuildMaxHeap(A, n)
    for i = n-1 down to 1:
        swap(A[0], A[i])
        Heapify(A, i, 0)     // heap size shrinks to i

Heapify(A, n, i):
    largest = i
    left = 2*i+1, right = 2*i+2
    if left < n and A[left] > A[largest]: largest = left
    if right < n and A[right] > A[largest]: largest = right
    if largest != i:
        swap(A[i], A[largest])
        Heapify(A, n, largest)

BuildMaxHeap(A, n):
    for i = n/2 - 1 down to 0:
        Heapify(A, n, i)
```

### 8. C++ Implementation
```cpp
void heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && a[left] > a[largest]) largest = left;
    if (right < n && a[right] > a[largest]) largest = right;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i); // build heap
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
```

### 9–13. Properties
| Property | Value |
|---|---|
| Best Time | O(n log n) |
| Average Time | O(n log n) |
| Worst Time | O(n log n) |
| Space | O(1) (iterative heapify) or O(log n) (recursive call stack) |
| Stable | No |
| In-place | Yes |
| Adaptive | No |
| Recursive/Iterative | Heapify usually recursive; overall structure iterative |

### 14. Advantages
Guaranteed O(n log n) worst case; in-place (O(1) extra space); no worst-case degradation like Quick Sort.

### 15. Disadvantages
Unstable; poor cache locality (jumps around array via heap indices) — slower in practice than Quick Sort despite same big-O; not adaptive.

### 16. Best Use Cases
When O(1) extra space AND guaranteed O(n log n) are both required; implementing priority queues; finding top-K elements (partial heap sort).

### 17. Common Mistakes
- Building the heap from index 0 instead of starting from the last non-leaf node (`n/2 - 1`).
- Forgetting to shrink heap size in the extraction loop.
- Off-by-one errors in child index formulas (`2*i+1`, `2*i+2`).

### 18. Interview Notes
Commonly asked alongside priority queue implementation, "find kth largest element using a heap," and "merge k sorted lists using a min-heap."

### 19. Practice Questions
- Find the kth largest element using a min-heap of size k.
- Sort a nearly-sorted (k-sorted) array using a min-heap.
- Implement a priority queue from scratch using heap operations.


---

# SECTION 7: Linear Time Sorting

## 7.1 Counting Sort

### 1. Definition
Counting Sort sorts integers within a known small range by counting the occurrences of each distinct value, then using prefix sums to place elements directly into their output position.

### 2. Why it Exists
Comparison sorts are bounded by Ω(n log n). Counting Sort beats this bound by **not comparing elements at all** — it exploits known range information.

### 3. Intuition
If you know all values lie between 0 and k, you can count how many times each value appears and reconstruct the sorted array directly from the counts.

### 4. Visual Explanation
```
Input: [4, 2, 2, 8, 3, 3, 1]   range 0..8

Count array (index = value):
idx:   0 1 2 3 4 5 6 7 8
cnt:   0 1 2 2 1 0 0 0 1

Prefix sum (cumulative count = position to place last occurrence):
idx:   0 1 2 3 4 5 6 7 8
psum:  0 1 3 5 6 6 6 6 7

Place elements from right to left of input (for stability) using prefix sums.
Output: [1, 2, 2, 3, 3, 4, 8]
```

### 5. Working Principle
1. Find range `[min, max]`.
2. Build count array of size `max-min+1`, count occurrences.
3. Convert counts to prefix sums (cumulative counts).
4. Traverse input from right to left, placing each element at `prefixSum[value]-1` in output, then decrement.

### 6. Step-by-Step Dry Run on A = [64, 34, 25, 12, 22, 11, 90]
```
Range: min=11, max=90 -> count array size = 80 (indices 0..79 representing values 11..90)

Count occurrences (each value appears once here):
value 11->1, 12->1, 22->1, 25->1, 34->1, 64->1, 90->1  (all others 0)

Prefix sums give each value's final position automatically based on rank.
Since all elements are distinct, this effectively places them in ascending order:
Output: [11, 12, 22, 25, 34, 64, 90]

(Note: Counting Sort is efficient here only conceptually — with max=90 it requires
an array of size 80, illustrating why it's only good for SMALL ranges relative to n.)
```

### 7. Pseudocode
```
CountingSort(A, n):
    max = max(A), min = min(A)
    range = max - min + 1
    count[0..range-1] = 0
    for i = 0 to n-1:
        count[A[i]-min]++
    for i = 1 to range-1:
        count[i] += count[i-1]          // prefix sum
    output[0..n-1]
    for i = n-1 down to 0:               // traverse backward for stability
        output[count[A[i]-min]-1] = A[i]
        count[A[i]-min]--
    copy output back to A
```

### 8. C++ Implementation
```cpp
void countingSort(vector<int>& a) {
    if (a.empty()) return;
    int maxVal = *max_element(a.begin(), a.end());
    int minVal = *min_element(a.begin(), a.end());
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0), output(a.size());
    for (int x : a) count[x - minVal]++;
    for (int i = 1; i < range; i++) count[i] += count[i - 1];
    for (int i = (int)a.size() - 1; i >= 0; i--) { // backward = stable
        output[count[a[i] - minVal] - 1] = a[i];
        count[a[i] - minVal]--;
    }
    a = output;
}
```

### 9–13. Properties
| Property | Value |
|---|---|
| Best/Avg/Worst Time | O(n + k), where k = range of input |
| Space | O(n + k) |
| Stable | Yes |
| In-place | No |
| Adaptive | No |
| Recursive/Iterative | Iterative |

### 14. Advantages
Linear time when `k = O(n)`; stable; simple.

### 15. Disadvantages
Impractical when range `k` is very large (huge memory); only works on integers/discrete keys (or values mappable to small integer range).

### 16. Best Use Cases
Sorting grades (0-100), ages, small fixed-range categorical data; as a subroutine inside Radix Sort.

### 17. Common Mistakes
- Forgetting to offset by `min` when values can be negative or don't start at 0.
- Traversing forward instead of backward when stability is required.
- Allocating count array based on `n` instead of the actual value range `k`.

### 18. Interview Notes
Common follow-up: "Sort an array of 0s, 1s, and 2s" — a specialized 1-pass Counting Sort (see Section 12, Dutch National Flag).

### 19. Practice Questions
- Sort an array containing only 0s, 1s, and 2s in a single pass.
- Sort students by grade (small fixed range) while preserving original order for ties.
- Use Counting Sort as a building block for Radix Sort.

## 7.2 Radix Sort

### 1. Definition
Radix Sort sorts integers by processing individual digits, from least significant digit (LSD) to most significant digit (MSD), using a stable sort (typically Counting Sort) at each digit position.

### 2. Why it Exists
Extends Counting Sort's linear-time idea to handle numbers with large value ranges by sorting digit-by-digit instead of by full value — avoiding a huge range array.

### 3. Intuition
Like sorting a stack of mail by postal code: first sort by the last digit, then by the second-last, and so on — since each sub-sort is stable, the final order ends up fully correct.

### 4. Visual Explanation
```
Input: [170, 45, 75, 90, 802, 24, 2, 66]

Pass 1 (sort by 1s digit, stable):
[170, 90, 802, 2, 24, 45, 75, 66]

Pass 2 (sort by 10s digit, stable):
[802, 2, 24, 45, 66, 170, 75, 90]

Pass 3 (sort by 100s digit, stable):
[2, 24, 45, 66, 75, 90, 170, 802]

Sorted!
```

### 5. Working Principle
For `d` = number of digits in the maximum value, perform `d` passes of stable digit-based Counting Sort, starting from the least significant digit.

### 6. Step-by-Step Dry Run on A = [64, 34, 25, 12, 22, 11, 90]
```
Max value = 90, has 2 digits -> 2 passes

Pass 1 (sort by 1s digit / exp=1):
digits: 64->4, 34->4, 25->5, 12->2, 22->2, 11->1, 90->0
Stable counting sort by these digits gives:
[90, 11, 12, 22, 34, 64, 25]
  (digit order 0,1,2,2,4,4,5 — ties broken by original order: 12 before 22 (orig order), 34 before 64 (orig order))

Pass 2 (sort by 10s digit / exp=10):
digits: 90->9, 11->1, 12->1, 22->2, 34->3, 64->6, 25->2
Stable counting sort by these digits (input is previous pass's output):
[11, 12, 22, 25, 34, 64, 90]
  (digit order 1,1,2,2,3,6,9 — ties 11/12 keep relative order from pass1, 22/25 keep relative order)

Final: [11, 12, 22, 25, 34, 64, 90]
```

### 7. Pseudocode
```
RadixSort(A, n):
    maxVal = max(A)
    for exp = 1; maxVal/exp > 0; exp *= 10:
        CountingSortByDigit(A, n, exp)

CountingSortByDigit(A, n, exp):
    output[0..n-1]
    count[0..9] = 0
    for i = 0 to n-1: count[(A[i]/exp) % 10]++
    for i = 1 to 9: count[i] += count[i-1]
    for i = n-1 down to 0:
        digit = (A[i]/exp) % 10
        output[count[digit]-1] = A[i]
        count[digit]--
    copy output back to A
```

### 8. C++ Implementation
```cpp
void countingSortByDigit(vector<int>& a, int exp) {
    int n = a.size();
    vector<int> output(n);
    int count[10] = {0};
    for (int i = 0; i < n; i++) count[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }
    a = output;
}

void radixSort(vector<int>& a) {
    if (a.empty()) return;
    int maxVal = *max_element(a.begin(), a.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSortByDigit(a, exp);
}
```

### 9–13. Properties
| Property | Value |
|---|---|
| Best/Avg/Worst Time | O(d·(n+k)), d = digits, k = 10 for base-10 |
| Space | O(n + k) |
| Stable | Yes (when using stable digit sort) |
| In-place | No |
| Adaptive | No |
| Recursive/Iterative | Iterative |

### 14. Advantages
Can beat O(n log n) for fixed-length integers/strings; stable; predictable performance.

### 15. Disadvantages
Only works on data with sortable digit/character representation; not adaptive; negative numbers need special handling.

### 16. Best Use Cases
Sorting large lists of fixed-length integers, phone numbers, or fixed-length strings.

### 17. Common Mistakes
- Forgetting to handle negative numbers (typically separate negatives and positives, sort each, then concatenate).
- Using an unstable digit sort, which breaks the overall algorithm's correctness.
- Stopping passes before processing the most significant digit of the largest number.

### 18. Interview Notes
Asked to demonstrate non-comparison sorting and to discuss when it beats O(n log n) sorts (when `d` is small relative to `log n`).

### 19. Practice Questions
- Sort an array of strings of equal length using Radix Sort.
- Modify Radix Sort to handle negative integers.
- Use Radix Sort to sort large fixed-width IDs.

## 7.3 Bucket Sort

### 1. Definition
Bucket Sort distributes elements into a number of "buckets" based on value range, sorts each bucket individually (commonly with Insertion Sort), then concatenates the buckets in order.

### 2. Why it Exists
Works extremely well when input is **uniformly distributed** over a range — average case beats O(n log n).

### 3. Intuition
Like sorting exam scores by first throwing them into bins (0-9, 10-19, ..., 90-100), then sorting each small bin individually.

### 4. Visual Explanation
```
Input (floats in [0,1)): [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68]

Buckets (10 buckets, range 0.1 each):
B0[0.0-0.1): []
B1[0.1-0.2): [0.17, 0.12]
B2[0.2-0.3): [0.26, 0.21, 0.23]
B3[0.3-0.4): [0.39]
B6[0.6-0.7): [0.68]
B7[0.7-0.8): [0.78, 0.72]
B9[0.9-1.0): [0.94]

Sort each bucket (Insertion Sort), then concatenate:
[0.12,0.17, 0.21,0.23,0.26, 0.39, 0.68, 0.72,0.78, 0.94]
```

### 5. Working Principle
1. Create `k` empty buckets.
2. Distribute each element into bucket `index = k * value / (max+1)` (for integers) or based on range.
3. Sort each bucket individually.
4. Concatenate buckets in order.

### 6. Step-by-Step Dry Run on A = [64, 34, 25, 12, 22, 11, 90] (using 5 buckets over range [11,90])
```
range = 90-11+1 = 80, bucket width = 80/5 = 16
Bucket 0 [11-26]:  64? no. 34?no. 25 yes. 12 yes. 22 yes. 11 yes. 90?no -> [25,12,22,11]
Bucket 1 [27-42]:  34 -> [34]
Bucket 2 [43-58]:  (empty)
Bucket 3 [59-74]:  64 -> [64]
Bucket 4 [75-90]:  90 -> [90]

Sort each bucket:
B0 sorted: [11,12,22,25]
B1 sorted: [34]
B3 sorted: [64]
B4 sorted: [90]

Concatenate: [11,12,22,25, 34, 64, 90]
Final: [11,12,22,25,34,64,90]
```

### 7. Pseudocode
```
BucketSort(A, n):
    create n empty buckets
    for i = 0 to n-1:
        idx = n * A[i] / (maxVal + 1)
        buckets[idx].insert(A[i])
    for each bucket:
        sort bucket (e.g., insertion sort)
    concatenate all buckets in order into A
```

### 8. C++ Implementation
```cpp
void bucketSort(vector<float>& a) { // for floats in [0,1)
    int n = a.size();
    vector<vector<float>> buckets(n);
    for (float x : a) {
        int idx = n * x; // assumes 0 <= x < 1
        buckets[idx].push_back(x);
    }
    for (auto& b : buckets) sort(b.begin(), b.end()); // insertion sort works well too
    int k = 0;
    for (auto& b : buckets)
        for (float x : b) a[k++] = x;
}
```

### 9–13. Properties
| Property | Value |
|---|---|
| Best Time | O(n + k) (uniform distribution) |
| Average Time | O(n + n²/k + k) ≈ O(n) when k ≈ n and data uniform |
| Worst Time | O(n²) (all elements in one bucket) |
| Space | O(n + k) |
| Stable | Yes (if the per-bucket sort is stable) |
| In-place | No |
| Adaptive | No |
| Recursive/Iterative | Iterative |

### 14. Advantages
Can achieve near-linear average time on uniformly distributed data; parallelizable (each bucket sorted independently).

### 15. Disadvantages
Worst case O(n²) if data is skewed into few buckets; requires knowledge of data distribution to choose good bucket ranges.

### 16. Best Use Cases
Uniformly distributed floating-point data in a known range; external sorting with naturally clustered data.

### 17. Common Mistakes
- Poor bucket count/range choice leading to skewed distribution (most elements landing in one bucket).
- Forgetting to sort within each bucket.
- Off-by-one in bucket index formula causing out-of-bounds access.

### 18. Interview Notes
Less commonly implemented from scratch in interviews, but conceptually tested via "how would you sort floating point numbers uniformly distributed between 0 and 1 in linear time."

### 19. Practice Questions
- Implement Bucket Sort for floating point numbers in [0, 1).
- Sort ages of a large population (likely uniform within a range) using buckets.
- Compare Bucket Sort performance on uniform vs skewed data.


---

# SECTION 8: Advanced Sorting Algorithms

## 8.1 Shell Sort

**Definition:** A generalization of Insertion Sort that compares elements far apart (a "gap"), progressively reducing the gap to 1, allowing elements to move long distances early on, which makes the final insertion-sort pass much cheaper.

**Intuition:** Insertion Sort is slow because elements move one position at a time. Shell Sort first sorts far-apart elements ("h-sorting"), so by the time gap=1, the array is nearly sorted.

**Visual (gap sequence n/2, n/4, ..., 1) on A = [64,34,25,12,22,11,90]:**
```
n=7, gap=3:
Compare/insert with stride 3: (64,12),(34,22),(25,11) groups
 group {A[0],A[3]} = {64,12} -> insertion-sort -> {12,64} -> [12,34,25,64,22,11,90]
 group {A[1],A[4]} = {34,22} -> sorted as {22,34} -> [12,22,25,64,34,11,90]
 group {A[2],A[5]} = {25,11} -> sorted as {11,25} -> [12,22,11,64,34,25,90]
 group {A[3],A[6]} continues with updated values...
 (after full gap=3 pass) -> [12,22,11,25,34,64,90] (approx, gap-sorted)

gap=1 (regular insertion sort) on nearly-sorted array:
-> [11,12,22,25,34,64,90]   (fast because array is nearly sorted already)
```

**Pseudocode:**
```
ShellSort(A, n):
    gap = n/2
    while gap > 0:
        for i = gap to n-1:
            temp = A[i]
            j = i
            while j >= gap and A[j-gap] > temp:
                A[j] = A[j-gap]
                j -= gap
            A[j] = temp
        gap = gap/2
```

**C++:**
```cpp
void shellSort(vector<int>& a) {
    int n = a.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i], j = i;
            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
    }
}
```

| Property | Value |
|---|---|
| Time | O(n log n) to O(n²) depending on gap sequence (Best: ~O(n log n), Worst: O(n²)) |
| Space | O(1) |
| Stable | No |
| In-place | Yes |
| Adaptive | Yes |

**Use cases:** Medium-sized arrays; embedded systems with limited memory (no recursion, no extra space). **Common mistake:** Using a poor gap sequence (plain n/2 halving) gives worse worst-case than sequences like Knuth's (3k+1) or Sedgewick's.

---

## 8.2 Tim Sort

**Definition:** A hybrid stable sort combining Insertion Sort (for small "runs") and Merge Sort (to merge runs), used in Python's `sorted()` and Java's `Arrays.sort()` for objects.

**Intuition:** Real-world data often contains already-sorted (or reverse-sorted) subsequences called "runs." TimSort detects these runs, extends short ones using Insertion Sort up to a minimum run length (`MIN_RUN`, typically 32-64), then merges runs using a Merge-Sort-like strategy with smart merge-order rules to stay efficient.

**Visual:**
```
Input split into runs based on existing order:
[1,2,3, 9,8,7,6, 4,5, 10]
 run1(asc)  run2(desc, reversed to asc) run3(asc) run4

Detected runs: [1,2,3] [6,7,8,9] [4,5] [10]
Extend short runs with insertion sort to MIN_RUN if needed.
Merge runs pairwise (like Merge Sort) using a stack-based merge strategy:
[1,2,3]+[6,7,8,9] -> [1,2,3,6,7,8,9]
[4,5]+[10]        -> [4,5,10]
Final merge: [1,2,3,4,5,6,7,8,9,10]
```

**Pseudocode (simplified):**
```
TimSort(A, n):
    MIN_RUN = 32
    for start = 0 to n step MIN_RUN:
        InsertionSort(A, start, min(start+MIN_RUN-1, n-1))
    size = MIN_RUN
    while size < n:
        for left = 0 to n step 2*size:
            mid = left + size - 1
            right = min(left + 2*size - 1, n-1)
            if mid < right: Merge(A, left, mid, right)
        size *= 2
```

| Property | Value |
|---|---|
| Best Time | O(n) (already sorted) |
| Average/Worst Time | O(n log n) |
| Space | O(n) |
| Stable | Yes |
| In-place | No |
| Adaptive | Yes (highly) |

**Use cases:** General-purpose default sort for languages prioritizing stability and real-world adaptiveness (Python, Java). **Interview note:** Rarely implemented fully from scratch, but you should know it's Python's/Java's default and *why* (stable + adaptive + good worst case).

---

## 8.3 IntroSort (Introspective Sort)

**Definition:** A hybrid of Quick Sort, Heap Sort, and Insertion Sort. Starts with Quick Sort; if recursion depth exceeds a threshold (`2*log(n)`), switches to Heap Sort to guarantee O(n log n); switches to Insertion Sort for small sub-arrays.

**Why it exists:** Gets Quick Sort's excellent average-case speed while eliminating its O(n²) worst case — used internally by C++ STL's `std::sort`.

**Visual / Logic Flow:**
```
        Start with QuickSort
               |
   recursion depth > 2*log2(n)? ----yes----> switch to HeapSort (guarantees O(n log n))
               | no
   sub-array size < 16? ----yes----> switch to InsertionSort (fast on small arrays)
               | no
        continue QuickSort partitioning
```

| Property | Value |
|---|---|
| Time | O(n log n) guaranteed worst case |
| Space | O(log n) |
| Stable | No |
| In-place | Yes |

**Use cases:** This is what `std::sort` actually uses in C++ — general-purpose, production-grade sorting. **Interview note:** Know this is why `std::sort` has a guaranteed O(n log n) worst case (unlike plain Quick Sort).

---

## 8.4 Tree Sort

**Definition:** Insert all elements into a Binary Search Tree (BST), then perform an in-order traversal to retrieve elements in sorted order.

**Visual:**
```
Insert [64,34,25,12,22,11,90] into a BST:

              64
            /    \
          34      90
         /  \
       25   ...
      /
    12
      \
       22
   (11 goes left of 12)

In-order traversal: 11,12,22,25,34,64,90
```

**C++ sketch:**
```cpp
struct Node { int val; Node *left, *right; };
void insert(Node*& root, int val) {
    if (!root) { root = new Node{val, nullptr, nullptr}; return; }
    if (val < root->val) insert(root->left, val);
    else insert(root->right, val);
}
void inorder(Node* root, vector<int>& out) {
    if (!root) return;
    inorder(root->left, out);
    out.push_back(root->val);
    inorder(root->right, out);
}
```

| Property | Value |
|---|---|
| Average Time | O(n log n) |
| Worst Time | O(n²) (skewed BST, e.g. sorted input) |
| Space | O(n) |
| Stable | Depends on duplicate handling |

**Use case:** When you need sorted data plus fast future insertions/lookups (use a self-balancing BST for guaranteed O(n log n)).

---

## 8.5 Cocktail Sort (Bidirectional Bubble Sort)

**Definition:** A variation of Bubble Sort that sorts in both directions on each pass — forward pass bubbles the largest element to the end, backward pass bubbles the smallest element to the start.

**Visual:**
```
Forward pass: bubble largest to the right (like Bubble Sort)
Backward pass: bubble smallest to the left
This fixes both ends each "round", converging faster than one-directional bubble sort
on arrays where small elements are near the end ("turtles").
```

**C++:**
```cpp
void cocktailSort(vector<int>& a) {
    int n = a.size(), start = 0, end = n - 1;
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; i++)
            if (a[i] > a[i+1]) { swap(a[i], a[i+1]); swapped = true; }
        if (!swapped) break;
        end--;
        swapped = false;
        for (int i = end; i > start; i--)
            if (a[i-1] > a[i]) { swap(a[i-1], a[i]); swapped = true; }
        start++;
    }
}
```

| Property | Value |
|---|---|
| Time | O(n²) worst/avg, O(n) best |
| Space | O(1) |
| Stable | Yes |
| In-place | Yes |
| Adaptive | Yes |

**Use case:** Mostly educational; fixes Bubble Sort's "turtle" problem (small values stuck near the end).

---

## 8.6 Comb Sort

**Definition:** An improvement over Bubble Sort that uses a shrinking gap (like Shell Sort) instead of comparing only adjacent elements, eliminating "turtles" (small values near the end) early.

**C++:**
```cpp
void combSort(vector<int>& a) {
    int n = a.size(), gap = n;
    bool swapped = true;
    while (gap > 1 || swapped) {
        gap = max(1, (int)(gap / 1.3));
        swapped = false;
        for (int i = 0; i + gap < n; i++) {
            if (a[i] > a[i + gap]) { swap(a[i], a[i + gap]); swapped = true; }
        }
    }
}
```

| Property | Value |
|---|---|
| Time | O(n²/2^p) average, O(n²) worst, O(n log n) best-ish |
| Space | O(1) |
| Stable | No |
| In-place | Yes |

**Use case:** Simple improvement over Bubble Sort when no library sort is available.

---

## 8.7 Gnome Sort

**Definition:** Similar to Insertion Sort, but moves backward swapping one position at a time instead of shifting — like a garden gnome sorting flower pots by repeatedly looking at the pot behind it.

**C++:**
```cpp
void gnomeSort(vector<int>& a) {
    int n = a.size(), i = 0;
    while (i < n) {
        if (i == 0 || a[i-1] <= a[i]) i++;
        else { swap(a[i], a[i-1]); i--; }
    }
}
```

| Property | Value |
|---|---|
| Time | O(n²) avg/worst, O(n) best |
| Space | O(1) |
| Stable | Yes |
| In-place | Yes |
| Adaptive | Yes |

**Use case:** Educational; extremely simple code, similar performance profile to Insertion Sort.

---

## 8.8 Pancake Sort

**Definition:** Sorts by repeatedly "flipping" (reversing) a prefix of the array — like flipping a stack of pancakes with a spatula to get the largest unsorted pancake to the bottom.

**Visual:**
```
[3,1,4,2] -> find max(4) at idx2 -> flip prefix[0..2] -> [4,1,3,2]
           -> flip prefix[0..3] (whole array) -> [2,3,1,4]   (4 now at end, fixed)
Repeat for remaining [2,3,1]:
 find max(3) at idx1 -> flip[0..1] -> [3,2,1] -> flip[0..2] -> [1,2,3,4]
```

**C++:**
```cpp
void flip(vector<int>& a, int k) { reverse(a.begin(), a.begin() + k + 1); }
void pancakeSort(vector<int>& a) {
    for (int size = a.size(); size > 1; size--) {
        int maxIdx = max_element(a.begin(), a.begin() + size) - a.begin();
        if (maxIdx != size - 1) {
            flip(a, maxIdx);
            flip(a, size - 1);
        }
    }
}
```

| Property | Value |
|---|---|
| Time | O(n²) |
| Space | O(1) |
| Stable | No |

**Use case:** Mostly a classic interview/puzzle problem (LeetCode "Pancake Sorting") testing array manipulation, not used in production.

---

## 8.9 Cycle Sort

**Definition:** Minimizes the number of memory writes — useful when writes are very costly. Places each element directly into its correct final position by following "cycles" of misplaced elements.

**C++:**
```cpp
void cycleSort(vector<int>& a) {
    int n = a.size();
    for (int start = 0; start < n - 1; start++) {
        int item = a[start];
        int pos = start;
        for (int i = start + 1; i < n; i++) if (a[i] < item) pos++;
        if (pos == start) continue;
        while (item == a[pos]) pos++;
        swap(a[pos], item);
        while (pos != start) {
            pos = start;
            for (int i = start + 1; i < n; i++) if (a[i] < item) pos++;
            while (item == a[pos]) pos++;
            swap(a[pos], item);
        }
    }
}
```

| Property | Value |
|---|---|
| Time | O(n²) |
| Space | O(1) |
| Stable | No |
| In-place | Yes |

**Use case:** Theoretically optimal number of writes (each element written at most once) — ideal for EEPROM/flash memory where writes are expensive.

---

## 8.10 Sleep Sort (Educational Only — Not a Real Algorithm)

**Definition:** A joke/educational "algorithm" that spawns a thread/task per element, each sleeping for a duration proportional to its value, then printing/collecting the value when it wakes up — naturally producing sorted output if timing is precise.

```cpp
// Conceptual only — not a real-world usable algorithm
#include <thread>
#include <chrono>
void sleepSort(vector<int>& a) {
    vector<thread> threads;
    for (int x : a) {
        threads.emplace_back([x]() {
            this_thread::sleep_for(chrono::milliseconds(x * 10));
            cout << x << " ";
        });
    }
    for (auto& t : threads) t.join();
}
```

**Why it's not real:** Relies on OS thread scheduling precision, doesn't scale, fails with negative numbers or large values, no complexity guarantees. Included purely as a fun illustration of "creative but impractical" algorithmic thinking — never used in interviews or production.


---

# SECTION 9: STL Sorting in C++

| Function | Complexity | Description |
|---|---|---|
| `sort(begin, end)` | O(n log n) avg, O(n log n) worst (IntroSort) | Sorts range, unstable |
| `stable_sort(begin, end)` | O(n log n) always | Sorts preserving relative order of equal elements (uses Merge Sort internally) |
| `partial_sort(begin, mid, end)` | O(n log k), k = mid-begin | Sorts only the first k elements fully; rest unspecified order |
| `nth_element(begin, nth, end)` | O(n) average | Places the nth element in its sorted position; smaller before, larger after (unsorted within partitions) |
| `is_sorted(begin, end)` | O(n) | Returns true if range is sorted |
| `is_sorted_until(begin, end)` | O(n) | Returns iterator to first out-of-order element |
| `inplace_merge(begin, mid, end)` | O(n) extra space, O(n log n) comparisons | Merges two consecutive sorted ranges in place |
| `merge(b1, e1, b2, e2, dest)` | O(n+m) | Merges two sorted ranges into a destination |
| `reverse(begin, end)` | O(n) | Reverses a range |
| `reverse_copy(begin, end, dest)` | O(n) | Copies range in reverse order |
| `rotate(begin, mid, end)` | O(n) | Rotates range so `mid` becomes the new first element |
| `next_permutation(begin, end)` | O(n) | Rearranges to the next lexicographic permutation |
| `prev_permutation(begin, end)` | O(n) | Rearranges to the previous lexicographic permutation |
| `binary_search(begin, end, val)` | O(log n) | Returns true/false if val exists (range must be sorted) |
| `lower_bound(begin, end, val)` | O(log n) | First position where val could be inserted keeping order (first >= val) |
| `upper_bound(begin, end, val)` | O(log n) | First position where val could be inserted after all equal elements (first > val) |
| `equal_range(begin, end, val)` | O(log n) | Returns pair {lower_bound, upper_bound} |

## Examples

```cpp
vector<int> v = {5, 2, 8, 2, 9, 1};

sort(v.begin(), v.end());                  // [1,2,2,5,8,9]
sort(v.begin(), v.end(), greater<int>());  // [9,8,5,2,2,1]

stable_sort(v.begin(), v.end());           // preserves order of equal elements

vector<int> v2 = {5,2,8,2,9,1};
partial_sort(v2.begin(), v2.begin()+3, v2.end()); // first 3 elements fully sorted ascending

vector<int> v3 = {5,2,8,2,9,1};
nth_element(v3.begin(), v3.begin()+2, v3.end()); // v3[2] is the 3rd smallest element

cout << is_sorted(v.begin(), v.end());     // 1 (true)

auto it = lower_bound(v.begin(), v.end(), 5); // iterator to first element >= 5
auto it2 = upper_bound(v.begin(), v.end(), 5); // iterator to first element > 5

vector<int> p = {1,2,3};
next_permutation(p.begin(), p.end());      // p becomes [1,3,2]
```

## Common Mistakes with STL Sorting

- Calling `binary_search`, `lower_bound`, or `upper_bound` on an **unsorted** range — undefined behavior.
- Using `nth_element` and expecting the rest of the array to be sorted — it's only guaranteed that the nth element is correctly placed.
- Forgetting `stable_sort` is needed when relative order of equal elements matters (`sort` does NOT guarantee this).
- Using `greater<int>()` but forgetting the include `<functional>` (usually fine via `<algorithm>` in practice, but good habit to know).

---

# SECTION 10: Custom Sorting (Comparators)

## Comparator Functions
A comparator returns `true` if the first argument should come **before** the second.

```cpp
bool cmpDesc(int a, int b) { return a > b; } // descending order
sort(v.begin(), v.end(), cmpDesc);
```

## Lambda Expressions
```cpp
sort(v.begin(), v.end(), [](int a, int b) { return a > b; }); // descending
```

## Sorting Structures / Objects
```cpp
struct Student { string name; int marks; };
vector<Student> students = {{"A",80},{"B",95},{"C",70}};

sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
    return a.marks > b.marks; // descending by marks
});
```

## Sorting Pairs
```cpp
vector<pair<int,int>> v = {{3,1},{1,2},{1,1}};
sort(v.begin(), v.end()); // sorts by first, then second by default (lexicographic)

// Custom: sort by second element ascending
sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.second < b.second; });
```

## Sorting 2D Arrays / Vectors of Vectors
```cpp
vector<vector<int>> intervals = {{1,3},{2,6},{8,10}};
sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
    return a[0] < b[0]; // sort intervals by start time
});
```

## Sorting Strings
```cpp
vector<string> words = {"banana","apple","cherry"};
sort(words.begin(), words.end()); // lexicographic ascending

// By length, then lexicographically
sort(words.begin(), words.end(), [](const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
});
```

## Multi-key Sorting
```cpp
// Sort by marks descending, then by name ascending for ties
sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
    if (a.marks != b.marks) return a.marks > b.marks;
    return a.name < b.name;
});
```

## Descending Order
```cpp
sort(v.rbegin(), v.rend());                       // reverse iterators
sort(v.begin(), v.end(), greater<int>());         // functional object
sort(v.begin(), v.end(), [](int a,int b){return a>b;}); // lambda
```

## Stable Comparators
When tie-breaking matters and order of equal elements from input must be preserved, use `stable_sort` instead of `sort` — a custom comparator alone does NOT guarantee stability for elements it considers equal.

```cpp
stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
    return a.marks > b.marks; // ties keep original relative order
});
```


---

# SECTION 11: Sorting Patterns

## Pattern 1: Direct Sorting
**Clue:** Problem just wants elements in order.
**Template:** `sort(v.begin(), v.end())`.
**Example:** Sort an array.

## Pattern 2: Sorting + Binary Search
**Clue:** "Find if X exists", "find smallest/largest satisfying condition" on sorted data.
**Template:**
```cpp
sort(v.begin(), v.end());
auto it = lower_bound(v.begin(), v.end(), target);
```
**Example:** Two Sum on sorted array, Search Insert Position.

## Pattern 3: Sorting + Two Pointers
**Clue:** "Pair/triplet sum", "closest pair", problems involving combinations of two elements.
**Template:**
```cpp
sort(v.begin(), v.end());
int l = 0, r = n - 1;
while (l < r) { /* move pointers based on sum vs target */ }
```
**Example:** 3Sum, Container With Most Water, Two Sum II.

## Pattern 4: Sorting + Greedy
**Clue:** "Maximize/minimize", "schedule", "select maximum non-overlapping."
**Template:** Sort by a key (end time, ratio, etc.), then greedily pick.
**Example:** Activity Selection, Fractional Knapsack, Job Sequencing.

## Pattern 5: Sorting + Hashing
**Clue:** "Group anagrams", "find duplicates with extra structure."
**Template:** Sort each element's internal representation (e.g., sort chars of a string) as a hash key.
**Example:** Group Anagrams.

## Pattern 6: Sorting + Sliding Window
**Clue:** "Smallest range covering elements from k lists", combined sorted streams.
**Example:** Smallest Range Covering Elements from K Lists.

## Pattern 7: Sorting Intervals
**Clue:** "Merge intervals", "overlapping meetings", "insert interval."
**Template:**
```cpp
sort(intervals.begin(), intervals.end()); // by start time
// then sweep and merge/compare with previous end
```
**Example:** Merge Intervals, Meeting Rooms, Insert Interval.

## Pattern 8: Coordinate Compression
**Clue:** Large value range but only relative order matters.
**Template:**
```cpp
vector<int> sorted = original;
sort(sorted.begin(), sorted.end());
sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
// map each original value to its index via lower_bound
```
**Example:** Count of Smaller Numbers After Self, range queries on large values.

## Pattern 9: Frequency Sorting
**Clue:** "Sort by frequency", "top K frequent."
**Template:** Count frequencies (hashmap), then sort by frequency (or use a heap for top-K).
**Example:** Top K Frequent Elements, Sort Characters By Frequency.

## Pattern 10: Custom Comparator
**Clue:** Sorting order isn't the default — needs domain-specific rule (e.g., "largest number formed by concatenation").
**Template:**
```cpp
sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
    return a + b > b + a; // for largest number formed by concatenation
});
```
**Example:** Largest Number, Custom Sort String.

## Pattern 11: K-Sorted Arrays (Nearly Sorted with bounded displacement)
**Clue:** "Each element at most k away from its sorted position."
**Template:** Use a min-heap of size k+1; the smallest of these k+1 elements is always the next sorted output.
**Example:** Sort a k-sorted (nearly sorted) array.

## Pattern 12: Nearly Sorted Arrays
**Clue:** Input already has a lot of order; adaptive sorts shine.
**Template:** Insertion Sort or TimSort-style run-detection.

## Pattern 13: Partial Sorting
**Clue:** "Find top K", "Kth largest/smallest" — full sort is wasteful.
**Template:** `nth_element`, `partial_sort`, or a heap of size K.
**Example:** Kth Largest Element in an Array.

## Pattern 14: Order Statistics
**Clue:** "Median", "Kth smallest", "percentile."
**Template:** Quickselect (`nth_element`) for O(n) average; two heaps for streaming median.
**Example:** Median of Data Stream, Kth Smallest Element in a Sorted Matrix.

---

# SECTION 12: Important Sorting Applications

## Remove Duplicates (from sorted array)
```cpp
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int k = 1;
    for (int i = 1; i < nums.size(); i++)
        if (nums[i] != nums[k-1]) nums[k++] = nums[i];
    return k;
}
```

## Merge Intervals
```cpp
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    for (auto& interval : intervals) {
        if (result.empty() || result.back()[1] < interval[0])
            result.push_back(interval);
        else
            result.back()[1] = max(result.back()[1], interval[1]);
    }
    return result;
}
```
**Dry run on [[1,3],[2,6],[8,10],[15,18]]:** sorted already by start. [1,3] starts result. [2,6] overlaps (2<=3) -> merge to [1,6]. [8,10] doesn't overlap -> push. [15,18] doesn't overlap -> push. Result: [[1,6],[8,10],[15,18]].

## Meeting Rooms (can attend all meetings?)
```cpp
bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    for (int i = 1; i < intervals.size(); i++)
        if (intervals[i][0] < intervals[i-1][1]) return false;
    return true;
}
```

## Activity Selection (max non-overlapping activities)
```cpp
int activitySelection(vector<vector<int>>& activities) {
    sort(activities.begin(), activities.end(), [](auto& a, auto& b){ return a[1] < b[1]; }); // by end time
    int count = 1, lastEnd = activities[0][1];
    for (int i = 1; i < activities.size(); i++) {
        if (activities[i][0] >= lastEnd) { count++; lastEnd = activities[i][1]; }
    }
    return count;
}
```

## Minimum Platforms (railway scheduling)
```cpp
int minPlatforms(vector<int> arr, vector<int> dep) {
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int i = 1, j = 0, platforms = 1, maxPlatforms = 1;
    while (i < arr.size() && j < dep.size()) {
        if (arr[i] <= dep[j]) { platforms++; i++; }
        else { platforms--; j++; }
        maxPlatforms = max(maxPlatforms, platforms);
    }
    return maxPlatforms;
}
```

## K Closest Elements
```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int lo = 0, hi = arr.size() - k;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (x - arr[mid] > arr[mid + k] - x) lo = mid + 1;
        else hi = mid;
    }
    return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
}
```

## Kth Largest Element (Quickselect)
```cpp
int findKthLargest(vector<int>& nums, int k) {
    nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
    return nums[k - 1];
}
```

## Top K Frequent Elements
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;
    vector<pair<int,int>> v(freq.begin(), freq.end());
    nth_element(v.begin(), v.begin() + k - 1, v.end(), [](auto& a, auto& b){ return a.second > b.second; });
    vector<int> result;
    for (int i = 0; i < k; i++) result.push_back(v[i].first);
    return result;
}
```

## Sort Colors (Dutch National Flag)
```cpp
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1) mid++;
        else swap(nums[mid], nums[high--]);
    }
}
```
**Dry run on [2,0,2,1,1,0]:** low=0,mid=0,high=5.
nums[mid]=2 -> swap(mid,high) -> [0,0,2,1,1,2], high=4 (mid stays 0)
nums[mid]=0 -> swap(low,mid), low=1,mid=1 -> [0,0,2,1,1,2]
nums[mid]=0 -> swap(low,mid), low=2,mid=2 -> [0,0,2,1,1,2]
nums[mid]=2 -> swap(mid,high) -> [0,0,1,1,2,2], high=3
nums[mid]=1 -> mid=3
nums[mid]=1 -> mid=4 > high(3) -> stop
Final: [0,0,1,1,2,2]

## Relative Sort Array
```cpp
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int,int> rank;
    for (int i = 0; i < arr2.size(); i++) rank[arr2[i]] = i;
    sort(arr1.begin(), arr1.end(), [&](int a, int b) {
        if (rank.count(a) && rank.count(b)) return rank[a] < rank[b];
        if (rank.count(a)) return true;
        if (rank.count(b)) return false;
        return a < b;
    });
    return arr1;
}
```

## Wiggle Sort
```cpp
void wiggleSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> result(nums.size());
    int n = nums.size(), j = (n + 1) / 2 - 1, k = n - 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) result[i] = nums[j--];
        else result[i] = nums[k--];
    }
    nums = result;
}
```


---

# SECTION 13: Special Sorting Topics

## Stable vs Unstable Sorting
Already covered in Section 1 — recap: stable sorts preserve relative order of equal-key elements; required for multi-pass/multi-key sorting (e.g., Radix Sort's correctness depends on stability).

## In-place vs Out-of-place
In-place sorts use O(1) extra memory (Quick, Heap, Insertion, Selection, Bubble); out-of-place sorts need O(n) extra (Merge, Counting, Radix, Bucket).

## Adaptive vs Non-adaptive
Adaptive sorts run faster on partially sorted input (Insertion, Bubble with early exit, TimSort); non-adaptive sorts run the same regardless of input order (Selection, Heap, standard Merge/Quick).

## Online vs Offline Sorting
- **Online sorting:** Can sort data as it arrives, without having the full dataset upfront (e.g., Insertion Sort into a sorted structure, or a balanced BST).
- **Offline sorting:** Requires the entire dataset before sorting begins (most algorithms — Quick Sort, Merge Sort).

## External Sorting
Used when data doesn't fit in RAM. Typically performed as **External Merge Sort**:
```
1. Split huge file into chunks that fit in memory.
2. Sort each chunk in memory (using e.g. Quick Sort) and write back to disk as a "run."
3. Merge sorted runs using a k-way merge (often with a min-heap) into the final sorted file.
```

## Multi-level Sorting
Sorting by multiple keys in priority order (e.g., sort employees by department, then by salary within department) — achieved via multi-key comparators or successive stable sorts (sort by least significant key first, most significant key last).

## Parallel Sorting
Divide-and-conquer sorts (Merge Sort, Quick Sort) parallelize naturally — independent sub-arrays can be sorted on different threads/cores, then merged. Bucket Sort also parallelizes well since buckets are independent.

## Cache-Friendly Sorting
Quick Sort tends to be more cache-friendly than Merge Sort or Heap Sort because it works in-place on contiguous memory with good locality, whereas Heap Sort jumps around the array via heap indices, hurting cache performance despite the same Big-O.

---

# SECTION 14: Interview Decision Framework

## Decision Tree

```
                         What are you sorting?
                                |
        ---------------------------------------------------
        |                      |                          |
   Small dataset         Need stability?              Known small
   (n < ~20)                   |                       integer range?
        |                yes-> Merge Sort / TimSort           |
   Insertion Sort               |                       yes-> Counting Sort
        |                no -> Quick Sort / IntroSort          |
        |                                              Fixed-length integers?
   Nearly sorted?                                              |
        |                                              yes-> Radix Sort
   yes-> Insertion Sort / TimSort
        |
   General purpose, no                              Need Top-K only?
   special constraints                                       |
        |                                              yes-> Heap (size K) /
   Quick Sort / IntroSort                                   nth_element / partial_sort
                                                              |
                                                   K-sorted (bounded displacement)?
                                                              |
                                                   yes-> Min-Heap of size k+1
                                                              |
                                                   Custom objects/multi-key?
                                                              |
                                                   yes-> Custom Comparator + stable_sort
```

## Quick Reference Table

| Situation | Recommended Algorithm |
|---|---|
| Small dataset (< ~20 elements) | Insertion Sort |
| Nearly sorted data | Insertion Sort / TimSort |
| General purpose, no constraints | Quick Sort / IntroSort (`std::sort`) |
| Stability required | Merge Sort / TimSort (`stable_sort`) |
| Small integer range | Counting Sort |
| Fixed-length integers/strings | Radix Sort |
| Need only Top-K elements | Heap / `partial_sort` / `nth_element` |
| K-sorted (nearly sorted, bounded) array | Min-Heap of size k+1 |
| Custom objects, multiple sort keys | Custom Comparator + `stable_sort` |
| Memory-constrained embedded system | Shell Sort / Heap Sort (O(1) space) |
| External (disk-based) huge dataset | External Merge Sort |
| Linked list | Merge Sort |
| Minimizing writes (expensive memory) | Cycle Sort / Selection Sort |

---

# SECTION 15: Common Tricks

## Comparator Tricks
```cpp
// Sort descending using negative trick (only for numeric types)
sort(v.begin(), v.end(), [](int a, int b){ return a > b; });

// Sort by absolute value
sort(v.begin(), v.end(), [](int a, int b){ return abs(a) < abs(b); });
```

## Pair Sorting Tricks
```cpp
// Sort pairs by second element, then first element
sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int,int>& b) {
    return a.second != b.second ? a.second < b.second : a.first < b.first;
});
```

## Interval Sorting Tricks
```cpp
// Sort intervals by end time for greedy activity selection
sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){ return a[1] < b[1]; });
```

## Stable Sorting Tricks
```cpp
// Achieve multi-key sort using successive stable sorts (least significant key first)
stable_sort(v.begin(), v.end(), byKey2);
stable_sort(v.begin(), v.end(), byKey1); // final order: primarily key1, secondarily key2
```

## Partial Sorting Tricks
```cpp
// Get top 3 elements without full sort
partial_sort(v.begin(), v.begin() + 3, v.end(), greater<int>());
```

## Coordinate Compression Tricks
```cpp
vector<int> comp = arr;
sort(comp.begin(), comp.end());
comp.erase(unique(comp.begin(), comp.end()), comp.end());
int compressedIndex = lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin();
```

## nth_element Tricks
```cpp
// Find median in O(n) average
nth_element(v.begin(), v.begin() + v.size()/2, v.end());
int median = v[v.size()/2];
```

---

# SECTION 16: Common Mistakes

| Mistake | Why It's a Problem | Fix |
|---|---|---|
| Wrong comparator (returns true for equal elements) | Causes undefined behavior / crashes in `std::sort` | Comparator must define strict weak ordering: `cmp(a,a)` must be false |
| Integer overflow in comparator (`a - b`) | Wraps around for large values, gives wrong order | Use explicit comparisons (`a < b`) instead of subtraction |
| Assuming `sort()` is stable | `std::sort` does NOT guarantee stability | Use `stable_sort()` when order of equal elements matters |
| Incorrect partition logic in Quick Sort | Infinite recursion or wrong results | Carefully verify pivot placement and recursive call boundaries |
| Infinite recursion in Quick Sort (Hoare) | Using wrong recursive call bounds (`p-1, p+1` instead of `low,p` / `p+1,high`) | For Hoare partition, recurse on `(low, p)` and `(p+1, high)` |
| Merge index errors | Off-by-one in merge loop bounds | Carefully bound `mid`, `mid+1`, and `r`; use `<=` consistently |
| Counting Sort range errors | Not offsetting by `min`, or wrong array size | Always compute `range = max - min + 1` and offset indices by `min` |


---

# SECTION 17: Curated Practice Question List

*A focused, high-signal list organized by difficulty and pattern (prefer LeetCode unless noted). This is a curated core set rather than an exhaustive 200-question list, chosen to cover every pattern in Section 11.*

## Easy

| Problem | Platform | Pattern | Key Idea |
|---|---|---|---|
| Sort an Array | LeetCode | Direct Sorting | Implement/use any O(n log n) sort |
| Merge Sorted Array | LeetCode | Two Pointers | Merge from the back to avoid overwrite |
| Squares of a Sorted Array | LeetCode | Two Pointers | Compare absolute values from both ends |
| Sort Colors | LeetCode | Direct Sorting / 3-way partition | Dutch National Flag, one pass |
| Two Sum II (sorted input) | LeetCode | Two Pointers | Move pointers based on sum vs target |
| Relative Sort Array | LeetCode | Custom Comparator | Rank map + custom comparator |
| Height Checker | LeetCode | Direct Sorting | Compare with sorted copy |
| Valid Anagram | LeetCode | Sorting + Hashing | Sort both strings and compare |
| Third Maximum Number | LeetCode | Direct Sorting | Track top-3 distinct values |
| Maximum Product of Three Numbers | LeetCode | Direct Sorting | Sort, consider two cases (all positive / two negatives) |

## Medium

| Problem | Platform | Pattern | Key Idea |
|---|---|---|---|
| Merge Intervals | LeetCode | Sorting Intervals | Sort by start, merge overlapping |
| Insert Interval | LeetCode | Sorting Intervals | Linear scan with insertion logic |
| Non-overlapping Intervals | LeetCode | Sorting + Greedy | Sort by end time, count removals |
| Meeting Rooms II | LeetCode | Sorting Intervals / Heap | Sort starts/ends, sweep with min-heap |
| 3Sum | LeetCode | Sorting + Two Pointers | Sort, fix one element, two-pointer the rest |
| 3Sum Closest | LeetCode | Sorting + Two Pointers | Track closest sum while sweeping |
| Sort Characters By Frequency | LeetCode | Frequency Sorting | Count frequency, sort by count descending |
| Top K Frequent Elements | LeetCode | Frequency Sorting / Heap | Bucket sort by frequency, or heap |
| Kth Largest Element in an Array | LeetCode | Order Statistics | Quickselect / `nth_element` / heap |
| Largest Number | LeetCode | Custom Comparator | Compare `a+b` vs `b+a` as strings |
| Group Anagrams | LeetCode | Sorting + Hashing | Sort chars of each string as hash key |
| Sort List (Linked List) | LeetCode | Merge Sort | Merge Sort adapted for linked lists |
| Wiggle Sort II | LeetCode | Direct Sorting | Sort then interleave from middle/end |
| Find K Closest Elements | LeetCode | Binary Search + Two Pointers | Binary search on window start |
| Minimum Number of Arrows to Burst Balloons | LeetCode | Sorting Intervals + Greedy | Sort by end coordinate |
| Pancake Sorting | LeetCode | Pancake Sort | Flip largest unsorted element into place |
| Custom Sort String | LeetCode | Custom Comparator | Map order, custom comparator |
| Sort Array By Parity | LeetCode | Two Pointers / Partition | Partition even/odd like Dutch flag |
| Maximum Gap | LeetCode | Bucket Sort | Bucket by range to find max gap in O(n) |
| Car Pooling | LeetCode | Sorting + Sweep | Sort pickup/dropoff events |

## Hard

| Problem | Platform | Pattern | Key Idea |
|---|---|---|---|
| Count of Smaller Numbers After Self | LeetCode | Merge Sort + Coordinate Compression | Count inversions during merge step |
| Reverse Pairs | LeetCode | Merge Sort | Count cross pairs during merge before merging |
| Median of Two Sorted Arrays | LeetCode | Binary Search (Order Statistics) | Partition-based binary search, not full merge |
| Smallest Range Covering Elements from K Lists | LeetCode | Heap + Sliding Window | Min-heap across k pointers |
| Merge k Sorted Lists | LeetCode | Heap / Divide and Conquer Merge | Min-heap of size k, or pairwise merge |
| Sliding Window Median | LeetCode | Order Statistics / Two Heaps | Two balanced heaps (or multiset) |
| Count of Range Sum | LeetCode | Merge Sort + Coordinate Compression | Count valid prefix-sum pairs during merge |
| Maximum Number of Events That Can Be Attended | LeetCode | Sorting + Greedy + Heap | Sort by start, min-heap of end times |
| Find Median from Data Stream | LeetCode | Order Statistics / Two Heaps | Max-heap (lower half) + min-heap (upper half) |
| Russian Doll Envelopes | LeetCode | Sorting + Binary Search (LIS) | Sort by width asc, height desc; LIS on heights |

---

# SECTION 18: Master Comparison Table

| Algorithm | Best | Average | Worst | Space | Stable | In-place | Adaptive | Comparison-based |
|---|---|---|---|---|---|---|---|---|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes | Yes | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No | Yes | No | Yes |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes | Yes | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes | No | No | Yes |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No | Yes | No | Yes |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No | Yes | No | Yes |
| Counting Sort | O(n+k) | O(n+k) | O(n+k) | O(n+k) | Yes | No | No | No |
| Radix Sort | O(d(n+k)) | O(d(n+k)) | O(d(n+k)) | O(n+k) | Yes | No | No | No |
| Bucket Sort | O(n+k) | O(n+k) | O(n²) | O(n+k) | Yes | No | No | No |
| Shell Sort | O(n log n) | O(n^1.3ish) | O(n²) | O(1) | No | Yes | Yes | Yes |
| TimSort | O(n) | O(n log n) | O(n log n) | O(n) | Yes | No | Yes | Yes |
| IntroSort | O(n log n) | O(n log n) | O(n log n) | O(log n) | No | Yes | No | Yes |
| Tree Sort | O(n log n) | O(n log n) | O(n²) | O(n) | Depends | No | No | Yes |
| Cocktail Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes | Yes | Yes |
| Comb Sort | O(n log n) | O(n²/2^p) | O(n²) | O(1) | No | Yes | No | Yes |
| Gnome Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes | Yes | Yes |
| Pancake Sort | O(n) | O(n²) | O(n²) | O(1) | No | Yes | No | Yes |
| Cycle Sort | O(n²) | O(n²) | O(n²) | O(1) | No | Yes | No | Yes |

**Best Use Case Quick Reference:**

| Algorithm | Best Use Case |
|---|---|
| Bubble / Gnome / Cocktail | Teaching, tiny/near-sorted arrays |
| Selection Sort | Minimizing swaps, small arrays |
| Insertion Sort | Small or nearly sorted data, online sorting |
| Merge Sort | Linked lists, stability needed, external sorting |
| Quick Sort | General-purpose, in-memory arrays |
| Heap Sort | O(1) space + guaranteed O(n log n), priority queues |
| Counting Sort | Small known integer range |
| Radix Sort | Fixed-length integers/strings |
| Bucket Sort | Uniformly distributed floating data |
| Shell Sort | Memory-constrained systems, no recursion |
| TimSort | Real-world data with runs (Python/Java default) |
| IntroSort | Production general sort (C++ `std::sort`) |
| Cycle Sort | Minimizing writes (flash memory) |


---

# SECTION 19: Revision Cheat Sheet

## Sorting Cheat Sheet (One-Liners)
- **Bubble:** repeatedly swap adjacent out-of-order pairs.
- **Selection:** repeatedly pick the minimum and place it at the front.
- **Insertion:** repeatedly insert the next element into its correct sorted position.
- **Merge:** divide into halves, sort each, merge sorted halves.
- **Quick:** pick a pivot, partition around it, recurse on both sides.
- **Heap:** build a max-heap, repeatedly extract the max to the end.
- **Counting:** count occurrences, use prefix sums to place directly.
- **Radix:** stable sort digit by digit, least significant first.
- **Bucket:** distribute into ranged buckets, sort each, concatenate.

## Complexity Cheat Sheet

```
O(n²) family   : Bubble, Selection, Insertion, Cycle, Gnome, Pancake
O(n log n)     : Merge, Quick (avg), Heap, TimSort, IntroSort, Shell (good gap seq)
O(n + k)       : Counting, Bucket (uniform data)
O(d(n + k))    : Radix
```

## Stability Cheat Sheet

```
STABLE   : Bubble, Insertion, Merge, Counting, Radix, Bucket, TimSort, Cocktail, Gnome
UNSTABLE : Selection, Quick, Heap, Shell, IntroSort, Comb, Pancake, Cycle
```

## STL Sorting Cheat Sheet

```cpp
sort(v.begin(), v.end());                      // IntroSort, unstable, O(n log n)
stable_sort(v.begin(), v.end());                // stable, O(n log n)
partial_sort(v.begin(), v.begin()+k, v.end());  // top-k sorted, O(n log k)
nth_element(v.begin(), v.begin()+k, v.end());   // kth element placed, O(n) avg
binary_search(v.begin(), v.end(), x);           // requires sorted range
lower_bound(v.begin(), v.end(), x);             // first >= x
upper_bound(v.begin(), v.end(), x);             // first > x
```

## Comparator Cheat Sheet

```cpp
// Ascending (default)
sort(v.begin(), v.end());
// Descending
sort(v.begin(), v.end(), greater<int>());
// Custom lambda
sort(v.begin(), v.end(), [](auto&a, auto&b){ return a.key < b.key; });
// Multi-key
sort(v.begin(), v.end(), [](auto&a, auto&b){
    if (a.k1 != b.k1) return a.k1 < b.k1;
    return a.k2 < b.k2;
});
```

## Quick Sort Template
```cpp
void quickSort(vector<int>& a, int low, int high) {
    if (low >= high) return;
    int pivot = a[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (a[j] <= pivot) swap(a[++i], a[j]);
    swap(a[i+1], a[high]);
    quickSort(a, low, i);
    quickSort(a, i+2, high);
}
```

## Merge Sort Template
```cpp
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int mid = l + (r-l)/2;
    mergeSort(a, l, mid);
    mergeSort(a, mid+1, r);
    vector<int> tmp;
    int i = l, j = mid+1;
    while (i <= mid && j <= r) tmp.push_back(a[i] <= a[j] ? a[i++] : a[j++]);
    while (i <= mid) tmp.push_back(a[i++]);
    while (j <= r) tmp.push_back(a[j++]);
    copy(tmp.begin(), tmp.end(), a.begin()+l);
}
```

## Heap Sort Template
```cpp
void heapify(vector<int>& a, int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) { swap(a[i], a[largest]); heapify(a, n, largest); }
}
void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n/2-1; i >= 0; i--) heapify(a, n, i);
    for (int i = n-1; i > 0; i--) { swap(a[0], a[i]); heapify(a, i, 0); }
}
```

## Counting Sort Template
```cpp
void countingSort(vector<int>& a, int maxVal) {
    vector<int> count(maxVal+1, 0), output(a.size());
    for (int x : a) count[x]++;
    for (int i = 1; i <= maxVal; i++) count[i] += count[i-1];
    for (int i = a.size()-1; i >= 0; i--) output[--count[a[i]]] = a[i];
    a = output;
}
```

---

# SECTION 20: Final Sorting Roadmap

## Beginner → Intermediate → Advanced

```
BEGINNER
  |- Understand swapping, comparing, stability, in-place concepts
  |- Master Bubble, Selection, Insertion Sort (with full dry runs by hand)
  |- Understand Big-O for best/average/worst case
        |
INTERMEDIATE
  |- Master Merge Sort and Quick Sort (Lomuto + Hoare partitions)
  |- Master Heap Sort (and heaps in general for priority queues)
  |- Learn Counting Sort, Radix Sort, Bucket Sort
  |- Learn STL: sort, stable_sort, partial_sort, nth_element, binary_search family
  |- Practice custom comparators (pairs, structs, multi-key)
        |
ADVANCED
  |- Learn Shell Sort, TimSort, IntroSort conceptually (how/why hybrids exist)
  |- Master sorting-based patterns: intervals, two pointers, frequency, greedy
  |- Solve order-statistics problems (Quickselect, two heaps for median)
  |- Solve advanced merge-sort-based counting problems (inversions, reverse pairs)
  |- Practice full Hard-tier problems under time pressure (mock OA/interview)
```

## What to Study First
1. Stability, in-place, adaptive concepts (Section 1–3).
2. Bubble, Selection, Insertion Sort with hand dry runs.
3. Merge Sort and Quick Sort deeply (most asked in interviews).

## What to Practice Next
1. Heap Sort + heap-based problems (Kth largest, Top-K frequent).
2. Counting/Radix/Bucket Sort for non-comparison-based thinking.
3. STL sorting functions and custom comparators.

## Suggested Weekly Learning Plan (4 Weeks)

| Week | Focus |
|---|---|
| 1 | Section 1–4: Concepts + Bubble, Selection, Insertion Sort (with dry runs) |
| 2 | Section 5–6: Merge Sort, Quick Sort, Heap Sort (deep dive + Easy/Medium problems) |
| 3 | Section 7–10: Counting/Radix/Bucket Sort, STL, Custom Comparators |
| 4 | Section 11–18: Patterns, Applications, Interview Framework, Hard problems, Mock OA |

## Suggested Weekly Revision Plan (Before Interviews)

| Day | Focus |
|---|---|
| Day 1 | Re-derive Bubble/Selection/Insertion from memory, no notes |
| Day 2 | Re-derive Merge Sort and Quick Sort (both partition schemes) from memory |
| Day 3 | Re-derive Heap Sort + solve 3 heap-based problems |
| Day 4 | Re-derive Counting/Radix Sort + solve 2 non-comparison problems |
| Day 5 | Drill STL sorting functions + comparators |
| Day 6 | Solve 5 mixed pattern problems (intervals, two pointers, greedy, frequency) |
| Day 7 | Timed mock test: 2 Easy + 2 Medium + 1 Hard sorting problem |

## Recommended Problems for Final Practice
Merge Intervals, 3Sum, Kth Largest Element, Top K Frequent Elements, Sort Colors, Largest Number, Count of Smaller Numbers After Self, Merge k Sorted Lists, Find Median from Data Stream.

## Common Interview Questions Recap
- "Implement Quick Sort and explain its worst case."
- "Why is Merge Sort preferred for linked lists?"
- "When would you use Counting Sort over a comparison sort?"
- "What does `std::sort` use internally, and why?"
- "How do you find the Kth largest element efficiently?"
- "Explain stability and give an example where it matters."

## Competitive Programming Tips
- Default to `sort()` / `stable_sort()` — don't hand-roll sorting algorithms in contests unless the problem demands a specific non-comparison technique (Counting/Radix Sort for performance, or a custom merge-based inversion count).
- Use `nth_element` for fast order-statistics instead of full sorts when only a single rank is needed.
- Watch for integer overflow in custom comparators — never use subtraction (`a - b`) to compare; use explicit `<`/`>`.
- For coordinate compression problems, `sort` + `unique` + `lower_bound` is a near-universal combo.
- Remember Merge Sort's inversion-counting trick — a very common "hard" competitive programming technique.

---

