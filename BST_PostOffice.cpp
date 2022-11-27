//
// Created by Yigit Sen on 27/10/2022.
//

#include "BST_PostOffice.h"

// TODO: Constructors and Destructors

//TIP: root will be nullptr at first, and we'll add a node once we try to add a mail object.
BST_PostOffice::BST_PostOffice()
{
    // // std::cout << "\t\tBST_PostOffice::BST_PostOffice() Constructor" << std::endl; 
    root = nullptr;
}

BST_PostOffice_Node::BST_PostOffice_Node(Mail *mail)
{
    // // std::cout << "\t\tBST_PostOffice::BST_PostOffice_Node() Constructor" << std::endl;
    district = mail->getDistrict();
    left = nullptr;
    right = nullptr;
    mailman[mail->getAddressHash()].addMail(mail);

}

BST_PostOffice::~BST_PostOffice()
{
    // // std::cout << "\t\tBST_PostOffice::BST_PostOffice() Destructor" << std::endl;
    if (root != nullptr) {
        delete root;
    }
    
}

BST_PostOffice_Node::~BST_PostOffice_Node()
{
    // // std::cout << "\t\tBST_PostOffice::BST_PostOffice_node() Destructor" << std::endl;
    if (left != nullptr) {
        delete left;
    }
    if (right != nullptr) {
        delete right;
    }

}

// TODO: Accessor functions.
BST_PostOffice * BST_PostOffice_Node::getLeftBST() const
{
    return left;

}

BST_PostOffice * BST_PostOffice_Node::getRightBST() const
{
    return right;
}

District BST_PostOffice_Node::getDistrict() const
{
    return district;
}


//TODO: Given a district, id and street name, find the mail object.
Mail *BST_PostOffice::find(District dist, int id, std::string streetName)
{
    // std::cout << "\t\tBST_PostOffice::find" << std::endl;
    // go down BST until district, then call find...   

    // find based on recursion
    if (this->root->getDistrict() == dist) {

        return this->root->find(id, streetName);
    }
    else if (dist < this->root->getDistrict() && this->root->left != nullptr) {
        return this->root->left->find(dist, id, streetName);
    } 
    else if (dist > this->root->getDistrict() && this->root->right != nullptr) {
        return this->root->right->find(dist, id, streetName);
    }

    return nullptr;


}

Mail *BST_PostOffice_Node::find(int id, std::string streetName)
{   
    // for each mailman,
    // we can check if the mailman has the mail
    // std::cout << "\t\tBST_PostOffice_Node::find" << std::endl;
    for ( int i = 0; i < HASH_MODULO; i++) {
        Mail* found_mail = mailman[i].find(id, streetName);
        if (found_mail != nullptr) {
            return found_mail;
        };
    }
    return nullptr;

}


// TODO: Given a district, id and street name, remove the mail object from the
// system.
bool BST_PostOffice::remove(District dist, int id, std::string streetName)
{
    // std::cout << "\t\tBST_PostOffice::remove" << std::endl;
    if (streetName.empty() || id == NULL ) {
        return false;
    }

    // remove based on recursion
    if (this->root->getDistrict() == dist) {
        return this->root->remove(id, streetName);
    }
    else if (dist < this->root->getDistrict() && this->root->left != nullptr) {
        return this->root->left->remove(dist, id, streetName);
    } 
    else if (dist > this->root->getDistrict() && this->root->right != nullptr) {
        return this->root->right->remove(dist, id, streetName);
    }

    return false;


}

bool BST_PostOffice_Node::remove(int id, std::string streetName)
{
    // std::cout << "\t\tBST_PostOffice_Node::remove" << std::endl;
    for ( int i = 0; i < HASH_MODULO; i++) {
        if (mailman[i].remove(id, streetName) == true) {
            return true;
        } 
    }   
    
    return false;
}

// TODO: Add mail to the system
void BST_PostOffice::addMail(Mail *mail)
{ 
    // std::cout << "\t\tBST_PostOffice::addMail" << std::endl;
    if (mail == nullptr) {
        return;
    }

    if (this->root == nullptr) {
        this->root = new BST_PostOffice_Node(mail);
    }

    else if (this->root->getDistrict() == mail->getDistrict()) {
        this->root->addMail(mail);
    } 
    else if (mail->getDistrict() < this->root->getDistrict()) {
        if (this->root->left == nullptr) {
            this->root->left = new BST_PostOffice();
        }
        this->root->left->addMail(mail);
    }
    else if (mail->getDistrict() > this->root->getDistrict()) {
        if (this->root->right == nullptr) {
            this->root->right = new BST_PostOffice();
        }
        this->root->right->addMail(mail);
    }

}

