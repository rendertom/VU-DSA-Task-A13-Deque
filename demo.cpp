#include <iostream>

#include "Deque.hpp"
using namespace std;

int main() {
  // Elemento įterpimas: pushAt(), pushBack(), pushFront();
  // Elemento gavimas: getAt(), getBack(), getFront();
  // Elemento trinimas: popAt(), popBack(); popFront(); clear();
  // Masymo apėjimas: print(), printReverse();
  // Masyvo statistika: getSize(), isEmpty();

  Deque<int> d;

  // 1. Elemento įterpimas: pushAt(), pushBack(), pushFront();
  d.pushBack(5);   // 5;
  d.pushBack(6);   // 5, 6;
  d.pushFront(2);  // 2, 5, 6;
  d.pushFront(1);  // 1, 2, 5, 6;
  d.pushAt(2, 3);  // 1, 2, 3, 5, 6;
  d.pushAt(3, 4);  // 1, 2, 3, 4, 5, 6;

  cout << "The contents of deque: ";
  d.print();  // 1, 2, 3, 4, 5, 6;

  // 2. Elemento gavimas: getAt(), getBack(), getFront();
  cout << "getBack(): " << d.getBack() << endl;    // 6;
  cout << "getFront(): " << d.getFront() << endl;  // 1;
  cout << "getAt(3): " << d.getAt(3) << endl;      // 4;

  // 3. Masymo apėjimas: print(), printReverse();
  cout << "print(): ";
  d.print();  // 1, 2, 3, 4, 5, 6;

  cout << "printReverse(): ";
  d.printReverse();  // 6, 5, 4, 3, 2, 1;

  // 4. Elemento trinimas: popAt(), popBack(); popFront(); clear();
  d.popBack();  // 1, 2, 3, 4, 5;
  d.popBack();  // 1, 2, 3, 4;
  cout << "Deque after 2 popBack's: ";
  d.print();  // 1, 2, 3, 4;

  d.popFront();  // 2, 3, 4;
  d.popFront();  // 3, 4;
  cout << "Deque after 2 popFront's: ";
  d.print();  // 3, 4;

  d.popAt(0);  // 4;
  d.popAt(0);  // Deque is empty;
  cout << "Deque after 2 popAt's: ";
  d.print();  // Deque is empty;

  // 5. Masyvo statistika: getSize(), isEmpty();
  for (int i = 0; i < 10; i++) d.pushBack(i);
  cout << "New deque: ";
  d.print();  // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9;

  cout << "Deque size: " << d.getSize() << endl;             // 10
  cout << "Is empty: " << boolalpha << d.isEmpty() << endl;  // false

  d.clear();

  cout << "Deque size: " << d.getSize() << endl;             // 0
  cout << "Is empty: " << boolalpha << d.isEmpty() << endl;  // true

  return 0;
}