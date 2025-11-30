# Assignment 10: Hashing

Lab Assignment 10: Hashing

---

## Question 1: Check for Duplicates Using Hash Set

**Explanation:** This program uses a hash set to efficiently check if an array contains any duplicate elements. The hash set provides O(1) average time complexity for insertion and lookup operations.

**Code:**
```cpp
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    
    if (containsDuplicate(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}
```

**Output:**
```
true
```

---

## Question 2: Find Common Elements Using Hash Set

**Explanation:** This program finds common elements between two arrays using a hash set. It first stores all elements from the first array in a set, then checks which elements from the second array exist in the set.

**Code:**
```cpp
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> findCommon(vector<int>& A, vector<int>& B) {
    unordered_set<int> setA(A.begin(), A.end());
    vector<int> common;
    
    for (int num : B) {
        if (setA.find(num) != setA.end()) {
            common.push_back(num);
            setA.erase(num);
        }
    }
    
    return common;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};
    
    vector<int> result = findCommon(A, B);
    
    cout << "Common elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Output:**
```
Common elements: 3 4 
```

---

## Question 3: Count Frequency Using Hash Map

**Explanation:** This program counts the frequency of each element in an array using a hash map (unordered_map). Each key represents an element, and its value represents the count of occurrences.

**Code:**
```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void countFrequency(vector<int>& nums) {
    unordered_map<int, int> freqMap;
    
    for (int num : nums) {
        freqMap[num]++;
    }
    
    cout << "Frequency count:" << endl;
    for (auto& pair : freqMap) {
        cout << pair.first << " -> " << pair.second << " times" << endl;
    }
}

int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};
    
    countFrequency(nums);
    
    return 0;
}
```

**Output:**
```
Frequency count:
2 -> 3 times
3 -> 2 times
4 -> 1 times
```

---

## Question 4: Find First Non-Repeating Element Using Hash Map

**Explanation:** This program finds the first element in an array that appears only once. It uses a hash map to count frequencies, then iterates through the array to find the first element with frequency 1.

**Code:**
```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int firstNonRepeating(vector<int>& nums) {
    unordered_map<int, int> freqMap;
    
    for (int num : nums) {
        freqMap[num]++;
    }
    
    for (int num : nums) {
        if (freqMap[num] == 1) {
            return num;
        }
    }
    
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 1, 2, 0, 4};
    
    int result = firstNonRepeating(nums);
    
    if (result != -1) {
        cout << "First non-repeating element: " << result << endl;
    } else {
        cout << "No non-repeating element found" << endl;
    }
    
    return 0;
}
```

**Output:**
```
First non-repeating element: 5
```

---

## Question 5: Detect Cycle in Linked List Using Hash Set

**Explanation:** This program detects if a linked list contains a cycle by using a hash set to track visited nodes. If a node is encountered that's already in the set, a cycle exists.

**Code:**
```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node* head) {
    unordered_set<Node*> visited;
    Node* current = head;
    
    while (current != nullptr) {
        if (visited.find(current) != visited.end()) {
            return true;
        }
        visited.insert(current);
        current = current->next;
    }
    
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;
    
    if (hasCycle(head)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}
```

**Output:**
```
true
```

---

## Question 6: Check for Duplicate Values in Binary Tree Using Hash Set

**Explanation:** This program checks if a binary tree contains duplicate node values using a hash set. It recursively traverses the tree and checks if each value has been seen before.

**Code:**
```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool hasDuplicates(Node* root, unordered_set<int>& seen) {
    if (root == nullptr) return false;
    
    if (seen.find(root->data) != seen.end()) {
        return true;
    }
    
    seen.insert(root->data);
    
    return hasDuplicates(root->left, seen) || hasDuplicates(root->right, seen);
}

bool checkDuplicates(Node* root) {
    unordered_set<int> seen;
    return hasDuplicates(root, seen);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(2);
    
    if (checkDuplicates(root)) {
        cout << "Duplicates Found" << endl;
    } else {
        cout << "No Duplicates" << endl;
    }
    
    return 0;
}
```

**Output:**
```
Duplicates Found
```

---

## Conclusion

This assignment provided comprehensive hands-on experience with hashing and hash-based data structures. Hash sets (unordered_set) and hash maps (unordered_map) are powerful tools that provide O(1) average time complexity for insertion, deletion, and lookup operations. We learned how to use hash sets to detect duplicates, find intersections, and detect cycles in data structures. Hash maps were used for frequency counting and finding non-repeating elements. These hashing techniques are fundamental in computer science and are widely used for optimization in many algorithms, including database indexing, caching, symbol tables in compilers, and solving various computational problems efficiently. Understanding hashing is essential for writing efficient code and solving real-world problems that require fast data retrieval and manipulation.