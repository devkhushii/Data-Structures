# 🚀 THE ULTIMATE ARRAY & VECTOR DSA HANDBOOK
### Complete Preparation for Beginners → Competitive Programmers → FAANG Interviews

---

> **How to use this handbook:**
> - Beginners: Read every section, run every dry run mentally before looking at code
> - Intermediate: Focus on Sections 4–8, patterns, and interview questions
> - Advanced: Jump to Sections 9–13 for competitive topics
> - Revision: Use Section 14 (Cheat Sheet) before exams/interviews

---

# TABLE OF CONTENTS

1. [Introduction to Arrays](#section-1)
2. [Vector Complete Guide (C++ STL)](#section-2)
3. [Array Memory Model](#section-3)
4. [Array Operations](#section-4)
5. [Complete Searching Algorithms](#section-5)
6. [All Array Patterns (20 Patterns)](#section-6)
7. [Important Algorithms on Arrays](#section-7)
8. [Sorting for Arrays](#section-8)
9. [Complete Interview Questions](#section-9)
10. [Problem Solving Framework](#section-10)
11. [Common Tricks](#section-11)
12. [Common Mistakes](#section-12)
13. [Advanced Topics](#section-13)
14. [Revision Cheat Sheet](#section-14)
15. [Final Mastery Roadmap](#section-15)

---

<a name="section-1"></a>
# SECTION 1: INTRODUCTION TO ARRAYS

---

## 1.1 What Is an Array?

### Definition
An **array** is a collection of elements stored at **contiguous (adjacent) memory locations**, where each element is of the **same data type** and can be accessed using an **index**.

Think of an array like a row of numbered lockers in a hallway:
- Each locker holds exactly one item
- Lockers are numbered from 0 (or 1)
- You can instantly open any locker if you know its number
- All lockers are the same size (same data type)

### Visual Representation

```
Index:    0     1     2     3     4     5
       +-----+-----+-----+-----+-----+-----+
Value: | 10  | 20  | 30  | 40  | 50  | 60  |
       +-----+-----+-----+-----+-----+-----+
Addr:  1000  1004  1008  1012  1016  1020
```

*(Assuming int = 4 bytes, base address = 1000)*

### Key Properties
| Property | Explanation |
|---|---|
| Contiguous Memory | Elements are stored back-to-back in RAM |
| Same Data Type | int[], float[], char[] — no mixing |
| Fixed Size (static) | Size declared at creation, cannot change |
| Random Access | Access any element in O(1) using index |
| 0-based Indexing (C++) | First element is at index 0 |

---

## 1.2 Why Arrays Are Important?

Arrays are the **foundation of computer science** because:

1. **Every data structure** is built on top of arrays (stacks, queues, heaps, hash tables)
2. **Most algorithms** operate on arrays (sorting, searching, DP)
3. **O(1) access** — the fastest possible element access
4. **Cache-friendly** — contiguous memory maximizes CPU cache hits
5. **Interviews** — 80%+ of DSA questions involve arrays

---

## 1.3 Real-World Examples

| Use Case | Array Role |
|---|---|
| Image Pixels | 2D array of RGB values |
| Music Audio | Array of sound sample values |
| Spreadsheet | 2D array of cells |
| Database table | Array of rows |
| Game Board (Chess) | 8×8 2D array |
| Browser History | Array of URLs |
| Stock Prices | Array of daily prices |
| Student Grades | Array of marks |

---

## 1.4 Memory Representation

When you declare `int arr[5]`, the OS allocates a **continuous block of memory**:

```
RAM:
Address:  1000    1004    1008    1012    1016
         +------+------+------+------+------+
         | arr[0]|arr[1]|arr[2]|arr[3]|arr[4]|
         +------+------+------+------+------+
         |  10  |  20  |  30  |  40  |  50  |
         +------+------+------+------+------+
              ↑
         Base address (arr points here)
```

**Address Formula:**
```
Address of arr[i] = Base_Address + (i × size_of_element)
                  = 1000 + (i × 4)     [for int]

arr[3] = 1000 + (3 × 4) = 1012  ✓
```

This is why array access is **O(1)** — it's just arithmetic!

---

## 1.5 Static vs Dynamic Arrays

### Static Arrays (Fixed Size)

```cpp
int arr[5];           // Declared with fixed size
int arr[5] = {1,2,3,4,5};  // Initialized

// Properties:
// - Size fixed at compile time
// - Stored on STACK (usually)
// - Very fast allocation
// - Cannot grow or shrink
```

```
Stack Memory:
+-----+-----+-----+-----+-----+
|  1  |  2  |  3  |  4  |  5  |
+-----+-----+-----+-----+-----+
```

### Dynamic Arrays (Variable Size)

```cpp
int* arr = new int[5];    // Heap allocation, C-style
// OR
vector<int> v;            // C++ STL vector (preferred)

// Properties:
// - Size can change at runtime
// - Stored on HEAP
// - Slightly slower (heap allocation)
// - Can grow and shrink
```

### Comparison Table

| Feature | Static Array | Dynamic Array (Vector) |
|---|---|---|
| Size | Fixed at compile time | Grows/shrinks at runtime |
| Memory | Stack (usually) | Heap |
| Speed | Slightly faster | Slightly slower |
| Risk | Stack overflow if large | Heap fragmentation |
| Flexibility | Low | High |
| C++ syntax | `int arr[n]` | `vector<int> v` |
| Size known? | Must know at compile time | Can figure out at runtime |

---

## 1.6 0-Based vs 1-Based Indexing

### 0-Based (C, C++, Java, Python, JavaScript)
```
arr = [10, 20, 30, 40, 50]
       ↑    ↑    ↑    ↑    ↑
Index: 0    1    2    3    4

First element: arr[0]
Last element:  arr[n-1]  (n = size)
```

**Why 0-based?** → Because `arr[i]` means "skip `i` elements from the base address." Skipping 0 elements gives the first element.

### 1-Based (MATLAB, Fortran, some competitive programming)
```
arr = [10, 20, 30, 40, 50]
       ↑    ↑    ↑    ↑    ↑
Index: 1    2    3    4    5

First element: arr[1]
Last element:  arr[n]   (n = size)
```

### Converting Between Indexing Systems
```
0-based index i  →  1-based index (i+1)
1-based index i  →  0-based index (i-1)
```

---

## 1.7 Advantages of Arrays

1. **O(1) Random Access** — Direct access via index, no traversal needed
2. **Cache Efficiency** — Contiguous memory = great CPU cache utilization
3. **Simple Implementation** — Easy to understand and use
4. **Memory Efficient** — No extra overhead per element (unlike linked lists)
5. **Sorting/Searching** — Most algorithms work on arrays
6. **Predictable Performance** — No pointer chasing

---

## 1.8 Disadvantages of Arrays

1. **Fixed Size** — Static arrays can't grow (use vectors instead)
2. **Costly Insertion/Deletion** — O(n) to insert/delete in the middle (must shift elements)
3. **Wasted Space** — If array is too large, memory is wasted
4. **Homogeneous** — Only one data type (use struct/class for mixed)
5. **No Built-in Bounds Checking** — `arr[100]` when size is 5 = undefined behavior!

---

## 1.9 Applications of Arrays

| Domain | Application |
|---|---|
| **Searching** | Linear search, Binary search |
| **Sorting** | All sorting algorithms |
| **Matrix Operations** | 2D arrays for linear algebra |
| **Dynamic Programming** | DP tables (1D/2D arrays) |
| **Graphs** | Adjacency matrix |
| **Strings** | A string is a char array |
| **Hashing** | Hash tables use arrays internally |
| **Heaps** | Binary heap stored in array |
| **Stacks/Queues** | Implemented using arrays |
| **Segment Trees** | Array-based tree |

---

## 1.10 Array Complexity Summary

| Operation | Time Complexity | Notes |
|---|---|---|
| Access arr[i] | O(1) | Direct index calculation |
| Search (unsorted) | O(n) | Linear scan |
| Search (sorted) | O(log n) | Binary search |
| Insert at end | O(1) | Just assign arr[n] |
| Insert at middle | O(n) | Must shift elements right |
| Delete at end | O(1) | Just decrement size |
| Delete at middle | O(n) | Must shift elements left |
| Traverse | O(n) | Visit every element |

---

<a name="section-2"></a>
# SECTION 2: VECTOR COMPLETE GUIDE (C++ STL)

---

## 2.1 What Is a Vector?

A **vector** is a dynamic array in C++ that can **automatically resize** itself. It's part of the Standard Template Library (STL) and is the most commonly used container.

```cpp
#include <vector>
using namespace std;
```

### Why Vector Over Raw Array?
| Feature | Raw Array | Vector |
|---|---|---|
| Size | Fixed | Dynamic |
| Bounds Checking | None | `.at()` throws exception |
| Memory Management | Manual | Automatic |
| Built-in Functions | None | Many (sort, size, etc.) |
| Pass to Function | Pointer + size | Just the vector |
| Copy | Manual | `v2 = v1;` works |

---

## 2.2 Internal Working of Vector

A vector internally maintains:
- A **pointer** to a heap-allocated array
- **size**: number of elements currently stored
- **capacity**: total space allocated

```
vector<int> v = {1, 2, 3};

Internally:
┌─────────────────────────────────────┐
│ ptr ──────────────────────────────► │  Heap Array:
│ size = 3                            │  [1][2][3][ ][ ][ ]
│ capacity = 6                        │   ↑         ↑
└─────────────────────────────────────┘  used      allocated
```

### Capacity Growth Strategy
When you push beyond capacity, the vector:
1. Allocates new array (usually **2× the old capacity**)
2. Copies all old elements to new array
3. Deletes old array
4. Updates internal pointer

```
Start: size=0, cap=0
push_back(1): size=1, cap=1  → [1]
push_back(2): size=2, cap=2  → [1][2]
push_back(3): size=3, cap=4  → [1][2][3][ ]   ← REALLOCATED (2× growth)
push_back(4): size=4, cap=4  → [1][2][3][4]
push_back(5): size=5, cap=8  → [1][2][3][4][5][ ][ ][ ] ← REALLOCATED
```

**Amortized O(1) push_back:** Although some pushes trigger O(n) reallocation, the average cost over n pushes is O(1).

---

## 2.3 Declaration and Initialization

```cpp
#include <vector>
using namespace std;

// Method 1: Empty vector
vector<int> v1;

// Method 2: Vector of size n (all zeros)
vector<int> v2(5);           // [0, 0, 0, 0, 0]

// Method 3: Vector of size n with default value
vector<int> v3(5, 10);       // [10, 10, 10, 10, 10]

// Method 4: Initializer list
vector<int> v4 = {1, 2, 3, 4, 5};

// Method 5: Copy from another vector
vector<int> v5(v4);           // Copy of v4

// Method 6: Range-based (from array)
int arr[] = {1, 2, 3, 4, 5};
vector<int> v6(arr, arr + 5);

// Method 7: Fill using assign
vector<int> v7;
v7.assign(5, 100);           // [100, 100, 100, 100, 100]

// 2D Vector (n rows, m columns, all zeros)
int n = 3, m = 4;
vector<vector<int>> mat(n, vector<int>(m, 0));

// Vector of strings
vector<string> names = {"Alice", "Bob", "Charlie"};

// Vector of pairs
vector<pair<int,int>> edges = {{1,2}, {3,4}, {5,6}};
```

---

## 2.4 All Vector Operations

### push_back — Add to End
```cpp
vector<int> v;
v.push_back(10);   // [10]
v.push_back(20);   // [10, 20]
v.push_back(30);   // [10, 20, 30]

// Time: O(1) amortized
// Space: May trigger reallocation (O(n) internally but amortized O(1))
```

**What happens internally:**
```
Before: ptr→[10][20][ ][ ], size=2, cap=4
push_back(30):
  cap > size, so just:
  arr[size] = 30
  size++
After:  ptr→[10][20][30][ ], size=3, cap=4
```

### pop_back — Remove from End
```cpp
vector<int> v = {1, 2, 3, 4, 5};
v.pop_back();   // [1, 2, 3, 4] — removes 5
v.pop_back();   // [1, 2, 3]    — removes 4

// Time: O(1)
// ⚠️ Calling pop_back on empty vector = UNDEFINED BEHAVIOR
if (!v.empty()) v.pop_back();  // Safe way
```

### size() — Number of Elements
```cpp
vector<int> v = {1, 2, 3, 4, 5};
cout << v.size();     // 5
// Time: O(1)

// ⚠️ Common mistake: size() returns unsigned type!
// This can cause bugs with subtraction:
if (v.size() - 1 >= 0) // ALWAYS TRUE (unsigned can't be negative)
if ((int)v.size() - 1 >= 0) // Correct
```

### capacity() — Allocated Space
```cpp
vector<int> v;
for (int i = 1; i <= 8; i++) {
    v.push_back(i);
    cout << "size=" << v.size() << " cap=" << v.capacity() << "\n";
}
// Output:
// size=1 cap=1
// size=2 cap=2
// size=3 cap=4
// size=4 cap=4
// size=5 cap=8
// size=6 cap=8
// size=7 cap=8
// size=8 cap=8
```

### reserve() — Pre-allocate Space
```cpp
vector<int> v;
v.reserve(100);     // Allocate space for 100 elements (no elements yet)
cout << v.size();   // 0 (still empty)
cout << v.capacity(); // 100

// Use reserve when you know the approximate size beforehand
// AVOIDS multiple reallocations → better performance
// Time: O(n) for copying if reallocation needed, O(1) if not
```

**When to use reserve:**
```cpp
// Without reserve: many reallocations
vector<int> v;
for (int i = 0; i < 1000000; i++) v.push_back(i); // ~20 reallocations

// With reserve: zero reallocations
vector<int> v;
v.reserve(1000000);
for (int i = 0; i < 1000000; i++) v.push_back(i); // 0 reallocations
```

### resize() — Change Number of Elements
```cpp
vector<int> v = {1, 2, 3};

v.resize(5);         // [1, 2, 3, 0, 0]  — added zeros
v.resize(7, 99);     // [1, 2, 3, 0, 0, 99, 99] — added 99s
v.resize(2);         // [1, 2]  — truncated

// Time: O(n) where n = new elements added
// Note: resize vs reserve
// resize CHANGES size (adds/removes elements)
// reserve CHANGES capacity (doesn't affect elements)
```

### shrink_to_fit() — Release Excess Memory
```cpp
vector<int> v;
v.reserve(1000);
v.push_back(1);
v.push_back(2);
cout << v.capacity();  // 1000

v.shrink_to_fit();
cout << v.capacity();  // 2 (implementation-defined, usually matches size)

// Time: O(n) — may need to reallocate and copy
// Use when you're done adding to the vector and want to free memory
```

### clear() — Remove All Elements
```cpp
vector<int> v = {1, 2, 3, 4, 5};
v.clear();
cout << v.size();     // 0
cout << v.capacity(); // Still 5! (memory not freed)

// Time: O(n) — calls destructor on each element
// Note: capacity unchanged (memory still held)
// To also free memory: v = vector<int>(); OR v.shrink_to_fit() after clear
```

### empty() — Check if Empty
```cpp
vector<int> v;
cout << v.empty();    // 1 (true)
v.push_back(1);
cout << v.empty();    // 0 (false)

// Time: O(1)
// Preferred over v.size() == 0 for clarity
```

### front() and back() — Access First/Last
```cpp
vector<int> v = {10, 20, 30, 40, 50};
cout << v.front();  // 10
cout << v.back();   // 50

v.front() = 100;    // Can also assign
v.back()  = 500;
// v = {100, 20, 30, 40, 500}

// Time: O(1)
// ⚠️ Undefined behavior on empty vector
```

### at() vs [] — Accessing Elements
```cpp
vector<int> v = {10, 20, 30};

// Method 1: Subscript (no bounds check)
cout << v[0];   // 10  (fastest)
cout << v[5];   // UNDEFINED BEHAVIOR — no error thrown

// Method 2: at() (with bounds check)
cout << v.at(0);  // 10
cout << v.at(5);  // Throws std::out_of_range exception

// Prefer [] for competitive programming (speed)
// Prefer at() for production code (safety)
```

### insert() — Insert at Position
```cpp
vector<int> v = {1, 2, 3, 4, 5};
auto it = v.begin();

v.insert(it + 2, 99);      // [1, 2, 99, 3, 4, 5]  — insert at index 2
v.insert(it, 3, 0);        // [0, 0, 0, 1, 2, 99, 3, 4, 5]  — insert 3 zeros at start

// Time: O(n) — must shift elements
// ⚠️ Iterator it is INVALIDATED after insert!
```

### erase() — Remove at Position
```cpp
vector<int> v = {1, 2, 3, 4, 5};

v.erase(v.begin() + 2);              // Remove index 2: [1, 2, 4, 5]
v.erase(v.begin(), v.begin() + 2);   // Remove indices 0,1: [4, 5]

// Time: O(n) — must shift elements
// Returns iterator to the element after the erased one
```

---

## 2.5 Iterators

An **iterator** is like a pointer that points to an element in a container.

```
vector<int> v = {10, 20, 30, 40, 50};
                   ↑                  ↑
              v.begin()           v.end()  (points PAST the last element)
```

### Types of Iterators

```cpp
vector<int> v = {10, 20, 30, 40, 50};

// Forward iterator
vector<int>::iterator it = v.begin();
cout << *it;    // 10
it++;
cout << *it;    // 20

// Const iterator (can't modify elements)
vector<int>::const_iterator cit = v.cbegin();
// *cit = 99;  // ERROR — can't modify

// Reverse iterator
vector<int>::reverse_iterator rit = v.rbegin();
cout << *rit;   // 50
rit++;
cout << *rit;   // 40

// Auto (simplest, modern C++)
for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";  // 10 20 30 40 50
}
```

### Range-Based For Loop (Best Practice)
```cpp
vector<int> v = {1, 2, 3, 4, 5};

// Read only
for (int x : v) cout << x << " ";

// Modify elements (use reference)
for (int& x : v) x *= 2;   // v = {2, 4, 6, 8, 10}

// Const reference (read-only, avoids copy for large types)
for (const int& x : v) cout << x << " ";
```

### begin(), end(), rbegin(), rend()
```cpp
v = {10, 20, 30, 40, 50}

begin() → points to 10  (v[0])
end()   → points PAST 50  (v[5], one beyond last)
rbegin()→ points to 50  (v[4])  ← reverse start
rend()  → points PAST 10 (v[-1]) ← reverse end

Forward:   begin → → → → end
Backward:  rend  ← ← ← ← rbegin
```

---

## 2.6 2D Vectors (Matrix)

```cpp
// 3×4 matrix, all zeros
int rows = 3, cols = 4;
vector<vector<int>> mat(rows, vector<int>(cols, 0));

// Initialize with values
vector<vector<int>> grid = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Access
cout << grid[1][2];  // 6

// Traverse
for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
        cout << grid[i][j] << " ";
    }
    cout << "\n";
}

// Range-based
for (auto& row : grid) {
    for (int val : row) cout << val << " ";
    cout << "\n";
}

// Dynamic matrix (ragged — different row sizes)
vector<vector<int>> ragged;
ragged.push_back({1, 2, 3});
ragged.push_back({4, 5});
ragged.push_back({6, 7, 8, 9});
```

---

## 2.7 emplace_back vs push_back

```cpp
// push_back: constructs object, then COPIES into vector
v.push_back(make_pair(1, 2));   // Create pair, then copy

// emplace_back: constructs DIRECTLY in vector (no copy)
v.emplace_back(1, 2);           // Constructs pair in-place

// For primitive types (int, etc.): no difference
// For complex types (structs, pairs, objects): emplace_back is faster
```

```cpp
// Example with struct
struct Point { int x, y; };
vector<Point> pts;

// push_back: create Point, then copy
pts.push_back({1, 2});

// emplace_back: construct directly
pts.emplace_back(1, 2);    // Faster!
```

---

## 2.8 Vector Operations Summary Table

| Operation | Time | What it does |
|---|---|---|
| `push_back(x)` | O(1) amortized | Add x at end |
| `pop_back()` | O(1) | Remove last |
| `v[i]` | O(1) | Access index i (no check) |
| `v.at(i)` | O(1) | Access index i (with check) |
| `v.size()` | O(1) | Number of elements |
| `v.capacity()` | O(1) | Allocated space |
| `v.reserve(n)` | O(n) or O(1) | Pre-allocate n space |
| `v.resize(n)` | O(n) | Change number of elements |
| `v.clear()` | O(n) | Remove all elements |
| `v.empty()` | O(1) | Check if empty |
| `v.front()` | O(1) | First element |
| `v.back()` | O(1) | Last element |
| `v.insert(it, x)` | O(n) | Insert x at position it |
| `v.erase(it)` | O(n) | Remove element at it |
| `v.begin()` | O(1) | Iterator to first |
| `v.end()` | O(1) | Iterator past last |
| `sort(v.begin(),v.end())` | O(n log n) | Sort the vector |
| `reverse(v.begin(),v.end())` | O(n) | Reverse the vector |

---

<a name="section-3"></a>
# SECTION 3: ARRAY MEMORY MODEL

---

## 3.1 Stack vs Heap Memory

### Stack Memory
```
Stack (grows downward):
┌──────────────────────────────────┐
│  main() frame                    │
│  ┌────────────────────────────┐  │
│  │ int arr[5] = {1,2,3,4,5}  │  │  ← Static array lives here
│  │ int n = 5                  │  │
│  └────────────────────────────┘  │
│  foo() frame                     │
│  ┌────────────────────────────┐  │
│  │ local variables            │  │
│  └────────────────────────────┘  │
└──────────────────────────────────┘
  ↓ (grows toward low addresses)
```

**Stack Arrays:**
```cpp
int arr[5];         // Allocated on stack
                    // Automatically freed when function returns
                    // Fast allocation (just move stack pointer)
                    // RISK: Stack overflow if too large (typically ~8MB limit)
```

### Heap Memory
```
Heap (grows upward):
┌──────────────────────────────────┐
│                                  │
│  [1][2][3][4][5]                 │  ← Dynamic array (vector's data lives here)
│                                  │
└──────────────────────────────────┘
  ↑ (grows toward high addresses)
```

**Heap Arrays:**
```cpp
int* arr = new int[5];   // Allocated on heap
                          // Must manually delete[] arr;
                          // Slower (OS must find free block)
                          // No stack overflow risk (GBs available)

vector<int> v(5);        // Vector manages heap memory for you
```

---

## 3.2 Cache Locality — Why Arrays Are Blazing Fast

Modern CPUs don't read RAM one byte at a time. They load **cache lines** (~64 bytes at once) into L1/L2/L3 cache.

```
CPU Cache (fast, small):
┌─────────────────────────────────┐
│ L1 Cache: ~32KB, ~4 cycles      │
│ L2 Cache: ~256KB, ~12 cycles    │
│ L3 Cache: ~8MB, ~40 cycles      │
└─────────────────────────────────┘
         ↕ (cache miss = slow)
RAM (slow, large):
┌─────────────────────────────────┐
│ ~8-32 GB, ~200 cycles           │
└─────────────────────────────────┘
```

**Array Access Pattern:**
```
arr = [10, 20, 30, 40, 50, 60, 70, 80] (stored contiguously)

When you access arr[0], the CPU loads an entire cache line:
Cache line: [10][20][30][40][50][60][70][80]  ← All loaded at once!

Now arr[1], arr[2], ..., arr[7] are already in cache → CACHE HIT → fast!
```

**Linked List vs Array (Cache behavior):**
```
Array:   [1] → [2] → [3] → [4]    (contiguous)
           ↑ Cache loads all at once ✓

Linked list: [1] --ptr--> [2] --ptr--> [3]
              ↑            ↑            ↑
           addr 0x1000   addr 0x5000  addr 0x2000
           Three different cache misses ✗
```

This is why array traversal is often **5-10x faster** than linked list traversal in practice!

---

## 3.3 Pointer Arithmetic

```cpp
int arr[] = {10, 20, 30, 40, 50};
int* ptr = arr;   // ptr points to arr[0]

// Pointer arithmetic
cout << *ptr;        // 10  (arr[0])
cout << *(ptr + 1);  // 20  (arr[1])
cout << *(ptr + 2);  // 30  (arr[2])

// arr[i] is EXACTLY the same as *(arr + i)
arr[3] == *(arr + 3)   // Both are 40 ✓

// Pointer difference gives number of elements
int* start = arr;
int* end = arr + 5;
cout << end - start;   // 5

// Traversal using pointers
for (int* p = arr; p < arr + 5; p++) {
    cout << *p << " ";
}
```

---

## 3.4 Memory Layout for 2D Arrays

### Row-Major Order (C/C++)
```
int mat[3][4]:

Row 0: [0][1][2][3]
Row 1: [4][5][6][7]        ← In memory: Row 0 first, then Row 1, then Row 2
Row 2: [8][9][10][11]

Memory: [0][1][2][3][4][5][6][7][8][9][10][11]
         ↑                 ↑             ↑
       mat[0][0]         mat[1][0]    mat[2][0]

Address of mat[i][j] = Base + (i * cols + j) * sizeof(int)
```

**Performance Implication:**
```cpp
// FAST: Row-major traversal (cache friendly)
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        mat[i][j];    // Sequential memory access ✓

// SLOW: Column-major traversal (cache unfriendly)
for (int j = 0; j < cols; j++)
    for (int i = 0; i < rows; i++)
        mat[i][j];    // Jumps in memory each step ✗
```

---

---

<a name="section-4"></a>
# SECTION 4: ARRAY OPERATIONS

---

## 4.1 Traversal

### Concept
Visit every element of the array exactly once.

### Code
```cpp
// Forward traversal
for (int i = 0; i < n; i++) cout << arr[i] << " ";

// Backward traversal
for (int i = n-1; i >= 0; i--) cout << arr[i] << " ";

// Range-based (C++11+)
for (int x : arr) cout << x << " ";

// Using pointers
for (int* p = arr; p < arr + n; p++) cout << *p << " ";
```

**Dry Run:**
```
arr = [3, 1, 4, 1, 5, 9, 2, 6], n = 8

i=0: print arr[0]=3
i=1: print arr[1]=1
i=2: print arr[2]=4
...
i=7: print arr[7]=6

Output: 3 1 4 1 5 9 2 6
```

**Complexity:** Time O(n), Space O(1)

---

## 4.2 Access

```cpp
// Direct access — O(1)
int val = arr[i];

// Safe access with bounds check
int safeGet(int arr[], int n, int i) {
    if (i < 0 || i >= n) return -1;  // Error value
    return arr[i];
}
```

---

## 4.3 Search (Linear)

### Concept
Find if a value exists (or its index) by scanning every element.

```cpp
// Returns index of target, or -1 if not found
int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}
```

**Dry Run:**
```
arr = [5, 3, 8, 1, 9, 2], target = 8

i=0: arr[0]=5 ≠ 8
i=1: arr[1]=3 ≠ 8
i=2: arr[2]=8 = 8  → return 2 ✓
```

**Complexity:** Time O(n), Space O(1)

---

## 4.4 Insertion

### Insert at End — O(1)
```cpp
// Static array
arr[n] = newVal;
n++;

// Vector
v.push_back(newVal);
```

### Insert at Middle — O(n)
```cpp
// Static array: insert val at index pos
void insertAt(int arr[], int& n, int pos, int val) {
    // Shift elements right
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    n++;
}
```

**Dry Run:**
```
arr = [1, 2, 3, 4, 5], n=5, insert 99 at index 2

Step 1 — Shift right from end to pos+1:
  i=5: arr[5] = arr[4] = 5  → [1, 2, 3, 4, 5, 5]
  i=4: arr[4] = arr[3] = 4  → [1, 2, 3, 4, 4, 5]
  i=3: arr[3] = arr[2] = 3  → [1, 2, 3, 3, 4, 5]

Step 2 — Place new value:
  arr[2] = 99               → [1, 2, 99, 3, 4, 5]
  n = 6
```

---

## 4.5 Deletion

### Delete at End — O(1)
```cpp
n--;    // Just decrement size
// OR
v.pop_back();
```

### Delete at Middle — O(n)
```cpp
void deleteAt(int arr[], int& n, int pos) {
    // Shift elements left
    for (int i = pos; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
}
```

**Dry Run:**
```
arr = [1, 2, 99, 3, 4, 5], n=6, delete at index 2

Shift left:
  i=2: arr[2] = arr[3] = 3  → [1, 2, 3, 3, 4, 5]
  i=3: arr[3] = arr[4] = 4  → [1, 2, 3, 4, 4, 5]
  i=4: arr[4] = arr[5] = 5  → [1, 2, 3, 4, 5, 5]

n-- = 5   → effective array: [1, 2, 3, 4, 5]
```

---

## 4.6 Reversal

### Approach 1: Brute Force — Extra Array
```cpp
// O(n) time, O(n) space
void reverseBrute(vector<int>& arr) {
    int n = arr.size();
    vector<int> rev(n);
    for (int i = 0; i < n; i++) rev[n-1-i] = arr[i];
    arr = rev;
}
```

### Approach 2: Optimal — Two Pointers In-Place
```cpp
// O(n) time, O(1) space
void reverse(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}
```

**Dry Run:**
```
arr = [1, 2, 3, 4, 5]
      L=0           R=4

Step 1: swap(arr[0],arr[4]) → [5, 2, 3, 4, 1],  L=1, R=3
Step 2: swap(arr[1],arr[3]) → [5, 4, 3, 2, 1],  L=2, R=2
Step 3: L >= R, STOP

Result: [5, 4, 3, 2, 1] ✓
```

---

## 4.7 Rotation

### Left Rotation by 1
```cpp
// Move arr[0] to the end
void leftRotateByOne(vector<int>& arr) {
    int first = arr[0];
    for (int i = 0; i < arr.size()-1; i++) arr[i] = arr[i+1];
    arr.back() = first;
}
```

### Left Rotation by k — Optimal (Reversal Algorithm)
```cpp
// Rotate left by k positions
// Approach: Reverse first k, reverse rest, reverse all
// Time: O(n), Space: O(1)

void leftRotate(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;  // Handle k >= n
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}
```

**Dry Run:**
```
arr = [1, 2, 3, 4, 5], k = 2

Step 1: reverse first 2:   [2, 1, 3, 4, 5]
Step 2: reverse rest:      [2, 1, 5, 4, 3]
Step 3: reverse all:       [3, 4, 5, 1, 2] ✓

Verification: left rotate [1,2,3,4,5] by 2 → [3,4,5,1,2] ✓
```

---

## 4.8 Merging Two Sorted Arrays

```cpp
// Merge two sorted arrays into one sorted array
// Time: O(n+m), Space: O(n+m)
vector<int> merge(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> result;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) result.push_back(a[i++]);
        else result.push_back(b[j++]);
    }
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);
    return result;
}
```

**Dry Run:**
```
a = [1, 3, 5, 7], b = [2, 4, 6]
     i=0           j=0

i=0,j=0: 1<2 → push 1, i=1    result=[1]
i=1,j=0: 3>2 → push 2, j=1    result=[1,2]
i=1,j=1: 3<4 → push 3, i=2    result=[1,2,3]
i=2,j=1: 5>4 → push 4, j=2    result=[1,2,3,4]
i=2,j=2: 5<6 → push 5, i=3    result=[1,2,3,4,5]
i=3,j=2: 7>6 → push 6, j=3    result=[1,2,3,4,5,6]
j exhausted → push remaining a: 7
Result: [1,2,3,4,5,6,7] ✓
```

---

<a name="section-5"></a>
# SECTION 5: COMPLETE SEARCHING ALGORITHMS

---

## 5.1 Linear Search

### Concept
Scan from left to right until you find the target. Simple but slow for large arrays.

```cpp
int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}
```

### Variations

**Search in 2D Array:**
```cpp
pair<int,int> search2D(vector<vector<int>>& mat, int target) {
    for (int i = 0; i < mat.size(); i++)
        for (int j = 0; j < mat[i].size(); j++)
            if (mat[i][j] == target) return {i, j};
    return {-1, -1};
}
```

**Find All Occurrences:**
```cpp
vector<int> findAll(vector<int>& arr, int target) {
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == target) result.push_back(i);
    return result;
}
```

**Complexity:** Time O(n), Space O(1)
**When to use:** Unsorted array, small n, or when sorting isn't worth it.

---

## 5.2 Binary Search

### Intuition
If the array is sorted, you can **eliminate half the search space** with each comparison. Like finding a word in a dictionary — you open to the middle, determine if the word comes before or after, and repeat.

```
arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
       0  1  2  3  4   5   6   7   8   9

Find 7:
  low=0, high=9, mid=4, arr[4]=9 > 7 → search LEFT half
  low=0, high=3, mid=1, arr[1]=3 < 7 → search RIGHT half
  low=2, high=3, mid=2, arr[2]=5 < 7 → search RIGHT half
  low=3, high=3, mid=3, arr[3]=7 = 7 → FOUND! index=3 ✓

Only 4 comparisons for 10 elements (vs 4 for linear too — but for 1M elements, binary search needs only 20 comparisons!)
```

### Iterative Binary Search

```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Prevents overflow!
        // ⚠️ Never use (low+high)/2 — may overflow for large values

        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;   // Search right
        else high = mid - 1;                          // Search left
    }
    return -1;  // Not found
}
```

**Full Dry Run:**
```
arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
       0  1  2   3   4   5   6   7   8   9

Target = 23

Iteration 1:
  low=0, high=9, mid=4
  arr[4]=16 < 23 → low = 5

Iteration 2:
  low=5, high=9, mid=7
  arr[7]=56 > 23 → high = 6

Iteration 3:
  low=5, high=6, mid=5
  arr[5]=23 = 23 → return 5 ✓
```

### Recursive Binary Search

```cpp
int binarySearchRec(vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;    // Base case: not found

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearchRec(arr, mid+1, high, target);
    else return binarySearchRec(arr, low, mid-1, target);
}
// Call: binarySearchRec(arr, 0, arr.size()-1, target);
```

**Complexity:** Time O(log n), Space O(1) iterative, O(log n) recursive (call stack)

### ⚠️ Common Binary Search Bug: Overflow
```cpp
// WRONG: (low + high) can overflow int
int mid = (low + high) / 2;

// CORRECT: Equivalent but no overflow
int mid = low + (high - low) / 2;
```

---

## 5.3 Binary Search Variants

### Lower Bound — First index where arr[i] >= target

```cpp
// Returns index of first element >= target
// If all elements < target, returns n
int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) low = mid + 1;
        else high = mid;           // arr[mid] >= target
    }
    return low;
}
// Also: lower_bound(arr.begin(), arr.end(), target) - arr.begin()
```

**Dry Run:**
```
arr = [1, 3, 3, 5, 5, 5, 8], target = 5

low=0, high=7
Iter 1: mid=3, arr[3]=5 >= 5 → high=3
Iter 2: mid=1, arr[1]=3 <  5 → low=2
Iter 3: mid=2, arr[2]=3 <  5 → low=3
low=3=high → return 3

arr[3]=5 is the first occurrence ✓
```

### Upper Bound — First index where arr[i] > target

```cpp
// Returns index of first element > target
int upperBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) low = mid + 1;
        else high = mid;
    }
    return low;
}
// Also: upper_bound(arr.begin(), arr.end(), target) - arr.begin()
```

### First and Last Occurrence

```cpp
// First occurrence of target in sorted array
int firstOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;   // Keep searching LEFT for first occurrence
        }
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return result;
}

// Last occurrence of target in sorted array
int lastOccurrence(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            low = mid + 1;    // Keep searching RIGHT for last occurrence
        }
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return result;
}

// Count occurrences
int countOccurrences(vector<int>& arr, int target) {
    int first = firstOccurrence(arr, target);
    if (first == -1) return 0;
    int last = lastOccurrence(arr, target);
    return last - first + 1;
}
```

**Dry Run for First Occurrence:**
```
arr = [1, 3, 3, 3, 5, 5, 8], target = 3

Iter 1: low=0, high=6, mid=3, arr[3]=3=target → result=3, high=2
Iter 2: low=0, high=2, mid=1, arr[1]=3=target → result=1, high=0
Iter 3: low=0, high=0, mid=0, arr[0]=1 < 3  → low=1
low > high → return result=1

arr[1]=3 is the first occurrence ✓
```

### Floor and Ceil

```cpp
// Floor: largest element <= target
int floor(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            result = arr[mid];  // Candidate for floor
            low = mid + 1;      // Try to find larger candidate
        }
        else high = mid - 1;
    }
    return result;
}

// Ceil: smallest element >= target
int ceil(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            result = arr[mid];  // Candidate for ceil
            high = mid - 1;     // Try to find smaller candidate
        }
        else low = mid + 1;
    }
    return result;
}
```

### Search in Rotated Sorted Array

```cpp
// Array was sorted then rotated at some pivot
// e.g., [4,5,6,7,0,1,2] is [0,1,2,4,5,6,7] rotated

int searchRotated(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;

        // Check which half is sorted
        if (arr[low] <= arr[mid]) {  // Left half is sorted
            if (arr[low] <= target && target < arr[mid])
                high = mid - 1;     // Target in left half
            else
                low = mid + 1;      // Target in right half
        } else {                     // Right half is sorted
            if (arr[mid] < target && target <= arr[high])
                low = mid + 1;      // Target in right half
            else
                high = mid - 1;     // Target in left half
        }
    }
    return -1;
}
```

**Dry Run:**
```
arr = [4, 5, 6, 7, 0, 1, 2], target = 0

Iter 1: low=0, high=6, mid=3, arr[3]=7 ≠ 0
  Left half [4,5,6,7] is sorted (arr[0]=4 ≤ arr[3]=7)
  Is 0 in [4,7]? No → low = 4

Iter 2: low=4, high=6, mid=5, arr[5]=1 ≠ 0
  Left half [0,1] is sorted (arr[4]=0 ≤ arr[5]=1)
  Is 0 in [0,1)? Yes (0>=0 and 0<1) → high = 4

Iter 3: low=4, high=4, mid=4, arr[4]=0 = 0 → return 4 ✓
```

### Peak Element — Binary Search

```cpp
// Find any peak: arr[i] > arr[i-1] and arr[i] > arr[i+1]
// Key insight: if arr[mid] < arr[mid+1], peak must be to the right

int findPeakElement(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[mid + 1])
            low = mid + 1;   // Peak is in right half
        else
            high = mid;      // Peak is in left half (or at mid)
    }
    return low;  // low == high, pointing at peak
}
```

### Binary Search on Answer (Concept)

Sometimes we binary search on the **answer space** rather than array index:

```cpp
// Template: Binary search on answer
// When: "Find minimum/maximum value such that condition holds"
// Condition must be monotonic (false...false...true...true OR vice versa)

int binarySearchOnAnswer(/* params */) {
    int low = MIN_POSSIBLE_ANSWER;
    int high = MAX_POSSIBLE_ANSWER;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(mid)) {   // Check if 'mid' as answer is feasible
            result = mid;
            high = mid - 1;     // Try smaller (for minimum)
            // or low = mid+1;  // Try larger (for maximum)
        } else {
            low = mid + 1;      // or high = mid - 1
        }
    }
    return result;
}
```

**Example: Koko Eating Bananas**
```cpp
// Koko must eat all bananas in h hours
// Each hour she eats k bananas from one pile
// Find minimum k

bool canEatInTime(vector<int>& piles, int h, int k) {
    long long hours = 0;
    for (int pile : piles) hours += (pile + k - 1) / k;  // ceil(pile/k)
    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canEatInTime(piles, h, mid)) {
            result = mid;
            high = mid - 1;  // Try slower speed
        } else {
            low = mid + 1;   // Need faster speed
        }
    }
    return result;
}
```

---

<a name="section-6"></a>
# SECTION 6: ALL ARRAY PATTERNS

---

## 6.1 HOW TO IDENTIFY PATTERNS

When you see a new problem, ask these questions:

```
1. What are we looking for?
   - Subarray? → Prefix Sum, Sliding Window, Kadane
   - Pair? → Two Pointers, Hashing
   - Count? → Hashing, Frequency Array
   - Min/Max? → Greedy, Binary Search on Answer

2. Is the array sorted?
   - Yes → Binary Search, Two Pointers
   - No but can sort? → Sort-based approach

3. What type of query?
   - Range sum? → Prefix Sum
   - Subarray max/min? → Monotonic Queue / Segment Tree
   - Next greater element? → Monotonic Stack

4. What is the constraint?
   - O(n)? → Single Pass patterns
   - O(n log n)? → Sorting-based
   - Missing/duplicate? → Cyclic Sort, XOR tricks
```

---

## Pattern 1: Traversal Problems

**Key Idea:** Visit each element, do some computation.

**Template:**
```cpp
for (int i = 0; i < n; i++) {
    // process arr[i]
}
```

### Problem 1: Find Maximum Element
```cpp
int findMax(vector<int>& arr) {
    int maxVal = INT_MIN;
    for (int x : arr) maxVal = max(maxVal, x);
    return maxVal;
}
// Time: O(n), Space: O(1)
```

### Problem 2: Find Second Maximum
```cpp
int secondMax(vector<int>& arr) {
    int first = INT_MIN, second = INT_MIN;
    for (int x : arr) {
        if (x > first) { second = first; first = x; }
        else if (x > second && x != first) second = x;
    }
    return second;
}
```

### Problem 3: Count Negative Numbers
```cpp
int countNeg(vector<int>& arr) {
    int count = 0;
    for (int x : arr) if (x < 0) count++;
    return count;
}
```

### Problem 4: Check Sorted Array
```cpp
bool isSorted(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] < arr[i-1]) return false;
    return true;
}
```

### Problem 5: Move Zeros to End
```cpp
void moveZeros(vector<int>& arr) {
    int pos = 0;
    for (int x : arr) if (x != 0) arr[pos++] = x;
    while (pos < arr.size()) arr[pos++] = 0;
}
// Dry run: [0,1,0,3,12] → pos tracks next non-zero position
// After pass: [1,3,12,3,12], then fill zeros: [1,3,12,0,0]
```

### Problem 6: Product of All Elements
```cpp
long long product(vector<int>& arr) {
    long long prod = 1;
    for (int x : arr) prod *= x;
    return prod;
}
```

### Problem 7: Sum of Even-Indexed Elements
```cpp
int sumEvenIdx(vector<int>& arr) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i += 2) sum += arr[i];
    return sum;
}
```

### Problem 8: Find All Leaders (elements greater than all to their right)
```cpp
vector<int> leaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> result = {arr[n-1]};  // Last is always leader
    int maxRight = arr[n-1];
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > maxRight) {
            result.push_back(arr[i]);
            maxRight = arr[i];
        }
    }
    reverse(result.begin(), result.end());
    return result;
}
```

### Problem 9: Find Element Appearing More Than n/2 Times (Moore Voting)
```cpp
int majorityElement(vector<int>& arr) {
    int candidate = arr[0], count = 1;
    for (int i = 1; i < arr.size(); i++) {
        if (count == 0) { candidate = arr[i]; count = 1; }
        else if (arr[i] == candidate) count++;
        else count--;
    }
    return candidate;
}
```

### Problem 10: Rotate Array by k
```cpp
void rotate(vector<int>& arr, int k) {
    int n = arr.size();
    k %= n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k, arr.end());
}
```

**LeetCode Problems for Traversal:** #1 (Two Sum), #26 (Remove Duplicates), #27 (Remove Element), #66 (Plus One), #88 (Merge Sorted Array), #121 (Best Time to Buy Stock), #169 (Majority Element), #189 (Rotate Array), #268 (Missing Number), #283 (Move Zeroes)

---

## Pattern 2: Frequency Counting

**Key Idea:** Count occurrences using a hash map or frequency array.

**When to use:**
- "How many times does X appear?"
- "Find the most/least frequent element"
- "Check if two arrays are anagrams"
- Count inversions, duplicates

**Template:**
```cpp
unordered_map<int, int> freq;
for (int x : arr) freq[x]++;

// Or if values in [0, MAX]:
vector<int> freq(MAX+1, 0);
for (int x : arr) freq[x]++;
```

### Problem 1: Most Frequent Element
```cpp
int mostFrequent(vector<int>& arr) {
    unordered_map<int,int> freq;
    for (int x : arr) freq[x]++;
    int maxFreq = 0, result = arr[0];
    for (auto& [val, cnt] : freq) {
        if (cnt > maxFreq) { maxFreq = cnt; result = val; }
    }
    return result;
}
```

### Problem 2: Find All Duplicates in Array (Values 1 to n)
```cpp
// LeetCode 442: O(n) time, O(1) space using negative marking
vector<int> findDuplicates(vector<int>& arr) {
    vector<int> result;
    for (int x : arr) {
        int idx = abs(x) - 1;
        if (arr[idx] < 0) result.push_back(abs(x));
        else arr[idx] = -arr[idx];
    }
    return result;
}
```

### Problem 3: First Non-Repeating Element
```cpp
int firstNonRepeating(vector<int>& arr) {
    unordered_map<int,int> freq;
    for (int x : arr) freq[x]++;
    for (int x : arr) if (freq[x] == 1) return x;
    return -1;
}
```

### Problem 4: Check Array Has Equal Number of 0s and 1s
```cpp
bool equalZerosOnes(vector<int>& arr) {
    int count = 0;
    for (int x : arr) count += (x == 1) ? 1 : -1;
    return count == 0;
}
```

### Problem 5: Group Anagrams Together
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& [k, v] : groups) result.push_back(v);
    return result;
}
```

### Problem 6: Top K Frequent Elements
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;
    vector<pair<int,int>> v(freq.begin(), freq.end());
    sort(v.begin(), v.end(), [](auto& a, auto& b){ return a.second > b.second; });
    vector<int> result;
    for (int i = 0; i < k; i++) result.push_back(v[i].first);
    return result;
}
// Time: O(n log n)
```

### Problem 7: Intersection of Two Arrays
```cpp
vector<int> intersect(vector<int>& a, vector<int>& b) {
    unordered_map<int,int> freq;
    for (int x : a) freq[x]++;
    vector<int> result;
    for (int x : b) {
        if (freq.count(x) && freq[x] > 0) {
            result.push_back(x);
            freq[x]--;
        }
    }
    return result;
}
```

### Problem 8: Subarray Sum Equals K (using frequency)
```cpp
// LeetCode 560
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> prefixCount;
    prefixCount[0] = 1;
    int sum = 0, count = 0;
    for (int x : nums) {
        sum += x;
        if (prefixCount.count(sum - k))
            count += prefixCount[sum - k];
        prefixCount[sum]++;
    }
    return count;
}
// Key insight: if prefix[j] - prefix[i] = k, then subarray [i+1..j] sums to k
```

### Problem 9: Longest Consecutive Sequence
```cpp
// LeetCode 128
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int longest = 0;
    for (int x : nums) {
        if (!s.count(x - 1)) {  // Start of a sequence
            int len = 1;
            while (s.count(x + len)) len++;
            longest = max(longest, len);
        }
    }
    return longest;
}
// Time: O(n), Space: O(n)
```

### Problem 10: Count Subarrays with Sum Divisible by K
```cpp
int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    freq[0] = 1;
    int sum = 0, count = 0;
    for (int x : nums) {
        sum = ((sum + x) % k + k) % k;  // Handle negative numbers
        count += freq[sum];
        freq[sum]++;
    }
    return count;
}
```

**LeetCode Problems for Frequency Counting:** #1 (Two Sum), #217 (Contains Duplicate), #219 (Contains Duplicate II), #242 (Valid Anagram), #347 (Top K Frequent), #349 (Intersection of Arrays), #387 (First Unique Character), #448 (Find Disappeared Numbers), #451 (Sort by Frequency), #560 (Subarray Sum Equals K)

---

## Pattern 3: Prefix Sum

**Key Idea:** Precompute cumulative sums so range sum queries become O(1).

**When to use:**
- Range sum queries
- Subarray problems
- Count subarrays with certain sum/property
- 2D range queries

```
arr     = [1,  2,  3,  4,  5]
prefix  = [0,  1,  3,  6, 10, 15]  (prefix[0]=0 for convenience)
           ↑
         prefix[i] = sum of arr[0..i-1]

Sum of arr[l..r] = prefix[r+1] - prefix[l]
```

### Building Prefix Sum
```cpp
vector<int> buildPrefix(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
        prefix[i+1] = prefix[i] + arr[i];
    return prefix;
}

// Range sum query [l, r] (0-indexed)
int rangeSum(vector<int>& prefix, int l, int r) {
    return prefix[r+1] - prefix[l];
}
```

**Dry Run:**
```
arr = [3, 5, 2, 8, 1, 4]

prefix[0] = 0
prefix[1] = 0 + 3 = 3
prefix[2] = 3 + 5 = 8
prefix[3] = 8 + 2 = 10
prefix[4] = 10 + 8 = 18
prefix[5] = 18 + 1 = 19
prefix[6] = 19 + 4 = 23

Query: sum of arr[2..4] = prefix[5] - prefix[2] = 19 - 8 = 11
Verify: 2 + 8 + 1 = 11 ✓
```

### Problem 1: Range Sum Query
```cpp
class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n+1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];
    }
    int sumRange(int l, int r) { return prefix[r+1] - prefix[l]; }
};
// LeetCode 303 — After O(n) build, each query is O(1)
```

### Problem 2: Equilibrium Index
```cpp
// Index i where sum of left = sum of right
int equilibrium(vector<int>& arr) {
    int n = arr.size();
    int total = 0;
    for (int x : arr) total += x;
    int leftSum = 0;
    for (int i = 0; i < n; i++) {
        int rightSum = total - leftSum - arr[i];
        if (leftSum == rightSum) return i;
        leftSum += arr[i];
    }
    return -1;
}
```

### Problem 3: Maximum Subarray Sum Using Prefix
```cpp
// O(n^2) using prefix (Kadane's is O(n) — see later)
int maxSubarraySum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n+1, 0);
    for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + arr[i];

    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            maxSum = max(maxSum, prefix[j+1] - prefix[i]);
    return maxSum;
}
```

### Problem 4: Subarray Sum Equals K (Count)
```cpp
// LeetCode 560 — covered in frequency counting
// Key: use prefix sum + hash map
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> count;
    count[0] = 1;
    int sum = 0, result = 0;
    for (int x : nums) {
        sum += x;
        result += count[sum - k];
        count[sum]++;
    }
    return result;
}
```

### Problem 5: Difference Array (Range Update in O(1))
```cpp
// Problem: Add v to every element in range [l, r], do this m times
// Naive: O(n) per update → O(nm) total
// Difference Array: O(1) per update, O(n) to reconstruct

// Build difference array
vector<int> diff(n+1, 0);

// Update: add v to arr[l..r]
void update(vector<int>& diff, int l, int r, int v) {
    diff[l] += v;
    diff[r+1] -= v;
}

// Reconstruct array after all updates
vector<int> reconstruct(vector<int>& diff) {
    vector<int> arr(diff.size());
    arr[0] = diff[0];
    for (int i = 1; i < diff.size(); i++)
        arr[i] = arr[i-1] + diff[i];
    return arr;
}
```

**Dry Run for Difference Array:**
```
n=6, initial arr = [0, 0, 0, 0, 0, 0]

Query 1: Add 5 to [1, 3]  → diff: [0, 5, 0, 0, -5, 0, 0]
Query 2: Add 3 to [2, 5]  → diff: [0, 5, 3, 0, -5, 0, -3]
Query 3: Add -2 to [0, 2] → diff: [-2, 5, 3, 2, -5, 0, -3]

Reconstruct (prefix sum of diff):
arr[0] = -2
arr[1] = -2 + 5 = 3
arr[2] = 3 + 3 = 6
arr[3] = 6 + 2 = 8
arr[4] = 8 + (-5) = 3
arr[5] = 3 + 0 = 3

Result: [-2, 3, 6, 8, 3, 3]

Verify query 1 (add 5 to [1,3]): indices 1,2,3 increased by 5 ✓
```

### Problem 6: 2D Prefix Sum
```cpp
// Build 2D prefix sum
int n = mat.size(), m = mat[0].size();
vector<vector<int>> prefix(n+1, vector<int>(m+1, 0));

for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];

// Sum of submatrix (r1,c1) to (r2,c2) (0-indexed)
int submatrixSum(int r1, int c1, int r2, int c2) {
    return prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
}
// LeetCode 304
```

### Problem 7: Longest Subarray with Sum = K (for non-negative)
```cpp
// Using sliding window for non-negative
// Using prefix + hashmap for any integers
int longestSubarraySum(vector<int>& arr, int k) {
    unordered_map<int,int> firstOcc;
    firstOcc[0] = -1;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (firstOcc.count(sum - k))
            maxLen = max(maxLen, i - firstOcc[sum - k]);
        if (!firstOcc.count(sum))
            firstOcc[sum] = i;  // Store first occurrence only
    }
    return maxLen;
}
```

**LeetCode for Prefix Sum:** #303 (Range Sum Query), #304 (2D Range Sum), #525 (Contiguous Array), #560 (Subarray Sum = K), #974 (Subarrays Divisible by K), #1004, #1248, #1480 (Running Sum)

---

## Pattern 4: Sliding Window

**Key Idea:** Maintain a "window" (subarray) that slides through the array, adding from right and removing from left.

**When to use:**
- "Longest/shortest subarray with property P"
- "Maximum/minimum sum of subarray of size k"
- All subarrays of specific size

### Fixed Size Window

```
Window size = k = 3
arr = [1, 2, 3, 4, 5, 6, 7]
       [1, 2, 3]              sum = 6
          [2, 3, 4]           sum = 9
             [3, 4, 5]        sum = 12
                [4, 5, 6]     sum = 15
                   [5, 6, 7]  sum = 18  ← Maximum
```

```cpp
// Maximum sum subarray of size k
int maxSumK(vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) return -1;

    // Build first window
    int windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += arr[i];

    int maxSum = windowSum;

    // Slide the window
    for (int i = k; i < n; i++) {
        windowSum += arr[i];      // Add new element
        windowSum -= arr[i - k];  // Remove old element
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
// Time: O(n), Space: O(1)
```

**Dry Run:**
```
arr = [2, 3, 4, 1, 5], k = 3

Initial window [0..2]: sum = 2+3+4 = 9, maxSum = 9

i=3: sum = 9 + 1 - 2 = 8, maxSum = 9
i=4: sum = 8 + 5 - 3 = 10, maxSum = 10

Answer: 10 (window [3,4,5] = 4+1+5=10... wait let me re-check)
[4,1,5] = 10 ✓
```

### Variable Size Window

```cpp
// Longest subarray with sum <= k (all non-negative)
int longestSubarraySumLeK(vector<int>& arr, int k) {
    int left = 0, sum = 0, maxLen = 0;
    for (int right = 0; right < arr.size(); right++) {
        sum += arr[right];
        while (sum > k) {    // Shrink window from left
            sum -= arr[left];
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

**Variable Window Template:**
```cpp
int left = 0, result = 0;
// (some state variable)
for (int right = 0; right < n; right++) {
    // Expand window: add arr[right]

    while (/* window is invalid */) {
        // Shrink: remove arr[left]
        left++;
    }
    // Update result with current valid window
    result = max(result, right - left + 1);
}
```

### Key Problems

### Problem 1: Max Sum Subarray of Size K
*(Covered above)*

### Problem 2: Longest Substring Without Repeating Characters
```cpp
// LeetCode 3
int lengthOfLongestSubstring(string s) {
    unordered_set<char> window;
    int left = 0, maxLen = 0;
    for (int right = 0; right < s.size(); right++) {
        while (window.count(s[right]))
            window.erase(s[left++]);
        window.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

### Problem 3: Minimum Size Subarray Sum >= target
```cpp
// LeetCode 209
int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, sum = 0, minLen = INT_MAX;
    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];
        while (sum >= target) {
            minLen = min(minLen, right - left + 1);
            sum -= nums[left++];
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}
```

### Problem 4: Fruit Into Baskets (At Most 2 Types)
```cpp
// LeetCode 904: Longest subarray with at most 2 distinct values
int totalFruit(vector<int>& fruits) {
    unordered_map<int,int> basket;
    int left = 0, maxLen = 0;
    for (int right = 0; right < fruits.size(); right++) {
        basket[fruits[right]]++;
        while (basket.size() > 2) {
            basket[fruits[left]]--;
            if (basket[fruits[left]] == 0) basket.erase(fruits[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

### Problem 5: Sliding Window Maximum (deque)
```cpp
// LeetCode 239: Max in every window of size k
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;  // Stores indices, front = max
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        // Remove elements outside window
        while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
        // Remove smaller elements from back
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}
// Time: O(n), each element pushed/popped at most once
```

**Dry Run for Sliding Window Max:**
```
nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3

i=0: dq=[0], window not full
i=1: nums[0]=1<3, pop 0, dq=[1], not full
i=2: dq=[1,2], i>=k-1, result=[nums[1]]=[3]
i=3: nums[2]=-1>-3, dq=[1,2,3], result=[3,nums[1]]=[3,3]
i=4: dq.front()=1<i-k+1=2, pop front, nums[2]=-1<5,pop,nums[3]=-3<5,pop
     dq=[4], result=[3,3,5]
i=5: nums[4]=5>3, dq=[4,5], result=[3,3,5,5]
i=6: dq.front()=4>=i-k+1=4 (ok), nums[5]=3<6,pop, dq=[4,6]
     wait — nums[4]=5<6, pop 4 too, dq=[6], result=[3,3,5,5,6]
i=7: nums[6]=6<7, pop, dq=[7], result=[3,3,5,5,6,7]

Answer: [3,3,5,3,6,7]
```

### Problem 6: Longest Subarray with Ones After Deleting One Zero
```cpp
// LeetCode 1004 variant
int longestSubarray(vector<int>& nums) {
    int left = 0, zeros = 0, maxLen = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zeros++;
        while (zeros > 1) {
            if (nums[left] == 0) zeros--;
            left++;
        }
        maxLen = max(maxLen, right - left);  // -1 for the deleted zero
    }
    return maxLen;
}
```

### Problem 7: Count Subarrays with Exactly K Ones
```cpp
// Trick: exactly k = at most k - at most (k-1)
int atMostK(vector<int>& arr, int k) {
    int left = 0, ones = 0, count = 0;
    for (int right = 0; right < arr.size(); right++) {
        if (arr[right] == 1) ones++;
        while (ones > k) {
            if (arr[left] == 1) ones--;
            left++;
        }
        count += right - left + 1;
    }
    return count;
}

int exactlyK(vector<int>& arr, int k) {
    return atMostK(arr, k) - atMostK(arr, k - 1);
}
// LeetCode 930
```

### Problem 8: Permutation in String
```cpp
// LeetCode 567: Check if s1's permutation is in s2
bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    vector<int> need(26, 0), have(26, 0);
    for (char c : s1) need[c-'a']++;
    int k = s1.size();
    for (int i = 0; i < s2.size(); i++) {
        have[s2[i]-'a']++;
        if (i >= k) have[s2[i-k]-'a']--;
        if (have == need) return true;
    }
    return false;
}
```

**LeetCode for Sliding Window:** #3, #76, #121, #209, #219, #239, #424, #438, #567, #643, #713, #904, #930, #992, #1004, #1052, #1208, #1248, #1343, #1423, #1456

---

## Pattern 5: Two Pointers

**Key Idea:** Use two indices that move toward each other (or in same direction) to avoid nested loops.

### Type 1: Opposite Direction (Sorted Array)

```cpp
// Template
int left = 0, right = n - 1;
while (left < right) {
    if (/* condition */) {
        // process
    } else if (/* too small */) {
        left++;
    } else {
        right--;
    }
}
```

### Problem 1: Two Sum in Sorted Array
```cpp
// LeetCode 167
vector<int> twoSum(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == target) return {l+1, r+1};
        else if (sum < target) l++;
        else r--;
    }
    return {};
}
```

**Dry Run:**
```
nums = [2, 7, 11, 15], target = 9
l=0, r=3: 2+15=17 > 9 → r=2
l=0, r=2: 2+11=13 > 9 → r=1
l=0, r=1: 2+7=9 = 9 → return [1,2] ✓
```

### Problem 2: Three Sum
```cpp
// LeetCode 15: All unique triplets summing to 0
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();
    for (int i = 0; i < n-2; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;  // Skip duplicates
        int l = i+1, r = n-1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                result.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l+1]) l++;
                while (l < r && nums[r] == nums[r-1]) r--;
                l++; r--;
            } else if (sum < 0) l++;
            else r--;
        }
    }
    return result;
}
// Time: O(n^2), Space: O(1)
```

### Problem 3: Container With Most Water
```cpp
// LeetCode 11
int maxArea(vector<int>& height) {
    int l = 0, r = height.size()-1, maxWater = 0;
    while (l < r) {
        int h = min(height[l], height[r]);
        maxWater = max(maxWater, h * (r - l));
        if (height[l] < height[r]) l++;
        else r--;
    }
    return maxWater;
}
// Intuition: Move the shorter side inward (it can only help)
```

### Problem 4: Remove Duplicates from Sorted Array
```cpp
// LeetCode 26
int removeDuplicates(vector<int>& nums) {
    int slow = 1;
    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[fast-1]) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}
```

### Type 2: Same Direction (Fast-Slow)

### Problem 5: Detect Cycle in Array (Floyd's)
```cpp
// Detect cycle using slow/fast pointer
bool hasCycle(vector<int>& nums) {
    int slow = nums[0], fast = nums[nums[0]];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    return true;
}
```

### Problem 6: Dutch National Flag (3-way partition)
```cpp
// LeetCode 75: Sort array of 0s, 1s, 2s
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size()-1;
    while (mid <= high) {
        if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
        else if (nums[mid] == 1) mid++;
        else swap(nums[mid], nums[high--]);
    }
}
// Dry run: [2,0,2,1,1,0]
// low=0, mid=0, high=5
// nums[0]=2: swap(mid,high) → [0,0,2,1,1,2], high=4
// nums[0]=0: swap(low,mid) → [0,0,2,1,1,2], low=1,mid=1
// nums[1]=0: swap(low,mid) → same, low=2,mid=2
// nums[2]=2: swap(mid,high) → [0,0,1,1,2,2], high=3
// nums[2]=1: mid++, mid=3
// nums[3]=1: mid++, mid=4, mid>high → DONE
// Result: [0,0,1,1,2,2] ✓
```

### Problem 7: Squares of Sorted Array
```cpp
// LeetCode 977: [-4,-1,0,3,10] → [0,1,9,16,100]
vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    int l = 0, r = n-1, pos = n-1;
    while (l <= r) {
        if (abs(nums[l]) > abs(nums[r]))
            result[pos--] = nums[l] * nums[l++];
        else
            result[pos--] = nums[r] * nums[r--];
    }
    return result;
}
```

### Problem 8: Trapping Rain Water (Two Pointers)
```cpp
// LeetCode 42
int trap(vector<int>& height) {
    int l = 0, r = height.size()-1;
    int leftMax = 0, rightMax = 0, water = 0;
    while (l < r) {
        if (height[l] <= height[r]) {
            if (height[l] >= leftMax) leftMax = height[l];
            else water += leftMax - height[l];
            l++;
        } else {
            if (height[r] >= rightMax) rightMax = height[r];
            else water += rightMax - height[r];
            r--;
        }
    }
    return water;
}
// Intuition: Water at position i = min(maxLeft, maxRight) - height[i]
```

**LeetCode for Two Pointers:** #11, #15, #16, #26, #27, #42, #75, #80, #125, #141, #151, #167, #283, #344, #345, #392, #443, #680, #713, #977, #1498, #1679

---

## Pattern 6: Hashing

**Key Idea:** Use hash map/set for O(1) lookup, eliminate brute-force nested loops.

### Problem 1: Two Sum (Classic)
```cpp
// LeetCode 1
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> seen;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.count(complement)) return {seen[complement], i};
        seen[nums[i]] = i;
    }
    return {};
}
// Time: O(n), Space: O(n)
// Key insight: for each element, check if its complement exists
```

### Problem 2: Longest Subarray with Equal 0s and 1s
```cpp
// LeetCode 525: Replace 0 with -1, find longest subarray with sum=0
int findMaxLength(vector<int>& nums) {
    unordered_map<int,int> firstOcc;
    firstOcc[0] = -1;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += (nums[i] == 1) ? 1 : -1;
        if (firstOcc.count(sum))
            maxLen = max(maxLen, i - firstOcc[sum]);
        else
            firstOcc[sum] = i;
    }
    return maxLen;
}
```

### Problem 3: 4Sum Count
```cpp
// LeetCode 454: Count tuples (i,j,k,l) with A[i]+B[j]+C[k]+D[l]=0
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int,int> sumAB;
    for (int a : A) for (int b : B) sumAB[a+b]++;
    int count = 0;
    for (int c : C) for (int d : D) count += sumAB[-(c+d)];
    return count;
}
// Time: O(n^2), much better than O(n^4) brute force
```

### Problem 4: Isomorphic Strings
```cpp
// LeetCode 205
bool isIsomorphic(string s, string t) {
    unordered_map<char,char> sToT, tToS;
    for (int i = 0; i < s.size(); i++) {
        if (sToT.count(s[i]) && sToT[s[i]] != t[i]) return false;
        if (tToS.count(t[i]) && tToS[t[i]] != s[i]) return false;
        sToT[s[i]] = t[i];
        tToS[t[i]] = s[i];
    }
    return true;
}
```

### Problem 5: Subarray Sum Divisible by K
```cpp
// LeetCode 974
int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int,int> remFreq;
    remFreq[0] = 1;
    int sum = 0, count = 0;
    for (int x : nums) {
        sum = ((sum + x) % k + k) % k;
        count += remFreq[sum]++;
    }
    return count;
}
```

**LeetCode for Hashing:** #1, #36, #49, #128, #136, #149, #202, #205, #217, #219, #242, #290, #347, #380, #387, #389, #409, #451, #454, #525, #560, #594, #599, #705, #706

---

## Pattern 7: Sorting Based Problems

**Key Idea:** Sort first, then solve more easily.

### Problem 1: Merge Intervals
```cpp
// LeetCode 56
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result = {intervals[0]};
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= result.back()[1])
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        else
            result.push_back(intervals[i]);
    }
    return result;
}
// Time: O(n log n) for sort, O(n) for merge
```

**Dry Run:**
```
intervals = [[1,3],[2,6],[8,10],[15,18]]

