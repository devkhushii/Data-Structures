# 📘 The Ultimate Array & Vector Handbook
### From Zero to Interview-Ready — Arrays, Vectors & Matrices

---

## How to Use This Handbook
- **First-time learners**: Read Sections 1–6 in order.
- **Interview prep**: Jump to Sections 7–11 (Patterns + Algorithms + Framework).
- **Last-minute revision**: Go straight to Section 14 (Cheat Sheets).
- **OA / CP practice**: Use Section 13 (Question Bank) + Section 7 (Patterns).

---

# SECTION 1: ARRAY FUNDAMENTALS

## 1.1 What is an Array?
**Definition**: An array is a linear, fixed-size (in its classic form) collection of elements of the **same data type**, stored in **contiguous memory locations**, accessed using an index.

**Intuition**: Think of an array as a row of numbered lockers in a corridor. Every locker is the same size, lockers are right next to each other, and you can walk directly to locker #7 without opening lockers #1–#6.

```
Index:   0     1     2     3     4
       +-----+-----+-----+-----+-----+
Value: | 10  | 20  | 30  | 40  | 50  |
       +-----+-----+-----+-----+-----+
Addr: 100   104   108   112   116   (assuming int = 4 bytes)
```

## 1.2 Why Arrays Exist
- Need a way to store **multiple values of the same type** under one name instead of declaring `a, b, c, d...`
- Need **O(1) random access** by position.
- Foundation for almost every other data structure (stacks, queues, hash tables, heaps, strings).

## 1.3 Real World Examples
| Real World | Array Analogy |
|---|---|
| Train coaches | Indexed compartments |
| Calendar days in a month | Indexed by day number |
| Pixels in an image | 2D array (matrix) |
| Spreadsheet | 2D array |
| Playlist | 1D array of songs |

## 1.4 Characteristics of Arrays
- Fixed size (static arrays) — size decided at compile/declaration time.
- Homogeneous — all elements same type.
- Contiguous memory.
- Indexed access — O(1).
- Elements stored in **sequence**, preserving insertion order positionally.

## 1.5 Static vs Dynamic Arrays
| Feature | Static Array | Dynamic Array |
|---|---|---|
| Size | Fixed at creation | Grows/shrinks at runtime |
| Memory | Stack or fixed heap block | Heap, reallocated as needed |
| Examples | `int arr[5]` (C++), Java arrays | `vector<int>` (C++), `ArrayList` (Java), Python `list` |
| Resize cost | Not possible | Amortized O(1) per insert |

## 1.6 Continuous (Contiguous) Memory Allocation
All elements are placed back-to-back in memory. This is **why** indexing is O(1) — the address of any element can be computed directly without traversal.

## 1.7 Indexing

### 0-Based Indexing
Used in C, C++, Java, Python, JavaScript. First element is at index `0`.

### 1-Based Indexing
Used in some math/CP contexts, Fortran, MATLAB, R. First element is at index `1`.

**Interview Note**: Always clarify which indexing the problem uses. Off-by-one bugs are the #1 cause of wrong answers in array problems.

## 1.8 Address Calculation Formula
For a 1D array:
```
Address(arr[i]) = BaseAddress + i * size_of(element_type)
```

For a 2D array `arr[rows][cols]` (Row-Major order, used by C/C++/Java):
```
Address(arr[i][j]) = BaseAddress + (i * cols + j) * size_of(element_type)
```

For Column-Major order (used by Fortran):
```
Address(arr[i][j]) = BaseAddress + (j * rows + i) * size_of(element_type)
```

**Dry Run**: `arr[3]` in `int arr[10]` with base address 1000:
```
Address = 1000 + 3 * 4 = 1012
```

## 1.9 Advantages
- O(1) random access.
- Cache-friendly (contiguous memory → fewer cache misses).
- Simple and memory-efficient (no extra pointers like linked lists).
- Easy to traverse, sort, and binary search.

## 1.10 Disadvantages
- Fixed size (static arrays) — wastage or overflow risk.
- Insertion/deletion in the middle is O(n) (requires shifting).
- Resizing dynamic arrays involves costly reallocation+copy.
- Homogeneous only — can't natively mix types.

## 1.11 Applications
- Implementing matrices, strings, stacks, queues, hash tables (buckets).
- Lookup tables, frequency counters, DP tables (1D/2D).
- Image processing, sorting/searching algorithms.

---

# SECTION 2: VECTOR COMPLETE GUIDE (C++ STL)

## 2.1 What is a Vector?
**Definition**: `std::vector` is a dynamic array provided by the C++ Standard Template Library. It automatically resizes itself when elements are added or removed beyond its current capacity.

## 2.2 Why Vector?
- Avoids manual memory management (`new[]`/`delete[]`).
- Grows automatically — no fixed size limitation.
- Provides rich built-in functions (sort, search via algorithms, etc.)

## 2.3 Internal Working & Dynamic Resizing
A vector maintains:
- `size` — number of elements currently stored.
- `capacity` — number of elements it can hold before reallocating.

When `size == capacity` and a new element is pushed:
1. A **new, larger memory block** is allocated (commonly **2x** capacity, implementation-defined — could be 1.5x in some STL implementations like MSVC).
2. All existing elements are **copied/moved** to the new block.
3. The old block is freed.
4. The new element is inserted.

```
Capacity growth (typical, doubling strategy):
1 → 2 → 4 → 8 → 16 → 32 ...
```

This is why vector push_back is **amortized O(1)**, not strictly O(1).

### Visual: Reallocation
```
size=4, capacity=4 → push_back(x)
[10][20][30][40]  (old block, capacity 4, FULL)
        |
        v  reallocate to capacity 8
[10][20][30][40][ x][ ][ ][ ]   (new block)
old block freed
```

