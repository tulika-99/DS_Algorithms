Locate the smallest Fibonacci Number greater than or equivalent to n. Call this as 'next'. Let the two Fibonacci numbers going before it be 'second' and 'first'. 

While the exhibit has components to be examined: 

1. Contrast key and the last element of the range secured by 'first' 

2. On the off chance that key matches, return the index 

3. Else If key is not exactly the element, move the three Fibonacci factors two Fibonacci down, showing disposal of around back two-third of the rest of the array. 

4. Else key is greater than the element, move the three Fibonacci factors one Fibonacci down. Reset balance to file. Together these demonstrate end of around front 33% of the rest of the exhibit. 

5. Since there may be a solitary component staying for examination, check if 'second' is 1. In the event that Yes, contrast key and that residual element. On the off chance that matches, return the index.



Points to be noted about fibonacci search algorithm:

1. Fibonacci Search divides given array in unequal parts.

2. Fibonacci Search examines relatively closer elements in subsequent steps. So when input array is big that cannot fit in CPU cache or even in RAM, Fibonacci Search can be useful.

3. Works for sorted arrays

4. A Divide and Conquer Algorithm.

5. Has Log(n) time complexity.
