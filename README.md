# Leetcode-2045.-Second-Minimum-Time-to-Reach-Destination
# Second Minimum Time to Reach Destination

This repository contains two optimized approaches to solve the problem of finding the **second minimum time** required to reach from node `1` to node `n` in an undirected graph, with traversal time constraints.

---

## 🔎 Problem Statement
Given an undirected graph with `n` nodes (1-indexed), edges, a fixed `time` to traverse each edge, and a `change` interval that determines when signals switch between green and red, find the **second minimum time** to reach from node `1` to node `n`.

- If the current time lies within a red interval, you must wait for the next green interval to proceed.
- The result should be the **second shortest** time to reach node `n`.

---

## ✅ Approaches Covered

### Approach 1: Priority Queue (Min-Heap)
- Use a **min-heap (priority queue)** to always expand the path with the current minimum time.
- Maintain two arrays:
  - `small[i]`: the smallest time to reach node `i`
  - `small2[i]`: the second smallest time to reach node `i`
- Adjust time based on the signal (red/green) interval.
- Stop once the second shortest time to reach `n` is found.

### Approach 2: Breadth-First Search (BFS)
- Perform a **level-based BFS** using a regular queue.
- Similar tracking of `small` and `small2` arrays as in the first approach.
- Also consider signal waiting time.
- Offers a simpler control structure than the priority queue.

---

## 📊 Time and Space Complexity

| Approach         | Time Complexity | Space Complexity |
|------------------|------------------|-------------------|
| Priority Queue   | O(E log V)       | O(V + E)          |
| BFS              | O(E)             | O(V + E)          |

---

## 📄 Example
**Input:**
```cpp
n = 5
edges = [[1,2],[1,3],[1,4],[3,4],[4,5]]
time = 3
change = 5
```
**Output:**
```cpp
13
```

---

## 🧬 Contributions
Feel free to improve or add more algorithms to the solution. Fork and submit a PR!

---

## 📜 License
MIT License

---

Happy Coding! 🚀

