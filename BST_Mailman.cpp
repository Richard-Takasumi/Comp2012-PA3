//
// Created by Yigit Sen on 27/10/2022.
//

#include "BST_Mailman.h"

// TODO: Constructors and Destructors
BST_Mailman::BST_Mailman()
{
}

BST_Mailman_Node::BST_Mailman_Node(Mail *mail)
{
}

BST_Mailman::~BST_Mailman()
{
}

BST_Mailman_Node::~BST_Mailman_Node()
{
}

// TODO: Getters
std::string BST_Mailman_Node::getStreetName() const
{
}

BST_Mailman * BST_Mailman_Node::getRightBST() const
{
}

BST_Mailman * BST_Mailman_Node::getLeftBST() const
{
}


// TODO add mail to the array mailPtr[] - NOTE: WE WILL NEVER ASK YOU TO
//  PUT TOO MANY MAILS. (a max of MAX_NUM_MAILS add_mail calls)
void BST_Mailman::addMail(Mail *mail)
{
}

void BST_Mailman_Node::addMail(Mail *mail)
{
}

// TODO: Remove a mail, given its street name and ID
bool BST_Mailman::remove(int id, std::string streetName)
{
}

bool BST_Mailman_Node::remove(int id)
{
}

// TODO: Find a mail item, given its street name and ID
Mail * BST_Mailman::find(int id, std::string streetName)
{
}

Mail *BST_Mailman_Node::find(int id)
{
}


// TODO: Print functions. See example outputs for the necessary formats.
void BST_Mailman::printInOrder() const
{
}

void BST_Mailman::printPostOrder() const
{
}

void BST_Mailman::printPreOrder() const
{
}

void BST_Mailman_Node::print() const
{
    std::cout << "BST Node for Street: " << streetName << std::endl;
    for (int i = 0; i < currentMailsStored; ++i) {
        if(mailPtr[i] != nullptr)
        {
            mailPtr[i]->printMail();
        }
    }
}