## 2.4 Declarations
```cpp
vector<int> v1;                  // empty vector
vector<int> v2(5);                // size 5, all zero-initialized
vector<int> v3(5, 100);           // size 5, all initialized to 100
vector<int> v4 = {1, 2, 3, 4};    // initializer list
vector<int> v5(v4);                // copy constructor
vector<vector<int>> mat(3, vector<int>(4, 0)); // 3x4 matrix of 0s
```

## 2.5 Vector Functions — Complete Reference

| Function | Syntax | Complexity | Description |
|---|---|---|---|
| `push_back` | `v.push_back(x)` | Amortized O(1), worst O(n) | Adds element at end |
| `emplace_back` | `v.emplace_back(args)` | Amortized O(1) | Constructs in-place at end (avoids extra copy) |
| `pop_back` | `v.pop_back()` | O(1) | Removes last element |
| `size` | `v.size()` | O(1) | Number of elements |
| `capacity` | `v.capacity()` | O(1) | Current allocated capacity |
| `reserve` | `v.reserve(n)` | O(n) once | Pre-allocates capacity to avoid repeated reallocation |
| `resize` | `v.resize(n)` / `v.resize(n, val)` | O(n) | Changes size; new elements default/val initialized |
| `shrink_to_fit` | `v.shrink_to_fit()` | O(n) | Requests capacity reduction to match size |
| `clear` | `v.clear()` | O(n) | Removes all elements, size becomes 0 (capacity unchanged) |
| `empty` | `v.empty()` | O(1) | Returns true if size == 0 |
| `front` | `v.front()` | O(1) | Reference to first element |
| `back` | `v.back()` | O(1) | Reference to last element |
| `data` | `v.data()` | O(1) | Raw pointer to underlying array |
| `at` | `v.at(i)` | O(1) | Bounds-checked access (throws exception) |
| `insert` | `v.insert(pos, val)` | O(n) | Inserts before iterator pos |
| `erase` | `v.erase(pos)` | O(n) | Removes element at iterator pos |
| `assign` | `v.assign(n, val)` | O(n) | Replaces contents |
| `swap` | `v.swap(v2)` | O(1) | Swaps contents of two vectors |

### Example + Dry Run: `reserve` vs `push_back` without reserve
```cpp
vector<int> v;
v.reserve(5);     // capacity = 5 immediately, no reallocation needed below
for (int i = 0; i < 5; i++) v.push_back(i); // no reallocations happen!
```
Without `reserve`, the same loop could trigger ~3 reallocations (1→2→4→8).

### `insert` / `erase` Dry Run
```cpp
vector<int> v = {1,2,3,5};
v.insert(v.begin()+3, 4);  // → {1,2,3,4,5}, shifts "5" right
v.erase(v.begin()+1);      // → {1,3,4,5}, shifts left to fill gap
```

**Common Mistake**: Using `v[i]` with out-of-bounds `i` is **undefined behavior** (no crash guarantee). Use `.at(i)` when you want safety with an exception.

**Interview Note**: Always mention "amortized O(1)" for push_back, not just "O(1)" — interviewers look for this nuance.

---

# SECTION 3: MEMORY MODEL

## 3.1 Stack vs Heap Memory
| | Stack | Heap |
|---|---|---|
| Allocation | Automatic, fast | Manual/dynamic, slower |
| Lifetime | Until scope ends | Until freed/deleted |
| Size | Small, limited | Large, flexible |
| Example | `int arr[10];` (local) | `new int[n];`, `vector<int>` internal buffer |

## 3.2 Array Memory Layout
A static local array lives on the **stack** (if declared inside a function) — contiguous block, fixed size, destroyed automatically when function returns.

## 3.3 Vector Memory Layout
A `vector` object itself (the small struct holding pointer, size, capacity) typically lives on the stack, but its **underlying data buffer** lives on the **heap**.

```
Stack:                  Heap:
+----------------+      +----+----+----+----+
| ptr  | size=3  | ---> | 10 | 20 | 30 |    |
| cap=4          |      +----+----+----+----+
+----------------+
```

## 3.4 Pointer Arithmetic
Since arrays are contiguous, `*(arr + i)` is equivalent to `arr[i]`. This works because the compiler computes `BaseAddress + i*sizeof(type)`.

## 3.5 Cache Locality
Because array elements are contiguous, accessing `arr[i]` often pulls `arr[i+1], arr[i+2]...` into the CPU cache too (cache lines are typically 64 bytes). This makes **sequential traversal** of arrays much faster in practice than traversing linked structures, even though both can be "O(n)".

