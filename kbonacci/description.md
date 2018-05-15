Define the k-bonacci sequence as follows. The first k terms are all 1. The nth term, for n >= k, is the sum of k previous terms in the sequence. For example, the first five terms of the 3-bonacci sequence are 1, 1, 1, 3, 5.

Given n and k, write a function which returns the nth term (0-indexed) of the k-bonacci sequence. Since the answer may be quite large, return it as a string.

Example
For k = 3 and n = 4, the output should be kbonacci(k, n) = "5".

Input/Output

[execution time limit] 4 seconds (py)

[input] integer k

The value k defining the k-bonacci sequence; i.e., the degree of the recurrence.

Guaranteed constraints:
1 ≤ k ≤ 103.

[input] integer n

The term of the k-bonacci sequence to return.

Guaranteed constraints:
1 ≤ n ≤ 25000.

[output] string

The nth number of the k-bonacci sequence, returned as a string.