void BST_PostOffice_Node::addMail(Mail *mail)
{
    // std::cout << "\t\tBST_PostOffice_Node::addMail" << std::endl;
    // add the mail to the mailman array at index == mail.addressHash;
    if (mail == nullptr) {
        return;
    }
    mailman[mail->getAddressHash()].addMail(mail);
}

// TODO: Given a district, print all of the data in it.
// TIP: Print style depends on type.
void BST_PostOffice::printDistrict(District dist, printType type) const
{  
    // std::cout << "\t\tBST_PostOffice::printDistrict" << std::endl;
    

    if (this->root == nullptr) {
        return;
    }

    if (this->root->getDistrict() == dist) {
        std::cout << "The District Mail Report for district " << dist << std::endl;
        this->root->print(type);
    }
    else if (dist < this->root->getDistrict() && this->root->left != nullptr) {
        this->root->left->printDistrict(dist, type);
    }
    else if (dist > this->root->getDistrict() && this->root->right != nullptr) {
        this->root->right->printDistrict(dist, type);
    }

    return;
}

void BST_PostOffice_Node::print(printType type) const
{
    // std::cout << "\t\tBST_PostOffice_Node::print" << std::endl;
    if (type != 1 && type != 2 && type != 3) {
        return;
    }

    for (int i = 0; i < HASH_MODULO; i++) {
        std::cout << "For Mailman " << i << std::endl;
        printMailman(i, type);
    }

}

// TODO: Given a district and ID of the mailman, print all mail in it
// TIP: Print style depends on type - see the header file
void BST_PostOffice::printMailman(District district, int i, printType type) const
{
    // std::cout << "\t\tBST_PostOffice::printMailman" << std::endl;
    if (this->root == nullptr) {
        return;
    }

    if (this->root->getDistrict() == district) {
        
        this->root->printMailman(i, type);
    }
    else if (district < this->root->getDistrict() && this->root->left != nullptr) {
        this->root->left->printMailman(district, i, type);
    }
    else if (district > this->root->getDistrict() && this->root->right != nullptr) {
        this->root->right->printMailman(district, i, type);
    }

    return;
}

void BST_PostOffice_Node::printMailman(int i, printType type) const
{
    // // std::cout << "\t\tBST_PostOffice_Node::printMailman" << std::endl;
    switch (type) {
        // in order
        case 1:
            mailman[i].printInOrder();
            break;

        // post order
        case 2:
            mailman[i].printPostOrder();
            break;


        // pre order
        case 3:
            mailman[i].printPreOrder();
            break;

        default:
            break;
    }
}

// TODO: Other print functions.
void BST_PostOffice::printInOrder() const
{
    // std::cout << "\t\tBST_PostOffice::printInOrder()" << std::endl;
    if (this->root == nullptr) {
        return;
    }

    if (this->root->left != nullptr) {
        this->root->left->printInOrder();
    }
    std::cout << "BST Node for District: " << this->root->getDistrict() << std::endl;
    for (int i = 0; i < HASH_MODULO; i++) {
        this->root->printMailman(i, printType::inorder);
    }

    if (this->root->right != nullptr) {
        this->root->right->printInOrder();    
    }

    return;

}

void BST_PostOffice::printPostOrder() const
{
    // std::cout << "\t\tBST_PostOffice::printPostOrder()" << std::endl;
    if (this->root == nullptr) {
        return;
    }

    if (this->root->left != nullptr) {
        this->root->left->printPostOrder();
    }
    if (this->root->right != nullptr) {
        this->root->right->printPostOrder();    
    }
    std::cout << "BST Node for District: " << this->root->getDistrict() << std::endl;
    for (int i = 0; i < HASH_MODULO; i++) {
        this->root->printMailman(i, printType::postorder);
    }

    return;
}

void BST_PostOffice::printPreOrder() const
{
    // std::cout << "\t\tBST_PostOffice::printPreOrder()" << std::endl;
    if (this->root == nullptr) {
        return;
    }

    std::cout << "BST Node for District: " << this->root->getDistrict() << std::endl;
    for (int i = 0; i < HASH_MODULO; i++) {
        this->root->printMailman(i, printType::preorder);
    }
    if (this->root->left != nullptr) {
        this->root->left->printPreOrder();
    }
    if (this->root->right != nullptr) {
        this->root->right->printPreOrder();    
    }

    return;
}