After sort (already sorted):
result = [[1,3]]

i=1: [2,6]: 2 <= 3 → merge: result = [[1,6]]
i=2: [8,10]: 8 > 6 → add: result = [[1,6],[8,10]]
i=3: [15,18]: 15 > 10 → add: result = [[1,6],[8,10],[15,18]]
```

### Problem 2: Insert Interval
```cpp
// LeetCode 57
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int i = 0, n = intervals.size();
    // Add all intervals before new interval
    while (i < n && intervals[i][1] < newInterval[0])
        result.push_back(intervals[i++]);
    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);
    // Add remaining intervals
    while (i < n) result.push_back(intervals[i++]);
    return result;
}
```

### Problem 3: Largest Number
```cpp
// LeetCode 179: Form largest number from array
string largestNumber(vector<int>& nums) {
    vector<string> strs;
    for (int x : nums) strs.push_back(to_string(x));
    sort(strs.begin(), strs.end(), [](string& a, string& b){
        return a + b > b + a;   // Custom comparator
    });
    if (strs[0] == "0") return "0";
    string result = "";
    for (string s : strs) result += s;
    return result;
}
// Insight: Compare "3"+"30" vs "30"+"3" = 330 vs 303 → "3" should come first
```

### Problem 4: Meeting Rooms II
```cpp
// LeetCode 253: Minimum rooms needed
int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<int> start, end;
    for (auto& i : intervals) { start.push_back(i[0]); end.push_back(i[1]); }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int rooms = 0, endPtr = 0;
    for (int s : start) {
        if (s < end[endPtr]) rooms++;
        else endPtr++;
    }
    return rooms;
}
```

**LeetCode for Sorting:** #56, #57, #75, #147, #148, #164, #179, #215, #252, #253, #280, #324, #347, #406, #435, #452, #493, #539, #561, #621

---

## Pattern 8: Binary Search on Arrays

*(Building on Section 5)*

### Problem 1: Kth Smallest in Sorted Matrix
```cpp
// LeetCode 378
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0], high = matrix[n-1][n-1];
    while (low < high) {
        int mid = low + (high - low) / 2;
        // Count elements <= mid
        int count = 0;
        int j = n-1;
        for (int i = 0; i < n; i++) {
            while (j >= 0 && matrix[i][j] > mid) j--;
            count += j + 1;
        }
        if (count < k) low = mid + 1;
        else high = mid;
    }
    return low;
}
```

### Problem 2: Find Minimum in Rotated Sorted Array
```cpp
// LeetCode 153
int findMin(vector<int>& nums) {
    int low = 0, high = nums.size()-1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high]) low = mid + 1;  // Min in right half
        else high = mid;                              // Min in left half (or mid)
    }
    return nums[low];
}
```

### Problem 3: Split Array Largest Sum
```cpp
// LeetCode 410: Split into m subarrays, minimize the largest sum
bool canSplit(vector<int>& nums, int m, long long maxSum) {
    int parts = 1;
    long long current = 0;
    for (int x : nums) {
        if (current + x > maxSum) { parts++; current = x; }
        else current += x;
        if (parts > m) return false;
    }
    return true;
}

