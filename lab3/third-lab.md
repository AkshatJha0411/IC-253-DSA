### **1. Tower of Hanoi using Stack (Linked List Implementation)**
- **Tower of Hanoi Problem**: Move disks from one rod to another, following rules: only one disk moves at a time, and no larger disk is placed on a smaller one.
- **Recursive Logic**: Move `n-1` disks to an auxiliary rod, move the nth disk to the target rod, then move `n-1` disks to the target.
- **Stack for Iterative Solution**: A stack simulates recursion by storing disk moves.
- **Time Complexity**: \(O(2^n)\).
- **Space Complexity**: Recursive: \(O(n)\) (call stack); Iterative: \(O(n)\) (stack).
- **Stack Operations**: Push (add), Pop (remove), Peek (view top).
- **Linked List Stack**: Each node points to the next, with the top node as the head.

---

### **2. Parenthesis Matching using Stack**
- **Parenthesis Matching**: Check if brackets in an expression are balanced and properly nested.
- **Stack Use**: Tracks opening brackets and matches them with closing ones.
- **Algorithm**: Push opening brackets, pop on closing brackets, and check for matches.
- **Multiple Brackets**: Use a stack to handle `{}`, `()`, `[]` by checking corresponding pairs.
- **Time Complexity**: \(O(n)\).
- **Edge Cases**: Unbalanced brackets, empty input, or mismatched types.

---

### **3. Binary Tree Operations**
- **Array Representation**: Root at index 0, left child at \(2i+1\), right at \(2i+2\).
- **Time Complexity (Array)**: Insertion, deletion, search: \(O(n)\).
- **Linked List Representation**: Nodes with `data`, `left`, and `right` pointers.
- **Deletion Complexity**: Replacing a node requires finding the bottom-most rightmost node.
- **Time Complexity (Linked List)**: Insertion, deletion, search: \(O(h)\), where \(h\) is height.

---

### **4. Find Elements at Dynamic Positions in a Linked List**
- **Approach**: Use two pointers: one moves at normal speed, the other at double speed to find mid, n/3, etc.
- **One Traversal**: Ensures efficiency (\(O(n)\) time complexity).
- **Runner Technique**: Fast pointer reaches the end while slow pointer reaches the desired position.

---

### **5. Infix to Postfix Conversion using Stack**
- **Infix vs Postfix**: Infix: operators between operands; Postfix: operators after operands.
- **Algorithm**: Use a stack to handle operators based on precedence and parentheses.
- **Operator Precedence**: Determines the order of operations.
- **Time Complexity**: \(O(n)\).
- **Benefits of Postfix**: No need for parentheses, easier evaluation.

---

### **6. Postfix to Infix Conversion using Stack**
- **Algorithm**: Use a stack to push operands and pop them when operators are encountered to form subexpressions.
- **Stack Role**: Temporarily stores operands and subexpressions.
- **Time Complexity**: \(O(n)\).
- **Operators and Operands**: Operands are pushed, operators combine the top two operands.

---

### **7. Merge Sort Algorithm**
- **Steps**: Divide the array into halves, recursively sort, then merge the sorted halves.
- **Divide-and-Conquer**: Splits the problem into smaller subproblems.
- **Time Complexity**: \(O(n \log n)\) (best, worst, average).
- **Auxiliary Space**: \(O(n)\).
- **Stability**: Equal elements retain their order.
- **Comparisons/Swaps**: \(O(n \log n)\).

---

### **8. Circular Queue in a Ticket Booking System**
- **Circular Queue**: A ring buffer where the last element points to the first.
- **Advantage Over Linear Queue**: Efficient space utilization.
- **Enqueue/Dequeue**: Add to the rear, remove from the front; handles overflow/underflow with modulo arithmetic.
- **Time Complexity**: \(O(1)\) for both operations.
- **Wraparound**: Rear and front pointers reset to 0 after reaching the end.
- **Applications**: Traffic systems, CPU scheduling, streaming data.