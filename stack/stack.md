# 📚 THE ULTIMATE STACK HANDBOOK
### From Absolute Beginner to Interview Champion

---

> **Who is this for?**
> Complete beginners · Intermediate learners · Placement prep · Online assessments · Competitive programming · Technical interviews · Last-minute revision

---

## TABLE OF CONTENTS

| Section | Topic |
|---------|-------|
| 1 | Stack Fundamentals |
| 2 | Stack Implementation |
| 3 | Stack Operations |
| 4 | Stack Memory Model |
| 5 | Complexity Analysis |
| 6 | Recursion and Stack |
| 7 | Important Stack Patterns |
| 8 | Monotonic Stack Mastery |
| 9 | Expression Problems |
| 10 | Balanced Parentheses Mastery |
| 11 | Important Stack Algorithms |
| 12 | Special Stacks |
| 13 | Monotonic Stack Interview Framework |
| 14 | Stack in Arrays and Strings |
| 15 | Interview Framework |
| 16 | Common Tricks |
| 17 | Common Mistakes |
| 18 | Complete Stack Question List |
| 19 | Revision Cheat Sheet |
| 20 | Final Stack Roadmap |

---

# SECTION 1: STACK FUNDAMENTALS

---

## 1.1 What is a Stack?

### Definition

A **Stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle. The element inserted last is the one that comes out first — just like a stack of plates.

### Intuition

Imagine a stack of plates:
- You place plates one on top of another.
- You can only take the **topmost** plate.
- You cannot access the bottom plate without removing all plates above it.

```
        ┌─────────┐
        │ Plate 5 │  ← TOP (Last In, First Out)
        ├─────────┤
        │ Plate 4 │
        ├─────────┤
        │ Plate 3 │
        ├─────────┤
        │ Plate 2 │
        ├─────────┤
        │ Plate 1 │  ← BOTTOM (First In, Last Out)
        └─────────┘
```

### Visual Explanation

```
  PUSH 10        PUSH 20        PUSH 30        POP           POP
  ┌────┐         ┌────┐         ┌────┐         ┌────┐        ┌────┐
  │ 10 │ ← top  │ 20 │ ← top  │ 30 │ ← top  │ 20 │ ← top  │ 10 │ ← top
  └────┘         ├────┤         ├────┤         ├────┤        └────┘
                 │ 10 │         ├────┤         │ 10 │
                 └────┘         │ 20 │         └────┘
                                ├────┤
                                │ 10 │
                                └────┘
```

---

## 1.2 Why Stacks Exist

Stacks solve the fundamental problem of **ordered reversal** and **nested/recursive processing**. Many real-world and computing problems need to process the most recently seen item first.

| Problem | Why Stack Helps |
|---------|----------------|
| Function calls | Most recent call must return first |
| Undo operation | Last action undone first |
| Bracket matching | Most recently opened must close first |
| Expression evaluation | Operators follow precedence rules |
| Path simplification | Backtrack from most recent directory |

---

## 1.3 Real World Applications

| Domain | Application |
|--------|-------------|
| **Browser** | Back/Forward navigation (back stack) |
| **Text Editors** | Undo/Redo operations |
| **Compilers** | Syntax checking, expression evaluation |
| **OS** | Function call stack, interrupt handling |
| **Mathematics** | Evaluation of expressions |
| **Graph Algorithms** | DFS traversal |
| **Parsing** | XML/HTML tag matching |
| **Memory** | Stack memory segment in programs |

---

## 1.4 LIFO Principle

**LIFO = Last In, First Out**

```
Timeline →
  t=0: Push A  →  [A]
  t=1: Push B  →  [A, B]
  t=2: Push C  →  [A, B, C]
  t=3: Pop     →  returns C, stack = [A, B]
  t=4: Pop     →  returns B, stack = [A]
  t=5: Pop     →  returns A, stack = []

Order of removal: C, B, A  (reverse of insertion order)
```

This is the exact **opposite** of a Queue (FIFO = First In, First Out).

---

## 1.5 Stack Terminology

| Term | Meaning |
|------|---------|
| **Push** | Insert element at the top |
| **Pop** | Remove element from the top |
| **Top / Peek** | View top element without removing |
| **Overflow** | Push to a full stack |
| **Underflow** | Pop from an empty stack |
| **Empty** | Stack has no elements |
| **Size** | Number of elements currently in stack |

---

## 1.6 Stack Representation

### 1. Array Representation

```
Index:  0    1    2    3    4
        ┌────┬────┬────┬────┬────┐
        │ 10 │ 20 │ 30 │ -- │ -- │
        └────┴────┴────┴────┴────┘
                    ↑
                  top = 2
```

### 2. Linked List Representation

```
  top
   ↓
  ┌───┬──────┐    ┌───┬──────┐    ┌───┬──────┐
  │30 │  ●───┼───►│20 │  ●───┼───►│10 │ NULL │
  └───┴──────┘    └───┴──────┘    └───┴──────┘
```

---

## 1.7 Stack Memory Model

```
HIGH ADDRESS
┌──────────────────┐
│   Stack Segment  │  ← grows downward
│  (function calls)│
│         ↓        │
├──────────────────┤
│        ...       │
├──────────────────┤
│         ↑        │
│   Heap Segment   │  ← grows upward
├──────────────────┤
│   BSS / Data     │  (global/static variables)
├──────────────────┤
│   Text Segment   │  (code)
└──────────────────┘
LOW ADDRESS
```

---

## 1.8 Stack vs Queue

| Feature | Stack | Queue |
|---------|-------|-------|
| Principle | LIFO (Last In First Out) | FIFO (First In First Out) |
| Insertion | At top | At rear |
| Deletion | From top | From front |
| Peek | Top element | Front element |
| Use case | Undo, recursion, parsing | BFS, scheduling, buffers |
| Real world | Stack of plates | Queue at a ticket counter |

```
Stack:                          Queue:
  Push → [3][2][1] → Pop        Enqueue → [1][2][3] → Dequeue
         top↑                             front↑    rear↑
  (same end)                    (different ends)
```

---

## 1.9 Stack vs Array

| Feature | Stack | Array |
|---------|-------|-------|
| Access | Only top element | Any index |
| Operations | Push, Pop, Top | Read/Write any position |
| Structure | Abstract (LIFO policy) | Concrete (random access) |
| Use | When order reversal is needed | When random access needed |
| Implementation | Can use array internally | —— |

---

## 1.10 Advantages of Stack

- **Simplicity**: Only three primary operations (push, pop, top)
- **O(1) operations**: All core operations are constant time
- **Memory efficiency**: No wasted memory (dynamic linked list version)
- **Natural for recursion**: Mirrors the call stack behavior
- **Backtracking**: Perfect for undo/redo and backtracking

---

## 1.11 Disadvantages of Stack

- **Limited access**: Only top element accessible
- **No random access**: Cannot access middle elements in O(1)
- **Stack overflow**: Fixed-size array stacks can overflow
- **Memory waste**: Array-based stacks may allocate more than needed
- **Not suitable**: For problems needing arbitrary element access

---

# SECTION 2: STACK IMPLEMENTATION

---

## 2.1 Stack Using Array

### Concept

Use a fixed-size array with a variable `top` pointing to the current top index.

```
  top = -1 means empty stack
  top = MAX-1 means full stack
```

### Memory Layout

```
  arr[]:  [10][20][30][--][--][--][--][--]
  index:   0   1   2   3   4   5   6   7
                    ↑
                  top=2    (MAX=8)
```

### Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class StackArray {
private:
    int arr[1000];
    int top;
    int capacity;

public:
    StackArray(int size = 1000) {
        capacity = size;
        top = -1;
    }

    // Push: O(1)
    void push(int val) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = val;
    }

    // Pop: O(1)
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return arr[top--];
    }

    // Top/Peek: O(1)
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    // Size: O(1)
    int size() {
        return top + 1;
    }

    // Empty: O(1)
    bool empty() {
        return top == -1;
    }

    // Clear: O(1)
    void clear() {
        top = -1;
    }
};

int main() {
    StackArray st(10);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.peek() << "\n"; // 30
    cout << "Pop: " << st.pop() << "\n";  // 30
    cout << "Size: " << st.size() << "\n"; // 2
    cout << "Empty: " << st.empty() << "\n"; // 0
    return 0;
}
```

### Dry Run

```
Initial: top = -1, arr = []

push(10): top = 0, arr = [10]
push(20): top = 1, arr = [10, 20]
push(30): top = 2, arr = [10, 20, 30]
peek():   returns arr[2] = 30, top = 2 (unchanged)
pop():    returns arr[2] = 30, top = 1
pop():    returns arr[1] = 20, top = 0
pop():    returns arr[0] = 10, top = -1
pop():    top == -1, UNDERFLOW
```

### Complexity Analysis

| Operation | Time | Space |
|-----------|------|-------|
| Push | O(1) | O(1) |
| Pop | O(1) | O(1) |
| Peek | O(1) | O(1) |
| Size | O(1) | O(1) |
| Total Space | — | O(N) |

### Advantages
- Cache-friendly (contiguous memory)
- Simple implementation
- O(1) for all operations

### Disadvantages
- Fixed size (overflow possible)
- Memory wasted if not full

---

## 2.2 Stack Using Vector (Dynamic Array)

### Concept

Use `std::vector` which dynamically resizes, eliminating the overflow problem.

```cpp
#include <bits/stdc++.h>
using namespace std;

class StackVector {
private:
    vector<int> v;

public:
    // Push: amortized O(1)
    void push(int val) {
        v.push_back(val);
    }

    // Pop: O(1)
    int pop() {
        if (v.empty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        int val = v.back();
        v.pop_back();
        return val;
    }

    // Top: O(1)
    int peek() {
        if (v.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return v.back();
    }

    int size() { return v.size(); }
    bool empty() { return v.empty(); }
    void clear() { v.clear(); }
};
```

### Internal Working of Vector Resize

```
  Initial: capacity=1,  [10]
  push(20): capacity=2, [10][20]
  push(30): capacity=4, [10][20][30][--]   ← doubles to 4
  push(40): capacity=4, [10][20][30][40]
  push(50): capacity=8, [10][20][30][40][50][--][--][--]  ← doubles to 8
```

### Advantages
- Dynamic size, no overflow
- Still O(1) amortized push

### Disadvantages
- Slight overhead from resizing
- May use more memory than needed

---

## 2.3 Stack Using Linked List

### Concept

Each node points to the node below it. `top` points to the most recently inserted node.

```
  push(10):    top → [10|NULL]
  push(20):    top → [20|→][10|NULL]
  push(30):    top → [30|→][20|→][10|NULL]
  pop():       top → [20|→][10|NULL], returns 30
```

### Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class StackLL {
private:
    Node* top;
    int sz;

public:
    StackLL() : top(nullptr), sz(0) {}

    // Push: O(1)
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        sz++;
    }

    // Pop: O(1)
    int pop() {
        if (!top) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        Node* temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        sz--;
        return val;
    }

    // Peek: O(1)
    int peek() {
        if (!top) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return top->data;
    }

    int size() { return sz; }
    bool empty() { return top == nullptr; }

    void clear() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        sz = 0;
    }

    ~StackLL() { clear(); }
};

int main() {
    StackLL st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.peek() << "\n";  // 30
    cout << st.pop() << "\n";   // 30
    cout << st.size() << "\n";  // 2
    return 0;
}
```

### Memory Layout

```
  top
   ↓
  ┌────┬──────┐    ┌────┬──────┐    ┌────┬──────┐
  │ 30 │  ●───┼───►│ 20 │  ●───┼───►│ 10 │ null │
  └────┴──────┘    └────┴──────┘    └────┴──────┘
```

### Complexity

| Operation | Time | Space |
|-----------|------|-------|
| Push | O(1) | O(1) |
| Pop | O(1) | O(1) |
| Peek | O(1) | O(1) |
| Total Space | — | O(N) |

### Advantages
- Dynamic size, never overflows
- Memory allocated only when needed

### Disadvantages
- Extra memory per node (pointer overhead)
- Not cache-friendly (scattered memory)
- Slower than array due to pointer chasing

---

## 2.4 STL Stack

### Concept

C++ STL provides `std::stack<T>` in `<stack>` header. It is a **container adaptor** built on top of `deque` by default (can also use `vector` or `list`).

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;                    // default: uses deque

    // Push
    st.push(10);
    st.push(20);
    st.push(30);

    // Top
    cout << st.top() << "\n";        // 30

    // Pop
    st.pop();                         // removes 30 (no return value!)
    cout << st.top() << "\n";        // 20

    // Size
    cout << st.size() << "\n";       // 2

    // Empty
    cout << st.empty() << "\n";      // 0 (false)

    // Using vector as underlying container
    stack<int, vector<int>> st2;
    st2.push(100);
    st2.push(200);

    return 0;
}
```

> ⚠️ **IMPORTANT**: `st.pop()` does NOT return the value. To get and remove, do:
> ```cpp
> int val = st.top();
> st.pop();
> ```

### STL Stack Methods

| Method | Description | Complexity |
|--------|-------------|------------|
| `push(x)` | Insert x at top | O(1) amortized |
| `pop()` | Remove top (no return) | O(1) |
| `top()` | Access top element | O(1) |
| `size()` | Number of elements | O(1) |
| `empty()` | Check if empty | O(1) |
| `emplace(args)` | Construct in-place at top | O(1) |
| `swap(other)` | Swap two stacks | O(1) |

---

# SECTION 3: STACK OPERATIONS

---

## 3.1 Push

### Concept

Insert an element at the top of the stack.

### Visualization

```
BEFORE push(40):          AFTER push(40):
  ┌────┐                   ┌────┐
  │ 30 │ ← top             │ 40 │ ← top  (new)
  ├────┤                   ├────┤
  │ 20 │                   │ 30 │
  ├────┤                   ├────┤
  │ 10 │                   │ 20 │
  └────┘                   ├────┤
                           │ 10 │
                           └────┘
```

### Dry Run (Array-based)

```
arr = [10, 20, 30, __, __], top = 2, capacity = 5

push(40):
  Step 1: Check top == capacity - 1? → 2 == 4? → NO (not overflow)
  Step 2: top++ → top = 3
  Step 3: arr[3] = 40
  Result: arr = [10, 20, 30, 40, __], top = 3
```

### Code

```cpp
void push(int val) {
    if (top == capacity - 1) throw overflow_error("Stack Overflow");
    arr[++top] = val;
}
```

### Complexity

| Metric | Array Stack | Linked List Stack | Vector Stack |
|--------|-------------|-------------------|--------------|
| Time | O(1) | O(1) | O(1) amortized |
| Space | O(1) | O(1) | O(1) amortized |

### Common Mistakes

- Forgetting to check for overflow (array-based)
- Incrementing `top` after assignment instead of before (off-by-one)

---

## 3.2 Pop

### Concept

Remove and return the top element.

### Visualization

```
BEFORE pop():             AFTER pop():
  ┌────┐                   ┌────┐
  │ 30 │ ← top → removed   │ 20 │ ← top
  ├────┤                   ├────┤
  │ 20 │                   │ 10 │
  ├────┤                   └────┘
  │ 10 │
  └────┘                   returns 30
```

### Dry Run

```
arr = [10, 20, 30], top = 2

pop():
  Step 1: Check top == -1? → 2 == -1? → NO (not underflow)
  Step 2: val = arr[2] = 30
  Step 3: top-- → top = 1
  Step 4: return 30
  Result: arr = [10, 20, --], top = 1
```

### Code

```cpp
int pop() {
    if (top == -1) throw underflow_error("Stack Underflow");
    return arr[top--];
}
```

### Common Mistakes

- Checking `top == 0` instead of `top == -1` for empty (off-by-one!)
- Forgetting that STL `stack::pop()` doesn't return a value
- Popping without checking if stack is empty

---

## 3.3 Top / Peek

### Concept

View the top element without removing it.

### Visualization

```
  ┌────┐
  │ 30 │ ← peek() returns 30, stack UNCHANGED
  ├────┤
  │ 20 │
  ├────┤
  │ 10 │
  └────┘
```

### Code

```cpp
int peek() {
    if (top == -1) throw underflow_error("Stack Empty");
    return arr[top];   // top does NOT change
}
```

### Common Mistakes

- Calling `pop()` when you only want to peek
- Not checking if stack is empty before peeking

---

## 3.4 Size

### Concept

Returns the number of elements currently in the stack.

```cpp
int size() {
    return top + 1;   // top is 0-indexed, so size = top + 1
}
```

### Dry Run

```
arr = [10, 20, 30], top = 2
size() = top + 1 = 3  ✓
```

---

## 3.5 Empty

### Concept

Returns `true` if the stack has no elements.

```cpp
bool empty() {
    return top == -1;
}
```

### Common Mistake

```cpp
// WRONG:
if (st.size() == 0) { ... }   // works but less idiomatic

// RIGHT:
if (st.empty()) { ... }       // prefer this
```

---

## 3.6 Clear

### Concept

Remove all elements from the stack.

```cpp
// Array-based: O(1)
void clear() {
    top = -1;   // Simply reset top; elements remain but are "logically" gone
}

// Linked List-based: O(n) - must free each node
void clear() {
    while (top) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}
```

---

# SECTION 4: STACK MEMORY MODEL

---

## 4.1 Function Call Stack

Every time a function is called, a new **stack frame** (activation record) is pushed onto the **call stack**. When the function returns, its frame is popped.

```
  Program:
    int main() {
        int x = foo(5);
    }

