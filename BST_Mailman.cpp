//
// Created by Yigit Sen on 27/10/2022.
//

#include "BST_Mailman.h"

// TODO: Constructors and Destructors
BST_Mailman::BST_Mailman()
{
    // // std::cout << "\tcalling BST_Mailman::BST_Mailman() CONSTRUCTOR" << std::endl;
    this->root = nullptr;
}

BST_Mailman_Node::BST_Mailman_Node(Mail *mail)
{
    // // std::cout << "\tcalling BST_Mailman_Node::BST_Mailman_Node CONSTRUCTOR" << std::endl;
    this->streetName = mail->getStreetName();
    for (int i = 0; i < MAX_NUM_MAILS; i++) {
        this->mailPtr[i] = nullptr;
    }
    this->mailPtr[0] = mail;
    this->currentMailsStored = 1;
    this->left = nullptr;
    this->right = nullptr;

}

BST_Mailman::~BST_Mailman()
{
    // // std::cout << "\tcalling BST_Mailman::~BST_Mailman DESTRUCTOR" << std::endl;
    // should resursively delete 
    delete this->root;    

}

BST_Mailman_Node::~BST_Mailman_Node()
{
    // // std::cout << "\tcalling BST_Mailman_Node::~BST_Mailman_Node DESTRUCTOR" << std::endl;
    for (int i = 0; i < MAX_NUM_MAILS; i++) {
        delete this->mailPtr[i];
    }
    if (this->left != nullptr) {
        delete this->left;
    }
    
    if (this->right != nullptr) {
        delete this->right;
    }
    
}

// TODO: Getters
std::string BST_Mailman_Node::getStreetName() const
{
    return this->streetName;
}

BST_Mailman * BST_Mailman_Node::getRightBST() const
{
    return this->right;
}

BST_Mailman * BST_Mailman_Node::getLeftBST() const
{
    return this->left;
}


// TODO add mail to the array mailPtr[] - NOTE: WE WILL NEVER ASK YOU TO
//  PUT TOO MANY MAILS. (a max of MAX_NUM_MAILS add_mail calls)
void BST_Mailman::addMail(Mail *mail)
{
    // // std::cout << "\tcalling BST_Mailman::addMail" << std::endl;

    if (mail == nullptr) {
        return;
    }

    // if the node is empty
    if (this->root == nullptr) {
        this->root = new BST_Mailman_Node(mail);
        return;
    }

    if (this->root->getStreetName() == mail->getStreetName()) {
        this->root->addMail(mail);
    } 
    else if (mail->getStreetName() < this->root->getStreetName()) {

        // if the left is empty, create a new mailman, and mailman_node and by default the mail will be added to that.
        if (this->root->left == nullptr) {
            this->root->left = new BST_Mailman();
        } 

        // when this it called, it will detect the new BST_Mailman() does not have a root,
        // so it will create a new BST_Mailman_Node with mail and add it.
        this->root->left->addMail(mail);    

        
    }
        // if the right is empty, create a new mailman, and mailman_node and by default the mail will be added to that.
    else if (mail->getStreetName() > this->root->getStreetName()) {
        if (this->root->right == nullptr) {
            this->root->right = new BST_Mailman();
        } 
        this->root->right->addMail(mail);    
    }

    return;

}


void BST_Mailman_Node::addMail(Mail *mail)
{
    // // std::cout << "\tcalling BST_Mailman_Node::addMail" << std::endl;
    this->mailPtr[this->currentMailsStored] = mail;
    this->currentMailsStored++;
}
// TODO: Remove a mail, given its street name and ID
bool BST_Mailman::remove(int id, std::string streetName)
{
    // // std::cout << "\tcalling BST_Mailman::remove" << std::endl;
    if (streetName.empty()) {
        return false;
    }

    if (this->root == nullptr) {
        return false;
    }

    if (this->root->getStreetName() == streetName) {
        return this->root->remove(id);
    }
    else if (streetName < this->root->getStreetName() && this->root->left != nullptr) {
        return this->root->left->remove(id, streetName);
    } 
    else if (streetName > this->root->getStreetName() && this->root->right != nullptr) {
        return this->root->right->remove(id, streetName);
    }

    return false;
}

bool BST_Mailman_Node::remove(int id)
{
    // // std::cout << "\tcalling BST_Mailman_Node::remove" << std::endl;
    for (int i = 0; i < this->currentMailsStored; i++) {
        if (this->mailPtr[i]->getId() == id) {
            // deleteion method
            delete this->mailPtr[i];
            this->mailPtr[i] = nullptr;
            return true;
        }
    }
    return false;

}

// TODO: Find a mail item, given its street name and ID
Mail * BST_Mailman::find(int id, std::string streetName)
{
    // // std::cout << "\tcalling BST_Mailman::find" << std::endl;
    if (streetName == "") {
        return nullptr;
    }

    if (this->root == nullptr) {
        return nullptr;
    }

    // remove based on recursion
    if (this->root->getStreetName() == streetName) {
        return this->root->find(id);
    }
    else if (streetName < this->root->getStreetName() && this->root->left != nullptr) {
        return this->root->left->find(id, streetName);
    } 
    else if (streetName > this->root->getStreetName() && this->root->right != nullptr) {
        return this->root->right->find(id, streetName);
    }

    return nullptr;

}

Mail *BST_Mailman_Node::find(int id)
{
    // // std::cout << "\tcalling BST_Mailman_Node::find" << std::endl;
    for (int i = 0; i < this->currentMailsStored; i++) {
        if (this->mailPtr[i]->getId() == id) {
            // deleteion method
            return this->mailPtr[i];
        }
    }
    return nullptr;

}


// TODO: Print functions. See example outputs for the necessary formats.
void BST_Mailman::printInOrder() const
{
    // // std::cout << "\tcalling BST_Mailman::printInOrder()" << std::endl;
    if (this->root == nullptr) {
        return;
    }

    if (this->root->left != nullptr) {
        this->root->left->printInOrder();
    }
    
    this->root->print();


    if (this->root->right != nullptr) {
        this->root->right->printInOrder();    
    }
    
    return;
}

void BST_Mailman::printPostOrder() const
{
    // // std::cout << "\tcalling BST_Mailman::printPostOrder()" << std::endl;
    if (this->root == nullptr) {
        return;
    }

    if (this->root->left != nullptr) {
        this->root->left->printPostOrder();
    }
    
    if (this->root->right != nullptr) {
        this->root->right->printPostOrder();
    }
    
    this->root->print();



    return;
}

void BST_Mailman::printPreOrder() const
{
    // // std::cout << "\tcalling BST_Mailman::printPreOrder()" << std::endl;

    if (this->root == nullptr) {
        return;
    }

    this->root->print();

    if (this->root->left != nullptr) {
        this->root->left->printPreOrder();
    }
    
    if (this->root->right != nullptr) {
        this->root->right->printPreOrder();
    }

    return;
}

void BST_Mailman_Node::print() const
{
    // std::cout << "\tcalling BST_Mailman_Node::print()" << std::endl;
    std::cout << "BST Node for Street: " << streetName << std::endl;
    for (int i = 0; i < currentMailsStored; ++i) {
        if(mailPtr[i] != nullptr)
        {
            mailPtr[i]->printMail();
        }
    }
}