int splitArray(vector<int>& nums, int m) {
    long long low = *max_element(nums.begin(), nums.end());
    long long high = 0;
    for (int x : nums) high += x;
    while (low < high) {
        long long mid = low + (high - low) / 2;
        if (canSplit(nums, m, mid)) high = mid;
        else low = mid + 1;
    }
    return low;
}
```

**LeetCode for Binary Search:** #33, #34, #35, #69, #74, #81, #153, #162, #240, #275, #278, #374, #378, #410, #436, #540, #658, #702, #704, #875

---

## Pattern 9: Greedy Array Problems

**Key Idea:** Make locally optimal choice at each step, hoping it leads to global optimum.

### Problem 1: Jump Game
```cpp
// LeetCode 55: Can you reach the last index?
bool canJump(vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false;   // Can't reach here
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}
// Intuition: Track the farthest index reachable so far
```

### Problem 2: Jump Game II (Minimum Jumps)
```cpp
// LeetCode 45
int jump(vector<int>& nums) {
    int jumps = 0, curEnd = 0, farthest = 0;
    for (int i = 0; i < nums.size()-1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == curEnd) {
            jumps++;
            curEnd = farthest;
        }
    }
    return jumps;
}
```

### Problem 3: Gas Station
```cpp
// LeetCode 134: Find starting station for circular route
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, tank = 0, start = 0;
    for (int i = 0; i < gas.size(); i++) {
        int gain = gas[i] - cost[i];
        totalGas += gain;
        tank += gain;
        if (tank < 0) {   // Can't continue from current start
            start = i + 1;
            tank = 0;
        }
    }
    return totalGas >= 0 ? start : -1;
}
```

### Problem 4: Assign Cookies
```cpp
// LeetCode 455
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child = 0, cookie = 0;
    while (child < g.size() && cookie < s.size()) {
        if (s[cookie] >= g[child]) child++;
        cookie++;
    }
    return child;
}
```

### Problem 5: Non-overlapping Intervals
```cpp
// LeetCode 435: Min removals to make intervals non-overlapping
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
        return a[1] < b[1];  // Sort by end time
    });
    int count = 0, lastEnd = INT_MIN;
    for (auto& interval : intervals) {
        if (interval[0] >= lastEnd) lastEnd = interval[1];
        else count++;   // Overlap, remove this interval
    }
    return count;
}
```

**LeetCode for Greedy:** #45, #55, #122, #134, #135, #253, #330, #376, #392, #406, #435, #452, #455, #605, #621, #649, #678, #714, #763, #1005

---

## Pattern 10: Monotonic Stack

**Key Idea:** Maintain a stack where elements are always in monotonic (increasing or decreasing) order.

**When to use:**
- "Next Greater/Smaller Element"
- "Previous Greater/Smaller Element"
- Span, range problems

```
Monotonic Increasing Stack: bottom → top is increasing
If new element breaks order, pop until it doesn't