    int foo(int n) {
        return bar(n) + 1;
    }

    int bar(int n) {
        return n * 2;
    }

  Call Stack (grows downward):
  ┌────────────────┐  ← HIGH ADDRESS
  │   main frame   │  → calls foo
  ├────────────────┤
  │   foo frame    │  → calls bar
  ├────────────────┤
  │   bar frame    │  ← currently executing
  └────────────────┘  ← Stack Pointer (SP)
```

---

## 4.2 Activation Records (Stack Frames)

Each stack frame contains:

```
┌────────────────────────────────────┐
│  Return Address                    │  → where to return after function ends
├────────────────────────────────────┤
│  Previous Frame Pointer (saved FP) │  → to restore caller's frame
├────────────────────────────────────┤
│  Local Variables                   │  → e.g., int x, int y
├────────────────────────────────────┤
│  Parameters / Arguments            │  → e.g., function(int n)
├────────────────────────────────────┤
│  Saved Registers                   │  → CPU registers saved by callee
└────────────────────────────────────┘
```

---

## 4.3 Recursion Stack

### Example: Factorial

```cpp
int factorial(int n) {
    if (n == 0) return 1;      // base case
    return n * factorial(n-1); // recursive call
}

factorial(4):
```

```
Call Stack Build-up:
  ┌─────────────┐
  │factorial(4) │  waiting for factorial(3)
  ├─────────────┤
  │factorial(3) │  waiting for factorial(2)
  ├─────────────┤
  │factorial(2) │  waiting for factorial(1)
  ├─────────────┤
  │factorial(1) │  waiting for factorial(0)
  ├─────────────┤
  │factorial(0) │  returns 1  ← base case
  └─────────────┘

Call Stack Unwind:
  factorial(0) = 1
  factorial(1) = 1 * 1 = 1
  factorial(2) = 2 * 1 = 2
  factorial(3) = 3 * 2 = 6
  factorial(4) = 4 * 6 = 24
```

---

## 4.4 Stack Overflow

**Stack Overflow** occurs when:
1. Infinite recursion (no base case or base case never reached)
2. Recursion too deep (stack memory exhausted)
3. Very large local variables allocated on stack

```cpp
// This causes stack overflow:
int infinite(int n) {
    return infinite(n + 1);  // no base case!
}

// Also stack overflow for large n:
int recurse(int n) {
    int arr[10000];  // large local array on stack each call!
    if (n == 0) return 0;
    return recurse(n - 1);
}
```

```
Stack Overflow:
  ┌──────────────┐
  │ recurse(0)   │
  ├──────────────┤
  │ recurse(1)   │
  ├──────────────┤
  │ recurse(2)   │
  ├──────────────┤
  │ ...          │
  ├──────────────┤
  │ recurse(n)   │  ← STACK OVERFLOW HERE
  └──────────────┘  (exceeds stack memory limit ~1-8 MB typically)
```

### How to Fix Stack Overflow

1. Add/fix base case
2. Use iteration instead of recursion
3. Use tail recursion (compiler optimizes)
4. Use explicit stack (simulate recursion)

---

## 4.5 Local Variables and Return Addresses

```cpp
int add(int a, int b) {
    int sum = a + b;   // sum is a LOCAL variable on the stack frame
    return sum;        // return address stored in stack frame
}
```

```
Stack Frame for add(3, 4):
┌──────────────────────┐
│ Return Address       │  → address of next instruction in caller
│ (e.g., 0x7fff1234)  │
├──────────────────────┤
│ Saved registers      │
├──────────────────────┤
│ Local: sum = 7       │
├──────────────────────┤
│ Param: b = 4         │
├──────────────────────┤
│ Param: a = 3         │
└──────────────────────┘
```

---

# SECTION 5: COMPLEXITY ANALYSIS

---

## 5.1 Complete Complexity Table

| Operation | Array Stack | Vector Stack | Linked List Stack | STL Stack |
|-----------|-------------|--------------|-------------------|-----------|
| Push | O(1) | O(1)* | O(1) | O(1)* |
| Pop | O(1) | O(1) | O(1) | O(1) |
| Top/Peek | O(1) | O(1) | O(1) | O(1) |
| Size | O(1) | O(1) | O(1) | O(1) |
| Empty | O(1) | O(1) | O(1) | O(1) |
| Search | O(n) | O(n) | O(n) | O(n) |
| Clear | O(1) | O(n) | O(n) | O(n) |
| Space | O(N) | O(N) | O(N) | O(N) |

*\* = amortized O(1) for vector (occasional O(n) resize)*

---

## 5.2 Why Push/Pop are O(1)

```
Array-based push:
  arr[++top] = val
  → Just one increment and one assignment
  → No loops, no searching
  → Constant time regardless of stack size ✓

Array-based pop:
  return arr[top--]
  → Just one decrement and one read
  → Constant time ✓
```

---

## 5.3 Why Search is O(n)

A stack only provides access to the top. To find an element:

```cpp
bool search(stack<int>& st, int target) {
    stack<int> temp;
    bool found = false;
    while (!st.empty()) {          // may need to go through all n elements
        if (st.top() == target) {
            found = true;
            break;
        }
        temp.push(st.top());
        st.pop();
    }
    // restore stack
    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
    return found;
}
// Time: O(n), Space: O(n)
```

---

## 5.4 Amortized Analysis of Vector Push

```
n pushes on a vector:

Individual costs:
  push 1:  cost 1  (no resize)
  push 2:  cost 2  (resize: copy 1 element, then insert)
  push 3:  cost 1  (no resize)
  push 4:  cost 3  (resize: copy 2 elements, then insert)
  push 5:  cost 1
  push 6:  cost 1
  push 7:  cost 1
  push 8:  cost 5  (resize: copy 4 elements)
  ...

Total cost for n pushes ≈ n + (1 + 2 + 4 + 8 + ... + n) ≈ 3n
Amortized cost per push = 3n / n = O(1)
```

---

## 5.5 Space Complexity

```
Stack with n elements:

Array Stack:
  Fixed array of size MAX → O(MAX) = O(N) space (even if not full)

Vector Stack:
  Dynamic array, usually holds between n and 2n → O(n)

Linked List Stack:
  n nodes × (data + pointer) = O(n)
```

---

## 5.6 Comparison with Other Data Structures

| Operation | Stack | Queue | Array | Linked List | BST |
|-----------|-------|-------|-------|-------------|-----|
| Insert (end) | O(1) | O(1) | O(1)* | O(1) | O(log n) |
| Delete (end) | O(1) | O(1) | O(1) | O(n) | O(log n) |
| Search | O(n) | O(n) | O(n) | O(n) | O(log n) |
| Random Access | O(n) | O(n) | O(1) | O(n) | O(log n) |

---
# SECTION 6: RECURSION AND STACK

---

## 6.1 How Recursion Uses the Stack

Every recursive call creates a new stack frame. The call stack is literally a stack data structure maintained by the OS/runtime.

```
Key insight: Recursion = Implicit Stack
             Iteration + Explicit Stack = Same result
```

### Example: Reverse a string using recursion

```cpp
void reverse(string& s, int left, int right) {
    if (left >= right) return;         // base case
    swap(s[left], s[right]);           // process
    reverse(s, left + 1, right - 1);  // recurse
}
```

### Call Stack for reverse("abc", 0, 2):

```
  ┌──────────────────────────────┐
  │ reverse("abc", 0, 2)         │  swap s[0],s[2] → "cba"
  ├──────────────────────────────┤
  │ reverse("cba", 1, 1)         │  left >= right → return
  └──────────────────────────────┘

Actually:
  PUSH: reverse("abc", 0, 2) → swaps → PUSH reverse("cba", 1, 1)
  POP:  reverse("cba", 1, 1) returns (base case)
  POP:  reverse("abc", 0, 2) returns
```

---

## 6.2 Recursive Tree Visualization

### Fibonacci

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

```
fib(4):
                    fib(4)
                   /      \
               fib(3)     fib(2)
              /    \      /    \
          fib(2) fib(1) fib(1) fib(0)
          /   \
       fib(1) fib(0)

Call order (DFS using stack): fib(4)→fib(3)→fib(2)→fib(1)→fib(0)→...
```

---

## 6.3 Converting Recursion to Iteration with Explicit Stack

```cpp
// Recursive DFS of a tree:
void dfs(Node* root) {
    if (!root) return;
    cout << root->val;
    dfs(root->left);
    dfs(root->right);
}

// Iterative equivalent using explicit stack:
void dfs_iterative(Node* root) {
    if (!root) return;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* node = st.top(); st.pop();
        cout << node->val;
        if (node->right) st.push(node->right);  // right first (LIFO)
        if (node->left)  st.push(node->left);   // left processed first
    }
}
```

---

## 6.4 Tail Recursion

A function is **tail recursive** if the recursive call is the LAST operation.

```cpp
// NOT tail recursive (multiplication happens after recursive call):
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n-1);   // ← multiply after return
}

// Tail recursive (accumulator pattern):
int factorial_tail(int n, int acc = 1) {
    if (n == 0) return acc;
    return factorial_tail(n-1, n * acc);  // ← nothing after recursive call
}
```

```
factorial_tail(4, 1):
  → factorial_tail(3, 4)
  → factorial_tail(2, 12)
  → factorial_tail(1, 24)
  → factorial_tail(0, 24) → returns 24

Stack frames: only ONE frame needed (compiler optimization = tail call elimination)
```

---

## 6.5 Stack Overflow Detection

```
Typical stack size: 1–8 MB (depends on OS)
Each frame size: 100 bytes (local vars + overhead)
Max recursion depth ≈ 8 MB / 100 bytes = ~80,000 frames

For n=100,000 recursive calls → STACK OVERFLOW
Solution: Convert to iterative or increase stack size
```

---

# SECTION 7: IMPORTANT STACK PATTERNS

---

## Pattern 1: Balanced Parentheses

### Identification Clues

- Problem mentions brackets: `()`, `[]`, `{}`
- Check if brackets are "valid", "matched", "balanced"
- Count open/close mismatches

### Intuition

When you see an **opening bracket**, push it.
When you see a **closing bracket**, check if it matches the top of stack.

```
"({[]})"  →  VALID
"({[}])"  →  INVALID (wrong closing order)
```

### Visualization

```
Input: ( { [ ] } )

