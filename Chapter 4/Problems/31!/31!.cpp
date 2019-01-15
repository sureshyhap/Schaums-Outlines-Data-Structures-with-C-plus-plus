/*
  hanoi(4, 'A', 'B', 'C') ->
  hanoi(3, 'A', 'C', 'B') -> , hanoi(1, 'A', 'B', 'C'), hanoi(3, 'B', 'A', 'C') ->
  [hanoi(2, 'A', 'B', 'C') ->, hanoi(1, 'A', 'C', 'B'), hanoi(2, 'C', 'A', 'B') ->], [hanoi(2, 'B', 'C', 'A') ->, hanoi(1, 'B', 'A', 'C'), hanoi(2, 'A', 'B', 'C') ->]
  ...
 */
