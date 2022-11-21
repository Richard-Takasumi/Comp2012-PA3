//
// Created by Yigit Sen on 27/10/2022.
//

#include "BST_PostOffice.h"

// TODO: Constructors and Destructors

//TIP: root will be nullptr at first, and we'll add a node once we try to add a mail object.
BST_PostOffice::BST_PostOffice()
{
}

BST_PostOffice_Node::BST_PostOffice_Node(Mail *mail)
{
}

BST_PostOffice::~BST_PostOffice()
{
}

BST_PostOffice_Node::~BST_PostOffice_Node()
{
}

// TODO: Accessor functions.
BST_PostOffice * BST_PostOffice_Node::getLeftBST() const
{
}

BST_PostOffice * BST_PostOffice_Node::getRightBST() const
{
}

District BST_PostOffice_Node::getDistrict() const
{
}


//TODO: Given a district, id and street name, find the mail object.
Mail *BST_PostOffice::find(District dist, int id, std::string streetName)
{
}

Mail *BST_PostOffice_Node::find(int id, std::string streetName)
{
}


// TODO: Given a district, id and street name, remove the mail object from the
// system.
bool BST_PostOffice::remove(District dist, int id, std::string streetName)
{
}

bool BST_PostOffice_Node::remove(int id, std::string streetName)
{
}

// TODO: Add mail to the system
void BST_PostOffice::addMail(Mail *mail)
{
}

void BST_PostOffice_Node::addMail(Mail *mail)
{
}

// TODO: Given a district, print all of the data in it.
// TIP: Print style depends on type.
void BST_PostOffice::printDistrict(District dist, printType type) const
{
}

void BST_PostOffice_Node::print(printType type) const
{
}

// TODO: Given a district and ID of the mailman, print all mail in it
// TIP: Print style depends on type - see the header file
void BST_PostOffice::printMailman(District district, int i, printType type) const
{
}

void BST_PostOffice_Node::printMailman(int i, printType type) const
{
}

// TODO: Other print functions.
void BST_PostOffice::printInOrder() const
{
}

void BST_PostOffice::printPostOrder() const
{
}

void BST_PostOffice::printPreOrder() const
{
}