( → push         stack: [(]
{ → push         stack: [(, {]
[ → push         stack: [(, {, []
] → top is [, matches → pop    stack: [(, {]
} → top is {, matches → pop    stack: [(]
) → top is (, matches → pop    stack: []

Stack empty at end → VALID ✓
```

### Template

```cpp
bool isBalanced(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;  // no matching open
            char top = st.top(); st.pop();
            if (c == ')' && top != '(') return false;
            if (c == '}' && top != '{') return false;
            if (c == ']' && top != '[') return false;
        }
    }
    return st.empty();  // all brackets matched
}
```

### Dry Run

```
Input: "{[()]}"

c='{': push → stack: ['{']
c='[': push → stack: ['{', '[']
c='(': push → stack: ['{', '[', '(']
c=')': top='(' matches → pop → stack: ['{', '[']
c=']': top='[' matches → pop → stack: ['{']
c='}': top='{' matches → pop → stack: []
end: stack.empty() = true → VALID ✓
```

### Common Mistakes

- Not checking if stack is empty before accessing top
- Forgetting to check `st.empty()` at the end

---

## Pattern 2: Matching Symbols

Generalization of Pattern 1. Any problem where you need to match **opening/closing** tokens.

```cpp
// Can also use a map for cleaner code:
bool isBalanced(string s) {
    stack<char> st;
    unordered_map<char, char> match = {{')', '('}, {']', '['}, {'}', '{'}};
    for (char c : s) {
        if (match.count(c)) {  // closing bracket
            if (st.empty() || st.top() != match[c]) return false;
            st.pop();
        } else {
            st.push(c);        // opening bracket
        }
    }
    return st.empty();
}
```

---

## Pattern 3: Expression Evaluation

### Identification Clues

- Evaluate arithmetic expressions
- Infix, prefix, postfix conversion
- Handle operator precedence

### Intuition

Use TWO stacks: one for operands, one for operators.

### Template (Two-Stack Infix Evaluation)

```cpp
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluate(string s) {
    stack<int> vals;
    stack<char> ops;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') continue;

        if (isdigit(s[i])) {
            int num = 0;
            while (i < s.size() && isdigit(s[i]))
                num = num * 10 + (s[i++] - '0');
            i--;
            vals.push(num);
        } else if (s[i] == '(') {
            ops.push(s[i]);
        } else if (s[i] == ')') {
            while (ops.top() != '(') {
                int b = vals.top(); vals.pop();
                int a = vals.top(); vals.pop();
                char op = ops.top(); ops.pop();
                vals.push(applyOp(a, b, op));
            }
            ops.pop();  // remove '('
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
                int b = vals.top(); vals.pop();
                int a = vals.top(); vals.pop();
                char op = ops.top(); ops.pop();
                vals.push(applyOp(a, b, op));
            }
            ops.push(s[i]);
        }
    }
    while (!ops.empty()) {
        int b = vals.top(); vals.pop();
        int a = vals.top(); vals.pop();
        char op = ops.top(); ops.pop();
        vals.push(applyOp(a, b, op));
    }
    return vals.top();
}
```

---

## Pattern 4: Monotonic Stack

### Identification Clues

- "Next greater/smaller element"
- "Previous greater/smaller element"
- Problems involving **spans**, **histograms**, **temperatures**
- Key phrase: "nearest", "closest", "first"

### Intuition

Maintain a stack where elements are in **monotonically increasing or decreasing** order.

```
Decreasing Monotonic Stack (for Next Greater Element):
  When we see a bigger element, the stack top found its "next greater"

  arr: [2, 1, 4, 3]
  
  i=0: push 2  → stack: [2]
  i=1: push 1  → stack: [2, 1]   (1 < 2, maintain decreasing)
  i=2: 4 > 1 → pop 1 (NGE of 1 is 4)
       4 > 2 → pop 2 (NGE of 2 is 4)
       push 4 → stack: [4]
  i=3: push 3  → stack: [4, 3]

  Remaining in stack have no NGE → -1
```

### Template (Next Greater Element)

```cpp
vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;  // stores indices

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

---

## Pattern 5: Next Greater Element

See Section 8 for full coverage.

---

## Pattern 6: Previous Greater Element

```cpp
vector<int> prevGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        if (!st.empty()) result[i] = arr[st.top()];
        st.push(i);
    }
    return result;
}
```

---

## Pattern 7: Next Smaller Element

```cpp
vector<int> nextSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}
```

---

## Pattern 8: Previous Smaller Element

```cpp
vector<int> prevSmaller(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if (!st.empty()) result[i] = arr[st.top()];
        st.push(i);
    }
    return result;
}
```

---

## Pattern 9: Histogram Problems

### Identification Clues

- "Largest rectangle in histogram"
- "Maximal area"
- Array of heights forming bars

### Intuition

For each bar, find how far left and right it can extend as the smallest bar.

```
Heights: [2, 1, 5, 6, 2, 3]

     6
   5 |
   | |   3
 2 | | 2 |
 | 1 | | |
 | | | | |
 ─────────
 0 1 2 3 4 5

Largest rectangle = 10 (using bars of height 5 and 6)
```

### Template

```cpp
int largestRectangle(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] > h) {
            int height = heights[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}
```

---

## Pattern 10: Span Problems

### Identification Clues

- "Stock span problem"
- "How many consecutive previous days"
- Find consecutive elements satisfying some condition

### Template

```cpp
vector<int> stockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> st;  // stores indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[st.top()] <= prices[i]) st.pop();
        span[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    return span;
}
```

---

## Pattern 11: Stack Simulation

### Identification Clues

- "Simulate" a process
- Asterisk `*` or `#` deletes previous character
- Backspace character problems

### Template

```cpp
// Backspace string compare
string processBackspace(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '#') {
            if (!st.empty()) st.pop();
        } else {
            st.push(c);
        }
    }
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
```

---

## Pattern 12: String Processing

### Identification Clues

- "Remove adjacent duplicates"
- "Decode string" (repeat a substring k times)
- "Simplify path"

### Template (Remove Adjacent Duplicates)

```cpp
string removeDuplicates(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
```

---

## Pattern 13: Undo/Redo Pattern

### Identification Clues

- "Undo last action"
- "Browser back/forward"
- "Most recent" operation needs reversal

```cpp
class TextEditor {
    stack<string> undoStack;
    stack<string> redoStack;
    string current = "";

public:
    void write(string text) {
        undoStack.push(current);
        redoStack = stack<string>(); // clear redo
        current += text;
    }

    void undo() {
        if (undoStack.empty()) return;
        redoStack.push(current);
        current = undoStack.top();
        undoStack.pop();
    }

    void redo() {
        if (redoStack.empty()) return;
        undoStack.push(current);
        current = redoStack.top();
        redoStack.pop();
    }

    string getText() { return current; }
};
```

---

## Pattern 14: Backtracking Simulation

Use a stack to simulate backtracking without actual recursion.

```cpp
// Simulate maze solving:
// Stack stores (row, col) positions
// Push neighboring unvisited cells
// Pop when backtracking

void solveMaze(vector<vector<int>>& maze, int sr, int sc, int er, int ec) {
    stack<pair<int,int>> path;
    set<pair<int,int>> visited;
    path.push({sr, sc});
    visited.insert({sr, sc});

    while (!path.empty()) {
        auto [r, c] = path.top();
        if (r == er && c == ec) {
            cout << "Found path!"; return;
        }
        // Try all 4 directions
        bool moved = false;
        for (auto [dr, dc] : vector<pair<int,int>>{{0,1},{0,-1},{1,0},{-1,0}}) {
            int nr = r + dr, nc = c + dc;
            if (/* valid */ !visited.count({nr, nc}) && maze[nr][nc] == 0) {
                path.push({nr, nc});
                visited.insert({nr, nc});
                moved = true;
                break;
            }
        }
        if (!moved) path.pop();  // backtrack
    }
}
```

---

## Pattern 15: Nested Structure Processing

### Identification Clues

- Nested brackets: `[[1,[2,3]],4]`
- Nested function calls
- Directory paths with `..`
- XML/JSON parsing

```cpp
// Decode Nested String: "3[a2[b]]" → "abbabbabb"
string decodeString(string s) {
    stack<int> counts;
    stack<string> strs;
    string current = "";
    int k = 0;

    for (char c : s) {
        if (isdigit(c)) {
            k = k * 10 + (c - '0');
        } else if (c == '[') {
            counts.push(k);
            strs.push(current);
            current = "";
            k = 0;
        } else if (c == ']') {
            int times = counts.top(); counts.pop();
            string prev = strs.top(); strs.pop();
            string rep = "";
            for (int i = 0; i < times; i++) rep += current;
            current = prev + rep;
        } else {
            current += c;
        }
    }
    return current;
}
```

---

# SECTION 8: MONOTONIC STACK MASTERY

---

## 8.1 What is a Monotonic Stack?

A **Monotonic Stack** is a stack where elements are always in **monotonically increasing** or **monotonically decreasing** order from bottom to top.

```
Monotonically Increasing Stack:
  Bottom → Top: 1, 3, 5, 7  (always increasing)

Monotonically Decreasing Stack:
  Bottom → Top: 9, 6, 4, 2  (always decreasing)
```

---

## 8.2 Increasing Monotonic Stack

### Rule

When pushing element `x`:
- While stack is NOT empty AND `stack.top() >= x`: pop
- Push `x`

```
Result: Stack bottom to top is always increasing

Use case: Next Greater Element (from right), Previous Smaller Element
```

```cpp
// Maintain increasing stack:
void maintainIncreasing(vector<int>& arr) {
    stack<int> st;
    for (int x : arr) {
        while (!st.empty() && st.top() >= x) st.pop();  // remove violators
        st.push(x);
    }
    // Stack now has elements in increasing order from bottom to top
}
```

---

## 8.3 Decreasing Monotonic Stack

### Rule

When pushing element `x`:
- While stack is NOT empty AND `stack.top() <= x`: pop
- Push `x`

```
Result: Stack bottom to top is always decreasing

Use case: Next Greater Element (from left), Stock Span
```

---

## 8.4 Next Greater Element

### Problem

For each element, find the first element to the right that is greater.

```
Input:  [2, 1, 4, 3, 6, 5]
Output: [4, 4, 6, 6,-1,-1]

Explanation:
  2 → next greater is 4
  1 → next greater is 4
  4 → next greater is 6
  3 → next greater is 6
  6 → no next greater → -1
  5 → no next greater → -1
```

### Visualization

```
arr: [2, 1, 4, 3, 6, 5]

i=0, val=2: st=[],       push 2.   stack: [2]
i=1, val=1: 1<2, push 1. stack: [2,1]
i=2, val=4: 4>1, pop 1 → NGE[1]=4
            4>2, pop 2 → NGE[2]=4
            push 4.  stack: [4]
i=3, val=3: 3<4, push 3. stack: [4,3]
i=4, val=6: 6>3, pop 3 → NGE[3]=6
            6>4, pop 4 → NGE[4]=6  (index of 4 is index 2 → NGE[2]=4, already set)
            push 6.  stack: [6]
i=5, val=5: 5<6, push 5. stack: [6,5]

Remaining: [6,5] → NGE = -1
```

### Code

```cpp
vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;  // stack of INDICES

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            nge[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return nge;
}
// Time: O(n), Space: O(n)
```

---

## 8.5 Next Greater Element II (Circular Array)

### Problem

Same as NGE but array is **circular** (after last element, wrap around to first).

```
Input:  [1, 2, 1]
Output: [2,-1, 2]

1 → next greater in circular = 2
2 → no greater even circularly = -1
1 → next greater in circular = 2 (wrap around)
```

### Trick: Iterate 2n times, use `i % n`

```cpp
vector<int> nextGreaterElementsII(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < 2 * n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i % n]) {
            result[st.top()] = nums[i % n];
            st.pop();
        }
        if (i < n) st.push(i);  // only push in first pass
    }
    return result;
}
// Time: O(n), Space: O(n)
```

---

## 8.6 Previous Greater Element

```
Input:  [4, 5, 2, 10, 8]
Output: [-1,-1,-1,-1, 10]

  4 → no previous greater → -1
  5 → no previous greater → -1
  2 → no previous greater → -1
  10 → no previous greater → -1
  8 → previous greater is 10
```

```cpp
vector<int> prevGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> pge(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        if (!st.empty()) pge[i] = arr[st.top()];
        st.push(i);
    }
    return pge;
}
```

---

## 8.7 Next Smaller Element

```
Input:  [4, 8, 5, 2, 25]
Output: [2, 5, 2,-1,-1]
```

```cpp
vector<int> nextSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            nse[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return nse;
}
```

---

## 8.8 Previous Smaller Element

```
Input:  [3, 7, 8, 4, 5]
Output: [-1,-1,-1, 3, 4]
```

```cpp
vector<int> prevSmallerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if (!st.empty()) pse[i] = arr[st.top()];
        st.push(i);
    }
    return pse;
}
```

---

## 8.9 Summary: Monotonic Stack Direction Table

| Problem | Stack Order | Condition to Pop | When to Record |
|---------|------------|------------------|----------------|
| Next Greater | Decreasing | `stack.top() < current` | On pop: NGE[top] = current |
| Prev Greater | Decreasing | `stack.top() <= current` | Before push: PGE[i] = stack.top() |
| Next Smaller | Increasing | `stack.top() > current` | On pop: NSE[top] = current |
| Prev Smaller | Increasing | `stack.top() >= current` | Before push: PSE[i] = stack.top() |

---

## 8.10 Daily Temperatures

### Problem (LeetCode 739)

Given temperatures, for each day find how many days until a warmer day.

```
Input:  [73, 74, 75, 71, 69, 72, 76, 73]
Output: [ 1,  1,  4,  2,  1,  1,  0,  0]
```

```cpp
vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> result(n, 0);
    stack<int> st;  // indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && T[st.top()] < T[i]) {
            result[st.top()] = i - st.top();  // days to wait
            st.pop();
        }
        st.push(i);
    }
    return result;
}
// Time: O(n), Space: O(n)
```

---

## 8.11 Stock Span Problem

### Problem

For each day's stock price, find the span = number of consecutive days before (including today) with price ≤ today.

```
Prices: [100, 80, 60, 70, 60, 75, 85]
Spans:  [  1,  1,  1,  2,  1,  4,  6]

Day 6 (price=85): span=6 because prices [100,80,60,70,60,75,85]
  → consecutive days with price ≤ 85 going backwards: all 6 previous + today = 6... wait:
  100 > 85, so span ends at day 0. Span = 6 days (1..6).
```

```cpp
vector<int> stockSpan(vector<int>& prices) {
    int n = prices.size();
    vector<int> span(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && prices[st.top()] <= prices[i]) st.pop();
        span[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }
    return span;
}
// Time: O(n), Space: O(n)
```

---

# SECTION 9: EXPRESSION PROBLEMS

---

## 9.1 Types of Expressions

| Type | Format | Example |
|------|--------|---------|
| **Infix** | operand op operand | `A + B * C` |
| **Prefix** | op operand operand | `+ A * B C` |
| **Postfix** | operand operand op | `A B C * +` |

---

## 9.2 Operator Precedence and Associativity

| Operator | Precedence | Associativity |
|----------|-----------|---------------|
| `(` `)` | Highest (grouping) | — |
| `^` (power) | 3 | Right to Left |
| `*` `/` `%` | 2 | Left to Right |
| `+` `-` | 1 | Left to Right |

---

## 9.3 Infix to Postfix Conversion

### Rules

1. Operands → directly to output
2. `(` → push to stack
3. `)` → pop until `(`
4. Operator → pop while top has ≥ precedence, then push

### Dry Run: `A + B * C - D`

```
Token  | Stack     | Output
-------|-----------|--------
A      | []        | A
+      | [+]       | A
B      | [+]       | A B
*      | [+, *]    | A B        (* has higher precedence than +)
C      | [+, *]    | A B C
-      | [-]       | A B C * +  (pop * then + because - <= both)
D      | [-]       | A B C * + D
END    | []        | A B C * + D -

Result: A B C * + D -
```

### Code

```cpp
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for (char c : s) {
        if (isalnum(c)) {
            result += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();  // remove '('
        } else {
            // operator: pop higher/equal precedence operators
            while (!st.empty() && st.top() != '(' &&
                   precedence(st.top()) >= precedence(c)) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}
// Time: O(n), Space: O(n)
```

---

## 9.4 Infix to Prefix Conversion

### Algorithm

1. Reverse the infix string
2. Swap `(` and `)` 
3. Apply Infix to Postfix algorithm
4. Reverse the result

### Code

```cpp
string infixToPrefix(string s) {
    // Step 1: reverse
    reverse(s.begin(), s.end());
    // Step 2: swap brackets
    for (char& c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    // Step 3: infix to postfix (but for right-associative, change >= to >)
    string postfix = infixToPostfix(s);
    // Step 4: reverse result
    reverse(postfix.begin(), postfix.end());
    return postfix;
}
```

---

## 9.5 Postfix Evaluation

### Rules

1. Operand → push to stack
2. Operator → pop two operands, apply, push result

### Dry Run: `2 3 4 * +`

```
Token | Stack    | Action
------|----------|-------
2     | [2]      | push 2
3     | [2,3]    | push 3
4     | [2,3,4]  | push 4
*     | [2,12]   | pop 4,3 → 3*4=12, push 12
+     | [14]     | pop 12,2 → 2+12=14, push 14

Result: 14
```

### Code

```cpp
int evaluatePostfix(string s) {
    stack<int> st;
    for (char c : s) {
        if (c == ' ') continue;
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int b = st.top(); st.pop();  // second operand
            int a = st.top(); st.pop();  // first operand
            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
        }
    }
    return st.top();
}
// Time: O(n), Space: O(n)
```

---

## 9.6 Prefix Evaluation

### Rules (scan right to left)

1. Operand → push
2. Operator → pop two operands, apply, push result

```cpp
int evaluatePrefix(string s) {
    stack<int> st;
    for (int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];
        if (c == ' ') continue;
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            if (c == '+') st.push(a + b);
            else if (c == '-') st.push(a - b);
            else if (c == '*') st.push(a * b);
            else if (c == '/') st.push(a / b);
        }
    }
    return st.top();
}
```

---

## 9.7 Expression Summary Table

| Conversion | Algorithm | Time | Space |
|-----------|-----------|------|-------|
| Infix → Postfix | Shunting-yard | O(n) | O(n) |
| Infix → Prefix | Reverse + I→P + Reverse | O(n) | O(n) |
| Postfix Eval | Left-to-right, 1 stack | O(n) | O(n) |
| Prefix Eval | Right-to-left, 1 stack | O(n) | O(n) |
| Infix Eval | 2-stack method | O(n) | O(n) |

---
# SECTION 10: BALANCED PARENTHESES MASTERY

---

## 10.1 Valid Parentheses (LeetCode 20)

### Problem

Given a string with `(`, `)`, `{`, `}`, `[`, `]`, determine if it's valid.

### Full Code

```cpp
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if (c == ')' && top != '(') return false;
            if (c == '}' && top != '{') return false;
            if (c == ']' && top != '[') return false;
        }
    }
    return st.empty();
}
// Time: O(n), Space: O(n)
```

### Dry Run

```
Input: "({[]})"

Step  | Char | Stack      | Action
------|------|------------|-------
1     | (    | [(]        | push
2     | {    | [(,{]      | push
3     | [    | [(,{,[]    | push
4     | ]    | [(,{]      | top=[, matches → pop
5     | }    | [(]        | top={, matches → pop
6     | )    | []         | top=(, matches → pop
END   |      | []         | empty → VALID ✓
```

### Edge Cases

```
""        → valid (empty string)
"("       → invalid (unclosed)
")("      → invalid (wrong order)
"((("     → invalid
"{[]}"    → valid
"([)]"    → invalid
```

---

## 10.2 Redundant / Duplicate Brackets

### Problem

Check if an expression has redundant brackets: `((a+b))` has redundant outer brackets.

### Intuition

If after popping until `(`, we find an operator, it's valid. If no operator found (just variables), brackets are redundant.

```cpp
bool hasRedundantBrackets(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == ')') {
            bool hasOperator = false;
            while (!st.empty() && st.top() != '(') {
                char top = st.top(); st.pop();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    hasOperator = true;
            }
            st.pop();  // remove '('
            if (!hasOperator) return true;  // redundant!
        } else {
            st.push(c);
        }
    }
    return false;
}

// "(a+b)" → no redundant
// "((a+b))" → redundant (outer brackets have no operator)
// "(a)" → redundant
```

---

## 10.3 Minimum Additions to Make Valid

### Problem (LeetCode 921)

Find minimum additions needed to make parentheses valid.

```
"())": need 1 opening → answer = 1
"(((": need 3 closing → answer = 3
"()()((": need 2 closing → answer = 2
```

```cpp
int minAddToMakeValid(string s) {
    int open = 0;   // unmatched '('
    int close = 0;  // unmatched ')'

    for (char c : s) {
        if (c == '(') {
            open++;
        } else {
            if (open > 0) open--;  // match with existing '('
            else close++;          // unmatched ')'
        }
    }
    return open + close;  // need close '(' for open, and open ')' for close
}
// Time: O(n), Space: O(1)
```

---

## 10.4 Minimum Removals to Make Valid

### Problem (LeetCode 1249)

Remove minimum brackets to make valid.

```cpp
string minRemoveToMakeValid(string s) {
    stack<int> st;  // indices of unmatched '('
    set<int> toRemove;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (!st.empty()) st.pop();  // matched
            else toRemove.insert(i);    // unmatched ')'
        }
    }
    while (!st.empty()) {
        toRemove.insert(st.top());
        st.pop();
    }

    string result = "";
    for (int i = 0; i < s.size(); i++) {
        if (!toRemove.count(i)) result += s[i];
    }
    return result;
}
// Time: O(n), Space: O(n)
```

---

## 10.5 Longest Valid Parentheses (LeetCode 32)

### Problem

Find the length of the longest valid parentheses substring.

```
"(()" → 2
")()())" → 4
"" → 0
```

### Stack Approach

Push indices. Stack always keeps the index of the last unmatched `)`.

```cpp
int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);  // base for length calculation
    int maxLen = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);  // new base
            } else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }
    return maxLen;
}
// Time: O(n), Space: O(n)
```

### Dry Run

```
Input: ")()())"

Stack starts: [-1]

i=0, ')': pop → stack empty, push 0 → stack: [0]
i=1, '(': push 1 → stack: [0, 1]
i=2, ')': pop 1 → stack: [0], maxLen = 2-0 = 2
i=3, '(': push 3 → stack: [0, 3]
i=4, ')': pop 3 → stack: [0], maxLen = max(2, 4-0) = 4
i=5, ')': pop 0 → stack empty, push 5 → stack: [5]

Result: 4 ✓
```

---

# SECTION 11: IMPORTANT STACK ALGORITHMS

---

## 11.1 Next Greater Element (Full Solution)

### Problem Statement

For each element in the array, find the first element to its right that is greater.

### Code (Complete)

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            nge[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return nge;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElement(arr);
    for (int x : result) cout << x << " ";
    // Output: 5 10 10 -1 -1
    return 0;
}
```

> **Interview Note**: Store indices in the stack, not values. This gives flexibility.

---

## 11.2 Largest Rectangle in Histogram (LeetCode 84)

### Problem Statement

Given heights of bars in a histogram, find the largest rectangle.

### Intuition

For each bar, find the **nearest smaller bar** on left and right. The bar can extend from (leftSmaller + 1) to (rightSmaller - 1).

```
heights: [2, 1, 5, 6, 2, 3]

          6
        5 |
        | |   3
      2 | | 2 |
      | 1 | | |
      | | | | |
      ─────────
      0 1 2 3 4 5

Largest rectangle = 10 (using bars 2,3 with height 5)
Width = 3-2+1=2? No: height=5, bars 2-3, width=2, area=10
Actually: height=min(5,6)=5, width=2 → area=10 ✓
```

### Algorithm

Use a monotonic stack. Pop each bar when a shorter bar is found, computing the area.

```cpp
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];

        while (!st.empty() && heights[st.top()] > h) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}
// Time: O(n), Space: O(n)
```

### Dry Run

```
heights: [2, 1, 5, 6, 2, 3]

i=0, h=2: push 0.          stack: [0]
i=1, h=1: heights[0]=2>1
  pop 0: height=2, width=1 (stack empty → width=i=1), area=2
  push 1.                  stack: [1]
i=2, h=5: push 2.          stack: [1,2]
i=3, h=6: push 3.          stack: [1,2,3]
i=4, h=2: heights[3]=6>2
  pop 3: height=6, width=4-2-1=1, area=6
  heights[2]=5>2:
  pop 2: height=5, width=4-1-1=2, area=10 ← max!
  push 4.                  stack: [1,4]
i=5, h=3: push 5.          stack: [1,4,5]
i=6, h=0 (sentinel):
  pop 5: height=3, width=6-4-1=1, area=3
  pop 4: height=2, width=6-1-1=4, area=8
  pop 1: height=1, width=6 (stack empty), area=6

maxArea = 10 ✓
```

---

## 11.3 Maximal Rectangle (LeetCode 85)

### Problem

Given a 0-1 matrix, find the largest rectangle of 1s.

### Approach

Build a histogram row by row, then apply Largest Rectangle in Histogram.

```
Matrix:
  1 0 1 0 0
  1 0 1 1 1
  1 1 1 1 1
  1 0 0 1 0

Heights (row by row):
  Row 0: [1, 0, 1, 0, 0]
  Row 1: [2, 0, 2, 1, 1]
  Row 2: [3, 1, 3, 2, 2]
  Row 3: [4, 0, 0, 3, 0]

Apply largestRectangleArea to each row's heights.
Max across all rows = 6 (row 2: [3,1,3,2,2])
```

```cpp
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            heights[c] = (matrix[r][c] == '1') ? heights[c] + 1 : 0;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}
// Time: O(rows × cols), Space: O(cols)
```

---

## 11.4 Celebrity Problem

### Problem

Among n people, find the celebrity (everyone knows them, they know nobody).

### Stack Approach

```
If A knows B → A cannot be celebrity
If A doesn't know B → B cannot be celebrity

Use stack to eliminate candidates:
1. Push all people 0..n-1
2. While stack has > 1 person: pop two, eliminate one
3. Verify the last remaining person
```

```cpp
int findCelebrity(int n) {
    stack<int> st;
    for (int i = 0; i < n; i++) st.push(i);

    while (st.size() > 1) {
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();
        if (knows(a, b)) {   // a is not celebrity
            st.push(b);
        } else {              // b is not celebrity
            st.push(a);
        }
    }

    int candidate = st.top();
    // Verify candidate
    for (int i = 0; i < n; i++) {
        if (i == candidate) continue;
        if (knows(candidate, i) || !knows(i, candidate)) return -1;
    }
    return candidate;
}
// Time: O(n), Space: O(n)
```

---

## 11.5 Asteroid Collision (LeetCode 735)

### Problem

Asteroids move right (+) or left (-). When two collide, smaller explodes. Same size both explode.

```
[5, 10, -5]  → [5, 10]    (5 moves right, -5 moves left but 10 destroys -5)
[8, -8]      → []         (equal size, both explode)
[10, 2, -5]  → [10]       (10 > 5, -5 destroyed by 10)
[-2, -1, 1, 2] → [-2,-1,1,2] (no collision: left-movers and right-movers don't meet)
```

```cpp
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int a : asteroids) {
        bool destroyed = false;
        while (!st.empty() && a < 0 && st.top() > 0) {
            if (st.top() < -a) {
                st.pop();  // stack top destroyed
                continue;
            } else if (st.top() == -a) {
                st.pop();  // both destroyed
            }
            destroyed = true;
            break;
        }
        if (!destroyed) st.push(a);
    }

    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
// Time: O(n), Space: O(n)
```

---

## 11.6 Remove K Digits (LeetCode 402)

### Problem

Remove k digits from number to make the smallest possible number.

```
"1432219", k=3 → "1219"
"10200",   k=1 → "200"
"10",      k=2 → "0"
```

### Intuition

Use a monotonic increasing stack. When we see a smaller digit, pop the larger digit (greedy).

```cpp
string removeKdigits(string num, int k) {
    stack<char> st;

    for (char c : num) {
        while (k > 0 && !st.empty() && st.top() > c) {
            st.pop();
            k--;
        }
        st.push(c);
    }

    // If k still remains, remove from end
    while (k--) st.pop();

    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());

    // Remove leading zeros
    int start = 0;
    while (start < result.size() - 1 && result[start] == '0') start++;
    return result.substr(start);
}
// Time: O(n), Space: O(n)
```

---

## 11.7 Decode String (LeetCode 394)

### Problem

`"3[a2[c]]"` → `"accaccacc"`

```cpp
string decodeString(string s) {
    stack<int> counts;
    stack<string> strs;
    string current = "";
    int k = 0;

    for (char c : s) {
        if (isdigit(c)) {
            k = k * 10 + (c - '0');
        } else if (c == '[') {
            counts.push(k);
            strs.push(current);
            current = "";
            k = 0;
        } else if (c == ']') {
            int times = counts.top(); counts.pop();
            string prev = strs.top(); strs.pop();
            for (int i = 0; i < times; i++) prev += current;
            current = prev;
        } else {
            current += c;
        }
    }
    return current;
}
```

### Dry Run

```
Input: "2[ab3[c]]"

c='2': k=2
c='[': push k=2 to counts, push ""  to strs, current="", k=0
c='a': current="a"
c='b': current="ab"
c='3': k=3
c='[': push k=3 to counts, push "ab" to strs, current="", k=0
c='c': current="c"
c=']': times=3, prev="ab", prev += "c"×3 = "ab"+"ccc" = "abccc", current="abccc"
c=']': times=2, prev="", prev += "abccc"×2 = "abcccabccc", current="abcccabccc"

Result: "abcccabccc"
```

---

## 11.8 Simplify Unix Path (LeetCode 71)

### Problem

`"/home/../usr//local/./"` → `"/usr/local"`

```cpp
string simplifyPath(string path) {
    stack<string> st;
    stringstream ss(path);
    string token;

    while (getline(ss, token, '/')) {
        if (token == "" || token == ".") {
            continue;            // ignore empty and current dir
        } else if (token == "..") {
            if (!st.empty()) st.pop();  // go up one level
        } else {
            st.push(token);
        }
    }

    string result = "";
    while (!st.empty()) {
        result = "/" + st.top() + result;
        st.pop();
    }
    return result.empty() ? "/" : result;
}
// Time: O(n), Space: O(n)
```

---

## 11.9 Min Stack (LeetCode 155)

### Problem

Design a stack that supports push, pop, top, and getMin in O(1).

### Approach 1: Two Stacks

```cpp
class MinStack {
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int val) {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top())
            minStack.push(val);
    }

    void pop() {
        if (mainStack.top() == minStack.top())
            minStack.pop();
        mainStack.pop();
    }

    int top() { return mainStack.top(); }
    int getMin() { return minStack.top(); }
};
```

### Approach 2: Store (value, currentMin) pairs

```cpp
class MinStack {
    stack<pair<int,int>> st;  // {value, minSoFar}

public:
    void push(int val) {
        int curMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, curMin});
    }

    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int getMin() { return st.top().second; }
};
```

---

# SECTION 12: SPECIAL STACKS

---

## 12.1 Min Stack (O(1) Minimum)

See 11.9 above for two approaches.

### Dry Run

```
push(5): mainStack=[5], minStack=[5]
push(3): mainStack=[5,3], minStack=[5,3]
push(7): mainStack=[5,3,7], minStack=[5,3] (7>3, don't push to minStack)
push(2): mainStack=[5,3,7,2], minStack=[5,3,2]
getMin() = minStack.top() = 2 ✓
pop():   mainStack=[5,3,7], 2==minStack.top(), so minStack.pop()=[5,3]
getMin() = 3 ✓
```

---

## 12.2 Max Stack

Same idea as Min Stack but track maximum.

```cpp
class MaxStack {
    stack<int> mainStack;
    stack<int> maxStack;

public:
    void push(int val) {
        mainStack.push(val);
        if (maxStack.empty() || val >= maxStack.top())
            maxStack.push(val);
    }

    void pop() {
        if (mainStack.top() == maxStack.top())
            maxStack.pop();
        mainStack.pop();
    }

    int top() { return mainStack.top(); }
    int getMax() { return maxStack.top(); }
};
```

---

## 12.3 Two Stacks in One Array

```
Array of size N split into two stacks:
Stack 1 grows from left (index 0)
Stack 2 grows from right (index N-1)

  [S1→][   empty   ][←S2]
  0    t1            t2  N-1

Overflow only when t1+1 == t2
```

```cpp
class TwoStacks {
    int* arr;
    int n;
    int top1, top2;

public:
    TwoStacks(int size) : n(size) {
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    void push1(int val) {
        if (top1 + 1 == top2) { cout << "Overflow\n"; return; }
        arr[++top1] = val;
    }

    void push2(int val) {
        if (top1 + 1 == top2) { cout << "Overflow\n"; return; }
        arr[--top2] = val;
    }

    int pop1() {
        if (top1 == -1) { cout << "Underflow\n"; return -1; }
        return arr[top1--];
    }

    int pop2() {
        if (top2 == n) { cout << "Underflow\n"; return -1; }
        return arr[top2++];
    }

    ~TwoStacks() { delete[] arr; }
};
```

---

## 12.4 K Stacks in One Array

### Design

Use auxiliary arrays `top[]`, `next[]`, and `free` to manage k stacks.

```
arr[]:   actual data
top[i]:  top index of stack i (-1 if empty)
next[j]: next free index after using arr[j]
free:    head of free list
```

```cpp
class KStacks {
    int* arr;    // storage
    int* top;    // top of each stack
    int* next;   // next available slot or next in free list
    int n, k;
    int freeTop; // head of free list

public:
    KStacks(int k, int n) : k(k), n(n) {
        arr = new int[n];
        top = new int[k];
        next = new int[n];

        // Initialize all stacks as empty
        fill(top, top + k, -1);

        // Initialize free list
        freeTop = 0;
        for (int i = 0; i < n - 1; i++) next[i] = i + 1;
        next[n - 1] = -1;
    }

    bool isFull() { return freeTop == -1; }
    bool isEmpty(int sn) { return top[sn] == -1; }

    void push(int val, int sn) {
        if (isFull()) { cout << "Overflow\n"; return; }
        int i = freeTop;
        freeTop = next[i];
        next[i] = top[sn];
        top[sn] = i;
        arr[i] = val;
    }

    int pop(int sn) {
        if (isEmpty(sn)) { cout << "Underflow\n"; return -1; }
        int i = top[sn];
        top[sn] = next[i];
        next[i] = freeTop;
        freeTop = i;
        return arr[i];
    }
};
```

---

## 12.5 Stack with Middle Element (O(1))

Support: push, pop, middle, deleteMiddle all in O(1).

```cpp
// Use doubly linked list + pointer to middle
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class MiddleStack {
    Node* head;  // top
    Node* mid;   // middle pointer
    int size;

    void updateMid(bool pushed) {
        if (size == 1) { mid = head; return; }
        if (pushed) {
            // Size increased: if odd, mid moves up
            if (size % 2 == 0) mid = mid->next;
        } else {
            // Size decreased: if even, mid moves down
            if (size % 2 == 1) mid = mid->prev;
        }
    }

public:
    MiddleStack() : head(nullptr), mid(nullptr), size(0) {}

    void push(int val) {
        Node* node = new Node(val);
        node->next = head;
        if (head) head->prev = node;
        head = node;
        size++;
        updateMid(true);
    }

    int pop() {
        if (!head) return -1;
        int val = head->data;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        size--;
        updateMid(false);
        delete temp;
        return val;
    }

    int getMiddle() { return mid->data; }

    int deleteMiddle() {
        if (!mid) return -1;
        int val = mid->data;
        Node* m = mid;
        if (m->prev) m->prev->next = m->next;
        if (m->next) m->next->prev = m->prev;
        if (m == head) head = m->next;
        size--;
        updateMid(false);
        delete m;
        return val;
    }
};
```

---

# SECTION 13: MONOTONIC STACK INTERVIEW FRAMEWORK

---

## 13.1 How to Identify Monotonic Stack Problems

### Decision Tree

```
Is the problem asking for:
  ├── "Next Greater Element" → Decreasing Monotonic Stack
  ├── "Previous Greater Element" → Decreasing Monotonic Stack
  ├── "Next Smaller Element" → Increasing Monotonic Stack
  ├── "Previous Smaller Element" → Increasing Monotonic Stack
  ├── "Histogram/Max Rectangle" → Monotonic Stack
  ├── "Stock Span / Days until warmer" → Monotonic Stack
  ├── "Number of visible people" → Monotonic Stack
  ├── "Remove K digits (smallest)" → Monotonic Increasing Stack
  └── "Subarray min/max sum" → Monotonic Stack
```

---

## 13.2 Complete Monotonic Stack Roadmap

### Step 1: Identify direction (next vs previous)

```
NEXT (scan left to right, answer given on pop):
  Greater: pop when current > top
  Smaller: pop when current < top

PREVIOUS (answer given before push):
  Greater: answer is stack.top() before push
  Smaller: answer is stack.top() before push
```

### Step 2: Identify comparison (greater vs smaller)

```
For NGE / NSE: record answer when you pop
For PGE / PSE: record answer when you push (top before pushing)
```

### Step 3: Choose what to store in stack

```
Most problems: store INDEX (not value)
Reason: you often need to compute widths/distances
```

### Step 4: Handle boundaries

```
- Initialize result array with -1 (for NGE problems)
- Initialize result array with 0 (for span problems)
- Add a sentinel (append 0 to heights for histogram)
```

---

## 13.3 Universal Monotonic Stack Template

```cpp
// Template for Next Greater Element (right direction)
vector<int> solve(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);  // default: no answer
    stack<int> st;               // stores indices

    for (int i = 0; i < n; i++) {
        // While current element satisfies the condition with stack top:
        while (!st.empty() && /* condition */ arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];  // record answer for popped element
            st.pop();
        }
        st.push(i);
    }
    return result;
}

