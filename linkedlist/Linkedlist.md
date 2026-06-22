# 🔗 The Ultimate Linked List Handbook

> **From Zero to Hero — Complete Guide for Beginners, Placement, OA, Competitive Programming & Technical Interviews**

---

## 📋 Table of Contents

| Section | Topic |
|---------|-------|
| 1 | [Linked List Fundamentals](#section-1-linked-list-fundamentals) |
| 2 | [Node Structure](#section-2-node-structure) |
| 3 | [Types of Linked Lists](#section-3-types-of-linked-lists) |
| 4 | [Linked List Memory Model](#section-4-linked-list-memory-model) |
| 5 | [Complexity Analysis](#section-5-complexity-analysis) |
| 6 | [Basic Operations](#section-6-basic-operations) |
| 7 | [Reversal Techniques](#section-7-reversal-techniques) |
| 8 | [Fast and Slow Pointer Pattern](#section-8-fast-and-slow-pointer-pattern) |
| 9 | [Important Linked List Patterns](#section-9-important-linked-list-patterns) |
| 10 | [Cycle Problems](#section-10-cycle-problems) |
| 11 | [Merging Problems](#section-11-merging-problems) |
| 12 | [Important Linked List Algorithms](#section-12-important-linked-list-algorithms) |
| 13 | [Sorting Linked Lists](#section-13-sorting-linked-lists) |
| 14 | [Doubly Linked List Mastery](#section-14-doubly-linked-list-mastery) |
| 15 | [Circular Linked List Mastery](#section-15-circular-linked-list-mastery) |
| 16 | [Interview Framework](#section-16-interview-framework) |
| 17 | [Common Tricks](#section-17-common-tricks) |
| 18 | [Common Mistakes](#section-18-common-mistakes) |
| 19 | [Complete Linked List Question List](#section-19-complete-linked-list-question-list) |
| 20 | [Revision Cheat Sheet](#section-20-revision-cheat-sheet) |
| 21 | [Final Roadmap](#section-21-final-roadmap) |

---

# SECTION 1: LINKED LIST FUNDAMENTALS

## 1.1 What is a Linked List?

### Definition

A **Linked List** is a linear data structure where elements (called **nodes**) are stored in non-contiguous memory locations. Each node holds:
1. **Data** — the value stored
2. **Pointer** — the address of the next node

Unlike arrays, linked list elements are **not stored sequentially** in memory. They are scattered across the heap, and each node knows where the next one lives.

### Intuition

Think of a **treasure hunt**:
- You start at the first clue (head node).
- Each clue (node) tells you the data AND where to find the next clue (pointer to next node).
- The last clue says "END" (null pointer).

```
[Clue 1: Data=10, Next→] ──► [Clue 2: Data=20, Next→] ──► [Clue 3: Data=30, Next=NULL]
```

Another analogy: **A train**. Each coach (node) is connected to the next coach (pointer). You can add or remove coaches without rearranging the whole train.

### Visual Representation

```
HEAD
 │
 ▼
┌──────┬──────┐    ┌──────┬──────┐    ┌──────┬──────┐
│  10  │  ●───┼───►│  20  │  ●───┼───►│  30  │ NULL │
└──────┴──────┘    └──────┴──────┘    └──────┴──────┘
  Node 1              Node 2              Node 3

[data | next*]      [data | next*]      [data | next*]
```

---

## 1.2 Why Linked Lists Exist

Arrays are great, but they have limitations:

| Problem with Arrays | How Linked Lists Solve It |
|---------------------|--------------------------|
| Fixed size at declaration | Dynamic size — grows/shrinks at runtime |
| Insertion in middle costs O(n) shifting | Insertion anywhere costs O(1) with a pointer |
| Deletion costs O(n) shifting | Deletion costs O(1) with correct pointer |
| Contiguous memory required | Non-contiguous — uses any free heap memory |

**When would you want a linked list over an array?**
- When you don't know the number of elements in advance
- When you frequently insert/delete from the beginning or middle
- When you want efficient memory utilization

---

## 1.3 Real-World Applications

| Application | How Linked List is Used |
|-------------|------------------------|
| Browser History | Doubly linked list — forward/back navigation |
| Music Playlist | Circular linked list — loop through songs |
| Undo/Redo in editors | Doubly linked list — previous/next states |
| OS Process Scheduling | Circular linked list — round-robin scheduling |
| Hash Table Chaining | Singly linked list — collision handling |
| Memory Allocator (malloc) | Free block list management |
| Polynomial Representation | Each term is a node |
| Adjacency List in Graphs | Linked list per vertex |
| LRU Cache | Doubly linked list + HashMap |
| Stack / Queue Implementation | Linked list as underlying structure |

---

## 1.4 Node Structure

### Data Field

The **data field** stores the actual value. It can be:
- `int`, `float`, `char`
- A string
- A struct or object
- A pointer to another object

### Pointer Field

The **pointer field** stores the **memory address** of the next node. In C++, this is `Node*` — a pointer to another Node.

```
┌───────────────────────────────┐
│           NODE                │
│  ┌──────────┬───────────────┐ │
│  │   data   │    next*      │ │
│  │  (int)   │  (Node ptr)   │ │
│  └──────────┴───────────────┘ │
└───────────────────────────────┘
```

---

## 1.5 Dynamic Memory Allocation

In C++, linked list nodes live on the **heap** (not the stack). We use `new` to allocate:

```cpp
Node* node = new Node();   // Allocates memory on heap
node->data = 10;
node->next = nullptr;
```

Memory is freed using `delete`:
```cpp
delete node;   // Returns heap memory to OS
```

---

## 1.6 Memory Representation

```
Stack Memory          Heap Memory (scattered addresses)
─────────────         ────────────────────────────────
head → 0x1000         Address 0x1000: [10 | 0x2048]
                      Address 0x2048: [20 | 0x3100]
                      Address 0x3100: [30 | NULL   ]
```

The variable `head` lives on the **stack** and holds the address `0x1000`. That address points into the **heap** where the actual nodes live.

---

## 1.7 Linked List vs Array

| Feature | Array | Linked List |
|---------|-------|-------------|
| Memory | Contiguous | Non-contiguous |
| Size | Fixed (static) | Dynamic |
| Access | O(1) Random Access | O(n) Sequential |
| Search | O(1) index / O(n) value | O(n) |
| Insert at beginning | O(n) — shifting required | O(1) |
| Insert at end | O(1) amortized | O(n) or O(1) with tail ptr |
| Insert at middle | O(n) | O(n) search + O(1) insert |
| Delete at beginning | O(n) — shifting required | O(1) |
| Delete at end | O(1) | O(n) |
| Cache performance | Excellent (locality) | Poor (scattered) |
| Memory overhead | None | Extra pointer per node |
| Implementation | Simple | More complex |

---

## 1.8 Advantages of Linked Lists

1. **Dynamic Size** — No pre-allocation needed; grow/shrink at runtime
2. **Efficient Insertions/Deletions** — O(1) at head with pointer update
3. **No Memory Waste** — Allocate exactly what you need
4. **Flexible Memory Use** — No need for large contiguous blocks
5. **Natural for Queues/Stacks** — Clean push/pop implementation
6. **Building Block** — Foundation for hash tables, graphs, etc.

---

## 1.9 Disadvantages of Linked Lists

1. **No Random Access** — Must traverse from head; O(n) to reach index k
2. **Extra Memory** — Each node carries a pointer (8 bytes on 64-bit systems)
3. **Poor Cache Performance** — Nodes scattered in memory; many cache misses
4. **No Backward Traversal** (Singly) — Must traverse forward only
5. **Complex Implementation** — Pointer manipulation is error-prone
6. **Not Suitable for Binary Search** — Can't jump to middle in O(1)

---

# SECTION 2: NODE STRUCTURE

## 2.1 Creating a Node in C++

### Basic Node (Singly Linked List)

```cpp
class Node {
public:
    int data;      // The value stored
    Node* next;    // Pointer to the next node

    // Default constructor
    Node() {
        data = 0;
        next = nullptr;
    }

    // Parameterized constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
```

### Node with Multiple Data Types

```cpp
// Generic node using templates
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T val) : data(val), next(nullptr) {}
};
```

### Doubly Linked List Node

```cpp
class DLLNode {
public:
    int data;
    DLLNode* prev;   // Points to previous node
    DLLNode* next;   // Points to next node

    DLLNode(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};
```

---

## 2.2 Memory Allocation

### Stack vs Heap Allocation

```cpp
// Stack allocation (automatic, limited size, dies when scope ends)
Node stackNode;          // Lives on stack — NOT recommended for LL
stackNode.data = 10;

// Heap allocation (manual, large, persists until deleted)
Node* heapNode = new Node(10);   // Lives on heap — USE THIS
```

### Why Heap Allocation for Linked Lists?

```
Stack frame (function scope):          Heap (program lifetime):
────────────────────────────           ─────────────────────────
│ head → 0x5000          │             │ 0x5000: [10 | 0x6000] │
│ temp → 0x7000          │             │ 0x6000: [20 | NULL   ] │
│ (dies when fn returns) │             │ (persists until delete)│
└────────────────────────┘             └────────────────────────┘
```

---

## 2.3 Pointer Basics

```cpp
int x = 42;
int* ptr = &x;      // ptr holds ADDRESS of x

cout << x;          // 42        (value)
cout << &x;         // 0x7fff... (address of x)
cout << ptr;        // 0x7fff... (same address)
cout << *ptr;       // 42        (dereference — value at address)

// For objects:
Node* node = new Node(10);
cout << node;         // Address of node on heap
cout << node->data;   // 10 (same as (*node).data)
cout << node->next;   // nullptr (or address of next node)
```

### Pointer Diagram

```
 ptr                 Heap
 ───                 ────
[0x5000] ──────────► 0x5000: [ data=10 | next=0x6000 ]
                                               │
                     0x6000: [ data=20 | next=NULL ] ◄──┘
```

---

## 2.4 Address Storage

```cpp
Node* head = nullptr;   // head points to nothing

// Create first node
head = new Node(10);    // head now points to node with data=10

// Create second node and link
Node* second = new Node(20);
head->next = second;    // first node's next points to second node

// Create third node and link
Node* third = new Node(30);
second->next = third;   // second's next points to third

// Now: head → [10|→] → [20|→] → [30|NULL]
```

### Memory Layout Diagram

```
Variable    Address    Value
─────────────────────────────────────────────────────
head        stack      0x1000    (points to first node)
            
Heap:
0x1000    [ data=10 | next=0x2000 ]
0x2000    [ data=20 | next=0x3000 ]
0x3000    [ data=30 | next=NULL   ]
```

---

# SECTION 3: TYPES OF LINKED LISTS

## 3.1 Singly Linked List (SLL)

### Structure

Each node has **one pointer** pointing to the next node. Traversal is one-directional (forward only).

```
HEAD
 │
 ▼
[1|→] → [2|→] → [3|→] → [4|NULL]
```

### C++ Implementation

```cpp
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() : head(nullptr) {}
};
```

### Memory Layout

```
Address:  0x100       0x200       0x300       0x400
          ┌────┬────┐ ┌────┬────┐ ┌────┬────┐ ┌────┬────┐
          │ 1  │200 │ │ 2  │300 │ │ 3  │400 │ │ 4  │NULL│
          └────┴────┘ └────┴────┘ └────┴────┘ └────┴────┘
```

### Advantages
- Simple implementation
- Less memory (one pointer per node)
- Efficient for forward traversal and front insertions/deletions

### Disadvantages
- No backward traversal
- Accessing previous node requires full traversal from head

### Applications
- Implementing stacks
- Hash table chaining
- Simple queues

### Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Access/Search | O(n) | O(1) |
| Insert at head | O(1) | O(1) |
| Insert at tail | O(n) | O(1) |
| Delete at head | O(1) | O(1) |
| Delete at tail | O(n) | O(1) |

---

## 3.2 Doubly Linked List (DLL)

### Structure

Each node has **two pointers**: one to the next node, one to the previous node. Traversal is **bi-directional**.

```
        HEAD                                    TAIL
         │                                       │
         ▼                                       ▼
NULL ←[1|→] ⇄ [←|2|→] ⇄ [←|3|→] ⇄ [←|4]→ NULL
```

More precisely:

```
NULL ← [NULL|1|0x200] ⇄ [0x100|2|0x300] ⇄ [0x200|3|0x400] ⇄ [0x300|4|NULL]
```

### C++ Implementation

```cpp
class DLLNode {
public:
    int data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    DLLNode* head;
    DLLNode* tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
};
```

### Memory Layout

```
        prev  data  next         prev  data  next
        ┌────┬────┬────┐         ┌────┬────┬────┐
NULL ◄──│NULL│ 1  │ ●──┼────►◄──┼─●  │ 2  │ ●──┼──► ...
        └────┴────┴────┘         └────┴────┴────┘
          Node 1                   Node 2
```

### Advantages
- Bidirectional traversal
- O(1) deletion given node pointer
- Efficient deque operations
- LRU Cache implementation

### Disadvantages
- More memory (two pointers per node)
- More complex pointer management
- Higher chance of pointer errors

### Applications
- Browser forward/back navigation
- LRU Cache
- Undo/Redo functionality
- Deque (double-ended queue)

### Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Access/Search | O(n) | O(1) |
| Insert at head | O(1) | O(1) |
| Insert at tail | O(1) with tail ptr | O(1) |
| Delete at head | O(1) | O(1) |
| Delete at tail | O(1) with tail ptr | O(1) |
| Delete given node | O(1) | O(1) |

---

## 3.3 Circular Linked List (CLL)

### Structure

The **last node** points back to the **head** instead of null. There is no null terminator. Traversal can continue indefinitely.

```
      HEAD
       │
       ▼
  ┌──[1|→]──►[2|→]──►[3|→]──►[4|→]──┐
  │                                   │
  └───────────────────────────────────┘
           (last node → head)
```

### C++ Implementation

```cpp
class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

// To create circular list:
// lastNode->next = head;  (link last back to head)
```

### Key Property

```
// Detect if a node is the last node in circular list:
if (current->next == head) {
    // current is the last node
}
```

### Advantages
- No null pointer — useful for round-robin systems
- Traversal can start from any node
- Efficient for queue implementations

### Disadvantages
- Risk of infinite loops if not careful
- More complex traversal termination logic

### Applications
- Round-robin CPU scheduling
- Music playlist (loop)
- Circular buffer
- Josephus problem

### Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Traversal | O(n) | O(1) |
| Insert at head | O(1) | O(1) |
| Insert at tail | O(1) if tail ptr available | O(1) |
| Delete head | O(1) | O(1) |

---

## 3.4 Circular Doubly Linked List (CDLL)

### Structure

Combines Doubly + Circular: the **last node's next** points to **head**, and **head's prev** points to the **last node**.

```
    ┌──────────────────────────────────────────┐
    │    HEAD                           TAIL   │
    │     │                              │     │
    ▼     ▼                              ▼     ▼
    └──►[←|1|→]⇄[←|2|→]⇄[←|3|→]⇄[←|4|→]────┘
```

### C++ Implementation

```cpp
class CDLLNode {
public:
    int data;
    CDLLNode* prev;
    CDLLNode* next;
    CDLLNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Setup:
// head->prev = tail;
// tail->next = head;
```

### Advantages
- Bidirectional traversal + circular property
- No null pointers anywhere
- Efficient insert/delete at both ends

### Disadvantages
- Most complex pointer management
- Highest memory overhead (two pointers)

### Applications
- Deque with circular buffer
- OS scheduling (advanced)
- Fibonacci heap implementation

### Dry Run: Creating a CDLL with 3 nodes

```
Step 1: Insert 1
  head → [←|1|→]
  head->prev = head (points to itself)
  head->next = head (points to itself)
  
Step 2: Insert 2 after 1
  head → [←|1|→] ⇄ [←|2|→] (circular)
  node2->next = head
  node2->prev = node1
  head->prev = node2
  node1->next = node2

Step 3: Insert 3 after 2
  [←|1|→] ⇄ [←|2|→] ⇄ [←|3|→] (circular, 3's next = 1)
```

---

# SECTION 4: LINKED LIST MEMORY MODEL

## 4.1 Heap Memory

```
Memory Layout of a Running Program:
─────────────────────────────────────
│         Stack (local variables)   │ ← grows downward
│─────────────────────────────────  │
│                                   │
│                                   │
│─────────────────────────────────  │
│   Heap (dynamic allocation)       │ ← grows upward
│─────────────────────────────────  │
│   BSS Segment (uninitialized)     │
│   Data Segment (globals)          │
│   Text Segment (code)             │
─────────────────────────────────────
```

- `new Node()` allocates from the **heap**
- `delete node` releases back to the heap
- The heap is managed by the OS and allocator (like `malloc`)

---

## 4.2 Dynamic Allocation

```cpp
Node* p = new Node(5);
// new does three things:
// 1. Requests sizeof(Node) bytes from heap
// 2. Constructs the Node object at that address
// 3. Returns the address (stored in p)

delete p;
// 1. Calls Node's destructor
// 2. Returns memory to heap
// p still holds the old address! (now dangling pointer)
p = nullptr;  // Always set to nullptr after delete
```

---

## 4.3 Pointer Connections (Visual)

```
Creating: 10 → 20 → 30

Step 1:
  head = new Node(10)
  
  Stack: [head=0xA00]    Heap: 0xA00:[10|NULL]

Step 2:
  head->next = new Node(20)
  
  Stack: [head=0xA00]    Heap: 0xA00:[10|0xB00]
                               0xB00:[20|NULL]

Step 3:
  head->next->next = new Node(30)
  
  Stack: [head=0xA00]    Heap: 0xA00:[10|0xB00]
                               0xB00:[20|0xC00]
                               0xC00:[30|NULL]
```

---

## 4.4 Null Pointer

```cpp
Node* ptr = nullptr;   // ptr points to address 0 (nothing)

// Dereferencing null pointer → CRASH (Segmentation Fault)
ptr->data = 10;   // ❌ UNDEFINED BEHAVIOR!

// Always check before dereferencing:
if (ptr != nullptr) {
    ptr->data = 10;   // ✅ Safe
}
```

**Common crash pattern:**
```cpp
Node* curr = head;
while (curr->next != nullptr) {   // Crashes if head is null!
    curr = curr->next;
}
// Fix:
while (curr != nullptr && curr->next != nullptr) { ... }
```

---

## 4.5 Dangling Pointer

A **dangling pointer** points to memory that has been freed (deleted). Accessing it is undefined behavior.

```cpp
Node* a = new Node(10);
Node* b = a;          // b and a point to the same node

delete a;             // Memory freed
a = nullptr;          // a is safe

// b is now a DANGLING POINTER — memory freed but b still holds old address
cout << b->data;      // ❌ UNDEFINED BEHAVIOR!

// Fix: set b = nullptr too, or don't delete while b is alive
```

---

## 4.6 Memory Leaks

A **memory leak** occurs when heap memory is allocated but never freed. In linked lists:

```cpp
// MEMORY LEAK: lost reference to entire list
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);

head = nullptr;   // All three nodes are now LEAKED!
// We lost the only reference (head) to the chain.
// Those nodes can never be deleted.
```

**Correct cleanup:**
```cpp
void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;   // Move first, then delete
        delete temp;
    }
}
```

**Why this order matters:**
```
Wrong:                         Correct:
delete head;                   temp = head;       // Save current
head = head->next; // CRASH!   head = head->next; // Move forward
                               delete temp;        // Delete saved
```

---

# SECTION 5: COMPLEXITY ANALYSIS

## 5.1 Complete Complexity Table — Singly Linked List

| Operation | Time Complexity | Space Complexity | Notes |
|-----------|----------------|-----------------|-------|
| Access by index | O(n) | O(1) | Must traverse from head |
| Search by value | O(n) | O(1) | Linear scan |
| Insert at head | O(1) | O(1) | Just update head |
| Insert at tail | O(n) | O(1) | Must traverse to end |
| Insert at tail (with tail ptr) | O(1) | O(1) | If tail pointer maintained |
| Insert at middle | O(n) | O(1) | O(n) to find + O(1) to insert |
| Delete at head | O(1) | O(1) | Update head to head→next |
| Delete at tail | O(n) | O(1) | Must find second-to-last |
| Delete at middle | O(n) | O(1) | O(n) to find + O(1) to delete |
| Delete by value | O(n) | O(1) | Linear scan to find |
| Traversal | O(n) | O(1) | Visit every node |
| Reverse (iterative) | O(n) | O(1) | Single pass |
| Reverse (recursive) | O(n) | O(n) | O(n) call stack |
| Find middle | O(n) | O(1) | Fast-slow pointer |
| Detect cycle | O(n) | O(1) | Floyd's algorithm |
| Merge two sorted lists | O(m+n) | O(1) | Two pointer merge |
| Sort (merge sort) | O(n log n) | O(log n) | Best sort for LL |

## 5.2 Complexity Comparison: SLL vs DLL vs Array

| Operation | Array | SLL | DLL |
|-----------|-------|-----|-----|
| Random Access | O(1) | O(n) | O(n) |
| Insert at head | O(n) | O(1) | O(1) |
| Insert at tail | O(1)* | O(n) | O(1)** |
| Insert at middle | O(n) | O(n) | O(n) |
| Delete at head | O(n) | O(1) | O(1) |
| Delete at tail | O(1) | O(n) | O(1)** |
| Delete at middle | O(n) | O(n) | O(1)*** |
| Search | O(n) | O(n) | O(n) |
| Space per element | 1 unit | 1 unit + 1 ptr | 1 unit + 2 ptrs |

*Amortized (dynamic array)  
**With tail pointer  
***Given a direct pointer to the node  

## 5.3 Why These Complexities?

**O(1) Insert at head (SLL):**
```
new_node->next = head;   // 1 operation
head = new_node;          // 1 operation
// Total: constant time regardless of list size
```

**O(n) Insert at tail (SLL, no tail ptr):**
```
// Must traverse entire list to find last node
Node* curr = head;
while (curr->next != nullptr)  // visits n nodes
    curr = curr->next;
curr->next = new_node;  // O(1) once found
```

**O(n) Access by index:**
```
// Cannot jump to index k like array[k]
// Must walk k steps from head
Node* curr = head;
for (int i = 0; i < k; i++)
    curr = curr->next;  // k iterations
```

---

# SECTION 6: BASIC OPERATIONS

## 6.1 Traversal

### Concept
Visit every node exactly once, from head to null.

### Visualization
```
head → [1] → [2] → [3] → [4] → NULL
        ↑
       curr (start)

Step 1: print 1, curr = curr→next
Step 2: print 2, curr = curr→next
Step 3: print 3, curr = curr→next
Step 4: print 4, curr = curr→next
Step 5: curr == NULL → STOP
```

### C++ Code
```cpp
void traverse(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
```

### Dry Run
```
List: 1 → 2 → 3 → NULL
curr = head (→ node 1)
Iteration 1: print 1, curr = node2
Iteration 2: print 2, curr = node3
Iteration 3: print 3, curr = NULL
Loop ends. Output: 1 2 3
```

### Complexity
- Time: O(n)
- Space: O(1)

### Common Mistakes
```cpp
// ❌ Wrong: modifying head directly
while (head != nullptr) {
    cout << head->data;
    head = head->next;  // Destroys head reference!
}

// ✅ Correct: use a temp pointer
Node* curr = head;
while (curr != nullptr) {
    cout << curr->data;
    curr = curr->next;
}
```

---

## 6.2 Search

### Concept
Find a node with a given value. Return the node (or index, or true/false).

### C++ Code
```cpp
// Returns pointer to node with target value, or nullptr
Node* search(Node* head, int target) {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == target)
            return curr;   // Found!
        curr = curr->next;
    }
    return nullptr;   // Not found
}

// Returns 0-based index of target, or -1
int searchIndex(Node* head, int target) {
    Node* curr = head;
    int index = 0;
    while (curr != nullptr) {
        if (curr->data == target)
            return index;
        curr = curr->next;
        index++;
    }
    return -1;
}
```

### Dry Run
```
List: 10 → 20 → 30 → 40 → NULL, target = 30

curr=10: 10 ≠ 30 → move
curr=20: 20 ≠ 30 → move
curr=30: 30 == 30 → RETURN node(30)
```

### Complexity
- Time: O(n) worst case, O(1) best case (head matches)
- Space: O(1)

---

## 6.3 Insert at Beginning

### Concept
Create a new node and make it the new head. Point new node's next to old head.

### Visualization
```
Before: head → [1] → [2] → [3] → NULL

Insert 0 at beginning:
  new_node = [0|→]
  new_node->next = head  →  [0|→] → [1] → [2] → [3] → NULL
  head = new_node        →  head points to [0]

After: head → [0] → [1] → [2] → [3] → NULL
```

### C++ Code
```cpp
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}
// Note: head is passed by reference (Node*&) so we can modify it
```

### Dry Run
```
Initial: head → [10] → [20] → NULL

Call insertAtHead(head, 5):
  newNode = new Node(5)   →   [5|NULL]
  newNode->next = head    →   [5|→10]
  head = newNode          →   head points to [5]

Result: head → [5] → [10] → [20] → NULL
```

### Complexity
- Time: O(1)
- Space: O(1)

### Edge Cases
- Empty list: `newNode->next = nullptr`, `head = newNode` — works correctly

---

## 6.4 Insert at End

### Concept
Traverse to the last node. Set last node's next to new node.

### Visualization
```
Before: head → [1] → [2] → [3] → NULL

Insert 4 at end:
  Traverse to [3] (where next == NULL)
  new_node = [4|NULL]
  [3]→next = new_node

After: head → [1] → [2] → [3] → [4] → NULL
```

### C++ Code
```cpp
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* curr = head;
    while (curr->next != nullptr)
        curr = curr->next;
    curr->next = newNode;
}
```

### Dry Run
```
List: [1] → [2] → NULL, insert 3

curr = head = node(1)
curr->next = node(2) ≠ NULL → move: curr = node(2)
curr->next = NULL → STOP
curr->next = new Node(3)

Result: [1] → [2] → [3] → NULL
```

### Complexity
- Time: O(n)
- Space: O(1)

### Optimization with Tail Pointer
```cpp
class LinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};
// Now insertAtTail is O(1)!
```

---

## 6.5 Insert at Position

### Concept
Traverse to the node BEFORE the target position. Rewire pointers.

### Visualization
```
List: [1] → [2] → [3] → [4] → NULL
Insert 99 at position 2 (0-indexed):

Before pos 2 is node at pos 1 (value=2)

[1] → [2] → [3] → [4] → NULL
             ↑
         Insert here

Step 1: Traverse to node at position (pos-1) = 1 → node(2)
Step 2: newNode->next = node(2)->next = node(3)
Step 3: node(2)->next = newNode

Result: [1] → [2] → [99] → [3] → [4] → NULL
```

### C++ Code
```cpp
void insertAtPosition(Node*& head, int val, int pos) {
    if (pos == 0) {
        insertAtHead(head, val);
        return;
    }
    Node* newNode = new Node(val);
    Node* curr = head;
    for (int i = 0; i < pos - 1 && curr != nullptr; i++)
        curr = curr->next;
    if (curr == nullptr) {
        cout << "Position out of bounds\n";
        delete newNode;
        return;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}
```

### Dry Run
```
List: [10] → [20] → [30] → NULL, insert 99 at position 1

pos=1, so stop at position 0 (node with data=10)
curr = node(10) (after 0 iterations)

newNode->next = curr->next = node(20)
curr->next = newNode

Result: [10] → [99] → [20] → [30] → NULL
```

### Complexity
- Time: O(n)
- Space: O(1)

### Edge Cases
- pos = 0 → Insert at head
- pos >= size → Out of bounds
- Empty list, pos > 0 → Out of bounds

---

## 6.6 Delete from Beginning

### Concept
Update head to point to the second node. Free the old head.

### Visualization
```
Before: head → [1] → [2] → [3] → NULL

Step 1: temp = head  →  temp = node(1)
Step 2: head = head→next  →  head = node(2)
Step 3: delete temp  →  free node(1)

After: head → [2] → [3] → NULL
```

### C++ Code
```cpp
void deleteFromHead(Node*& head) {
    if (head == nullptr) return;   // Empty list
    Node* temp = head;
    head = head->next;
    delete temp;
}
```

### Complexity
- Time: O(1)
- Space: O(1)

---

## 6.7 Delete from End

### Concept
Traverse to the second-to-last node. Set its next to null. Free last node.

### Visualization
```
Before: head → [1] → [2] → [3] → NULL

Traverse until curr->next->next == NULL
→ curr = node(2) (second-to-last)

temp = curr->next = node(3)
curr->next = NULL
delete temp

After: head → [1] → [2] → NULL
```

### C++ Code
```cpp
void deleteFromTail(Node*& head) {
    if (head == nullptr) return;
    if (head->next == nullptr) {   // Only one node
        delete head;
        head = nullptr;
        return;
    }
    Node* curr = head;
    while (curr->next->next != nullptr)
        curr = curr->next;
    delete curr->next;
    curr->next = nullptr;
}
```

### Dry Run
```
List: [10] → [20] → [30] → NULL

curr = node(10)
curr->next->next = node(30) ≠ NULL → move: curr = node(20)
curr->next->next = NULL → STOP

delete curr->next (= node(30))
curr->next = nullptr

Result: [10] → [20] → NULL
```

### Complexity
- Time: O(n)
- Space: O(1)

### Edge Cases
- Empty list → return
- Single node → delete head, set to null

---

## 6.8 Delete by Position

### C++ Code
```cpp
void deleteAtPosition(Node*& head, int pos) {
    if (head == nullptr) return;
    if (pos == 0) {
        deleteFromHead(head);
        return;
    }
    Node* curr = head;
    for (int i = 0; i < pos - 1 && curr->next != nullptr; i++)
        curr = curr->next;
    if (curr->next == nullptr) return;  // pos out of bounds
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
}
```

### Visualization
```
List: [10] → [20] → [30] → [40] → NULL, delete pos=2

Traverse to pos-1=1 (node with data=20)
curr = node(20)
temp = curr->next = node(30)
curr->next = temp->next = node(40)
delete temp (node(30))

Result: [10] → [20] → [40] → NULL
```

---

## 6.9 Delete by Value

### C++ Code
```cpp
void deleteByValue(Node*& head, int val) {
    if (head == nullptr) return;
    // Special case: head contains the value
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* curr = head;
    while (curr->next != nullptr) {
        if (curr->next->data == val) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            return;
        }
        curr = curr->next;
    }
}
```

### Complexity
- Time: O(n)
- Space: O(1)

---

## 6.10 Update Node

```cpp
void updateNode(Node* head, int oldVal, int newVal) {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == oldVal) {
            curr->data = newVal;
            return;
        }
        curr = curr->next;
    }
}
```

---

# SECTION 7: REVERSAL TECHNIQUES

## 7.1 Iterative Reversal

### Intuition
Use three pointers: `prev`, `curr`, `next`. Walk through the list, flipping each pointer to point backward.

### Visualization
```
Original: [1] → [2] → [3] → [4] → NULL

Step 0: prev=NULL, curr=1, next=?

Step 1: next=2, 1→NULL, prev=1, curr=2
        NULL ← [1]   [2] → [3] → [4]

Step 2: next=3, 2→1, prev=2, curr=3
        NULL ← [1] ← [2]   [3] → [4]

Step 3: next=4, 3→2, prev=3, curr=4
        NULL ← [1] ← [2] ← [3]   [4]

Step 4: next=NULL, 4→3, prev=4, curr=NULL
        NULL ← [1] ← [2] ← [3] ← [4]

curr == NULL → STOP, new head = prev = node(4)

Result: [4] → [3] → [2] → [1] → NULL
```

### C++ Code
```cpp
Node* reverseIterative(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;   // Save next
        curr->next = prev;             // Reverse pointer
        prev = curr;                   // Advance prev
        curr = nextNode;               // Advance curr
    }
    return prev;   // New head
}
```

### Dry Run (Detailed)
```
List: 1 → 2 → 3 → NULL

Initial: prev=NULL, curr→1

Iter 1:
  nextNode = curr->next = node(2)
  curr->next = prev = NULL     → 1→NULL
  prev = curr = node(1)
  curr = nextNode = node(2)
  State: NULL←[1]  [2]→[3]→NULL

Iter 2:
  nextNode = curr->next = node(3)
  curr->next = prev = node(1)  → 2→1
  prev = curr = node(2)
  curr = nextNode = node(3)
  State: NULL←[1]←[2]  [3]→NULL

Iter 3:
  nextNode = curr->next = NULL
  curr->next = prev = node(2)  → 3→2
  prev = curr = node(3)
  curr = nextNode = NULL
  State: NULL←[1]←[2]←[3]

curr==NULL: return prev = node(3)
Result: 3 → 2 → 1 → NULL ✓
```

### Complexity
- Time: O(n)
- Space: O(1)

### Edge Cases
- Empty list → return nullptr
- Single node → return head (no change)
- Two nodes → works correctly

---

## 7.2 Recursive Reversal

### Intuition
Recursively reverse the rest of the list, then fix the link for the current node.

### Visualization
```
reverseRec(1→2→3→NULL)
  = reverseRec(2→3→NULL) then fix 1
    = reverseRec(3→NULL) then fix 2
      = reverseRec(NULL or just 3) → return 3 (base case)
      Fix 2: 3→next = 2, 2→next = NULL → [3]→[2]→NULL
    Fix 1: 2→next = 1, 1→next = NULL → [3]→[2]→[1]→NULL
  Return new head = 3
```

### C++ Code
```cpp
Node* reverseRecursive(Node* head) {
    // Base case: empty or single node
    if (head == nullptr || head->next == nullptr)
        return head;
    
    // Recursively reverse the rest
    Node* newHead = reverseRecursive(head->next);
    
    // Fix the link: make next node point back to current
    head->next->next = head;
    head->next = nullptr;
    
    return newHead;
}
```

### Call Stack Visualization
```
reverseRec(1):
  calls reverseRec(2):
    calls reverseRec(3):
      calls reverseRec(NULL) → returns NULL... wait
      
Actually base case is single node:
reverseRec(3): head->next==NULL → return node(3)

Back in reverseRec(2):
  newHead = node(3)
  head->next->next = head  →  node(3)->next = node(2)
  head->next = nullptr     →  node(2)->next = NULL
  return node(3)           →  3→2→NULL

Back in reverseRec(1):
  newHead = node(3)
  head->next->next = head  →  node(2)->next = node(1)
  head->next = nullptr     →  node(1)->next = NULL
  return node(3)           →  3→2→1→NULL ✓
```

### Complexity
- Time: O(n)
- Space: O(n) — call stack depth is n

### Common Mistake
```cpp
// ❌ Wrong: forgetting to set head->next = nullptr
head->next->next = head;
// Without: head->next = nullptr, you get a cycle!
// 1 ↔ 2 → ... (2 and 1 point to each other)
```

---

## 7.3 Reverse in Groups of K

### Intuition
Divide the list into groups of k nodes. Reverse each group, then connect groups.

### Visualization
```
List: 1 → 2 → 3 → 4 → 5 → 6 → NULL, k=2

Group 1: [1,2] → reverse → [2,1]
Group 2: [3,4] → reverse → [4,3]
Group 3: [5,6] → reverse → [6,5]

Connect: 2→1→4→3→6→5→NULL
```

With k=3:
```
Group 1: [1,2,3] → reverse → [3,2,1]
Group 2: [4,5,6] → reverse → [6,5,4]

Connect: 3→2→1→6→5→4→NULL
```

### C++ Code
```cpp
Node* reverseKGroup(Node* head, int k) {
    if (head == nullptr || k == 1) return head;
    
    // Check if there are k nodes remaining
    Node* check = head;
    for (int i = 0; i < k; i++) {
        if (check == nullptr) return head;  // Less than k nodes left
        check = check->next;
    }
    
    // Reverse k nodes
    Node* prev = nullptr;
    Node* curr = head;
    for (int i = 0; i < k; i++) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    // head is now the tail of reversed group
    // Recursively reverse next group and connect
    head->next = reverseKGroup(curr, k);
    
    return prev;  // New head of this group
}
```

### Dry Run (k=2, list: 1→2→3→4→NULL)
```
Call reverseKGroup(1, 2):
  check passes (2 nodes exist)
  Reverse [1,2]: prev=2, curr=3
    2→NULL initially, then 1→NULL, 2→1
  head(1)->next = reverseKGroup(3, 2)
    Reverse [3,4]: 4→3→NULL
    head(3)->next = reverseKGroup(NULL, 2) = NULL
    return node(4)
  head(1)->next = node(4) → 1→4→3→NULL... wait
  
Correct trace:
  After reversing [1,2]: 2→1, curr=3
  head = node(1), which is now tail of reversed group
  head(1)->next = result of reverseKGroup(3, 2)
  = node(4) [which leads 4→3→NULL]
  
  So: 2→1→4→3→NULL ✓
  Return node(2)
```

### Complexity
- Time: O(n)
- Space: O(n/k) recursive calls

---

## 7.4 Reverse Between Positions (LeetCode 92)

### Intuition
Find positions left and right. Reverse only the sublist between them.

### Visualization
```
List: 1 → 2 → 3 → 4 → 5, left=2, right=4

Identify:
  Before sublist: node(1) [connection point]
  Sublist: 2 → 3 → 4
  After sublist: node(5)

Reverse sublist: 4 → 3 → 2
Connect: 1 → 4 → 3 → 2 → 5

Result: 1 → 4 → 3 → 2 → 5
```

### C++ Code
```cpp
Node* reverseBetween(Node* head, int left, int right) {
    if (!head || left == right) return head;
    
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* pre = dummy;
    
    // Move pre to the node before position left
    for (int i = 0; i < left - 1; i++)
        pre = pre->next;
    
    Node* curr = pre->next;
    
    // Reverse right-left times
    for (int i = 0; i < right - left; i++) {
        Node* nextNode = curr->next;
        curr->next = nextNode->next;
        nextNode->next = pre->next;
        pre->next = nextNode;
    }
    
    Node* result = dummy->next;
    delete dummy;
    return result;
}
```

### Dry Run (left=2, right=4, list=1→2→3→4→5)
```
dummy→1→2→3→4→5
pre = dummy
Move pre to pos left-1=1: pre = node(1)
curr = pre->next = node(2)

Iteration 1 (i=0):
  nextNode = curr->next = node(3)
  curr->next = node(3)->next = node(4)
  nextNode->next = pre->next = node(2)
  pre->next = nextNode = node(3)
  List: dummy→1→3→2→4→5, curr=node(2)

Iteration 2 (i=1):
  nextNode = curr->next = node(4)
  curr->next = node(4)->next = node(5)
  nextNode->next = pre->next = node(3)
  pre->next = node(4)
  List: dummy→1→4→3→2→5, curr=node(2)

right-left=2 iterations done.
Return dummy->next = node(1)
Result: 1→4→3→2→5 ✓
```

### Complexity
- Time: O(n)
- Space: O(1)

---

# SECTION 8: FAST AND SLOW POINTER PATTERN

## 8.1 The Core Idea

The **Fast-Slow Pointer** (also called **Tortoise and Hare**) technique uses two pointers moving at different speeds through the list.

```
slow moves 1 step at a time
fast moves 2 steps at a time

If the list has a cycle: fast will eventually catch slow (they'll meet)
If no cycle: fast will reach null
If finding middle: when fast reaches end, slow is at middle
```

### Template
```cpp
Node* slow = head;
Node* fast = head;

while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;        // 1 step
    fast = fast->next->next;  // 2 steps
}
// slow is now at middle (or just past middle for even-length lists)
```

---

## 8.2 Find Middle Node

### Problem
Find the middle node of a linked list.
- For odd length: exact middle
- For even length: return second middle (common convention)

### Visualization
```
Odd (n=5):  1 → 2 → [3] → 4 → 5 → NULL
                      ↑ middle

Even (n=4): 1 → 2 → [3] → 4 → NULL
                      ↑ second middle (returned)
```

### Step-by-Step (n=5)
```
Initial: slow=1, fast=1

Step 1: slow=2, fast=3
Step 2: slow=3, fast=5
Step 3: fast->next = NULL → loop ends
Return slow = node(3) ✓ (middle)
```

### Step-by-Step (n=4)
```
Initial: slow=1, fast=1

Step 1: slow=2, fast=3
Step 2: slow=3, fast=NULL (fast = fast->next->next = node(4)->next = NULL? No...)

Wait, fast = node(3), fast->next = node(4), fast->next->next = NULL
Loop condition: fast != NULL && fast->next != NULL
After step 1: slow=2, fast=3
  fast=3: fast != NULL ✓, fast->next=4 != NULL ✓ → continue
After step 2: slow=3, fast=NULL (fast = node(4)->next = NULL)
  fast=NULL → loop ends
Return slow = node(3) (second middle) ✓
```

### C++ Code
```cpp
Node* findMiddle(Node* head) {
    if (head == nullptr) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

### Complexity
- Time: O(n)
- Space: O(1)

---

## 8.3 Detect Cycle

### Problem
Given a linked list, return true if it contains a cycle.

### Intuition
If there's a cycle, fast pointer will loop around and eventually "lap" slow pointer — they'll meet. If no cycle, fast reaches null.

### Visualization (Cycle)
```
1 → 2 → 3 → 4 → 5
            ↑       ↓
            └── 7 ← 6

slow: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 4 → 5...
fast: 1 → 3 → 5 → 7 → 5 → 7 → 5...

They meet at some node in the cycle!
```

### C++ Code
```cpp
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;  // They meet → cycle!
    }
    return false;  // fast reached null → no cycle
}
```

### Dry Run
```
List: 1 → 2 → 3 → 2 (cycle back to 2)
       ↑       ↑
     head    cycle

slow=1, fast=1
Step 1: slow=2, fast=3
Step 2: slow=3, fast=2 (fast: 3→2, i.e., fast = node(3)->next->next = node(2)->next? 
        Actually fast = node(3)->next = node(2), then fast->next = node(3))
        Hmm, let me redo:
        
List: node1(1)→node2(2)→node3(3)→node2 [3's next = 2 = cycle]

slow=node1, fast=node1
Iter 1: slow=node2, fast=node3
Iter 2: slow=node3, fast=node2 (fast: node3→node2→node3, so fast=node2? 
        fast = fast->next->next = node3->next->next = node2->next = node3)
        slow=node3, fast=node3 → MEET! return true ✓
```

### Complexity
- Time: O(n)
- Space: O(1)

### Interview Notes
> **Why does fast always catch slow?** In a cycle of length L, when slow enters the cycle, fast is already somewhere in it. The gap between them decreases by 1 each step (fast gains 1 on slow per iteration inside cycle). They must meet within L steps.

---

## 8.4 Find Cycle Start (Floyd's Algorithm)

### Problem
If a cycle exists, find the node where the cycle begins.

### The Math Behind Floyd's

```
Let:
  F = distance from head to cycle start
  a = distance from cycle start to meeting point
  C = cycle length

When slow and fast meet:
  slow traveled: F + a
  fast traveled: F + a + nC (went around cycle n times)

Since fast = 2 × slow:
  2(F + a) = F + a + nC
  F + a = nC
  F = nC - a = (n-1)C + (C - a)
  
C - a = distance from meeting point to cycle start (going forward)
So F = (n-1)C + (C - a)

This means: if we put one pointer at head and one at meeting point,
both moving 1 step, they'll meet at the CYCLE START!
(head pointer travels F, meeting-point pointer travels C-a + full cycles = F)
```

### Visualization
```
head                   cycle start
 │                         │
 ▼                         ▼
[1] → [2] → [3] → [4] → [5] → [6]
                           ↑         ↓
                           └── [8] ← [7]

F = 4 (head to cycle start: nodes 1,2,3,4)
Cycle: 5→6→7→8→5, length C=4

After detection, slow and fast meet somewhere in cycle.
Place ptr1 at head, ptr2 at meeting point.
Both move 1 step → they meet at cycle start (node 5).
```

### C++ Code
```cpp
Node* detectCycleStart(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool hasCycle = false;
    
    // Phase 1: Detect cycle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }
    
    if (!hasCycle) return nullptr;
    
    // Phase 2: Find cycle start
    Node* ptr = head;
    while (ptr != slow) {
        ptr = ptr->next;
        slow = slow->next;
    }
    return ptr;  // Meeting point = cycle start
}
```

### Complexity
- Time: O(n)
- Space: O(1)

---

## 8.5 Cycle Length

```cpp
int cycleLength(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    // Find meeting point
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Count cycle length from meeting point
            int length = 1;
            Node* curr = slow->next;
            while (curr != slow) {
                length++;
                curr = curr->next;
            }
            return length;
        }
    }
    return 0;  // No cycle
}
```

---

## 8.6 Happy Number

### Problem (LeetCode 202)
Repeatedly replace a number with the sum of squares of its digits. If it reaches 1, it's happy; if it cycles, it's not.

### Key Insight
Map the process as a linked list of states. A cycle (non-1) = unhappy.

```cpp
int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow = n;
    int fast = n;
    do {
        slow = sumOfSquares(slow);
        fast = sumOfSquares(sumOfSquares(fast));
    } while (slow != fast);
    return slow == 1;
}
```

---

## 8.7 Circular Array Loop (LeetCode 457)

```cpp
bool circularArrayLoop(vector<int>& nums) {
    int n = nums.size();
    auto next = [&](int i) {
        return ((i + nums[i]) % n + n) % n;
    };
    
    for (int i = 0; i < n; i++) {
        int slow = i, fast = i;
        // Only follow same direction
        while (nums[slow] * nums[next(slow)] > 0 &&
               nums[fast] * nums[next(fast)] > 0 &&
               nums[fast] * nums[next(next(fast))] > 0) {
            slow = next(slow);
            fast = next(next(fast));
            if (slow == fast) {
                if (slow == next(slow)) break;  // Single element cycle
                return true;
            }
        }
    }
    return false;
}
```

---

# SECTION 9: IMPORTANT LINKED LIST PATTERNS

## Pattern Overview Table

| Pattern | When to Use | Key Technique |
|---------|-------------|---------------|
| Traversal | Visit all nodes | Single pointer, loop |
| Fast-Slow Pointers | Middle, cycle, kth from end | Two pointers at diff speed |
| Reversal | Reverse part or all | Three-pointer technique |
| Merge | Combine sorted lists | Two pointers, dummy node |
| Dummy Node | Simplify head changes | Extra node before head |
| Two Pointer | Distance-based, gaps | Two pointers at same speed |
| Partition | Separate by condition | Two sublists + connect |
| Cycle Detection | Loop detection | Floyd's algorithm |
| Multi Pointer | Complex rearrangements | 3+ pointers |
| In-place Modification | Modify without extra space | Direct pointer manipulation |

---

## Pattern 1: Traversal Pattern

### Identification Clues
- "Print all nodes"
- "Count nodes"
- "Find sum / max / min"
- Any operation requiring visiting every node

### Template
```cpp
void traverse(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        // Process curr->data
        process(curr->data);
        curr = curr->next;
    }
}
```

### Common Problems
- Print linked list
- Count nodes: O(n) time, O(1) space
- Find maximum element
- Check if list is palindrome (with extra structures)

---

## Pattern 2: Fast-Slow Pointer Pattern

### Identification Clues
- "Find middle"
- "Detect cycle"
- "Kth node from end"
- "Check if palindrome" (find middle, reverse second half)

### Template
```cpp
Node* slow = head;
Node* fast = head;
while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
}
// slow is at middle
```

### Dry Run
```
1 → 2 → 3 → 4 → 5

s=1, f=1
s=2, f=3
s=3, f=5  → f->next=NULL, stop
slow = 3 (middle) ✓
```

### Common Problems
- Middle of linked list (LC 876)
- Linked list cycle (LC 141)
- Linked list cycle II (LC 142)
- Palindrome linked list (LC 234)
- Reorder list (LC 143)

---

## Pattern 3: Reversal Pattern

### Identification Clues
- "Reverse the list"
- "Reverse between positions"
- "Reverse in groups of k"
- "Check palindrome" (compare with reversed half)

### Template
```cpp
Node* prev = nullptr;
Node* curr = head;
while (curr != nullptr) {
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
}
// prev = new head
```

### Common Problems
- Reverse linked list (LC 206)
- Reverse linked list II (LC 92)
- Reverse nodes in k-group (LC 25)
- Swap pairs (LC 24)
- Palindrome check

---

## Pattern 4: Merge Pattern

### Identification Clues
- "Merge two sorted lists"
- "Merge k sorted lists"
- "Sort the linked list"

### Template
```cpp
Node* merge(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;
    while (l1 && l2) {
        if (l1->data <= l2->data) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return dummy->next;
}
```

### Common Problems
- Merge two sorted lists (LC 21)
- Merge k sorted lists (LC 23)
- Sort list (LC 148)

---

## Pattern 5: Dummy Node Pattern

### Identification Clues
- Operations that might change the head
- "Delete a node" (first node might be deleted)
- Inserting before head
- Merging lists

### Why Use It?
The dummy node eliminates special-case handling for head operations.

### Template
```cpp
Node* dummy = new Node(0);
dummy->next = head;
Node* curr = dummy;

// Perform operations on curr->next (not curr)
// ...

Node* result = dummy->next;
delete dummy;
return result;
```

### Visualization
```
Without dummy:
  if head needs deletion:
    head = head->next; // special case

With dummy:
  dummy → head → ...
  We always operate on curr->next, never need to special-case head
  dummy→next is always the real head
```

### Common Problems
- Remove Nth node from end (LC 19)
- Delete duplicates (LC 83)
- Partition list (LC 86)
- All merge problems

---

## Pattern 6: Two Pointer (Same Speed) Pattern

### Identification Clues
- "Remove Nth node from end"
- "Find kth node from end"
- "Find intersection of two lists"

### Template (Gap technique)
```cpp
// Find kth node from end: advance first pointer k steps,
// then move both until first reaches end

Node* first = head;
Node* second = head;

// Advance first by k steps
for (int i = 0; i < k; i++)
    first = first->next;

// Move both until first reaches end
while (first != nullptr) {
    first = first->next;
    second = second->next;
}
// second is now kth from end
```

### Common Problems
- Remove Nth from end (LC 19)
- Intersection of two lists (LC 160)
- Find kth node from end

---

## Pattern 7: Partition Pattern

### Identification Clues
- "Partition around value x"
- "Separate odd/even positions"
- "Separate nodes by condition"

### Template
```cpp
// Partition: nodes < x go to left list, >= x go to right list
Node* leftDummy = new Node(0);
Node* rightDummy = new Node(0);
Node* left = leftDummy;
Node* right = rightDummy;

Node* curr = head;
while (curr != nullptr) {
    if (curr->data < x) {
        left->next = curr;
        left = left->next;
    } else {
        right->next = curr;
        right = right->next;
    }
    curr = curr->next;
}

right->next = nullptr;
left->next = rightDummy->next;
return leftDummy->next;
```

### Common Problems
- Partition list (LC 86)
- Odd-even linked list (LC 328)
- Separate even/odd nodes

---

## Pattern 8: Cycle Detection Pattern

### Identification Clues
- "Does the list have a loop?"
- "Where does the cycle begin?"
- "Length of cycle"

### Template
```cpp
// Phase 1: Detect
Node* slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
        // Phase 2: Find start
        Node* ptr = head;
        while (ptr != slow) {
            ptr = ptr->next;
            slow = slow->next;
        }
        return ptr; // Cycle start
    }
}
return nullptr; // No cycle
```

---

## Pattern 9: Multi-Pointer Pattern

### Identification Clues
- Complex rearrangements
- "Swap adjacent nodes"
- "Reorder list"

### Example: Reorder List (LC 143)
```
Original: 1→2→3→4→5
Reorder: 1→5→2→4→3

Steps:
1. Find middle (fast-slow)
2. Reverse second half
3. Merge two halves
```

```cpp
void reorderList(Node* head) {
    if (!head || !head->next) return;
    
    // Step 1: Find middle
    Node* slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Step 2: Reverse second half
    Node* secondHalf = slow->next;
    slow->next = nullptr;
    Node* prev = nullptr, *curr = secondHalf;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    secondHalf = prev;
    
    // Step 3: Merge
    Node* first = head, *second = secondHalf;
    while (second) {
        Node* tmp1 = first->next;
        Node* tmp2 = second->next;
        first->next = second;
        second->next = tmp1;
        first = tmp1;
        second = tmp2;
    }
}
```

---

## Pattern 10: In-Place Modification Pattern

### Identification Clues
- O(1) space required
- "Modify list without extra data structure"
- Sorting, rearranging in place

### Key Idea
Manipulate existing pointers; don't allocate new nodes.

### Example: Remove duplicates from sorted list
```cpp
Node* deleteDuplicates(Node* head) {
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            Node* dup = curr->next;
            curr->next = dup->next;
            delete dup;
        } else {
            curr = curr->next;
        }
    }
    return head;
}
```

---

# SECTION 10: CYCLE PROBLEMS

## 10.1 Floyd's Cycle Detection Algorithm

### Overview

**Floyd's Algorithm** (Tortoise and Hare) is the standard O(1) space cycle detection method.

### Core Theorem
If a cycle exists, a pointer moving at 2x speed will eventually meet a pointer moving at 1x speed within the cycle.

### Why It Works (Mathematical Proof)

```
Let:
  μ (mu) = index of cycle start (distance from head)
  λ (lambda) = cycle length

When slow pointer enters cycle (has traveled μ steps):
  fast has traveled 2μ steps
  fast is at position: μ + (μ mod λ) inside cycle... 
  
Simplified: the distance between slow and fast inside the cycle
decreases by 1 each step.
They will meet in at most λ steps after slow enters the cycle.
```

### Complete Implementation

```cpp
class FloydsCycleDetection {
public:
    // Returns nullptr if no cycle, else meeting point
    Node* detectCycle(Node* head) {
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return slow;  // Meeting point
        }
        return nullptr;  // No cycle
    }
    
    // Returns cycle start, or nullptr
    Node* findCycleStart(Node* head) {
        Node* meetPoint = detectCycle(head);
        if (!meetPoint) return nullptr;
        
        Node* ptr = head;
        while (ptr != meetPoint) {
            ptr = ptr->next;
            meetPoint = meetPoint->next;
        }
        return ptr;
    }
    
    // Returns cycle length
    int cycleLength(Node* head) {
        Node* meetPoint = detectCycle(head);
        if (!meetPoint) return 0;
        
        int len = 1;
        Node* curr = meetPoint->next;
        while (curr != meetPoint) {
            len++;
            curr = curr->next;
        }
        return len;
    }
};
```

---

## 10.2 Remove Cycle

### Approach
1. Detect cycle using Floyd's
2. Find cycle start
3. Find the last node in cycle (node whose next = cycle start)
4. Set that node's next = nullptr

```cpp
void removeCycle(Node* head) {
    Node* slow = head, *fast = head;
    bool cycle = false;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { cycle = true; break; }
    }
    if (!cycle) return;
    
    // Find cycle start
    Node* ptr = head;
    if (ptr == slow) {
        // Special case: cycle starts at head
        while (slow->next != ptr) slow = slow->next;
    } else {
        while (ptr->next != slow->next) {
            ptr = ptr->next;
            slow = slow->next;
        }
    }
    // slow is now the last node in the cycle
    slow->next = nullptr;
}
```

### Dry Run
```
List with cycle: 1→2→3→4→5→3 (5's next = 3)

Phase 1 (detect):
slow=1,fast=1
slow=2,fast=3
slow=3,fast=5
slow=4,fast=4 → MEET at node(4)

Phase 2 (find start):
ptr=head=1, slow=meetpoint=4
ptr=1, slow=4 → not equal → advance: ptr=2, slow=5
ptr=2, slow=5 → not equal → advance: ptr=3, slow=3 → MEET at node(3)

Cycle start = node(3)

Find last node: traverse cycle from start until we find node whose next=node(3)
3→4→5→3: node(5)->next = node(3) → node(5) is last node
Set node(5)->next = nullptr

Result: 1→2→3→4→5→NULL (no more cycle)
```

---

## 10.3 Detect Cycle — Hash Set Method (Brute Force)

```cpp
bool hasCycleBrute(Node* head) {
    unordered_set<Node*> visited;
    Node* curr = head;
    while (curr != nullptr) {
        if (visited.count(curr)) return true;  // Seen before = cycle
        visited.insert(curr);
        curr = curr->next;
    }
    return false;
}
// Time: O(n), Space: O(n)
// Floyd's is better: O(1) space
```

---

# SECTION 11: MERGING PROBLEMS

## 11.1 Merge Two Sorted Lists (LeetCode 21)

### Problem
Merge two sorted linked lists into one sorted linked list.

### Visualization
```
L1: 1 → 3 → 5 → NULL
L2: 2 → 4 → 6 → NULL

Compare heads, pick smaller:
1 < 2 → pick 1 from L1
2 < 3 → pick 2 from L2
3 < 4 → pick 3 from L1
4 < 5 → pick 4 from L2
5 < 6 → pick 5 from L1
         pick 6 from L2

Result: 1 → 2 → 3 → 4 → 5 → 6 → NULL
```

### Brute Force
```cpp
// Collect all values, sort, rebuild
Node* mergeSortedBrute(Node* l1, Node* l2) {
    vector<int> vals;
    while (l1) { vals.push_back(l1->data); l1 = l1->next; }
    while (l2) { vals.push_back(l2->data); l2 = l2->next; }
    sort(vals.begin(), vals.end());
    
    Node* dummy = new Node(0);
    Node* curr = dummy;
    for (int v : vals) {
        curr->next = new Node(v);
        curr = curr->next;
    }
    return dummy->next;
}
// Time: O((m+n) log(m+n)), Space: O(m+n)
```

### Optimal (Two Pointer + Dummy)
```cpp
Node* mergeTwoLists(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;
    
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data <= l2->data) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    
    // Attach remaining nodes
    curr->next = (l1 != nullptr) ? l1 : l2;
    
    return dummy->next;
}
// Time: O(m+n), Space: O(1)
```

### Dry Run
```
l1: 1→3→5, l2: 2→4→6

dummy→?, curr=dummy

Iter 1: 1<=2 → curr→1, l1=3, curr=1
Iter 2: 3>2  → curr→2, l2=4, curr=2
Iter 3: 3<=4 → curr→3, l1=5, curr=3
Iter 4: 5>4  → curr→4, l2=6, curr=4
Iter 5: 5<=6 → curr→5, l1=NULL, curr=5

l1 is NULL → curr->next = l2 (which is 6→NULL)

Result: dummy→1→2→3→4→5→6→NULL
Return dummy->next = node(1) ✓
```

---

## 11.2 Merge K Sorted Lists (LeetCode 23)

### Approach 1: Brute Force
```cpp
// Collect all values, sort, rebuild — O(N log N) where N = total nodes
```

### Approach 2: Merge One by One
```cpp
Node* mergeKLists(vector<Node*>& lists) {
    Node* result = nullptr;
    for (Node* list : lists)
        result = mergeTwoLists(result, list);
    return result;
}
// Time: O(kN) where k = number of lists, N = total nodes
```

### Approach 3: Divide and Conquer (Optimal)
```cpp
Node* mergeKLists(vector<Node*>& lists) {
    if (lists.empty()) return nullptr;
    return mergeRange(lists, 0, lists.size() - 1);
}

Node* mergeRange(vector<Node*>& lists, int left, int right) {
    if (left == right) return lists[left];
    int mid = left + (right - left) / 2;
    Node* l1 = mergeRange(lists, left, mid);
    Node* l2 = mergeRange(lists, mid + 1, right);
    return mergeTwoLists(l1, l2);
}
// Time: O(N log k), Space: O(log k)
```

### Approach 4: Min-Heap (Priority Queue)
```cpp
Node* mergeKLists(vector<Node*>& lists) {
    // Min-heap: (value, node)
    priority_queue<pair<int,Node*>, vector<pair<int,Node*>>, greater<>> pq;
    
    for (Node* l : lists)
        if (l) pq.push({l->data, l});
    
    Node* dummy = new Node(0);
    Node* curr = dummy;
    
    while (!pq.empty()) {
        auto [val, node] = pq.top(); pq.pop();
        curr->next = node;
        curr = curr->next;
        if (node->next) pq.push({node->next->data, node->next});
    }
    return dummy->next;
}
// Time: O(N log k), Space: O(k)
```

---

## 11.3 Intersection of Two Lists (LeetCode 160)

### Problem
Find the node where two linked lists intersect. Return null if no intersection.

### Visualization
```
List A: 1 → 3 → 5 ─┐
                     ├→ 8 → 9 → NULL
List B:     2 → 4 ─┘

Intersection at node(8).
```

### Approach 1: Hash Set
```cpp
Node* getIntersectionNode(Node* headA, Node* headB) {
    unordered_set<Node*> visited;
    Node* curr = headA;
    while (curr) { visited.insert(curr); curr = curr->next; }
    curr = headB;
    while (curr) {
        if (visited.count(curr)) return curr;
        curr = curr->next;
    }
    return nullptr;
}
// Time: O(m+n), Space: O(m)
```

### Approach 2: Two Pointer (Optimal, O(1) space)
```cpp
Node* getIntersectionNode(Node* headA, Node* headB) {
    if (!headA || !headB) return nullptr;
    Node* pA = headA, *pB = headB;
    
    while (pA != pB) {
        pA = (pA == nullptr) ? headB : pA->next;
        pB = (pB == nullptr) ? headA : pB->next;
    }
    return pA;
}
// Time: O(m+n), Space: O(1)
```

### Intuition
```
If lists have lengths m and n, and intersect at distance a from headA, b from headB:
  pA travels: a + (m-a) + b = m + b
  pB travels: b + (n-b) + a = n + a
  
Since m + b = n + a iff m - n = a - b... hmm.

Simpler: pA travels m then switches to headB, pB travels n then switches to headA.
Total travel for both: m+n steps.
They will meet at the intersection (or both at nullptr if no intersection).

Visual:
  pA: A1→A2→...→Am→B1→B2→...→Bn
  pB: B1→B2→...→Bn→A1→A2→...→Am
  Both paths have same length m+n, and align at intersection point.
```

---

## 11.4 Union of Two Lists

```cpp
Node* unionLists(Node* head1, Node* head2) {
    unordered_set<int> seen;
    Node* dummy = new Node(0);
    Node* curr = dummy;
    
    while (head1) {
        if (!seen.count(head1->data)) {
            seen.insert(head1->data);
            curr->next = new Node(head1->data);
            curr = curr->next;
        }
        head1 = head1->next;
    }
    while (head2) {
        if (!seen.count(head2->data)) {
            seen.insert(head2->data);
            curr->next = new Node(head2->data);
            curr = curr->next;
        }
        head2 = head2->next;
    }
    return dummy->next;
}
```

---

# SECTION 12: IMPORTANT LINKED LIST ALGORITHMS

## 12.1 Remove Nth Node from End (LeetCode 19)

### Intuition
Use two pointers with a gap of n. When fast reaches end, slow is at the node before the target.

### Visualization
```
List: 1→2→3→4→5, n=2 (remove 2nd from end = node 4)

Use dummy for edge cases (removing head):
dummy→1→2→3→4→5

Fast advances n+1=3 steps:
fast: dummy→1→2→3
slow: dummy

Both advance until fast=NULL:
fast: 3→4→5→NULL
slow: dummy→1→2→3

slow is at node(3), slow->next = node(4) [target]
slow->next = slow->next->next = node(5)

Result: dummy→1→2→3→5
```

### C++ Code
```cpp
Node* removeNthFromEnd(Node* head, int n) {
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* fast = dummy;
    Node* slow = dummy;
    
    // Advance fast by n+1 steps
    for (int i = 0; i <= n; i++)
        fast = fast->next;
    
    // Move both until fast is nullptr
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // Delete node
    Node* toDelete = slow->next;
    slow->next = toDelete->next;
    delete toDelete;
    
    Node* result = dummy->next;
    delete dummy;
    return result;
}
```

### Complexity
- Time: O(n)
- Space: O(1)

---

## 12.2 Rotate Linked List (LeetCode 61)

### Problem
Rotate list to the right by k places.

### Visualization
```
List: 1→2→3→4→5, k=2

Rotation means last k nodes go to front:
  [1,2,3] [4,5]  →  [4,5] + [1,2,3]
  Result: 4→5→1→2→3
```

### C++ Code
```cpp
Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;
    
    // Find length and tail
    int len = 1;
    Node* tail = head;
    while (tail->next) { tail = tail->next; len++; }
    
    k = k % len;  // Handle k > len
    if (k == 0) return head;
    
    // Find new tail: (len - k - 1) steps from head
    Node* newTail = head;
    for (int i = 0; i < len - k - 1; i++)
        newTail = newTail->next;
    
    // Rearrange
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;
    
    return newHead;
}
```

### Dry Run
```
List: 1→2→3→4→5, k=2

len=5, tail=node(5)
k = 2 % 5 = 2

newTail: 5-2-1 = 2 steps from head
  newTail = node(1)→node(2)→node(3) (2 steps) = node(3)

newHead = newTail->next = node(4)
newTail->next = nullptr  → 1→2→3→NULL
tail->next = head        → node(5)->next = node(1)

Chain: 4→5→1→2→3→NULL
Return node(4) ✓
```

---

## 12.3 Merge Sort on Linked List (LeetCode 148)

### Why Merge Sort?
- **No random access** needed (unlike quicksort)
- **Stable sort**
- O(n log n) worst case guaranteed
- O(1) extra space for the merge step (unlike arrays)

### Algorithm
1. Find middle (fast-slow pointer)
2. Split into two halves
3. Recursively sort each half
4. Merge sorted halves

```cpp
Node* sortList(Node* head) {
    // Base case
    if (!head || !head->next) return head;
    
    // Find middle and split
    Node* mid = getMid(head);
    Node* rightHalf = mid->next;
    mid->next = nullptr;
    
    // Recursively sort
    Node* left = sortList(head);
    Node* right = sortList(rightHalf);
    
    // Merge
    return merge(left, right);
}

Node* getMid(Node* head) {
    Node* slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;  // Returns first middle for even length
}

Node* merge(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;
    while (l1 && l2) {
        if (l1->data <= l2->data) { curr->next = l1; l1 = l1->next; }
        else { curr->next = l2; l2 = l2->next; }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return dummy->next;
}
```

### Complexity
- Time: O(n log n)
- Space: O(log n) — recursion stack

### Dry Run (short)
```
List: 4→2→1→3

getMid(4→2→1→3) = node(2)
Split: left=4→2, right=1→3

sortList(4→2):
  getMid(4→2) = node(4)
  left=4, right=2
  sortList(4) = 4, sortList(2) = 2
  merge(4, 2) = 2→4

sortList(1→3):
  getMid(1→3) = node(1)
  left=1, right=3
  merge(1, 3) = 1→3

merge(2→4, 1→3):
  1<2 → pick 1
  2<3 → pick 2
  3<4 → pick 3
  pick 4
  = 1→2→3→4 ✓
```

---

## 12.4 Palindrome Linked List (LeetCode 234)

### Approach
1. Find middle
2. Reverse second half
3. Compare first and second halves
4. (Optional) Restore list

```cpp
bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;
    
    // Find middle
    Node* slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    Node* prev = nullptr, *curr = slow->next;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    // Compare
    Node* left = head, *right = prev;
    while (right) {
        if (left->data != right->data) return false;
        left = left->next;
        right = right->next;
    }
    return true;
}
```

### Dry Run
```
List: 1→2→2→1

Find middle: slow=node(2 at pos1), fast=node(2 at pos2) after loop
Reverse second half (slow->next = node(2 at pos2)):
  prev=1, curr=2(pos2)→reversed... → right half = 1→2 (reversed)

Wait let's be precise:
List: 1→2→2→1
Indices: 0 1 2 3

slow=0, fast=0
Iter 1: slow=1, fast=2 (fast = node[0]->next->next = node[2])
  fast->next = node[3] ≠ NULL, fast->next->next = NULL → stop
  (condition: fast->next && fast->next->next → node[3] && NULL → false)
slow = node[1] (value 2)

Reverse from slow->next = node[2] (value 2):
  curr = node[2], node[3] sequence
  After reverse: node[1 reversed] ← node[2 reversed]
  Wait: reversing 2→1 gives 1→2

right = 1→2 (reversed second half)
left = 1→2 (original first half)

Compare: 1==1 ✓, 2==2 ✓ → return true ✓
```

---

## 12.5 Partition List (LeetCode 86)

```cpp
Node* partition(Node* head, int x) {
    Node* lessHead = new Node(0);  // Dummy for < x list
    Node* greaterHead = new Node(0);  // Dummy for >= x list
    Node* less = lessHead;
    Node* greater = greaterHead;
    
    Node* curr = head;
    while (curr) {
        if (curr->data < x) {
            less->next = curr;
            less = less->next;
        } else {
            greater->next = curr;
            greater = greater->next;
        }
        curr = curr->next;
    }
    
    greater->next = nullptr;     // End the greater list
    less->next = greaterHead->next;  // Connect less → greater
    
    return lessHead->next;
}
```

---

# SECTION 13: SORTING LINKED LISTS

## 13.1 Merge Sort (Preferred)

See Section 12.3 for complete implementation.

**Why Merge Sort is preferred:**
- Works well with linked lists' sequential nature
- No random access needed
- O(n log n) guaranteed
- Stable sort
- In-place merge possible (O(1) space for merge step)

## 13.2 Insertion Sort on Linked List

### Intuition
Build sorted list one node at a time. For each node, find its correct position in the already-sorted portion.

```cpp
Node* insertionSortList(Node* head) {
    Node* dummy = new Node(0);
    Node* curr = head;
    
    while (curr) {
        Node* next = curr->next;
        // Find the insertion position in sorted portion
        Node* prev = dummy;
        while (prev->next && prev->next->data < curr->data)
            prev = prev->next;
        
        curr->next = prev->next;
        prev->next = curr;
        curr = next;
    }
    return dummy->next;
}
```

### Complexity
- Time: O(n²) worst case
- Space: O(1)

### When to Use
- Nearly sorted lists (O(n) near-best-case)
- Small lists
- When simplicity matters more than performance

## 13.3 Bubble Sort on Linked List

```cpp
void bubbleSortList(Node* head) {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        Node* curr = head;
        while (curr->next) {
            if (curr->data > curr->next->data) {
                swap(curr->data, curr->next->data);
                swapped = true;
            }
            curr = curr->next;
        }
    } while (swapped);
}
```

### Complexity
- Time: O(n²)
- Space: O(1)

### Why Not Quicksort?
- Linked lists have no random access → can't pick pivot efficiently
- Partitioning requires knowing the pivot position
- Cache performance is already poor; quicksort makes it worse
- Worst case O(n²) common in practice for linked lists
- Merge sort is strictly better for linked lists

## 13.4 Summary: Sorting Comparison

| Algorithm | Time (Best) | Time (Avg) | Time (Worst) | Space | Stable? |
|-----------|------------|------------|-------------|-------|---------|
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(log n) | Yes ✓ |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes ✓ |
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes ✓ |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No |

**For interviews: Always prefer Merge Sort for linked lists.**
---

# SECTION 14: DOUBLY LINKED LIST MASTERY

## 14.1 Structure

```cpp
class DLLNode {
public:
    int data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    DLLNode* head;
    DLLNode* tail;
    int size;
    
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
};
```

### Memory Layout
```
NULL ←[prev|data|next]⇄[prev|data|next]⇄[prev|data|next]→ NULL
       ↑                                  ↑
      head                               tail
```

---

## 14.2 DLL Traversal

```cpp
// Forward traversal
void traverseForward(DLLNode* head) {
    DLLNode* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// Backward traversal (start from tail)
void traverseBackward(DLLNode* tail) {
    DLLNode* curr = tail;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->prev;
    }
}
```

---

## 14.3 DLL Insertions

### Insert at Head
```cpp
void insertAtHead(DLLNode*& head, DLLNode*& tail, int val) {
    DLLNode* newNode = new DLLNode(val);
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
```

### Visualization
```
Before: NULL←[1]⇄[2]⇄[3]→NULL

Insert 0 at head:
[0]→head: newNode->next = node(1)
node(1)->prev = newNode
head = newNode

After: NULL←[0]⇄[1]⇄[2]⇄[3]→NULL
```

### Insert at Tail
```cpp
void insertAtTail(DLLNode*& head, DLLNode*& tail, int val) {
    DLLNode* newNode = new DLLNode(val);
    if (tail == nullptr) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
```

### Insert After Given Node
```cpp
void insertAfter(DLLNode* node, int val) {
    if (!node) return;
    DLLNode* newNode = new DLLNode(val);
    newNode->next = node->next;
    newNode->prev = node;
    if (node->next) node->next->prev = newNode;
    node->next = newNode;
}
```

---

## 14.4 DLL Deletions

### Delete at Head
```cpp
void deleteHead(DLLNode*& head, DLLNode*& tail) {
    if (!head) return;
    if (head == tail) { delete head; head = tail = nullptr; return; }
    DLLNode* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
}
```

### Delete at Tail
```cpp
void deleteTail(DLLNode*& head, DLLNode*& tail) {
    if (!tail) return;
    if (head == tail) { delete tail; head = tail = nullptr; return; }
    DLLNode* temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}
```

### Delete Given Node (O(1) — DLL advantage!)
```cpp
void deleteNode(DLLNode*& head, DLLNode*& tail, DLLNode* node) {
    if (!node) return;
    if (node == head) { deleteHead(head, tail); return; }
    if (node == tail) { deleteTail(head, tail); return; }
    // Middle node: update both neighbors
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}
```

### Why O(1) Deletion is a DLL Superpower
```
Singly LL: To delete node X, need previous node → must traverse from head: O(n)
Doubly LL: node X has prev pointer → directly update both neighbors: O(1)

Given pointer to node X:
  X->prev->next = X->next;   // previous node skips X
  X->next->prev = X->prev;   // next node skips X
  delete X;
```

---

## 14.5 DLL Reversal

```cpp
void reverseDLL(DLLNode*& head, DLLNode*& tail) {
    DLLNode* curr = head;
    DLLNode* temp = nullptr;
    
    while (curr != nullptr) {
        // Swap prev and next
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;  // Move to next (which was prev before swap)
    }
    
    // Swap head and tail
    if (temp) head = temp->prev;
    swap(head, tail);
}
```

---

## 14.6 LRU Cache using DLL + HashMap

The most famous DLL application!

```cpp
class LRUCache {
    int capacity;
    unordered_map<int, DLLNode*> cache;
    DLLNode* head;  // Most recently used end
    DLLNode* tail;  // Least recently used end
    
    void removeNode(DLLNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void addToFront(DLLNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    
public:
    LRUCache(int cap) : capacity(cap) {
        head = new DLLNode(0);  // Dummy head
        tail = new DLLNode(0);  // Dummy tail
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        DLLNode* node = cache[key];
        removeNode(node);
        addToFront(node);
        return node->data;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            DLLNode* node = cache[key];
            node->data = value;
            removeNode(node);
            addToFront(node);
        } else {
            if ((int)cache.size() == capacity) {
                // Evict LRU (tail->prev)
                DLLNode* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->data);  // Note: store key in node for real impl
                delete lru;
            }
            DLLNode* newNode = new DLLNode(value);
            cache[key] = newNode;
            addToFront(newNode);
        }
    }
};
```

---

# SECTION 15: CIRCULAR LINKED LIST MASTERY

## 15.1 Circular Singly Linked List

### Structure
Last node's next = head (instead of null).

```cpp
class CircularLL {
public:
    Node* head;
    CircularLL() : head(nullptr) {}
};
```

### Key Invariant
```
// To check if single-node circular list:
head->next == head

// To check if curr is last node:
curr->next == head
```

---

## 15.2 Circular LL: Insert at Head

```cpp
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        newNode->next = newNode;  // Points to itself
        head = newNode;
        return;
    }
    // Find last node
    Node* last = head;
    while (last->next != head) last = last->next;
    
    newNode->next = head;
    last->next = newNode;
    head = newNode;
}
```

### Visualization
```
Before: head→[1]→[2]→[3]→(back to head)

Insert 0:
  last = node(3)
  newNode->next = head (node 1)
  last->next = newNode (node 3 → node 0)
  head = newNode

After: head→[0]→[1]→[2]→[3]→(back to 0)
```

---

## 15.3 Circular LL: Insert at Tail

```cpp
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* last = head;
    while (last->next != head) last = last->next;
    last->next = newNode;
    newNode->next = head;
}
```

---

## 15.4 Circular LL: Delete

```cpp
void deleteNode(Node*& head, int val) {
    if (!head) return;
    
    // Single node
    if (head->next == head) {
        if (head->data == val) { delete head; head = nullptr; }
        return;
    }
    
    // Delete head
    if (head->data == val) {
        Node* last = head;
        while (last->next != head) last = last->next;
        last->next = head->next;
        delete head;
        head = last->next;
        return;
    }
    
    // Delete other node
    Node* curr = head;
    while (curr->next != head && curr->next->data != val)
        curr = curr->next;
    
    if (curr->next->data == val) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
}
```

---

## 15.5 Circular LL: Traversal

```cpp
void traverse(Node* head) {
    if (!head) return;
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);  // Stop when back at head
    cout << endl;
}
// NOTE: Use do-while, not while, to ensure head is visited
```

---

## 15.6 Josephus Problem

Classic circular list application: n people in circle, every k-th person eliminated. Find survivor.

```cpp
int josephus(int n, int k) {
    // Build circular list
    Node* head = new Node(1);
    Node* curr = head;
    for (int i = 2; i <= n; i++) {
        curr->next = new Node(i);
        curr = curr->next;
    }
    curr->next = head;  // Make circular
    
    curr = head;
    while (curr->next != curr) {
        // Advance k-1 steps
        for (int i = 0; i < k - 1; i++) curr = curr->next;
        // Remove next node
        Node* toDelete = curr->next;
        curr->next = toDelete->next;
        delete toDelete;
    }
    
    int result = curr->data;
    delete curr;
    return result;
}
```

---

# SECTION 16: INTERVIEW FRAMEWORK

## 16.1 How to Identify Linked List Patterns

```
PROBLEM RECEIVED
      │
      ▼
┌─────────────────────────────────────────────┐
│           IDENTIFY THE PATTERN              │
└─────────────────────────────────────────────┘
      │
      ├── Does it mention cycle/loop? ──────────────► Floyd's Cycle Detection
      │
      ├── Find middle node? ─────────────────────────► Fast-Slow Pointer
      │
      ├── Kth from end / window ────────────────────► Two Pointer (gap=k)
      │
      ├── Reverse all/part of list? ────────────────► Three-Pointer Reversal
      │
      ├── Merge sorted lists? ──────────────────────► Merge Pattern + Dummy
      │
      ├── Partition/rearrange? ─────────────────────► Partition Pattern + Dummy
      │
      ├── Delete/modify head possible? ─────────────► Dummy Node
      │
      ├── Check palindrome? ─────────────────────────► Find middle + Reverse
      │
      └── Complex rearrangement? ───────────────────► Multi-Pointer
```

## 16.2 Complete Decision Tree

```
START
  │
  ▼
Is cycle detection involved?
  YES → Floyd's (fast/slow pointers)
  NO  ↓

Is finding middle needed?
  YES → Fast/Slow (fast advances 2x)
  NO  ↓

Is position-from-end (kth from end) needed?
  YES → Two pointers with k-gap
  NO  ↓

Is reversal needed?
  YES (full reversal) → 3-pointer iterative
  YES (partial)       → Dummy + position tracking
  NO  ↓

Is merging sorted lists?
  YES (2 lists) → Two-pointer merge + dummy
  YES (k lists) → Divide & conquer or heap
  NO  ↓

Is partitioning/separating?
  YES → Two sublists + dummy nodes + connect
  NO  ↓

Does head potentially change?
  YES → Always use dummy node
  NO  ↓

Single traversal processing?
  YES → Simple traversal pattern
```

---

## 16.3 Interview Problem-Solving Template

```
STEP 1: UNDERSTAND (2 min)
  - Clarify input: null? single node? cycles?
  - Clarify output: new head? modified in-place? value?
  - Ask about constraints: space, time

STEP 2: EXAMPLES (2 min)
  - Draw 2-3 examples on paper/whiteboard
  - Include edge cases: empty, single, two nodes

STEP 3: APPROACH (3 min)
  - Identify the pattern
  - State brute force first
  - Explain optimal approach

STEP 4: CODE (10 min)
  - Write clean, correct code
  - Handle edge cases first
  - Use meaningful variable names (prev/curr/next, not p/q/r)

STEP 5: DRY RUN (3 min)
  - Walk through your code with an example
  - Verify edge cases

STEP 6: COMPLEXITY (1 min)
  - State time and space complexity
  - Justify each
```

---

## 16.4 Common Interview Problems by Difficulty

| Problem | Key Pattern | Key Trick |
|---------|-------------|-----------|
| Reverse Linked List | Reversal | 3 pointers |
| Middle of LL | Fast-Slow | Stop when fast->next->next is null |
| Detect Cycle | Fast-Slow | Meet = cycle |
| Merge Two Sorted | Merge | Dummy node |
| Remove Nth from End | Two Pointer | Gap of n+1 |
| Find Cycle Start | Floyd's Phase 2 | Reset one pointer to head |
| Palindrome LL | Fast-Slow + Reverse | Split at middle |
| Reorder List | Multi-Pattern | Find mid, reverse, merge |
| Reverse K-Group | Reversal | Check k nodes exist first |
| Merge K Sorted | D&C + Merge | Divide in half recursively |

---

# SECTION 17: COMMON TRICKS

## 17.1 Dummy Node Tricks

```cpp
// TRICK: Dummy node eliminates head-change edge cases
Node* dummy = new Node(0);
dummy->next = head;
// Now: always operate on curr->next, never need to special-case head
// At end: return dummy->next as the new head
```

**When to always use dummy node:**
- Deleting a node (could be head)
- Partitioning (result list might start from any node)
- Merging (new head comes from one of the lists)

---

## 17.2 Fast-Slow Pointer Tricks

```cpp
// Trick 1: Stop slow at first middle (for odd) or first of two middles (for even)
// Use: fast starts at head->next
Node* slow = head;
Node* fast = head->next;
while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
// slow = first middle

// Trick 2: Stop slow at second middle (standard)
// Use: fast starts at head
Node* slow = head, *fast = head;
while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
// slow = second middle (for even length)

// Trick 3: Detect cycle AND keep slow at entry point for merge problems
// After detecting, keep slow at meeting point for Phase 2
```

---

## 17.3 Reversal Tricks

```cpp
// Trick: Reverse to check palindrome without extra space
Node* slow = head, *fast = head;
while (fast->next && fast->next->next) { slow = slow->next; fast = fast->next->next; }
// Reverse from slow->next
Node* prev = nullptr, *curr = slow->next;
while (curr) { Node* t = curr->next; curr->next = prev; prev = curr; curr = t; }
// Compare head with prev (reversed second half)
```

---

## 17.4 The "Previous Node" Trick for Deletion

```cpp
// To delete a node, you need its PREVIOUS node
// Use a 'prev' pointer that always lags one step behind curr

Node* prev = dummy;
Node* curr = head;
while (curr) {
    if (shouldDelete(curr)) {
        prev->next = curr->next;  // Skip curr
        delete curr;
        curr = prev->next;        // Don't advance prev
    } else {
        prev = curr;
        curr = curr->next;
    }
}
```

---

## 17.5 Cycle-Related Tricks

```cpp
// Trick: After Floyd's Phase 2, slow and ptr meet at CYCLE START
// This is the key insight for LeetCode 142

// Trick: Cycle length = count steps from meeting point back to meeting point
int len = 0;
Node* temp = meetingPoint;
do { temp = temp->next; len++; } while (temp != meetingPoint);
```

---

## 17.6 Merge Tricks

```cpp
// Trick: Use the smaller head as the "anchor"
// No need to create new nodes — reuse existing nodes
// Always attach result to dummy->next for clean return

// Trick: After merging two halves, attach remaining tail directly
curr->next = l1 ? l1 : l2;  // Attach whichever has remaining nodes
```

---

# SECTION 18: COMMON MISTAKES

## 18.1 Null Pointer Dereference

```cpp
// ❌ MISTAKE: Not checking null before accessing
Node* curr = head;
while (curr->next != nullptr) {  // CRASHES if head is null!
    curr = curr->next;
}

// ✅ FIX: Check curr itself first
while (curr != nullptr && curr->next != nullptr) {
    curr = curr->next;
}
```

```cpp
// ❌ MISTAKE: Fast pointer not double-checked
fast = fast->next->next;  // CRASHES if fast->next is null!

// ✅ FIX: Always check both conditions
while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
}
```

---

## 18.2 Losing Node Reference

```cpp
// ❌ MISTAKE: Advancing pointer before saving next
head->next = newNode;   // Lost reference to original head->next!

// ✅ FIX: Save next before modifying
Node* temp = head->next;
head->next = newNode;
newNode->next = temp;
```

```cpp
// ❌ MISTAKE: Deleting head before saving next
delete head;
head = head->next;  // head is already deleted! Undefined behavior.

// ✅ FIX: Save next first
Node* temp = head->next;
delete head;
head = temp;
```

---

## 18.3 Incorrect Pointer Update Order

```cpp
// ❌ MISTAKE: Wrong order in reversal
curr->next = prev;   // OK
prev = curr->next;   // WRONG! curr->next is now prev (already changed)
curr = curr->next;   // WRONG!

// ✅ FIX: Save next first, then update in correct order
Node* nextNode = curr->next;  // Save next FIRST
curr->next = prev;            // Reverse pointer
prev = curr;                  // Advance prev
curr = nextNode;              // Advance curr using saved value
```

---

## 18.4 Infinite Loops

```cpp
// ❌ MISTAKE: Forgetting to advance pointer
while (curr != nullptr) {
    if (curr->data == target) return curr;
    // Forgot: curr = curr->next; ← infinite loop!
}

// ❌ MISTAKE: Circular list traversal without termination
Node* curr = head;
while (curr->next != nullptr) {  // NULL never reached in circular list!
    curr = curr->next;
}

// ✅ FIX for circular: check against head
Node* curr = head;
do {
    process(curr);
    curr = curr->next;
} while (curr != head);
```

---

## 18.5 Memory Leaks

```cpp
// ❌ MISTAKE: Not freeing deleted nodes
Node* temp = curr->next;
curr->next = temp->next;
// forgot: delete temp; ← memory leak

// ❌ MISTAKE: Losing reference to entire list
Node* result = ...;
head = nullptr;  // If head is the only reference to list, rest is leaked

// ✅ FIX: Always delete nodes you're removing
Node* temp = curr->next;
curr->next = temp->next;
delete temp;   // Free memory!

// ✅ FIX for list cleanup:
while (head) {
    Node* temp = head;
    head = head->next;
    delete temp;
}
```

---

## 18.6 Edge Cases Checklist

```
For ANY linked list problem, always test:
✓ Empty list (head = nullptr)
✓ Single node
✓ Two nodes
✓ Even-length list
✓ Odd-length list
✓ All identical elements
✓ Already sorted (for sorting problems)
✓ Reverse sorted
✓ k = 0 or k = n (for k-related problems)
✓ Cycle at head (for cycle problems)
✓ Cycle at tail
✓ n = 1 (for remove nth)
```

---

## 18.7 DLL-Specific Mistakes

```cpp
// ❌ MISTAKE: Not updating prev pointer when inserting
newNode->next = node->next;
node->next = newNode;         // Forgot: newNode->prev = node
                              // Forgot: if newNode->next: newNode->next->prev = newNode

// ✅ FIX:
newNode->next = node->next;
newNode->prev = node;
if (node->next) node->next->prev = newNode;
node->next = newNode;
```

---

# SECTION 19: COMPLETE LINKED LIST QUESTION LIST

## Easy Problems

| # | Problem | Platform | Pattern | Key Idea |
|---|---------|----------|---------|----------|
| 1 | Reverse Linked List | LC 206 | Reversal | 3-pointer iterative |
| 2 | Middle of Linked List | LC 876 | Fast-Slow | Slow = middle when fast ends |
| 3 | Linked List Cycle | LC 141 | Cycle Detection | Floyd's phase 1 |
| 4 | Merge Two Sorted Lists | LC 21 | Merge | Dummy + two pointers |
| 5 | Remove Duplicates from Sorted List | LC 83 | Traversal | Skip if curr==curr->next |
| 6 | Delete Node in LL (given node) | LC 237 | In-place | Copy next data, skip next |
| 7 | Intersection of Two Linked Lists | LC 160 | Two Pointer | Traverse both, switch heads |
| 8 | Palindrome Linked List | LC 234 | Fast-Slow+Reverse | Find mid, reverse, compare |
| 9 | Convert Binary LL to Integer | LC 1290 | Traversal | val = val*2 + curr->data |
| 10 | Remove Linked List Elements | LC 203 | Dummy Node | Remove all occurrences of val |
| 11 | Design Linked List | LC 707 | Implementation | Implement all basic ops |
| 12 | Linked List Cycle II | LC 142 | Floyd's Phase 2 | Reset ptr to head |
| 13 | Get Decimal Value of LL as Binary | LC 1290 | Traversal | Bit manipulation |
| 14 | Count Nodes in Linked List | - | Traversal | Count while not null |
| 15 | Find Length of Linked List | - | Traversal | Traverse and count |
| 16 | Search in Linked List | - | Traversal | Linear search |
| 17 | Delete all occurrences of key | - | Dummy | Skip matching nodes |
| 18 | Print LL in Reverse | - | Recursion | Recurse then print |
| 19 | Check if LL is Sorted | - | Traversal | curr <= curr->next |
| 20 | Remove Duplicates (unsorted) | LC 82 | HashSet | Track seen values |
| 21 | Merge Sorted LLs (recursive) | LC 21 | Recursion | Base + merge step |
| 22 | Split LL into Two Halves | - | Fast-Slow | Find mid, split |
| 23 | Convert LL to Array | - | Traversal | Push to vector |
| 24 | Create LL from Array | - | Construction | Link nodes |
| 25 | Sum of LL | - | Traversal | Accumulate |
| 26 | Maximum in LL | - | Traversal | Track max |
| 27 | Minimum in LL | - | Traversal | Track min |
| 28 | Nth node from end | - | Two Pointer | Gap of n |
| 29 | Check common element in two LL | - | HashSet | Intersection check |
| 30 | Append last N nodes to front | - | Rotation | Find split point |
| 31 | Multiply Two LL as Numbers | - | Traversal | Traverse, compute |
| 32 | Delete Nth node from end | LC 19 | Two Pointer | Dummy + gap n+1 |
| 33 | Swap data of kth and (n-k+1)th node | - | Two Pointer | Find both nodes |
| 34 | Flatten a Multilevel LL | LC 430 | DFS/Traversal | Unfold levels |
| 35 | Clone LL with Random Pointer | LC 138 | HashMap | Map old→new |
| 36 | Add 1 to Number LL | - | Reverse | Reverse, add, reverse back |
| 37 | Add Two Numbers (LL) | LC 2 | Traversal | Digit by digit with carry |
| 38 | Subtract Two Numbers (LL) | - | Traversal | Similar to add |
| 39 | Check if LL length is even or odd | - | Fast Pointer | fast moves 2x |
| 40 | Find pair with given sum in sorted DLL | - | Two Pointer | Head+tail pointers |
| 41 | Count triplets in sorted DLL | - | Two Pointer | Fix one, two-ptr rest |
| 42 | Rotate LL by k | LC 61 | Rotation | Cycle, find new tail |
| 43 | Segregate Even/Odd nodes | - | Partition | Two sublists |
| 44 | Move last node to front | - | Traversal | Find second-to-last |
| 45 | Check if two LLs are identical | - | Traversal | Node-by-node compare |
| 46 | Remove all nodes with greater value | - | Stack/Reverse | Monotone from right |
| 47 | Insert in sorted LL | - | Traversal | Find position, insert |
| 48 | Delete without head pointer | LC 237 | Copy trick | Copy next, delete next |
| 49 | Swap nodes in LL | LC 1721 | Find+Swap | Locate positions, swap data |
| 50 | Next Greater Node | LC 1019 | Stack + LL | Monotone stack |

---

## Medium Problems

| # | Problem | Platform | Pattern | Key Idea |
|---|---------|----------|---------|----------|
| 1 | Add Two Numbers | LC 2 | Traversal | Carry propagation |
| 2 | Remove Nth from End | LC 19 | Two Pointer | Dummy + n+1 gap |
| 3 | Swap Nodes in Pairs | LC 24 | Reversal | Swap adjacent pairs |
| 4 | Rotate List | LC 61 | Rotation | Make circular, cut |
| 5 | Partition List | LC 86 | Partition | Two sublists, connect |
| 6 | Reverse Linked List II | LC 92 | Reversal | Dummy + boundary |
| 7 | Copy List with Random Pointer | LC 138 | HashMap | Two-pass or interleave |
| 8 | Linked List Cycle II | LC 142 | Floyd's | Phase 1 + Phase 2 |
| 9 | Reorder List | LC 143 | Multi-Pattern | Mid + Reverse + Merge |
| 10 | Sort List | LC 148 | Merge Sort | Find mid, sort, merge |
| 11 | Insertion Sort List | LC 147 | Insertion Sort | Dummy + find position |
| 12 | Reverse Nodes in k-Group | LC 25 | Group Reversal | Check k, reverse, recurse |
| 13 | Odd Even Linked List | LC 328 | Partition | Odd/Even sublists |
| 14 | Remove Duplicates from Sorted LL II | LC 82 | Dummy | Skip all duplicates |
| 15 | Flatten Multilevel DLL | LC 430 | DFS | Unfold child lists |
| 16 | Split LL in Parts | LC 725 | Traversal | Calculate sizes |
| 17 | Linked List Components | LC 817 | HashSet | Check set membership |
| 18 | Convert Binary LL to Integer | LC 1290 | Traversal | Bit shifting |
| 19 | Next Greater Node | LC 1019 | Stack | Monotone stack |
| 20 | Middle of LL (variations) | LC 876 | Fast-Slow | Various stop conditions |
| 21 | Swapping Nodes in LL | LC 1721 | Two Pointer | Find kth, find (n-k+1)th |
| 22 | Merge Nodes Between Zeros | LC 2181 | Traversal | Accumulate between zeros |
| 23 | Delete Node (not tail) | LC 237 | Copy Trick | Copy next value |
| 24 | Design Browser History | LC 1472 | DLL | Insert + traverse |
| 25 | Design Circular Queue | LC 622 | Circular LL | Array-based or LL |
| 26 | Reverse Even Length Groups | LC 2074 | Reversal | Group by group |
| 27 | Maximum Twin Sum | LC 2130 | Fast-Slow+Reverse | Find mid, reverse, sum |
| 28 | Delete Nodes from LL Present in Array | LC 3217 | HashSet | Filter traversal |
| 29 | Merge in Between | LC 1669 | Traversal | Find bounds, replace |
| 30 | Insert into Sorted Circular LL | LC 708 | Traversal | Handle edge cases |
| 31 | Design Linked List | LC 707 | Implementation | Full implementation |
| 32 | Smallest Value After Removing... | LC 2487 | Stack | Monotone stack |
| 33 | Remove Nodes from LL | LC 2487 | Stack/Reverse | Greater on right |
| 34 | Add Two Numbers II | LC 445 | Stack/Reverse | No modifying input |
| 35 | Number of Nodes in LL | - | Traversal | Count pass |
| 36 | Middle of LL (first middle) | - | Fast-Slow | Variant start |
| 37 | Merge Sort Linked List | - | Merge Sort | Classic impl |
| 38 | Quicksort on LL | - | Partition | Pivot + partition |
| 39 | Self Organizing List | - | Frequency | Move-to-front |
| 40 | Segregate 0s, 1s, 2s | - | Dutch National Flag | 3 sublists |
| 41 | Reverse alternate K nodes | - | Reversal | Alternate rev/skip |
| 42 | Rearrange LL | - | Multi-Pattern | Mid, reverse, merge |
| 43 | Sort biotonic DLL | - | Merge Sort | Split at peak |
| 44 | Flatten LL to sorted | - | Merge | Merge down |
| 45 | Multiply 2 LL numbers | - | Stack | LIFO multiply |
| 46 | Merge K sorted (divide conquer) | LC 23 | D&C | Binary reduction |
| 47 | Find pairs with given sum in DLL | - | Two Ptr | Head + tail |
| 48 | Delete middle node | LC 2095 | Fast-Slow | Find mid-1 |
| 49 | Swap adjacent nodes values | - | Traversal | Swap data |
| 50 | Clone DLL | - | HashMap | Copy + link |
| 51 | Count distinct elements in LL | - | HashSet | Count |
| 52 | Sorted insert into sorted circular LL | - | Traversal | 3 cases |
| 53 | Remove all occurrences of x | - | Dummy | Skip matches |
| 54 | Sum of last n nodes | - | Two Pointer | Advance n, sum rest |
| 55 | Recursive reverse in groups | - | Recursion | Group + recurse |
| 56 | Double a Number Represented as LL | LC 2816 | Stack/Reverse | Reverse, double, carry |
| 57 | Node Swap | LC 24 | Dummy + Pointers | Iterative pair swap |
| 58 | Delete Nodes and Return Forest | - | DFS | If deleted, cut links |
| 59 | Design LRU Cache | LC 146 | DLL+HashMap | O(1) get/put |
| 60 | Design LFU Cache | LC 460 | DLL+HashMap | Frequency tracking |
| 61 | All O`one Data Structure | LC 432 | DLL+HashMap | Bucket by frequency |
| 62 | Plus One Linked List | LC 369 | Reverse or Recurse | Find last non-9 |
| 63 | Linked list random node | LC 382 | Reservoir Sampling | Equal probability |
| 64 | Remove zero sum sub-lists | LC 1171 | Prefix Sum + Map | Running sum |
| 65 | Convert sorted list to BST | LC 109 | Fast-Slow | Inorder + BST build |
| 66 | Maximum chunk to make sorted | - | Array-based | (LL variant) |
| 67 | Rearrange LL in place | - | Multi-Pattern | Verify reversal approach |
| 68 | LL in Binary Search Tree | LC 1367 | DFS | Match sequence |
| 69 | Merge LL Alternately | LC 1669 | Merge | Interleave nodes |
| 70 | Length of Longest Palindrome Sublist | - | Reverse + Compare | Variations |
| 71 | All Valid Triplets | - | Three Pointer | Three-ptr traversal |
| 72 | Count pairs with given sum | - | HashSet | Track seen values |
| 73 | Doubly LL Sorting | - | Various | Compare sorts |
| 74 | Circular buffer (LL impl) | - | Circular LL | Wrap-around |
| 75 | Josephus Circular (generalized) | - | Circular LL | Count k each time |
| 76–100 | Additional GFG / Codeforces variants | GFG | Mixed | Practice each pattern |

---

## Hard Problems

| # | Problem | Platform | Pattern | Key Idea |
|---|---------|----------|---------|----------|
| 1 | Merge K Sorted Lists | LC 23 | D&C + Merge | O(N log k) |
| 2 | Reverse Nodes in K-Group | LC 25 | Group Reversal | Check k exist |
| 3 | Copy List with Random Pointer | LC 138 | HashMap / Interleave | O(1) space variant |
| 4 | Sort List (optimal) | LC 148 | Bottom-up Merge Sort | O(1) space |
| 5 | Design LRU Cache | LC 146 | DLL + HashMap | O(1) all ops |
| 6 | Design LFU Cache | LC 460 | DLL + HashMap | Min freq tracking |
| 7 | LRU Cache II (with TTL) | - | DLL + HashMap | Expiry tracking |
| 8 | All O`one Data Structure | LC 432 | DLL + HashMap | Max/min in O(1) |
| 9 | Text Justification (LL-based) | - | Complex | Word wrapping |
| 10 | Largest Rectangle in Histogram (LL) | - | Monotone Stack | Convert approach |
| 11 | Detect cycle in undirected graph (adj list) | - | DFS on LL | Graph adaptation |
| 12 | Reverse a LL in groups alternately | GFG | Group Reversal | Alternate rev/skip |
| 13 | Delete nodes > all right nodes | - | Reverse | O(n) monotone |
| 14 | Flatten LL to strictly increasing | - | Merge | Multi-level |
| 15 | Sort a LL of 0s, 1s, 2s | GFG | Dutch Flag | Count or partition |
| 16 | Skip M nodes, delete N nodes | - | Traversal | Count and skip |
| 17 | Merge K sorted LL (via heap) | LC 23 | Priority Queue | O(N log k) |
| 18 | LL to represent number, multiply two | - | Stack | LL arithmetic |
| 19 | Convert BST to sorted DLL | LC 426 | Inorder DFS | O(1) space trick |
| 20 | Longest palindrome by concatenating | - | Complex | Manacher on LL |
| 21 | Maximum XOR of LL elements | - | Trie of LL | Bit trie |
| 22 | Rearrange chars in LL by frequency | - | HashMap + Sort | Priority queue |
| 23 | Count of reversals for sorted | - | Counting | Inversions |
| 24 | Circular tour problem (LL) | - | Circular LL | Greedy |
| 25 | Memory allocator (LL) | - | Free List | First-fit/best-fit |
| 26 | Skip list implementation | - | Probabilistic | Tower of pointers |
| 27 | XOR Linked List | - | XOR Trick | Prev XOR next = ptr |
| 28 | Serialize/Deserialize LL | - | Encoding | String encoding |
| 29 | Multi-level flatten to sorted | - | D&C Merge | Recursive flatten |
| 30 | LL with least recently used order | - | DLL | Cache simulation |
| 31 | Merge sort bottom-up O(1) space | LC 148 | Bottom-up | Block-by-block merge |
| 32 | Find all cycles in LL | - | DFS + Colors | Graph approach |
| 33 | Reverse alternating K nodes | GFG | Group Reversal | Rev K, skip K |
| 34 | Partition to make pairs from ends | - | Two Pointer | Head + tail |
| 35 | Longest increasing subsequence in LL | - | DP on LL | Patience sorting |
| 36 | Interleave two halves | - | Split + Merge | Find mid + interleave |
| 37 | Remove all subsets summing to 0 | LC 1171 | Prefix Sum | Cumulative map |
| 38 | Evaluate complex expression (LL) | - | Stack-based | Parse tree |
| 39 | Clone graph as adjacency LL | - | BFS/DFS | Copy + map |
| 40 | LL-based dictionary | - | Hashing | Chaining with LL |
| 41 | Queue using two stacks (LL) | - | LL Stack | Amortized O(1) |
| 42 | Deque using DLL | - | DLL | Four O(1) ops |
| 43 | Implement hash map with chaining | - | LL Chaining | Full implementation |
| 44 | Scheduler using circular LL | - | Circular | Round-robin |
| 45 | Memory pool allocator | - | Free List | Buddy system |
| 46 | Rope data structure | - | LL Segments | String concat O(1) |
| 47 | Fibonacci heap | - | DLL | Complex but powerful |
| 48 | Splay tree as LL | - | Advanced | Move to root |
| 49 | Segment LL for range queries | - | Advanced | Chunking |
| 50 | Online median with two DLLs | - | DLL + Balance | Maintain order |

---

# SECTION 20: REVISION CHEAT SHEET

## 20.1 Linked List Complexity Cheat Sheet

```
╔══════════════════════╦════════════╦════════════╗
║ Operation            ║    SLL     ║    DLL     ║
╠══════════════════════╬════════════╬════════════╣
║ Access (index)       ║   O(n)     ║   O(n)     ║
║ Search               ║   O(n)     ║   O(n)     ║
║ Insert at head       ║   O(1)     ║   O(1)     ║
║ Insert at tail       ║ O(n)/O(1)* ║   O(1)*    ║
║ Insert at middle     ║   O(n)     ║   O(n)     ║
║ Delete at head       ║   O(1)     ║   O(1)     ║
║ Delete at tail       ║   O(n)     ║   O(1)*    ║
║ Delete (given ptr)   ║   O(n)     ║   O(1)     ║
║ Reverse              ║   O(n)     ║   O(n)     ║
║ Find middle          ║   O(n)     ║   O(n)     ║
║ Detect cycle         ║   O(n)     ║   O(n)     ║
║ Sort (merge sort)    ║ O(n log n) ║ O(n log n) ║
╚══════════════════════╩════════════╩════════════╝
* With tail pointer maintained
```

---

## 20.2 Pattern Quick-Reference

```
PATTERN               WHEN                   TEMPLATE HINT
─────────────────────────────────────────────────────────────
Fast-Slow             Middle, Cycle          f=h, s=h; f+=2, s+=1
Two Pointer (gap)     Kth from end           advance first by k+1
Reversal              Reverse list/part      prev, curr, next
Dummy Node            Head might change      Node dummy(0); dummy.next=head
Partition             Separate by condition  Two sublists + connect
Merge                 Combine sorted         Dummy + compare heads
Floyd's               Cycle start            Phase1: detect, Phase2: reset
Multi-pointer         Reorder/Rearrange      Split+Reverse+Merge
```

---

## 20.3 Fast-Slow Pointer Template

```cpp
// TEMPLATE 1: Find middle (second middle for even)
Node* findMiddle(Node* head) {
    Node* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// TEMPLATE 2: Find middle (first middle for even)
Node* findFirstMiddle(Node* head) {
    Node* slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// TEMPLATE 3: Detect cycle
bool hasCycle(Node* head) {
    Node* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// TEMPLATE 4: Find cycle start
Node* cycleStart(Node* head) {
    Node* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) {
            Node* ptr = head;
            while (ptr != slow) { ptr = ptr->next; slow = slow->next; }
            return ptr;
        }
    }
    return nullptr;
}
```

---

## 20.4 Reversal Template

```cpp
// TEMPLATE 1: Full reversal (iterative)
Node* reverse(Node* head) {
    Node* prev = nullptr, *curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// TEMPLATE 2: Reverse between positions
Node* reverseBetween(Node* head, int l, int r) {
    Node* dummy = new Node(0); dummy->next = head;
    Node* pre = dummy;
    for (int i = 0; i < l-1; i++) pre = pre->next;
    Node* curr = pre->next;
    for (int i = 0; i < r-l; i++) {
        Node* nxt = curr->next;
        curr->next = nxt->next;
        nxt->next = pre->next;
        pre->next = nxt;
    }
    return dummy->next;
}

// TEMPLATE 3: Reverse K groups
Node* reverseKGroup(Node* head, int k) {
    Node* check = head;
    for (int i = 0; i < k; i++) { if (!check) return head; check = check->next; }
    Node* prev = nullptr, *curr = head;
    for (int i = 0; i < k; i++) { Node* nxt = curr->next; curr->next = prev; prev = curr; curr = nxt; }
    head->next = reverseKGroup(curr, k);
    return prev;
}
```

---

## 20.5 Merge Template

```cpp
// TEMPLATE: Merge two sorted linked lists
Node* merge(Node* l1, Node* l2) {
    Node* dummy = new Node(0);
    Node* curr = dummy;
    while (l1 && l2) {
        if (l1->data <= l2->data) { curr->next = l1; l1 = l1->next; }
        else { curr->next = l2; l2 = l2->next; }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return dummy->next;
}
```

---

## 20.6 Dummy Node Template

```cpp
// TEMPLATE: Any operation that might modify head
Node* operation(Node* head) {
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* curr = dummy;
    
    // ... perform operations on curr->next ...
    
    Node* result = dummy->next;
    delete dummy;
    return result;
}
```

---

## 20.7 Complete Node Implementation (Production-Ready)

```cpp
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Helper: Create list from vector
ListNode* makeList(vector<int> v) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int x : v) { curr->next = new ListNode(x); curr = curr->next; }
    return dummy->next;
}

// Helper: Print list
void print(ListNode* head) {
    while (head) { cout << head->val; if (head->next) cout << "→"; head = head->next; }
    cout << "→NULL\n";
}

// Helper: Free list
void freeList(ListNode* head) {
    while (head) { ListNode* t = head->next; delete head; head = t; }
}
```

---

# SECTION 21: FINAL LINKED LIST ROADMAP

## 21.1 Beginner → Intermediate → Advanced Path

```
WEEK 1-2: FOUNDATIONS
━━━━━━━━━━━━━━━━━━━━━
□ Understand node structure (data + next)
□ Dynamic memory allocation (new/delete)
□ Create SLL manually
□ Implement traversal
□ Implement search
□ Insert at head (O(1))
□ Insert at tail (O(n))
□ Delete at head (O(1))
□ Delete at tail (O(n))
□ Print list
□ Count nodes, find max/min

Practice (Easy): LC 707 (Design LL), LC 203, LC 83

WEEK 3: REVERSAL MASTERY
━━━━━━━━━━━━━━━━━━━━━━━━
□ Iterative reversal (3 pointers)
□ Recursive reversal
□ Understand the pointer swap sequence
□ Reverse k-group
□ Reverse between positions

Practice: LC 206, LC 92, LC 25, LC 24

WEEK 4: FAST-SLOW POINTERS
━━━━━━━━━━━━━━━━━━━━━━━━━━
□ Find middle node
□ Detect cycle (Floyd's Phase 1)
□ Find cycle start (Floyd's Phase 2)
□ Find cycle length
□ Understand WHY Floyd's works

Practice: LC 876, LC 141, LC 142, LC 234

WEEK 5: MERGING AND SORTING
━━━━━━━━━━━━━━━━━━━━━━━━━━━
□ Merge two sorted lists
□ Understand dummy node pattern
□ Merge K sorted lists (D&C + heap)
□ Sort list using merge sort
□ Insertion sort on LL

Practice: LC 21, LC 23, LC 148, LC 147

WEEK 6: INTERMEDIATE PATTERNS
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
□ Remove Nth from end (two pointer gap)
□ Rotate list
□ Partition list
□ Odd-even LL
□ Intersection of two lists
□ Copy list with random pointer

Practice: LC 19, LC 61, LC 86, LC 328, LC 160, LC 138

WEEK 7: DOUBLY AND CIRCULAR
━━━━━━━━━━━━━━━━━━━━━━━━━━━
□ Implement DLL (all operations)
□ O(1) delete with DLL
□ LRU Cache (DLL + HashMap)
□ Circular LL (all operations)
□ Josephus problem
□ Circular buffer

Practice: LC 146, LC 622

WEEK 8: ADVANCED PROBLEMS
━━━━━━━━━━━━━━━━━━━━━━━━━
□ Reorder list (LC 143)
□ Reverse K-group optimally (LC 25)
□ Bottom-up merge sort (O(1) space)
□ Design LFU Cache (LC 460)
□ Flatten multilevel DLL (LC 430)

Practice: LC 143, LC 25, LC 148 (O(1) space), LC 460, LC 430
```

---

## 21.2 Weekly Revision Plan

```
DAILY (15 min): Review one pattern template
WEEKLY (1 hr):  Solve 5 problems of current level
BIWEEKLY:       Do one timed mock (solve 3 LL problems in 45 min)
```

---

## 21.3 Must-Know Problems for Interviews

```
TIER 1 (Must know cold):
  LC 206  - Reverse Linked List
  LC 21   - Merge Two Sorted Lists
  LC 141  - Linked List Cycle
  LC 876  - Middle of Linked List
  LC 19   - Remove Nth Node from End
  LC 206  - Reverse Linked List

TIER 2 (High frequency):
  LC 142  - Linked List Cycle II
  LC 234  - Palindrome Linked List
  LC 143  - Reorder List
  LC 92   - Reverse Linked List II
  LC 148  - Sort List
  LC 146  - LRU Cache

TIER 3 (Advanced / FAANG):
  LC 25   - Reverse Nodes in K-Group
  LC 23   - Merge K Sorted Lists
  LC 138  - Copy List with Random Pointer
  LC 460  - LFU Cache
  LC 432  - All O`one Data Structure
```

---

## 21.4 Pre-Interview Quick Checklist

```
30 MINUTES BEFORE YOUR INTERVIEW:

PATTERNS TO RECALL:
  □ Fast-slow: while(f && f->next) { s=s->next; f=f->next->next; }
  □ Reversal:  prev=null; while(c){ n=c->next; c->next=prev; prev=c; c=n; }
  □ Dummy:     Node* d=new Node(0); d->next=head; ... return d->next;
  □ Merge:     while(l1&&l2){ pick smaller, advance }; attach rest

EDGE CASES:
  □ null input
  □ single node
  □ two nodes
  □ even/odd length

COMPLEXITY:
  □ Most LL algorithms: O(n) time, O(1) space
  □ Recursive: O(n) space (call stack)
  □ Sort: O(n log n) time
```

---

## 21.5 Mental Models for Linked Lists

```
1. POINTER = GPS COORDINATE
   Don't think of pointers as confusing.
   A pointer is just a GPS coordinate (memory address).
   "Node* p = 0x1234" means "p holds the address 0x1234"
   "*p" means "the thing AT address 0x1234"

2. LINKED LIST = CHAIN OF POINTERS
   Each node is a box. Each box has a label (data) and
   an arrow (next pointer) pointing to the next box.

3. TRAVERSAL = FOLLOWING ARROWS
   Start at head, follow arrows until you reach NULL.

4. REVERSAL = FLIPPING ARROWS
   Make each arrow point backward instead of forward.

5. FAST-SLOW = TWO RUNNERS
   Slow runs at 1 mph, fast at 2 mph.
   If on a circular track: fast catches slow.
   If on a straight path: fast reaches end first.

6. DUMMY NODE = FAKE STARTING LINE
   Create a fake node before head so you never have to
   special-case "what if head changes?"
```

---

## 21.6 Final Summary Table

| Topic | Key Concept | Go-To Algorithm |
|-------|-------------|----------------|
| Reversal | Flip all next pointers | 3-pointer iterative |
| Middle | Split list | Fast-slow pointer |
| Cycle detect | Loop check | Floyd's Phase 1 |
| Cycle start | Find entry point | Floyd's Phase 2 |
| Kth from end | Gap technique | Two pointers, gap=k |
| Merge sorted | Combine in order | Dummy + compare heads |
| Sort LL | Best sorting | Merge sort (O(n log n)) |
| Delete node | Previous needed | Dummy node pattern |
| Palindrome | Mirror check | Find mid + reverse + compare |
| LRU Cache | O(1) get/put | DLL + HashMap |
| Cycle removal | Fix last node | Floyd's + find tail |
| Reorder | Complex rearrange | Find mid + reverse + merge |

---

> **Remember:** Every linked list problem reduces to pointer manipulation.
> Master the 10 patterns, practice the 20 core problems, and you'll be ready for any linked list interview question.

---

