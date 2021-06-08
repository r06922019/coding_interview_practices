# Sticky plan

## Queue

Qsort

Merge sort

Binary search

LCS

LIS

## 06/10

### 06/08
https://leetcode.com/problems/number-of-good-pairs/
https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/

### 06/09 notes

### 1 more mock

## 06/09

### 06/07
https://leetcode.com/problems/course-schedule
https://leetcode.com/problems/course-schedule-ii

### 06/08 notes

### 1 more mock


## 06/08
1512. Number of Good Pairs

1578. Minimum Deletion Cost to Avoid Repeating Letters

828. Count Unique Characters of All Substrings of a Given String


## 06/07

207. Course Schedule
210. Course Schedule II

It's for detecting circular dependency.
1 method is to use 3-color DFS. if encounter a node with status traversing when traversing current, we've got a cycle
1 method is to use multi-entry BFS, add to queue only if in_degree becomes zero

124. Binary Tree Maximum Path Sum
First think of a recursive structure
Think of the helper function's usage and what to return

## 06/06

859. Buddy Strings (6/8)
Ans only exists when only 2 or 0 diffs
2 -> need to be exact same
0 -> need to be exact same

1329. Sort the Matrix Diagonally
Collect them diagonally, sort them
(m+n) * min(m,n) * log(min(m,n))
qsort can do it in place

