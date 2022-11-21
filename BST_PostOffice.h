//
// Created by Yigit Sen on 27/10/2022.
//

#ifndef BST_POSTOFFICE_H
#define BST_POSTOFFICE_H
#include "Mail.h"
#include "BST_Mailman.h"

enum printType
{
    inorder = 1,
    postorder = 2,
    preorder = 3
};

class BST_PostOffice;

class BST_PostOffice_Node
{
    friend class BST_PostOffice;

    District district;
    BST_PostOffice *left;
    BST_PostOffice *right;
    BST_Mailman mailman[HASH_MODULO];

public:
    BST_PostOffice_Node();
    BST_PostOffice_Node(Mail *mail);
    ~BST_PostOffice_Node();

    BST_PostOffice * getLeftBST() const;
    BST_PostOffice * getRightBST() const;
    District getDistrict() const;
    void print(printType type) const;
    void printMailman(int i, printType type) const;

    Mail *find(int id, std::string streetName);
    bool remove(int id, std::string streetName);
    void addMail(Mail *mail);
};

class BST_PostOffice
{
    friend class BST_PostOffice_Node;

    BST_PostOffice_Node *root = nullptr;

public:
    BST_PostOffice();
    ~BST_PostOffice();

    void printInOrder() const;
    void printPostOrder() const;
    void printPreOrder() const;
    void printMailman(District district, int i, printType type) const;
    void printDistrict(District dist, printType type) const;

    void addMail(Mail *mail);
    Mail *find(District dist, int id, std::string streetName);
    bool remove(District dist, int id, std::string streetName);
};


#endif //BST_POSTOFFICE_H