// For Previous Greater Element (change when you record):
vector<int> solvePGE(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        if (!st.empty()) result[i] = arr[st.top()];  // record BEFORE pushing
        st.push(i);
    }
    return result;
}
```

---

## 13.4 Problem Pattern Table

| Problem | Direction | Condition | Record When |
|---------|-----------|-----------|-------------|
| Next Greater | L→R | `top < curr` | On pop |
| Next Smaller | L→R | `top > curr` | On pop |
| Prev Greater | L→R | `top <= curr` pop, then read | Before push |
| Prev Smaller | L→R | `top >= curr` pop, then read | Before push |
| NGE Circular | 2×L→R | `top < curr` | On pop |
| Stock Span | L→R | `top <= curr` | Before push (distance) |
| Daily Temps | L→R | `top < curr` | On pop (distance) |
| Histogram | L→R | `top > 0/curr` | On pop (area) |

---

# SECTION 14: STACK IN ARRAYS AND STRINGS

---

## 14.1 Next Greater Element in Arrays

See Section 8.4.

---

## 14.2 Daily Temperatures

See Section 8.10.

---

## 14.3 Largest Rectangle in Histogram

See Section 11.2.

---

## 14.4 Remove Adjacent Duplicates (LeetCode 1047)

### Problem

`"abbaca"` → `"ca"` (repeatedly remove adjacent duplicates)

```cpp
string removeDuplicates(string s) {
    string result = "";  // use string as stack
    for (char c : s) {
        if (!result.empty() && result.back() == c) {
            result.pop_back();
        } else {
            result.push_back(c);
        }
    }
    return result;
}
// Time: O(n), Space: O(n)
```

### Dry Run

```
Input: "abbaca"

