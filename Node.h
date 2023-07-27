//
// Created by dylan-roman on 7/25/23.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H


class Node {
public:
    int data{};
    Node *next{};
    Node *prev{};

    Node();

    static void push(Node **start, int data);

    static void remove(Node **linkedList, int position);

    static void display(Node *start);

    static void removeBackwards(Node **linkedList, int position);
};


#endif //UNTITLED_NODE_H
