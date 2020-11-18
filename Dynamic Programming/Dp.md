What is Dynamic Programming?

Dynamic Programming (DP) is an algorithmic technique for solving an optimization problem by breaking it down into simpler subproblems and utilizing the fact that the optimal solution to the overall problem depends upon the optimal solution to its subproblems.

Characteristics of Dynamic Programming
1. Overlapping Subproblems
2. Optimal Substructure Property

Overlapping Subproblems:
Subproblems are smaller versions of the original problem. Any problem has overlapping sub-problems if finding its solution involves solving the same subproblem multiple times

Optimal Substructure Property:
Any problem has optimal substructure property if its overall optimal solution can be constructed from the optimal solutions of its subproblems. 

Dynamic Programming Methods
1. Top-down with Memoization
2. Bottom-up with Tabulation

Top-down with Memoization:
In this approach, we try to solve the bigger problem by recursively finding the solution to smaller sub-problems. Whenever we solve a sub-problem, we cache its result so that we don’t end up solving it repeatedly if it’s called multiple times. Instead, we can just return the saved result. This technique of storing the results of already solved subproblems is called Memoization.

Bottom-up with Tabulation:
Tabulation is the opposite of the top-down approach and avoids recursion. In this approach, we solve the problem “bottom-up” (i.e. by solving all the related sub-problems first). This is typically done by filling up an n-dimensional table. Based on the results in the table, the solution to the top/original problem is then computed.

Where can we use it?
1. Counting problems
2. Maximization/Minimization problems

Defining a DP Problem:
1. State
2. Return Values
3. Base Case
4. Transitions
5. Memorization

Resources:
https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews/m2G1pAq0OO0