c='a': result="a"
c='b': result="ab"
c='b': back='b'==c → pop → result="a"
c='a': back='a'==c → pop → result=""
c='c': result="c"
c='a': result="ca"

Output: "ca" ✓
```

---

## 14.5 Remove K Adjacent Duplicates (LeetCode 1209)

### Problem

`"deeedbbcccbdaa"`, k=3 → `"aa"`

Use stack of `{char, count}` pairs.

```cpp
string removeDuplicates(string s, int k) {
    stack<pair<char, int>> st;

    for (char c : s) {
        if (!st.empty() && st.top().first == c) {
            st.top().second++;
            if (st.top().second == k) st.pop();  // k consecutive → remove
        } else {
            st.push({c, 1});
        }
    }

    string result = "";
    while (!st.empty()) {
        auto [ch, cnt] = st.top(); st.pop();
        result += string(cnt, ch);
    }
    reverse(result.begin(), result.end());
    return result;
}
```

---

## 14.6 Decode String

See Section 11.7.

---

## 14.7 Remove K Digits

See Section 11.6.

---

## 14.8 Simplify Unix Path

See Section 11.8.

---

## 14.9 Score of Parentheses (LeetCode 856)

### Problem

- `()` = 1
- `(A)` = 2 * A
- `AB` = A + B

```
"(())" → 2
"()()" → 2
"(()(()))" → 6
```

```cpp
int scoreOfParentheses(string s) {
    stack<int> st;
    st.push(0);  // base score

    for (char c : s) {
        if (c == '(') {
            st.push(0);  // placeholder for current level
        } else {
            int top = st.top(); st.pop();
            int belowTop = st.top(); st.pop();
            st.push(belowTop + max(2 * top, 1));
        }
    }
    return st.top();
}
// Time: O(n), Space: O(n)
```

---

## 14.10 Sum of Subarray Minimums (LeetCode 907)

### Problem

Find sum of minimums of all subarrays.

### Key Insight

For each element `arr[i]`, count how many subarrays have `arr[i]` as the minimum.
Use Previous Smaller Element (PSE) and Next Smaller Element (NSE).

```
Count of subarrays where arr[i] is min =
  (i - PSE[i]) × (NSE[i] - i)

PSE[i] = index of previous element smaller than arr[i]
NSE[i] = index of next element smaller than arr[i]
```

```cpp
int sumSubarrayMins(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<int> st;

    // Previous smaller (strict)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        left[i] = st.empty() ? i + 1 : i - st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Next smaller or equal
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        right[i] = st.empty() ? n - i : st.top() - i;
        st.push(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + (long long)arr[i] * left[i] * right[i]) % MOD;
    }
    return ans;
}
// Time: O(n), Space: O(n)
```

---
# SECTION 15: INTERVIEW FRAMEWORK

---

## 15.1 How to Identify Stack Problems

### Decision Tree

```
Does the problem involve:
  ├── Matching/Nesting (brackets, tags, calls)
  │     └── USE STACK (push open, check on close)
  │
  ├── Reversing order / LIFO behavior
  │     └── USE STACK
  │
  ├── Undo/Redo / Previous state restoration
  │     └── USE STACK
  │
  ├── Next/Previous Greater/Smaller element
  │     └── USE MONOTONIC STACK
  │
  ├── Expression evaluation/conversion
  │     └── USE STACK (one or two)
  │
  ├── Recursion simulation
  │     └── USE STACK (explicit call stack)
  │
  ├── Histogram / Maximum rectangle
  │     └── USE MONOTONIC STACK
  │
  ├── Span problems (consecutive days)
  │     └── USE MONOTONIC STACK
  │
  ├── Path simplification (Unix path)
  │     └── USE STACK
  │
  ├── String building with deletions
  │     └── USE STACK (string as stack)
  │
  └── Nested structure decoding
        └── USE STACK (two stacks: count + string)
