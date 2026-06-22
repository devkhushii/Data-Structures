# 🧵 The Ultimate String Handbook
### From Absolute Beginner to Advanced — Interviews · OA · Competitive Programming · Revision

> **Who is this for?** Complete beginners, intermediate learners, placement prep, OA/competitive programming, technical interviews, and last-minute revision.

---

## 📋 Table of Contents

1. [String Fundamentals](#section-1-string-fundamentals)
2. [String Implementation](#section-2-string-implementation)
3. [String Operations](#section-3-string-operations)
4. [Complexity Analysis](#section-4-complexity-analysis)
5. [Character Manipulation](#section-5-character-manipulation)
6. [String Searching Algorithms](#section-6-string-searching-algorithms)
7. [String Patterns](#section-7-string-patterns)
8. [Palindrome Mastery](#section-8-palindrome-mastery)
9. [Anagram Mastery](#section-9-anagram-mastery)
10. [Substring Mastery](#section-10-substring-mastery)
11. [Important String Algorithms](#section-11-important-string-algorithms)
12. [Sliding Window on Strings](#section-12-sliding-window-on-strings)
13. [Two Pointers on Strings](#section-13-two-pointers-on-strings)
14. [Hashing on Strings](#section-14-hashing-on-strings)
15. [String Sorting & Ordering](#section-15-string-sorting--ordering)
16. [String Interview Framework](#section-16-string-interview-framework)
17. [Common Tricks](#section-17-common-tricks)
18. [Common Mistakes](#section-18-common-mistakes)
19. [Complete Question List](#section-19-complete-string-question-list)
20. [Revision Cheat Sheet](#section-20-revision-cheat-sheet)
21. [Final String Roadmap](#section-21-final-string-roadmap)

---

# SECTION 1: STRING FUNDAMENTALS

## 1.1 What is a String?

**Definition:** A string is a sequence of characters stored contiguously in memory. It is one of the most fundamental data structures used in computing.

**Intuition:** Think of a string like a necklace — each bead is a character, and together they form a meaningful sequence.

```
String: "HELLO"

Index:   0    1    2    3    4
         ┌────┬────┬────┬────┬────┐
         │ H  │ E  │ L  │ L  │ O  │
         └────┴────┴────┴────┴────┘
```

A string can contain:
- Letters: `a-z`, `A-Z`
- Digits: `0-9`
- Special characters: `!@#$%^&*()`
- Whitespace: spaces, tabs, newlines
- Unicode characters: `α`, `β`, `中`, `🙂`

---

## 1.2 Why Strings Matter

Strings appear **everywhere** in real-world computing:

| Domain | String Usage |
|--------|-------------|
| Web Development | URLs, HTML parsing, JSON |
| Databases | SQL queries, text search |
| Operating Systems | File paths, commands |
| Security | Password hashing, encryption |
| Bioinformatics | DNA sequences (ACGT strings) |
| NLP / AI | Tokenization, text processing |
| Competitive Programming | ~30% of problems involve strings |

---

## 1.3 Character vs String

| Aspect | Character | String |
|--------|-----------|--------|
| Definition | Single symbol | Sequence of characters |
| In C++ | `char c = 'A';` | `string s = "Hello";` |
| Memory | 1 byte (ASCII) | n bytes + overhead |
| Literal syntax | Single quotes `'A'` | Double quotes `"Hello"` |
| Mutability | Always mutable | Depends on language |

**Key Rule:** `'A'` ≠ `"A"` — a char is NOT a string of length 1 in low-level languages.

---

## 1.4 ASCII

**Definition:** ASCII (American Standard Code for Information Interchange) is a 7-bit character encoding standard. It maps 128 characters (0–127) to integer values.

**Intuition:** Every character has a numeric ID. The computer stores that number; we see the character.

```
ASCII Table (Key Values):
┌───────────────────────────────────────────────┐
│  Decimal  │ Character │ Notes                 │
├───────────────────────────────────────────────┤
│   0       │  NUL      │ Null character '\0'   │
│   32      │  SPACE    │ Space character        │
│   48–57   │  '0'–'9'  │ Digit characters       │
│   65–90   │  'A'–'Z'  │ Uppercase letters      │
│   97–122  │  'a'–'z'  │ Lowercase letters      │
│   127     │  DEL      │ Delete character       │
└───────────────────────────────────────────────┘
```

**Key Relationships:**
- `'A'` = 65, `'Z'` = 90
- `'a'` = 97, `'z'` = 122
- `'a' - 'A'` = 32 (lowercase is 32 more than uppercase)
- `'0'` = 48, `'9'` = 57

```cpp
// ASCII in C++
char c = 'A';
int ascii = (int)c;     // ascii = 65
char back = (char)65;   // back = 'A'

// Check if digit
bool isDigit = (c >= '0' && c <= '9');

// Convert to lowercase
char lower = c + 32;    // 'A' → 'a'
```

---

## 1.5 Unicode

**Definition:** Unicode is a universal character encoding standard that assigns a unique code point (number) to every character in every human language.

**Why we need it:** ASCII only covers 128 characters — not enough for global languages.

```
Unicode Examples:
┌─────────────────────────────────────────┐
│ Character │ Unicode Code Point │ Name   │
├─────────────────────────────────────────┤
│    A      │    U+0041          │ LATIN  │
│    α      │    U+03B1          │ GREEK  │
│    中     │    U+4E2D          │ CJK    │
│    🙂     │    U+1F642         │ EMOJI  │
│    ₹      │    U+20B9          │ RUPEE  │
└─────────────────────────────────────────┘
```

Unicode currently defines **1,114,112** code points (U+0000 to U+10FFFF).

---

## 1.6 UTF-8, UTF-16, UTF-32

These are **encodings** — ways to store Unicode code points as bytes.

```
Encoding Comparison:
┌──────────┬──────────────┬──────────────────────────────────────┐
│ Encoding │ Bytes/Char   │ Notes                                │
├──────────┼──────────────┼──────────────────────────────────────┤
│ UTF-8    │ 1–4 bytes    │ Variable width; ASCII-compatible      │
│ UTF-16   │ 2 or 4 bytes │ Used by Java, C#, JavaScript         │
│ UTF-32   │ 4 bytes      │ Fixed width; simple but wasteful     │
└──────────┴──────────────┴──────────────────────────────────────┘
```

**UTF-8 Encoding Rules:**
```
Code point range    │ UTF-8 byte pattern
────────────────────┼───────────────────────────────────
U+0000  – U+007F   │ 0xxxxxxx                  (1 byte)
U+0080  – U+07FF   │ 110xxxxx 10xxxxxx         (2 bytes)
U+0800  – U+FFFF   │ 1110xxxx 10xxxxxx 10xxxxxx (3 bytes)
U+10000 – U+10FFFF │ 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx (4 bytes)
```

**Interview Note:** UTF-8 is the most common encoding on the web (>96% of websites). ASCII is a subset of UTF-8.

---

## 1.7 String Memory Representation

### Stack vs Heap Storage (C++)

```
Small string "Hi":
┌──────────────────────────────────────────────┐
│             Stack Frame                       │
│  ┌────────────────────────────────────────┐  │
│  │  std::string s = "Hi"                  │  │
│  │  [ptr | size=2 | capacity=15]          │  │
│  │   ↓ (Small String Optimization: SSO)   │  │
│  │  Characters stored inline in stack!    │  │
│  └────────────────────────────────────────┘  │
└──────────────────────────────────────────────┘

Large string "Hello, World! This is long...":
┌──────────────────────────────────────────────┐
│             Stack Frame                       │
│  ┌────────────────────────────────────────┐  │
│  │  [ptr ──────────────────────┐ size|cap]│  │
│  └────────────────────────────────────────┘  │
│                                  ↓            │
│             Heap Memory                       │
│  ┌──────────────────────────────────────────┐ │
│  │  H e l l o ,   W o r l d ! ...  \0      │ │
│  └──────────────────────────────────────────┘ │
└──────────────────────────────────────────────┘
```

### Memory Layout of a C-style string

```
char s[] = "HELLO";

Address: 100  101  102  103  104  105
         ┌────┬────┬────┬────┬────┬────┐
         │ H  │ E  │ L  │ L  │ O  │ \0 │
         └────┴────┴────┴────┴────┴────┘
           s[0] s[1] s[2] s[3] s[4] s[5]
```

---

## 1.8 Mutable vs Immutable Strings

| Language | String Mutability | Notes |
|----------|------------------|-------|
| C++ | **Mutable** | `std::string` can be modified in place |
| C | **Mutable** (char array) | But string literals are const |
| Java | **Immutable** | `String` class; use `StringBuilder` for mutation |
| Python | **Immutable** | Use list of chars, then `''.join()` |
| Go | **Immutable** | Use `[]byte` for mutation |
| JavaScript | **Immutable** | Strings are primitives |

**Why Immutability Matters in Interviews:**
```java
// Java - WRONG (creates new string each time → O(n²))
String result = "";
for (int i = 0; i < n; i++) result += chars[i];

// Java - CORRECT (O(n))
StringBuilder sb = new StringBuilder();
for (int i = 0; i < n; i++) sb.append(chars[i]);
String result = sb.toString();
```

---

## 1.9 String Interning

**Definition:** String interning is a technique where only one copy of each distinct string value is stored. When two variables have the same string value, they point to the same memory.

```
Java String Interning:
┌─────────────────────────────────┐
│  String Pool (Heap)             │
│  ┌───────────────────────────┐  │
│  │  "hello"                  │  │
│  └───────────────────────────┘  │
│          ↑            ↑         │
│  String a = "hello"  String b = "hello"  │
│  (a == b) → true (same reference!)       │
└─────────────────────────────────┘

But:
  String c = new String("hello");
  (a == c) → false (different object)
  a.equals(c) → true
```

**Interview Note:** Always use `.equals()` for string comparison in Java, never `==`.

---

## 1.10 Null Character and Escape Characters

**Null Character (`\0`):**
- ASCII value: 0
- Marks the END of a C-string
- Without it, the string has no defined end!

```cpp
char s[] = {'H', 'E', 'L', 'L', 'O', '\0'}; // proper C-string
char s2[] = "HELLO"; // compiler adds \0 automatically
```

**Common Escape Characters:**

| Escape | Meaning | ASCII Value |
|--------|---------|-------------|
| `\0` | Null | 0 |
| `\n` | Newline | 10 |
| `\t` | Tab | 9 |
| `\r` | Carriage Return | 13 |
| `\\` | Backslash | 92 |
| `\'` | Single Quote | 39 |
| `\"` | Double Quote | 34 |

---

# SECTION 2: STRING IMPLEMENTATION

## 2.1 String as Character Array (C-Style)

```cpp
// C-style string declaration
char s1[] = "Hello";           // Array with \0 added automatically
char s2[6] = {'H','e','l','l','o','\0'}; // Explicit \0
const char* s3 = "World";     // Pointer to string literal (read-only)

// DANGER: buffer overflow
char buf[5];
strcpy(buf, "Hello");   // OK (5 chars + \0 = 6) → OVERFLOW!
```

**Memory:**
```
char s[] = "Hello";
┌───┬───┬───┬───┬───┬───┐
│ H │ e │ l │ l │ o │\0 │   ← 6 bytes total
└───┴───┴───┴───┴───┴───┘
  0   1   2   3   4   5
```

---

## 2.2 C++ `std::string`

```cpp
#include <string>
using namespace std;

// Declaration
string s = "Hello";
string s2(5, 'a');         // "aaaaa"
string s3(s, 1, 3);        // "ell" (substr from index 1, length 3)
string s4 = s.substr(1,3); // "ell"

// Key properties
s.length();    // or s.size() → 5
s.empty();     // false
s.capacity();  // implementation-defined
s[0];          // 'H' (no bounds check)
s.at(0);       // 'H' (with bounds check, throws out_of_range)
s.front();     // 'H'
s.back();      // 'o'

// Modification
s.push_back('!');   // "Hello!"
s.pop_back();       // "Hello"
s += " World";      // "Hello World"
s.append(" World"); // "Hello World"
s.insert(5, ",");   // "Hello, World"
s.erase(5, 2);      // "HelloWorld"
s.replace(0, 5, "Hi"); // "Hi World"

// Search
s.find("llo");      // returns index or string::npos
s.rfind("l");       // last occurrence
s.find_first_of("aeiou"); // first vowel index

// Conversion
stoi("42");      // string to int
stol("42");      // string to long
stof("3.14");    // string to float
to_string(42);   // int to string
```

### SSO (Small String Optimization)

```
std::string internal layout (typical 64-bit):

For short strings (≤15 chars on most implementations):
┌───────────────────────────────────────────────┐
│  [char buffer: 16 bytes][size: 8 bytes]       │
│   Characters stored directly in stack!        │
└───────────────────────────────────────────────┘

For long strings:
┌───────────────────────────────────────────────┐
│  [ptr: 8 bytes][size: 8 bytes][cap: 8 bytes]  │
│   ptr → heap memory                           │
└───────────────────────────────────────────────┘
```

---

## 2.3 Java String

```java
// Immutable String
String s = "Hello";
String s2 = new String("Hello");   // forces new object (avoid this)

// Operations
s.length();          // 5
s.charAt(0);         // 'H'
s.indexOf("ll");     // 2
s.substring(1, 4);   // "ell" (from index 1 to 3, exclusive end)
s.toUpperCase();     // "HELLO"
s.toLowerCase();     // "hello"
s.trim();            // removes leading/trailing whitespace
s.replace("l","r");  // "Herro"
s.split(",");        // split by delimiter
s.contains("ell");   // true
s.startsWith("He");  // true
s.endsWith("lo");    // true
s.equals("Hello");   // true (USE THIS, not ==)
s.compareTo("Hi");   // negative (H < H is false, e < i)
String.valueOf(42);  // "42"
Integer.parseInt("42"); // 42

// Mutable StringBuilder (use for building strings)
StringBuilder sb = new StringBuilder();
sb.append("Hello");
sb.append(' ');
sb.append("World");
sb.insert(5, ",");
sb.reverse();
sb.deleteCharAt(0);
sb.toString();       // convert back to String
```

---

## 2.4 Python String

```python
s = "Hello"

# Access
s[0]          # 'H'
s[-1]         # 'o' (last char)
s[1:4]        # 'ell' (slice)
s[::-1]       # 'olleH' (reverse)

# Methods
len(s)                # 5
s.upper()             # 'HELLO'
s.lower()             # 'hello'
s.strip()             # remove whitespace
s.split(',')          # split by delimiter
','.join(['a','b'])   # 'a,b'
s.find('ll')          # 2
s.replace('l','r')    # 'Herro'
s.startswith('He')    # True
s.endswith('lo')      # True
s.isalpha()           # True
s.isdigit()           # False
s.isalnum()           # True
s.count('l')          # 2
ord('A')              # 65 (char to ASCII)
chr(65)               # 'A' (ASCII to char)

# String formatting
f"Value: {42}"        # f-string
"Hello {}".format(s)  # format method
```

---

# SECTION 3: STRING OPERATIONS

## 3.1 Traversal

**Definition:** Visiting each character of the string exactly once.

**Intuition:** Walk through the necklace bead by bead.

```cpp
string s = "Hello";

// Method 1: Index-based
for (int i = 0; i < s.length(); i++) {
    cout << s[i] << " ";
}

// Method 2: Range-based for (C++11)
for (char c : s) {
    cout << c << " ";
}

// Method 3: Iterator
for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
}
```

**Dry Run for "Hello":**
```
i=0: s[0]='H'
i=1: s[1]='e'
i=2: s[2]='l'
i=3: s[3]='l'
i=4: s[4]='o'
Output: H e l l o
```

**Complexity:** Time O(n), Space O(1)

**Common Mistakes:**
- Using `i <= s.length()` instead of `i < s.length()` → off-by-one
- Modifying string while iterating

---

## 3.2 Reverse

**Definition:** Reversing the order of characters in a string.

**Approaches:**

**Brute Force:** Create a new string, append from end to beginning.
```cpp
string reverseStr(string s) {
    string result = "";
    for (int i = s.length() - 1; i >= 0; i--)
        result += s[i];
    return result;
}
// Time: O(n), Space: O(n)
```

**Optimal (Two Pointers, in-place):**
```cpp
string reverseStr(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}
// Time: O(n), Space: O(1)
```

**Using STL:**
```cpp
reverse(s.begin(), s.end()); // In-place, O(n), O(1)
```

**Dry Run for "HELLO":**
```
Initial: H E L L O
         ↑       ↑
Step 1:  swap(H,O) → O E L L H,  left=1, right=3
         O E L L H
           ↑   ↑
Step 2:  swap(E,L) → O L L E H,  left=2, right=2
         left >= right → stop
Result:  O L L E H → "OLLEH"
```

---

## 3.3 Search (Find)

**Find first occurrence of a character:**
```cpp
int findChar(string s, char target) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == target) return i;
    }
    return -1; // not found
}
```

**Using STL:**
```cpp
size_t pos = s.find('l');       // first 'l' → 2
size_t pos2 = s.rfind('l');    // last 'l' → 3
if (pos == string::npos) { /* not found */ }
```

**Dry Run for find('l') in "Hello":**
```
i=0: s[0]='H' ≠ 'l'
i=1: s[1]='e' ≠ 'l'
i=2: s[2]='l' == 'l' → return 2
```

---

## 3.4 Insert

```cpp
string s = "Hello World";
s.insert(5, ",");     // "Hello, World" — insert at index 5
s.insert(0, "Say "); // "Say Hello World"

// Char insert
s.insert(s.begin() + 5, ','); // iterator-based
```

**Complexity:** O(n) — requires shifting all subsequent characters.

---

## 3.5 Delete

```cpp
string s = "Hello World";
s.erase(5, 6);         // erase 6 chars starting at index 5 → "Hello"
s.erase(s.begin());    // erase first char

// Remove all occurrences of a character
s.erase(remove(s.begin(), s.end(), ' '), s.end()); // remove spaces
```

**Complexity:** O(n) — shifting required.

---

## 3.6 Substring

**Definition:** A contiguous sequence of characters within a string.

```cpp
string s = "Hello World";

// Method 1: substr(start, length)
string sub = s.substr(6, 5); // "World"

// Method 2: substr(start) — to end
string sub2 = s.substr(6);   // "World"

// Manual extraction
string manual = "";
for (int i = 6; i < 11; i++) manual += s[i];
```

**All Substrings Generation:**
```cpp
void allSubstrings(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << s.substr(i, j-i+1) << "\n";
        }
    }
}
// Count of substrings: n*(n+1)/2
// Time: O(n³) due to substr copy, or O(n²) if just printing
```

**Dry Run for "abc":**
```
i=0: j=0: "a"
     j=1: "ab"
     j=2: "abc"
i=1: j=1: "b"
     j=2: "bc"
i=2: j=2: "c"
Total: 6 substrings (n=3, n*(n+1)/2 = 6)
```

---

## 3.7 Concatenation

```cpp
string a = "Hello";
string b = " World";

// Method 1: + operator
string c = a + b;       // "Hello World" — creates new string

// Method 2: append
a.append(b);            // modifies a in place

// Method 3: += 
a += b;

// Performance warning: repeated concatenation in loop
// BAD: O(n²) total
string result = "";
for (int i = 0; i < n; i++) result += str;

// GOOD: use stringstream or reserve
string result;
result.reserve(n * str.length());
for (int i = 0; i < n; i++) result += str;
```

---

## 3.8 Rotate

**Left Rotate by k positions:**
```cpp
// "ABCDE" rotated left by 2 → "CDEAB"
string leftRotate(string s, int k) {
    int n = s.length();
    k = k % n;
    return s.substr(k) + s.substr(0, k);
}

// In-place using reverse:
void leftRotateInPlace(string& s, int k) {
    int n = s.length();
    k = k % n;
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());
    reverse(s.begin(), s.end());
}
```

**Dry Run for "ABCDE", k=2:**
```
Step 1: reverse first 2: "BACDE"
Step 2: reverse rest:    "BACED" wait...
        reverse "CDE"  → "EDC"  → "BAEDC"
Step 3: reverse all:     "CDEAB" ✓
```

---

## 3.9 Split and Join

```cpp
#include <sstream>
#include <vector>

// Split by delimiter
vector<string> split(string s, char delim) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Join vector of strings
string join(vector<string>& v, string delim) {
    string result = "";
    for (int i = 0; i < v.size(); i++) {
        if (i > 0) result += delim;
        result += v[i];
    }
    return result;
}

// Usage
vector<string> words = split("Hello World Foo", ' ');
// words = ["Hello", "World", "Foo"]
string joined = join(words, "-");
// joined = "Hello-World-Foo"
```

---

## 3.10 Compare

```cpp
string a = "apple", b = "banana";

// Lexicographic comparison
if (a < b)      cout << "apple comes first";   // true
if (a == b)     cout << "equal";
a.compare(b);   // negative if a < b, 0 if equal, positive if a > b

// Case-insensitive compare
bool equalIgnoreCase(string a, string b) {
    if (a.length() != b.length()) return false;
    for (int i = 0; i < a.length(); i++) {
        if (tolower(a[i]) != tolower(b[i])) return false;
    }
    return true;
}
```

---

# SECTION 4: COMPLEXITY ANALYSIS

## 4.1 String Operation Complexity Table

| Operation | C++ (std::string) | Java (String) | Python |
|-----------|-------------------|---------------|--------|
| Access `s[i]` | O(1) | O(1) | O(1) |
| Length | O(1) | O(1) | O(1) |
| Append 1 char | O(1) amortized | O(n) (new String) | O(n) |
| Concatenate | O(n+m) | O(n+m) | O(n+m) |
| Substring | O(k) | O(k) | O(k) |
| Find/Search | O(n·m) naive | O(n·m) naive | O(n·m) naive |
| Compare | O(min(n,m)) | O(min(n,m)) | O(min(n,m)) |
| Insert at i | O(n) | O(n) | O(n) |
| Delete at i | O(n) | O(n) | O(n) |
| Reverse | O(n) | O(n) | O(n) |
| Sort characters | O(n log n) | O(n log n) | O(n log n) |
| Traverse | O(n) | O(n) | O(n) |

## 4.2 Space Complexity Notes

| Operation | Space |
|-----------|-------|
| Reversed copy | O(n) |
| In-place reverse | O(1) |
| All substrings | O(n²) |
| Frequency array | O(1) — only 26 or 128 slots |
| Hash map of chars | O(1) — bounded by alphabet size |

## 4.3 Language-Specific Quirks

```
C++ std::string:
  - Append is O(1) amortized (doubles capacity)
  - substr creates copy → O(k)
  - string::npos = SIZE_MAX (largest size_t)

Java String:
  - Concatenation with + creates new String → O(n)
  - StringBuilder.append is O(1) amortized
  - s.charAt(i) is O(1)

Python:
  - s + t creates new string → O(n+m)
  - ''.join(list) is O(n) total → always use join
  - Slicing s[i:j] creates copy → O(j-i)
```

---

# SECTION 5: CHARACTER MANIPULATION

## 5.1 Case Conversion

```cpp
char c = 'A';

// Manual conversion
char lower = c + 32;          // 'A' → 'a'
char upper = c - 32;          // 'a' → 'A'

// Using cctype library (PREFERRED)
#include <cctype>
tolower('A');   // 'a'
toupper('a');   // 'A'

// Convert entire string
string s = "Hello World";
for (char& c : s) c = tolower(c);  // "hello world"
for (char& c : s) c = toupper(c);  // "HELLO WORLD"

// Using transform (STL)
transform(s.begin(), s.end(), s.begin(), ::tolower);
```

---

## 5.2 ASCII Conversion and Arithmetic

```cpp
// char ↔ int
char c = 'A';
int num = (int)c;        // 65
char back = (char)65;    // 'A'

// Direct arithmetic (implicit conversion)
int diff = 'z' - 'a';   // 25
char third = 'a' + 2;   // 'c'

// Common patterns
int alphabetIndex = c - 'a';    // 'a'=0, 'b'=1, ..., 'z'=25
int digitValue = c - '0';       // '0'=0, '1'=1, ..., '9'=9

// Frequency array using char arithmetic
int freq[26] = {0};
for (char c : s) freq[c - 'a']++;

// This is O(1) space (bounded by alphabet size = 26)
```

---

## 5.3 Character Classification

```cpp
#include <cctype>

char c = 'A';

isalpha(c);    // true: is alphabetic (a-z or A-Z)
isdigit(c);    // false: is digit (0-9)
isalnum(c);    // true: is alphanumeric
islower(c);    // false: is lowercase
isupper(c);    // true: is uppercase
isspace(c);    // false: is whitespace (space, tab, newline)
ispunct(c);    // false: is punctuation

// Manual equivalents
bool isAlpha = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
bool isDigit = (c >= '0' && c <= '9');
bool isLower = (c >= 'a' && c <= 'z');
bool isUpper = (c >= 'A' && c <= 'Z');
bool isVowel = (string("aeiouAEIOU").find(c) != string::npos);
```

---

## 5.4 Vowel Check

```cpp
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Faster: using a set
bool isVowelFast(char c) {
    static const string vowels = "aeiouAEIOU";
    return vowels.find(c) != string::npos;
}

// Even faster: boolean lookup table
bool isVowelTable(char c) {
    static bool table[128] = {};
    static bool initialized = false;
    if (!initialized) {
        for (char v : string("aeiouAEIOU")) table[v] = true;
        initialized = true;
    }
    return table[(int)c];
}
```

---

## 5.5 Character Frequency

```cpp
// Frequency of lowercase letters only
int freq[26] = {0};
string s = "abracadabra";
for (char c : s) freq[c - 'a']++;

// Print frequency
for (int i = 0; i < 26; i++) {
    if (freq[i] > 0)
        cout << (char)('a' + i) << ": " << freq[i] << "\n";
}
// Output:
// a: 5
// b: 2
// c: 1
// d: 1
// r: 2

// Frequency of all ASCII chars
int freq128[128] = {0};
for (char c : s) freq128[(int)c]++;

// Using unordered_map (for any string)
unordered_map<char, int> freq_map;
for (char c : s) freq_map[c]++;
```

**Dry Run for "abracadabra":**
```
Char: a  b  r  a  c  a  d  a  b  r  a
      ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓  ↓
freq['a'-'a'] = freq[0]: 1→2→3→4→5
freq['b'-'a'] = freq[1]: 1→2
freq['r'-'a'] = freq[17]: 1→2
freq['c'-'a'] = freq[2]: 1
freq['d'-'a'] = freq[3]: 1
```

---

## 5.6 Digit Conversion

```cpp
// Char digit ↔ int
char c = '7';
int val = c - '0';        // 7
char back = '0' + 7;      // '7'

// String to integer (manual)
int strToInt(string s) {
    int result = 0;
    bool negative = false;
    int i = 0;
    if (s[0] == '-') { negative = true; i = 1; }
    for (; i < s.length(); i++) {
        result = result * 10 + (s[i] - '0');
    }
    return negative ? -result : result;
}

// Built-in conversions
int x = stoi("123");       // 123
long y = stol("1234567");  // 1234567
double z = stod("3.14");   // 3.14
string s2 = to_string(42); // "42"
```

---

# SECTION 6: STRING SEARCHING ALGORITHMS

## 6.1 Naive Pattern Matching

**Definition:** Check every possible starting position in the text for the pattern.

**Intuition:** Slide a window of size m over the text. At each position, compare all m characters.

**Visualization:**
```
Text:    A B C A B C A B D
Pattern: A B C A B D

Position 0: ABCABC vs ABCABD → mismatch at index 5
Position 1:  BCABCA vs ABCABD → mismatch at index 0
Position 2:   CABCAB vs ABCABD → mismatch at index 0
Position 3:    ABCABD vs ABCABD → MATCH! ✓
```

**Code:**
```cpp
vector<int> naiveSearch(string text, string pattern) {
    vector<int> matches;
    int n = text.length(), m = pattern.length();
    
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) j++;
        if (j == m) matches.push_back(i); // full match
    }
    return matches;
}
```

**Dry Run for text="AABAABAAA", pattern="AAB":**
```
i=0: text[0..2]="AAB" vs "AAB" → MATCH at 0
i=1: text[1..3]="ABA" vs "AAB" → mismatch at j=1
i=2: text[2..4]="BAA" vs "AAB" → mismatch at j=0
i=3: text[3..5]="AAB" vs "AAB" → MATCH at 3
i=4: text[4..6]="ABA" → mismatch
i=5: text[5..7]="BAA" → mismatch
i=6: text[6..8]="AAA" → mismatch at j=2
Result: [0, 3]
```

**Complexity:**
- Best: O(n) — pattern not found after first char each time
- Worst: O(n·m) — "AAAA...A" and pattern "AAA...AB"
- Space: O(1)

**Common Mistakes:**
- Loop condition `i <= n - m` (not `i < n - m`)
- Forgetting to check all positions even after partial match

**Interview Notes:**
- Good enough for small inputs and interviews
- For large inputs, KMP or Z-Algorithm preferred
- Worst case pattern: text="aaaaaa", pattern="aaab"

---

## 6.2 Rabin-Karp Algorithm

**Definition:** Uses polynomial hashing to quickly compare pattern with text substrings. Only does character-by-character comparison when hashes match (to avoid false positives).

**Intuition:** Instead of comparing strings character by character, compute a hash for the pattern and a rolling hash for each text window. If hashes match, verify character by character.

**Hash Function:**
```
hash("abc") = 'a'*p^2 + 'b'*p^1 + 'c'*p^0   (mod MOD)
```

**Rolling Hash Magic:**
```
Text:    a b c d e
Window:  [a b c]       hash1 = a*p^2 + b*p^1 + c*p^0
Next:      [b c d]     hash2 = b*p^2 + c*p^1 + d*p^0

hash2 = (hash1 - a*p^(m-1)) * p + d    ← O(1) update!
```

**Code:**
```cpp
vector<int> rabinKarp(string text, string pattern) {
    vector<int> matches;
    int n = text.length(), m = pattern.length();
    if (m > n) return matches;
    
    const long long MOD = 1e9 + 7;
    const long long BASE = 31;
    
    // Compute BASE^(m-1) mod MOD
    long long power = 1;
    for (int i = 0; i < m - 1; i++)
        power = (power * BASE) % MOD;
    
    // Compute pattern hash and first window hash
    long long patHash = 0, winHash = 0;
    for (int i = 0; i < m; i++) {
        patHash = (patHash * BASE + pattern[i]) % MOD;
        winHash = (winHash * BASE + text[i]) % MOD;
    }
    
    for (int i = 0; i <= n - m; i++) {
        if (winHash == patHash) {
            // Verify to avoid false positives
            if (text.substr(i, m) == pattern)
                matches.push_back(i);
        }
        // Roll hash
        if (i < n - m) {
            winHash = (winHash - text[i] * power % MOD + MOD) % MOD;
            winHash = (winHash * BASE + text[i + m]) % MOD;
        }
    }
    return matches;
}
```

**Dry Run for text="ABCABC", pattern="ABC":**
```
BASE=31, MOD=1e9+7

patHash = 'A'*31^2 + 'B'*31 + 'C' = 65*961 + 66*31 + 67 = 64912

i=0: winHash = hash("ABC") = 64912 == patHash → verify → MATCH
i=1: roll: remove 'A', add 'A'
     winHash = hash("BCA") ≠ 64912
i=2: roll: winHash = hash("CAB") ≠ 64912
i=3: winHash = hash("ABC") = 64912 → MATCH
```

**Complexity:**
- Average: O(n + m)
- Worst: O(n·m) — when all hashes match (many false positives)
- Space: O(1)

**Interview Notes:**
- Great for multiple pattern search
- Useful for finding repeated substrings
- Choose large prime MOD to minimize collisions
- Double hashing reduces collision probability

---

## 6.3 KMP Algorithm (Knuth-Morris-Pratt)

**Definition:** KMP preprocesses the pattern to build a failure function (also called LPS — Longest Proper Prefix which is also a Suffix array). This allows skipping characters in the text when a mismatch occurs.

**Intuition:** When a mismatch occurs at position j in the pattern, instead of restarting from j=0, we can restart from lps[j-1] because we know the previous characters matched a prefix of the pattern.

**LPS Array:**
```
Pattern: A A B A A C

Index:   0  1  2  3  4  5
Char:    A  A  B  A  A  C
LPS:     0  1  0  1  2  0

LPS[i] = length of longest proper prefix of pattern[0..i]
         which is also a suffix of pattern[0..i]
```

**LPS Construction Visualization:**
```
pattern = "AABAAC"

i=0: pattern[0]='A'  → lps[0]=0 (always 0 by definition)
i=1: pattern[1]='A', compare with pattern[lps[0]]='A' → match
     lps[1]=1
i=2: pattern[2]='B', compare with pattern[lps[1]]='A' → mismatch
     lps[1]=1 → fallback to lps[0]=0
     pattern[2]='B' vs pattern[0]='A' → mismatch
     lps[2]=0
i=3: pattern[3]='A', compare with pattern[0]='A' → match
     lps[3]=1
i=4: pattern[4]='A', compare with pattern[1]='A' → match
     lps[4]=2
i=5: pattern[5]='C', compare with pattern[2]='B' → mismatch
     fallback: lps[1]=1 → compare with pattern[1]='A' → mismatch
     fallback: lps[0]=0 → compare with pattern[0]='A' → mismatch
     lps[5]=0
```

**Code:**
```cpp
// Build LPS (Failure Function)
vector<int> buildLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0; // length of previous longest prefix suffix
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // fallback (key insight!)
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP Search
vector<int> kmpSearch(string text, string pattern) {
    vector<int> matches;
    int n = text.length(), m = pattern.length();
    vector<int> lps = buildLPS(pattern);
    
    int i = 0, j = 0; // i for text, j for pattern
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }
        if (j == m) {
            matches.push_back(i - j); // found match
            j = lps[j - 1];           // prepare for next match
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1]; // use LPS to skip
            else i++;
        }
    }
    return matches;
}
```

**Dry Run: text="AABAABAAA", pattern="AABAAA"**
```
Pattern LPS: A A B A A A
             0 1 0 1 2 2

Searching:
i=0,j=0: A==A → i=1,j=1
i=1,j=1: A==A → i=2,j=2
i=2,j=2: B==B → i=3,j=3
i=3,j=3: A==A → i=4,j=4
i=4,j=4: A==A → i=5,j=5
i=5,j=5: B≠A  → j=lps[4]=2
i=5,j=2: B==B → i=6,j=3
i=6,j=3: A==A → i=7,j=4
i=7,j=4: A==A → i=8,j=5
i=8,j=5: A==A → i=9,j=6
j==m=6 → MATCH at i-j=9-6=3 → matches=[3]
j = lps[5] = 2
```

**Complexity:**
- Time: O(n + m) — preprocessing O(m), search O(n)
- Space: O(m) for LPS array

**Interview Notes:**
- KMP is the go-to for pattern matching in interviews
- Key insight: the LPS fallback avoids restarting from 0
- LPS array is also useful for finding the shortest period of a string
- If LPS[m-1] > 0, the pattern has a proper border

---

## 6.4 Z Algorithm

**Definition:** The Z-array of string S is an array where Z[i] is the length of the longest substring starting at position i that is also a prefix of S.

**Intuition:** Z-function helps match a pattern by concatenating `pattern + '#' + text` and finding Z values. If Z[i] == m (pattern length), there's a match.

**Z-Array Visualization:**
```
String:  A A B A A C
Index:   0 1 2 3 4 5
Z:       X 1 0 2 1 0
         ↑ can't define Z[0] (or define as string length)

Z[1]=1: S[1..1]="A" == S[0..0]="A" → length 1
Z[2]=0: S[2]='B' ≠ S[0]='A' → 0
Z[3]=2: S[3..4]="AA" == S[0..1]="AA" → length 2
Z[4]=1: S[4]='A' == S[0]='A', S[5]='C' ≠ S[1]='A' → 1
Z[5]=0: S[5]='C' ≠ S[0]='A' → 0
```

**Code:**
```cpp
vector<int> zFunction(string s) {
    int n = s.length();
    vector<int> z(n, 0);
    z[0] = n;
    int l = 0, r = 0; // Z-box boundaries
    
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

// Pattern matching using Z-function
vector<int> zSearch(string text, string pattern) {
    string combined = pattern + "#" + text;
    vector<int> z = zFunction(combined);
    vector<int> matches;
    int m = pattern.length();
    
    for (int i = m + 1; i < combined.length(); i++) {
        if (z[i] == m) {
            matches.push_back(i - m - 1); // position in text
        }
    }
    return matches;
}
```

**Complexity:** O(n + m)

**Interview Notes:**
- Z-algorithm is simpler to code than KMP in many cases
- The Z-box `[l, r)` gives the key O(n) guarantee
- Combined string `pattern + "#" + text` — `#` prevents unwanted matches

---

## 6.5 Boyer-Moore Algorithm

**Intuition:** Boyer-Moore scans the pattern RIGHT TO LEFT and uses two heuristics to skip as many characters as possible:
1. **Bad Character Rule:** When a mismatch occurs, shift pattern so the mismatched text character aligns with its rightmost occurrence in the pattern.
2. **Good Suffix Rule:** If a suffix matched, shift to align with the next occurrence of that suffix in the pattern.

**Bad Character Heuristic (simplified):**
```cpp
void buildBadChar(string pattern, int badChar[256]) {
    fill(badChar, badChar + 256, -1);
    for (int i = 0; i < pattern.length(); i++)
        badChar[(int)pattern[i]] = i;
}

vector<int> boyerMoore(string text, string pattern) {
    vector<int> matches;
    int n = text.length(), m = pattern.length();
    int badChar[256];
    buildBadChar(pattern, badChar);
    
    int shift = 0;
    while (shift <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[shift + j]) j--;
        
        if (j < 0) {
            matches.push_back(shift);
            shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
        } else {
            shift += max(1, j - badChar[(int)text[shift + j]]);
        }
    }
    return matches;
}
```

**Complexity:**
- Best/Average: O(n/m) — sublinear!
- Worst: O(n·m)

---

## 6.6 Finite Automata Matching

**Definition:** Build a DFA (Deterministic Finite Automaton) from the pattern. Each state represents how many characters of the pattern have been matched.

```cpp
// Build transition table
void buildFSM(string pattern, int m, int fsm[][256]) {
    for (int state = 0; state <= m; state++) {
        for (int c = 0; c < 256; c++) {
            int next = min(m + 1, state + 1);
            while (next > 0) {
                // Check if pattern[0..next-1] is suffix of pattern[0..state-1]+c
                string cur = pattern.substr(0, state) + (char)c;
                string pref = pattern.substr(0, next);
                if (cur.length() >= next && 
                    cur.substr(cur.length() - next) == pref) break;
                next--;
            }
            fsm[state][c] = next;
        }
    }
}
```

**Complexity:** O(m·256) preprocessing, O(n) search.

---

# SECTION 7: STRING PATTERNS

## How to Identify Patterns

```
Read the problem → Ask these questions:
┌─────────────────────────────────────────────────────────┐
│ Does it ask about a CONTIGUOUS part of the string?      │
│   → Substring problem → Sliding Window / Two Pointers   │
│                                                         │
│ Does it ask about CHARACTERS and their counts?          │
│   → Frequency Counting / Hashing                        │
│                                                         │
│ Does it ask about REARRANGEMENT or SORTING characters?  │
│   → Anagram pattern                                     │
│                                                         │
│ Does it ask about SAME forwards and backwards?          │
│   → Palindrome pattern                                  │
│                                                         │
│ Does it ask if one string EXISTS in another?            │
│   → Pattern Matching (KMP/Z/Rabin-Karp)                 │
│                                                         │
│ Does it ask about a REPEATED structure?                 │
│   → Rolling Hash / Period detection                     │
└─────────────────────────────────────────────────────────┘
```

---

## Pattern 1: Frequency Counting

**Identification Clues:**
- "Count occurrences of..."
- "How many times does character X appear?"
- "Are all characters unique?"
- "Valid anagram?"
- "Characters with even/odd frequency"

**Template:**
```cpp
// Frequency array (lowercase letters)
int freq[26] = {0};
for (char c : s) freq[c - 'a']++;

// Frequency map (any characters)
unordered_map<char, int> freq;
for (char c : s) freq[c]++;

// Check if all characters unique
bool allUnique(string s) {
    int freq[26] = {0};
    for (char c : s) {
        if (freq[c - 'a']++ > 0) return false;
    }
    return true;
}
```

**Common Problems:**
- Valid Anagram (LC 242)
- First Unique Character (LC 387)
- Find the Difference (LC 389)
- Ransom Note (LC 383)

**Common Mistakes:**
- Using freq['a'-'a'] for uppercase — won't work, use freq[c-'A']
- Not resetting frequency array between test cases

---

## Pattern 2: Hashing

**Identification Clues:**
- "Two strings equivalent?" (after some transformation)
- "Group strings with same property"
- "Find duplicates"
- "Check if permutation exists"

**Template:**
```cpp
// String hashing using sorted chars (anagram key)
string getKey(string s) {
    sort(s.begin(), s.end());
    return s;
}

// Group anagrams
unordered_map<string, vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string& s : strs) mp[getKey(s)].push_back(s);
    vector<vector<string>> result;
    for (auto& p : mp) result.push_back(p.second);
    return result;  // or return vector
}
```

---

## Pattern 3: Sliding Window

### Fixed Window

**Identification Clues:**
- "All substrings of length k"
- "Maximum/Minimum in window of size k"
- "Anagram in string of length k"

**Template:**
```cpp
// Fixed window of size k
int maxSumWindow(string s, int k) {
    int n = s.length();
    // Initialize window
    int windowVal = 0;
    for (int i = 0; i < k; i++) windowVal += (s[i] - 'a');
    
    int maxVal = windowVal;
    // Slide window
    for (int i = k; i < n; i++) {
        windowVal += (s[i] - 'a');       // add new char
        windowVal -= (s[i - k] - 'a');   // remove old char
        maxVal = max(maxVal, windowVal);
    }
    return maxVal;
}
```

**Dry Run for "abcde", k=3:**
```
Window: [a,b,c] → val=0+1+2=3
Slide:  remove 'a', add 'd' → [b,c,d] → val=3-0+3=6
Slide:  remove 'b', add 'e' → [c,d,e] → val=6-1+4=9
Max = 9
```

### Variable Window

**Identification Clues:**
- "Longest/Shortest substring with condition X"
- "Minimum window containing all of..."
- "Longest substring without repeating..."

**Template:**
```cpp
// Variable window - expand right, shrink left
int variableWindow(string s) {
    unordered_map<char, int> window;
    int left = 0, result = 0;
    
    for (int right = 0; right < s.length(); right++) {
        // Expand: add s[right] to window
        window[s[right]]++;
        
        // Shrink: while window is invalid
        while (/* window is invalid */) {
            window[s[left]]--;
            if (window[s[left]] == 0) window.erase(s[left]);
            left++;
        }
        
        // Update result (window is now valid)
        result = max(result, right - left + 1);
    }
    return result;
}
```

---

## Pattern 4: Two Pointers

**Identification Clues:**
- "Palindrome check"
- "Reverse the string"
- "Compare from both ends"
- "Valid palindrome (skip non-alphanum)"

**Template:**
```cpp
// Two pointers inward
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}
```

---

## Pattern 5: Character Mapping

**Identification Clues:**
- "Isomorphic strings" (one-to-one mapping)
- "Word pattern"
- "Is string s1 a pattern match for s2?"

**Template:**
```cpp
// Check if two strings are isomorphic
bool isIsomorphic(string s, string t) {
    unordered_map<char,char> s2t, t2s;
    for (int i = 0; i < s.length(); i++) {
        char cs = s[i], ct = t[i];
        if (s2t.count(cs) && s2t[cs] != ct) return false;
        if (t2s.count(ct) && t2s[ct] != cs) return false;
        s2t[cs] = ct;
        t2s[ct] = cs;
    }
    return true;
}
```

---

## Pattern 6: Anagram Problems

**Identification Clues:**
- "Same characters, different order"
- "Rearranging characters"
- "Permutation of string"

**Approach:** Two strings are anagrams iff their character frequency arrays are equal.

```cpp
// O(n) anagram check
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    int freq[26] = {0};
    for (char c : s) freq[c - 'a']++;
    for (char c : t) {
        if (--freq[c - 'a'] < 0) return false;
    }
    return true;
}

// Find all anagram starting positions in text
vector<int> findAnagrams(string text, string pattern) {
    vector<int> result;
    int n = text.length(), m = pattern.length();
    if (n < m) return result;
    
    int pFreq[26] = {}, wFreq[26] = {};
    for (char c : pattern) pFreq[c-'a']++;
    for (int i = 0; i < m; i++) wFreq[text[i]-'a']++;
    
    if (equal(pFreq, pFreq+26, wFreq)) result.push_back(0);
    
    for (int i = m; i < n; i++) {
        wFreq[text[i]-'a']++;
        wFreq[text[i-m]-'a']--;
        if (equal(pFreq, pFreq+26, wFreq)) result.push_back(i-m+1);
    }
    return result;
}
```

---

## Pattern 7: Palindrome Problems

See Section 8 for full details.

**Quick Template:**
```cpp
// Check palindrome using two pointers
bool isPalin(string s) {
    int l = 0, r = s.size()-1;
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

// Expand around center
int expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1; // length of palindrome
}
```

---

## Pattern 8: Substring Problems

**Identification Clues:**
- "Find all substrings with property X"
- "Longest/Shortest substring..."
- "Count substrings..."

**Common Approaches:**
- Sliding Window for contiguous constraints
- Two Pointers for palindrome-type problems
- Hashing for repeated substrings

```cpp
// Count substrings with exactly k distinct chars
int countSubstringsKDistinct(string s, int k) {
    // atMost(k) - atMost(k-1)
    auto atMost = [&](int k) {
        unordered_map<char,int> freq;
        int l = 0, count = 0;
        for (int r = 0; r < s.size(); r++) {
            freq[s[r]]++;
            while (freq.size() > k) {
                if (--freq[s[l]] == 0) freq.erase(s[l]);
                l++;
            }
            count += r - l + 1; // all substrings ending at r
        }
        return count;
    };
    return atMost(k) - atMost(k-1);
}
```

---

## Pattern 9: Pattern Matching

See Section 6 for full algorithms.

**Quick Decision:**
```
Single pattern, small input  → Naive (O(nm))
Single pattern, large input  → KMP or Z-Algorithm (O(n+m))
Multiple patterns            → Rabin-Karp or Aho-Corasick
Approximate matching         → Edit Distance (DP)
```

---

## Pattern 10: String Compression

**Identification Clues:**
- "Run-length encoding"
- "Compress consecutive same characters"
- "Count and say"

```cpp
// Basic RLE compression
string compress(string s) {
    string result = "";
    int i = 0, n = s.length();
    while (i < n) {
        char c = s[i];
        int count = 0;
        while (i < n && s[i] == c) { i++; count++; }
        result += c;
        if (count > 1) result += to_string(count);
    }
    return result.length() < s.length() ? result : s;
}

// Example: "aabcccccaaa" → "a2bc5a3"
```

---

## Pattern 11: Lexicographical Ordering

**Identification Clues:**
- "Smallest/Largest string after operations"
- "Next permutation of string"
- "Dictionary order"

```cpp
// Lexicographic comparison
bool lexLess(string& a, string& b) { return a < b; } // built-in for strings

// Next permutation (STL)
string s = "abc";
do {
    cout << s << "\n";
} while (next_permutation(s.begin(), s.end()));
// Prints: abc, acb, bac, bca, cab, cba

// Smallest string from given characters
sort(chars.begin(), chars.end()); // greedy: pick smallest available
```

---

## Pattern 12: Rolling Hash

**Template:**
```cpp
class RollingHash {
    long long hash, power;
    const long long BASE = 31, MOD = 1e9 + 7;
    int windowSize;
public:
    RollingHash(string& s, int k) : windowSize(k) {
        hash = 0; power = 1;
        for (int i = 0; i < k - 1; i++) power = power * BASE % MOD;
        for (int i = 0; i < k; i++)
            hash = (hash * BASE + s[i]) % MOD;
    }
    void roll(char remove, char add) {
        hash = (hash - remove * power % MOD + MOD) % MOD;
        hash = (hash * BASE + add) % MOD;
    }
    long long getHash() { return hash; }
};
```

---

## Pattern 13: Prefix Function (KMP LPS)

```cpp
// Prefix function (LPS array)
vector<int> prefixFunction(string s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

// Uses:
// 1. Pattern matching (KMP)
// 2. Find period of string: period = n - pi[n-1]
// 3. Count occurrences of pattern in text
```

---

## Pattern 14: String Transformation

**Identification Clues:**
- "Can string A become string B with operations?"
- "Minimum operations to transform"
- "Edit distance"

```cpp
// Check if s can become t by removing characters
bool canTransform(string s, string t) {
    int j = 0;
    for (int i = 0; i < s.length() && j < t.length(); i++) {
        if (s[i] == t[j]) j++;
    }
    return j == t.length(); // subsequence check
}
```

---

## Pattern 15: Word Processing

**Identification Clues:**
- "Reverse words in sentence"
- "Remove extra spaces"
- "Count words"
- "Word break"

```cpp
// Reverse words in a string
string reverseWords(string s) {
    // Trim and split
    stringstream ss(s);
    vector<string> words;
    string word;
    while (ss >> word) words.push_back(word);
    
    // Reverse word order
    reverse(words.begin(), words.end());
    
    // Join
    string result = "";
    for (int i = 0; i < words.size(); i++) {
        if (i) result += " ";
        result += words[i];
    }
    return result;
}
```

---

# SECTION 8: PALINDROME MASTERY

## 8.1 Palindrome Check

**Definition:** A string that reads the same forwards and backwards.

```
"racecar" → is a palindrome
 r a c e c a r
 ↑           ↑  s[0] == s[6]
   ↑       ↑    s[1] == s[5]
     ↑   ↑      s[2] == s[4]
       ↑        s[3] (middle, always matches itself)
```

**Approaches:**

**Brute Force: Reverse and Compare**
```cpp
bool isPalinBrute(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}
// Time: O(n), Space: O(n)
```

**Optimal: Two Pointers**
```cpp
bool isPalin(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}
// Time: O(n), Space: O(1)
```

**Valid Palindrome II (skip non-alphanumeric):**
```cpp
// LC 125
bool isPalinValid(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        while (l < r && !isalnum(s[l])) l++;
        while (l < r && !isalnum(s[r])) r--;
        if (tolower(s[l]) != tolower(s[r])) return false;
        l++; r--;
    }
    return true;
}
```

---

## 8.2 Longest Palindromic Substring

**Expand Around Center Technique:**

**Intuition:** A palindrome has a center (1 character for odd length, between 2 characters for even length). Expand outward while characters match.

```
"babad"
Centers: b | a | b | a | d
         ↓   ↓   ↓   ↓   ↓
         1   1   3   1   1  (odd centers)
           1   1   1   1    (even centers)
```

**Code:**
```cpp
string longestPalindrome(string s) {
    int n = s.length();
    int start = 0, maxLen = 1;
    
    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
            l--; r++;
        }
    };
    
    for (int i = 0; i < n; i++) {
        expand(i, i);     // odd length palindromes
        expand(i, i+1);   // even length palindromes
    }
    
    return s.substr(start, maxLen);
}
// Time: O(n²), Space: O(1)
```

**Dry Run for "babad":**
```
i=0 (center='b'): expand(0,0)
  l=0,r=0: 'b'=='b' → len=1, start=0, expand: l=-1 stop
  expand(0,1): 'b'≠'a' → stop

i=1 (center='a'): expand(1,1)
  l=1,r=1: 'a'=='a' → len=1, expand
  l=0,r=2: 'b'=='b' → len=3 > 1, start=0, maxLen=3, expand
  l=-1 → stop
  expand(1,2): 'a'≠'b' → stop

i=2 (center='b'): expand(2,2)
  l=2,r=2: len=1, expand
  l=1,r=3: 'a'=='a' → len=3 (same as current max)
  l=0,r=4: 'b'≠'d' → stop

Result: s.substr(0,3) = "bab"
(Both "bab" and "aba" are valid; output depends on first found)
```

---

## 8.3 Count Palindromic Substrings

```cpp
// Count all palindromic substrings (LC 647)
int countSubstrings(string s) {
    int n = s.length(), count = 0;
    
    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            count++;
            l--; r++;
        }
    };
    
    for (int i = 0; i < n; i++) {
        expand(i, i);   // odd
        expand(i, i+1); // even
    }
    return count;
}
// Time: O(n²), Space: O(1)
```

**Dry Run for "abc":**
```
i=0: expand(0,0): "a" → count=1; stop
     expand(0,1): 'a'≠'b' → stop
i=1: expand(1,1): "b" → count=2; expand: 'a'≠'c' → stop
     expand(1,2): 'b'≠'c' → stop
i=2: expand(2,2): "c" → count=3; stop
     expand(2,3): r out of bounds → stop
Result: 3 (each single character is a palindrome)
```

---

## 8.4 Longest Palindromic Prefix/Suffix

```cpp
// Longest palindromic prefix
// Approach: Concatenate s + '#' + reverse(s), find KMP LPS
string longestPalindromicPrefix(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    string combined = s + "#" + rev;
    vector<int> lps = buildLPS(combined);
    return s.substr(0, lps.back());
}
```

---

# SECTION 9: ANAGRAM MASTERY

## 9.1 Valid Anagram (LC 242)

**Definition:** Two strings are anagrams if they contain the same characters with the same frequencies.

```cpp
// Method 1: Sort and compare O(n log n)
bool isAnagramSort(string s, string t) {
    if (s.length() != t.length()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

// Method 2: Frequency array O(n) time, O(1) space
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    int freq[26] = {0};
    for (char c : s) freq[c - 'a']++;
    for (char c : t) {
        if (--freq[c - 'a'] < 0) return false;
    }
    return true;
}
```

**Dry Run for s="anagram", t="nagaram":**
```
After processing s: freq[a]=3, freq[n]=1, freq[g]=1, freq[r]=1, freq[m]=1

Processing t:
'n': freq[n]=0
'a': freq[a]=2
'g': freq[g]=0
'a': freq[a]=1
'r': freq[r]=0
'a': freq[a]=0
'm': freq[m]=0
All freq = 0 → true (valid anagram)
```

---

## 9.2 Group Anagrams (LC 49)

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string& s : strs) {
        string key = s;
        sort(key.begin(), key.end()); // canonical form
        mp[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& [key, group] : mp) result.push_back(group);
    return result;
}

// Better key: frequency signature (avoids O(k log k) sort)
string getFreqKey(string& s) {
    int freq[26] = {0};
    for (char c : s) freq[c-'a']++;
    string key = "";
    for (int i = 0; i < 26; i++)
        key += to_string(freq[i]) + "#";
    return key;
}
```

**Example:**
```
Input: ["eat","tea","tan","ate","nat","bat"]

Sorted keys:
"eat" → "aet"
"tea" → "aet"  ← same group
"tan" → "ant"
"ate" → "aet"  ← same group
"nat" → "ant"  ← same group
"bat" → "abt"

Output: [["eat","tea","ate"],["tan","nat"],["bat"]]
```

---

## 9.3 Find All Anagrams in String (LC 438)

```cpp
vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    int n = s.length(), m = p.length();
    if (n < m) return result;
    
    int pFreq[26] = {}, wFreq[26] = {};
    for (char c : p) pFreq[c - 'a']++;
    for (int i = 0; i < m; i++) wFreq[s[i] - 'a']++;
    
    if (equal(pFreq, pFreq+26, wFreq)) result.push_back(0);
    
    for (int i = m; i < n; i++) {
        wFreq[s[i] - 'a']++;          // add new right char
        wFreq[s[i-m] - 'a']--;        // remove old left char
        if (equal(pFreq, pFreq+26, wFreq))
            result.push_back(i - m + 1);
    }
    return result;
}
// Time: O(n), Space: O(1)
```

---

# SECTION 10: SUBSTRING MASTERY

## 10.1 Substring vs Subsequence

```
String: "abcde"

SUBSTRING (contiguous):
┌─┬─┬─┬─┬─┐
│a│b│c│d│e│
└─┴─┴─┴─┴─┘
 ↑ ↑ ↑     → "abc" is a substring (indices 0,1,2 — contiguous)
       ↑ ↑ → "de" is a substring

SUBSEQUENCE (not necessarily contiguous):
"ace" is a subsequence (pick indices 0, 2, 4)
 a _ c _ e
"bd" is a subsequence (pick indices 1, 3)
```

| Property | Substring | Subsequence |
|----------|-----------|-------------|
| Contiguous? | YES | NO (can skip) |
| Count of n-char string | n(n+1)/2 + 1 (incl. "") | 2^n |
| Finding all | O(n²) | O(2^n) brute |

---

## 10.2 Enumerate All Substrings

```cpp
// All substrings: O(n²) count, O(n³) with substr copy
void allSubstrings(string s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << s.substr(i, j - i + 1) << "\n";
        }
    }
}
// Total substrings = n*(n+1)/2
```

**Visualization for "abc":**
```
i\j  0    1    2
0    "a"  "ab" "abc"
1         "b"  "bc"
2               "c"
```

---

## 10.3 Longest Substring Without Repeating Characters (LC 3)

```cpp
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int left = 0, maxLen = 0;
    
    for (int right = 0; right < s.length(); right++) {
        // If character was seen and is inside current window
        if (lastSeen.count(s[right]) && lastSeen[s[right]] >= left) {
            left = lastSeen[s[right]] + 1; // shrink from left
        }
        lastSeen[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
```

**Dry Run for "abcabcbb":**
```
right=0: 'a' not seen → lastSeen={a:0}, window=[0,0], len=1
right=1: 'b' not seen → lastSeen={a:0,b:1}, window=[0,1], len=2
right=2: 'c' not seen → lastSeen={a:0,b:1,c:2}, window=[0,2], len=3
right=3: 'a' seen at 0 ≥ left=0 → left=1
         lastSeen={a:3,b:1,c:2}, window=[1,3], len=3
right=4: 'b' seen at 1 ≥ left=1 → left=2
         window=[2,4], len=3
right=5: 'c' seen at 2 ≥ left=2 → left=3
         window=[3,5], len=3
right=6: 'b' seen at 4 ≥ left=3 → left=5
         window=[5,6], len=2
right=7: 'b' seen at 6 ≥ left=5 → left=7
         window=[7,7], len=1
Result: 3
```

---

## 10.4 Minimum Window Substring (LC 76)

```cpp
string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    
    int left = 0, valid = 0;
    int start = 0, minLen = INT_MAX;
    
    for (int right = 0; right < s.length(); right++) {
        char c = s[right];
        window[c]++;
        if (need.count(c) && window[c] == need[c]) valid++;
        
        // Shrink while valid
        while (valid == need.size()) {
            // Update minimum
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            // Remove left
            char d = s[left++];
            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
// Time: O(n), Space: O(|t|)
```

---

# SECTION 11: IMPORTANT STRING ALGORITHMS

## 11.1 Manacher's Algorithm

**Definition:** Finds all palindromic substrings in O(n) time.

**Key Insight:** Transform string to insert separators, removing odd/even distinction.

**Transformation:**
```
"abba" → "#a#b#b#a#"
"aba"  → "#a#b#a#"

This ensures every palindrome has a unique center in the transformed string.
```

**P array:** P[i] = radius of longest palindrome centered at i (in transformed string)

```cpp
string longestPalinManacher(string s) {
    // Transform
    string t = "#";
    for (char c : s) { t += c; t += '#'; }
    int n = t.length();
    vector<int> P(n, 0);
    int center = 0, right = 0; // rightmost palindrome boundary
    
    for (int i = 0; i < n; i++) {
        if (i < right) {
            int mirror = 2 * center - i;
            P[i] = min(right - i, P[mirror]);
        }
        // Try to expand
        int l = i - P[i] - 1, r = i + P[i] + 1;
        while (l >= 0 && r < n && t[l] == t[r]) {
            P[i]++;
            l--; r++;
        }
        // Update center/right
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
    }
    
    // Find max
    int maxLen = 0, centerIdx = 0;
    for (int i = 0; i < n; i++) {
        if (P[i] > maxLen) { maxLen = P[i]; centerIdx = i; }
    }
    return s.substr((centerIdx - maxLen) / 2, maxLen);
}
// Time: O(n), Space: O(n)
```

**P-array Dry Run for "abba":**
```
t = "#a#b#b#a#"
i:  0 1 2 3 4 5 6 7 8

P[0]='#': try expand → boundaries → P[0]=0
P[1]='a': expand: t[0]='#'==t[2]='#' → P[1]=1 → 'a'==t[3]='b'? no
          center=1, right=2
P[2]='#': i=2 < right=2? no. expand: t[1]='a'==t[3]='b'? no. P[2]=0
...
P[4]='b': i=4 > right=2, expand:
  t[3]='b'==t[5]='b'→ P[4]=1
  t[2]='#'==t[6]='#'→ P[4]=2
  t[1]='a'==t[7]='a'→ P[4]=3
  t[0]='#'==t[8]='#'→ P[4]=4
  out of bounds → P[4]=4
  center=4, right=8
Max P = 4 at center=4
Palindrome = s.substr((4-4)/2, 4) = s.substr(0, 4) = "abba"
```

---

## 11.2 String Compression / Run-Length Encoding

```cpp
// Run-Length Encoding: "aabcccccaaa" → "a2bc5a3"
string rleEncode(string s) {
    string result = "";
    int i = 0, n = s.length();
    while (i < n) {
        char c = s[i];
        int count = 0;
        while (i < n && s[i] == c) { count++; i++; }
        result += c;
        if (count > 1) result += to_string(count);
    }
    return result;
}

// Decode RLE: "a2bc5a3" → "aabcccccaaa"
string rleDecode(string s) {
    string result = "";
    int i = 0, n = s.length();
    while (i < n) {
        char c = s[i++];
        int count = 0;
        while (i < n && isdigit(s[i])) {
            count = count * 10 + (s[i++] - '0');
        }
        if (count == 0) count = 1;
        result += string(count, c);
    }
    return result;
}
```

**Dry Run for "aabcccccaaa":**
```
i=0: c='a', count: a,a → count=2, i=2 → result="a2"
i=2: c='b', count: b → count=1, i=3 → result="a2b"
i=3: c='c', count: c,c,c,c,c → count=5, i=8 → result="a2bc5"
i=8: c='a', count: a,a,a → count=3, i=11 → result="a2bc5a3"
```

---

## 11.3 LPS Array Construction (Detailed)

See Section 6.3 (KMP) for code. Key uses:

```
LPS Applications:
1. Pattern matching (KMP)
2. Shortest period of string: period = n - lps[n-1]
3. Longest palindromic prefix (with reversed string)
4. Number of distinct borders of string

Period example:
"abcabc" → lps = [0,0,0,1,2,3]
period = 6 - 3 = 3 ("abc" repeats)

"abaabab" → lps = [0,0,1,1,2,3,4]  
Not a perfect repetition since n % (n - lps[n-1]) ≠ 0
```

---

# SECTION 12: SLIDING WINDOW ON STRINGS

## 12.1 Longest Substring with All Unique Characters (LC 3)

(See Section 10.3 for complete solution)

## 12.2 Longest Repeating Character Replacement (LC 424)

**Problem:** You can replace at most k characters. Find the longest substring with all same characters.

**Intuition:** In a valid window, `(window_size - max_frequency) <= k`

```cpp
int characterReplacement(string s, int k) {
    int freq[26] = {0};
    int left = 0, maxFreq = 0, result = 0;
    
    for (int right = 0; right < s.length(); right++) {
        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right] - 'A']);
        
        // Window invalid: replacements needed > k
        while ((right - left + 1) - maxFreq > k) {
            freq[s[left] - 'A']--;
            left++;
            // Note: we don't update maxFreq (lazy deletion optimization)
        }
        result = max(result, right - left + 1);
    }
    return result;
}
// Time: O(n), Space: O(1)
```

**Dry Run for s="AABABBA", k=1:**
```
right=0: 'A', freq[A]=1, maxFreq=1, window=1, replacements=0 ≤ 1 → ok
right=1: 'A', freq[A]=2, maxFreq=2, window=2, rep=0 → ok, result=2
right=2: 'B', freq[B]=1, maxFreq=2, window=3, rep=1 ≤ 1 → ok, result=3
right=3: 'A', freq[A]=3, maxFreq=3, window=4, rep=1 → ok, result=4
right=4: 'B', freq[B]=2, maxFreq=3, window=5, rep=2 > 1 → shrink
  left=0→1: freq[A]=2, window=4, rep=4-3=1 ≤ 1 → ok
right=5: 'B', freq[B]=3, maxFreq=3, window=5, rep=2 > 1 → shrink
  left=1→2: freq[A]=1, window=4, rep=4-3=1 → ok
right=6: 'A', freq[A]=2, maxFreq=3, window=5, rep=2 > 1 → shrink
  left=2→3: freq[B]=2, window=4, rep=4-3=1 → ok
Result: 4 ("AABA" or "ABBA")
```

---

## 12.3 Permutation in String (LC 567)

```cpp
bool checkInclusion(string pattern, string text) {
    int n = text.length(), m = pattern.length();
    if (n < m) return false;
    
    int pFreq[26] = {}, wFreq[26] = {};
    for (char c : pattern) pFreq[c-'a']++;
    for (int i = 0; i < m; i++) wFreq[text[i]-'a']++;
    
    if (equal(pFreq, pFreq+26, wFreq)) return true;
    
    for (int i = m; i < n; i++) {
        wFreq[text[i]-'a']++;
        wFreq[text[i-m]-'a']--;
        if (equal(pFreq, pFreq+26, wFreq)) return true;
    }
    return false;
}
```

---

## 12.4 Complete Sliding Window Templates

```cpp
/* ============================================
   TEMPLATE 1: FIXED SIZE WINDOW
   ============================================ */
int fixedWindow(string s, int k) {
    // Initialize window [0, k-1]
    int windowState = 0;
    for (int i = 0; i < k; i++) {
        // Process s[i]
    }
    int result = windowState;
    
    // Slide window
    for (int i = k; i < s.length(); i++) {
        // Add s[i] (right)
        // Remove s[i-k] (left)
        result = max(result, windowState);
    }
    return result;
}

/* ============================================
   TEMPLATE 2: VARIABLE SIZE WINDOW (find MAX length)
   ============================================ */
int variableWindowMax(string s) {
    unordered_map<char,int> window;
    int left = 0, result = 0;
    
    for (int right = 0; right < s.length(); right++) {
        // Add right element
        window[s[right]]++;
        
        // Shrink while INVALID
        while (/* window invalid */) {
            window[s[left]]--;
            if (window[s[left]] == 0) window.erase(s[left]);
            left++;
        }
        
        // Window is VALID, update result
        result = max(result, right - left + 1);
    }
    return result;
}

/* ============================================
   TEMPLATE 3: VARIABLE SIZE WINDOW (find MIN length)
   ============================================ */
int variableWindowMin(string s, string t) {
    unordered_map<char,int> need, window;
    for (char c : t) need[c]++;
    
    int left = 0, valid = 0, result = INT_MAX, start = 0;
    
    for (int right = 0; right < s.length(); right++) {
        char c = s[right];
        window[c]++;
        if (need.count(c) && window[c] == need[c]) valid++;
        
        // Shrink while VALID
        while (valid == (int)need.size()) {
            // Update result (smaller window)
            if (right - left + 1 < result) {
                result = right - left + 1;
                start = left;
            }
            // Remove left
            char d = s[left++];
            if (need.count(d)) {
                if (window[d] == need[d]) valid--;
                window[d]--;
            }
        }
    }
    return result == INT_MAX ? 0 : result;
}
```

---

# SECTION 13: TWO POINTERS ON STRINGS

## 13.1 Reverse String (LC 344)

```cpp
void reverseString(vector<char>& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) swap(s[l++], s[r--]);
}
// Time: O(n), Space: O(1)
```

## 13.2 Valid Palindrome II (LC 680)

**Problem:** Can we make string a palindrome by removing at most one character?

```cpp
bool validPalindrome(string s) {
    auto isPalin = [](string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    };
    
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            // Try removing either s[l] or s[r]
            return isPalin(s, l+1, r) || isPalin(s, l, r-1);
        }
        l++; r--;
    }
    return true;
}
```

## 13.3 Backspace String Compare (LC 844)

```cpp
bool backspaceCompare(string s, string t) {
    auto process = [](string& s) {
        string result = "";
        for (char c : s) {
            if (c == '#') { if (!result.empty()) result.pop_back(); }
            else result += c;
        }
        return result;
    };
    return process(s) == process(t);
}

// O(1) space: two pointers from the end
bool backspaceCompareOptimal(string s, string t) {
    int i = s.length()-1, j = t.length()-1;
    int skipS = 0, skipT = 0;
    
    while (i >= 0 || j >= 0) {
        while (i >= 0) {
            if (s[i] == '#') { skipS++; i--; }
            else if (skipS > 0) { skipS--; i--; }
            else break;
        }
        while (j >= 0) {
            if (t[j] == '#') { skipT++; j--; }
            else if (skipT > 0) { skipT--; j--; }
            else break;
        }
        if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
        if ((i >= 0) != (j >= 0)) return false;
        i--; j--;
    }
    return true;
}
```

## 13.4 Two Pointer Template

```cpp
/* ============================================
   TWO POINTER TEMPLATE: INWARD (Palindrome-style)
   ============================================ */
bool twoPointerInward(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        // Skip invalid chars if needed
        // while (l < r && !condition(s[l])) l++;
        // while (l < r && !condition(s[r])) r--;
        
        if (/* mismatch */) return false;
        l++; r--;
    }
    return true;
}

/* ============================================
   TWO POINTER TEMPLATE: SAME DIRECTION
   ============================================ */
void twoPointerSameDir(string s) {
    int slow = 0;
    for (int fast = 0; fast < s.length(); fast++) {
        if (/* condition on s[fast] */) {
            s[slow++] = s[fast]; // keep character
        }
        // else: skip s[fast]
    }
    // Effective string is s[0..slow-1]
}
```

---

# SECTION 14: HASHING ON STRINGS

## 14.1 Frequency Arrays

```cpp
// For lowercase letters only
int freq[26] = {0};
for (char c : s) freq[c - 'a']++;

// For all ASCII
int freq[128] = {0};
for (char c : s) freq[(int)c]++;

// Compare two frequency arrays
bool sameFreq(int a[], int b[], int size) {
    for (int i = 0; i < size; i++)
        if (a[i] != b[i]) return false;
    return true;
}
```

## 14.2 Hash Maps for Strings

```cpp
// Count character frequencies
unordered_map<char, int> charFreq(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    return freq;
}

// Find first non-repeating character
char firstUnique(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    for (char c : s)
        if (freq[c] == 1) return c;
    return '\0';
}

// Check if two strings have same character set
bool sameCharSet(string s, string t) {
    unordered_set<char> setS(s.begin(), s.end());
    unordered_set<char> setT(t.begin(), t.end());
    return setS == setT;
}
```

## 14.3 Polynomial Hash

```cpp
// Polynomial rolling hash: O(n) computation, O(1) comparison
class PolyHash {
    const long long BASE = 131, MOD = 1e9 + 7;
    vector<long long> h, p; // prefix hashes and powers
public:
    PolyHash(string& s) {
        int n = s.length();
        h.resize(n + 1, 0);
        p.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i+1] = (h[i] * BASE + s[i]) % MOD;
            p[i+1] = p[i] * BASE % MOD;
        }
    }
    
    // Get hash of s[l..r] in O(1)
    long long getHash(int l, int r) {
        return (h[r+1] - h[l] * p[r-l+1] % MOD + MOD) % MOD;
    }
};

// Usage: compare substrings in O(1)
PolyHash ph(s);
if (ph.getHash(0, 2) == ph.getHash(3, 5)) {
    // s[0..2] and s[3..5] are likely equal (verify to be sure)
}
```

---

# SECTION 15: STRING SORTING & ORDERING

## 15.1 Lexicographical Order

```cpp
// Sort strings lexicographically
vector<string> v = {"banana", "apple", "cherry"};
sort(v.begin(), v.end()); // {"apple", "banana", "cherry"}

// Custom comparator: sort by length, then lex
sort(v.begin(), v.end(), [](string& a, string& b) {
    if (a.length() != b.length()) return a.length() < b.length();
    return a < b;
});

// Sort characters in a string
string s = "dcba";
sort(s.begin(), s.end()); // "abcd"
```

## 15.2 Frequency-Based Sorting

```cpp
// Sort characters by frequency (descending)
// LC 451: Sort Characters By Frequency
string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    
    vector<pair<int,char>> v;
    for (auto& [c, f] : freq) v.push_back({f, c});
    sort(v.rbegin(), v.rend()); // sort by frequency desc
    
    string result = "";
    for (auto& [f, c] : v) result += string(f, c);
    return result;
}
// "tree" → "eert" or "eetr"
```

## 15.3 Custom String Sorting (Largest Number)

```cpp
// LC 179: Arrange numbers to form largest number
string largestNumber(vector<int>& nums) {
    vector<string> strs;
    for (int n : nums) strs.push_back(to_string(n));
    
    sort(strs.begin(), strs.end(), [](string& a, string& b) {
        return a + b > b + a; // compare concatenations
    });
    
    if (strs[0] == "0") return "0"; // all zeros
    string result = "";
    for (string& s : strs) result += s;
    return result;
}
// [3,30,34,5,9] → "9534330"
```

---

# SECTION 16: STRING INTERVIEW FRAMEWORK

## Decision Tree

```
Received a String Problem
          │
          ▼
    Read the problem carefully
          │
          ├─── Does it involve PATTERN MATCHING?
          │         │
          │         └── Single pattern → KMP / Z-Algorithm
          │             Multiple patterns → Rabin-Karp
          │
          ├─── Does it involve a PALINDROME?
          │         │
          │         └── Check → Two Pointers
          │             Longest → Expand Around Center / Manacher
          │             Count → Expand Around Center
          │
          ├─── Does it involve ANAGRAMS / PERMUTATIONS?
          │         │
          │         └── Check → Frequency Array
          │             Group → Sort each string as key
          │             Find all → Sliding Window + Freq
          │
          ├─── Does it involve a SUBSTRING (contiguous)?
          │         │
          │         └── Fixed length → Fixed Sliding Window
          │             Variable length → Variable Sliding Window
          │             With constraints → Two Pointers
          │
          ├─── Does it involve CHARACTER COUNTS / FREQUENCIES?
          │         │
          │         └── Simple count → Frequency Array (O(1) space)
          │             Complex → Hash Map
          │
          ├─── Does it involve SEARCHING?
          │         │
          │         └── In sorted → Binary Search on answer
          │             Repeated → Rolling Hash
          │
          └─── Does it involve ORDERING?
                    │
                    └── Lex order → Sort
                        Custom → Custom comparator
```

## Framework for Any String Problem

```
Step 1: Identify the output type
  - Boolean (yes/no)
  - Integer (count, length)
  - String (transformation)
  - Array (positions, groups)

Step 2: Identify the constraint
  - "All characters unique" → hash set / freq array
  - "Contiguous" → sliding window
  - "Any order" → sorting / frequency
  - "Must match exactly" → KMP / Z-algo
  - "Same letters" → anagram check

Step 3: Choose algorithm
  - O(n): Sliding window, two pointers, freq array
  - O(n log n): Sorting based
  - O(n·m): Naive matching (acceptable for small input)
  - O(n + m): KMP, Z-algorithm, Rabin-Karp

Step 4: Handle edge cases
  - Empty string
  - Single character
  - All same characters
  - Uppercase/lowercase mixing
  - Special characters / spaces
```

---

# SECTION 17: COMMON TRICKS

## 17.1 Sliding Window Tricks

```cpp
// Trick 1: Use count of "satisfied conditions" to avoid array comparison
int satisfied = 0;
// Instead of: if (equal(pFreq, pFreq+26, wFreq))
// Track satisfied++ when freq matches, satisfied-- when it breaks

// Trick 2: Don't shrink maxFreq (lazy deletion)
// In LC 424 (longest repeating char replacement), maxFreq never decreases
// This is safe because we only care about VALID windows of maximum size

// Trick 3: Two-pass for minimum — find max first, then verify
```

## 17.2 Hashing Tricks

```cpp
// Trick 1: Sort as canonical form for anagram grouping
sort(s.begin(), s.end()); // O(k log k) per string

// Trick 2: Frequency signature as key
string getKey(string s) {
    int freq[26] = {};
    for (char c : s) freq[c-'a']++;
    string key = "";
    for (int i = 0; i < 26; i++) key += to_string(freq[i]) + "#";
    return key;
}

// Trick 3: XOR trick for finding single occurrence
char findSingle(string s) {
    char x = 0;
    for (char c : s) x ^= c;
    return x; // char that appears odd times
}
```

## 17.3 Palindrome Tricks

```cpp
// Trick 1: A string is periodic iff n % (n - lps[n-1]) == 0
// Trick 2: Palindrome center count: for n chars, there are 2n-1 centers
// Trick 3: s + '#' + reverse(s) → KMP LPS[2n] = len of longest palindromic prefix
// Trick 4: Odd-length palindromes: expand from single center
//           Even-length palindromes: expand from pair
```

## 17.4 KMP Tricks

```cpp
// Trick 1: Find period of string
// period = n - lps[n-1]
// If n % period == 0, string is made of period repeating

// Trick 2: Count distinct borders
// Every prefix of lps values forms a border

// Trick 3: Concatenate pattern#text
// Z[i] == len(pattern) means pattern found at position i-len(pattern)-1 in text
```

## 17.5 Lexicographical Tricks

```cpp
// Trick 1: Lexicographically smallest rotation
// Find minimum element position, rotate there

// Trick 2: Next permutation (STL)
next_permutation(s.begin(), s.end());

// Trick 3: For "smallest string after k swaps"
// Sort the string (greedy: always take smallest available)
// But think carefully about actual swap constraints!

// Trick 4: String comparison is O(min(|a|,|b|)) — not O(1)!
// When sorting many strings, total comparisons matter
```

---

# SECTION 18: COMMON MISTAKES

## 18.1 Off-by-One Errors

```cpp
// WRONG: accessing s[n] which doesn't exist
for (int i = 0; i <= s.length(); i++) // should be i < s.length()

// WRONG: substring going out of bounds
s.substr(i, j - i); // should be j - i + 1 for inclusive end

// WRONG: palindrome check stops too early
while (l <= r) // should be l < r (l == r is a single char, always palindrome)

// WRONG: sliding window init
for (int i = 0; i < k; i++) // correct for init
for (int i = k; i < n; i++) // correct for sliding (not i = k-1)
```

## 18.2 Substring Boundary Errors

```cpp
// s.substr(start, LENGTH) — second arg is LENGTH, not end index!
// In Python: s[start:end] — end is EXCLUSIVE
// In Java: s.substring(start, end) — end is EXCLUSIVE

// WRONG (C++):
s.substr(2, 5); // chars at indices 2,3,4,5,6 (5 chars starting at 2)

// Conversion:
// If you have [l, r] inclusive → substr(l, r - l + 1)
// If you have [l, r) exclusive → substr(l, r - l)
```

## 18.3 Case Sensitivity Bugs

```cpp
// WRONG: comparing without normalization
if (s == t) // fails if "Hello" vs "hello"

// CORRECT: normalize first
transform(s.begin(), s.end(), s.begin(), ::tolower);
transform(t.begin(), t.end(), t.begin(), ::tolower);
if (s == t) // now case-insensitive

// WRONG: frequency array for mixed case
int freq[26] = {};
freq[s[i] - 'a']++; // fails if s[i] is uppercase!

// CORRECT:
freq[tolower(s[i]) - 'a']++;
// OR separate arrays for upper and lower
```

## 18.4 Unicode Issues

```cpp
// WRONG: treating char as always 1 byte
// In C++, char is 1 byte but UTF-8 characters can be 2-4 bytes
// "中" in UTF-8 = 3 bytes → s[0],s[1],s[2] are not the same as "中"[0]

// CORRECT for Unicode in C++: use wstring or handle multi-byte chars
wstring ws = L"中文"; // wide string

// In competitive programming: if problem says only lowercase letters,
// you're safe. Otherwise, ask/clarify.
```

## 18.5 Hash Collision Mistakes

```cpp
// WRONG: relying on hash match without verification
if (windowHash == patternHash) {
    // Assume match — WRONG! Could be collision
}

// CORRECT: verify on hash match
if (windowHash == patternHash) {
    if (text.substr(i, m) == pattern) { // O(m) verification
        matches.push_back(i);
    }
}

// Better: double hashing (two different MOD values)
// Reduces collision probability to ~1/(MOD1 * MOD2)
```

## 18.6 Sliding Window Bugs

```cpp
// WRONG: forgetting to shrink window
for (int right = 0; right < n; right++) {
    add(s[right]);
    result = max(result, right - left + 1); // BUG: window might be invalid!
}

// CORRECT: check validity before updating result
for (int right = 0; right < n; right++) {
    add(s[right]);
    while (!valid()) { remove(s[left++]); } // shrink
    result = max(result, right - left + 1); // now window is valid
}

// WRONG: updating both left and right inside while loop
// CORRECT: only move left inside while, right moves in outer for

// WRONG: For minimum window, updating result OUTSIDE while loop
// CORRECT: update result INSIDE while loop (when window is valid AND can shrink)
```

---

# SECTION 19: COMPLETE STRING QUESTION LIST

## Easy (50 Questions)

| # | Problem Name | Platform | Pattern |
|---|-------------|----------|---------|
| 1 | Reverse String | LC 344 | Two Pointers |
| 2 | Reverse Vowels of a String | LC 345 | Two Pointers |
| 3 | Valid Palindrome | LC 125 | Two Pointers |
| 4 | Valid Anagram | LC 242 | Frequency Count |
| 5 | First Unique Character | LC 387 | Frequency Count |
| 6 | Ransom Note | LC 383 | Frequency Count |
| 7 | Find the Difference | LC 389 | Frequency / XOR |
| 8 | Is Subsequence | LC 392 | Two Pointers |
| 9 | Longest Common Prefix | LC 14 | String comparison |
| 10 | Count and Say | LC 38 | Simulation |
| 11 | Roman to Integer | LC 13 | Parsing |
| 12 | Integer to Roman | LC 12 | Greedy |
| 13 | String to Integer (atoi) | LC 8 | Parsing |
| 14 | Add Binary | LC 67 | Simulation |
| 15 | Reverse String II | LC 541 | Simulation |
| 16 | Reverse Words in a String III | LC 557 | Two Pointers |
| 17 | To Lower Case | LC 709 | Character manipulation |
| 18 | Detect Capital | LC 520 | String check |
| 19 | Length of Last Word | LC 58 | Traversal |
| 20 | Jewels and Stones | LC 771 | Frequency Count |
| 21 | Unique Morse Code Words | LC 804 | Hashing |
| 22 | Goat Latin | LC 824 | String manipulation |
| 23 | Uncommon Words from Two Sentences | LC 884 | Frequency Count |
| 24 | Number of Lines to Write String | LC 806 | Simulation |
| 25 | Keyboard Row | LC 500 | Set lookup |
| 26 | Student Attendance Record I | LC 551 | Parsing |
| 27 | Reverse Words in a String (easy) | LC 557 | Split/Reverse |
| 28 | Most Common Word | LC 819 | Frequency + Exclusion |
| 29 | Unique Email Addresses | LC 929 | String parsing |
| 30 | License Key Formatting | LC 482 | Simulation |
| 31 | Excel Sheet Column Number | LC 171 | Math + String |
| 32 | Excel Sheet Column Title | LC 168 | Math + String |
| 33 | Implement strStr() | LC 28 | Pattern Matching |
| 34 | Count Binary Substrings | LC 696 | Two Pointers |
| 35 | Robot Return to Origin | LC 657 | Simulation |
| 36 | Fizz Buzz | LC 412 | Simulation |
| 37 | Buddy Strings | LC 859 | Frequency Count |
| 38 | Verifying an Alien Dictionary | LC 953 | Custom Sort |
| 39 | Decrypt String from Alphabet to Integer | LC 1309 | Parsing |
| 40 | Check if Two String Arrays are Equivalent | LC 1662 | String join |
| 41 | Remove Vowels from a String | LC 1119 | Filtering |
| 42 | Defanging an IP Address | LC 1108 | Replacement |
| 43 | Number of Segments in a String | LC 434 | Count words |
| 44 | Repeated Substring Pattern | LC 459 | KMP / Pattern |
| 45 | Valid Palindrome II | LC 680 | Two Pointers |
| 46 | Reverse Only Letters | LC 917 | Two Pointers |
| 47 | Shortest Distance to a Character | LC 821 | Two-pass |
| 48 | Largest Substring Between Two Equal Chars | LC 1624 | Last seen |
| 49 | Check if the Sentence Is Pangram | LC 1832 | Frequency |
| 50 | Truncate Sentence | LC 1816 | Parsing |

---

## Medium (100 Questions)

| # | Problem Name | Platform | Pattern |
|---|-------------|----------|---------|
| 1 | Longest Substring Without Repeating Characters | LC 3 | Sliding Window |
| 2 | Longest Palindromic Substring | LC 5 | Expand Center |
| 3 | Zigzag Conversion | LC 6 | Simulation |
| 4 | Group Anagrams | LC 49 | Hashing |
| 5 | Multiply Strings | LC 43 | Simulation |
| 6 | Jump Game | LC 55 | Greedy |
| 7 | Permutations (string-based) | LC 46 | Backtracking |
| 8 | Decode Ways | LC 91 | DP on string |
| 9 | Word Search | LC 79 | DFS |
| 10 | Restore IP Addresses | LC 93 | Backtracking |
| 11 | Reverse Words in a String | LC 151 | Two Pointers |
| 12 | Minimum Window Substring | LC 76 | Sliding Window |
| 13 | Longest Repeating Character Replacement | LC 424 | Sliding Window |
| 14 | Find All Anagrams in a String | LC 438 | Sliding Window |
| 15 | Permutation in String | LC 567 | Sliding Window |
| 16 | Decode String | LC 394 | Stack |
| 17 | Check Inclusion | LC 567 | Frequency / Window |
| 18 | Isomorphic Strings | LC 205 | Character Mapping |
| 19 | Word Pattern | LC 290 | Character Mapping |
| 20 | Palindromic Substrings | LC 647 | Expand Center |
| 21 | Longest Palindrome | LC 409 | Frequency Count |
| 22 | Sort Characters By Frequency | LC 451 | Freq + Sort |
| 23 | Repeated DNA Sequences | LC 187 | Rolling Hash |
| 24 | Encode and Decode Strings | LC 271 | String format |
| 25 | Sentence Screen Fitting | LC 418 | Simulation |
| 26 | Bold Words in String | LC 758 | Interval merge |
| 27 | Complex Number Multiplication | LC 537 | Parsing |
| 28 | Optimal Division | LC 553 | Math + String |
| 29 | Longest Word in Dictionary | LC 720 | Sorting + Hashing |
| 30 | Expressive Words | LC 809 | Two Pointers |
| 31 | Find and Replace in String | LC 833 | Simulation |
| 32 | Unique Letter String | LC 828 | Contribution technique |
| 33 | Longest Turbulent Subarray | LC 978 | Sliding Window |
| 34 | String Without AAA or BBB | LC 984 | Greedy |
| 35 | Shifting Letters | LC 848 | Prefix Sum |
| 36 | Reorder Data in Log Files | LC 937 | Custom Sort |
| 37 | Sum of Subarray Minimums | LC 907 | Stack (pattern) |
| 38 | Interval List Intersections | LC 986 | Two Pointers |
| 39 | Compare Version Numbers | LC 165 | Parsing |
| 40 | Remove Duplicate Letters | LC 316 | Stack + Greedy |
| 41 | Largest Number | LC 179 | Custom Sort |
| 42 | Maximum Product of Word Lengths | LC 318 | Bit masking |
| 43 | Bulls and Cows | LC 299 | Freq Count |
| 44 | Additive Number | LC 306 | Backtracking |
| 45 | Count Numbers with Unique Digits | LC 357 | Combinatorics |
| 46 | Flatten Nested List Iterator | LC 341 | Stack |
| 47 | Decode Ways II | LC 639 | DP |
| 48 | K-th Symbol in Grammar | LC 779 | Recursion |
| 49 | String Compression | LC 443 | Two Pointers |
| 50 | Reorganize String | LC 767 | Greedy + Heap |
| 51 | Custom Sort String | LC 791 | Sorting |
| 52 | Rotated Digits | LC 788 | Simulation |
| 53 | Unique Substrings in Wraparound String | LC 467 | Sliding Window |
| 54 | Find All Duplicates in Array | LC 442 | Freq trick |
| 55 | Count Unique Characters | LC 828 | Contribution |
| 56 | Long Pressed Name | LC 925 | Two Pointers |
| 57 | Reorder Log Files | LC 937 | Custom sort |
| 58 | Flip Binary String | LC Custom | Sliding Window |
| 59 | Minimum Add to Make Parentheses Valid | LC 921 | Stack / Count |
| 60 | Score of Parentheses | LC 856 | Stack |
| 61 | Longest Common Subsequence | LC 1143 | DP |
| 62 | Number of Matching Subsequences | LC 792 | Multi-pointer |
| 63 | Letter Combinations of Phone Number | LC 17 | Backtracking |
| 64 | Generate Parentheses | LC 22 | Backtracking |
| 65 | Palindrome Partitioning | LC 131 | Backtrack + DP |
| 66 | ZigZag Conversion | LC 6 | Simulation |
| 67 | Longest Substring with At Most K Distinct | LC 340 | Sliding Window |
| 68 | Longest Substring with At Most 2 Distinct | LC 159 | Sliding Window |
| 69 | Fruit Into Baskets | LC 904 | Sliding Window |
| 70 | Max Consecutive Ones III | LC 1004 | Sliding Window |
| 71 | Minimum Size Subarray Sum | LC 209 | Sliding Window |
| 72 | Subarrays with K Different Integers | LC 992 | Sliding Window |
| 73 | Binary Subarrays With Sum | LC 930 | Sliding Window |
| 74 | Count Number of Nice Subarrays | LC 1248 | Sliding Window |
| 75 | Shortest Subarray with Sum at Least K | LC 862 | Deque |
| 76 | Implement Trie (Prefix Tree) | LC 208 | Trie |
| 77 | Design Add and Search Words | LC 211 | Trie + DFS |
| 78 | Replace Words | LC 648 | Trie |
| 79 | Camelcase Matching | LC 1023 | Two Pointers |
| 80 | Longest Chunked Palindrome | LC 1147 | Greedy |
| 81 | Search Suggestions System | LC 1268 | Sorting + Binary Search |
| 82 | Minimum Remove to Make Valid Parentheses | LC 1249 | Stack |
| 83 | Check if a String Contains All Binary Codes | LC 1461 | Rolling Hash |
| 84 | Thousand Separator | LC 1556 | Simulation |
| 85 | Count Substrings with Only One Distinct Letter | LC 1180 | Math |
| 86 | Number of Substrings Containing All 3 Chars | LC 1358 | Sliding Window |
| 87 | Get Equal Substrings Within Budget | LC 1208 | Sliding Window |
| 88 | Minimum Operations to Reduce X to Zero | LC 1658 | Sliding Window |
| 89 | Longest Subarray with Maximum Bitwise AND | LC 2419 | Observation |
| 90 | Frequency of the Most Frequent Element | LC 1838 | Sliding Window |
| 91 | Maximum Erasure Value | LC 1695 | Sliding Window |
| 92 | Maximize the Confusion of an Exam | LC 2024 | Sliding Window |
| 93 | Maximum Points You Can Obtain | LC 1423 | Sliding Window |
| 94 | Minimum Consecutive Cards to Pick Up | LC 2260 | Hashing |
| 95 | K Radius Subarray Averages | LC 2090 | Sliding Window |
| 96 | Subarray Product Less Than K | LC 713 | Sliding Window |
| 97 | Partition Labels | LC 763 | Greedy |
| 98 | Break a Palindrome | LC 1328 | Greedy |
| 99 | Check if String is a Prefix of Array | LC 1961 | String comparison |
| 100 | Lexicographically Smallest Equivalent String | LC 1061 | Union-Find |

---

## Hard (50 Questions)

| # | Problem Name | Platform | Pattern |
|---|-------------|----------|---------|
| 1 | Minimum Window Substring | LC 76 | Sliding Window |
| 2 | Regular Expression Matching | LC 10 | DP / Recursion |
| 3 | Wildcard Matching | LC 44 | DP / Greedy |
| 4 | Edit Distance | LC 72 | DP |
| 5 | Longest Valid Parentheses | LC 32 | Stack / DP |
| 6 | Distinct Subsequences | LC 115 | DP |
| 7 | Interleaving String | LC 97 | DP |
| 8 | Scramble String | LC 87 | DP / Recursion |
| 9 | Text Justification | LC 68 | Simulation |
| 10 | String to Integer (atoi) Hard variant | LC 8 | FSM parsing |
| 11 | Palindrome Pairs | LC 336 | Hashing |
| 12 | Longest Substring with At Most K Distinct | LC 340 | Sliding Window |
| 13 | Substring with Concatenation of All Words | LC 30 | Sliding Window + Hash |
| 14 | Find Minimum in Rotated Sorted Array | LC 153 | Binary Search |
| 15 | Count of Palindromic Substrings (all) | LC 647 | Manacher |
| 16 | Shortest Palindrome | LC 214 | KMP |
| 17 | Minimum Palindrome Partition | LC 132 | DP |
| 18 | Burst Balloons | LC 312 | Interval DP |
| 19 | Strange Printer | LC 664 | Interval DP |
| 20 | Zuma Game | LC 488 | DFS + Memoization |
| 21 | Remove Boxes | LC 546 | DP |
| 22 | Count Different Palindromic Subsequences | LC 730 | DP |
| 23 | Word Break II | LC 140 | Backtracking + DP |
| 24 | Concatenated Words | LC 472 | DP + Trie |
| 25 | Longest Word in Dictionary through Deleting | LC 524 | Two Pointers |
| 26 | Count of Smaller Numbers After Self | LC 315 | Merge Sort |
| 27 | Maximum Frequency Stack | LC 895 | Hashing |
| 28 | Unique Substrings in Wraparound String | LC 467 | DP |
| 29 | Find the Closest Palindrome | LC 564 | Math + String |
| 30 | Encode String with Shortest Length | LC 471 | DP |
| 31 | Minimum Cost to Cut a Stick | LC 1547 | Interval DP |
| 32 | Smallest Range Covering Elements from K Lists | LC 632 | Sliding Window + Heap |
| 33 | Stamping the Sequence | LC 936 | Greedy Reverse |
| 34 | Expressive Words (Hard version) | Custom | Two Pointers |
| 35 | Longest Duplicate Substring | LC 1044 | Rabin-Karp + Binary Search |
| 36 | String Transforms Into Another String | LC 1153 | Graph (characters) |
| 37 | Check if Word Can Be Placed in Crossword | LC 2018 | Simulation |
| 38 | Maximize Number of Subsequences | LC 2207 | Greedy |
| 39 | Count Palindromes (Hard) | LC 2484 | Contribution + Manacher |
| 40 | Shortest Superstring | LC 943 | DP + Bitmask |
| 41 | Minimum Number of Steps to Make Two Strings Anagram II | LC 2186 | Frequency |
| 42 | Minimum ASCII Delete Sum | LC 712 | DP (LCS variant) |
| 43 | Delete Operation for Two Strings | LC 583 | DP (LCS) |
| 44 | Maximize the Beauty of the Garden | LC 1817 | Hashing |
| 45 | Sum of Beauty of All Substrings | LC 1781 | Sliding Window |
| 46 | Count Anagrams | LC 2514 | Combinatorics + Freq |
| 47 | Rearrange String k Distance Apart | LC 358 | Greedy + Heap |
| 48 | Basic Calculator III | LC 772 | Stack + Parsing |
| 49 | Find All Good Strings | LC 1397 | DP + KMP |
| 50 | Number of Ways to Separate Numbers | LC 1977 | DP + LCP |

---

# SECTION 20: REVISION CHEAT SHEET

## String Cheat Sheet

```cpp
// ════════════════════════════════════════════════
//  C++ STRING QUICK REFERENCE
// ════════════════════════════════════════════════
string s = "hello";
s.length()        // 5
s[i]              // char at i (no bounds check)
s.at(i)           // char at i (bounds checked)
s.substr(i, len)  // substring of length len from i
s.find(c)         // first position of c (string::npos if not found)
s.rfind(c)        // last position of c
s += "world"      // append
s.push_back('!')  // append char
s.pop_back()      // remove last char
s.insert(i, "x") // insert at position i
s.erase(i, len)   // erase len chars from i
s.replace(i,len,t)// replace
sort(s.begin(), s.end())          // sort chars
reverse(s.begin(), s.end())       // reverse
transform(s.begin(),s.end(),s.begin(),::tolower) // to lower
stoi(s), stol(s), stof(s)        // string to number
to_string(42)                     // number to string
```

## Character Cheat Sheet

```cpp
// ════════════════════════════════════════════════
//  CHARACTER QUICK REFERENCE
// ════════════════════════════════════════════════
isalpha(c)   // is letter
isdigit(c)   // is digit 0-9
isalnum(c)   // is letter or digit
islower(c)   // is lowercase
isupper(c)   // is uppercase
isspace(c)   // is whitespace
tolower(c)   // convert to lowercase
toupper(c)   // convert to uppercase

// ASCII values (memorize!)
'A'=65, 'Z'=90
'a'=97, 'z'=122
'0'=48, '9'=57
' '=32, '\n'=10

// Key formulas
c - 'a'      // 0-25 index for lowercase
c - 'A'      // 0-25 index for uppercase
c - '0'      // digit value
c + 32       // uppercase to lowercase (manual)
c - 32       // lowercase to uppercase (manual)
```

## Complexity Cheat Sheet

```
Operation           │ Time       │ Space
────────────────────┼────────────┼──────────
Access s[i]         │ O(1)       │ O(1)
Length              │ O(1)       │ O(1)
Append char         │ O(1) amort │ O(1)
Concatenate         │ O(n+m)     │ O(n+m)
Substring (length k)│ O(k)       │ O(k)
Find/Search (naive) │ O(n·m)     │ O(1)
KMP/Z search        │ O(n+m)     │ O(m)
Rabin-Karp          │ O(n+m) avg │ O(1)
Sort string (len n) │ O(n log n) │ O(1)
Reverse             │ O(n)       │ O(1)
Freq count (26 char)│ O(n)       │ O(1)
All substrings      │ O(n²)      │ O(n²)
Manacher (longest P)│ O(n)       │ O(n)
```

## Sliding Window Template

```cpp
// FIND MAXIMUM WINDOW SIZE
int slidingWindowMax(string s) {
    unordered_map<char,int> window;
    int l = 0, result = 0;
    for (int r = 0; r < s.size(); r++) {
        window[s[r]]++;                        // expand right
        while (/* invalid */) {
            if (--window[s[l]] == 0) window.erase(s[l]);
            l++;                               // shrink left
        }
        result = max(result, r - l + 1);       // update
    }
    return result;
}

// FIND MINIMUM WINDOW SIZE
string slidingWindowMin(string s, string t) {
    unordered_map<char,int> need, window;
    for (char c : t) need[c]++;
    int l = 0, valid = 0, start = 0, minLen = INT_MAX;
    for (int r = 0; r < s.size(); r++) {
        window[s[r]]++;
        if (need.count(s[r]) && window[s[r]] == need[s[r]]) valid++;
        while (valid == (int)need.size()) {    // window valid → shrink
            if (r - l + 1 < minLen) { minLen = r-l+1; start = l; }
            if (need.count(s[l]) && window[s[l]] == need[s[l]]) valid--;
            window[s[l++]]--;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
```

## Two Pointer Template

```cpp
// INWARD (palindrome / two-sum style)
void twoPointerInward(string s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        // process s[l] and s[r]
        l++; r--;
    }
}

// SAME DIRECTION (filter / partition)
void twoPointerSame(string& s) {
    int slow = 0;
    for (int fast = 0; fast < s.size(); fast++) {
        if (keep(s[fast])) s[slow++] = s[fast];
    }
    s.resize(slow);
}
```

## Frequency Counting Template

```cpp
// Lowercase letters
int freq[26] = {};
for (char c : s) freq[c - 'a']++;

// Any ASCII char
int freq[128] = {};
for (char c : s) freq[(unsigned char)c]++;

// Any Unicode char
unordered_map<char, int> freq;
for (char c : s) freq[c]++;

// Check two strings same freq
bool same = equal(freq1, freq1+26, freq2);
```

## KMP Template

```cpp
// Build LPS array
vector<int> buildLPS(string p) {
    int m = p.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (p[i] == p[len]) { lps[i++] = ++len; }
        else if (len) len = lps[len-1];
        else lps[i++] = 0;
    }
    return lps;
}

// KMP search
vector<int> kmp(string text, string pattern) {
    vector<int> lps = buildLPS(pattern);
    vector<int> matches;
    int n = text.size(), m = pattern.size();
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) { i++; j++; }
        if (j == m) { matches.push_back(i - j); j = lps[j-1]; }
        else if (i < n && text[i] != pattern[j]) {
            if (j) j = lps[j-1]; else i++;
        }
    }
    return matches;
}
```

## Rabin-Karp Template

```cpp
vector<int> rabinKarp(string text, string pattern) {
    const long long BASE = 31, MOD = 1e9 + 7;
    int n = text.size(), m = pattern.size();
    vector<int> matches;
    if (m > n) return matches;
    
    long long power = 1;
    for (int i = 0; i < m-1; i++) power = power * BASE % MOD;
    
    long long ph = 0, wh = 0;
    for (int i = 0; i < m; i++) {
        ph = (ph * BASE + pattern[i]) % MOD;
        wh = (wh * BASE + text[i]) % MOD;
    }
    
    for (int i = 0; i <= n-m; i++) {
        if (wh == ph && text.substr(i, m) == pattern)
            matches.push_back(i);
        if (i < n-m) {
            wh = (wh - text[i] * power % MOD + MOD) % MOD;
            wh = (wh * BASE + text[i+m]) % MOD;
        }
    }
    return matches;
}
```

---

# SECTION 21: FINAL STRING ROADMAP

## Beginner → Intermediate → Advanced

```
WEEK 1: FUNDAMENTALS
─────────────────────────────────────────────────────────────
Day 1-2: ASCII, Character types, String basics
  - Learn ASCII table (memorize key ranges)
  - Practice: char-to-int, int-to-char conversions
  - Problems: LC 709, 520, 383 (easy char manipulation)

Day 3-4: String operations in C++
  - Length, access, substr, find, insert, erase
  - Practice all basic operations
  - Problems: LC 344, 345, 14, 58

Day 5-7: Traversal patterns + Frequency
  - Traverse with index, range-based, iterator
  - Frequency arrays (26-char)
  - Problems: LC 387, 242, 389, 771

WEEK 2: CORE PATTERNS
─────────────────────────────────────────────────────────────
Day 8-9: Two Pointers
  - Reverse, Valid Palindrome
  - Problems: LC 125, 680, 844, 392

Day 10-12: Sliding Window (Fixed then Variable)
  - Fixed: anagram check in window
  - Variable: longest unique substring
  - Problems: LC 3, 438, 567, 424

Day 13-14: Palindromes
  - Check, expand around center, count
  - Problems: LC 5, 647, 131, 409

WEEK 3: ALGORITHMS
─────────────────────────────────────────────────────────────
Day 15-16: KMP Algorithm
  - Understand LPS array fully
  - Code from scratch 3 times
  - Problems: LC 28, 459, 214

Day 17-18: Z Algorithm
  - Code from scratch
  - Use for pattern matching
  - Problems: Same as KMP category

Day 19-21: Hashing + Rabin-Karp
  - Rolling hash concept
  - Polynomial hashing
  - Problems: LC 187, 1044, 1316

WEEK 4: ADVANCED PATTERNS
─────────────────────────────────────────────────────────────
Day 22-23: Anagram mastery
  - Group anagrams, find all anagrams
  - Problems: LC 49, 438, 242, 267

Day 24-25: Minimum Window + Hard Sliding Window
  - Problems: LC 76, 30, 340

Day 26-28: Mixed practice + Review
  - 2-3 medium problems per day
  - 1 hard problem

WEEK 5-6: INTERVIEW PREP
─────────────────────────────────────────────────────────────
Day 29-35: Timed problem solving
  - 3 problems per session (easy + medium + hard)
  - Review all templates
  - Mock interview practice

Day 36-42: Company-specific questions
  - FAANG favorite patterns
  - Review common mistakes
  - Optimize solutions
```

## Problem Solving Order

### Phase 1: Foundation (Week 1-2)
LC 344 → 242 → 125 → 387 → 14 → 3 → 438 → 567

### Phase 2: Algorithms (Week 3)
LC 28 → 459 → 214 → 187 → 5 → 647

### Phase 3: Advanced (Week 4+)
LC 76 → 49 → 30 → 424 → 1044 → 336

## Quick Revision Roadmap (3 days before interview)

```
Day 1: Review ALL templates
  - Sliding window (fixed + variable)
  - Two pointers (inward + same direction)
  - Frequency counting
  - KMP / Z-function

Day 2: Solve 5 medium + 2 hard problems
  - Focus on problems you've solved before
  - Time yourself (20 min per medium, 40 min per hard)

Day 3: Review cheat sheets + edge cases
  - Off-by-one errors
  - Empty string, single char
  - All same characters
  - Case sensitivity
  - Read through this cheat sheet one more time
```

## Top 20 Must-Know Problems

| Priority | Problem | LC # | Why Important |
|----------|---------|------|---------------|
| 🔴 | Longest Substring Without Repeating | 3 | Sliding window foundation |
| 🔴 | Minimum Window Substring | 76 | Min window template |
| 🔴 | Longest Palindromic Substring | 5 | Expand center technique |
| 🔴 | Group Anagrams | 49 | Hashing + canonical form |
| 🔴 | Valid Palindrome | 125 | Two pointer classic |
| 🔴 | Find All Anagrams | 438 | Fixed window + freq |
| 🔴 | Implement strStr (KMP) | 28 | KMP algorithm |
| 🟡 | Longest Repeating Char Replacement | 424 | Clever window condition |
| 🟡 | Palindromic Substrings | 647 | Count palindromes |
| 🟡 | Encode/Decode Strings | 271 | String design |
| 🟡 | Repeated Substring Pattern | 459 | KMP period property |
| 🟡 | String Compression | 443 | Two pointer |
| 🟡 | Permutation in String | 567 | Fixed window |
| 🟡 | Reverse Words in String | 151 | Word manipulation |
| 🟡 | Remove Duplicate Letters | 316 | Stack + greedy |
| 🟢 | Sort Characters by Frequency | 451 | Freq + sort |
| 🟢 | Palindrome Pairs | 336 | Hashing (hard) |
| 🟢 | Shortest Palindrome | 214 | KMP trick |
| 🟢 | Longest Duplicate Substring | 1044 | Rabin-Karp + binary search |
| 🟢 | Count Palindromic Subsequences | 730 | DP on strings |

---

## Final Tips for Interviews

```
1. CLARIFY FIRST
   - Is the string ASCII or Unicode?
   - Case-sensitive?
   - Can input be empty?
   - What should we return for edge cases?

2. THINK BEFORE CODING
   - What pattern does this resemble?
   - What's the brute force? Can we do better?
   - What's the target time complexity?

3. CODE CLEARLY
   - Name variables well (left/right, not i/j for two pointers)
   - Comment your window logic
   - Separate helper functions

4. TEST YOUR CODE
   - Empty string ""
   - Single character "a"
   - All same chars "aaaa"
   - Pattern is longer than text
   - Pattern not found

5. DISCUSS TRADEOFFS
   - Freq array O(1) space vs HashMap O(k) space
   - KMP O(n+m) vs Naive O(nm)
   - In-place vs extra space

6. COMPLEXITY ANALYSIS
   - Always state time AND space
   - Remember: string copying costs O(n)!
   - substr() costs O(k), not O(1)
```

---

*This handbook covers: String fundamentals, All major algorithms (KMP, Z-algorithm, Rabin-Karp, Manacher), All key patterns (Sliding Window, Two Pointers, Frequency Counting, Hashing), 200 curated problems, Complete templates and cheat sheets, and a step-by-step learning roadmap.*

