/*
  h + 1 is the minimum number of nodes for a binary tree of height h (a linear list). 2 ^ (h + 1) - 1 is the maximum number of nodes for a binary tree of height h (a full tree).
  For the second inequality, subtract 1 from the left side and the middle of the first inequlaity to get h <= n- 1. Also, add 1 to the middle and right side of the first inequlity, take the lg, and then subtract 1 to get lg(n + 1) - 1 <= h. This will always be less than or equal to the floor of the log(n) so you can 
 */
