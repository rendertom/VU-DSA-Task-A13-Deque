#include <iostream>

struct Node {
  int value;
  Node *previous;
  Node *next;
};

class Deque {
  Node *back;
  Node *front;
  int size;

 public:
  Deque() {
    back = NULL;
    front = NULL;
    size = 0;
  }

  void deleteBack();
  void deleteFront();
  void erase();
  int getBack();
  int getFront();
  int getSize();
  void insertBack(int);
  void insertFront(int);
  bool isEmpty();
  void print();

 private:
  Node *createNode(int);
};

void Deque::deleteFront() {
  if (isEmpty()) {
    std::cout << "Deque is empty" << std::endl;
  } else {
    Node *temp = front;
    front = front->next;
    front->previous = NULL;

    std::cout << "Deleted Front: " << temp->value << std::endl;
    delete temp;

    size--;
  }
}

void Deque::deleteBack() {
  if (isEmpty()) {
    std::cout << "Deque is empty" << std::endl;
  } else {
    Node *temp = back;
    back = back->previous;
    back->next = NULL;

    std::cout << "Deleted back: " << temp->value << std::endl;
    delete temp;

    size--;
  }
}

void Deque::erase() {
  back = NULL;
  while (front != NULL) {
    Node *temp = front;
    front = front->next;
    delete temp;
  }
  size = 0;
}

int Deque::getBack() {
  if (isEmpty()) {
    std::cout << "Deque is empty" << std::endl;
    return -1;
  } else {
    return back->value;
  }
}

int Deque::getFront() {
  if (isEmpty()) {
    std::cout << "Deque is empty" << std::endl;
    return -1;
  } else {
    return front->value;
  }
}

int Deque::getSize() {
  return size;
}

void Deque::insertBack(int value) {
  Node *node = createNode(value);
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

void Deque::insertFront(int value) {
  Node *node = createNode(value);
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

bool Deque::isEmpty() {
  return front == NULL;
}

void Deque::print() {
  if (isEmpty()) {
    std::cout << "Deque is empty" << std::endl;
  } else {
    Node *temp = front;
    while (temp != NULL) {
      std::cout << temp->value << " ";
      temp = temp->next;
    }
    std::cout << std::endl;

    delete temp;
  }
}

Node *Deque::createNode(int value) {
  Node *node = new Node;
  node->value = value;
  node->previous = NULL;
  node->next = NULL;
  return node;
}