```

---

## 15.2 Interview Approach: 5-Step Method

### Step 1: Clarify

```
- Input format and size
- Edge cases (empty, single element, all same)
- Can we use extra space?
- Is the array sorted?
```

### Step 2: Identify the Pattern

```
- Is this a matching problem? → Balanced Parentheses pattern
- Is this "find nearest X"? → Monotonic Stack
- Is this an expression? → Expression Evaluation
- Does order matter? → Consider Stack
```

### Step 3: Choose Approach

```
Brute Force first: explain it
Better approach: mention stack
Optimal: implement stack solution
```

### Step 4: Code

```
- Handle edge cases first
- Use clear variable names (not 's', use 'stk' or 'stack')
- Comment key logic
```

### Step 5: Test

```
- Dry run with given example
- Test edge cases: empty input, single element, all same
- Verify time/space complexity
```

---

## 15.3 Common Interview Questions and Their Patterns

| Question | Pattern | Stack Type |
|----------|---------|------------|
| Valid Parentheses | Matching | Regular Stack |
| Min Stack | Design | Two Stacks |
| Daily Temperatures | Next Greater | Monotonic Dec. |
| Largest Rectangle in Histogram | Area | Monotonic |
| Decode String | Nested | Two Stacks |
| Evaluate RPN | Postfix | Regular Stack |
| Simplify Path | Path | Regular Stack |
| Asteroid Collision | Simulation | Regular Stack |
| Remove K Digits | Greedy | Monotonic Inc. |
| Next Greater Element | NGE | Monotonic Dec. |
| Stock Span | Span | Monotonic Dec. |
| Score of Parentheses | Nested | Regular Stack |

---

## 15.4 Time/Space Complexity Quick Reference

| Algorithm | Time | Space | Notes |
|-----------|------|-------|-------|
| Valid Parentheses | O(n) | O(n) | Stack depth ≤ n |
| NGE / NSE | O(n) | O(n) | Each element pushed/popped once |
| Largest Rectangle | O(n) | O(n) | Monotonic stack |
| Min Stack | O(1) each | O(n) | Extra stack for mins |
| Decode String | O(n) | O(n) | Stack size = nesting depth |
| Infix to Postfix | O(n) | O(n) | Operator stack |
| Postfix Eval | O(n) | O(n) | Operand stack |

---

# SECTION 16: COMMON TRICKS

---

## 16.1 Monotonic Stack Tricks

### Trick 1: Store Indices, Not Values

```cpp
// BAD: lose position information
stack<int> st;
st.push(arr[i]);  // only value, can't compute width

// GOOD: store index, access value via arr[idx]
stack<int> st;
st.push(i);  // store index
int val = arr[st.top()];  // retrieve value when needed
```

### Trick 2: Sentinel Values to Avoid Empty Stack Checks

```cpp
// Instead of checking st.empty() repeatedly:
// Append a sentinel to the array
arr.push_back(0);  // ensures all elements are popped
// OR initialize stack with -1
stack<int> st;
st.push(-1);  // sentinel: span[i] = i - st.top() without empty check
```

### Trick 3: Circular Array via Double Iteration

```cpp
// Process indices 0 to 2n-1 with i % n
for (int i = 0; i < 2 * n; i++) {
    // process arr[i % n]
    if (i < n) st.push(i);  // only push in first pass
}
```

### Trick 4: Use Stack to Compute Contributions

```cpp
// For "sum of subarray minimums": each element contributes
// arr[i] × (left_count) × (right_count)
// Use PSE and NSE to find these counts
```

---

## 16.2 Parentheses Tricks

### Trick 1: Count Instead of Stack (Simple Cases)

```cpp
// For only one type of bracket:
bool isValid(string s) {
    int count = 0;
    for (char c : s) {
        if (c == '(') count++;
        else if (c == ')') {
            count--;
            if (count < 0) return false;  // too many closing
        }
    }
    return count == 0;
}
```

### Trick 2: String as Stack

```cpp
// Instead of stack<char>, use string (efficient):
string result;
for (char c : s) {
    if (!result.empty() && result.back() == c) result.pop_back();
    else result.push_back(c);
}
```

### Trick 3: Two-Pass for Min Add/Remove

```cpp
// One left-to-right pass: count unmatched ')'
// One right-to-left pass: count unmatched '('
// Total = both counts
```

---

## 16.3 Expression Tricks

### Trick 1: Use ASCII for Operators

```cpp
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
```

### Trick 2: Handle Multi-digit Numbers

```cpp
if (isdigit(s[i])) {
    int num = 0;
    while (i < s.size() && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
        i++;
    }
    i--;  // adjust for loop increment
    st.push(num);
}
```

### Trick 3: Right-Associativity for Power Operator

```cpp
// For '^' (right-associative): use '>' instead of '>='
while (!ops.empty() && precedence(ops.top()) > precedence(c)) { ... }
// (for left-associative, use >=)
```

---

## 16.4 Histogram Tricks

### Trick 1: Add Sentinel Zero

```cpp
heights.push_back(0);  // forces all remaining bars to be processed
// Without sentinel, you'd need a second loop to handle remaining bars
```

### Trick 2: Row-by-row Histogram for 2D Problems

```cpp
// For maximal rectangle in matrix:
// Build cumulative height matrix row by row
for (int c = 0; c < cols; c++) {
    heights[c] = (matrix[r][c] == '1') ? heights[c] + 1 : 0;
}
```

---

## 16.5 Span Tricks

### Trick 1: Initialize Stack with -1

```cpp
stack<int> st;
st.push(-1);  // makes span[i] = i - (-1) = i+1 when stack is "empty"

for (int i = 0; i < n; i++) {
    while (st.top() != -1 && prices[st.top()] <= prices[i]) st.pop();
    span[i] = i - st.top();  // no empty check needed!
    st.push(i);
}
```

---

## 16.6 Simulation Tricks

### Trick 1: Use Stack to Reverse

```cpp
// Reverse a string using stack:
string reverse(string s) {
    stack<char> st;
    for (char c : s) st.push(c);
    string result;
    while (!st.empty()) { result += st.top(); st.pop(); }
    return result;
}
```

### Trick 2: Implement Queue Using Two Stacks

```cpp
class MyQueue {
    stack<int> in, out;

    void transfer() {
        if (out.empty()) {
            while (!in.empty()) { out.push(in.top()); in.pop(); }
        }
    }

public:
    void push(int val) { in.push(val); }
    int pop() { transfer(); int v = out.top(); out.pop(); return v; }
    int peek() { transfer(); return out.top(); }
    bool empty() { return in.empty() && out.empty(); }
};
```

---

# SECTION 17: COMMON MISTAKES

---

## 17.1 Stack Underflow

```cpp
// WRONG: accessing top of empty stack
int val = st.top();  // CRASH if st is empty!
st.pop();            // CRASH if st is empty!

// RIGHT: always check before accessing
if (!st.empty()) {
    int val = st.top();
    st.pop();
}
```

---

## 17.2 Stack Overflow (in Recursion)

```cpp
// WRONG: infinite recursion
int count(int n) {
    return 1 + count(n);  // no base case!
}

// WRONG: base case never reached
int fib(int n) {
    if (n < 0) return 0;  // for n=5, this never triggers
    return fib(n-1) + fib(n-2);  // no base case for n=0,1
}

// RIGHT:
int fib(int n) {
    if (n <= 1) return n;  // correct base case
    return fib(n-1) + fib(n-2);
}
```

---

## 17.3 Incorrect Pop Order

```cpp
// For postfix evaluation, order of operands matters!
// WRONG for subtraction/division:
int a = st.top(); st.pop();
int b = st.top(); st.pop();
result = a - b;  // WRONG: should be b - a

// RIGHT:
int b = st.top(); st.pop();  // second operand (top)
int a = st.top(); st.pop();  // first operand
result = a - b;  // a op b
```

---

## 17.4 STL stack::pop() Returns Void

```cpp
// WRONG: treating pop() as if it returns a value
int val = st.pop();  // COMPILATION ERROR!

// RIGHT:
int val = st.top();  // read first
st.pop();            // then remove
```

---

## 17.5 Off-by-One in Array Stack

```cpp
// WRONG: top starts at 0
top = 0;
arr[top++] = val;  // push: arr[0]=val, top=1
pop: return arr[top--];  // returns arr[1] → WRONG!

// RIGHT: top starts at -1
top = -1;
arr[++top] = val;  // push: top becomes 0, arr[0]=val ✓
pop: return arr[top--];  // returns arr[current_top] ✓
```

---

## 17.6 Forgetting st.empty() After Monotonic Stack

```cpp
// WRONG: accessing st.top() when stack might be empty
result[i] = arr[st.top()];  // crash if empty!

// RIGHT: always check
if (!st.empty()) result[i] = arr[st.top()];
else result[i] = -1;
```

---

## 17.7 Missing Final Stack Drain in Expression Evaluation

```cpp
// WRONG: stopping evaluation at end of string
// (operators in stack are not processed!)
return vals.top();  // may be wrong if ops stack is not empty

// RIGHT: drain the operators stack after the main loop
while (!ops.empty()) {
    int b = vals.top(); vals.pop();
    int a = vals.top(); vals.pop();
    char op = ops.top(); ops.pop();
    vals.push(applyOp(a, b, op));
}
return vals.top();
```

---

## 17.8 Monotonic Stack Direction Confusion

```
Common confusion:
  "Next Greater" → use Decreasing stack? Or Increasing?

Remember:
  For NEXT GREATER (pop when current > top):
    Stack maintained in DECREASING order
    (we pop smaller elements from top because we found their NGE)

  For NEXT SMALLER (pop when current < top):
    Stack maintained in INCREASING order
    (we pop larger elements from top because we found their NSE)
```

---

## 17.9 Memory Leak in Linked List Stack

```cpp
// WRONG: forgetting to delete nodes
void pop() {
    top = top->next;  // original node leaked!
}

