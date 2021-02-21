#include <iostream>

template <class T>
struct Node {
  T value;
  Node *previous;
  Node *next;
};

template <class T>
class Deque {
  Node<T> *back;
  Node<T> *front;
  int size;

 public:
  Deque() {
    back = NULL;
    front = NULL;
    size = 0;
  }

  void clear();
  T getAt(int);
  T getBack();
  T getFront();
  int getSize();
  bool isEmpty();
  void popAt(int);
  void popBack();
  void popFront();
  void print();
  void printReverse();
  void pushAt(int, T);
  void pushBack(T);
  void pushFront(T);

 private:
  Node<T> *createNode(T);
  int mod(int, int);
};

template <class T>
void Deque<T>::clear() {
  back = NULL;
  while (front != NULL) {
    Node<T> *temp = front;
    front = front->next;
    delete temp;
  }
  size = 0;
}

template <class T>
T Deque<T>::getAt(int index) {
  if (isEmpty()) {
    std::cout << "Deque is empty" << std::endl;
    return -1;
  }

  index = mod(index, size);

  if (index == 0) {
    return getFront();
  } else if (index == size - 1) {
    return getBack();
  } else {
    Node<T> *node = front;
    int count = 0;
    while (count != index) {
      node = node->next;
      count++;
    }
    return node->value;
  }
}

template <class T>
T Deque<T>::getBack() {
  if (isEmpty()) {
    std::cout << "Deque is empty" << std::endl;
    return -1;
  } else {
    return back->value;
  }
}

template <class T>
T Deque<T>::getFront() {
  if (isEmpty()) {
    std::cout << "Deque is empty" << std::endl;
    return -1;
  } else {
    return front->value;
  }
}

template <class T>
int Deque<T>::getSize() {
  return size;
}

template <class T>
bool Deque<T>::isEmpty() {
  return front == NULL;
}

template <class T>
void Deque<T>::popAt(int index) {
  if (isEmpty()) {
    std::cout << "Deque is empty" << std::endl;
  }

  index = mod(index, size);

  if (index == 0) {
    popFront();
  } else if (index == size - 1) {
    popBack();
  } else {
    Node<T> *node = front;
    int count = 0;
    while (count != index) {
      node = node->next;
      count++;
    }
    Node<T> *tempPrev = node->previous;
    Node<T> *tempNext = node->next;

    tempPrev->next = tempNext;
    tempNext->previous = tempPrev;

    delete node;

    size--;
  }
}

template <class T>
void Deque<T>::popBack() {
  if (isEmpty()) {
    std::cout << "Deque is empty" << std::endl;
  } else if (size == 1) {
    clear();
  } else {
    Node<T> *temp = back;
    back = back->previous;
    back->next = NULL;

    // std::cout << "Deleted back: " << temp->value << std::endl;
    delete temp;

    size--;
  }
}

template <class T>
void Deque<T>::popFront() {
  if (isEmpty()) {
    std::cout << "Deque is empty" << std::endl;
  } else if (size == 1) {
    clear();
  } else {
    Node<T> *temp = front;
    front = front->next;
    front->previous = NULL;

    // std::cout << "Deleted Front: " << temp->value << std::endl;
    delete temp;

    size--;
  }
}

template <class T>
void Deque<T>::print() {
  if (isEmpty()) {
    std::cout << "Deque is empty" << std::endl;
  } else {
    Node<T> *temp = front;
    while (temp != NULL) {
      std::cout << temp->value << " ";
      temp = temp->next;
    }
    std::cout << std::endl;

    delete temp;
  }
}

template <class T>
void Deque<T>::printReverse() {
  if (isEmpty()) {
    std::cout << "Deque is empty" << std::endl;
  } else {
    Node<T> *temp = back;
    while (temp != NULL) {
      std::cout << temp->value << " ";
      temp = temp->previous;
    }
    std::cout << std::endl;

    delete temp;
  }
}

template <class T>
void Deque<T>::pushAt(int index, T value) {
  index = mod(index, size + 1);

  if (index == 0) {
    pushFront(value);
  } else if (index == size) {
    pushBack(value);
  } else {
    Node<T> *left = front;
    int count = 0;
    while (count != index - 1) {
      left = left->next;
      count++;
    }

    Node<T> *right = left->next;
    Node<T> *node = createNode(value);

    left->next = node;
    right->previous = node;

    node->previous = left;
    node->next = right;

    size++;
  }
}

template <class T>
void Deque<T>::pushBack(T value) {
  Node<T> *node = createNode(value);

  if (isEmpty()) {
    back = node;
    front = node;
  } else {
    node->previous = back;
    back->next = node;
    back = node;
  }
  size++;
}

template <class T>
void Deque<T>::pushFront(T value) {
  Node<T> *node = createNode(value);
  if (isEmpty()) {
    back = node;
    front = node;
  } else {
    node->next = front;
    front->previous = node;
    front = node;
  }
  size++;
}

template <class T>
Node<T> *Deque<T>::createNode(T value) {
  Node<T> *node = new Node<T>;
  node->value = value;
  node->previous = NULL;
  node->next = NULL;
  return node;
}

template <class T>
int Deque<T>::mod(int value, int modulus) {
  int remainder = value % modulus;
  return remainder < 0 ? remainder + modulus : remainder;
}
