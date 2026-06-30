# The Ultimate Queue Handbook

### From First Principles to Advanced Patterns — Beginner to Interview-Ready

> A complete, self-contained reference for learning, revising, and mastering **Queues** — built for beginners, placement preparation, online assessments, competitive programming, and technical interviews.

---

## How to Use This Handbook

- **First-time learners**: Read Sections 1 → 6 in order. Don't skip the dry runs.
- **Placement / OA prep**: Focus on Sections 7, 8, 10, 14, 17.
- **Interview revision (1 night before)**: Jump straight to Section 18 (Cheat Sheets) and Section 13 (Interview Framework).
- **Competitive programmers**: Sections 8, 9, 10, 15 contain the templates you'll reuse the most.

All code is written in **C++** (using STL where relevant) because that is the dominant language in interviews and competitive programming. The logic translates directly to Java, Python, or JavaScript.

---

## Table of Contents

1. [Queue Fundamentals](#section-1-queue-fundamentals)
2. [Queue Implementation](#section-2-queue-implementation)
3. [Queue Operations](#section-3-queue-operations)
4. [Circular Queue Mastery](#section-4-circular-queue-mastery)
5. [Deque (Double Ended Queue)](#section-5-deque-double-ended-queue)
6. [Complexity Analysis](#section-6-complexity-analysis)
7. [Important Queue Patterns](#section-7-important-queue-patterns)
8. [Deque & Monotonic Queue Mastery](#section-8-deque--monotonic-queue-mastery)
9. [Priority Queue Mastery](#section-9-priority-queue-mastery)
10. [Important Queue Algorithms](#section-10-important-queue-algorithms)
11. [Special Queues](#section-11-special-queues)
12. [Queue Applications](#section-12-queue-applications)
13. [Interview Framework](#section-13-interview-framework)
14. [Queue in Arrays & Strings](#section-14-queue-in-arrays--strings)
15. [Common Tricks](#section-15-common-tricks)
16. [Common Mistakes](#section-16-common-mistakes)
17. [Complete Queue Question List](#section-17-complete-queue-question-list)
18. [Revision Cheat Sheet](#section-18-revision-cheat-sheet)
19. [Final Queue Roadmap](#section-19-final-queue-roadmap)

---

# SECTION 1: QUEUE FUNDAMENTALS

## 1.1 What is a Queue?

### Definition

A **Queue** is a linear data structure that stores elements in a particular order and allows insertion only at one end (called the **Rear**/**Back**) and removal only from the other end (called the **Front**). It strictly follows the **FIFO (First In, First Out)** principle — the element that is inserted first is the one removed first.

### Intuition

Think of a real-world queue (line) at a ticket counter. The person who joins the line first is served first. New people join at the back of the line; nobody is served by jumping the line from the middle. A Queue data structure mimics this exact behavior in memory.

### Visual Explanation

```text
Insertion (Enqueue) happens here ----v
                                   [Rear]
Front -> [10] [20] [30] [40] <- Rear
  ^
Removal (Dequeue) happens here

Order of removal: 10, 20, 30, 40  (same order as insertion)
```

```text
Step 1: enqueue(10)        Front->[10]<-Rear
Step 2: enqueue(20)        Front->[10][20]<-Rear
Step 3: enqueue(30)        Front->[10][20][30]<-Rear
Step 4: dequeue()  -> 10   Front->[20][30]<-Rear
Step 5: enqueue(40)        Front->[20][30][40]<-Rear
```

## 1.2 Why Queues Exist

Arrays and plain lists let you access any index freely, but many real systems need a structure that enforces **order of processing** — the order things arrive must be the order they are handled. Examples: print jobs, customer support tickets, CPU task scheduling, message brokers. A Queue enforces this ordering as a structural guarantee instead of something a programmer has to remember to implement correctly each time.

## 1.3 FIFO Principle (First In, First Out)

| Action | Effect |
|---|---|
| Enqueue (Insert) | Always adds to the Rear |
| Dequeue (Remove) | Always removes from the Front |
| Order Guarantee | Elements leave in the exact order they entered |

FIFO is the single defining property of a queue. If insertion and removal both happen from the same end, it is **not** a queue — it becomes a Stack (LIFO).

## 1.4 Queue Terminology

| Term | Meaning |
|---|---|
| Front | Pointer/index to the first (oldest) element — next to be removed |
| Rear / Back | Pointer/index to the last (newest) element — last inserted |
| Enqueue | Operation to insert an element at the Rear |
| Dequeue | Operation to remove an element from the Front |
| Overflow | Attempting to enqueue into a full queue |
| Underflow | Attempting to dequeue from an empty queue |
| Size | Number of elements currently in the queue |
| Capacity | Maximum number of elements the queue can hold (for fixed-size implementations) |

## 1.5 Real World Applications

| Application | How Queue is Used |
|---|---|
| CPU Scheduling | Processes wait in a ready queue to get CPU time |
| Printer Spooling | Print jobs are processed in the order they were submitted |
| Call Center Systems | Callers are answered in the order they called |
| Keyboard Buffer | Keystrokes are processed in the order typed |
| BFS Traversal | Level-order exploration uses a queue to track the next nodes |
| Message Queues (Kafka, RabbitMQ) | Producers push, consumers pop, in order |
| Order Processing Systems | E-commerce orders are fulfilled in arrival order |
| Network Packet Buffering | Routers buffer and forward packets in arrival order |
| Ticket Booking Systems | "First come first serve" booking |

## 1.6 Queue vs Stack

| Aspect | Queue | Stack |
|---|---|---|
| Principle | FIFO (First In First Out) | LIFO (Last In First Out) |
| Insertion | Rear | Top |
| Removal | Front | Top |
| Real World Analogy | Line at a ticket counter | Stack of plates |
| Use Case | BFS, scheduling, buffering | DFS, undo operations, recursion (call stack) |
| Number of active ends | Two (front & rear) | One (top) |

```text
QUEUE (FIFO)                    STACK (LIFO)
Front->[10][20][30]<-Rear         [30] <- Top (push/pop here)
  remove from front                [20]
                                   [10]
```

## 1.7 Queue vs Array

| Aspect | Queue (ADT) | Array |
|---|---|---|
| Access | Only front/rear accessible | Random access via index |
| Purpose | Enforces order of processing | General-purpose storage |
| Underlying Storage | Can be implemented USING an array | Is the raw storage itself |
| Operations Allowed | enqueue, dequeue, front, rear, size, empty | get, set, insert at index, delete at index, etc. |

A Queue is an **Abstract Data Type (ADT)** — a contract of allowed operations. An array is one possible way to *implement* that contract (see Section 2).

## 1.8 Queue vs Linked List

| Aspect | Queue (ADT) | Linked List |
|---|---|---|
| Nature | Behavioral contract (FIFO) | Concrete data structure |
| Access | Only two ends matter | Can traverse and access any node (with O(n) walk) |
| Relationship | Can be implemented USING a linked list | Is the underlying storage mechanism |
| Resizing | Logical concept — doesn't "resize" itself | Naturally dynamic, grows/shrinks node by node |

## 1.9 Advantages of Queue

- Maintains strict insertion order — predictable, fair processing.
- O(1) enqueue and dequeue when implemented correctly (circular array or linked list).
- Models real-world FIFO systems directly and intuitively.
- Forms the backbone of BFS, scheduling, and buffering algorithms.

## 1.10 Disadvantages of Queue

- No random access — you cannot access the 5th element directly without dequeuing the first four (in a pure queue ADT).
- A naive array-based queue wastes space or requires costly shifting (see Section 2).
- Searching is O(n) since only front/rear are exposed by the ADT.
- Fixed-size array queues can suffer from overflow even when "logical" space is free (solved by circular queues).

## 1.11 Applications Summary

```text
                 ┌────────────────────────┐
                 │        QUEUE            │
                 └────────────────────────┘
                            │
      ┌─────────────┬───────────────┬──────────────┐
      ▼              ▼               ▼              ▼
 CPU Scheduling  BFS Traversal   Buffering     Order Processing
 (ready queue)   (graph/tree     (printers,    (e-commerce,
                  level order)    keyboards)    ticketing)
```

## 1.12 Edge Cases to Always Consider (Conceptual)

- Empty queue: dequeue/front/rear should never be called blindly — always check `isEmpty()` first.
- Full queue (fixed-size): enqueue must check `isFull()` to avoid overflow.
- Single-element queue: front == rear; dequeuing it must correctly reset both pointers.
- Queue holding duplicate values: operations must work on **position**, not value identity.

## 1.13 Common Mistakes (Conceptual Level)

- Confusing Queue (FIFO) with Stack (LIFO) when picking a data structure for a problem.
- Forgetting to check `isEmpty()` before `front()`/`dequeue()`, causing undefined behavior or crashes.
- Assuming a plain array-based queue is O(1) for dequeue (it's O(n) unless circular or using a moving front pointer — see Section 2).

## 1.14 Interview Notes

- Interviewers love asking "Implement a Queue using two Stacks" and "Implement a Stack using two Queues" — both covered in Section 10.
- Always state the **time and space complexity** of each operation before coding.
- If asked "Why not just use an array?" — the answer is: a queue *restricts* operations to enforce order safely; that restriction is the value, not a limitation.

## 1.15 Practice Questions (Conceptual)

1. Explain FIFO with a real-world example other than a ticket line.
2. Why does dequeuing from the front of a plain array take O(n) time?
3. Give three real systems that internally rely on a queue.
4. Why is a Queue called an Abstract Data Type rather than a concrete structure?

---

# SECTION 2: QUEUE IMPLEMENTATION

## 2.1 Queue Using Array (Linear / Naive)

### Definition

The simplest queue implementation: use a fixed-size array, an integer `front`, and an integer `rear`. Enqueue increments `rear` and places the element there. Dequeue removes from `front`.

### Intuition

You are simply marking two positions in a static array and moving them forward as elements come and go.

### Visual Explanation

```text
Index:   0    1    2    3    4
Array: [10] [20] [30] [ ] [ ]
        ^front      ^rear

After dequeue():
Index:   0    1    2    3    4
Array: [ ] [20] [30] [ ] [ ]
             ^front    ^rear
```

### The Core Problem: Wasted Space

```text
After repeated enqueue/dequeue, front keeps moving right.
Even though slots 0 and 1 are logically free, you cannot
reuse them — rear eventually hits array capacity and reports
"overflow" even though the queue isn't actually full.

[ ] [ ] [ ] [40] [50]
              ^front     rear -> out of bounds! FALSE OVERFLOW
```

This is exactly why the **Circular Queue** (Section 4) exists.

### Brute Force Approach (Naive Array, Shift on Dequeue)

Shift every element left by one position on every dequeue. Simple, but wasteful.

```cpp
class QueueNaive {
    int arr[100], size = 0;
public:
    void enqueue(int x) {
        if (size == 100) { cout << "Overflow\n"; return; }
        arr[size++] = x;
    }
    void dequeue() {
        if (size == 0) { cout << "Underflow\n"; return; }
        for (int i = 0; i < size - 1; i++) arr[i] = arr[i+1]; // O(n) shift
        size--;
    }
};
```

**Time Complexity:** Enqueue O(1), Dequeue O(n) due to shifting.
**Space Complexity:** O(n) for the array.

### Better Approach (Two Pointers, No Shifting)

Keep a `front` index that simply moves forward instead of shifting the whole array.

```cpp
class QueueArray {
    int arr[100];
    int front = 0, rear = -1, size = 0;
public:
    bool isEmpty() { return size == 0; }
    bool isFull()  { return size == 100; }

    void enqueue(int x) {
        if (isFull()) { cout << "Overflow\n"; return; }
        rear++;
        arr[rear] = x;
        size++;
    }
    void dequeue() {
        if (isEmpty()) { cout << "Underflow\n"; return; }
        front++;
        size--;
    }
    int getFront() { return arr[front]; }
};
```

**Time Complexity:** Enqueue O(1), Dequeue O(1) — no shifting needed.
**Space Complexity:** O(n).
**Limitation:** Still suffers the "false overflow" problem above — front-side space is never reclaimed.

### Optimal Approach

Use a **Circular Array** (Section 2.2 / Section 4) so freed front-side slots are reused, or use a **Linked List** (Section 2.3) for unbounded dynamic sizing, or simply use **`std::queue`** from STL (Section 2.4) in real code.

### Dry Run (Two-Pointer Array Queue)

```text
enqueue(10): front=0 rear=0 size=1   [10]
enqueue(20): front=0 rear=1 size=2   [10,20]
enqueue(30): front=0 rear=2 size=3   [10,20,30]
dequeue():   front=1 rear=2 size=2   [_,20,30]
front():     returns 20
```

### Edge Cases

- Enqueue into a full array → must report overflow, not silently corrupt memory.
- Dequeue from empty → must report underflow.
- After many dequeues, `rear` can hit capacity even with logical room left (motivates circular queue).

### Common Mistakes

- Forgetting to check `isFull()`/`isEmpty()` before operations.
- Off-by-one errors initializing `rear = -1` vs `rear = 0`.
- Not incrementing/decrementing `size` consistently with `front`/`rear`.

### Interview Notes

State clearly that the plain array queue's biggest weakness is space reuse, and immediately pivot to circular queue as the fix — this shows depth.

---

## 2.2 Queue Using Circular Array

### Definition

A circular array queue treats the underlying array as a **ring**: when `rear` (or `front`) reaches the last index, it wraps around to index `0` using modulo arithmetic, reclaiming freed space.

### Visual Explanation

```text
        index 0
           |
  index4 [ ]  index1
        /      \
  index3        index2

Array is logically circular: after index 4 comes index 0 again.
rear = (rear + 1) % capacity
front = (front + 1) % capacity
```

### Internal Working

```cpp
class CircularQueue {
    vector<int> arr;
    int front, rear, capacity, size;
public:
    CircularQueue(int cap) {
        capacity = cap;
        arr.resize(cap);
        front = 0; rear = -1; size = 0;
    }
    bool isFull()  { return size == capacity; }
    bool isEmpty() { return size == 0; }

    void enqueue(int x) {
        if (isFull()) { cout << "Overflow\n"; return; }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        size++;
    }
    void dequeue() {
        if (isEmpty()) { cout << "Underflow\n"; return; }
        front = (front + 1) % capacity;
        size--;
    }
    int getFront() { return isEmpty() ? -1 : arr[front]; }
    int getRear()  { return isEmpty() ? -1 : arr[rear]; }
};
```

### Dry Run (capacity = 5)

```text
enqueue(1): front=0 rear=0 size=1  [1,_,_,_,_]
enqueue(2): front=0 rear=1 size=2  [1,2,_,_,_]
enqueue(3): front=0 rear=2 size=3  [1,2,3,_,_]
dequeue():  front=1 rear=2 size=2  [_,2,3,_,_]
dequeue():  front=2 rear=2 size=1  [_,_,3,_,_]
enqueue(4): front=2 rear=3 size=2  [_,_,3,4,_]
enqueue(5): front=2 rear=4 size=3  [_,_,3,4,5]
enqueue(6): rear=(4+1)%5=0         [6,_,3,4,5]  <- wrap-around!
```

### Advantages

- True O(1) enqueue and dequeue with **no wasted space**.
- Fixed memory footprint — good for embedded/real-time systems with known capacity.

### Disadvantages

- Fixed capacity — must resize manually if it needs to grow (or use a dynamic array doubling strategy).
- Slightly trickier index math (`isFull`/`isEmpty` need careful condition design — see Section 4).

### Complexity

| Operation | Time | Space |
|---|---|---|
| Enqueue | O(1) | O(1) extra |
| Dequeue | O(1) | O(1) extra |
| Front/Rear | O(1) | O(1) |

(Full deep-dive with overflow/underflow edge cases is in **Section 4**.)

---

## 2.3 Queue Using Linked List

### Definition

A linked-list-based queue keeps a `head` (front) and `tail` (rear) pointer over a singly linked list. Enqueue appends a new node at `tail`; dequeue removes the node at `head`.

### Visual Explanation

```text
front                                   rear
  |                                       |
 [10|*]->[20|*]->[30|*]->[40|NULL]
```

### Internal Working

```cpp
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class QueueLL {
    Node *front, *rear;
public:
    QueueLL() : front(nullptr), rear(nullptr) {}

    bool isEmpty() { return front == nullptr; }

    void enqueue(int x) {
        Node* node = new Node(x);
        if (rear == nullptr) {        // empty queue
            front = rear = node;
            return;
        }
        rear->next = node;
        rear = node;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Underflow\n"; return; }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr; // queue became empty
        delete temp;
    }

    int getFront() { return isEmpty() ? -1 : front->data; }
};
```

### Memory Layout

Unlike arrays, nodes are scattered across heap memory and linked via pointers — no contiguous block required, so there is **no fixed capacity** and no overflow (until system memory itself is exhausted).

### Advantages

- Dynamic size — grows and shrinks naturally, no resizing logic needed.
- No overflow concerns (memory-permitting).
- O(1) enqueue and dequeue with both pointers tracked.

### Disadvantages

- Extra memory overhead per node (pointer storage).
- Poor cache locality compared to arrays (pointer chasing is slower in practice despite same Big-O).
- Slightly more code complexity (pointer management, risk of memory leaks if `delete` is forgotten in C++).

### Dry Run

```text
enqueue(10): front=10, rear=10                       [10]
enqueue(20): front=10, rear=20                        [10]->[20]
enqueue(30): front=10, rear=30                        [10]->[20]->[30]
dequeue():   front=20, rear=30 (10 removed)           [20]->[30]
dequeue():   front=30, rear=30 (20 removed)           [30]
dequeue():   front=NULL, rear=NULL (queue empty)      []
```

### Complexity

| Operation | Time | Space |
|---|---|---|
| Enqueue | O(1) | O(1) per node |
| Dequeue | O(1) | O(1) |

### Common Mistakes

- Forgetting to reset `rear = nullptr` when the last element is dequeued — leaves a dangling pointer.
- Memory leaks from not `delete`-ing dequeued nodes in C++.
- Null-pointer dereference when calling `front()`/`dequeue()` on an empty queue.

---

## 2.4 STL Queue (`std::queue`)

### Definition

C++ STL provides `std::queue<T>`, a **container adapter** built (by default) on top of `std::deque`, exposing only FIFO-safe operations.

### Usage

```cpp
#include <queue>
using namespace std;

queue<int> q;
q.push(10);       // enqueue
q.push(20);
q.push(30);
cout << q.front(); // 10
cout << q.back();  // 30
q.pop();           // dequeue -> removes 10
cout << q.size();  // 2
cout << q.empty(); // false
```

### Internal Working

By default `std::queue` wraps `std::deque` (a chunked, doubly-indexable structure — see Section 2.5), giving true O(1) push/pop at both ends without the manual circular-array logic. You can also back it with `std::list`.

### Key STL Queue Methods

| Method | Purpose | Complexity |
|---|---|---|
| `push(x)` | Enqueue at rear | O(1) |
| `pop()` | Dequeue from front (no return value!) | O(1) |
| `front()` | Access front element | O(1) |
| `back()` | Access rear element | O(1) |
| `empty()` | Check if queue is empty | O(1) |
| `size()` | Number of elements | O(1) |

### Common Mistake

`pop()` does **not** return the removed value (unlike many other languages' `dequeue()`). You must call `front()` first, store it, then call `pop()`.

```cpp
int val = q.front();
q.pop();
```

### Interview Notes

In interviews, you may be asked to implement a queue from scratch (Sections 2.1–2.3) even though `std::queue` exists — this tests fundamentals. In competitive programming, just use `std::queue` directly to save time.

---

## 2.5 STL Deque (`std::deque`)

### Definition

`std::deque` (double-ended queue) supports O(1) insertion/removal at **both** front and back, and also supports O(1) random access via `[]`, unlike `std::queue`.

### Usage

```cpp
#include <deque>
using namespace std;

deque<int> dq;
dq.push_back(10);
dq.push_front(5);
dq.push_back(20);
// dq: [5, 10, 20]

dq.pop_front();  // removes 5
dq.pop_back();   // removes 20
cout << dq[0];   // random access -> 10
```

### Memory Layout

Internally, `std::deque` is implemented as a **sequence of fixed-size memory blocks** ("chunks") with an index map pointing to each chunk — not a single contiguous array like `std::vector`. This is what allows O(1) growth at both ends without ever shifting existing elements.

```text
Map (array of block pointers):
[ ptr0 ][ ptr1 ][ ptr2 ]
   |       |       |
   v       v       v
 [block0][block1][block2]   <- fixed-size chunks of elements
```

### Advantages

- O(1) push/pop at both ends.
- O(1) random access (unlike `std::list`).
- Used as the default backing container for `std::queue` and `std::stack`.

### Disadvantages

- Slightly more memory overhead than `std::vector` due to the chunked structure.
- Iterator invalidation rules are more complex than vectors.

### Complexity

| Operation | Complexity |
|---|---|
| push_front / push_back | O(1) |
| pop_front / pop_back | O(1) |
| Random access `dq[i]` | O(1) |
| Insert/erase in middle | O(n) |

This is the foundation for **Section 5 (Deque)** and **Section 8 (Monotonic Deque)** — the most powerful and most frequently interview-tested queue variant.

---

# SECTION 3: QUEUE OPERATIONS

Every queue implementation (array, circular array, linked list, STL) exposes the same logical operation set. This section treats each operation as a standalone concept.

## 3.1 Enqueue

### Concept

Inserts a new element at the **rear** of the queue. It is the only way new data enters a queue.

### Visualization

```text
Before: Front->[10][20][30]<-Rear
enqueue(40)
After:  Front->[10][20][30][40]<-Rear
```

### Dry Run

```text
q = []
enqueue(5)  -> [5]
enqueue(15) -> [5, 15]
enqueue(25) -> [5, 15, 25]
```

### Complexity

| Implementation | Time |
|---|---|
| Array (two-pointer) | O(1) amortized, O(n) if resize needed |
| Circular Array | O(1) |
| Linked List | O(1) |
| STL queue/deque | O(1) |

### Common Mistakes

- Not checking `isFull()` for fixed-capacity implementations.
- Forgetting to update `size`/`rear` together, causing desync between logical size and pointer position.

---

## 3.2 Dequeue

### Concept

Removes and (usually) returns the element at the **front** of the queue. It is the only way data leaves a queue.

### Visualization

```text
Before: Front->[10][20][30]<-Rear
dequeue() -> returns 10
After:  Front->[20][30]<-Rear
```

### Dry Run

```text
q = [5, 15, 25]
dequeue() -> returns 5,  q = [15, 25]
dequeue() -> returns 15, q = [25]
dequeue() -> returns 25, q = []
dequeue() -> UNDERFLOW (queue empty)
```

### Complexity

| Implementation | Time |
|---|---|
| Naive array (shifting) | O(n) |
| Two-pointer / Circular array | O(1) |
| Linked List | O(1) |
| STL queue/deque | O(1) |

### Common Mistakes

- Calling dequeue on an empty queue without checking `isEmpty()` first → undefined behavior / crash.
- In linked-list implementations, forgetting to reset `rear = nullptr` when the queue becomes empty after the last dequeue.

---

## 3.3 Front

### Concept

Returns (without removing) the element currently at the front — the next one that will be dequeued.

### Visualization

```text
Front->[10][20][30]<-Rear
front() -> 10   (queue unchanged)
```

### Complexity: O(1) in all standard implementations.

### Common Mistakes

- Confusing `front()` (peek) with `dequeue()` (remove) — `front()` must never modify the queue.

---

## 3.4 Rear

### Concept

Returns (without removing) the element currently at the rear — the most recently enqueued element.

### Visualization

```text
Front->[10][20][30]<-Rear
rear() -> 30   (queue unchanged)
```

### Complexity: O(1).

### Common Mistakes

- Assuming `rear()` exists on `std::queue` as `rear()` — in C++ STL the method is actually named `back()`.

---

## 3.5 Size

### Concept

Returns the current number of elements in the queue.

### Implementation Note

Maintain a running `size` counter updated on every enqueue/dequeue rather than recomputing it by traversal — this keeps `size()` O(1) instead of O(n).

### Complexity: O(1) (with a maintained counter) or O(n) (if computed by traversal — avoid this).

---

## 3.6 Empty

### Concept

Checks whether the queue currently holds zero elements. This check should **always** precede `front()`, `rear()`, and `dequeue()` calls in production code.

```cpp
if (!q.empty()) {
    int x = q.front();
    q.pop();
}
```

### Complexity: O(1).

---

## 3.7 Clear

### Concept

Removes all elements from the queue, resetting it to an empty state.

```cpp
// STL queue has no .clear() — common trick:
queue<int> empty;
swap(q, empty);   // O(1) swap, old contents destroyed
```

For a circular array implementation: simply reset `front = 0; rear = -1; size = 0;` — no need to physically erase the values, since they will be overwritten on future enqueues. This is an O(1) clear instead of an O(n) erase loop.

### Complexity: O(1) (via swap-trick or pointer reset) vs O(n) (if manually popping every element in a loop).

### Common Mistakes

- Manually looping `while (!q.empty()) q.pop();` works but is O(n) — fine for correctness, just slower than the swap-trick when performance matters.

---

# SECTION 4: CIRCULAR QUEUE MASTERY

## 4.1 Why Circular Queue Exists

### Definition

A **Circular Queue** is a fixed-capacity queue implemented over an array where the index wraps from the last position back to index `0`, so that space freed by dequeues at the front is reused for future enqueues — eliminating the "false overflow" problem of a plain linear array queue (see Section 2.1).

### Intuition

Picture a circular clock face with `capacity` positions numbered `0` to `capacity-1`. `front` and `rear` are hands that move clockwise. When a hand passes position `capacity - 1`, it wraps to `0`.

### Visual Explanation

```text
              0
        4 [ ][ ] 1
              [ ]
        3 [ ][ ] 2

front and rear both move using: index = (index + 1) % capacity
```

## 4.2 Circular Queue Design

### Required State

```cpp
vector<int> arr(capacity);
int front = 0;
int rear  = -1;
int size  = 0;       // explicit counter avoids front==rear ambiguity
```

Using an explicit `size` counter (instead of trying to distinguish "full" vs "empty" purely from `front == rear`) is the cleanest, least error-prone design and is what most production and interview solutions use.

## 4.3 Front Pointer & Rear Pointer

| Pointer | Meaning | Update Rule |
|---|---|---|
| `front` | Index of the oldest (next-to-remove) element | `front = (front + 1) % capacity` on dequeue |
| `rear` | Index of the newest (last-inserted) element | `rear = (rear + 1) % capacity` on enqueue |

## 4.4 Overflow Conditions

```text
isFull()  ⇔  size == capacity
```

Attempting `enqueue()` when `isFull()` is true must be rejected — this is a true overflow (not the false overflow of Section 2.1, since all `capacity` slots really are occupied).

## 4.5 Underflow Conditions

```text
isEmpty()  ⇔  size == 0
```

Attempting `dequeue()`, `front()`, or `rear()` when `isEmpty()` is true must be rejected.

## 4.6 Modulo Arithmetic — The Core Trick

The wrap-around behavior is achieved entirely through the modulo operator:

```text
next_index = (current_index + 1) % capacity
```

```text
capacity = 5
index 4 -> (4 + 1) % 5 = 0   (wraps to start)
index 2 -> (2 + 1) % 5 = 3   (normal advance)
```

## 4.7 Complete Implementation

```cpp
class CircularQueue {
    vector<int> arr;
    int front, rear, cap, sz;
public:
    CircularQueue(int capacity) {
        cap = capacity;
        arr.resize(cap);
        front = 0;
        rear = -1;
        sz = 0;
    }

    bool isFull()  { return sz == cap; }
    bool isEmpty() { return sz == 0; }

    bool enqueue(int x) {
        if (isFull()) return false;          // Overflow
        rear = (rear + 1) % cap;
        arr[rear] = x;
        sz++;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) return false;         // Underflow
        front = (front + 1) % cap;
        sz--;
        return true;
    }

    int getFront() { return isEmpty() ? -1 : arr[front]; }
    int getRear()  { return isEmpty() ? -1 : arr[rear]; }
};
```

## 4.8 Complete Dry Run (capacity = 4)

```text
Operation        front  rear  size  Array State
init                0    -1    0    [_, _, _, _]
enqueue(1)           0    0    1    [1, _, _, _]
enqueue(2)           0    1    2    [1, 2, _, _]
enqueue(3)           0    2    3    [1, 2, 3, _]
enqueue(4)           0    3    4    [1, 2, 3, 4]   <- now FULL
enqueue(5)           --   --   --   OVERFLOW (rejected)
dequeue()            1    3    3    [_, 2, 3, 4]
dequeue()            2    3    2    [_, _, 3, 4]
enqueue(5)           2    0    3    [5, _, 3, 4]   <- rear wrapped to 0!
enqueue(6)           2    1    4    [5, 6, 3, 4]   <- FULL again
```

Notice how slots 0 and 1 (freed by the two dequeues) were successfully reused by the later enqueues — this is the entire point of a circular queue.

## 4.9 Real World Applications

| Application | Why Circular Queue Fits |
|---|---|
| CPU Round-Robin Scheduling | Fixed pool of processes cycled in order, reused continuously |
| Circular Buffers in Networking | Fixed-size packet buffers that continuously reuse memory |
| Streaming Audio/Video Buffers | Fixed-size playback buffer constantly overwritten with new frames |
| Traffic Light / Resource Cycling | Resources allocated and freed in a repeating cycle |

## 4.10 Common Mistakes

- Using `front == rear` alone to detect both "empty" and "full" — this is ambiguous without an explicit `size` counter (a known classic bug; some textbooks solve it by sacrificing one slot instead — both approaches are valid, but **the size-counter approach is simpler and less error-prone**).
- Forgetting the modulo operator entirely and just incrementing `rear` without wrapping — causes an immediate (and incorrect) array-bounds overflow.
- Off-by-one errors initializing `rear = -1` instead of `rear = 0` combined with inconsistent first-enqueue logic.

## 4.11 Interview Notes

- A very common interview/OA question: "Design a Circular Queue" (LeetCode 622) — practice the exact implementation in 4.7 until it's muscle memory.
- Be ready to explain *why* `% capacity` is the key trick — interviewers often probe this specifically.

---

# SECTION 5: DEQUE (DOUBLE ENDED QUEUE)

## 5.1 What is Deque?

### Definition

A **Deque** (Double-Ended Queue, pronounced "deck") is a linear data structure that allows insertion and deletion at **both** the front and the rear in O(1) time. It generalizes both Queue (FIFO) and Stack (LIFO) — you can use a deque to simulate either.

### Intuition

Think of a deque as a queue where the line allows people to join or leave from **either** end, not just the back/front respectively.

### Visual Explanation

```text
   insert/delete here          insert/delete here
            v                          v
        Front -> [10][20][30][40] <- Rear
```

## 5.2 Insert Front

### Concept

Adds a new element to the front of the deque.

```text
Before: [10][20][30]
insertFront(5)
After:  [5][10][20][30]
```

```cpp
deque<int> dq = {10, 20, 30};
dq.push_front(5);   // [5, 10, 20, 30]
```

**Complexity:** O(1).

## 5.3 Insert Rear

### Concept

Adds a new element to the rear of the deque.

```text
Before: [10][20][30]
insertRear(40)
After:  [10][20][30][40]
```

```cpp
dq.push_back(40);   // [10, 20, 30, 40]
```

**Complexity:** O(1).

## 5.4 Delete Front

### Concept

Removes the element at the front of the deque.

```text
Before: [10][20][30]
deleteFront()
After:  [20][30]
```

```cpp
dq.pop_front();
```

**Complexity:** O(1).

## 5.5 Delete Rear

### Concept

Removes the element at the rear of the deque.

```text
Before: [10][20][30]
deleteRear()
After:  [10][20]
```

```cpp
dq.pop_back();
```

**Complexity:** O(1).

## 5.6 Applications of Deque

| Application | Why Deque Fits |
|---|---|
| Sliding Window Maximum/Minimum | Maintains a monotonic structure with insert/remove from both ends (Section 8) |
| Palindrome Checking | Compare and pop from both ends simultaneously |
| Undo/Redo Systems | Need to add/remove from both recent and oldest ends |
| Browser History (forward/back) | Natural double-ended navigation |
| A-Steal Job Scheduling (work-stealing queues) | Workers pop from one end, thieves steal from the other |
| Implementing both Stack and Queue with one structure | Deque is a strict superset of both |

## 5.7 STL Deque — Internal Working & Complexity

Already detailed in Section 2.5, but summarized here for completeness:

| Operation | Complexity |
|---|---|
| `push_front(x)` | O(1) |
| `push_back(x)` | O(1) |
| `pop_front()` | O(1) |
| `pop_back()` | O(1) |
| `front()` / `back()` | O(1) |
| `dq[i]` random access | O(1) |
| Insert/erase at arbitrary middle index | O(n) |

### Dry Run

```text
dq = []
push_back(10)   -> [10]
push_back(20)   -> [10, 20]
push_front(5)   -> [5, 10, 20]
pop_back()      -> [5, 10]      (removed 20)
push_front(1)   -> [1, 5, 10]
pop_front()     -> [5, 10]      (removed 1)
```

## 5.8 Edge Cases

- Deque with a single element: both `front()` and `back()` point to the same element; popping from either end empties the deque.
- Repeated `push_front`/`pop_back` only — deque degrades to behaving like a stack; verify your logic doesn't accidentally assume FIFO-only behavior.

## 5.9 Common Mistakes

- Using `std::deque` when only `std::queue`/`std::stack` semantics are needed — fine functionally, but signals less precise intent in interviews. Prefer the most restrictive type that satisfies the problem.
- Forgetting that `std::deque` (unlike `std::queue`) supports random access and erase-in-middle — useful but O(n) if used carelessly in tight loops.

## 5.10 Interview Notes

Deque is the single most powerful tool in this handbook for **Sliding Window** style problems — almost every "maximum/minimum in every window of size k" problem (Section 8) is solved using a **monotonic deque**, not a plain queue or heap. Recognizing "deque, not queue" is a critical pattern-matching skill for OAs and interviews.

---

# SECTION 6: COMPLEXITY ANALYSIS

## 6.1 Operation-Wise Complexity (All Implementations)

| Operation | Naive Array (shift) | Two-Pointer Array | Circular Array | Linked List | STL `queue` | STL `deque` |
|---|---|---|---|---|---|---|
| Enqueue / push_back | O(1) | O(1) | O(1) | O(1) | O(1) | O(1) |
| Dequeue / pop_front | O(n) | O(1)* | O(1) | O(1) | O(1) | O(1) |
| push_front | N/A | N/A | N/A | O(1)** | N/A | O(1) |
| pop_back | N/A | N/A | N/A | O(n)** | N/A | O(1) |
| Front/Rear (peek) | O(1) | O(1) | O(1) | O(1) | O(1) | O(1) |
| Search (by value) | O(n) | O(n) | O(n) | O(n) | O(n) | O(n) |
| Random access | O(1) | O(1) | O(1) | O(n) | N/A | O(1) |
| Space | O(n) | O(n) | O(n) (fixed cap) | O(n) | O(n) | O(n) |

\* Wastes front-side space over time (Section 2.1).
\*\* A *singly* linked list queue only tracks `front`/`rear`, so `pop_back` requires an O(n) traversal to find the new tail; a *doubly* linked list fixes this to O(1) at the cost of extra pointer memory.

## 6.2 Why "O(1) Enqueue/Dequeue" Matters

A correctly implemented queue (circular array, linked list, or STL) guarantees **O(1) amortized** time for both core operations regardless of how many elements have passed through it over the program's lifetime. This is what makes queues suitable for high-throughput systems (schedulers, buffers, message brokers) where thousands of operations happen per second.

## 6.3 Complexity by Use Case

| Use Case | Recommended Structure | Why |
|---|---|---|
| Fixed maximum size known in advance | Circular Array | No dynamic allocation overhead, predictable memory |
| Unknown / unbounded size | Linked List or STL `queue` (deque-backed) | Grows dynamically without manual resizing |
| Need both-end access | `std::deque` | O(1) at both ends + random access |
| Need priority-based removal (not FIFO) | `std::priority_queue` (Section 9) | O(log n) insert/remove-max instead of O(1) FIFO |
| Sliding window max/min | Monotonic Deque (Section 8) | Amortized O(1) per element overall, O(n) total |

## 6.4 Master Complexity Table (Patterns Preview)

| Pattern | Time Complexity | Space Complexity |
|---|---|---|
| Basic FIFO simulation | O(n) | O(n) |
| Circular Queue operations | O(1) per op | O(capacity) |
| Sliding Window Maximum (monotonic deque) | O(n) total | O(k) |
| Priority Queue operations | O(log n) per op | O(n) |
| BFS-style multi-source processing | O(V + E) | O(V) |
| Stream processing (first non-repeating char) | O(n) total, O(1) amortized per char | O(26) or O(n) |

---

# SECTION 7: IMPORTANT QUEUE PATTERNS

This section teaches **pattern recognition** — the single highest-leverage skill for OAs and interviews. Once you can identify *which* pattern a problem belongs to, the solution template follows almost automatically.

## Pattern 1: Basic FIFO Processing

### Identification Clues
"Process items in the order received", "simulate a queue/line", "first come first serve".

### Intuition
Direct, literal use of a queue — no transformation needed.

### Template

```cpp
queue<int> q;
for (int x : input) q.push(x);
while (!q.empty()) {
    int curr = q.front(); q.pop();
    // process curr
}
```

### Common Problems
Ticket counter simulation, simple task queue simulation, round-robin scheduling (Section 10.4 — "Circular Tour" related family).

---

## Pattern 2: Circular Queue

### Identification Clues
"Fixed buffer size", "design a circular structure", "reuse freed space", "ring buffer".

### Intuition
Use modulo arithmetic to wrap indices instead of resizing or shifting.

### Template
See Section 4.7 for the full implementation.

### Common Problems
Design Circular Queue (LeetCode 622), Design Circular Deque (LeetCode 641), Moving Average from Data Stream (LeetCode 346 — uses a fixed-size circular window).

---

## Pattern 3: Deque Pattern

### Identification Clues
"Insert/remove from both ends", "need access to both newest and oldest elements", "palindrome check", "undo/redo".

### Intuition
Neither a pure stack nor a pure queue is sufficient — both ends matter.

### Template

```cpp
deque<int> dq;
dq.push_back(x);    // or push_front
dq.pop_front();      // or pop_back
```

### Common Problems
Design Front Middle Back Queue (LeetCode 1670), Palindrome check via deque, Sliding window problems (see Pattern 4).

---

## Pattern 4: Sliding Window Maximum

### Identification Clues
"Maximum/minimum of every subarray of size k", "sliding window", "moving max".

### Intuition
Maintain a **monotonic decreasing deque** of indices — front always holds the index of the current window's maximum.

### Template

```cpp
vector<int> slidingWindowMax(vector<int>& nums, int k) {
    deque<int> dq;       // stores indices, values decreasing front->back
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();      // out of window
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back(); // maintain decreasing order
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}
```

Full dry run in **Section 8.1**.

### Common Problems
Sliding Window Maximum (LeetCode 239), Sliding Window Minimum (GFG), Maximum of all subarrays of size k.

---

## Pattern 5: Monotonic Queue

### Identification Clues
"Next greater/smaller while maintaining order", "maximum in a constrained range", "find nearest greater element in a moving structure".

### Intuition
A queue/deque that maintains elements in strictly increasing or decreasing order by evicting "dominated" elements before inserting new ones.

### Template
Same structural idea as Pattern 4, generalized — see full coverage in **Section 8**.

### Common Problems
Shortest Subarray with Sum at Least K (LeetCode 862), Constrained Subsequence Sum (LeetCode 1425), Jump Game VI (LeetCode 1696).

---

## Pattern 6: Multi-Source Processing (BFS-style)

### Identification Clues
"Multiple starting points spread simultaneously", "rotten oranges", "shortest time for all X to reach Y", "infection/contamination spreading".

### Intuition
Push **all** initial sources into the queue at once (not just one), then process level by level — each "level" of the BFS represents one unit of time elapsed.

### Template

```cpp
queue<pair<int,int>> q;
for (auto& source : allSources) q.push(source);
int time = 0;
while (!q.empty()) {
    int sz = q.size();
    bool advanced = false;
    for (int i = 0; i < sz; i++) {
        auto [r, c] = q.front(); q.pop();
        // explore neighbors, push newly affected cells
        // mark advanced = true if any neighbor was newly processed
    }
    if (advanced) time++;
}
```

### Common Problems
Rotten Oranges (LeetCode 994 — detailed in Section 10.3), Walls and Gates, 01 Matrix (LeetCode 542).

---

## Pattern 7: Simulation Problems

### Identification Clues
"Simulate the process step by step", "what happens after k rounds", "card game / token passing simulation".

### Intuition
Directly model the real-world process using enqueue/dequeue exactly as the problem describes — no clever trick, just faithful simulation.

### Template

```cpp
queue<int> q;
for (int x : input) q.push(x);
while (q.size() > 1) {
    int a = q.front(); q.pop();
    int b = q.front(); q.pop();
    // apply rule, push result(s) back
    q.push(/* combined or modified value */);
}
```

### Common Problems
Reveal Cards In Increasing Order (LeetCode 950), Last Stone Weight variations, Josephus Problem variants.

---

## Pattern 8: Producer-Consumer Pattern

### Identification Clues
"One side generates items, another consumes them", "bounded buffer", "synchronize generation and consumption".

### Intuition
A queue acts as the shared bounded buffer between a producer thread/process and a consumer thread/process — producer blocks (or fails) when the queue is full, consumer blocks (or fails) when it's empty.

### Conceptual Template (single-threaded simulation)

```cpp
queue<int> buffer;
int CAPACITY = 5;

void produce(int item) {
    if (buffer.size() < CAPACITY) buffer.push(item);
    // else: wait / drop / block depending on system design
}

int consume() {
    if (!buffer.empty()) { int x = buffer.front(); buffer.pop(); return x; }
    // else: wait / block
    return -1;
}
```

### Common Problems
Bounded Blocking Queue design questions, OS-level producer-consumer simulation questions, Design Hit Counter (LeetCode 362, queue-based rate windowing).

---

## Pattern 9: Scheduling Problems

### Identification Clues
"CPU scheduling", "task with cooldown", "round robin", "process with execution time".

### Intuition
Queues (often combined with a hash map or priority queue) model tasks waiting their turn, with cooldowns/priorities tracked alongside.

### Template (Task Scheduler — cooldown style)

```cpp
// Conceptual: track next-available time for each task type, use queue/heap to pick next task
```

### Common Problems
Task Scheduler (LeetCode 621), Design Hit Counter, Number of Recent Calls (LeetCode 933 — queue-based time window).

---

## Pattern 10: Stream Processing

### Identification Clues
"Characters/numbers arrive one at a time", "process as a stream", "no full array given upfront", "maintain state as data arrives".

### Intuition
A queue maintains the elements that are still "candidates" as new stream elements arrive, discarding elements that can no longer be valid answers.

### Template (First Non-Repeating Character in Stream — see Section 10.2 for full solution)

```cpp
queue<char> q;
int freq[26] = {0};
for (char c : stream) {
    q.push(c);
    freq[c - 'a']++;
    while (!q.empty() && freq[q.front() - 'a'] > 1) q.pop();
    cout << (q.empty() ? '#' : q.front());
}
```

### Common Problems
First Non-Repeating Character in a Stream, Moving Average from Data Stream (LeetCode 346), Number of Recent Calls (LeetCode 933).

---

# SECTION 8: DEQUE & MONOTONIC QUEUE MASTERY

This is the single most interview-critical section in the handbook. Monotonic deques solve an entire family of "best value in every window" problems in O(n) instead of the naive O(n·k).

## 8.1 Sliding Window Maximum

### Definition
Given an array and window size `k`, find the maximum element in every contiguous window of size `k` as it slides from left to right.

### Intuition
A brute-force scan of every window is O(n·k). Instead, maintain a **deque of indices** where the corresponding values are in **strictly decreasing order** from front to back. The front of the deque is always the maximum of the current window, because any smaller element that appeared before a larger one can never become the answer again (the larger element will always be the max until it itself slides out).

### Visual Explanation

```text
nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3

i=0 (val=1):  deque(idx)=[0]                  values=[1]
i=1 (val=3):  1 dominates 0 (1<3, pop 0)      deque=[1]          values=[3]
i=2 (val=-1): -1 < 3, just push               deque=[1,2]        values=[3,-1]   window[0..2] complete -> max = nums[1] = 3
i=3 (val=-3): -3 < -1, push; idx1 still valid deque=[1,2,3]      values=[3,-1,-3] window[1..3] -> max = nums[1] = 3
i=4 (val=5):  pop 3,2,1 (all < 5)             deque=[4]          values=[5]      window[2..4] -> max = nums[4] = 5
i=5 (val=3):  3<5, push                       deque=[4,5]        values=[5,3]    window[3..5] -> max = nums[4] = 5
i=6 (val=6):  pop 5,4 (both <6)               deque=[6]          values=[6]      window[4..6] -> max = nums[6] = 6
i=7 (val=7):  pop 6 (<7)                      deque=[7]          values=[7]      window[5..7] -> max = nums[7] = 7

Result: [3, 3, 5, 5, 6, 7]
```

### Brute Force Approach

For every window, scan all `k` elements to find the max.

```cpp
vector<int> bruteForce(vector<int>& nums, int k) {
    vector<int> res;
    for (int i = 0; i + k <= nums.size(); i++) {
        int mx = nums[i];
        for (int j = i; j < i + k; j++) mx = max(mx, nums[j]);
        res.push_back(mx);
    }
    return res;
}
```
**Time:** O(n·k). **Space:** O(1) extra (excluding output).

### Better Approach

Use a max-heap of `(value, index)` pairs; pop stale (out-of-window) indices lazily.

```cpp
vector<int> usingHeap(vector<int>& nums, int k) {
    priority_queue<pair<int,int>> pq;   // (value, index), max-heap by default
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        pq.push({nums[i], i});
        while (pq.top().second <= i - k) pq.pop();   // discard stale entries
        if (i >= k - 1) res.push_back(pq.top().first);
    }
    return res;
}
```
**Time:** O(n log n). **Space:** O(n).

### Optimal Approach (Monotonic Deque)

```cpp
vector<int> slidingWindowMax(vector<int>& nums, int k) {
    deque<int> dq;          // stores indices; nums[dq[i]] strictly decreasing
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}
```
**Time:** O(n) — each index is pushed and popped from the deque at most once. **Space:** O(k) for the deque.

### Time & Space Complexity Summary

| Approach | Time | Space |
|---|---|---|
| Brute Force | O(n·k) | O(1) extra |
| Heap-based | O(n log n) | O(n) |
| Monotonic Deque (Optimal) | O(n) | O(k) |

### Edge Cases
- `k == 1`: every element is its own window's max — result equals input array.
- `k == n`: single window, single output — the global max.
- All elements equal: deque should still behave correctly (use `<` not `<=` when popping back, or be consistent — popping on `<` keeps equal values, which is fine for max tracking).

### Common Mistakes
- Storing **values** instead of **indices** in the deque — you lose the ability to detect when the front has slid out of the window.
- Using `<=` instead of `<` when evicting from the back inconsistently, leading to wrong results with duplicate values (decide deliberately and be consistent).
- Forgetting the `dq.front() <= i - k` check, which removes indices that have fallen outside the current window.

### Interview Notes
This exact pattern (monotonic deque of indices) is reused, with only the comparison direction flipped, for the minimum-in-window variant below — master one and you've mastered both.

---

## 8.2 Sliding Window Minimum

### Definition
Same as 8.1 but find the **minimum** of every window of size `k`.

### Intuition
Mirror image of 8.1 — maintain a deque of indices with **strictly increasing** values front-to-back; the front is always the window minimum.

### Optimal Template

```cpp
vector<int> slidingWindowMin(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] > nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}
```

### Dry Run

```text
nums = [4, 2, 12, 11, 8], k = 2

i=0(4):  deque=[0]                    -> values [4]
i=1(2):  pop 0 (4>2), push 1          -> deque=[1] values[2]   window[0,1] min=2
i=2(12): push 2                       -> deque=[1,2] values[2,12] window[1,2] min=2
i=3(11): pop 2(12>11), push 3         -> deque=[1,3] values[2,11] window[2,3] min=2
i=4(8):  pop 3(11>8); idx1=2 falls out (1<=4-2=2)? 1<=2 true, pop 1; push4
                                       -> deque=[4] values[8]  window[3,4] min=8

Result: [2, 2, 2, 8]
```

**Time:** O(n). **Space:** O(k).

### Common Mistakes
Same as 8.1 but mirrored — using the wrong comparison direction (`<` instead of `>`) silently turns this into a max-window solution instead.

---

## 8.3 First Negative Integer in Every Window of Size K

### Definition
For every window of size `k`, output the first negative number, or `0` if none exists.

### Intuition
Maintain a queue of **indices of negative numbers seen so far within the current window** (not a full monotonic structure — just a plain FIFO of negative-index candidates, since order of arrival is what matters, not magnitude).

### Optimal Template

```cpp
vector<int> firstNegativeInWindow(vector<int>& nums, int k) {
    deque<int> dq;     // indices of negative numbers, in order
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) dq.push_back(i);
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        if (i >= k - 1) result.push_back(dq.empty() ? 0 : nums[dq.front()]);
    }
    return result;
}
```

### Dry Run

```text
nums = [12, -1, -7, 8, -15, 30, 16, 28], k = 3

i=0(12):  dq=[]            (not negative)
i=1(-1):  dq=[1]
i=2(-7):  dq=[1,2]         window[0,2] -> first neg = nums[1] = -1
i=3(8):   dq=[1,2]; 1<=3-3=0? false      window[1,3] -> first neg = nums[1] = -1
i=4(-15): dq=[1,2,4]; 1<=4-3=1? true, pop 1 -> dq=[2,4]   window[2,4] -> first neg = nums[2] = -7
i=5(30):  dq=[2,4]; 2<=5-3=2? true, pop 2 -> dq=[4]       window[3,5] -> first neg = nums[4] = -15
i=6(16):  dq=[4]; 4<=6-3=3? false                          window[4,6] -> first neg = nums[4] = -15
i=7(28):  dq=[4]; 4<=7-3=4? true, pop 4 -> dq=[]            window[5,7] -> no negatives -> 0

Result: [-1, -1, -7, -15, -15, 0]
```

**Time:** O(n). **Space:** O(k) worst case.

### Common Mistakes
Forgetting to evict indices that fall out of the window even when they were never popped for being "non-extreme" (since this isn't a strictly monotonic structure, the only eviction reason is going out-of-window).

---

## 8.4 Maximum of All Subarrays of Size K

This is identical to **Section 8.1 (Sliding Window Maximum)** — the same problem under a different name (common on GFG vs LeetCode). Use the exact same monotonic decreasing deque template.

---

## 8.5 Monotonic Increasing Queue

### Definition
A deque where elements are maintained in non-decreasing order from front to back, used to efficiently track the **minimum** in a sliding range.

### Construction Rule
When pushing a new element `x`, pop all elements from the **back** that are **greater than** `x` before pushing — this guarantees the front always holds the smallest remaining element.

```cpp
void pushIncreasing(deque<int>& dq, int x) {
    while (!dq.empty() && dq.back() > x) dq.pop_back();
    dq.push_back(x);
}
```

### Use Cases
Sliding window minimum (8.2), maintaining a running minimum with eviction, certain DP optimization problems (monotonic deque DP) that are otherwise out of scope per this handbook's focus.

---

## 8.6 Monotonic Decreasing Queue

### Definition
A deque where elements are maintained in non-increasing order from front to back, used to efficiently track the **maximum** in a sliding range.

### Construction Rule
When pushing a new element `x`, pop all elements from the **back** that are **less than** `x` before pushing — this guarantees the front always holds the largest remaining element.

```cpp
void pushDecreasing(deque<int>& dq, int x) {
    while (!dq.empty() && dq.back() < x) dq.pop_back();
    dq.push_back(x);
}
```

### Use Cases
Sliding window maximum (8.1), shortest subarray with sum at least K, certain greedy/optimization problems with a sliding constraint.

---

## 8.7 Monotonic Deque — Master Template (Memorize This)

```cpp
// Generalized template: maintain max (decreasing) or min (increasing) over a sliding window
deque<int> dq;     // stores indices
for (int i = 0; i < n; i++) {
    // 1. Remove out-of-window indices from FRONT
    while (!dq.empty() && dq.front() <= i - k) dq.pop_front();

    // 2. Remove dominated elements from BACK
    //    For MAX:  while (!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();
    //    For MIN:  while (!dq.empty() && arr[dq.back()] > arr[i]) dq.pop_back();
    while (!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();

    // 3. Push current index
    dq.push_back(i);

    // 4. Record answer once the first full window is formed
    if (i >= k - 1) answer.push_back(arr[dq.front()]);
}
```

### Why It's O(n) Overall (Amortized Analysis)
Each index is pushed onto the deque **exactly once** and popped **at most once** (either from the front for sliding out, or from the back for being dominated). Total pushes = n, total pops ≤ n, so total work across the whole algorithm is O(n), even though it might look like a nested loop.

### Cheat Sheet

| Want | Deque Order | Pop-Back Condition |
|---|---|---|
| Window Maximum | Strictly decreasing | `arr[back] < arr[new]` |
| Window Minimum | Strictly increasing | `arr[back] > arr[new]` |

---

# SECTION 9: PRIORITY QUEUE MASTERY

## 9.1 What is Priority Queue?

### Definition

A **Priority Queue** is an abstract data type where each element has an associated priority, and elements are removed in order of priority (highest or lowest first) rather than strictly insertion order (FIFO). It is most commonly implemented using a **Binary Heap**.

### Intuition

Think of an emergency room: patients aren't treated in arrival order — they're treated by severity (priority). A priority queue formalizes "most important first" processing.

### Visual Explanation

```text
Max-Heap Priority Queue (conceptual, as a tree):

              50
            /    \
          30      40
         /  \     /
       10   20   35

top() always returns 50 (the maximum)
```

> **Note:** This handbook covers Priority Queue strictly as it relates to and is used alongside queue-based patterns (scheduling, multi-source processing). A full Binary Heap / Tree internals deep-dive is intentionally out of scope per this handbook's focus on Queues.

## 9.2 Max Heap Based Priority Queue

### Definition
A priority queue where the element with the **largest** value always has the highest priority and is returned first.

```cpp
priority_queue<int> maxHeap;   // max-heap by default in C++ STL
maxHeap.push(10);
maxHeap.push(30);
maxHeap.push(20);
cout << maxHeap.top();  // 30
maxHeap.pop();           // removes 30
```

**Complexity:** push O(log n), pop O(log n), top O(1).

## 9.3 Min Heap Based Priority Queue

### Definition
A priority queue where the element with the **smallest** value always has the highest priority.

```cpp
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(10);
minHeap.push(30);
minHeap.push(20);
cout << minHeap.top();  // 10
```

**Complexity:** push O(log n), pop O(log n), top O(1).

## 9.4 STL Priority Queue — Internal Working

`std::priority_queue` is implemented as a **binary heap stored in a `vector`** (or `deque`) under the hood, using `std::make_heap`, `push_heap`, and `pop_heap` internally. Parent-child relationships are computed by index arithmetic (`parent = (i-1)/2`, `children = 2i+1, 2i+2`), avoiding any explicit pointer-based tree structure.

```text
Array representation:  [50, 30, 40, 10, 20, 35]
Tree representation:
                50
              /    \
            30      40
           /  \     /
         10   20   35

Index 0 = root, index i's children at 2i+1 and 2i+2
```

## 9.5 Custom Comparators

### For Pairs / Objects with Custom Priority Logic

```cpp
// Min-heap of pairs, ordered by first element
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

// Custom comparator using a lambda (requires decltype)
auto cmp = [](pair<int,int>& a, pair<int,int>& b) {
    return a.second > b.second;   // min-heap by second value
};
priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq2(cmp);
```

### Common Mistake
The comparator for `priority_queue` works **opposite** to `sort()`. In `sort()`, `cmp(a, b) = true` means "a comes before b". In `priority_queue`, `cmp(a, b) = true` means "a has *lower* priority than b" (so b ends up on top). This inversion trips up almost everyone the first time.

## 9.6 Pair Priority Queue

### Use Case
Frequently used for "value with index" or "weight with node" problems — e.g., Dijkstra's algorithm uses `priority_queue<pair<int,int>>` (distance, node) — though full graph coverage is out of scope here, the **pattern** of pairing a priority value with auxiliary data is directly reusable in queue-based scheduling problems.

```cpp
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
pq.push({5, 101});   // {priority, id}
pq.push({2, 102});
pq.push({8, 103});
cout << pq.top().second; // 102 (lowest priority value = highest actual priority for min-heap)
```

## 9.7 Vector-Backed Priority Queue (Custom Implementation)

For interview "implement it yourself" questions:

```cpp
class MaxPQ {
    vector<int> heap;

    void heapifyUp(int i) {
        while (i > 0 && heap[(i-1)/2] < heap[i]) {
            swap(heap[(i-1)/2], heap[i]);
            i = (i-1)/2;
        }
    }
    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2*i+1, right = 2*i+2, largest = i;
            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;
            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }
public:
    void push(int x) {
        heap.push_back(x);
        heapifyUp(heap.size() - 1);
    }
    void pop() {
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
    int top() { return heap[0]; }
};
```

### Dry Run (push 10, 30, 20)

```text
push(10): heap=[10]
push(30): heap=[10,30] -> heapifyUp: 30>10, swap -> heap=[30,10]
push(20): heap=[30,10,20] -> heapifyUp: parent of idx2 is idx0=30, 30>20 no swap
top() = 30
pop():    heap[0]=heap.back()=20, pop_back -> heap=[20,10]
          heapifyDown(0): left=10, right=none, 10<20, no swap
          heap=[20,10]
```

**Complexity:** push O(log n), pop O(log n), top O(1).

## 9.8 Complexity Summary

| Operation | Array (unsorted) | Array (sorted) | Binary Heap |
|---|---|---|---|
| Insert | O(1) | O(n) | O(log n) |
| Get Max/Min | O(n) | O(1) | O(1) |
| Extract Max/Min | O(n) | O(1)* | O(log n) |
| Build from n elements | O(n) | O(n log n) | O(n) |

\* O(1) extraction from a sorted array only if extracting from the correct end; reinserting still costs O(n) to keep it sorted.

## 9.9 Applications

| Application | How Priority Queue is Used |
|---|---|
| CPU Scheduling (priority-based) | Higher-priority processes scheduled first instead of pure FIFO |
| Task Scheduler with cooldown | Always picks the most frequent remaining task next |
| Merge K Sorted Lists/Streams | Min-heap of "next smallest" across all sources |
| Top-K element problems | Maintain a heap of size K |
| Event-driven simulation | Process events ordered by timestamp |
| Huffman Coding (out of full scope here) | Always merge two lowest-frequency nodes |

## 9.10 Edge Cases
- Empty priority queue: calling `top()`/`pop()` is undefined behavior — always check `empty()` first.
- Duplicate priorities: heap order among equal-priority elements is **not guaranteed stable** — don't assume insertion order is preserved for ties.

## 9.11 Common Mistakes
- Forgetting the three-template-argument form (`priority_queue<T, vector<T>, greater<T>>`) when a min-heap is needed — writing just `priority_queue<int, greater<int>>` is a **compile error** (missing the container type argument).
- Using a priority queue when a plain FIFO queue is what's actually needed (and vice versa) — always confirm whether the problem cares about *priority* or strictly *arrival order*.

## 9.12 Interview Notes
"Top K Frequent Elements", "Kth Largest Element in a Stream", and "Merge K Sorted Lists" are extremely common priority-queue interview questions. Always clarify out loud: "this needs priority-based removal, not FIFO order, so I'll use a heap/priority_queue" — naming the choice explicitly signals strong fundamentals.

---

# SECTION 10: IMPORTANT QUEUE ALGORITHMS

## 10.1 Sliding Window Maximum

Already covered in full depth in **Section 8.1**. Cross-reference for the complete brute-force → optimal walkthrough.

---

## 10.2 First Non-Repeating Character in Stream

### Problem Statement
Given a stream of characters arriving one at a time, after each character report the first non-repeating character seen so far in the stream, or `#` if none exists.

### Intuition
Maintain a queue of **candidate** characters (those with frequency exactly 1 so far). When a new character arrives, push it and update its frequency. Then pop from the front of the queue while the front character's frequency is greater than 1 — it's no longer a valid "non-repeating" candidate. Whatever remains at the front (if anything) is the answer.

### Visualization

```text
Stream: a a b c

'a': freq[a]=1, queue=[a]               front valid -> answer 'a'
'a': freq[a]=2, queue=[a]; pop a(freq>1) queue=[]    -> answer '#'
'b': freq[b]=1, queue=[b]               front valid -> answer 'b'
'c': freq[c]=1, queue=[b,c]             front valid -> answer 'b'
```

### Optimal Approach

```cpp
string firstNonRepeating(string stream) {
    queue<char> q;
    int freq[26] = {0};
    string result = "";
    for (char c : stream) {
        q.push(c);
        freq[c - 'a']++;
        while (!q.empty() && freq[q.front() - 'a'] > 1) q.pop();
        result += q.empty() ? '#' : q.front();
    }
    return result;
}
```

### Dry Run
```text
stream = "aabc"
i=0 'a': freq[a]=1 q=[a]        front 'a' valid -> 'a'
i=1 'a': freq[a]=2 q=[a]        pop 'a' (freq>1) -> q=[]  -> '#'
i=2 'b': freq[b]=1 q=[b]        front 'b' valid -> 'b'
i=3 'c': freq[c]=1 q=[b,c]      front 'b' valid -> 'b'
Result: "a#bb"
```

### Time Complexity: O(n) amortized — each character is pushed once and popped at most once.
### Space Complexity: O(26) for frequency array + O(n) worst case for the queue.

### Edge Cases
- All characters repeat eventually → output ends with many `#`.
- Single character stream → trivially that character.
- Stream with all distinct characters → queue keeps growing, front never changes from index 0's value... actually front is always the *oldest still-unique* char, so it changes only when that char repeats.

### Common Mistakes
- Forgetting that the **while loop** must pop *all* now-invalid front characters, not just check once — multiple characters may need cascading removal.
- Indexing `freq` with `c - 'a'` incorrectly for non-lowercase input (clarify input constraints).

### Interview Notes
This is the canonical "Pattern 10: Stream Processing" problem (Section 7) — instantly recognizable and a favorite OA question (GFG / Amazon OA).

---

## 10.3 Rotten Oranges (Queue Perspective)

### Problem Statement
Given a grid where `0` = empty, `1` = fresh orange, `2` = rotten orange, every minute any fresh orange adjacent (4-directionally) to a rotten orange becomes rotten. Find the minimum minutes until no fresh orange remains, or `-1` if impossible.

### Intuition
This is a textbook **multi-source BFS** (Pattern 6, Section 7). Push *all* initially rotten oranges into the queue simultaneously, then process level by level — each level = one minute.

### Visualization

```text
Grid:
2 1 1
1 1 0
0 1 1

Minute 0: rotten = {(0,0)}, fresh count = 6
Minute 1: (0,1) and (1,0) rot       -> rotten spreads
Minute 2: (0,2) and (1,1) rot
Minute 3: (2,1) rots
Minute 4: (2,2) rots
All fresh rotten by minute 4 -> but (2,0) is 0 (empty, not orange) so it's never counted
```

### Optimal Approach (Multi-Source BFS)

```cpp
int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    queue<pair<int,int>> q;
    int freshCount = 0;

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 2) q.push({r, c});
            if (grid[r][c] == 1) freshCount++;
        }

    if (freshCount == 0) return 0;

    int minutes = 0;
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int sz = q.size();
        bool rottedThisRound = false;
        for (int i = 0; i < sz; i++) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    freshCount--;
                    q.push({nr, nc});
                    rottedThisRound = true;
                }
            }
        }
        if (rottedThisRound) minutes++;
    }

    return freshCount == 0 ? minutes : -1;
}
```

### Dry Run
```text
freshCount=6, queue=[(0,0)]
Round1: pop(0,0) -> rot (0,1) and (1,0); freshCount=4; minutes=1
Round2: pop(0,1),(1,0) -> rot (0,2),(1,1); freshCount=2; minutes=2
Round3: pop(0,2),(1,1) -> rot (2,1); freshCount=1; minutes=3
Round4: pop(2,1) -> rot (2,2); freshCount=0; minutes=4
Queue processes remaining empty -> loop ends
Return minutes = 4
```

### Time Complexity: O(rows × cols) — every cell visited at most once.
### Space Complexity: O(rows × cols) for the queue in the worst case.

### Edge Cases
- No fresh oranges at all → answer is `0` immediately.
- Fresh oranges that can never be reached (isolated by `0`s) → answer is `-1`.
- Grid with only one cell.

### Common Mistakes
- Starting BFS from a single rotten orange instead of **all** rotten oranges simultaneously — this gives wrong minute counts.
- Forgetting to track `freshCount` to detect unreachable fresh oranges (without this check, you might return a minute count even though some oranges never rot).
- Off-by-one in counting `minutes` — only increment when an actual round of rotting happens, not for every queue iteration.

### Interview Notes
This is one of the most popular "queue = BFS" interview questions (LeetCode 994). Always explicitly say "I'll use multi-source BFS by seeding the queue with all rotten oranges" — this is the key insight interviewers listen for.

---

## 10.4 Circular Tour (Gas Station Problem)

### Problem Statement
Given `n` petrol pumps with `petrol[i]` available and `distance[i]` to the next pump, find the starting pump index from which a truck (with tank capacity = total fuel collected) can complete a full circular tour, or `-1` if impossible.

### Intuition
While this is often solved greedily without an explicit queue, the **conceptual queue framing** is: think of it as a circular structure where you track a running deficit. If starting from index `i` causes the tank to go negative before returning to `i`, then no start point between `i` and the failure point can work either — skip directly past the failure point. This greedy "skip" is closely related to the circular queue / circular array traversal pattern (Section 4).

### Optimal Approach

```cpp
int tourStart(vector<int>& petrol, vector<int>& distance) {
    int n = petrol.size();
    int start = 0, deficit = 0, balance = 0;

    for (int i = 0; i < n; i++) {
        balance += petrol[i] - distance[i];
        if (balance < 0) {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }

    return (deficit + balance >= 0) ? start : -1;
}
```

### Dry Run
```text
petrol   = [4, 6, 7, 4]
distance = [6, 5, 3, 5]
diff     = [-2, 1, 4, -1]

i=0: balance=-2 -> deficit=-2, start=1, balance=0
i=1: balance=1
i=2: balance=5
i=3: balance=4

deficit + balance = -2 + 4 = 2 >= 0 -> valid, start = 1
```

### Time Complexity: O(n).
### Space Complexity: O(1).

### Edge Cases
- Total petrol < total distance → no solution exists, return `-1`.
- Single pump → trivially the start if `petrol[0] >= distance[0]`.

### Common Mistakes
- Resetting `balance` but forgetting to accumulate the failed segment into `deficit` — this loses track of whether the overall tour is even feasible.
- Confusing this with a literal queue-simulation approach (an O(n²) brute force that actually simulates a circular queue of pumps) when the greedy O(n) solution is expected for optimal marks.

### Interview Notes
Mention the brute-force circular-simulation approach (literally walking the circular array — Section 4 style — for each start, O(n²)) first, then pivot to the greedy O(n) optimal solution. Interviewers want to see you can do both.

---

## 10.5 Generate Binary Numbers from 1 to N

### Problem Statement
Generate binary representations of numbers from 1 to N using a queue.

### Intuition
Start a queue with `"1"`. To generate the next binary number, dequeue the front, append it to the result, then enqueue `front + "0"` and `front + "1"` — this naturally produces binary numbers in increasing order (it's essentially a BFS over a binary tree of digit strings).

### Visualization

```text
queue = ["1"]
pop "1" -> result=["1"]; push "10","11" -> queue=["10","11"]
pop "10" -> result=["1","10"]; push "100","101" -> queue=["11","100","101"]
pop "11" -> result=["1","10","11"]; push "110","111" -> queue=["100","101","110","111"]
...
```

### Optimal Approach

```cpp
vector<string> generateBinaryNumbers(int n) {
    vector<string> result;
    queue<string> q;
    q.push("1");
    for (int i = 0; i < n; i++) {
        string curr = q.front(); q.pop();
        result.push_back(curr);
        q.push(curr + "0");
        q.push(curr + "1");
    }
    return result;
}
```

### Dry Run (n = 5)
```text
i=0: curr="1"   result=["1"]              push "10","11"
i=1: curr="10"  result=["1","10"]         push "100","101"
i=2: curr="11"  result=["1","10","11"]    push "110","111"
i=3: curr="100" result=[...,"100"]        push "1000","1001"
i=4: curr="101" result=[...,"101"]        push "1010","1011"

Result: ["1","10","11","100","101"]
```

### Time Complexity: O(n) to generate n numbers (each push/pop O(1) amortized, ignoring string-copy cost).
### Space Complexity: O(n) for the queue and result.

### Edge Cases
- N = 0 → empty result.
- N = 1 → just `["1"]`.

### Common Mistakes
- Starting the queue with `"0"` instead of `"1"` — produces an incorrect leading number.
- Forgetting this naturally produces numbers in sorted increasing order *only* because of the FIFO property — using a stack here would break the ordering.

### Interview Notes
A classic "see the queue, see BFS-style generation" pattern question — good for testing whether a candidate understands *why* FIFO order specifically guarantees sorted output here.

---

## 10.6 Interleave Two Halves of a Queue

### Problem Statement
Given a queue of even length `2n`, rearrange it so that the first half and second half are interleaved: `a1, b1, a2, b2, ..., an, bn`.

### Intuition
Use an auxiliary queue. Push the first `n` elements into the auxiliary queue (emptying them from the original), then alternately pop one from the auxiliary queue and one from the (now second-half-only) original queue, pushing each back onto the original.

### Visualization

```text
Original: [1,2,3,4,5,6,7,8]   n=4

Step 1: move first 4 to aux
aux = [1,2,3,4]
original = [5,6,7,8]

Step 2: interleave
pop aux(1), push to original -> original=[5,6,7,8,1]
pop original(5)... 

(Cleaner standard approach shown in code below)
```

### Optimal Approach

```cpp
void interleaveQueue(queue<int>& q) {
    int n = q.size() / 2;
    queue<int> aux;

    // Step 1: move first half to aux
    for (int i = 0; i < n; i++) {
        aux.push(q.front());
        q.pop();
    }

    // Step 2: interleave aux and remaining original (second half) back into original
    while (!aux.empty()) {
        q.push(aux.front()); aux.pop();
        q.push(q.front());   q.pop();
    }
}
```

### Dry Run (q = [1,2,3,4,5,6,7,8], n=4)
```text
After step1: aux=[1,2,3,4], q=[5,6,7,8]

iter1: push aux.front()=1 -> q=[5,6,7,8,1]; aux=[2,3,4]
       push q.front()=5  -> q=[6,7,8,1,5]
iter2: push aux.front()=2 -> q=[6,7,8,1,5,2]; aux=[3,4]
       push q.front()=6  -> q=[7,8,1,5,2,6]
iter3: push aux.front()=3 -> q=[7,8,1,5,2,6,3]; aux=[4]
       push q.front()=7  -> q=[8,1,5,2,6,3,7]
iter4: push aux.front()=4 -> q=[8,1,5,2,6,3,7,4]; aux=[]
       push q.front()=8  -> q=[1,5,2,6,3,7,4,8]

Result: [1,5,2,6,3,7,4,8]   (interleaved!)
```

### Time Complexity: O(n).
### Space Complexity: O(n) for the auxiliary queue.

### Edge Cases
- Odd-length queue → typically undefined/invalid input; clarify with interviewer whether to handle gracefully.
- Empty queue → no-op.

### Common Mistakes
- Pushing in the wrong order (aux-then-original vs original-then-aux) — produces a reversed interleave pattern; always re-derive from a small dry run rather than memorizing blindly.

---

## 10.7 Reverse First K Elements of a Queue

### Problem Statement
Reverse only the first `k` elements of a queue, leaving the rest in their original order.

### Intuition
Use an auxiliary **stack** (LIFO) to reverse just the first `k` elements, then route the rest of the original queue back around using a temporary holding mechanism.

### Optimal Approach

```cpp
queue<int> reverseFirstK(queue<int> q, int k) {
    stack<int> st;

    // Step 1: push first k elements onto a stack (reverses their order)
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: push stack contents back into the queue (now reversed)
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: move the remaining (n-k) original front elements to the back, preserving order
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}
```

### Dry Run (q = [1,2,3,4,5,6,7,8,9,10], k = 5)
```text
Step1: stack=[5,4,3,2,1] (top=5), q=[6,7,8,9,10]
Step2: pop stack into q -> q=[6,7,8,9,10,5,4,3,2,1]
Step3: remaining = 10-5 = 5 -> move front 5 elements (6,7,8,9,10) to back
       q=[5,4,3,2,1,6,7,8,9,10]

Result: [5,4,3,2,1,6,7,8,9,10]   <- first 5 reversed, rest unchanged
```

### Time Complexity: O(n).
### Space Complexity: O(k) for the stack.

### Edge Cases
- `k == 0` → no-op, return queue unchanged.
- `k == n` (entire queue) → step 3 does nothing, entire queue is reversed.

### Common Mistakes
- Forgetting Step 3 entirely — without it, the reversed first-k elements aren't correctly repositioned relative to the rest.
- Off-by-one in computing `remaining = q.size() - k` — must be computed **after** Steps 1–2, when the queue again has its original total size.

---

## 10.8 Queue Reversal (Reverse Entire Queue)

### Problem Statement
Reverse the order of all elements in a queue.

### Intuition
A queue (FIFO) and a stack (LIFO) have opposite ordering — funneling every element through a stack once naturally reverses them.

### Optimal Approach (Using Stack)

```cpp
queue<int> reverseQueue(queue<int> q) {
    stack<int> st;
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    return q;
}
```

### Alternative: Recursive Approach (No Auxiliary Stack — Uses Call Stack Instead)

```cpp
void reverseQueueRecursive(queue<int>& q) {
    if (q.empty()) return;
    int front = q.front();
    q.pop();
    reverseQueueRecursive(q);
    q.push(front);
}
```

### Dry Run (q = [1,2,3,4])
```text
Using stack:
Drain to stack: st=[4,3,2,1] (top=4)... actually pushing 1,2,3,4 in order gives top=4
                pop order from queue: 1,2,3,4 pushed -> st top is 4
Refill queue from stack (pop 4,3,2,1): q=[4,3,2,1]

Result: [4,3,2,1]
```

### Time Complexity: O(n) for both approaches.
### Space Complexity: O(n) — auxiliary stack, or O(n) call stack depth for the recursive version.

### Edge Cases
- Empty queue → reversal is a no-op.
- Single element → unchanged after reversal.

### Common Mistakes
- Attempting in-place reversal without any auxiliary structure — not possible with pure FIFO operations alone; some auxiliary space (stack, or recursion's call stack) is mathematically required.

### Interview Notes
A great follow-up question after this one: "Can you do it without an explicit stack?" — the recursive solution answers that (though it secretly uses the call stack, which is a fair point to raise).

---

## 10.9 Implement Stack Using Queues

### Problem Statement
Implement a Stack (LIFO) using only Queue (FIFO) operations.

### Intuition
**Approach A (costly push):** On every `push`, add the new element, then rotate the queue so the newly added element moves to the front — this makes `pop`/`top` O(1) but `push` O(n).
**Approach B (costly pop):** Push normally (O(1)), but to `pop`/`top`, dequeue all-but-last into a second queue, then swap — `push` O(1), `pop`/`top` O(n).

### Optimal Approach (Costly Push — most commonly asked)

```cpp
class StackUsingQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() { q.pop(); }              // front is always the most recently pushed
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};
```

### Dry Run (push 1, push 2, push 3)
```text
push(1): q=[1]
push(2): q=[1,2] -> rotate 1 time: push front(1), pop -> q=[2,1]
push(3): q=[2,1,3] -> rotate 2 times:
           push front(2), pop -> q=[1,3,2]
           push front(1), pop -> q=[3,2,1]
top() = 3  (correct! last pushed is "on top")
pop() removes 3 -> q=[2,1]
top() = 2  (correct, matches stack LIFO order)
```

### Time Complexity: push O(n), pop O(1), top O(1).
### Space Complexity: O(n).

### Edge Cases
- Single push then immediate pop → trivially correct.
- Many pushes in a row → each push costs progressively up to O(n), so n pushes total O(n²).

### Common Mistakes
- Rotating the wrong number of times (`size() - 1` is correct — rotate everything **except** the just-pushed element to the back).
- Forgetting that `top()`/`pop()` simply map to `front()`/`pop()` of the underlying queue once the invariant (front = most recent) is maintained.

### Interview Notes
Always ask the interviewer whether `push` or `pop` should be the cheap operation — this signals you understand the fundamental tradeoff, and there are two equally valid designs.

---

## 10.10 Implement Queue Using Stacks

### Problem Statement
Implement a Queue (FIFO) using only Stack (LIFO) operations.

### Intuition
Use two stacks: an "in-stack" for incoming elements (O(1) push) and an "out-stack" for outgoing elements. When the out-stack is empty and a dequeue/front is requested, transfer all elements from in-stack to out-stack (which reverses their order back to FIFO order) — this transfer is **amortized O(1)** because each element is moved at most twice in its lifetime (once into in-stack, once into out-stack).

### Optimal Approach (Amortized O(1))

```cpp
class QueueUsingStacks {
    stack<int> inStack, outStack;

    void transfer() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
public:
    void enqueue(int x) {
        inStack.push(x);
    }
    void dequeue() {
        transfer();
        outStack.pop();
    }
    int front() {
        transfer();
        return outStack.top();
    }
    bool empty() { return inStack.empty() && outStack.empty(); }
};
```

### Dry Run
```text
enqueue(1): inStack=[1]
enqueue(2): inStack=[1,2]
enqueue(3): inStack=[1,2,3]

front(): outStack empty -> transfer: pop 3,2,1 from inStack, push to outStack
         outStack=[1,2,3] (top=1, since reversed)... 
         wait: popping inStack gives 3,2,1 in that order, pushing each onto outStack:
         push 3 -> outStack=[3]; push 2 -> outStack=[3,2]; push 1 -> outStack=[3,2,1]
         outStack.top() = 1  -> correct! (1 was enqueued first)

dequeue(): outStack not empty, skip transfer, pop top(1) -> outStack=[3,2]
enqueue(4): inStack=[4]
front(): outStack not empty (still has [3,2]) -> no transfer -> top=2 (correct, 2 was enqueued 2nd, still pending)
```

### Time Complexity: enqueue O(1) always; dequeue/front **amortized** O(1) (worst-case single call O(n), but total cost across n operations is O(n)).
### Space Complexity: O(n).

### Edge Cases
- Interleaved enqueue/dequeue calls — verify the transfer-only-when-empty rule still preserves correct FIFO order (it does, by design).
- Empty queue → `dequeue()`/`front()` on an empty structure must check `empty()` first.

### Common Mistakes
- Transferring on **every** dequeue call instead of only when `outStack` is empty — this degrades performance to O(n) per operation instead of amortized O(1).
- Forgetting the `empty()` check combines **both** stacks (`inStack.empty() && outStack.empty()`), not just one.

### Interview Notes
This is the single most commonly asked "implement X using Y" queue/stack interview question (LeetCode 232). The **amortized analysis** explanation ("each element is pushed and popped at most twice across its lifetime, so total work is O(n) for n operations") is exactly what separates a strong answer from an average one — always say this part out loud.

---

# SECTION 11: SPECIAL QUEUES

## 11.1 Circular Queue

Already covered in full depth in **Section 4**. Summary: fixed-capacity array queue using modulo-wrapped indices for O(1) enqueue/dequeue with full space reuse.

**Complexity:** All core ops O(1). **Dry run:** see Section 4.8.

## 11.2 Deque

Already covered in full depth in **Section 5**. Summary: double-ended queue allowing O(1) insertion/removal at both front and rear.

**Complexity:** All core ops O(1). **Dry run:** see Section 5.7.

## 11.3 Priority Queue

Already covered in full depth in **Section 9**. Summary: heap-based structure where removal order is determined by priority, not arrival order.

**Complexity:** Insert/remove O(log n), peek O(1). **Dry run:** see Section 9.7.

## 11.4 Input Restricted Deque

### Design
A deque variant where **insertion is allowed only at one end** (typically the rear), but **deletion is allowed at both ends**.

```text
        insert here only
                v
        Front -> [10][20][30] <- Rear
          ^                ^
       delete OK        delete OK
```

```cpp
class InputRestrictedDeque {
    deque<int> dq;
public:
    void insertRear(int x) { dq.push_back(x); }   // only allowed insertion point
    void deleteFront() { if (!dq.empty()) dq.pop_front(); }
    void deleteRear()  { if (!dq.empty()) dq.pop_back(); }
};
```

**Complexity:** All exposed ops O(1).
**Dry Run:**
```text
insertRear(1) -> [1]
insertRear(2) -> [1,2]
insertRear(3) -> [1,2,3]
deleteFront()  -> [2,3]
deleteRear()   -> [2]
```

## 11.5 Output Restricted Deque

### Design
The mirror image: **insertion allowed at both ends**, but **deletion allowed only at one end** (typically the front).

```text
   insert OK              insert OK
        v                      v
   Front -> [10][20][30] <- Rear
     ^
  delete here only
```

```cpp
class OutputRestrictedDeque {
    deque<int> dq;
public:
    void insertFront(int x) { dq.push_front(x); }
    void insertRear(int x)  { dq.push_back(x); }
    void deleteFront()      { if (!dq.empty()) dq.pop_front(); }  // only allowed deletion point
};
```

**Complexity:** All exposed ops O(1).
**Dry Run:**
```text
insertRear(1)  -> [1]
insertFront(2) -> [2,1]
insertRear(3)  -> [2,1,3]
deleteFront()   -> [1,3]
```

## 11.6 Double Ended Priority Queue (DEPQ)

### Design
A structure that supports efficient access and removal of **both** the minimum and maximum elements — effectively a priority queue with two "ends" of priority instead of one.

### Common Implementation Strategies
1. **Two heaps** (a min-heap and a max-heap) with cross-references — complex to keep in sync.
2. **`std::multiset`** in C++ — supports O(log n) insert, and O(1) access to both `*begin()` (min) and `*rbegin()` (max), with O(log n) erase.

```cpp
multiset<int> depq;
depq.insert(10);
depq.insert(30);
depq.insert(20);

cout << *depq.begin();   // min -> 10
cout << *depq.rbegin();  // max -> 30

depq.erase(depq.begin());   // remove min
depq.erase(prev(depq.end())); // remove max
```

**Complexity:** Insert O(log n), get-min/get-max O(1), remove-min/remove-max O(log n).

### Applications
Finding both the cheapest and most expensive item efficiently in a dynamic dataset, median-maintenance-adjacent problems, certain dual-priority scheduling systems.

## 11.7 Multiple Queues in One Array

### Design
When memory must be shared between `k` queues using a single fixed-size array (common in embedded systems / low-level systems design questions), the array is logically divided into `k` equal (or dynamically managed) segments, each with its own `front`/`rear` pointers, optionally combined with circular wrap-around per segment.

```text
Array of size 12, divided for 3 queues (k=3), each gets 4 slots:

Queue 1: indices [0..3]
Queue 2: indices [4..7]
Queue 3: indices [8..11]

[Q1_0][Q1_1][Q1_2][Q1_3] [Q2_0][Q2_1][Q2_2][Q2_3] [Q3_0][Q3_1][Q3_2][Q3_3]
```

### Simple Fixed-Partition Implementation

```cpp
class MultipleQueues {
    vector<int> arr;
    vector<int> front, rear, size;
    int segmentSize;
public:
    MultipleQueues(int totalSize, int k) {
        arr.resize(totalSize);
        segmentSize = totalSize / k;
        front.assign(k, 0);
        rear.assign(k, -1);
        size.assign(k, 0);
    }
    bool enqueue(int qid, int x) {
        if (size[qid] == segmentSize) return false; // overflow for this queue
        rear[qid] = (rear[qid] + 1) % segmentSize;
        int actualIndex = qid * segmentSize + rear[qid];
        arr[actualIndex] = x;
        size[qid]++;
        return true;
    }
    bool dequeue(int qid) {
        if (size[qid] == 0) return false; // underflow for this queue
        front[qid] = (front[qid] + 1) % segmentSize;
        size[qid]--;
        return true;
    }
};
```

**Complexity:** O(1) per operation, fixed-capacity tradeoff per queue (a more advanced dynamic-partition design allows queues to "borrow" space from each other but adds significant complexity — typically out of scope for standard interviews).

### Applications
Memory-constrained embedded systems, simulating multiple independent FIFO buffers within one allocated memory block (e.g., multiple network connection buffers sharing one fixed pool).

---

# SECTION 12: QUEUE APPLICATIONS

## 12.1 CPU Scheduling

Operating systems maintain a **ready queue** of processes waiting for CPU time. In simple **Round-Robin scheduling**, each process gets a fixed time slice (quantum); if it doesn't finish, it's re-enqueued at the rear — this is a direct, literal use of a (often circular) queue.

```text
Ready Queue: [P1][P2][P3][P4]
P1 runs for quantum, doesn't finish -> re-enqueued at rear: [P2][P3][P4][P1]
```

## 12.2 Printer Queue (Spooling)

Print jobs submitted by multiple users are placed in a queue and printed strictly in the order received — ensuring fairness ("first come, first served") regardless of which user or document is larger.

## 12.3 Call Center Queue

Incoming calls wait in a FIFO queue until an agent becomes available. Some real systems combine this with a **priority queue** for VIP/escalated callers — a great real-world example of combining Section 7's FIFO pattern with Section 9's priority pattern.

## 12.4 Task Scheduling

Background job systems (e.g., cron-like task runners, simple worker pools) often use a queue to hold pending tasks; workers dequeue tasks as they become free, guaranteeing tasks are processed roughly in submission order.

## 12.5 Order Processing Systems

E-commerce platforms typically process orders in arrival order to maintain fairness (and avoid disputes over "why was a later order fulfilled before mine") — a queue (sometimes a distributed message queue) ensures this.

## 12.6 Buffer Management

Any system bridging a fast producer and a slower consumer (or vice versa) uses a queue as a buffer to smooth out speed mismatches without losing data — see Pattern 8 (Producer-Consumer, Section 7).

## 12.7 Keyboard Buffer

Keystrokes are placed into a queue as they're typed; the application processes/echoes them in the same order, even if it momentarily lags behind fast typing.

## 12.8 Network Packet Scheduling

Routers and switches buffer incoming packets in queues before forwarding; in more advanced systems, multiple priority queues handle different traffic classes (e.g., QoS — Quality of Service — uses priority queues to make sure latency-sensitive traffic like VoIP jumps ahead of bulk file transfers).

## 12.9 Streaming Systems

Real-time data pipelines (e.g., processing live sensor data, video frame buffers, or financial market ticks) rely heavily on bounded queues to hold incoming data for processing without overwhelming downstream consumers — directly related to Pattern 10 (Stream Processing, Section 7) and Pattern 8 (Producer-Consumer).

## 12.10 Summary Table

| Domain | Queue Role |
|---|---|
| Operating Systems | Ready queue for CPU scheduling |
| Printing | Spooler maintains print-job order |
| Telephony | Call queue ensures fair, ordered handling |
| Job Systems | Background task queues |
| E-commerce | Order processing fairness |
| I/O Systems | Buffering between producer/consumer speed mismatches |
| Input Devices | Keyboard/input event buffering |
| Networking | Packet buffering and QoS scheduling |
| Data Engineering | Streaming pipelines and message brokers |

---

# SECTION 13: INTERVIEW FRAMEWORK

## 13.1 How to Identify a Queue Problem

Ask yourself, in order:

1. **Does the problem care about the order things arrived/were processed?** → Likely FIFO / Queue.
2. **Does it need access to both the oldest and newest elements?** → Deque.
3. **Does "importance"/"priority" matter more than arrival order?** → Priority Queue.
4. **Does it involve simultaneous spreading from multiple starting points (grids, graphs, infection-style spread)?** → Multi-source BFS with Queue.
5. **Does it ask for max/min over every sliding window?** → Monotonic Deque.
6. **Does it describe a literal real-world queue (ticket counter, scheduling, simulation)?** → Direct Queue simulation.

## 13.2 Decision Tree

```text
                  Read the problem statement
                            │
            ┌───────────────┴────────────────┐
            ▼                                 ▼
   "process in arrival                "need ends/priority/
    order" (FIFO)?                     window logic"?
            │                                 │
            ▼                  ┌──────────────┼───────────────┐
       Use QUEUE                ▼              ▼               ▼
                       "both ends      "priority-based   "max/min over
                        matter"?        removal"?          window of size k"?
                            │               │                   │
                            ▼               ▼                   ▼
                       Use DEQUE     Use PRIORITY QUEUE   Use MONOTONIC DEQUE


   "multiple starting points spreading simultaneously
    (grid/graph, infection-style)"?
            │
            ▼
   Use QUEUE (Multi-Source BFS)


   "scheduling with cooldowns / repeated tasks"?
            │
            ▼
   Use QUEUE + HASH MAP (or + PRIORITY QUEUE for frequency-based scheduling)
```

## 13.3 Quick-Reference Rules

| If the problem says... | Use |
|---|---|
| "first come first serve" / "process in order" | Queue |
| "sliding window maximum/minimum" | Monotonic Deque |
| "stream of data, process as it arrives" | Queue (Stream Processing pattern) |
| "highest priority first" / "k largest/smallest" | Priority Queue |
| "scheduling" / "cooldown between repeats" | Queue (+ Hash Map / Priority Queue) |
| "nearest greater/smaller while scanning" | Monotonic Queue/Deque |
| "spreads from multiple sources simultaneously" | Queue (Multi-Source BFS) |
| "fixed-size buffer that reuses freed space" | Circular Queue |
| "both ends of data matter" | Deque |

## 13.4 Complete Interview Roadmap

```text
STEP 1: Clarify constraints
  - What's the input size? (affects whether O(n log n) is acceptable vs needing O(n))
  - Is there a fixed capacity, or is it unbounded?
  - Do duplicates matter? Negative numbers? Empty input?

STEP 2: Identify the pattern (use Section 13.2's decision tree)

STEP 3: State your chosen data structure OUT LOUD with justification
  - "I'll use a monotonic deque here because we need O(n) sliding window max"

STEP 4: Write the brute force first (if time allows) to validate understanding,
         then optimize to the pattern-based solution

STEP 5: Dry run on a small example BEFORE coding (catches logic errors early)

STEP 6: Code the solution, narrating as you go

STEP 7: State time and space complexity explicitly at the end

STEP 8: Test edge cases out loud: empty input, single element, all duplicates,
         maximum window size, k = 0 or k = n
```

## 13.5 What Interviewers Are Actually Listening For

- Did the candidate immediately reach for a queue/deque, or did they brute-force without recognizing the pattern?
- Did they correctly distinguish "value" vs "index" storage in monotonic deque problems (a very common trip-up)?
- Did they discuss amortized complexity correctly (e.g., Section 10.10's two-stack queue)?
- Did they handle empty/edge cases proactively, not just when prompted?

---

# SECTION 14: QUEUE IN ARRAYS & STRINGS

Queues (especially deques) are one of the most powerful tools for solving array and string problems efficiently. This section consolidates how queue-based thinking maps onto these problem types.

## 14.1 Sliding Window Maximum (Array)

Covered fully in **Section 8.1**. The array is treated as a stream; a monotonic decreasing deque of indices tracks the max in O(n) total.

## 14.2 Sliding Window Minimum (Array)

Covered fully in **Section 8.2**. Mirror of 14.1 using a monotonic increasing deque.

## 14.3 Stream Characters (String)

Treating a string as an incoming stream (character by character) and maintaining queue-based state (Section 7, Pattern 10) is the core technique behind many "process as you go" string problems.

```cpp
// General template for stream-based string processing
queue<char> q;
for (char c : streamString) {
    q.push(c);
    // update auxiliary state (frequency map, etc.)
    // evict invalid front candidates if needed
    // record answer for this point in the stream
}
```

## 14.4 First Non-Repeating Character (String)

Covered fully in **Section 10.2**. A queue of "still-unique" candidate characters, updated as the string streams in.

## 14.5 Window-Based Problems — General Recipe

Most array/string "window" problems (fixed-size or variable-size) follow this general recipe:

```text
1. Decide: does the window need MAX/MIN tracking? -> Monotonic Deque
   does it need frequency tracking only?            -> Queue + Hash Map
   does it need both ends accessible?                -> Deque

2. Slide the window by:
   a. Adding the new right-edge element (update state)
   b. Removing left-edge elements that fall outside the window (update state)

3. Record the answer once the window reaches valid size
```

### Worked Example: Maximum Sum Subarray of Size K (Queue-Adjacent, for contrast)

This particular problem doesn't need a queue at all — it's solved with a simple running-sum sliding window — included here specifically to show **when NOT to reach for a queue/deque**:

```cpp
int maxSumSubarray(vector<int>& nums, int k) {
    int windowSum = 0, maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        windowSum += nums[i];
        if (i >= k - 1) {
            maxSum = max(maxSum, windowSum);
            windowSum -= nums[i - k + 1];
        }
    }
    return maxSum;
}
```

**Why no deque here:** We only need a running **sum**, not the max/min *individual element* within the window — a simple accumulator suffices. Recognizing this distinction (sum vs extremum tracking) avoids unnecessary over-engineering in interviews.

## 14.6 Summary: Array/String Problem → Queue Structure Mapping

| Problem Type | Structure |
|---|---|
| Max/Min in every window of size k | Monotonic Deque |
| First non-repeating char in stream | Queue + frequency map |
| Multi-source spread over a grid/string positions | Queue (BFS-style) |
| Running sum/average over window | Plain accumulator (no queue needed) |
| Need both window bounds simultaneously accessible | Deque |

---

# SECTION 15: COMMON TRICKS

## 15.1 Circular Queue Tricks

- Use an explicit `size` counter instead of trying to disambiguate `front == rear` for both empty and full — avoids the classic "sacrifice one slot" workaround entirely.
- For an O(1) "clear" operation, just reset `front = 0; rear = -1; size = 0;` rather than physically erasing data — stale values are simply overwritten on future enqueues.
- When capacity needs to grow dynamically, allocate a new larger array, then copy elements out **starting from `front`, wrapping as needed** — don't naively `memcpy` the raw array, since the data may currently be split across the wrap-around boundary.

## 15.2 Deque Tricks

- A deque can simulate **both** a stack and a queue — if you're unsure whether a future requirement might need both-end access, defaulting to `deque` over `queue` is a safe forward-compatible choice.
- For "remove from middle" type requirements, a plain deque is still O(n) — if frequent middle deletions are needed, consider a different structure (e.g., a doubly linked list with direct node pointers) instead of forcing a deque to do something it's not optimized for.

## 15.3 Monotonic Queue Tricks

- Always decide upfront: are you storing **values** or **indices**? Storing indices is almost always correct because it lets you detect "has this element fallen out of the window" — storing raw values loses that information.
- Pick strict (`<`/`>`) vs non-strict (`<=`/`>=`) comparisons deliberately when evicting from the back — this determines how duplicate values are handled, and the choice should be consistent throughout the algorithm.
- The front-eviction check (`dq.front() <= i - k`) should always be a `while` in theory, but since at most one index falls out per step in a fixed-step sliding window, an `if` is equivalent and slightly clearer — just be aware it must become a `while` if the window can shrink by more than one position per step.

## 15.4 Sliding Window Tricks

- Distinguish whether you need the window's **extremum** (→ monotonic deque) or an **aggregate** like sum/count/average (→ simple running accumulator, Section 14.5) — using a deque when a running sum would do is unnecessary overhead.
- For variable-size windows (expand/shrink based on a condition), a deque is still useful, but the eviction condition changes from "index out of fixed range" to "condition violated" — adapt the front-eviction check accordingly.

## 15.5 Priority Queue Tricks

- Remember the C++ STL `priority_queue` comparator is **inverted** relative to `sort()` — `cmp(a,b) = true` means "a has lower priority", the opposite of "a should come first" in sort semantics.
- For a quick min-heap of `pair<int,int>`, use `greater<pair<int,int>>` directly with the default pair comparison (lexicographic) instead of writing a custom comparator, when that ordering happens to suffice.
- Lazy deletion (Section 8.1's heap-based sliding-window-max example) is a powerful trick: instead of removing stale elements immediately, just check and discard them when they reach the top — useful whenever true removal from the middle of a heap would otherwise be expensive.

## 15.6 Simulation Tricks

- When simulating a process described step-by-step in the problem statement, **trust the literal description first** — write the brute-force simulation exactly as described before trying to find a clever shortcut; this guarantees correctness and often reveals the pattern needed for optimization.
- For circular/repeating simulations (e.g., "what's the state after k rounds"), check whether the state eventually **cycles** — if so, you can compute `k % cycle_length` instead of literally simulating all k steps, turning an O(k) simulation into O(cycle_length).

---

# SECTION 16: COMMON MISTAKES

## 16.1 Queue Overflow

**Mistake:** Enqueuing into a fixed-capacity queue without checking `isFull()` first, causing silent data corruption or out-of-bounds writes.

```cpp
// WRONG — no overflow check
void enqueue(int x) { arr[++rear] = x; }

// CORRECT
void enqueue(int x) {
    if (isFull()) { /* handle overflow */ return; }
    arr[++rear] = x;
}
```

## 16.2 Queue Underflow

**Mistake:** Calling `dequeue()`, `front()`, or `rear()` on an empty queue without checking `isEmpty()` first.

```cpp
// WRONG
int val = q.front();   // undefined behavior if q is empty!
q.pop();

// CORRECT
if (!q.empty()) {
    int val = q.front();
    q.pop();
}
```

## 16.3 Circular Queue Index Errors

**Mistake:** Forgetting to apply `% capacity` when advancing `front`/`rear`, or applying it inconsistently between the two.

```cpp
// WRONG — will go out of bounds once rear hits capacity-1
rear = rear + 1;

// CORRECT
rear = (rear + 1) % capacity;
```

**Mistake:** Trying to distinguish full vs empty using only `front == rear` without an explicit size counter — leads to ambiguous states.

## 16.4 Deque Boundary Errors

**Mistake:** Calling `pop_front()`/`pop_back()` on an empty deque.

```cpp
// WRONG
dq.pop_front();   // undefined behavior if dq is empty

// CORRECT
if (!dq.empty()) dq.pop_front();
```

**Mistake:** Mixing up `push_front`/`push_back` direction, silently producing reversed results — always sanity-check with a 3-element dry run before trusting deque-heavy code.

## 16.5 Priority Queue Comparator Mistakes

**Mistake:** Writing the comparator with `sort()` semantics (true = "a before b") instead of `priority_queue` semantics (true = "a has lower priority").

```cpp
// If you want a MIN-heap and write this thinking "true = a comes first":
struct Cmp {
    bool operator()(int a, int b) { return a < b; }  // WRONG for min-heap! This makes a MAX-heap.
};

// CORRECT for min-heap:
struct Cmp {
    bool operator()(int a, int b) { return a > b; }  // true = a has LOWER priority than b
};
```

**Mistake:** Forgetting the three-argument template form when declaring a non-default-ordered priority queue — `priority_queue<int, vector<int>, greater<int>>` not `priority_queue<int, greater<int>>` (the latter is a compile error).

## 16.6 Sliding Window Bugs

**Mistake:** Storing values instead of indices in a monotonic deque, losing the ability to detect when the window-max/min has expired.

**Mistake:** Recording the window answer (`result.push_back(...)`) before the window has actually reached size `k` — always gate this with `if (i >= k - 1)`.

**Mistake:** Using `<=` vs `<` inconsistently when evicting from the back of a monotonic deque, leading to subtly wrong results specifically on inputs with duplicate values — always test duplicate-heavy inputs explicitly.

## 16.7 Master Mistake-Avoidance Checklist

| Before submitting, verify... |
|---|
| Every `dequeue`/`front`/`pop_front`/`pop_back` is guarded by an emptiness check |
| Every fixed-capacity `enqueue` is guarded by a fullness check |
| Circular index math uses `% capacity` consistently on every pointer update |
| Monotonic deque stores indices, not raw values |
| Priority queue comparator direction was sanity-checked with a 2-element example |
| Edge cases tested: empty input, single element, k=0, k=n, all-duplicate values |

---

# SECTION 17: COMPLETE QUEUE QUESTION LIST

> **A note on this list:** Rather than padding with low-quality or unverifiable entries, this is a carefully curated, verified set of the highest-value Queue/Deque/Priority-Queue problems spanning every pattern in this handbook (Section 7). Use it as your core practice set — mastering these will prepare you for the vast majority of OA and interview queue questions, including unfamiliar variants. Problem numbers refer to LeetCode unless marked **GFG**.

## Easy

| Problem Name | Platform | Pattern Used | Key Idea |
|---|---|---|---|
| Implement Stack using Queues (LC 225) | LeetCode | Stack-Queue Interop (10.9) | Rotate queue after each push so newest element sits at front |
| Implement Queue using Stacks (LC 232) | LeetCode | Stack-Queue Interop (10.10) | Two stacks, amortized O(1) transfer only when out-stack is empty |
| Moving Average from Data Stream (LC 346) | LeetCode | Stream Processing (P10) | Fixed-size queue + running sum, evict oldest on overflow |
| Number of Recent Calls (LC 933) | LeetCode | Stream Processing (P10) | Queue as a sliding time window; evict timestamps outside range |
| Kth Largest Element in a Stream (LC 703) | LeetCode | Priority Queue (Sec 9) | Maintain a min-heap of size k; root is the answer |
| Last Stone Weight (LC 1046) | LeetCode | Priority Queue (Sec 9) | Max-heap; repeatedly smash the two largest stones |
| Relative Ranks (LC 506) | LeetCode | Priority Queue (Sec 9) | Max-heap of (score, index) pairs to assign medal ranks |
| Time Needed to Buy Tickets (LC 2073) | LeetCode | Basic FIFO Simulation (P1) | Simulate the circular line, or shortcut with per-person math |
| Number of Students Unable to Eat Lunch (LC 1700) | LeetCode | Basic FIFO Simulation (P1) | Simulate queue+stack interplay; detect a full no-progress cycle |
| Find the Winner of the Circular Game (LC 1823) | LeetCode | Circular Queue (Sec 4) | Rotate-and-eliminate using a circular structure (Josephus-style) |
| First Unique Character in a String (LC 387) | LeetCode | Stream Processing (P10) | Same core idea as Section 10.2, applied to a static string |
| Generate Binary Numbers from 1 to N | GFG | Basic FIFO Simulation (P1) | BFS-style string generation; FIFO order guarantees sorted output |
| Reverse a Queue | GFG | Stack-Queue Interop | Drain into a stack, refill — see Section 10.8 |

## Medium

| Problem Name | Platform | Pattern Used | Key Idea |
|---|---|---|---|
| Design Circular Queue (LC 622) | LeetCode | Circular Queue (Sec 4) | Modulo-wrapped front/rear with explicit size counter |
| Design Circular Deque (LC 641) | LeetCode | Circular Queue + Deque (Sec 4, 5) | Combine modulo wrap-around with double-ended operations |
| Design Front Middle Back Queue (LC 1670) | LeetCode | Deque Pattern (P3) | Two deques split at the midpoint, rebalanced on every op |
| Dota2 Senate (LC 649) | LeetCode | Circular Queue / Simulation | Two queues of indices; re-enqueue surviving senator with `+n` to preserve round order |
| Task Scheduler (LC 621) | LeetCode | Scheduling (P9) | Greedy/heap-based cooldown tracking of most frequent task |
| Rotting Oranges (LC 994) | LeetCode | Multi-Source Processing (P6) | Seed queue with ALL initial rotten cells, BFS level-by-level |
| 01 Matrix (LC 542) | LeetCode | Multi-Source Processing (P6) | Seed queue with all zero-cells, BFS outward for shortest distance |
| Reveal Cards In Increasing Order (LC 950) | LeetCode | Simulation (P7) | Reverse-simulate the reveal process using a queue of indices |
| Jump Game VI (LC 1696) | LeetCode | Monotonic Queue (P5) | Monotonic decreasing deque of best-DP-value indices in window k |
| Top K Frequent Elements (LC 347) | LeetCode | Priority Queue (Sec 9) | Min-heap of size k ordered by frequency |
| Kth Largest Element in an Array (LC 215) | LeetCode | Priority Queue (Sec 9) | Min-heap of size k, or quickselect as an alternative |
| K Closest Points to Origin (LC 973) | LeetCode | Priority Queue (Sec 9) | Max-heap of size k ordered by distance |
| Design Hit Counter (LC 362) | LeetCode | Stream Processing (P10) | Queue of timestamps; evict entries older than 300s |
| Meeting Rooms II (LC 253) | LeetCode | Scheduling / Priority Queue | Min-heap of meeting end-times to track concurrent rooms needed |
| Top K Frequent Words (LC 692) | LeetCode | Priority Queue (Sec 9) | Heap with custom comparator: frequency desc, then lexicographic |
| Reorganize String (LC 767) | LeetCode | Priority Queue (Sec 9) | Max-heap by frequency; alternate placement to avoid adjacency |
| Longest Subarray With Absolute Diff ≤ Limit (LC 1438) | LeetCode | Monotonic Deque (Sec 8) | Two monotonic deques (max & min) tracked simultaneously over the window |
| Continuous Subarrays (LC 2762) | LeetCode | Monotonic Deque (Sec 8) | Two monotonic deques maintain max/min for the "diff ≤ 2" window condition |
| Gas Station (LC 134) | LeetCode | Circular Tour (Sec 10.4) | Greedy O(n) deficit-tracking, conceptually a circular traversal |
| Reverse First K Elements of Queue | GFG | Stack-Queue Interop (10.7) | Stack-reverse first k, then rotate the remainder around |
| Interleave First Half of Queue with Second Half | GFG | Deque Pattern (P3) | Auxiliary queue + controlled push/pop interleaving (Sec 10.6) |
| First Negative Integer in Every Window of Size K | GFG | Monotonic Queue (Sec 8.3) | Plain FIFO of negative-value indices, evict on window exit |
| Sliding Window Minimum | GFG | Monotonic Deque (Sec 8.2) | Mirror of Sliding Window Maximum with increasing order |

## Hard

| Problem Name | Platform | Pattern Used | Key Idea |
|---|---|---|---|
| Sliding Window Maximum (LC 239) | LeetCode | Monotonic Deque (Sec 8.1) | Strictly decreasing deque of indices, O(n) amortized |
| Shortest Subarray with Sum at Least K (LC 862) | LeetCode | Monotonic Deque (Sec 8) | Monotonic deque over prefix sums to find shortest valid window |
| Constrained Subsequence Sum (LC 1425) | LeetCode | Monotonic Deque (Sec 8) | Deque tracks max DP value within the last k positions |
| Max Value of Equation (LC 1499) | LeetCode | Monotonic Deque (Sec 8) | Deque maintains best `(yi - xi)` candidate within the x-distance constraint |
| Find Median from Data Stream (LC 295) | LeetCode | Double-Ended Priority Queue (Sec 11.6) | Two heaps (max-heap for lower half, min-heap for upper half) |
| Sliding Window Median (LC 480) | LeetCode | Double-Ended Priority Queue + Sliding Window | Balanced two-heap structure with lazy deletion as the window slides |
| Merge K Sorted Lists (LC 23) | LeetCode | Priority Queue (Sec 9) | Min-heap holding the current head of each list, pop-and-advance |
| Process Tasks Using Servers (LC 1882) | LeetCode | Scheduling + Priority Queue | Two heaps (free servers, busy servers) drive task assignment |
| Minimum Interval to Include Each Query (LC 1851) | LeetCode | Priority Queue + Sweep | Min-heap of interval end-points, processed alongside sorted queries |

---

# SECTION 18: REVISION CHEAT SHEET

## 18.1 Queue Cheat Sheet

```text
FIFO: First In, First Out
enqueue -> Rear   |   dequeue -> Front
std::queue<int> q;
q.push(x);   q.pop();   q.front();   q.back();   q.empty();   q.size();
```

| Implementation | Enqueue | Dequeue | When To Use |
|---|---|---|---|
| Circular Array | O(1) | O(1) | Known fixed capacity |
| Linked List | O(1) | O(1) | Unknown/unbounded size |
| STL queue | O(1) | O(1) | Default choice in C++ |

## 18.2 Circular Queue Cheat Sheet

```text
rear = (rear + 1) % capacity
front = (front + 1) % capacity
isFull()  ⇔ size == capacity
isEmpty() ⇔ size == 0
```
Always maintain an explicit `size` counter — never rely on `front == rear` alone.

## 18.3 Deque Cheat Sheet

```text
std::deque<int> dq;
dq.push_front(x); dq.push_back(x);
dq.pop_front();    dq.pop_back();
dq.front();        dq.back();
dq[i];              // O(1) random access
```
All core ops O(1). Use whenever both ends matter, or to implement a monotonic structure.

## 18.4 Priority Queue Cheat Sheet

```text
// Max-heap (default)
priority_queue<int> maxHeap;

// Min-heap
priority_queue<int, vector<int>, greater<int>> minHeap;

push() -> O(log n)   pop() -> O(log n)   top() -> O(1)
```
Comparator returns `true` if the first argument has **lower** priority — opposite of `sort()`.

## 18.5 Complexity Cheat Sheet

| Operation | Queue | Circular Queue | Deque | Priority Queue |
|---|---|---|---|---|
| Insert | O(1) | O(1) | O(1) (either end) | O(log n) |
| Remove | O(1) | O(1) | O(1) (either end) | O(log n) |
| Peek | O(1) | O(1) | O(1) | O(1) |
| Search | O(n) | O(n) | O(n) | O(n) |

## 18.6 Sliding Window Maximum Template (Memorize)

```cpp
vector<int> slidingWindowMax(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}
```

## 18.7 Monotonic Queue Template (General Form)

```cpp
deque<int> dq;   // indices
for (int i = 0; i < n; i++) {
    while (!dq.empty() && dq.front() <= i - k) dq.pop_front();   // out of window
    while (!dq.empty() && /* arr[dq.back()] dominated by arr[i] */) dq.pop_back();
    dq.push_back(i);
    if (i >= k - 1) /* dq.front() holds the answer for this window */;
}
```

## 18.8 One-Page Pattern Lookup

| Symptom in Problem | Reach For |
|---|---|
| "process in order received" | Queue |
| "fixed buffer, reuse space" | Circular Queue |
| "both ends matter" | Deque |
| "max/min in every window of size k" | Monotonic Deque |
| "highest priority first" / "k largest/smallest" | Priority Queue |
| "stream, react as data arrives" | Queue (Stream Processing) |
| "spreads from multiple sources at once" | Queue (Multi-Source BFS) |
| "scheduling with cooldown" | Queue + Hash Map / Priority Queue |

---

# SECTION 19: FINAL QUEUE ROADMAP

## 19.1 Beginner → Intermediate → Advanced

```text
┌─────────────────────────────────────────────────────────────────┐
│ BEGINNER                                                          │
│  Sections 1-3: Fundamentals, Implementation, Operations           │
│  Goal: Implement a queue from scratch (array + linked list)       │
├─────────────────────────────────────────────────────────────────┤
│ INTERMEDIATE                                                      │
│  Sections 4-6: Circular Queue, Deque, Complexity Analysis         │
│  Goal: Comfortably solve Design Circular Queue/Deque problems     │
├─────────────────────────────────────────────────────────────────┤
│ ADVANCED                                                           │
│  Sections 7-11: Patterns, Monotonic Deque, Priority Queue,        │
│  Core Algorithms, Special Queues                                  │
│  Goal: Recognize and solve any sliding-window/scheduling/         │
│  multi-source problem in optimal time                             │
├─────────────────────────────────────────────────────────────────┤
│ INTERVIEW-READY                                                    │
│  Sections 12-18: Applications, Interview Framework, Tricks,       │
│  Mistakes, Practice List, Cheat Sheets                            │
│  Goal: Pattern-match any new problem within the first minute      │
└─────────────────────────────────────────────────────────────────┘
```

## 19.2 What to Study First

1. FIFO principle and queue terminology (1.1 – 1.4)
2. Queue using array, then circular array (2.1 – 2.2)
3. Queue using linked list (2.3)
4. STL `queue` and `deque` usage (2.4 – 2.5)
5. All core operations with edge cases (Section 3)

## 19.3 What to Practice Next

1. Circular Queue full mastery — implement from memory (Section 4)
2. Deque operations and applications (Section 5)
3. Implement Stack using Queues, and Queue using Stacks (Section 10.9 – 10.10)
4. First Non-Repeating Character in Stream, Rotten Oranges (Section 10.2 – 10.3)

## 19.4 Advanced Practice (Interview/OA Stage)

1. Monotonic Deque mastery — Sliding Window Maximum/Minimum until it's automatic (Section 8)
2. Priority Queue — custom comparators, pair priority queues (Section 9)
3. Full pattern recognition drills using the Decision Tree (Section 13.2)
4. Work through the entire Practice Question List (Section 17), timing yourself

## 19.5 Weekly Learning Plan (4-Week Track)

| Week | Focus | Sections | Goal |
|---|---|---|---|
| 1 | Fundamentals + Implementations | 1, 2, 3 | Implement Queue from scratch in 3 ways |
| 2 | Circular Queue + Deque | 4, 5, 6 | Solve Design Circular Queue/Deque confidently |
| 3 | Patterns + Monotonic Deque + Priority Queue | 7, 8, 9 | Solve Sliding Window Maximum without hints |
| 4 | Algorithms + Interview Prep | 10, 11, 12, 13 | Solve 5 algorithms (Section 10) from memory |

## 19.6 Weekly Revision Plan (Pre-Interview, 1 Week)

| Day | Focus |
|---|---|
| Day 1 | Re-read Section 18 (Cheat Sheets) fully |
| Day 2 | Re-implement Circular Queue and Deque from scratch, no reference |
| Day 3 | Re-derive the Monotonic Deque template and solve 3 sliding-window problems |
| Day 4 | Solve 3 Priority Queue problems with custom comparators |
| Day 5 | Solve 3 algorithms from Section 10 (pick ones you're weakest on) |
| Day 6 | Full mock: solve 5 random problems from Section 17 against the clock |
| Day 7 | Light review of Section 13 (Interview Framework) and Section 16 (Common Mistakes) |

## 19.7 Recommended Problem Order (First-Time Solve Order)

```text
1. Implement Stack using Queues          (10.9)
2. Implement Queue using Stacks           (10.10)
3. Design Circular Queue                  (Section 17, Medium)
4. Number of Recent Calls                 (Section 17, Easy)
5. First Non-Repeating Character          (10.2)
6. Rotten Oranges                         (10.3)
7. Sliding Window Maximum                 (8.1 / Section 17, Hard)
8. Sliding Window Minimum                 (8.2 / Section 17, Medium)
9. Kth Largest Element in a Stream        (Section 17, Easy)
10. Task Scheduler                        (Section 17, Medium)
```

## 19.8 Final Self-Assessment Checklist

Before walking into an interview or OA, you should be able to:

- [ ] Implement a queue from scratch using an array, circular array, and linked list — without looking anything up.
- [ ] Explain why a circular queue is better than a naive array queue, with the exact "false overflow" problem in your own words.
- [ ] Write the monotonic deque template for sliding window maximum from memory, including all four steps.
- [ ] Correctly write both a max-heap and min-heap declaration in C++ STL, including the three-argument form.
- [ ] Implement Stack using Queues AND Queue using Stacks, and explain the complexity tradeoff of each approach.
- [ ] Use the Section 13.2 decision tree to classify a brand-new, unseen problem within 60 seconds.
- [ ] Name at least five real-world systems that use a queue internally, and explain why.

---

## Closing Notes

Queues are deceptively simple at first glance — "just FIFO" — but the depth from Section 4 onward (circular queues, monotonic deques, priority queues, and the ten core patterns) is exactly what separates candidates who can recognize and solve unfamiliar problems quickly from those who can only solve problems they've memorized. Revisit Section 18 the night before any interview or OA, and Section 13 whenever you're stuck pattern-matching a new problem.

**Good luck — and remember: when in doubt, ask "does order of arrival matter, or does priority matter, or do both ends matter?" That single question resolves almost every queue-family decision you'll ever need to make.**