// RIGHT:
void pop() {
    Node* temp = top;
    top = top->next;
    delete temp;  // free memory
}
```

---

# SECTION 18: COMPLETE STACK QUESTION LIST

---

## 18.1 Easy (50 Questions)

| # | Problem | Platform | Pattern | Key Idea |
|---|---------|----------|---------|----------|
| 1 | Valid Parentheses | LeetCode 20 | Balanced Brackets | Push open, check on close |
| 2 | Min Stack | LeetCode 155 | Design | Two stacks |
| 3 | Implement Stack using Queues | LeetCode 225 | Design | Two queues |
| 4 | Implement Queue using Stacks | LeetCode 232 | Design | Two stacks |
| 5 | Remove All Adjacent Duplicates | LeetCode 1047 | String | Stack as result |
| 6 | Backspace String Compare | LeetCode 844 | Simulation | Stack builds result |
| 7 | Baseball Game | LeetCode 682 | Simulation | Stack for scores |
| 8 | Make The String Great | LeetCode 1544 | String | Stack removes pairs |
| 9 | Next Greater Element I | LeetCode 496 | Monotonic | NGE with hash map |
| 10 | Daily Temperatures | LeetCode 739 | Monotonic | Next warmer day |
| 11 | Crawler Log Folder | LeetCode 1598 | Path | Count depth |
| 12 | Check if Word Equals Summation | LeetCode 1880 | Math | — |
| 13 | Find if Path Exists in Graph | LeetCode 1971 | DFS | Stack DFS |
| 14 | Number of Students Unable to Eat Lunch | LeetCode 1700 | Simulation | Queue/Stack |
| 15 | Maximum Nesting Depth of Parentheses | LeetCode 1614 | Brackets | Track depth |
| 16 | Count of Matches in Tournament | LeetCode 1688 | Math | — |
| 17 | Increasing Decreasing String | LeetCode 1370 | — | — |
| 18 | Reverse Linked List | LeetCode 206 | Stack/Recursion | Push then pop |
| 19 | Binary Tree Inorder Traversal | LeetCode 94 | Stack | Iterative inorder |
| 20 | Binary Tree Preorder Traversal | LeetCode 144 | Stack | Iterative preorder |
| 21 | Evaluate Reverse Polish Notation | LeetCode 150 | Postfix | Operand stack |
| 22 | Moving Average from Data Stream | LeetCode 346 | Sliding Window | — |
| 23 | Design Parking System | LeetCode 1603 | Design | — |
| 24 | Goal Parser Interpretation | LeetCode 1678 | String | — |
| 25 | Defanging an IP Address | LeetCode 1108 | String | — |
| 26 | Merge Strings Alternately | LeetCode 1768 | String | — |
| 27 | Convert Binary Number in Linked List | LeetCode 1290 | Math | — |
| 28 | Create Target Array in Given Order | LeetCode 1389 | Array | — |
| 29 | Decompress Run-Length Encoded List | LeetCode 1313 | Encoding | — |
| 30 | Sort Array by Parity | LeetCode 905 | Array | — |
| 31 | Next Greater Element II (easy version) | GFG | Monotonic | Circular NGE |
| 32 | Previous Smaller Element | GFG | Monotonic | PSE using stack |
| 33 | Stack Permutation | GFG | Stack | Verify permutation |
| 34 | Implement two stacks in an array | GFG | Design | Two ends |
| 35 | Reverse a Stack | GFG | Recursion | Stack recursion |
| 36 | Sort a Stack | GFG | Recursion | Insert in sorted order |
| 37 | Delete Middle of Stack | GFG | Recursion | Size/2 depth |
| 38 | Reverse String | LeetCode 344 | Stack | Reverse via stack |
| 39 | Palindrome Check using Stack | Basic | Stack | Push then compare |
| 40 | Check Mirror of Tree using Stack | GFG | Tree | Stack traversal |
| 41 | Convert Decimal to Binary | Basic | Stack | Push remainders |
| 42 | Balanced Expression with Replacement | GFG | Brackets | Match with wildcards |
| 43 | Expression contains redundant brackets | GFG | Expression | Stack based |
| 44 | Remove Consecutive Duplicates | GFG | String | Stack |
| 45 | Next Greater Frequency Element | GFG | Monotonic | Freq + stack |
| 46 | Get Min at Pop | GFG | Design | Track min |
| 47 | Special Stack | GFG | Design | Min in O(1) |
| 48 | Stack using Linked List | GFG | Implementation | Basic |
| 49 | Stack using Array | GFG | Implementation | Basic |
| 50 | Postfix Evaluation | GFG | Expression | Basic |

---

## 18.2 Medium (100 Questions)

| # | Problem | Platform | Pattern | Key Idea |
|---|---------|----------|---------|----------|
| 1 | Largest Rectangle in Histogram | LeetCode 84 | Monotonic | NSE on both sides |
| 2 | Decode String | LeetCode 394 | Nested | Two stacks |
| 3 | Asteroid Collision | LeetCode 735 | Simulation | Stack with conditions |
| 4 | Remove K Digits | LeetCode 402 | Monotonic | Greedy + increasing stack |
| 5 | 132 Pattern | LeetCode 456 | Monotonic | Decreasing stack |
| 6 | Next Greater Element II | LeetCode 503 | Monotonic | Circular array |
| 7 | Online Stock Span | LeetCode 901 | Span | Monotonic stack |
| 8 | Simplify Path | LeetCode 71 | Path | Stack for directories |
| 9 | Score of Parentheses | LeetCode 856 | Nested | Stack scoring |
| 10 | Minimum Remove to Make Valid | LeetCode 1249 | Brackets | Stack + index set |
| 11 | Minimum Add to Make Parentheses Valid | LeetCode 921 | Brackets | Counter |
| 12 | Longest Valid Parentheses | LeetCode 32 | Brackets | Stack of indices |
| 13 | Sum of Subarray Minimums | LeetCode 907 | Monotonic | Contribution |
| 14 | Validate Stack Sequences | LeetCode 946 | Simulation | Simulate push/pop |
| 15 | Flatten Nested List Iterator | LeetCode 341 | Nested | Stack of iterators |
| 16 | Mini Parser | LeetCode 385 | Parsing | Stack of lists |
| 17 | Exclusive Time of Functions | LeetCode 636 | Simulation | Stack of function IDs |
| 18 | Number of Visible People in Queue | LeetCode 1944 | Monotonic | Decreasing stack |
| 19 | Final Prices With Special Discount | LeetCode 1475 | NSE | Next smaller element |
| 20 | Maximum Width Ramp | LeetCode 962 | Monotonic | Dec. stack + two pointers |
| 21 | Car Fleet | LeetCode 853 | Monotonic | Sort + stack |
| 22 | Buildings With Ocean View | LeetCode 1762 | Monotonic | Right to left, dec. stack |
| 23 | Min Stack | LeetCode 155 | Design | Already listed |
| 24 | Max Stack | LeetCode 716 | Design | Two stacks |
| 25 | Dinner Plate Stacks | LeetCode 1172 | Design | Stack + heap |
| 26 | Maximum Frequency Stack | LeetCode 895 | Design | Freq map + stack |
| 27 | Design a Stack With Increment | LeetCode 1381 | Design | Lazy propagation |
| 28 | Check if There is a Path With Equal 0s 1s | LeetCode 2048 | — | — |
| 29 | Flatten a Multilevel Doubly Linked List | LeetCode 430 | Nested | Stack |
| 30 | Path Sum II | LeetCode 113 | DFS | Stack for path |
| 31 | Infix to Postfix | GFG | Expression | Shunting yard |
| 32 | Prefix to Infix | GFG | Expression | Right to left |
| 33 | Prefix to Postfix | GFG | Expression | Stack based |
| 34 | Postfix to Prefix | GFG | Expression | Stack based |
| 35 | Postfix to Infix | GFG | Expression | Stack based |
| 36 | K Stacks in Array | GFG | Design | Linked free list |
| 37 | The Celebrity Problem | GFG | Elimination | Two-pointer / stack |
| 38 | Count Reversals to Balance Brackets | GFG | Brackets | Count imbalance |
| 39 | Next Greater Element in Matrix | GFG | Monotonic | Row-wise |
| 40 | Maximum of Minimum for Every Window Size | GFG | Monotonic | PSE + NSE |
| 41 | Stock Buy Sell to Maximize Profit | GFG | Monotonic | — |
| 42 | Trapping Rain Water | LeetCode 42 | Two Pointer / Stack | Stack finds bounds |
| 43 | Removing Stars From a String | LeetCode 2390 | Simulation | Stack pop on star |
| 44 | Check if a Parentheses String Can Be Valid | LeetCode 2116 | Brackets | Two pass |
| 45 | Remove Outermost Parentheses | LeetCode 1021 | Brackets | Depth tracking |
| 46 | Reverse Substrings Between Each Pair | LeetCode 1190 | Brackets | Stack + string |
| 47 | Maximum Score From Removing Substrings | LeetCode 1717 | Greedy | Stack |
| 48 | Minimum Stack | LeetCode 155 | Design | See above |
| 49 | Kth Largest Element using Stack | Codeforces | Monotonic | — |
| 50 | Number of Subarrays with Bounded Max | LeetCode 795 | Monotonic | Stack |
| 51 | Sum of Subarray Ranges | LeetCode 2104 | Monotonic | Contribution |
| 52 | Count Subarrays Where Max Element Appears K Times | LeetCode 2962 | Sliding window | — |
| 53 | Counting Subarrays with Max Min Difference | CF | Monotonic | — |
| 54 | Number of People Aware of a Secret | LeetCode 2327 | DP/Simulation | Queue/Stack |
| 55 | Longest Subarray After Removing One Element | LeetCode 1493 | Sliding | — |
| 56 | Reveal Cards In Increasing Order | LeetCode 950 | Queue | — |
| 57 | Process Tasks Using Servers | LeetCode 1882 | Heap+Queue | — |
| 58 | Palindrome Linked List | LeetCode 234 | Stack | Push half, compare |
| 59 | Binary Tree Postorder Traversal | LeetCode 145 | Stack | Iterative |
| 60 | N-ary Tree Preorder | LeetCode 589 | Stack | Iterative |
| 61 | Binary Tree Level Order (using stack) | LeetCode 102 | BFS | (Queue usually) |
| 62 | Zigzag Level Order Traversal | LeetCode 103 | Stack | Alternate direction |
| 63 | Cartesian Tree from Preorder Traversal | LeetCode 1008 | Monotonic | Stack build |
| 64 | Minimum Cost Tree From Leaf Values | LeetCode 1130 | Monotonic | Stack |
| 65 | Remove Nodes From Linked List | LeetCode 2487 | Monotonic | NGE |
| 66 | Steps to Make Array Non-decreasing | LeetCode 2289 | Monotonic | Stack + DP |
| 67 | Count Collisions on a Road | LeetCode 2211 | Simulation | Stack |
| 68 | Number of Smooth Descent Periods | LeetCode 2110 | Monotonic | — |
| 69 | Robot Collisions | LeetCode 2751 | Simulation | Stack collision |
| 70 | Count Subarrays With Score < K | LeetCode 2302 | Sliding | — |
| 71 | Strange Printer | LeetCode 664 | DP | — |
| 72 | Different Ways to Add Parentheses | LeetCode 241 | Divide | — |
| 73 | Evaluate Reverse Polish Notation | LeetCode 150 | Postfix | See above |
| 74 | Basic Calculator II | LeetCode 227 | Expression | Stack for values |
| 75 | Basic Calculator | LeetCode 224 | Expression | Stack for values+ops |
| 76 | Decode String (k times) | LeetCode 394 | Nested | See above |
| 77 | Minimum Number of Operations (brackets) | GFG | Brackets | — |
| 78 | Implement Stack using Array | GFG | Implementation | — |
| 79 | Get Min Element from Stack | GFG | Design | — |
| 80 | Max Rectangle in Histogram | GFG | Monotonic | See above |
| 81 | Largest Rectangle Containing Only 1s | GFG | Monotonic | 2D histogram |
| 82 | Number of NGEs to the Right | GFG | Monotonic | NGE extension |
| 83 | Delete Half Nodes | GFG | Tree | — |
| 84 | Length of Longest Valid Substr | GFG | Brackets | — |
| 85 | Implement Stack with Delete Mid | GFG | Design | DLL + mid pointer |
| 86 | Minimum Cost of Ropes | GFG | Heap | — |
| 87 | Print Bracket Number | GFG | Brackets | Numbering depth |
| 88 | Circular tour | GFG | Queue | — |
| 89 | Count Pairs with Given Sum | GFG | Hashing | — |
| 90 | Smallest Element Repeated Exactly K Times | GFG | Hashing | — |
| 91 | Next Permutation | LeetCode 31 | Monotonic | Stack-like |
| 92 | Previous Permutation with One Swap | LeetCode 1053 | Monotonic | — |
| 93 | Find Maximum Sum of 2 Numbers | GFG | — | — |
| 94 | Stock Buy and Sell | LeetCode 121 | Monotonic | Min from left |
| 95 | Container With Most Water | LeetCode 11 | Two Pointer | — |
| 96 | Check if Array is Stack Sortable | GFG | Stack | Simulate 1..n |
| 97 | Stack Permutations | GFG | Stack | — |
| 98 | Design Browser History | LeetCode 1472 | Two Stack | Back/Forward |
| 99 | Constrained Subsequence Sum | LeetCode 1425 | Monotonic | Deque/Stack+DP |
| 100 | Maximum Score of Good Subarray | LeetCode 2454 | Monotonic | Two-stack |

---

## 18.3 Hard (50 Questions)

| # | Problem | Platform | Pattern | Key Idea |
|---|---------|----------|---------|----------|
| 1 | Maximal Rectangle | LeetCode 85 | 2D Histogram | Row-by-row histogram |
| 2 | Largest Rectangle in Histogram | LeetCode 84 | Monotonic | NSE both sides |
| 3 | Trapping Rain Water | LeetCode 42 | Stack/Two-ptr | Bound search |
| 4 | Basic Calculator | LeetCode 224 | Expression | Handle signs |
| 5 | Remove Duplicate Letters | LeetCode 316 | Monotonic | Greedy stack |
| 6 | Create Maximum Number | LeetCode 321 | Monotonic | Two stacks merge |
| 7 | Maximum Score From Removing Brackets | LeetCode 1717 | Greedy | Stack |
| 8 | Stamping the Sequence | LeetCode 936 | Simulation | Stack reverse |
| 9 | Minimum Cost to Merge Stones | LeetCode 1000 | DP | — |
| 10 | Number of Atoms | LeetCode 726 | Parsing | Stack of maps |
| 11 | Parse Lisp Expression | LeetCode 736 | Parsing | Stack + scope |
| 12 | Maximum Width Ramp | LeetCode 962 | Monotonic | Dec stack + 2ptr |
| 13 | Strange Printer | LeetCode 664 | DP | — |
| 14 | Maximum Frequency Stack | LeetCode 895 | Design | Freq bucket |
| 15 | Buildings With Ocean View | LeetCode 1762 | Monotonic | Dec stack R-to-L |
| 16 | Sum of Subarray Minimums | LeetCode 907 | Monotonic | Contribution count |
| 17 | Sum of Subarray Ranges | LeetCode 2104 | Monotonic | Max-Min via stacks |
| 18 | Count Subarrays With Fixed Bounds | LeetCode 2444 | Monotonic | — |
| 19 | Steps to Make Array Non-decreasing | LeetCode 2289 | Monotonic+DP | — |
| 20 | Minimum Number of Removals | LeetCode 2126 | DP | — |
| 21 | Largest Rectangle III | Codeforces | Monotonic | — |
| 22 | Max Points on Stack | CF 1837D | — | — |
| 23 | Robot Collisions | LeetCode 2751 | Simulation | Stack |
| 24 | K-th Smallest Lexicographically | LeetCode 440 | Trie-like | — |
| 25 | Score After Flipping Matrix | LeetCode 861 | Greedy | — |
| 26 | Minimum Cost of Ropes | GFG/CSES | Heap | — |
| 27 | Maximal Score After Applying K Operations | LeetCode 2530 | Heap | — |
| 28 | Dinner Plate Stacks | LeetCode 1172 | Design | — |
| 29 | Design a Food Rating System | LeetCode 2353 | Design+Heap | — |
| 30 | Largest Component Size by Common Factor | LeetCode 952 | Union Find | — |
| 31 | Constrained Subsequence Sum | LeetCode 1425 | Monotonic+DP | Deque |
| 32 | Sliding Window Maximum | LeetCode 239 | Monotonic | Deque (Dec.) |
| 33 | Jump Game VI | LeetCode 1696 | Monotonic+DP | Deque |
| 34 | Jump Game VII | LeetCode 1871 | — | — |
| 35 | Minimum Add to Make Parentheses Valid II | CF | Brackets | — |
| 36 | Expression Evaluation with Functions | ICPC | Expression | Multiple stacks |
| 37 | Sequence of Moves | Codeforces | Stack sim | — |
| 38 | Maximum Rectangle in Binary Matrix | GFG | 2D Histogram | — |
| 39 | Minimum Cost to Cut a Stick | LeetCode 1547 | DP | — |
| 40 | Count All Subarrays Min Equal k | CF | Monotonic | — |
| 41 | Minimum Cost Tree From Leaf Values | LeetCode 1130 | Monotonic | Stack build |
| 42 | Stone Game VI | LeetCode 1686 | Greedy | — |
| 43 | Maximum XOR With an Element From Array | LeetCode 1707 | Trie | — |
| 44 | Decode Permutation | CF | Stack+BFS | — |
| 45 | Valid Stack Sequences II | CF | Stack | — |
| 46 | K-th Permutation | LeetCode 60 | Math | — |
| 47 | Smallest Subsequence of Distinct Char | LeetCode 1081 | Monotonic | Stack + freq |
| 48 | Count Subarrays where Max > K | CF | Monotonic | — |
| 49 | Number of Submatrices That Sum to Target | LeetCode 1074 | Prefix Sum | Histogram |
| 50 | Max Sum of Rectangle No Larger Than K | LeetCode 363 | BST+Stack | 2D prefix |

---

# SECTION 19: REVISION CHEAT SHEET

---

## 19.1 Stack Operations Cheat Sheet

```
OPERATION    | ARRAY STACK      | VECTOR STACK     | STL STACK
-------------|------------------|------------------|------------------
Push         | arr[++top]=val   | v.push_back(val) | st.push(val)
Pop          | return arr[top--]| v.pop_back()     | st.pop() [void!]
Top/Peek     | arr[top]         | v.back()         | st.top()
Size         | top + 1          | v.size()         | st.size()
Empty        | top == -1        | v.empty()        | st.empty()
Clear        | top = -1         | v.clear()        | while(!st.empty()) st.pop()
```

---

## 19.2 Complexity Cheat Sheet

```
ALL stack operations (push, pop, top, size, empty): O(1)
Search: O(n)
Space: O(n)

Monotonic Stack algorithms: O(n) time, O(n) space
  (each element pushed and popped exactly once)
