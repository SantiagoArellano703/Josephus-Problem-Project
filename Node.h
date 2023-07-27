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

    static void display(Node *start);

    static Node *createDCLL(int n);

    static int josephus(Node *head, int k);

    static int josephusReverse(Node *head, int k);
};


#endif //UNTITLED_NODE_H
