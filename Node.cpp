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

int Node::josephus(Node *head, int k) {
  Node *ptr = head;
  if (ptr->next == head) {
    cout<<endl;
    Node::display(head, 0);
    return ptr->data;
  }

  Node *todel = ptr, *todel_prev = todel->prev;
  for (int i = 0; i < k; i++) {
    todel_prev = todel;
    todel = todel->next;
  }
  Node::display(head, todel->data);

  Node *new_head = todel->next;
  new_head->prev = todel_prev;
  todel_prev->next = new_head;

  free(todel);
  return josephus(new_head, k);
}

int Node::josephusReverse(Node *head, int k) {
  Node *ptr = head;
  if (ptr->next == head) {
    Node::display(head, 0);
    return ptr->data;
  }

  Node *todel = ptr;
  Node *todel_next = todel->next;
  for (int i = 0; i < k; i++) {
    todel_next = todel;
    todel = todel->prev; // Moverse hacia atrás en la lista
  }

  Node::display(head, todel->data);
  cout<<endl; 

  Node *new_head = todel->prev;
  new_head->next = todel_next;
  todel_next->prev = new_head;


  free(todel);
  return josephusReverse(new_head, k);
}

void Node::display(Node *start, int deleted) {
  struct Node *temp = start;

  cout << "\nLista: " << endl;
  while (temp->next != start) {
    if (temp->data == deleted)
      cout << "\033[31m" << temp->data << "\033[0m" << "-";
    else
      cout << temp->data << "-";
    temp = temp->next;
  }
  if (temp->data == deleted)
    cout << "\033[31m" << temp->data << "\033[0m";
  else
    cout << temp->data << endl;
}