```

---

## 19.3 Monotonic Stack Templates

```cpp
// ═══════════════════════════════════════
// NEXT GREATER ELEMENT (right, decreasing stack)
// ═══════════════════════════════════════
vector<int> nge(n, -1);
stack<int> st; // indices
for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] < arr[i]) {
        nge[st.top()] = arr[i]; st.pop();
    }
    st.push(i);
}

// ═══════════════════════════════════════
// NEXT SMALLER ELEMENT (right, increasing stack)
// ═══════════════════════════════════════
vector<int> nse(n, -1);
stack<int> st;
for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] > arr[i]) {
        nse[st.top()] = arr[i]; st.pop();
    }
    st.push(i);
}

// ═══════════════════════════════════════
// PREVIOUS GREATER ELEMENT
// ═══════════════════════════════════════
vector<int> pge(n, -1);
stack<int> st;
for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
    if (!st.empty()) pge[i] = arr[st.top()];
    st.push(i);
}

// ═══════════════════════════════════════
// PREVIOUS SMALLER ELEMENT
// ═══════════════════════════════════════
vector<int> pse(n, -1);
stack<int> st;
for (int i = 0; i < n; i++) {
    while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
    if (!st.empty()) pse[i] = arr[st.top()];
    st.push(i);
}
```

---

## 19.4 Parentheses Template

```cpp
// ═══════════════════════════════════════
// VALID PARENTHESES
// ═══════════════════════════════════════
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c=='(' || c=='{' || c=='[') { st.push(c); continue; }
        if (st.empty()) return false;
        char t = st.top(); st.pop();
        if (c==')' && t!='(') return false;
        if (c=='}' && t!='{') return false;
        if (c==']' && t!='[') return false;
    }
    return st.empty();
}

// ═══════════════════════════════════════
// MINIMUM ADDITIONS
// ═══════════════════════════════════════
int minAdd(string s) {
    int open = 0, close = 0;
    for (char c : s) {
        if (c == '(') open++;
        else { if (open > 0) open--; else close++; }
    }
    return open + close;
}

// ═══════════════════════════════════════
// LONGEST VALID PARENTHESES
// ═══════════════════════════════════════
int longest(string s) {
    stack<int> st; st.push(-1);
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') { st.push(i); }
        else {
            st.pop();
            if (st.empty()) st.push(i);
            else maxLen = max(maxLen, i - st.top());
        }
    }
    return maxLen;
}
```

---

## 19.5 Expression Evaluation Template

```cpp
// ═══════════════════════════════════════
// INFIX TO POSTFIX
// ═══════════════════════════════════════
int prec(char c) {
    if (c=='^') return 3;
    if (c=='*'||c=='/') return 2;
    if (c=='+'||c=='-') return 1;
    return 0;
}
string toPostfix(string s) {
    stack<char> ops; string res;
    for (char c : s) {
        if (isalnum(c)) { res += c; }
        else if (c == '(') { ops.push(c); }
        else if (c == ')') {
            while (ops.top() != '(') { res += ops.top(); ops.pop(); }
            ops.pop();
        } else {
            while (!ops.empty() && prec(ops.top()) >= prec(c)) {
                res += ops.top(); ops.pop();
            }
            ops.push(c);
        }
    }
    while (!ops.empty()) { res += ops.top(); ops.pop(); }
    return res;
}

// ═══════════════════════════════════════
// POSTFIX EVALUATION
// ═══════════════════════════════════════
int evalPostfix(string s) {
    stack<int> st;
    for (char c : s) {
        if (isdigit(c)) { st.push(c - '0'); }
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (c=='+') st.push(a+b);
            if (c=='-') st.push(a-b);
            if (c=='*') st.push(a*b);
            if (c=='/') st.push(a/b);
        }
    }
    return st.top();
}
```

---

## 19.6 Min Stack Template

```cpp
class MinStack {
    stack<pair<int,int>> st; // {val, min_so_far}
public:
    void push(int val) {
        int m = st.empty() ? val : min(val, st.top().second);
        st.push({val, m});
    }
    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int getMin() { return st.top().second; }
};
```

---

## 19.7 Next Greater Element Template (with HashMap for 2 arrays)

```cpp
// LC 496: NGE for arr1 elements searching in arr2
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> ngeMap;
    stack<int> st;

    for (int x : nums2) {
        while (!st.empty() && st.top() < x) {
            ngeMap[st.top()] = x;
            st.pop();
        }
        st.push(x);
    }
    // Remaining have no NGE → not in map → -1

    vector<int> result;
    for (int x : nums1) {
        result.push_back(ngeMap.count(x) ? ngeMap[x] : -1);
    }
    return result;
}
```

---

## 19.8 Histogram Template

```cpp
int largestRect(vector<int> h) {
    h.push_back(0);  // sentinel
    stack<int> st;
    int maxArea = 0, n = h.size();
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] > h[i]) {
            int height = h[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}
```

---

# SECTION 20: FINAL STACK ROADMAP

---

## 20.1 Beginner → Intermediate → Advanced

```
╔══════════════════════════════════════════════════════════════╗
║                    STACK LEARNING PATH                       ║
╠══════════════════════════════════════════════════════════════╣
║  BEGINNER (Week 1-2)                                         ║
║  ─────────────────────────────────────────────────          ║
║  ✓ What is a Stack, LIFO principle                          ║
║  ✓ Array, Vector, LinkedList, STL implementation            ║
║  ✓ Push, Pop, Top, Size, Empty operations                   ║
║  ✓ Valid Parentheses (LC 20)                                ║
║  ✓ Min Stack (LC 155)                                       ║
║  ✓ Implement Queue using Stacks (LC 232)                    ║
║  ✓ Postfix Evaluation                                       ║
║  ✓ Reverse a String using Stack                             ║
╠══════════════════════════════════════════════════════════════╣
║  INTERMEDIATE (Week 3-4)                                     ║
║  ─────────────────────────────────────────────────          ║
║  ✓ Infix to Postfix/Prefix conversion                      ║
║  ✓ Next Greater Element (all 4 variants)                    ║
║  ✓ Daily Temperatures (LC 739)                              ║
║  ✓ Stock Span Problem                                       ║
║  ✓ Largest Rectangle in Histogram (LC 84)                   ║
║  ✓ Longest Valid Parentheses (LC 32)                        ║
║  ✓ Decode String (LC 394)                                   ║
║  ✓ Simplify Path (LC 71)                                    ║
║  ✓ Remove K Digits (LC 402)                                 ║
╠══════════════════════════════════════════════════════════════╣
║  ADVANCED (Week 5-6)                                         ║
║  ─────────────────────────────────────────────────          ║
║  ✓ Maximal Rectangle (LC 85)                                ║
║  ✓ Trapping Rain Water (LC 42)                              ║
║  ✓ Basic Calculator I & II (LC 224, 227)                    ║
║  ✓ Sum of Subarray Minimums (LC 907)                        ║
║  ✓ Maximum Frequency Stack (LC 895)                         ║
║  ✓ Robot Collisions (LC 2751)                               ║
║  ✓ Sum of Subarray Ranges (LC 2104)                         ║
║  ✓ Steps to Make Array Non-decreasing (LC 2289)             ║
║  ✓ Number of Visible People in Queue (LC 1944)              ║
╚══════════════════════════════════════════════════════════════╝
```

---

## 20.2 Weekly Learning Plan

### Week 1: Foundations

| Day | Topic | Problems |
|-----|-------|----------|
| Mon | What is Stack, LIFO, Applications | Read only |
| Tue | Array + Vector Implementation | Implement from scratch |
| Wed | LinkedList + STL Stack | Implement from scratch |
| Thu | Operations: Push, Pop, Top, Size, Empty | LC 155 (Min Stack) |
| Fri | Memory Model, Function Call Stack | LC 20 (Valid Parentheses) |
| Sat | Complexity Analysis | LC 232 (Queue using 2 Stacks) |
| Sun | Revision + Review Week 1 | LC 225 (Stack using Queues) |

### Week 2: Classic Stack Problems

| Day | Topic | Problems |
|-----|-------|----------|
| Mon | Balanced Parentheses Patterns | LC 20, LC 921, LC 1249 |
| Tue | Expression: Postfix Evaluation | GFG Postfix Eval |
| Wed | Expression: Infix to Postfix | GFG Infix→Postfix |
| Thu | String Processing with Stack | LC 1047, LC 844 |
| Fri | Stack Simulation | LC 682, LC 735 |
| Sat | Recursion and Stack | Convert recursion to iteration |
| Sun | Revision + Practice | LC 32 (Longest Valid Parens) |

### Week 3: Monotonic Stack Basics

| Day | Topic | Problems |
|-----|-------|----------|
| Mon | What is Monotonic Stack, Intuition | Read + visualize |
| Tue | Next Greater Element | LC 496, GFG NGE |
| Wed | Previous Greater Element | GFG PGE |
| Thu | Next/Previous Smaller Element | GFG NSE, PSE |
| Fri | Daily Temperatures | LC 739 |
| Sat | Stock Span Problem | LC 901, GFG |
| Sun | NGE II (Circular) | LC 503 |

### Week 4: Monotonic Stack Advanced

| Day | Topic | Problems |
|-----|-------|----------|
| Mon | Largest Rectangle in Histogram | LC 84 |
| Tue | Maximal Rectangle | LC 85 |
| Wed | Remove K Digits | LC 402 |
| Thu | Sum of Subarray Minimums | LC 907 |
| Fri | 132 Pattern | LC 456 |
| Sat | Buildings With Ocean View | LC 1762 |
| Sun | Revision: All monotonic patterns | Mixed practice |

### Week 5: Special Design + Advanced

| Day | Topic | Problems |
|-----|-------|----------|
| Mon | Min Stack, Max Stack | LC 155, LC 716 |
| Tue | Two Stacks in Array, K Stacks | GFG Design |
| Wed | Trapping Rain Water | LC 42 |
| Thu | Basic Calculator I + II | LC 224, LC 227 |
| Fri | Decode String + Nested Structures | LC 394 |
| Sat | Maximum Frequency Stack | LC 895 |
| Sun | Contest Problems | Codeforces Div 2 |

### Week 6: Interview Preparation

| Day | Topic | Problems |
|-----|-------|----------|
| Mon | Mock Interview: Easy Stacks | 3 easy problems |
| Tue | Mock Interview: Medium Stacks | 3 medium problems |
| Wed | Mock Interview: Monotonic Stack | 3 monotonic problems |
| Thu | Mock Interview: Design | Design questions |
| Fri | Mixed Practice | Random stack problems |
| Sat | Timed Contest Simulation | 4 problems in 90 min |
| Sun | Final Revision: Cheat Sheet | Review all templates |

---

## 20.3 Quick Problem Identification Guide

```
CLUE IN PROBLEM               → PATTERN
─────────────────────────────────────────────────
"valid/balanced brackets"     → Balanced Parentheses
"next greater element"        → Monotonic Stack (Dec.)
"previous smaller element"    → Monotonic Stack (Inc.)
"span of stock"               → Monotonic Stack (Dec.)
"temperature/days until"      → Monotonic Stack (Dec.)
"rectangle in histogram"      → Monotonic Stack + Area
"decode encoded string"       → Two Stacks (cnt + str)
"evaluate expression"         → One or Two Stacks
"simplify path"               → Stack (directory)
"remove k digits / smallest"  → Monotonic Stack (Inc.)
"undo/redo"                   → Two Stacks
"minimum element O(1)"        → Two Stacks (Min Stack)
"adjacent duplicates"         → Stack (match on top)
"asteroid collision"          → Stack with logic
"backspace/delete"            → Stack (pop on '#')
```

---

## 20.4 Last-Minute Interview Revision (30 Minutes)

```
5 MINUTES:
  □ LIFO principle, push/pop/top/empty/size all O(1)
  □ STL: st.push(x), st.pop() [void!], st.top(), st.empty()

10 MINUTES:
  □ Valid Parentheses: push open, check close, empty at end
  □ Min Stack: pair<val, min_so_far> on each push
  □ Postfix Eval: push numbers, pop 2 on operator

10 MINUTES:
  □ NGE: decreasing stack, record on pop
  □ NSE: increasing stack, record on pop
  □ Histogram: monotonic stack + sentinel 0

5 MINUTES:
  □ Common mistakes: pop() returns void in STL!
  □ Always check empty() before top()/pop()
  □ Store indices not values in monotonic stack
```

---

## 20.5 Recommended Practice Order

### Must-Do (30 problems that cover 90% of interview patterns)

```
EASY:
  1. LC 20 - Valid Parentheses
  2. LC 155 - Min Stack
  3. LC 232 - Implement Queue using Stacks
  4. LC 1047 - Remove All Adjacent Duplicates in String
  5. LC 844 - Backspace String Compare

MEDIUM:
  6. LC 739 - Daily Temperatures
  7. LC 496 - Next Greater Element I
  8. LC 503 - Next Greater Element II
  9. LC 901 - Online Stock Span
  10. LC 84 - Largest Rectangle in Histogram
  11. LC 394 - Decode String
  12. LC 71 - Simplify Path
  13. LC 402 - Remove K Digits
  14. LC 735 - Asteroid Collision
  15. LC 32 - Longest Valid Parentheses
  16. LC 150 - Evaluate Reverse Polish Notation
  17. LC 921 - Min Add to Make Parentheses Valid
  18. LC 1249 - Minimum Remove to Make Valid
  19. LC 907 - Sum of Subarray Minimums
  20. LC 456 - 132 Pattern
  21. LC 856 - Score of Parentheses
  22. LC 946 - Validate Stack Sequences
  23. LC 1762 - Buildings With Ocean View
  24. LC 227 - Basic Calculator II
  25. LC 1475 - Final Prices With Special Discount

HARD:
  26. LC 85 - Maximal Rectangle
  27. LC 42 - Trapping Rain Water
  28. LC 224 - Basic Calculator
  29. LC 316 - Remove Duplicate Letters
  30. LC 895 - Maximum Frequency Stack
```

---

> ## 🎯 Final Words
>
> Stacks appear in ~30% of all coding interview problems, either directly or as part of a larger solution. Master the fundamentals (Section 1-5), then focus heavily on Monotonic Stack (Sections 7-8, 13) as it's the most commonly tested advanced pattern. Practice the 30 must-do problems above and you'll be well-prepared for any interview.
>
> **Remember:**
> - Every element enters and leaves the stack exactly once in O(n) algorithms
> - When stuck, ask: "What information do I need from elements I've already seen?"
> - The answer to that question often leads to a stack solution
>
> Good luck! 🚀

---
