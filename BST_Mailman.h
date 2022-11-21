//
// Created by Yigit Sen on 27/10/2022.
//

#ifndef BST_MAILMAN_H
#define BST_MAILMAN_H
#include "iostream"
#include <string>
#include "Mail.h"

const int MAX_NUM_MAILS = 100;

class BST_Mailman;

class BST_Mailman_Node
{
    friend class BST_Mailman;

    std::string streetName;
    Mail *mailPtr[MAX_NUM_MAILS];
    int currentMailsStored = 0;
    BST_Mailman *right;
    BST_Mailman *left;

public:
    BST_Mailman_Node();
    BST_Mailman_Node(Mail *mail);
    ~BST_Mailman_Node();

    BST_Mailman * getLeftBST() const;
    BST_Mailman * getRightBST() const;
    std::string getStreetName() const;
    void print() const;

    void addMail(Mail * mail);
    Mail *find(int id);
    bool remove(int id);
};


class BST_Mailman
{
    friend class BST_Mailman_Node;

    BST_Mailman_Node *root;

public:
    BST_Mailman();
    ~BST_Mailman();

    void printInOrder() const;
    void printPostOrder() const;
    void printPreOrder() const;

    void addMail(Mail *mail);
    Mail *find(int id, std::string streetName);
    bool remove(int id, std::string streetName);
};

#endif //BST_V2_BST_MAILMAN_H
