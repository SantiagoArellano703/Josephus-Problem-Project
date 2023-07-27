//
// Created by dylan-roman on 7/25/23.
//

// Circular Doubly Linked List

#include "Node.h"
#include <iostream>

using namespace std;

Node::Node() = default;

Node *Node::createDCLL(int n) {
  Node *head = nullptr;
  Node *ptr = head, *ptr_prev = head;

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      head = (Node *) malloc(sizeof(Node));
      head->data = i + 1;
      head->next = head->prev = head;
      ptr_prev = head;
    } else {
      ptr = (Node *) malloc(sizeof(Node));
      ptr->data = i + 1;
      ptr_prev->next = ptr;
      ptr->prev = ptr_prev;
      ptr_prev = ptr;
    }
  }
  ptr->next = head;
  head->prev = ptr;
  return head;
}

//void display(Node *head) {
//  Node *ptr = head;
//  do {
//    printf("%d-> ", ptr->data);
//    ptr = ptr->next;
//  } while (ptr != head);
//  printf("\b\b\b  \n");
//}

int Node::josephus(Node *head, int k) {
  Node::display(head);
  Node *ptr = head;
  if (ptr->next == head)
    return ptr->data;

  Node *todel = ptr, *todel_prev = todel->prev;
  for (int i = 0; i < k; i++) {
    todel_prev = todel;
    todel = todel->next;
  }
  Node *new_head = todel->next;
  new_head->prev = todel_prev;
  todel_prev->next = new_head;

  free(todel);
  return josephus(new_head, k);
}

int Node::josephusReverse(Node *head, int k) {
  Node::display(head);
  Node *ptr = head;
  if (ptr->next == head)
    return ptr->data;

  Node *todel = ptr;
  Node *todel_next = todel->next;
  for (int i = 0; i < k; i++) {
    todel_next = todel;
    todel = todel->prev; // Moverse hacia atrás en la lista
  }

  Node *new_head = todel->prev;
  new_head->next = todel_next;
  todel_next->prev = new_head;


  free(todel);
  return josephusReverse(new_head, k);
}

void Node::display(struct Node *start) {
  struct Node *temp = start;

  cout << "\nRecorrer hacia adelante\n" << endl;
  while (temp->next != start) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << temp->data << endl;
}