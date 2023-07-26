//
// Created by dylan-roman on 7/25/23.
//

// Circular Doubly Linked List

#include "Node.h"
#include <iostream>

using namespace std;

Node::Node() = default;


void Node::push(Node **start, int data) {
  // Step 1: Create a new node
  Node *newNode = new Node();
  newNode->data = data;

  // Step 2: If Linked List is empty, then make the new node as linked list
  if (*start == nullptr) {
    newNode->next = newNode;
    newNode->prev = newNode;
    *start = newNode;
    return;
  }

  // Step 3: Else find last node
  Node *last = (*start)->prev;

  // Step 4: Make next and prev of new node
  newNode->next = *start;
  newNode->prev = last;

  // Step 5: Change the prev of start and next of last as new node
  (*start)->prev = newNode;
  last->next = newNode;
}

void Node::remove(Node **linkedList, int position) {
  // Case 1: If linked list is empty
  if (*linkedList == nullptr) {
    return;
  }

  // Case 2: If linked list is not empty
  // Step 1: Init current node and previous node
  Node *current = *linkedList;
  Node *previous = nullptr;

  // Step 2: Find previous node of the node to be deleted
  for (int i = 0; i < position; ++i) {
    previous = current;
    current = current->next;
  }

  // Step 3: Check if node to be deleted is the only node in the linked list
  if (current->next == *linkedList && previous == nullptr) {
    *linkedList = nullptr;
    return;
  }

  cout << current->data << endl;

  // Step 4: If more than one node, check if it is the first node
  if (current == *linkedList) {
    previous = (*linkedList)->prev; // Make the previous node because in this case is nullptr

    *linkedList = (*linkedList)->next;
    previous->next = *linkedList;
    (*linkedList)->prev = previous;

    free(current); // Liberating memory
  } else if (current->next == *linkedList) {
    // Step 5: If it is the last node
    previous->next = *linkedList;
    (*linkedList)->prev = previous;

    free(current); // Liberating memory
  } else {
    // Step 6: If it is another node
    Node *temp = current->next;

    previous->next = temp;
    temp->prev = previous;

    free(current); // Liberating memory
  }

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