Example for Next Greater Element:
arr = [4, 5, 2, 25]

i=0: push 4  → stack=[4]
i=1: 5>4, pop 4 (nextGreater[4]=5), push 5 → stack=[5]
i=2: 2<5, push 2 → stack=[5,2]
i=3: 25>2, pop 2 (nextGreater[2]=25)
        25>5, pop 5 (nextGreater[5]=25), push 25 → stack=[25]
Remaining: nextGreater[25]=-1

Result: [5, 25, 25, -1]
```

```cpp
// Next Greater Element
vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;  // Store indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}
```

### Problem 1: Next Greater Element II (Circular)
```cpp
// LeetCode 503
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;
    for (int i = 0; i < 2*n; i++) {  // Traverse twice for circular
        while (!st.empty() && nums[st.top()] < nums[i%n]) {
            result[st.top()] = nums[i%n];
            st.pop();
        }
        if (i < n) st.push(i);
    }
    return result;
}
```

### Problem 2: Largest Rectangle in Histogram
```cpp
// LeetCode 84: Classic monotonic stack problem
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    heights.push_back(0);  // Sentinel to flush stack at end
    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int h = heights[st.top()]; st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        st.push(i);
    }
    return maxArea;
}
```

**Dry Run:**
```
heights = [2, 1, 5, 6, 2, 3]

i=0: push 0 → st=[0]
i=1: h[0]=2 > h[1]=1 → pop 0, h=2, w=1(st empty), area=2*1=2; push 1 → st=[1]
i=2: 1<5, push 2 → st=[1,2]
i=3: 5<6, push 3 → st=[1,2,3]
i=4: h[3]=6>2, pop: h=6, w=4-2-1=1, area=6; h[2]=5>2, pop: h=5, w=4-1-1=2, area=10;
     1<2, push 4 → st=[1,4]
i=5: 2<3, push 5 → st=[1,4,5]
End (sentinel 0):
     h[5]=3>0, pop: h=3,w=6-4-1=1, area=3
     h[4]=2>0, pop: h=2,w=6-1-1=4, area=8
     h[1]=1>0, pop: h=1,w=6, area=6
