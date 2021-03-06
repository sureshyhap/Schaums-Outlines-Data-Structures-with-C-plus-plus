#include <iostream>
#include "Queue.h"

int main(int argc, char* argv[]) {
  Queue<int> q;
  q.push(5);
  q.push(3);
  q.push(2);
  q.print();
  q.pop();
  q.print();
  Queue<int> q2(q), q3;
  q2.print();
  q3 = q;
  q3.print();
  q.front_() = 10;
  q.print();
  q.back_() = 20;
  q.print();
  q.push(11);
  q.push(13);
  q.print();
  reverse(q);
  q.print();
  return 0;
}