## 3.6 Memory Optimization Tips
- Use `reserve()` when final size is known/estimated to avoid repeated reallocations.
- Avoid `vector<bool>` for performance-critical bit manipulation (it's a specialized bit-packed type with quirks) — prefer `bitset` or raw bit tricks.
- Pass vectors by `const reference` (`const vector<int>&`) to avoid copying.

---

# SECTION 4: COMPLEXITY ANALYSIS

## 4.1 Definitions
- **Time Complexity**: How runtime scales with input size `n`.
- **Space Complexity**: How extra memory scales with `n`.
- **Best Case**: Fastest scenario (e.g., element found at index 0).
- **Average Case**: Expected behavior over typical/random inputs.
- **Worst Case**: Slowest possible scenario — what we usually optimize for.
- **Amortized Analysis**: Average cost per operation over a sequence of operations, even if individual operations vary (used for vector push_back).

## 4.2 Complete Array/Vector Operation Complexity Table

| Operation | Array | Vector (push/pop at end) | Vector (middle) |
|---|---|---|---|
| Access by index | O(1) | O(1) | O(1) |
| Search (unsorted) | O(n) | O(n) | O(n) |
| Search (sorted, binary search) | O(log n) | O(log n) | O(log n) |
| Insert at end | O(1) (if space) | Amortized O(1) | — |
| Insert at beginning/middle | O(n) | O(n) | O(n) |
| Delete at end | O(1) | O(1) | — |
| Delete at beginning/middle | O(n) | O(n) | O(n) |
| Traversal | O(n) | O(n) | O(n) |

**Space Complexity**: O(n) to store n elements; O(1) extra for in-place algorithms, O(n) extra if a copy/auxiliary array is used.

---

# SECTION 5: ARRAY OPERATIONS

## 5.1 Traversal
**Concept**: Visit each element once, typically left to right.
```cpp
for (int i = 0; i < n; i++) cout << arr[i] << " ";
```
Complexity: O(n) time, O(1) space.

## 5.2 Access
Direct indexed access `arr[i]` → O(1).

## 5.3 Search
- **Brute Force (unsorted)**: Linear scan → O(n).
- **Optimal (sorted)**: Binary Search → O(log n).

```cpp
// Linear Search
int linearSearch(vector<int>& a, int target) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] == target) return i;
    return -1;
}
```

## 5.4 Insert
- **At end**: O(1) amortized (vector) / O(1) if space available (array).
- **At index i (middle)**: Shift all elements from i to end right by one → O(n).

**Dry Run** (insert 99 at index 2 in `[1,2,3,4,5]`, capacity available):
```
Before: [1,2,3,4,5]
Shift right from end: [1,2,3,4,4,5] -> wait, shift properly:
Step: copy 5 to index 5: [1,2,3,4,5,5]
Step: copy 4 to index 4: [1,2,3,4,4,5]
Insert 99 at index 2:    [1,2,99,4,4,5] -> 
Final correct:           [1,2,99,3,4,5]
```

## 5.5 Delete
Shift elements after index left by one to fill the gap → O(n).

## 5.6 Update
Direct assignment `arr[i] = newVal` → O(1).

## 5.7 Reverse
**Two Pointer Technique** (optimal, in-place):
```cpp
void reverse(vector<int>& a) {
    int l = 0, r = a.size() - 1;
    while (l < r) swap(a[l++], a[r--]);
}
```
Time: O(n), Space: O(1).

## 5.8 Rotate
### Left Rotate by k (Optimal — Reversal Algorithm)
```cpp
void rotateLeft(vector<int>& a, int k) {
    int n = a.size();
    k %= n;
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
    reverse(a.begin(), a.end());
}
```
**Dry Run** for `a = [1,2,3,4,5], k=2`:
```
reverse first k:      [2,1,3,4,5]
reverse rest:         [2,1,5,4,3]
reverse whole:         [3,4,5,1,2]   ✓ left rotated by 2
```
Time: O(n), Space: O(1).

## 5.9 Merge (Two Sorted Arrays)
Two-pointer merge → O(n+m) time, O(n+m) space (or O(1) extra if merging in-place with gap method).

## 5.10 Split
Dividing array into two parts (e.g., for merge sort) — O(n) to copy into sub-arrays.

## 5.11 Shift
Shifting all elements by one position (left or right) — used in deletion/insertion — O(n).

---

# SECTION 6: PREFIX SUM FAMILY

## 6.1 Prefix Sum
**Definition**: `prefix[i] = arr[0] + arr[1] + ... + arr[i]`

**Intuition**: Precompute cumulative sums once, then answer **any range sum query in O(1)**.

```
arr:     [2, 4, 6, 8, 10]
prefix:  [2, 6, 12, 20, 30]
```

**Range Sum Query** `sum(l, r) = prefix[r] - prefix[l-1]` (handle `l=0` specially, or use `prefix[-1]=0`).

```cpp
vector<int> prefix(n);
prefix[0] = arr[0];
for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + arr[i];

// query sum(l, r):
int query(int l, int r) {
    if (l == 0) return prefix[r];
    return prefix[r] - prefix[l-1];
}
```
Time: O(n) build, O(1) query. Space: O(n).

## 6.2 Suffix Sum
`suffix[i] = arr[i] + arr[i+1] + ... + arr[n-1]` — built right to left. Useful for "left part vs right part" problems (e.g., equilibrium index).

## 6.3 Prefix XOR
Same idea but with XOR instead of sum: `prefixXOR[i] = arr[0]^arr[1]^...^arr[i]`. Range XOR query: `xor(l,r) = prefixXOR[r] ^ prefixXOR[l-1]`.

## 6.4 Difference Array
**Use Case**: Multiple **range update** queries (add `val` to all elements from `l` to `r`), then read final array.

```cpp
vector<int> diff(n+1, 0);
// To add 'val' to range [l, r]:
diff[l] += val;
diff[r+1] -= val;

// Reconstruct final array:
vector<int> result(n);
result[0] = diff[0];
for (int i = 1; i < n; i++) result[i] = result[i-1] + diff[i];
```
Time: O(1) per update, O(n) to reconstruct. This converts **O(n) per update** into **O(1) per update**.

## 6.5 2D Prefix Sum
`prefix[i][j] = sum of all elements in rectangle (0,0) to (i,j)`

```cpp
prefix[i][j] = arr[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
```

**Query sum of rectangle** `(r1,c1)` to `(r2,c2)`:
```cpp
sum = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1];
```
(handle boundary rows/cols = 0 carefully). Time: O(rows*cols) build, O(1) per query.

---

# SECTION 7: ARRAY PATTERNS

> This is the **most important section for interviews**. Most array problems reduce to one of these patterns.

## Pattern 1: Traversal
**Clues**: "process every element", "find max/min/sum".
**Template**: Single for-loop, O(n).

## Pattern 2: Frequency Counting
**Clues**: "count occurrences", "duplicate", "majority", "anagram".
**Template**: Hash map or fixed-size count array.
```cpp
unordered_map<int,int> freq;
for (int x : arr) freq[x]++;
```

## Pattern 3: Prefix Sum
**Clues**: "subarray sum equals k", "range sum queries", "equilibrium index".
(See Section 6)

## Pattern 4: Sliding Window

### Fixed Window
**Clues**: "subarray of size k", "max/min sum of window size k".
```cpp
int windowSum = 0;
for (int i = 0; i < n; i++) {
    windowSum += arr[i];
    if (i >= k - 1) {
        // process window [i-k+1, i]
        windowSum -= arr[i - k + 1];
    }
}
```

### Variable Window
**Clues**: "longest/shortest subarray with condition X" (sum ≤ k, at most k distinct, etc.)
```cpp
int l = 0; int sum = 0; int best = 0;
for (int r = 0; r < n; r++) {
    sum += arr[r];
    while (sum > target) {       // shrink while condition violated
        sum -= arr[l];
        l++;
    }
    best = max(best, r - l + 1);
}
```
**Dry Run** for `arr=[1,2,1,0,1,1,0], target sum<=4`: window grows/shrinks tracking max length — classic "longest subarray with sum ≤ k" pattern.

## Pattern 5: Two Pointers

### Opposite Direction
**Clues**: "pair sum in sorted array", "reverse array", "palindrome check".
```cpp
int l = 0, r = n-1;
while (l < r) {
    if (arr[l] + arr[r] == target) { /* found */ }
    else if (arr[l] + arr[r] < target) l++;
    else r--;
}
```

### Same Direction
**Clues**: "remove duplicates in-place", "move zeroes".
```cpp
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (condition(arr[fast])) {
        swap(arr[slow], arr[fast]);
        slow++;
    }
}
```

### Fast-Slow Pointer
**Clues**: Used in array-based **cycle detection** (e.g., "Find the Duplicate Number" treating array as a linked list via indices).

## Pattern 6: Hashing
**Clues**: "two sum", "subarray sum = k", "first unique element".
```cpp
unordered_map<int,int> seen;
for (int i = 0; i < n; i++) {
    if (seen.count(target - arr[i])) { /* pair found */ }
    seen[arr[i]] = i;
}
```

## Pattern 7: Sorting Based
**Clues**: "merge intervals", "closest pair", problems where order doesn't matter but relative comparison does.
Sort first (O(n log n)), then apply linear scan / two pointers.

## Pattern 8: Binary Search
**Clues**: "sorted array", "search in rotated sorted array", "find peak", "minimize the maximum" (binary search on answer).
```cpp
int l = 0, r = n - 1;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) l = mid + 1;
    else r = mid - 1;
}
return -1;
```

## Pattern 9: Greedy Arrays
**Clues**: "maximize/minimize with local optimal choice", "jump game", "gas station".
Make the locally-best choice at each step and prove it leads to global optimum.

## Pattern 10: Kadane Pattern
**Clues**: "maximum subarray sum", "maximum sum contiguous subarray".
(See Section 8)

## Pattern 11: Merge Intervals
**Clues**: "overlapping intervals", "merge meetings", "insert interval".
```cpp
sort(intervals.begin(), intervals.end());
vector<vector<int>> merged;
for (auto& iv : intervals) {
    if (!merged.empty() && iv[0] <= merged.back()[1])
        merged.back()[1] = max(merged.back()[1], iv[1]);
    else
        merged.push_back(iv);
}
```

## Pattern 12: Matrix Pattern
**Clues**: "2D grid", "spiral", "rotate image", "search in matrix".
(See Section 9)

## Pattern 13: Bit Manipulation Arrays
**Clues**: "single number", "XOR of array", "subsets via bitmask".
Key identity: `x ^ x = 0`, `x ^ 0 = x`.

## Pattern 14: Cyclic Sort
**Clues**: "array contains numbers from 1 to n", "find missing/duplicate number", values map directly to indices.
```cpp
int i = 0;
while (i < n) {
    int correct = arr[i] - 1;
    if (arr[i] != arr[correct]) swap(arr[i], arr[correct]);
    else i++;
}
```
Time: O(n) — each swap places at least one element correctly.

## Pattern 15: Dutch National Flag
**Clues**: "sort array of 0s,1s,2s", "3-way partitioning".
(See Section 8)

## Pattern 16: Meet In The Middle
**Clues**: "subset sum with n up to ~40", split array into two halves, brute force each half, combine.
Reduces O(2^n) to O(2^(n/2)).

## Pattern 17: Sweep Line
**Clues**: "interval overlap count", "max meetings at once", "skyline problem".
Convert intervals into +1/-1 events at boundaries, sort events, sweep across.

## Pattern 18: Coordinate Compression
**Clues**: "values are large/sparse but only relative order matters" — map values to ranks `0..n-1` to allow array/BIT-based techniques.
```cpp
vector<int> sorted_vals = arr;
sort(sorted_vals.begin(), sorted_vals.end());
sorted_vals.erase(unique(sorted_vals.begin(), sorted_vals.end()), sorted_vals.end());
// rank of arr[i] = lower_bound(sorted_vals, arr[i]) - sorted_vals.begin()
```

---

# SECTION 8: IMPORTANT ARRAY ALGORITHMS

## 8.1 Kadane's Algorithm — Maximum Subarray Sum
**Problem**: Find the contiguous subarray with the largest sum.

**Intuition**: At every index, decide: extend the previous subarray, or start fresh from here (if previous sum became negative, it can't help).

```cpp
int maxSubArray(vector<int>& a) {
    int maxSum = a[0], curSum = a[0];
    for (int i = 1; i < a.size(); i++) {
        curSum = max(a[i], curSum + a[i]);
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}
```
**Dry Run** for `[-2,1,-3,4,-1,2,1,-5,4]`:
```
i=0: cur=-2, max=-2
i=1: cur=max(1,-2+1=-1)=1, max=1
i=2: cur=max(-3,1-3=-2)=-2, max=1
i=3: cur=max(4,-2+4=2)=4, max=4
i=4: cur=max(-1,4-1=3)=3, max=4
i=5: cur=max(2,3+2=5)=5, max=5
i=6: cur=max(1,5+1=6)=6, max=6
i=7: cur=max(-5,6-5=1)=1, max=6
i=8: cur=max(4,1+4=5)=5, max=6
Answer: 6  (subarray [4,-1,2,1])
```
Time: O(n), Space: O(1).
**Interview Note**: Mention how to also track the actual subarray (store start/end indices).

## 8.2 Moore's Voting Algorithm — Majority Element (> n/2)
**Intuition**: Maintain a candidate and a count. If counts cancel out, switch candidate.
```cpp
int majorityElement(vector<int>& a) {
    int count = 0, candidate = 0;
    for (int x : a) {
        if (count == 0) candidate = x;
        count += (x == candidate) ? 1 : -1;
    }
    return candidate; // verify if needed (count occurrences)
}
```
Time: O(n), Space: O(1).

## 8.3 Dutch National Flag Algorithm — Sort 0s, 1s, 2s
```cpp
void sortColors(vector<int>& a) {
    int low = 0, mid = 0, high = a.size() - 1;
    while (mid <= high) {
        if (a[mid] == 0) swap(a[low++], a[mid++]);
        else if (a[mid] == 1) mid++;
        else swap(a[mid], a[high--]);
    }
}
```
**Dry Run** for `[2,0,2,1,1,0]`:
```
low=0 mid=0 high=5: a[mid]=2 -> swap(mid,high): [0,0,2,1,1,2], high=4
low=0 mid=0 high=4: a[mid]=0 -> swap(low,mid): [0,0,2,1,1,2], low=1,mid=1
low=1 mid=1 high=4: a[mid]=0 -> swap: [0,0,2,1,1,2], low=2,mid=2
low=2 mid=2 high=4: a[mid]=2 -> swap(mid,high): [0,0,1,1,2,2], high=3
low=2 mid=2 high=3: a[mid]=1 -> mid++
low=2 mid=3 high=3: a[mid]=1 -> mid++
mid > high, done: [0,0,1,1,2,2] ✓
```
Time: O(n) single pass, Space: O(1).

## 8.4 Floyd's Cycle Detection (Array Application)
**Use Case**: "Find the Duplicate Number" — array of n+1 integers in range [1,n]. Treat `arr[i]` as a pointer to next index → forms a linked structure with a guaranteed cycle.
```cpp
int findDuplicate(vector<int>& a) {
    int slow = a[0], fast = a[0];
    do {
        slow = a[slow];
        fast = a[a[fast]];
    } while (slow != fast);
    slow = a[0];
    while (slow != fast) {
        slow = a[slow];
        fast = a[fast];
    }
    return slow;
}
```
Time: O(n), Space: O(1).

## 8.5 Quick Select — Kth Largest/Smallest
**Intuition**: Like quicksort, but only recurse into the partition that contains the kth element.
```cpp
int quickSelect(vector<int>& a, int l, int r, int k) {
    int pivot = a[r], p = l;
    for (int i = l; i < r; i++)
        if (a[i] <= pivot) swap(a[i], a[p++]);
    swap(a[p], a[r]);
    if (p == k) return a[p];
    else if (p < k) return quickSelect(a, p+1, r, k);
    else return quickSelect(a, l, p-1, k);
}
```
Time: Average O(n), Worst O(n²). Space: O(1) extra (O(log n) recursion stack average).

## 8.6 Prefix Sum / Difference Array
(See Section 6 — fully covered there)

---

# SECTION 9: MATRIX (2D ARRAY) MASTERY

## 9.1 Matrix Representation
A matrix is an array of arrays — `mat[i][j]` where `i` = row, `j` = column.
```cpp
vector<vector<int>> mat(rows, vector<int>(cols, 0));
```

## 9.2 Traversal Types

### Row-wise
```cpp
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        cout << mat[i][j];
```

### Column-wise
```cpp
for (int j = 0; j < cols; j++)
    for (int i = 0; i < rows; i++)
        cout << mat[i][j];
```

### Diagonal Traversal (main diagonal, i==j)
```cpp
for (int i = 0; i < min(rows, cols); i++) cout << mat[i][i];
```

### Anti-Diagonal Traversal
Elements where `i + j = constant`.
```cpp
for (int d = 0; d < rows + cols - 1; d++) {
    for (int i = 0; i < rows; i++) {
        int j = d - i;
        if (j >= 0 && j < cols) cout << mat[i][j];
    }
}
```

### Spiral Traversal
**Intuition**: Maintain 4 boundaries (top, bottom, left, right). Traverse top row → right col → bottom row → left col, then shrink boundaries.
```cpp
vector<int> spiralOrder(vector<vector<int>>& mat) {
    vector<int> res;
    int top=0, bottom=mat.size()-1, left=0, right=mat[0].size()-1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++) res.push_back(mat[top][j]);
        top++;
        for (int i = top; i <= bottom; i++) res.push_back(mat[i][right]);
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) res.push_back(mat[bottom][j]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) res.push_back(mat[i][left]);
            left++;
        }
    }
    return res;
}
```
Time: O(rows*cols), Space: O(1) extra (excluding output).

### Zigzag (Boustrophedon) Traversal
Alternate direction per row: left-to-right on even rows, right-to-left on odd rows.

## 9.3 Key Matrix Problems

### Rotate Matrix 90° (In-Place)
**Optimal Trick**: Transpose, then reverse each row (for clockwise rotation).
```cpp
void rotate(vector<vector<int>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            swap(mat[i][j], mat[j][i]);      // transpose
    for (auto& row : mat)
        reverse(row.begin(), row.end());     // reverse each row
}
```
**Dry Run** for `[[1,2],[3,4]]`:
```
Transpose: [[1,3],[2,4]]
Reverse rows: [[3,1],[4,2]]   ✓ (90° clockwise)
```
Time: O(n²), Space: O(1).

### Search in a Sorted Matrix (rows and cols sorted)
**Optimal**: Start at top-right corner. If current > target, move left. If current < target, move down.
```cpp
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int i = 0, j = mat[0].size()-1;
    while (i < mat.size() && j >= 0) {
        if (mat[i][j] == target) return true;
        else if (mat[i][j] > target) j--;
        else i++;
    }
    return false;
}
```
Time: O(rows + cols), Space: O(1).

### Set Matrix Zeroes
**Optimal (O(1) extra space)**: Use first row & first column as markers.
```cpp
void setZeroes(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();
    bool firstRowZero = false, firstColZero = false;
    for (int j = 0; j < cols; j++) if (mat[0][j] == 0) firstRowZero = true;
    for (int i = 0; i < rows; i++) if (mat[i][0] == 0) firstColZero = true;

    for (int i = 1; i < rows; i++)
        for (int j = 1; j < cols; j++)
            if (mat[i][j] == 0) { mat[i][0] = 0; mat[0][j] = 0; }

    for (int i = 1; i < rows; i++)
        for (int j = 1; j < cols; j++)
            if (mat[i][0] == 0 || mat[0][j] == 0) mat[i][j] = 0;

    if (firstRowZero) for (int j = 0; j < cols; j++) mat[0][j] = 0;
    if (firstColZero) for (int i = 0; i < rows; i++) mat[i][0] = 0;
}
```
Time: O(rows*cols), Space: O(1).

### 2D Prefix Sum Matrix
(See Section 6.5)

---

# SECTION 10: INTERVIEW PROBLEM SOLVING FRAMEWORK

## 10.1 Decision Tree for Array Problems

```
START
  │
  ├─ Is it about a CONTIGUOUS subarray sum/range? ──► Prefix Sum / Sliding Window
  │
  ├─ Is it about finding a PAIR/TRIPLET with a condition?
  │     ├─ Array is sorted? ──► Two Pointers
  │     └─ Array is unsorted? ──► Hashing (or sort + two pointers)
  │
  ├─ Is the array SORTED and you need to find something? ──► Binary Search
  │
  ├─ Do you need to count FREQUENCY / duplicates? ──► Hashing / Frequency Array
  │
  ├─ Is it MAXIMUM CONTIGUOUS sum/product? ──► Kadane's Algorithm
  │
  ├─ Are you given INTERVALS to merge/overlap? ──► Sort + Merge Intervals / Sweep Line
  │
  ├─ Are values restricted to range [1..n] (cyclic property)? ──► Cyclic Sort
  │
  ├─ Is it a 2D GRID problem? ──► Matrix Traversal Patterns
  │
  ├─ Local greedy choice seems to lead to a global optimum? ──► Greedy
  │
  └─ None of the above, brute force is needed first? ──► Start Brute Force → Optimize
```

## 10.2 General Problem-Solving Steps
1. **Clarify**: input size, constraints, sorted or not, duplicates allowed, edge cases.
2. **Brute force first**: always state the O(n²) or O(n³) approach, even if you won't code it.
3. **Identify the pattern** using the decision tree above.
4. **Optimize**: apply the matching pattern/algorithm.
5. **Dry run** on a small example, including edge cases.
6. **State complexity** clearly (time AND space).

---

# SECTION 11: COMMON TRICKS

## Prefix Sum Tricks
- Use `prefix[-1] = 0` conceptually (or a `(n+1)`-sized array starting at index 1) to avoid boundary `if` checks.
- "Subarray sum equals k" → `prefix[j] - prefix[i] = k` → store prefix sums in a hashmap and look for `prefix[j] - k`.

## Binary Search Tricks
- Use `mid = l + (r - l) / 2` to avoid integer overflow (instead of `(l+r)/2`).
- "Binary search on answer": when the question says "minimize the maximum" or "maximize the minimum", binary search over the **answer space**, not the array.

## Sliding Window Tricks
- For "exactly k distinct" problems: compute `atMost(k) - atMost(k-1)`.
- Always shrink the window with a `while`, not an `if`, when multiple shrink steps may be needed.

## Hashing Tricks
- For "two sum", store `value → index` while iterating once; check complement before inserting current.
- Use a `count` array instead of hashmap when value range is small and known (faster, O(1) guaranteed).

## Sorting Tricks
- Sorting is a powerful preprocessing step — many problems become trivial after sorting (e.g., merge intervals, closest pair).
- Sorting destroys original order/index — save indices first if needed.

## Matrix Tricks
- Use boundary variables (top, bottom, left, right) for spiral-type traversal instead of complex modular math.
- Transpose + reverse = rotate 90° clockwise. Reverse + transpose = rotate 90° counter-clockwise.

---

# SECTION 12: COMMON MISTAKES

## Off-By-One Errors
```cpp
// WRONG: misses last element
for (int i = 0; i < n - 1; i++)
// RIGHT
for (int i = 0; i < n; i++)
```

## Integer Overflow
```cpp
int mid = (l + r) / 2;       // can overflow if l, r are large ints
int mid = l + (r - l) / 2;   // SAFE
```
Also: summing large arrays into an `int` can overflow — use `long long` for sums.

## Binary Search Bugs
- Infinite loop when `l = mid` instead of `l = mid + 1` (or vice versa for `r`).
- Wrong condition (`<` vs `<=`) causing missed elements at boundaries.

## Prefix Sum Bugs
- Forgetting to handle `l == 0` case separately when computing `prefix[r] - prefix[l-1]`.

## Sliding Window Bugs
- Using `if` instead of `while` to shrink the window — fails when multiple shrinks are needed in one step.
- Forgetting to update the window sum/count when shrinking from the left.

## Hashing Bugs
- Checking `map[complement]` before inserting current element causes self-pairing bugs (e.g., target=6, arr has a single 3 — must not pair 3 with itself unless duplicate exists).

## Rotation Bugs
- Forgetting `k %= n` when `k > n`, causing unnecessary or wrong rotations (or out-of-bounds access in some implementations).

---

# SECTION 13: COMPLETE ARRAY QUESTION LIST

> Curated, pattern-tagged practice list. Use these for daily practice (Platform: LeetCode unless noted).

## Easy

| # | Problem | Pattern | Key Idea |
|---|---|---|---|
| 1 | Two Sum | Hashing | Complement lookup |
| 2 | Best Time to Buy and Sell Stock | Traversal/Greedy | Track min price so far |
| 3 | Contains Duplicate | Hashing | Set lookup |
| 4 | Maximum Subarray | Kadane | Running sum reset |
| 5 | Move Zeroes | Two Pointers | Same direction swap |
| 6 | Remove Duplicates from Sorted Array | Two Pointers | Slow-fast pointer |
| 7 | Plus One | Traversal | Carry propagation |
| 8 | Merge Sorted Array | Two Pointers | Merge from back |
| 9 | Majority Element | Moore's Voting | Candidate/count |
| 10 | Single Number | Bit Manipulation | XOR cancels pairs |
| 11 | Pascal's Triangle | Matrix/DP-ish | Build row by row |
| 12 | Missing Number | Sum formula / XOR | n(n+1)/2 - sum |
| 13 | Squares of a Sorted Array | Two Pointers | Compare from ends |
| 14 | Valid Mountain Array | Traversal | Increasing then decreasing |
| 15 | Find Pivot Index | Prefix Sum | Left sum == right sum |
| 16 | Flood Fill (as grid) | Matrix Traversal | DFS/BFS on grid |
| 17 | Transpose Matrix | Matrix | Swap rows/cols |
| 18 | Third Maximum Number | Traversal | Track top 3 |
| 19 | Check if Array Is Sorted | Traversal | Single pass compare |
| 20 | Running Sum of 1d Array | Prefix Sum | Cumulative add |
| 21 | Kth Largest Element (small array) | Sorting | Sort then index |
| 22 | Intersection of Two Arrays | Hashing | Set intersection |
| 23 | Array Partition | Sorting | Sort + pair adjacent |
| 24 | Toeplitz Matrix | Matrix | Diagonal comparison |
| 25 | Max Consecutive Ones | Sliding Window | Count streaks |

## Medium

| # | Problem | Pattern | Key Idea |
|---|---|---|---|
| 1 | 3Sum | Two Pointers + Sorting | Fix one, two-pointer rest |
| 2 | Product of Array Except Self | Prefix/Suffix | Prefix * Suffix product |
| 3 | Rotate Array | Reversal Algorithm | 3-reversal trick |
| 4 | Subarray Sum Equals K | Prefix Sum + Hashing | prefix[j]-prefix[i]=k |
| 5 | Longest Substring Without Repeating (string-as-array) | Sliding Window | Variable window |
| 6 | Sort Colors | Dutch National Flag | 3-way partition |
| 7 | Spiral Matrix | Matrix Traversal | Boundary shrinking |
| 8 | Rotate Image | Matrix | Transpose + reverse |
| 9 | Set Matrix Zeroes | Matrix | Marker rows/cols |
| 10 | Search in Rotated Sorted Array | Binary Search | Modified binary search |
| 11 | Find Minimum in Rotated Sorted Array | Binary Search | Compare with mid |
| 12 | Kth Largest Element in an Array | Quick Select | Partition-based selection |
| 13 | Container With Most Water | Two Pointers | Move smaller height pointer |
| 14 | Merge Intervals | Sorting + Sweep | Sort + merge overlapping |
| 15 | Insert Interval | Merge Intervals | Linear scan + merge |
| 16 | Non-overlapping Intervals | Greedy | Sort by end time |
| 17 | Gas Station | Greedy | Track running deficit |
| 18 | Jump Game | Greedy | Track farthest reachable |
| 19 | Jump Game II | Greedy/BFS | Level-based jumps |
| 20 | Find All Duplicates in an Array | Cyclic Sort / Marking | Negate visited indices |
| 21 | Find the Duplicate Number | Floyd's Cycle | Linked-list cycle on indices |
| 22 | Subarray Sum Divisible by K | Prefix Sum + Hashing | Mod equivalence classes |
| 23 | Continuous Subarray Sum | Prefix Sum + Hashing | Same mod remainder |
| 24 | Maximum Product Subarray | Kadane variant | Track max AND min |
| 25 | 4Sum | Two Pointers + Sorting | Nested fix + two pointer |
| 26 | Next Permutation | Array manipulation | Find pivot, swap, reverse |
| 27 | Search a 2D Matrix | Binary Search / Two pointer | Treat as sorted 1D or staircase |
| 28 | Game of Life | Matrix simulation | In-place state encoding |
| 29 | Diagonal Traverse | Matrix | Direction-flipping diagonal walk |
| 30 | Longest Consecutive Sequence | Hashing | Set + sequence expansion |
| 31 | Minimum Size Subarray Sum | Sliding Window | Shrink while sum >= target |
| 32 | Subarray Product Less Than K | Sliding Window | Shrink on product overflow |
| 33 | Find All Anagrams in a String | Sliding Window + Hashing | Fixed window frequency match |
| 34 | K Closest Points to Origin | Sorting/Quick Select | Distance comparator |
| 35 | Top K Frequent Elements | Hashing + Sorting/Heap | Frequency map + bucket |

## Hard

| # | Problem | Pattern | Key Idea |
|---|---|---|---|
| 1 | Trapping Rain Water | Two Pointers / Prefix | Left max & right max arrays |
| 2 | First Missing Positive | Cyclic Sort | Place x at index x-1 |
| 3 | Median of Two Sorted Arrays | Binary Search | Partition-based binary search |
| 4 | Sliding Window Maximum | Monotonic Deque | Maintain decreasing deque |
| 5 | Maximum Sum Rectangle in 2D Matrix | Kadane + Prefix Sum | Row compression + Kadane |
| 6 | Count of Smaller Numbers After Self | Merge Sort / BIT | Counting inversions |
| 7 | Largest Rectangle in Histogram | Monotonic Stack | Track increasing stack of bars |
| 8 | Maximal Rectangle (in 0/1 matrix) | Histogram + DP-ish | Row-wise histogram trick |
| 9 | Longest Increasing Subsequence (O(n log n)) | Binary Search | Patience sorting / tails array |
| 10 | Russian Doll Envelopes | Sorting + LIS | Sort + LIS on second dimension |
| 11 | Sliding Window Median | Two heaps / multiset | Balance two halves |
| 12 | Count Subarrays with Sum K (negative allowed) | Prefix Sum + Hashing | Same as subarray sum, generalized |
| 13 | Smallest Range Covering Elements from K Lists | Sliding Window + Heap | Min-heap of pointers |
| 14 | Max Points on a Line | Slope hashing | Group by slope from each point |
| 15 | Candy (Greedy array) | Greedy, two-pass | Left-to-right & right-to-left pass |

---

# SECTION 14: REVISION CHEAT SHEET

## Array Cheat Sheet
```
Access:        arr[i]                       O(1)
Traverse:       for(i=0;i<n;i++)              O(n)
Insert middle:  shift right, then place       O(n)
Delete middle:  shift left to fill gap        O(n)
Reverse:        two pointer swap               O(n)
Rotate:         3-reversal trick               O(n)
```

## Vector Cheat Sheet
```cpp
vector<int> v;             // declare
v.push_back(x);            // amortized O(1)
v.pop_back();               // O(1)
v.size(); v.capacity();     // O(1)
v.reserve(n);                // pre-allocate, avoid reallocation
v.insert(it, val);            // O(n)
v.erase(it);                   // O(n)
v.clear();                      // O(n), size=0, capacity unchanged
```

## Complexity Cheat Sheet
| Operation | Complexity |
|---|---|
| Access | O(1) |
| Search (unsorted) | O(n) |
| Search (sorted) | O(log n) |
| Insert/Delete at end | O(1) amortized |
| Insert/Delete at middle | O(n) |
| Sort | O(n log n) |

## Binary Search Template
```cpp
int l = 0, r = n - 1;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) l = mid + 1;
    else r = mid - 1;
}
return -1;
```

## Sliding Window Template
```cpp
int l = 0;
for (int r = 0; r < n; r++) {
    // expand window using arr[r]
    while (/* window invalid */) {
        // shrink window using arr[l]
        l++;
    }
    // update answer using window [l, r]
}
```

## Two Pointer Template
```cpp
int l = 0, r = n - 1;
while (l < r) {
    if (/* condition met */) { /* process */ l++; r--; }
    else if (/* need bigger */) l++;
    else r--;
}
```

## Prefix Sum Template
```cpp
vector<long long> prefix(n);
prefix[0] = arr[0];
for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + arr[i];
// sum(l, r) = prefix[r] - (l > 0 ? prefix[l-1] : 0)
```

## Rotation Template (Reversal Algorithm)
```cpp
void rotateLeft(vector<int>& a, int k) {
    int n = a.size(); k %= n;
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());
    reverse(a.begin(), a.end());
}
```

---

# SECTION 15: FINAL ARRAY & VECTOR ROADMAP

## Beginner → Intermediate → Advanced

### Beginner 
- Array fundamentals, memory model, indexing
- Vector basics & STL functions
- Traversal, search, insert, delete, update
- Reverse, basic rotation
- Easy questions (Section 13)

### Intermediate 
- Prefix sum, suffix sum, difference array
- Sliding window (fixed + variable)
- Two pointers (all 3 types)
- Hashing-based patterns
- Sorting-based patterns
- Binary search on arrays
- Medium questions (Section 13)

### Advanced 
- Kadane's, Moore's Voting, Dutch National Flag
- Cyclic sort, Floyd's cycle on arrays
- Matrix mastery (spiral, rotate, search, prefix sum 2D)
- Merge intervals, sweep line, coordinate compression
- Quick select, meet in the middle
- Hard questions (Section 13)



## Weekly Revision Plan
- **Daily**: Re-derive 1 template from memory (no looking at notes).
- **Every 3 days**: Re-solve 2 previously solved problems without hints.
- **Weekly**: Full pass through Section 14 (Cheat Sheets) + timed mock of 3 mixed-pattern problems.

## Recommended Practice Order
1. Easy (all 25) → build muscle memory for syntax & basic patterns.
2. Medium, grouped by pattern (do all sliding window together, then all two-pointer, etc.) — pattern recognition > random practice.
3. Hard — attempt brute force first, always, before looking at optimal.
4. Timed mock sets mixing patterns randomly (simulates real interview/OA conditions).

---

# 🎯 Final Notes
- Arrays and Vectors are the **foundation** of almost all interview problems — master the 18 patterns in Section 7 and you can solve 80%+ of array-based interview questions.
- Always state **Brute → Better → Optimal** out loud in interviews, even if you jump straight to optimal in code.
- Dry run on paper before coding — it catches off-by-one and boundary bugs early.
- Revisit Section 14 (Cheat Sheet) the night before any interview or OA.