maxArea = 10 ✓
```

### Problem 3: Trapping Rain Water (Stack-based)
```cpp
// LeetCode 42
int trap(vector<int>& height) {
    stack<int> st;
    int water = 0;
    for (int i = 0; i < height.size(); i++) {
        while (!st.empty() && height[st.top()] < height[i]) {
            int bottom = height[st.top()]; st.pop();
            if (st.empty()) break;
            int h = min(height[st.top()], height[i]) - bottom;
            int w = i - st.top() - 1;
            water += h * w;
        }
        st.push(i);
    }
    return water;
}
```

### Problem 4: Daily Temperatures
```cpp
// LeetCode 739: Days until warmer temperature
vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> result(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && T[st.top()] < T[i]) {
            result[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    return result;
}
```

### Problem 5: Stock Span Problem
```cpp
// Number of consecutive days before today with price <= today
vector<int> stockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> st;  // Stack of indices
    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[st.top()] <= prices[i]) st.pop();
        span[i] = st.empty() ? i+1 : i - st.top();
        st.push(i);
    }
    return span;
}
```

**LeetCode for Monotonic Stack:** #42, #84, #85, #316, #402, #456, #496, #503, #556, #581, #654, #739, #769, #795, #856, #901, #907, #921, #962, #1019

---

## Pattern 11: Monotonic Queue

**Key Idea:** Queue that maintains elements in monotonic order, allowing O(1) max/min queries over a sliding window.

```cpp
// Maximum in each window of size k — O(n) total
vector<int> slidingWindowMax(vector<int>& arr, int k) {
    deque<int> dq;  // Stores indices, front is max
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        // Remove elements out of window
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        // Maintain monotonic decreasing order
        while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k-1) result.push_back(arr[dq.front()]);
    }
    return result;
}
```

### Problem 1: Sliding Window Maximum (LeetCode 239)
*(Covered above)*

### Problem 2: Shortest Subarray with Sum >= K (may have negatives)
```cpp
// LeetCode 862
int shortestSubarray(vector<int>& A, int K) {
    int n = A.size();
    vector<long long> prefix(n+1, 0);
    for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + A[i];
    deque<int> dq;
    int result = INT_MAX;
    for (int i = 0; i <= n; i++) {
        while (!dq.empty() && prefix[i] - prefix[dq.front()] >= K) {
            result = min(result, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && prefix[i] <= prefix[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    return result == INT_MAX ? -1 : result;
}
```

### Problem 3: Maximum Sum Circular Subarray
```cpp
// LeetCode 918
int maxSubarraySumCircular(vector<int>& A) {
    // Max of: (non-circular max) OR (total - non-circular min)
    int totalSum = 0, maxSum = INT_MIN, minSum = INT_MAX;
    int curMax = 0, curMin = 0;
    for (int x : A) {
        curMax = max(curMax + x, x);
        maxSum = max(maxSum, curMax);
        curMin = min(curMin + x, x);
        minSum = min(minSum, curMin);
        totalSum += x;
    }
    return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
}
```

**LeetCode for Monotonic Queue:** #239, #862, #918, #1438, #1499, #1696, #2073, #2398, #2762, #2945

---

## Pattern 12: Kadane's Algorithm Pattern

**Key Idea:** Maximum subarray sum can be computed in O(n) by deciding at each position: extend the current subarray or start fresh.

### Core Kadane's Algorithm
```cpp
// LeetCode 53: Maximum Subarray
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], curSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        curSum = max(nums[i], curSum + nums[i]);  // Extend or restart
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}
```

**Dry Run:**
```
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

i=0: curSum=-2, maxSum=-2
i=1: curSum=max(1, -2+1)=max(1,-1)=1, maxSum=1
i=2: curSum=max(-3, 1-3)=max(-3,-2)=-2, maxSum=1
i=3: curSum=max(4, -2+4)=max(4,2)=4, maxSum=4
i=4: curSum=max(-1, 4-1)=3, maxSum=4
i=5: curSum=max(2, 3+2)=5, maxSum=5
i=6: curSum=max(1, 5+1)=6, maxSum=6
i=7: curSum=max(-5, 6-5)=1, maxSum=6
i=8: curSum=max(4, 1+4)=5, maxSum=6

Answer: 6 (subarray [4,-1,2,1]) ✓
```

### Kadane's with Subarray Indices
```cpp
pair<int, pair<int,int>> maxSubarrayWithIndices(vector<int>& nums) {
    int maxSum = nums[0], curSum = nums[0];
    int start = 0, end = 0, tempStart = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > curSum + nums[i]) {
            curSum = nums[i];
            tempStart = i;
        } else {
            curSum += nums[i];
        }
        if (curSum > maxSum) {
            maxSum = curSum;
            start = tempStart;
            end = i;
        }
    }
    return {maxSum, {start, end}};
}
```

### Problem 1: Maximum Product Subarray
```cpp
// LeetCode 152
int maxProduct(vector<int>& nums) {
    int maxProd = nums[0], minProd = nums[0], result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) swap(maxProd, minProd);  // Negative flips min/max
        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);
        result = max(result, maxProd);
    }
    return result;
}
// Key: Track both max and min (negative * negative = positive!)
```

### Problem 2: Best Time to Buy and Sell Stock
```cpp
// LeetCode 121: Single transaction
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int p : prices) {
        minPrice = min(minPrice, p);
        maxProfit = max(maxProfit, p - minPrice);
    }
    return maxProfit;
}
// Kadane's variant: profit[i] = prices[i] - prices[j] for j < i
```

### Problem 3: Maximum Sum Circular Subarray
*(Covered in Pattern 11)*

### Problem 4: Kadane's on 2D (Maximum Sum Rectangle)
```cpp
// Maximum sum subrectangle in 2D array
int maxSumSubmatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    int maxSum = INT_MIN;
    for (int left = 0; left < cols; left++) {
        vector<int> temp(rows, 0);
        for (int right = left; right < cols; right++) {
            for (int i = 0; i < rows; i++) temp[i] += matrix[i][right];
            // Apply Kadane's on temp
            int curSum = temp[0], curMax = temp[0];
            for (int i = 1; i < rows; i++) {
                curSum = max(temp[i], curSum + temp[i]);
                curMax = max(curMax, curSum);
            }
            maxSum = max(maxSum, curMax);
        }
    }
    return maxSum;
}
```

**LeetCode for Kadane:** #53, #121, #122, #123, #152, #309, #376, #413, #516, #689, #713, #740, #918, #978, #1186, #1191, #1567, #2321, #2414

---

## Pattern 13: Merge Intervals

### Template
```cpp
// Sort by start, then merge overlapping
sort(intervals.begin(), intervals.end());
vector<vector<int>> result = {intervals[0]};
for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] <= result.back()[1])
        result.back()[1] = max(result.back()[1], intervals[i][1]);
    else
        result.push_back(intervals[i]);
}
```

### Problem 1: Meeting Rooms (Can Attend All?)
```cpp
// LeetCode 252
bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    for (int i = 1; i < intervals.size(); i++)
        if (intervals[i][0] < intervals[i-1][1]) return false;
    return true;
}
```

### Problem 2: Employee Free Time
```cpp
// Flatten all intervals, sort, find gaps
vector<vector<int>> employeeFreeTime(vector<vector<vector<int>>>& schedule) {
    vector<vector<int>> all;
    for (auto& emp : schedule) for (auto& interval : emp) all.push_back(interval);
    sort(all.begin(), all.end());
    vector<vector<int>> result;
    int end = all[0][1];
    for (int i = 1; i < all.size(); i++) {
        if (all[i][0] > end) result.push_back({end, all[i][0]});
        end = max(end, all[i][1]);
    }
    return result;
}
```

**LeetCode for Intervals:** #56, #57, #228, #252, #253, #352, #435, #452, #495, #630, #715, #759, #986, #1272, #1288

---

## Pattern 14: Matrix Problems

### Spiral Traversal
```cpp
// LeetCode 54: Spiral order
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int top=0, bottom=matrix.size()-1, left=0, right=matrix[0].size()-1;
    vector<int> result;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) result.push_back(matrix[top][i]);
        top++;
        for (int i = top; i <= bottom; i++) result.push_back(matrix[i][right]);
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) result.push_back(matrix[bottom][i]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) result.push_back(matrix[i][left]);
            left++;
        }
    }
    return result;
}
```

**Visual Dry Run for Spiral:**
```
Matrix:          Traversal order:
1  2  3  4       → 1  2  3  4
5  6  7  8       ↓ 8 12 16
9  10 11 12      ← 15 14 13
13 14 15 16      ↑ 9 (then 5)
                    → 6  7
                    ↑ 11 10
                 Result: [1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10]
```

### Rotate Matrix 90° Clockwise
```cpp
// LeetCode 48: In-place rotation
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // Step 1: Transpose (swap matrix[i][j] with matrix[j][i])
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);
    // Step 2: Reverse each row
    for (auto& row : matrix)
        reverse(row.begin(), row.end());
}
// Anti-clockwise: reverse rows first, then transpose
```

**Dry Run:**
```
Original:    After transpose:   After row reverse:
1 2 3        1 4 7             7 4 1
4 5 6   →    2 5 8      →      8 5 2
7 8 9        3 6 9             9 6 3

90° clockwise rotation ✓
```

### Search in Row-Wise and Column-Wise Sorted Matrix
```cpp
// LeetCode 240: O(n+m) solution
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0, col = matrix[0].size()-1;  // Start top-right
    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] > target) col--;  // Eliminate column
        else row++;                                   // Eliminate row
    }
    return false;
}
```

### Set Matrix Zeroes
```cpp
// LeetCode 73: If cell is 0, set row and column to 0
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool firstRow = false, firstCol = false;
    // Check if first row/col has zeros
    for (int j = 0; j < n; j++) if (matrix[0][j] == 0) firstRow = true;
    for (int i = 0; i < m; i++) if (matrix[i][0] == 0) firstCol = true;
    // Use first row/col as markers
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][j] == 0) { matrix[i][0] = matrix[0][j] = 0; }
    // Set zeros based on markers
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
    if (firstRow) for (int j = 0; j < n; j++) matrix[0][j] = 0;
    if (firstCol) for (int i = 0; i < m; i++) matrix[i][0] = 0;
}
```

**LeetCode for Matrix:** #36, #48, #54, #59, #64, #73, #74, #79, #130, #200, #240, #289, #304, #329, #378, #463, #542, #695, #733, #994

---

## Pattern 15: Bit Manipulation with Arrays

### Key Bit Operations
```cpp
x & 1        // Check if odd
x >> 1       // Divide by 2
x << 1       // Multiply by 2
x & (x-1)   // Remove last set bit
x ^ x = 0   // XOR of same numbers is 0
x ^ 0 = x   // XOR with 0 gives x
```

### Problem 1: Find Single Number
```cpp
// LeetCode 136: Every element appears twice except one
int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int x : nums) result ^= x;  // Pairs cancel out (XOR is 0)
    return result;
}
// Dry run: [4,1,2,1,2] → 4^1^2^1^2 = 4^(1^1)^(2^2) = 4^0^0 = 4 ✓
```

### Problem 2: Single Number III (Two unique elements)
```cpp
// LeetCode 260: Two elements appear once
vector<int> singleNumber(vector<int>& nums) {
    int xorAll = 0;
    for (int x : nums) xorAll ^= x;
    // xorAll = a ^ b (two unique numbers)
    // Find any set bit (where a and b differ)
    int diffBit = xorAll & (-xorAll);  // Lowest set bit
    int a = 0, b = 0;
    for (int x : nums) {
        if (x & diffBit) a ^= x;
        else b ^= x;
    }
    return {a, b};
}
```

### Problem 3: Count Set Bits in Array
```cpp
// LeetCode 338: Count bits 0..n
vector<int> countBits(int n) {
    vector<int> result(n+1);
    for (int i = 1; i <= n; i++)
        result[i] = result[i >> 1] + (i & 1);
    return result;
}
// result[i] = result[i/2] + (i%2)
// Because shifting right removes one bit
```

### Problem 4: Missing Number
```cpp
// LeetCode 268: Find missing in [0..n]
int missingNumber(vector<int>& nums) {
    int n = nums.size(), result = n;
    for (int i = 0; i < n; i++) result ^= i ^ nums[i];
    return result;
}
```

### Problem 5: Subsets (using bitmask)
```cpp
// LeetCode 78: All subsets
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> result;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++)
            if (mask & (1 << i)) subset.push_back(nums[i]);
        result.push_back(subset);
    }
    return result;
}
// Time: O(n * 2^n), Space: O(n * 2^n)
```

**LeetCode for Bit Manipulation:** #136, #137, #190, #191, #201, #231, #260, #268, #318, #338, #389, #421, #461, #477, #693, #762, #78, #1239, #1442, #1486

---

## Pattern 16: Cyclic Sort

**Key Idea:** For arrays with values in range [1, n] or [0, n], place each number at its "correct" index by swapping.

**When to use:**
- "Array contains numbers in range [1, n]"
- "Find missing/duplicate numbers"
- "Cyclic nature of array indices"

```cpp
// Cyclic Sort Template
void cyclicSort(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        int correct = nums[i] - 1;  // nums[i] should be at index correct
        if (nums[i] != nums[correct])
            swap(nums[i], nums[correct]);   // Place nums[i] at correct position
        else
            i++;
    }
}
```

**Dry Run:**
```
nums = [3, 1, 5, 4, 2]
i=0: nums[0]=3, correct=2, nums[2]=5≠3, swap → [5,1,3,4,2]
i=0: nums[0]=5, correct=4, nums[4]=2≠5, swap → [2,1,3,4,5]
i=0: nums[0]=2, correct=1, nums[1]=1≠2, swap → [1,2,3,4,5]
i=0: nums[0]=1, correct=0, nums[0]=1=nums[0], i++ → i=1
i=1: nums[1]=2=nums[1], i++ → i=2, ... 
Final: [1,2,3,4,5] ✓
```

### Problem 1: Find Missing Number
```cpp
// LeetCode 268
int missingNumber(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        if (nums[i] < nums.size() && nums[i] != nums[nums[i]])
            swap(nums[i], nums[nums[i]]);
        else i++;
    }
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != i) return i;
    return nums.size();
}
```

### Problem 2: Find All Missing Numbers
```cpp
// LeetCode 448
vector<int> findDisappearedNumbers(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        int correct = nums[i] - 1;
        if (nums[i] != nums[correct]) swap(nums[i], nums[correct]);
        else i++;
    }
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != i+1) result.push_back(i+1);
    return result;
}
```

### Problem 3: Find Duplicate Number
```cpp
// LeetCode 287: O(n) time, O(1) space
int findDuplicate(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];
    do { slow = nums[slow]; fast = nums[nums[fast]]; }
    while (slow != fast);
    fast = nums[0];
    while (slow != fast) { slow = nums[slow]; fast = nums[fast]; }
    return slow;
    // Floyd's cycle detection on the array as a linked list
}
```

**LeetCode for Cyclic Sort:** #41, #268, #287, #442, #448, #645, #765

---

## Pattern 17: Dutch National Flag (DNF)

### Problem
Sort an array of 0s, 1s, and 2s in O(n) time using O(1) space.

### Intuition
Think of the array as three sections:
```
[  0s  |  1s  |  ?  |  2s  ]
         ↑     ↑    ↑
         low   mid  high
```

### Algorithm
```cpp
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low++], nums[mid++]);   // 0: swap to left section
        } else if (nums[mid] == 1) {
            mid++;                             // 1: already in middle
        } else {
            swap(nums[mid], nums[high--]);     // 2: swap to right section
            // Note: don't increment mid (swapped val needs checking)
        }
    }
}
```

**Detailed Dry Run:**
```
nums = [2, 0, 2, 1, 1, 0]
low=0, mid=0, high=5

Step 1: nums[0]=2 → swap(nums[0],nums[5]) → [0,0,2,1,1,2], high=4
         now nums[0]=0 (need to check)
Step 2: nums[0]=0 → swap(nums[0],nums[0]) → same, low=1, mid=1
Step 3: nums[1]=0 → swap(nums[1],nums[1]) → same, low=2, mid=2
Step 4: nums[2]=2 → swap(nums[2],nums[4]) → [0,0,1,1,2,2], high=3
Step 5: nums[2]=1 → mid=3
Step 6: nums[3]=1 → mid=4, mid>high → DONE

Result: [0,0,1,1,2,2] ✓
```

### Generalization: k Colors (k-way partition)
```cpp
// 4-way partition (0,1,2,3) — use counting sort O(n)
// For arbitrary k, use counting sort or radix sort
```

---

## Pattern 18: Meet in the Middle

**Key Idea:** Split the array into two halves, solve each independently, combine results. Reduces O(2^n) to O(2^(n/2)).

**When to use:**
- n up to ~40 (2^40 too slow, 2^20 ≈ 1M OK)
- "Find subset with sum = target"

```cpp
// 4Sum — all quadruplets summing to target
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> result;
    for (int i = 0; i < n-3; i++) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        for (int j = i+1; j < n-2; j++) {
            if (j > i+1 && nums[j] == nums[j-1]) continue;
            int l = j+1, r = n-1;
            long long need = (long long)target - nums[i] - nums[j];
            while (l < r) {
                long long sum = nums[l] + nums[r];
                if (sum == need) {
                    result.push_back({nums[i],nums[j],nums[l],nums[r]});
                    while (l<r && nums[l]==nums[l+1]) l++;
                    while (l<r && nums[r]==nums[r-1]) r--;
                    l++; r--;
                } else if (sum < need) l++;
                else r--;
            }
        }
    }
    return result;
}
```

**Subset Sum with Meet in Middle:**
```cpp
// Find if any subset sums to target
// n up to 40
bool subsetSum(vector<int>& arr, long long target) {
    int n = arr.size(), half = n/2;
    // Generate all subset sums for left half
    vector<long long> leftSums;
    for (int mask = 0; mask < (1 << half); mask++) {
        long long s = 0;
        for (int i = 0; i < half; i++)
            if (mask & (1 << i)) s += arr[i];
        leftSums.push_back(s);
    }
    sort(leftSums.begin(), leftSums.end());
    // For each right half subset, check if complement exists in left
    for (int mask = 0; mask < (1 << (n-half)); mask++) {
        long long s = 0;
        for (int i = 0; i < n-half; i++)
            if (mask & (1 << i)) s += arr[half+i];
        long long need = target - s;
        if (binary_search(leftSums.begin(), leftSums.end(), need)) return true;
    }
    return false;
}
// Time: O(2^(n/2) * n), Space: O(2^(n/2))
```

---

## Pattern 19: Sweep Line

**Key Idea:** Simulate a vertical line sweeping from left to right, processing events.

**When to use:**
- Interval problems (overlaps, counts)
- "At each point, how many intervals are active?"

```cpp
// Count maximum simultaneous meetings
int maxMeetings(vector<pair<int,int>>& meetings) {
    vector<pair<int,int>> events;
    for (auto& [s, e] : meetings) {
        events.push_back({s, 1});   // Start event
        events.push_back({e, -1});  // End event
    }
    sort(events.begin(), events.end());
    int current = 0, maxCount = 0;
    for (auto& [time, type] : events) {
        current += type;
        maxCount = max(maxCount, current);
    }
    return maxCount;
}
```

**Dry Run:**
```
meetings = [(1,4), (2,6), (3,5)]

Events: (1,+1), (2,+1), (3,+1), (4,-1), (5,-1), (6,-1)
Sort:   same as above

time=1: current=1, max=1
time=2: current=2, max=2
time=3: current=3, max=3  ← 3 meetings at once!
time=4: current=2, max=3
time=5: current=1, max=3
time=6: current=0, max=3
```

### Difference Array as Sweep Line
```cpp
// Apply sweep line for range updates
vector<int> diff(n+2, 0);
for each query (l, r, val):
    diff[l] += val;
    diff[r+1] -= val;

// Reconstruct
for (int i = 1; i <= n; i++) diff[i] += diff[i-1];
// diff[i] = value at position i after all updates
```

---

## Pattern 20: Coordinate Compression

**Key Idea:** When values are large but count is small, map them to small indices (0 to n-1).

**When to use:**
- Values are large (up to 10^9) but there are few unique values (up to 10^5)
- Need to use values as array indices

```cpp
// Compress coordinates
void compress(vector<int>& arr) {
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    for (int& x : arr) {
        x = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
    }
    // Now arr contains values 0 to (unique count - 1)
}
```

**Dry Run:**
```
arr = [1000000, 3, 999, 3, 1000000]

sorted = [3, 999, 1000000]  (after sort + unique)

Compress:
1000000 → index 2
3       → index 0
999     → index 1
3       → index 0
1000000 → index 2

Compressed: [2, 0, 1, 0, 2]
Now values are in [0, 2] — usable as array indices!
```

**Application: Count Inversions using BIT**
```cpp
int countInversions(vector<int>& arr) {
    // Compress coordinates
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int n = sorted.size();

    // BIT (Fenwick Tree) to count inversions
    vector<int> bit(n+1, 0);
    auto update = [&](int i) { for (i++; i <= n; i += i&(-i)) bit[i]++; };
    auto query = [&](int i) { int s=0; for (i++; i > 0; i -= i&(-i)) s+=bit[i]; return s; };

    int inversions = 0;
    for (int x : arr) {
        int idx = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
        inversions += query(n-1) - query(idx);  // Count elements > x already processed
        update(idx);
    }
    return inversions;
}
```

---
---

<a name="section-7"></a>
# SECTION 7: IMPORTANT ALGORITHMS ON ARRAYS

---

## 7.1 Kadane's Algorithm

*(Detailed coverage in Pattern 12)*

**Interview Notes:**
- Works only when at least one positive element exists (else return max element)
- For empty subarray allowed: initialize curSum = 0, not nums[0]
- Can be extended to 2D (Maximum Sum Rectangle)
- Follow-up: "What if we want circular subarray?" → Kadane + Total - MinSubarray

---

## 7.2 Moore's Voting Algorithm (Majority Element)

### Problem
Find element appearing more than n/2 times.

### Intuition
If majority element exists, it "outvotes" all others combined.

```cpp
int majorityElement(vector<int>& nums) {
    int candidate = nums[0], count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (count == 0) { candidate = nums[i]; count = 1; }
        else if (nums[i] == candidate) count++;
        else count--;
    }
    // Verify (if majority not guaranteed)
    int verifyCount = 0;
    for (int x : nums) if (x == candidate) verifyCount++;
    return verifyCount > nums.size()/2 ? candidate : -1;
}
// Time: O(n), Space: O(1)
```

**Dry Run:**
```
nums = [3, 3, 4, 2, 4, 4, 2, 4, 4]
candidate=3, count=1

i=1: 3=3, count=2
i=2: 4≠3, count=1
i=3: 2≠3, count=0
i=4: count=0, candidate=4, count=1
i=5: 4=4, count=2
i=6: 2≠4, count=1
i=7: 4=4, count=2
i=8: 4=4, count=3

candidate = 4 ✓ (appears 5 > 9/2 = 4.5 times)
```

### Extended: n/3 Majority (at most 2 candidates)
```cpp
// LeetCode 229: Elements appearing > n/3 times
vector<int> majorityElement(vector<int>& nums) {
    int c1 = INT_MIN, c2 = INT_MIN, cnt1 = 0, cnt2 = 0;
    for (int x : nums) {
        if (x == c1) cnt1++;
        else if (x == c2) cnt2++;
        else if (cnt1 == 0) { c1 = x; cnt1 = 1; }
        else if (cnt2 == 0) { c2 = x; cnt2 = 1; }
        else { cnt1--; cnt2--; }
    }
    cnt1 = cnt2 = 0;
    for (int x : nums) {
        if (x == c1) cnt1++;
        else if (x == c2) cnt2++;
    }
    vector<int> result;
    if (cnt1 > nums.size()/3) result.push_back(c1);
    if (cnt2 > nums.size()/3) result.push_back(c2);
    return result;
}
```

---

## 7.3 Dutch National Flag Algorithm

*(Detailed coverage in Pattern 17)*

**Interview Notes:**
- Invented by Dijkstra, named after the Dutch flag (3 stripes = 3 sections)
- Real applications: quicksort partitioning with duplicates, 3-way partition
- Key insight: 3 pointers create 4 regions: processed-0 | processed-1 | unprocessed | processed-2

---

## 7.4 Floyd's Cycle Detection (Tortoise and Hare)

### Problem
Find if there's a cycle, and find the start of the cycle.

```cpp
// Phase 1: Detect cycle
int slow = nums[0], fast = nums[0];
do {
    slow = nums[slow];       // 1 step
    fast = nums[nums[fast]]; // 2 steps
} while (slow != fast);     // They meet inside the cycle

// Phase 2: Find cycle start
fast = nums[0];              // Reset one pointer to start
while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];       // Both move 1 step
}
// slow == fast == cycle start
```

**Proof Sketch:**
```
     ←—F—→    ← C →
  0----k----entry---meet
  
If slow traveled distance d, fast traveled 2d.
Cycle length C, d = k + x (k steps before cycle, x inside).
2d = k + x + nC for some n.
k + x + nC = 2(k + x) → k = nC - x
Reset fast to 0: moves k steps.
Slow moves k steps from meet: ends at entry.
k ≡ -x (mod C), so x+k ≡ 0 (mod C). They meet at entry! ✓
```

---

## 7.5 Binary Search Variants Summary

| Variant | Condition | Move |
|---|---|---|
| Standard | arr[mid]==target | Return mid |
| Lower Bound | arr[mid] < target | low=mid+1, else high=mid |
| Upper Bound | arr[mid] <= target | low=mid+1, else high=mid |
| First Occurrence | arr[mid]==target | record, high=mid-1 |
| Last Occurrence | arr[mid]==target | record, low=mid+1 |
| Peak Element | arr[mid]<arr[mid+1] | low=mid+1 else high=mid |
| Rotated Search | complex | depends on sorted half |

---

## 7.6 Prefix Sum and Difference Array

*(Detailed in Pattern 3)*

---

## 7.7 Fenwick Tree (Binary Indexed Tree) — Introduction

### What it solves
Point updates and prefix sum queries, both in O(log n).

```cpp
class FenwickTree {
    vector<int> tree;
    int n;
public:
    FenwickTree(int n) : n(n), tree(n+1, 0) {}

    void update(int i, int delta) {  // 1-indexed
        for (i++; i <= n; i += i & (-i))
            tree[i] += delta;
    }

    int query(int i) {  // prefix sum [0..i]
        int sum = 0;
        for (i++; i > 0; i -= i & (-i))
            sum += tree[i];
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - (l > 0 ? query(l-1) : 0);
    }
};
// Time: O(log n) per operation, Space: O(n)
```

**Visual of Fenwick Tree:**
```
Index: 1  2  3  4  5  6  7  8
tree[i] stores sum of range based on lowest set bit:
tree[1] = arr[1]          (range 1 bit = 1)
tree[2] = arr[1]+arr[2]   (range 2 bits = 10)
tree[3] = arr[3]          (range 1 bit = 1)
tree[4] = arr[1..4]       (range 4 bits = 100)
tree[6] = arr[5]+arr[6]   (range 2 bits = 10)
tree[8] = arr[1..8]       (range 8 bits = 1000)
```

---

## 7.8 Segment Tree — Introduction

### What it solves
Range queries (min, max, sum, GCD) and point/range updates in O(log n).

```cpp
class SegmentTree {
    vector<int> tree;
    int n;
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) { tree[node] = arr[start]; return; }
        int mid = (start + end) / 2;
        build(arr, 2*node, start, mid);
        build(arr, 2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];  // Sum tree
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;           // Out of range
        if (l <= start && end <= r) return tree[node]; // Fully in range
        int mid = (start + end) / 2;
        return query(2*node, start, mid, l, r) +
               query(2*node+1, mid+1, end, l, r);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) { tree[node] = val; return; }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2*node, start, mid, idx, val);
        else update(2*node+1, mid+1, end, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    // Wrappers
    int query(int l, int r) { return query(1, 0, n-1, l, r); }
    void update(int idx, int val) { update(1, 0, n-1, idx, val); }
};
```

---

## 7.9 Sparse Table — Introduction

### What it solves
Range Minimum/Maximum Queries (RMQ) in O(1) after O(n log n) preprocessing.

```cpp
class SparseTable {
    vector<vector<int>> table;
    vector<int> log2;
    int n;
public:
    SparseTable(vector<int>& arr) {
        n = arr.size();
        int LOG = __lg(n) + 1;
        table.assign(LOG, vector<int>(n));
        log2.resize(n+1);
        log2[1] = 0;
        for (int i = 2; i <= n; i++) log2[i] = log2[i/2] + 1;

        table[0] = arr;
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i + (1<<j) <= n; i++)
                table[j][i] = min(table[j-1][i], table[j-1][i + (1<<(j-1))]);
    }

    int query(int l, int r) {  // Range minimum [l, r]
        int j = log2[r - l + 1];
        return min(table[j][l], table[j][r - (1<<j) + 1]);
    }
};
// O(n log n) build, O(1) query
```

---

<a name="section-8"></a>
# SECTION 8: SORTING FOR ARRAYS

---

## 8.1 Sorting Algorithm Comparison

| Algorithm | Best | Average | Worst | Space | Stable | In-place |
|---|---|---|---|---|---|---|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No | Yes |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes | No |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No | Yes |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No | Yes |
| Counting Sort | O(n+k) | O(n+k) | O(n+k) | O(k) | Yes | No |
| Radix Sort | O(nk) | O(nk) | O(nk) | O(n+k) | Yes | No |
| Bucket Sort | O(n+k) | O(n+k) | O(n²) | O(n) | Yes | No |

---

## 8.2 Bubble Sort

### Intuition
Repeatedly compare adjacent elements and swap if out of order. Largest "bubbles" to the end each pass.

```cpp
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // Already sorted — O(n) best case
    }
}
```

**Dry Run:**
```
arr = [64, 34, 25, 12, 22, 11, 90]

Pass 1:
[34, 25, 12, 22, 11, 64, 90]  ← 90 bubbles to end
Pass 2:
[25, 12, 22, 11, 34, 64, 90]  ← 64 in place
Pass 3:
[12, 22, 11, 25, 34, 64, 90]
Pass 4:
[12, 11, 22, 25, 34, 64, 90]
Pass 5:
[11, 12, 22, 25, 34, 64, 90]  ✓
```

**Best use:** Small arrays, nearly sorted data (O(n) best case with flag).

---

## 8.3 Selection Sort

### Intuition
Find the minimum element and place it at the beginning. Repeat for remaining.

```cpp
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}
```

**Dry Run:**
```
arr = [64, 25, 12, 22, 11]

i=0: min=11 at idx=4, swap(0,4) → [11, 25, 12, 22, 64]
i=1: min=12 at idx=2, swap(1,2) → [11, 12, 25, 22, 64]
i=2: min=22 at idx=3, swap(2,3) → [11, 12, 22, 25, 64]
i=3: min=25 at idx=3, no swap   → [11, 12, 22, 25, 64]
Done ✓
```

**Note:** Always O(n²), not adaptive. Good for small arrays or when writes are expensive (O(n) writes).

---

## 8.4 Insertion Sort

### Intuition
Like sorting playing cards. Take one card at a time, insert it in the correct position among already-sorted cards.

```cpp
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
```

**Dry Run:**
```
arr = [5, 3, 4, 1, 2]

i=1: key=3, arr[0]=5>3, shift → [5,5,4,1,2], j=-1, arr[0]=3 → [3,5,4,1,2]
i=2: key=4, arr[1]=5>4, shift → [3,5,5,1,2], j=0, arr[0]=3<4, arr[1]=4 → [3,4,5,1,2]
i=3: key=1, shift 5,4,3 → [1,3,4,5,2]
i=4: key=2, shift 5,4,3 → [1,2,3,4,5] ✓
```

**Best use:** Small arrays, nearly sorted (O(n) best case), online sorting (can sort as data arrives).

---

## 8.5 Merge Sort

### Intuition
Divide array in half, recursively sort each half, then merge the two sorted halves.

```cpp
void merge(vector<int>& arr, int l, int mid, int r) {
    vector<int> left(arr.begin()+l, arr.begin()+mid+1);
    vector<int> right(arr.begin()+mid+1, arr.begin()+r+1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}
// Call: mergeSort(arr, 0, arr.size()-1);
```

**Visualization:**
```
[38, 27, 43, 3, 9, 82, 10]
         ↙              ↘
  [38, 27, 43, 3]    [9, 82, 10]
      ↙      ↘         ↙    ↘
 [38, 27] [43, 3]  [9, 82]  [10]
   ↙  ↘    ↙  ↘    ↙   ↘
 [38][27] [43][3] [9]  [82]

Merge pairs: [27,38] [3,43] [9,82] [10]
Merge quads: [3,27,38,43] [9,10,82]
Final merge: [3,9,10,27,38,43,82] ✓
```

**Interview Notes:**
- Only stable O(n log n) sort that's easy to implement
- Used in external sorting (too much data for RAM)
- Best for linked lists (no random access needed)
- Python's `sorted()` is TimSort (hybrid merge + insertion)

---

## 8.6 Quick Sort

### Intuition
Choose a pivot, partition array (smaller on left, larger on right), recurse on both halves.

```cpp
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Last element as pivot
    int i = low - 1;        // i tracks position of last "small" element
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[i+1], arr[high]);  // Place pivot in correct position
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
```

**Dry Run (Partition):**
```
arr = [3, 6, 8, 10, 1, 2, 1], pivot = arr[6] = 1
i = -1

j=0: arr[0]=3 > 1, skip
j=1: arr[1]=6 > 1, skip
j=2: arr[2]=8 > 1, skip
j=3: arr[3]=10 > 1, skip
j=4: arr[4]=1 <= 1, i=0, swap(arr[0],arr[4]) → [1,6,8,10,3,2,1]
j=5: arr[5]=2 > 1, skip

Place pivot: swap(arr[i+1], arr[6]) = swap(arr[1], arr[6]) → [1,1,8,10,3,2,6]
Return pi=1

Left part [1] sorted, right part [8,10,3,2,6] recurse
```

**Avoiding Worst Case:**
```cpp
// Random pivot to avoid O(n²) on sorted input
int partition(vector<int>& arr, int low, int high) {
    int randIdx = low + rand() % (high - low + 1);
    swap(arr[randIdx], arr[high]);
    // rest same
}
```

**Interview Notes:**
- Average O(n log n), but worst case O(n²) for sorted input with last-element pivot
- Cache-friendly (in-place)
- Not stable, but fastest in practice due to constants
- 3-way partition for many duplicates (DNF approach)

---

## 8.7 Heap Sort

### Intuition
Build a max-heap, then repeatedly extract the maximum to sort.

```cpp
void heapify(vector<int>& arr, int n, int i) {
    int largest = i, left = 2*i+1, right = 2*i+2;
    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    // Build max heap
    for (int i = n/2-1; i >= 0; i--) heapify(arr, n, i);
    // Extract elements
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move max to end
        heapify(arr, i, 0);    // Restore heap on reduced array
    }
}
```

**Interview Notes:**
- Guaranteed O(n log n) — unlike quicksort
- In-place (unlike mergesort)
- Not stable, poor cache performance
- Used in priority queues, k-th largest element

---

## 8.8 Counting Sort

### Intuition
Count occurrences of each value, then reconstruct. No comparisons!

```cpp
void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    vector<int> count(maxVal + 1, 0);
    for (int x : arr) count[x]++;
    int idx = 0;
    for (int i = 0; i <= maxVal; i++)
        while (count[i]--) arr[idx++] = i;
}
// Time: O(n+k), Space: O(k)  where k = max value
```

**Dry Run:**
```
arr = [1, 4, 1, 2, 7, 5, 2]
maxVal = 7

count = [0, 2, 2, 0, 1, 1, 0, 1]
         0  1  2  3  4  5  6  7

Reconstruct:
i=1: place 1 twice → arr=[1,1,...]
i=2: place 2 twice → arr=[1,1,2,2,...]
i=4: place 4 once  → arr=[1,1,2,2,4,...]
i=5: place 5 once  → arr=[1,1,2,2,4,5,...]
i=7: place 7 once  → arr=[1,1,2,2,4,5,7] ✓
```

**When to use:** k (range of values) is small — sorting ages, grades, characters.

---

## 8.9 Radix Sort

### Intuition
Sort digit by digit (LSD: least significant to most significant), using counting sort on each digit.

```cpp
void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal/exp > 0; exp *= 10) {
        vector<int> output(arr.size());
        vector<int> count(10, 0);
        for (int x : arr) count[(x/exp)%10]++;
        for (int i = 1; i < 10; i++) count[i] += count[i-1];
        for (int i = arr.size()-1; i >= 0; i--) {
            output[--count[(arr[i]/exp)%10]] = arr[i];
        }
        arr = output;
    }
}
// Time: O(n * digits), Stable, good for fixed-width numbers
```

**Dry Run:**
```
arr = [170, 45, 75, 90, 802, 24, 2, 66]

Sort by 1s digit: [170, 90, 802, 2, 24, 45, 75, 66]
Sort by 10s digit:[802, 2, 24, 45, 66, 170, 75, 90]
Sort by 100s digit:[2, 24, 45, 66, 75, 90, 170, 802] ✓
```

---

## 8.10 Bucket Sort

### Intuition
Distribute elements into "buckets," sort each bucket, concatenate.

```cpp
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n);
    for (float x : arr) buckets[int(n*x)].push_back(x);
    for (auto& b : buckets) sort(b.begin(), b.end());
    int idx = 0;
    for (auto& b : buckets) for (float x : b) arr[idx++] = x;
}
// Best for uniformly distributed data in [0, 1)
// Average: O(n + n²/k + k) where k = bucket count
```

---

<a name="section-9"></a>
# SECTION 9: COMPLETE INTERVIEW ARRAY QUESTIONS

---

## Easy (50 Questions)

| # | Problem | LeetCode | Pattern | Key Idea |
|---|---|---|---|---|
| 1 | Two Sum | #1 | Hashing | Complement lookup |
| 2 | Best Time to Buy and Sell Stock | #121 | Traversal/Kadane | Track min price |
| 3 | Contains Duplicate | #217 | Hashing | Hash set |
| 4 | Missing Number | #268 | Math/Cyclic Sort | XOR or sum formula |
| 5 | Find All Numbers Disappeared | #448 | Cyclic Sort | Negative marking |
| 6 | Single Number | #136 | Bit Manipulation | XOR all elements |
| 7 | Move Zeroes | #283 | Two Pointers | Slow-fast pointer |
| 8 | Squares of Sorted Array | #977 | Two Pointers | Merge from ends |
| 9 | Remove Duplicates (Sorted) | #26 | Two Pointers | Slow pointer |
| 10 | Remove Element | #27 | Two Pointers | Overwrite unwanted |
| 11 | Plus One | #66 | Array Traversal | Carry propagation |
| 12 | Merge Sorted Array | #88 | Two Pointers | Merge from back |
| 13 | Find Pivot Index | #724 | Prefix Sum | Left sum = right sum |
| 14 | Running Sum of 1D Array | #1480 | Prefix Sum | Cumulative sum |
| 15 | Count Items Matching Rule | #1773 | Traversal | Condition check |
| 16 | Sum of Unique Elements | #1748 | Hashing | Frequency = 1 |
| 17 | Maximum Difference | #2016 | Traversal | Track min before |
| 18 | Max Consecutive Ones | #485 | Traversal | Reset on 0 |
| 19 | Third Maximum Number | #414 | Traversal | Track 3 maxes |
| 20 | Array Partition | #561 | Sorting | Sort, take pairs |
| 21 | Majority Element | #169 | Moore Voting | Cancel opposites |
| 22 | Pascal's Triangle | #118 | 2D Array | row[j] = prev[j-1]+prev[j] |
| 23 | Pascal's Triangle II | #119 | 1D DP | Compute row |
| 24 | Best Time to Sell with Cooldown | #309 | DP | State machine |
| 25 | Check if Array is Sorted | — | Traversal | Compare adjacent |
| 26 | Find Maximum Element | — | Traversal | One pass |
| 27 | Rotate Array | #189 | Reversal | Reverse trick |
| 28 | Search Insert Position | #35 | Binary Search | Lower bound |
| 29 | Binary Search | #704 | Binary Search | Standard template |
| 30 | First Bad Version | #278 | Binary Search | Min satisfying predicate |
| 31 | Climbing Stairs | #70 | DP on array | Fibonacci pattern |
| 32 | Count Negative in Matrix | #1351 | Binary Search | Row-wise binary search |
| 33 | Intersection of Two Arrays | #349 | Hashing | Hash set |
| 34 | Happy Number | #202 | Hashing/Cycle | Floyd's cycle |
| 35 | Monotonic Array | #896 | Traversal | Check direction |
| 36 | Sort Array by Parity | #905 | Two Pointers | Dutch flag variant |
| 37 | Flipping Image | #832 | Bit Manipulation | Flip and reverse |
| 38 | Transpose Matrix | #867 | Matrix | Swap i,j |
| 39 | Average Salary (Excluding Min/Max) | #1491 | Traversal | Track min/max/sum |
| 40 | Number of Good Pairs | #1512 | Hashing | Frequency count |
| 41 | Shuffle Array | #1470 | Array | Interleave halves |
| 42 | Check if Two Arrays Are Equal | #1460 | Hashing/Sorting | Sort both |
| 43 | Decompress Run-Length Encoding | #1313 | Array | Expand pairs |
| 44 | Kids with Greatest Candies | #1431 | Traversal | Check max |
| 45 | Find N Unique Integers Sum to Zero | #1304 | Construction | Greedy |
| 46 | Replace Elements with Greatest Right | #1299 | Traversal from Right | Track max from right |
| 47 | Last Stone Weight | #1046 | Heap/Greedy | Max heap |
| 48 | Find Lucky Integer | #1394 | Hashing | freq[x]==x |
| 49 | Smaller Numbers Than Current | #1365 | Sorting + Binary Search | Sort copy, binary search |
| 50 | Create Target Array in Given Order | #1389 | Array Simulation | Insert at index |

---

## Medium (100 Questions)

| # | Problem | LeetCode | Pattern | Key Idea |
|---|---|---|---|---|
| 1 | Three Sum | #15 | Sorting + Two Pointers | Sort, fix one, 2-pointer |
| 2 | Container With Most Water | #11 | Two Pointers | Move shorter side |
| 3 | Subarray Sum Equals K | #560 | Prefix Sum + Hash | prefixSum hashmap |
| 4 | Maximum Subarray | #53 | Kadane | Extend or restart |
| 5 | Merge Intervals | #56 | Sorting | Sort by start |
| 6 | Sort Colors | #75 | Dutch National Flag | 3-way partition |
| 7 | Maximum Product Subarray | #152 | Kadane variant | Track min and max |
| 8 | Find Minimum in Rotated | #153 | Binary Search | Identify sorted half |
| 9 | Search in Rotated Array | #33 | Binary Search | Which half is sorted |
| 10 | Longest Consecutive Sequence | #128 | Hashing | Hash set + extend |
| 11 | Find All Duplicates | #442 | Cyclic Sort | Negative marking |
| 12 | Product of Array Except Self | #238 | Prefix + Suffix | No division |
| 13 | Set Matrix Zeroes | #73 | Matrix | Use first row/col as marker |
| 14 | Spiral Matrix | #54 | Matrix | Boundary simulation |
| 15 | Rotate Image | #48 | Matrix | Transpose + reverse |
| 16 | Word Search | #79 | Matrix + DFS | Backtracking |
| 17 | Jump Game | #55 | Greedy | Track max reach |
| 18 | Jump Game II | #45 | Greedy | BFS-like levels |
| 19 | Best Time to Buy/Sell II | #122 | Greedy | Take all profits |
| 20 | Unique Paths | #62 | DP (2D array) | count paths |
| 21 | Minimum Path Sum | #64 | DP (2D) | Grid DP |
| 22 | Triangle | #120 | DP | Bottom-up triangle |
| 23 | Count and Say | #38 | String/Array | Run-length encode |
| 24 | Rotate Array | #189 | Reversal | Triple reverse |
| 25 | Increasing Triplet Subsequence | #334 | Greedy | Track two mins |
| 26 | Shortest Unsorted Subarray | #581 | Sorting | Compare sorted |
| 27 | Wiggle Subsequence | #376 | Greedy | Count alternations |
| 28 | House Robber | #198 | DP | Can't rob adjacent |
| 29 | House Robber II | #213 | DP | Circular — two cases |
| 30 | Maximum Sum Circular | #918 | Kadane | Total - minSubarray |
| 31 | Find the Duplicate | #287 | Floyd's Cycle | Array as linked list |
| 32 | Kth Largest Element | #215 | Quickselect/Heap | Partial sort |
| 33 | Top K Frequent | #347 | Heap/Bucket Sort | Frequency, get top k |
| 34 | Two Sum II | #167 | Two Pointers | Sorted array |
| 35 | Squares of Sorted Array | #977 | Two Pointers | Merge from ends |
| 36 | 4Sum | #18 | Sorting + Two Pointers | Fix two, 2-pointer |
| 37 | Remove Nth Node (Array equiv) | #19 | Two Pointers | Gap of n |
| 38 | Group Anagrams | #49 | Hashing | Sorted string as key |
| 39 | Insert Interval | #57 | Intervals | Three phases |
| 40 | Interval List Intersections | #986 | Two Pointers | Merge two interval lists |
| 41 | Non-overlapping Intervals | #435 | Greedy | Min removals |
| 42 | Minimum Number of Arrows | #452 | Greedy | Sort by end |
| 43 | Partition Labels | #763 | Greedy | Last occurrence |
| 44 | Gas Station | #134 | Greedy | Net gain |
| 45 | Candy | #135 | Greedy | Two passes |
| 46 | Score After Flipping Matrix | #861 | Greedy | Maximize ones |
| 47 | Maximum Points on a Line | #149 | Hashing | Slope as key |
| 48 | Largest Number | #179 | Custom Sort | a+b vs b+a |
| 49 | Relative Ranks | #506 | Sorting | Sort + map |
| 50 | K Closest Points to Origin | #973 | Heap/Quickselect | Distance sort |
| 51 | Daily Temperatures | #739 | Monotonic Stack | Next greater day |
| 52 | Largest Rectangle Histogram | #84 | Monotonic Stack | Area with each bar as min |
| 53 | Maximal Rectangle | #85 | Stack on Matrix | Histogram per row |
| 54 | Sum of Subarray Minimums | #907 | Monotonic Stack | Contribution technique |
| 55 | Next Greater Element I | #496 | Monotonic Stack | Precompute with hash |
| 56 | Next Greater Element II | #503 | Monotonic Stack | Circular, traverse twice |
| 57 | Online Stock Span | #901 | Monotonic Stack | Consecutive days |
| 58 | Sliding Window Maximum | #239 | Monotonic Deque | Maintain max in window |
| 59 | Minimum Size Subarray Sum | #209 | Sliding Window | Variable window |
| 60 | Longest Substring Without Repeat | #3 | Sliding Window + Hash | Shrink on duplicate |
| 61 | Fruit Into Baskets | #904 | Sliding Window | At most 2 distinct |
| 62 | Permutation in String | #567 | Sliding Window | Fixed window + freq |
| 63 | Substrings with K Distinct | #340 | Sliding Window | Exactly k = atMost(k)-atMost(k-1) |
| 64 | Max Consecutive Ones III | #1004 | Sliding Window | At most k zeros |
| 65 | Subarrays with K Different Integers | #992 | Sliding Window | ExactK trick |
| 66 | Binary Subarrays with Sum | #930 | Sliding Window | Same trick |
| 67 | Count Subarrays with Sum Div K | #974 | Prefix + Hash | Remainder classes |
| 68 | Contiguous Array | #525 | Prefix Sum + Hash | 0→-1 trick |
| 69 | Range Sum Query Immutable | #303 | Prefix Sum | Build once, query O(1) |
| 70 | Range Sum Query 2D | #304 | 2D Prefix Sum | 4-corner formula |
| 71 | Summary Ranges | #228 | Traversal | Extend range |
| 72 | Meeting Rooms II | #253 | Sweep Line | Count concurrent |
| 73 | Sort Array by Parity II | #922 | Two Pointers | Fix even/odd indices |
| 74 | Find All Anagrams | #438 | Sliding Window | Fixed window + freq |
| 75 | Check Array Sorted/Rotated | #1752 | Traversal | Count breaks |
| 76 | Minimum Operations (Reduce to 0) | #1658 | Prefix/Sliding Window | Total-target |
| 77 | Find Peak Element | #162 | Binary Search | Binary search on slope |
| 78 | Capacity to Ship in D Days | #1011 | Binary Search on Answer | Feasibility check |
| 79 | Koko Eating Bananas | #875 | Binary Search on Answer | Min k |
| 80 | Allocate Minimum Pages | — | Binary Search on Answer | Max min allocation |
| 81 | Beautiful Array | #932 | Divide and Conquer | Odd/even split |
| 82 | Longest Mountain in Array | #845 | Two Pointers | Find peaks |
| 83 | Maximum Width Ramp | #962 | Monotonic Stack | Left mins + right maxes |
| 84 | Subarray Sums Divisible by K | #974 | Prefix Sum | Remainder map |
| 85 | Number of Subarrays with Bounded Max | #795 | Two Pointers | AtMost trick |
| 86 | Number of Sub-Arrays of Size K with Avg >= Threshold | #1343 | Sliding Window | Fixed window sum |
| 87 | Maximum Average Subarray | #643 | Sliding Window | Fixed window |
| 88 | Maximum Points You Can Obtain | #1423 | Sliding Window | Total - middle window |
| 89 | Minimum Difference Between Largest/Smallest | #1509 | Sorting | Sort + check windows |
| 90 | Partition Array into K Consecutive Subsequences | #1296 | Greedy + Sorting | Sorted with freq map |
| 91 | Max Number of Events | #1353 | Greedy + Heap | Sort by start, min-heap by end |
| 92 | Car Fleet | #853 | Monotonic Stack | Sort + stack |
| 93 | Asteroid Collision | #735 | Stack | Handle directions |
| 94 | Decode String | #394 | Stack | Process brackets |
| 95 | Evaluate Reverse Polish Notation | #150 | Stack | Operator handling |
| 96 | Remove K Digits | #402 | Monotonic Stack | Maintain increasing |
| 97 | Largest Rectangle (Histogram) | #84 | Stack | Already listed |
| 98 | Minimum Domino Rotations | #1007 | Greedy | Check both values |
| 99 | Matrix Diagonal Sum | #1572 | Matrix Traversal | Index math |
| 100 | Lucky Numbers in Matrix | #1380 | Row min, Col max | Traversal |

---

## Hard (50 Questions)

| # | Problem | LeetCode | Pattern | Key Idea |
|---|---|---|---|---|
| 1 | Trapping Rain Water | #42 | Two Pointers/Stack | Min of left-max, right-max |
| 2 | Largest Rectangle in Histogram | #84 | Monotonic Stack | Area with each min |
| 3 | Maximal Rectangle | #85 | Stack + DP | Per-row histogram |
| 4 | First Missing Positive | #41 | Cyclic Sort | Place at correct index |
| 5 | Median of Two Sorted Arrays | #4 | Binary Search | Partition on smaller array |
| 6 | Sliding Window Maximum | #239 | Monotonic Deque | Already covered |
| 7 | Reverse Pairs | #493 | Merge Sort | Count during merge |
| 8 | Count of Smaller Numbers After Self | #315 | Merge Sort/BIT | Inversion count |
| 9 | Maximum Sum of Two Non-overlapping | #1031 | Prefix Sum | Precompute max from both sides |
| 10 | Minimum Number of Taps | #1326 | Greedy/DP | Jump game variant |
| 11 | Minimum Interval to Include Each Query | #2158 | Sweep Line + Heap | Offline queries |
| 12 | Maximum Performance of a Team | #1383 | Greedy + Heap | Sort by efficiency |
| 13 | Number of Subarrays with Product < K | #713 | Two Pointers | Sliding window count |
| 14 | Count of Range Sum | #327 | Merge Sort + BIT | Range query |
| 15 | Jump Game VI | #1696 | Monotonic Deque + DP | DP with window max |
| 16 | Minimum Cost to Cut a Stick | #1547 | Interval DP | Precompute prefix |
| 17 | Odd Even Jump | #975 | Monotonic Stack + DP | Two types of jumps |
| 18 | Reaching Points | #780 | Math + Reverse | Work backwards |
| 19 | Minimum Difference Between Sorted Array | #719 | Binary Search | Search on answer |
| 20 | Swim in Rising Water | #778 | Binary Search + BFS | Minimize max time |
| 21 | Max Value of Equation | #1499 | Monotonic Deque | Sliding window max |
| 22 | Minimum Number of Removals | #1671 | LIS | DP + Binary Search |
| 23 | Make Array Strictly Increasing | #1187 | DP + Binary Search | DP states |
| 24 | Constrained Subsequence Sum | #1425 | Monotonic Deque + DP | DP with window max |
| 25 | Frog Jump | #403 | DP + Hash | Reachable jumps |
| 26 | Max Chunks to Make Sorted I | #769 | Greedy | Max prefix == index |
| 27 | Max Chunks to Make Sorted II | #768 | Monotonic Stack | Merge chunks |
| 28 | Longest Subarray with Max Bitwise AND | #2401 | Bit + Two Pointers | Max element runs |
| 29 | Minimum Total Fuel Cost | #2477 | Tree + Greedy | Traversal |
| 30 | Count Array Pairs Divisible by K | #2183 | Math + Hashing | GCD pairing |
| 31 | Smallest Range Covering K Lists | #632 | Heap + Sliding Window | Min window |
| 32 | Merge K Sorted Arrays | — | Heap | Min-heap |
| 33 | Shortest Subarray with Sum >= K | #862 | Monotonic Deque | Prefix sum + deque |
| 34 | Subarrays with K Different Integers | #992 | Sliding Window | ExactK trick |
| 35 | Beautiful Arrangement II | #667 | Construction | Arrange carefully |
| 36 | Max Sum of Subarray Length K No Overlap | #1031 | Prefix Sum | Left max + right max |
| 37 | Minimum Cost to Merge Stones | #1000 | Interval DP | Greedy insight first |
| 38 | Stone Game VII | #1690 | Interval DP | Min max game |
| 39 | Burst Balloons | #312 | Interval DP | Think last balloon |
| 40 | Minimum Operations to Reduce to Zero | #1658 | Prefix Sum | Max middle subarray |
| 41 | Longest Increasing Subsequence | #300 | DP + Binary Search | Patience sorting |
| 42 | Russian Doll Envelopes | #354 | LIS in 2D | Sort + LIS |
| 43 | Maximum Sum of 3 Non-overlapping | #689 | DP | Precompute windows |
| 44 | Best Meeting Point | #296 | Math + Median | Median minimizes distance |
| 45 | K-th Smallest Pair Distance | #719 | Binary Search on Answer | Count pairs |
| 46 | Maximize Distance to Closest Person | #849 | Traversal | Track last person |
| 47 | Minimum Knight Moves | #1197 | BFS | Shortest path |
| 48 | Find K-th Smallest in Sorted Matrix | #378 | Binary Search | Count elements |
| 49 | Minimum Falling Path Sum II | #1289 | DP | Track min and second min |
| 50 | Grid Game | #2017 | Prefix Sum | Two robots |

---

<a name="section-10"></a>
# SECTION 10: ARRAY PROBLEM SOLVING FRAMEWORK

---

## The Decision Tree

```
Given an array problem:

STEP 1: READ CAREFULLY
├── What is the INPUT? (sorted? distinct? range of values?)
├── What is the OUTPUT? (index? count? subarray? boolean?)
└── What are the CONSTRAINTS? (n, values, queries)

STEP 2: RECOGNIZE PATTERN
│
├── "Find element / search" → Binary Search (if sorted) or Linear Search
│
├── "Subarray / substring" →
│   ├── Fixed length → Sliding Window (Fixed)
│   ├── Variable length → Sliding Window (Variable) or Prefix Sum
│   └── Max/Min sum → Kadane's Algorithm
│
├── "Pair / triplet with sum" →
│   ├── Sorted array → Two Pointers
│   └── Unsorted → Hash Map
│
├── "Count occurrences / frequency" → Hash Map / Array
│
├── "Next greater/smaller element" → Monotonic Stack
│
├── "Range queries (sum/min/max)" →
│   ├── Sum only, no updates → Prefix Sum
│   ├── Min/Max only → Sparse Table
│   └── Updates + queries → Segment Tree / Fenwick Tree
│
├── "Minimum / maximum answer" → Binary Search on Answer
│
├── "Intervals" → Sort + Sweep / Greedy
│
├── "Missing / duplicate (values 1..n)" → Cyclic Sort or XOR
│
├── "Sort 0s, 1s, 2s" → Dutch National Flag
│
├── "Matrix traversal" → DFS / BFS / Layer-by-layer
│
└── "Optimal choice at each step" → Greedy

STEP 3: VERIFY
├── Does it handle empty array?
├── Does it handle single element?
├── Does it handle all same elements?
└── Does it handle negative numbers?
```

---

## Common Interview Patterns by Constraint

```
n ≤ 20          → Try all subsets O(2^n), brute force
n ≤ 100         → O(n^3) DP or brute force
n ≤ 1000        → O(n^2) approaches OK
n ≤ 10^4        → O(n log n) sorting/binary search
n ≤ 10^5        → O(n) or O(n log n) required
n ≤ 10^6        → O(n) only
n ≤ 10^9        → O(log n) (binary search on answer)
```

---

## Checklist Before Coding

```
□ Read problem statement twice
□ Note constraints (array size, value range)
□ Think of examples including edge cases
□ Identify the pattern
□ Consider brute force O(n^2) first
□ Think if you can optimize to O(n) or O(n log n)
□ Code the solution
□ Test with examples
□ Check edge cases: empty, single element, all same, negatives, overflow
□ Analyze time and space complexity
```

---

<a name="section-11"></a>
# SECTION 11: COMMON TRICKS

---

## Prefix Sum Tricks
```cpp
// Trick 1: Range sum in O(1)
prefix[r+1] - prefix[l]

// Trick 2: Find if subarray with sum K exists
// Use prefix + hashmap

// Trick 3: 0/1 array equal zeros and ones
// Replace 0 with -1, find longest subarray with sum 0

// Trick 4: Count subarrays with sum div K
// sum % k, handle negatives: (sum%k + k) % k

// Trick 5: 2D range sum
// prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1]
```

## Sliding Window Tricks
```cpp
// Trick 1: ExactlyK = AtMostK - AtMostK-1
// For problems like "exactly k distinct elements"

// Trick 2: Complement approach
// "Subarrays with sum >= target" = total - "subarrays with sum < target"

// Trick 3: Fixed window vs variable
// Fixed: if problem specifies window size
// Variable: if condition must hold, shrink from left when violated
```

## Hashing Tricks
```cpp
// Trick 1: Count pairs with sum S
// For each x, check if (S-x) exists

// Trick 2: Subarray sum equals K
// prefixSum[j] - prefixSum[i] = K → check count[sum-K]

// Trick 3: Sort by frequency
// count freq, then sort by freq descending

// Trick 4: First occurrence
// Only store index if not already in map
```

## Binary Search Tricks
```cpp
// Trick 1: Search on answer
// "Find minimum X such that f(X) is true"
// f must be monotonic

// Trick 2: When to use lower_bound vs upper_bound
// lower_bound: first element >= target
// upper_bound: first element > target
// Count of target = upper_bound - lower_bound

// Trick 3: Avoid overflow
// mid = low + (high - low) / 2

// Trick 4: When low+1 == high, check both
// Useful for floating point binary search
```

## Sorting Tricks
```cpp
// Trick 1: Custom comparator
sort(v.begin(), v.end(), [](auto& a, auto& b) {
    return a.first < b.first;  // Sort by first element
});

// Trick 2: Sort indices (not values)
vector<int> idx(n);
iota(idx.begin(), idx.end(), 0);
sort(idx.begin(), idx.end(), [&](int a, int b){ return arr[a] < arr[b]; });
// idx now gives sorted order of arr

// Trick 3: Partial sort (k-th element)
nth_element(arr.begin(), arr.begin()+k, arr.end());
// arr[k] is the k-th smallest in O(n)

// Trick 4: Sort and reverse
sort(v.rbegin(), v.rend());  // Descending order
```

## Interview Tricks
```cpp
// Trick 1: When stuck, think about prefix sum
// "Something about subarrays?" → prefix sum is usually involved

// Trick 2: Two passes
// Traverse once forward (left info), once backward (right info)

// Trick 3: Running minimum/maximum
// Track min/max seen so far as you traverse

// Trick 4: Reduce to known problem
// Max circular subarray → Kadane + (total - min subarray)

// Trick 5: XOR for single/paired elements
// XOR all → paired elements cancel, single remains
```

---

<a name="section-12"></a>
# SECTION 12: COMMON MISTAKES

---

## Off-By-One Errors

```cpp
// WRONG: Missing last element
for (int i = 0; i < n-1; i++)  // Stops at n-2

// CORRECT
for (int i = 0; i < n; i++)    // Goes to n-1

// WRONG: Binary search loop condition
while (low < high)              // Misses single-element case
while (low <= high)             // Correct for standard binary search

// WRONG: Last element
arr[n]   // Out of bounds! Valid indices are 0 to n-1
arr[n-1] // Correct last element
```

## Index Out of Bounds

```cpp
// WRONG: Accessing without checking
v.pop_back()     // Crash if empty

// CORRECT
if (!v.empty()) v.pop_back()

// WRONG: Negative index
if (v.size() - 1 >= 0)  // v.size() is unsigned, always >= 0!

// CORRECT
if (!v.empty() && (int)v.size() - 1 >= 0)
// Or simpler: if (!v.empty())
```

## Overflow Issues

```cpp
// WRONG: int overflow with large sum
int sum = 0;
for (int x : arr) sum += x;  // Can overflow!

// CORRECT: Use long long
long long sum = 0;
for (int x : arr) sum += x;

// WRONG: Multiplication overflow
int mid = (low + high) / 2;  // (low+high) can overflow

// CORRECT
int mid = low + (high - low) / 2;

// WRONG: Comparing to INT_MIN/INT_MAX
int result = INT_MIN;
result - 1;  // UNDERFLOW!
```

## Binary Search Bugs

```cpp
// Bug 1: Infinite loop with wrong update
while (low < high) {
    int mid = low + (high - low) / 2;
    if (condition) low = mid;    // WRONG! Should be mid+1
    // This causes infinite loop when low+1 == high
}

// Bug 2: Wrong condition direction
if (arr[mid] < target) high = mid - 1;  // WRONG! Should move low
if (arr[mid] < target) low = mid + 1;   // CORRECT

// Bug 3: Forgetting to handle not found
int bsearch(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size()-1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid+1;
        else hi = mid-1;
    }
    return -1;  // Don't forget this!
}
```

## Sliding Window Mistakes

```cpp
// Bug 1: Not shrinking when invalid
for (int right = 0; right < n; right++) {
    add(arr[right]);
    // MUST shrink if window is invalid
    while (isInvalid()) {
        remove(arr[left]);
        left++;
    }
}

// Bug 2: Wrong window size calculation
// Window size = right - left + 1  (not right - left)

// Bug 3: Not handling empty result
int minLen = INT_MAX;
// After loop:
return minLen == INT_MAX ? 0 : minLen;  // Handle "no valid window"
```

## Prefix Sum Mistakes

```cpp
// Bug 1: Wrong indexing
// prefix[i] = sum of first i elements (arr[0..i-1])
// Sum from l to r (inclusive, 0-indexed):
// WRONG: prefix[r] - prefix[l]
// CORRECT: prefix[r+1] - prefix[l]

// Bug 2: Negative modulo
int rem = sum % k;
// rem could be negative in C++!
rem = (rem + k) % k;  // Make it non-negative
```

## Two Pointer Mistakes

```cpp
// Bug 1: Moving wrong pointer
if (sum < target) right--;  // WRONG (moving wrong direction)
if (sum < target) left++;   // CORRECT (need larger sum, move left right)

// Bug 2: Forgetting to skip duplicates in 3Sum
while (l < r && nums[l] == nums[l+1]) l++;  // Need this!
while (l < r && nums[r] == nums[r-1]) r--;  // And this!
l++; r--;
```

---

<a name="section-13"></a>
# SECTION 13: ADVANCED TOPICS

---

## 13.1 Mo's Algorithm

**Use case:** Answer multiple range queries offline in O((n+q)√n).

```cpp
struct Query { int l, r, idx; };

int blockSize;
bool cmp(Query& a, Query& b) {
    int blockA = a.l / blockSize, blockB = b.l / blockSize;
    if (blockA != blockB) return blockA < blockB;
    return (blockA & 1) ? a.r > b.r : a.r < b.r;  // Alternating for efficiency
}

// Template
vector<int> moAlgorithm(vector<int>& arr, vector<pair<int,int>>& queries) {
    int n = arr.size(), q = queries.size();
    blockSize = max(1, (int)sqrt(n));
    vector<Query> qs(q);
    for (int i = 0; i < q; i++) qs[i] = {queries[i].first, queries[i].second, i};
    sort(qs.begin(), qs.end(), cmp);

    vector<int> freq(n+1, 0), answers(q);
    int curL = 0, curR = -1, curAns = 0;

    auto add = [&](int pos) { /* update state when adding arr[pos] */ };
    auto remove = [&](int pos) { /* update state when removing arr[pos] */ };

    for (auto& query : qs) {
        while (curR < query.r) add(++curR);
        while (curL > query.l) add(--curL);
        while (curR > query.r) remove(curR--);
        while (curL < query.l) remove(curL++);
        answers[query.idx] = curAns;
    }
    return answers;
}
```

---

## 13.2 Order Statistics (K-th Element)

### Quickselect — O(n) average
```cpp
int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low == high) return arr[low];
    int pivot = arr[high], i = low;
    for (int j = low; j < high; j++)
        if (arr[j] <= pivot) swap(arr[i++], arr[j]);
    swap(arr[i], arr[high]);
    int pi = i;
    if (pi == k) return arr[pi];
    else if (pi < k) return quickSelect(arr, pi+1, high, k);
    else return quickSelect(arr, low, pi-1, k);
}

int kthSmallest(vector<int>& arr, int k) {
    return quickSelect(arr, 0, arr.size()-1, k-1);
}
```

---

## 13.3 Range Queries Summary

| Problem | Best Solution | Build Time | Query Time | Update Time |
|---|---|---|---|---|
| Range Sum | Prefix Array | O(n) | O(1) | — |
| Range Sum + Update | Fenwick Tree | O(n log n) | O(log n) | O(log n) |
| Range Min/Max | Sparse Table | O(n log n) | O(1) | — |
| Range Min/Max + Update | Segment Tree | O(n) | O(log n) | O(log n) |
| Range GCD | Sparse Table | O(n log n) | O(1) | — |
| Range Update + Query | Lazy Segment Tree | O(n) | O(log n) | O(log n) |

---

<a name="section-14"></a>
# SECTION 14: REVISION CHEAT SHEET

---

## One-Page Revision

```
ARRAYS:
  Access: O(1) | Search (unsorted): O(n) | Search (sorted): O(log n)
  Insert/Delete at end: O(1) | Insert/Delete at middle: O(n)
  Static: stack, fixed size | Dynamic (Vector): heap, resizable

VECTOR:
  push_back: O(1) amortized | pop_back: O(1)
  insert/erase: O(n) | size/capacity: O(1)
  reserve before bulk insert | shrink_to_fit to free memory

KEY ALGORITHMS:
  Kadane (Max Subarray): curSum = max(x, curSum+x), track maxSum
  Moore Voting (Majority): cancel pairs, verify
  Dutch Flag: low/mid/high pointers, swap
  Two Pointers: opposite (sorted) or same direction
  Prefix Sum: prefix[i+1] = prefix[i] + arr[i], sum[l..r] = p[r+1]-p[l]
  Sliding Window: expand right, shrink left when invalid
  Binary Search: mid = low+(high-low)/2, move low/high

SORTING:
  O(n²): Bubble, Selection, Insertion (small n, or nearly sorted)
  O(n log n): Merge (stable), Quick (cache), Heap (in-place)
  O(n+k): Counting, Radix (small range)

PATTERN IDENTIFICATION:
  Subarray sum → Prefix Sum + HashMap
  Max/min subarray → Kadane
  Sorted array pair → Two Pointers
  Next greater element → Monotonic Stack
  Sliding max/min → Monotonic Deque
  Missing/duplicate 1..n → Cyclic Sort or XOR
  Range query no update → Prefix Sum / Sparse Table
  Range query + update → Segment Tree / Fenwick Tree
```

---

## Complexity Reference Table

| Pattern | Time | Space |
|---|---|---|
| Linear Scan | O(n) | O(1) |
| Binary Search | O(log n) | O(1) |
| Prefix Sum Build | O(n) | O(n) |
| Prefix Sum Query | O(1) | — |
| Sliding Window | O(n) | O(1) or O(k) |
| Sorting-based | O(n log n) | O(1) or O(n) |
| Kadane | O(n) | O(1) |
| Two Pointers | O(n) | O(1) |
| Monotonic Stack | O(n) | O(n) |
| Hash Map approach | O(n) | O(n) |
| Fenwick Tree | O(log n) per op | O(n) |
| Segment Tree | O(log n) per op | O(n) |
| Sparse Table | O(1) query | O(n log n) |
| Quick Sort | O(n log n) avg | O(log n) |
| Merge Sort | O(n log n) | O(n) |

---

## Pattern Identification Quick Reference

| Clue in Problem | Try This Pattern |
|---|---|
| "Sorted array, find X" | Binary Search |
| "Subarray with property" | Sliding Window |
| "Subarray sum = K" | Prefix Sum + HashMap |
| "Max/min subarray sum" | Kadane's |
| "Two elements sum to X" | Two Pointers (sorted) or HashMap |
| "Appears more than n/2 times" | Moore's Voting |
| "Next greater element" | Monotonic Stack |
| "Max in sliding window" | Monotonic Deque |
| "Sort 0s, 1s, 2s" | Dutch National Flag |
| "Missing/duplicate 1..n" | Cyclic Sort |
| "Range sum queries" | Prefix Sum |
| "Interval merge/overlap" | Sort by start + merge |
| "Matrix rotation" | Transpose + reverse |
| "k-th smallest/largest" | Quickselect or Min-heap |
| "XOR of some elements" | Bit Manipulation |

---

## Common C++ STL Tricks for Arrays

```cpp
// Sort descending
sort(v.rbegin(), v.rend());

// Max and min element
*max_element(v.begin(), v.end());
*min_element(v.begin(), v.end());

// Sum of all elements
accumulate(v.begin(), v.end(), 0LL);

// Reverse in-place
reverse(v.begin(), v.end());

// Binary search (must be sorted)
binary_search(v.begin(), v.end(), target);  // bool
lower_bound(v.begin(), v.end(), target);    // iterator to first >= target
upper_bound(v.begin(), v.end(), target);    // iterator to first > target

// Remove duplicates (sort first)
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

// Fill vector
fill(v.begin(), v.end(), 0);

// Initialize with sequence (0,1,2,...)
iota(v.begin(), v.end(), 0);

// Rotate left by k
rotate(v.begin(), v.begin()+k, v.end());

// Count occurrences
count(v.begin(), v.end(), target);

// Partition
partition(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
```

---

<a name="section-15"></a>
# SECTION 15: FINAL ARRAY MASTERY ROADMAP

---

## Complete Learning Path

```
WEEK 1-2: FOUNDATIONS (Beginner)
────────────────────────────────
Day 1: Arrays basics, memory model, C++ array syntax
Day 2: Vector operations (all methods), 2D vectors
Day 3: Linear search, Binary search (iterative + recursive)
Day 4: Basic sorting (Bubble, Selection, Insertion)
Day 5: Array operations (reverse, rotate, merge)
Day 6-7: LeetCode Easy (problems 1-20 from Easy list)

Practice Problems:
  LeetCode: #1, #26, #27, #66, #88, #121, #136, #169, #189, #217

WEEK 3-4: CORE PATTERNS (Intermediate)
────────────────────────────────────────
Day 8: Prefix Sum (1D and 2D)
Day 9: Sliding Window (fixed and variable)
Day 10: Two Pointers (opposite and same direction)
Day 11: Hashing with arrays
Day 12: Merge Sort, Quick Sort
Day 13: Kadane's Algorithm + variants
Day 14: LeetCode Medium (problems 1-30 from Medium list)

Practice Problems:
  LeetCode: #53, #56, #75, #128, #152, #153, #167, #238, #239, #560

WEEK 5-6: ADVANCED PATTERNS
────────────────────────────
Day 15: Monotonic Stack
Day 16: Monotonic Queue (Deque)
Day 17: Binary Search on Answer
Day 18: Cyclic Sort and bit manipulation tricks
Day 19: Dutch National Flag, Merge Intervals
Day 20: Matrix problems (spiral, rotate, search)
Day 21: LeetCode Medium (problems 31-70)

Practice Problems:
  LeetCode: #42, #84, #85, #239, #287, #303, #347, #739, #875, #907

WEEK 7-8: EXPERT LEVEL
────────────────────────
Day 22: Segment Trees (concept + implementation)
Day 23: Fenwick Trees (BIT)
Day 24: Sparse Table (RMQ)
Day 25: Mo's Algorithm
Day 26: Coordinate Compression, Sweep Line
Day 27-28: LeetCode Hard (problems 1-20 from Hard list)

Practice Problems:
  LeetCode: #4, #41, #315, #493, #719, #862, #1687

WEEK 9-10: INTERVIEW PREP
───────────────────────────
Day 29-30: Mock interviews (timed)
Day 31: Review all patterns + cheat sheet
Day 32: Company-specific problems (Amazon, Google, Meta)
Day 33: Advanced optimizations
Day 34-35: Final revision of all 20 patterns

MONTHLY REVISION PLAN
──────────────────────
Week 1 of each month:
  - Re-solve Easy problems (10 per day)
  - Review pattern cheat sheet

Week 2:
  - Re-solve Medium problems (5 per day)
  - Focus on weak patterns

Week 3:
  - Hard problems (2-3 per day)
  - System design + algorithmic thinking

Week 4:
  - Mock interviews
  - Compete on Codeforces/CF Rounds
```

---

## Recommended LeetCode Study Order

```
PHASE 1 — Easy foundation (do all of these):
  Arrays: #1, #26, #27, #35, #66, #88, #121, #136, #169, #189,
          #217, #268, #283, #349, #448, #485, #724, #977

PHASE 2 — Key medium problems:
  Two Pointers: #11, #15, #75, #167, #977
  Sliding Window: #3, #76, #209, #239, #424, #438, #567, #904
  Prefix Sum: #303, #304, #525, #560, #974
  Kadane: #53, #121, #152, #918
  Binary Search: #33, #34, #35, #153, #162, #278, #875
  Sorting: #56, #57, #75, #179, #215, #347
  Monotonic Stack: #496, #503, #739, #901, #907

PHASE 3 — Key hard problems:
  #4, #41, #42, #84, #85, #287, #315, #493, #862

PHASE 4 — Company-specific:
  Google: #4, #42, #84, #218, #239, #315
  Amazon: #1, #121, #347, #560, #973
  Meta: #11, #15, #56, #57, #253
  Microsoft: #33, #34, #35, #88, #153
```

---

## Competitive Programming Path

```
For competitive programming (Codeforces, ICPC, CodeChef):

Level 1 (Div 4, Div 3):
  - All basic operations
  - Prefix sum, sliding window
  - Standard binary search
  - Basic sorting

Level 2 (Div 2 A-C):
  - All patterns 1-12
  - Segment trees (basic)
  - Fenwick trees

Level 3 (Div 2 D-E, Div 1 A-B):
  - All 20 patterns
  - Lazy propagation in segment trees
  - Mo's algorithm
  - Offline techniques
  - Advanced binary search

Level 4 (Div 1 C-E):
  - Sqrt decomposition
  - Persistent data structures
  - Advanced techniques
```

---

## Interview Ready Checklist

```
Before your interview, make sure you can:

□ Code binary search from memory in 2 minutes
□ Implement sliding window for any problem type
□ Write Kadane's algorithm in 1 minute
□ Build and query prefix sum array
□ Implement merge sort and quicksort
□ Solve Two Sum and all variants
□ Explain Dutch National Flag algorithm
□ Use monotonic stack for next greater element
□ Implement BFS/DFS on matrix
□ Rotate a matrix in-place
□ Find missing number using multiple approaches
□ Handle all edge cases (empty, single, negatives)
□ Analyze time and space complexity correctly
□ Communicate your thought process clearly

Remember:
  1. Clarify before coding
  2. Start with brute force
  3. Optimize to final solution
  4. Code clean, readable code
  5. Test with examples and edge cases
  6. Analyze complexity at the end
```

---

# FINAL NOTES

---

> **"Arrays are the foundation. Master them and you master DSA."**

Key takeaways:
- **O(1) access** is the superpower of arrays
- **Prefix sums** convert range queries from O(n) to O(1)
- **Sliding window** converts O(n²) subarray problems to O(n)
- **Two pointers** eliminate brute-force nested loops
- **Monotonic stack/queue** solve "next greater/max in window" in O(n)
- **Binary search** applies not just to sorted arrays but to any monotonic function
- **Sorting** unlocks a huge family of simplifications
- **Hashing** trades space for time — O(n) from O(n²)

Practice consistently. Solve 5 problems daily. Review weekly. And most importantly — **understand the pattern, not just the code**.

---

*Handbook compiled for maximum DSA preparation coverage.*
*Total patterns: 20 | Total problems listed: 200+ | Algorithms covered: 30+*
*Suitable for: Beginners → FAANG interview preparation → Competitive Programming*

---