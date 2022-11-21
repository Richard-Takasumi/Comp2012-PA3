#include <iostream>
#include "BST_PostOffice.h"

using namespace std;

BST_PostOffice *po;
int mailCount = 1;

void sendMail()
{
    string address = "";
    int district = 0;
    string streetName = "";
    string content = "";
    cout << "Please enter the address: \n" << endl;
    cin.clear();
    cin.sync();
    cin.ignore();
    getline(cin, address);
    cout << "-----------------------------------" << endl;
    cout << "Please enter the street name: \n" << endl;
    cin.clear();
    cin.sync();
    getline(cin, streetName);
    cout << "-----------------------------------" << endl;
    cout << "Please enter the district number: " << endl;
    cout << "Islands: 1\t\tKwai Tsing: 2\tNorth: 3" << endl;
    cout << "Sai Kung: 4\t\tSha Tin: 5\t\tTai Po: 6" << endl;
    cout << "Tsuen Wan: 7\tTuen Mun: 8\t\tYuen Long: 9" << endl;
    cout << "Kowloon: 10\t\tKwun Tong: 11\tSham Shui Po: 12" << endl;
    cout << "WongTaiSin: 13\tYauTsimMong: 14\tCentral/Western: 15" << endl;
    cout << "Eastern: 16\t\tSouthern: 17\tWan Chai: 18\n" << endl;

    cin.clear();
    cin.sync();
    string strTemp = "";
    getline(cin, strTemp);
    district = stoi( strTemp);
    cout << "-----------------------------------" << endl;
    cout << "Please enter the content: \n" << endl;
    cin.clear();
    cin.sync();
    getline(cin, content);
    Mail *m = new Mail(mailCount, address, District(district), streetName, content);
    po->addMail(m);
    cout << "Your mail has been posted!" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cin.clear();
    cin.sync();
    cin.ignore();
}

void removeMail()
{
    string districtStr;
    string streetName;
    string idStr;
    cout << "Please enter the district number: " << endl;
    cout << "Islands: 1\t\tKwai Tsing: 2\tNorth: 3" << endl;
    cout << "Sai Kung: 4\t\tSha Tin: 5\t\tTai Po: 6" << endl;
    cout << "Tsuen Wan: 7\tTuen Mun: 8\t\tYuen Long: 9" << endl;
    cout << "Kowloon: 10\t\tKwun Tong: 11\tSham Shui Po: 12" << endl;
    cout << "WongTaiSin: 13\tYauTsimMong: 14\tCentral/Western: 15" << endl;
    cout << "Eastern: 16\t\tSouthern: 17\tWan Chai: 18\n" << endl;

    cin.clear();
    cin.sync();
    cin.ignore();
    getline(cin, districtStr);
    cout << "-----------------------------------" << endl;
    cout << "Please enter the street name: \n" << endl;
    cin.clear();
    cin.sync();
    getline(cin, streetName);
    cout << "-----------------------------------" << endl;
    cout << "Please enter the ID number of the mail item: \n" << endl;
    cin.clear();
    cin.sync();
    getline(cin, idStr);
    cout << "-----------------------------------" << endl;

    bool success = po->remove(District(stoi(districtStr)), stoi(idStr), streetName);
    if(success)
    {
        cout << "We have removed the mail item from delivery schedule! \n" << endl;
        cout << "-----------------------------------" << endl;
    }
    else
    {
        cout << "We didn't find the mail item in our circulation. Try again. \n" << endl;
        cout << "-----------------------------------" << endl;
    }
    cin.clear();
    cin.sync();
    cin.ignore();
}

void printForPostOffice( printType type)
{
    int district;
    cout << "Please enter the district number: " << endl;
    cout << "Islands: 1\t\tKwai Tsing: 2\tNorth: 3" << endl;
    cout << "Sai Kung: 4\t\tSha Tin: 5\t\tTai Po: 6" << endl;
    cout << "Tsuen Wan: 7\tTuen Mun: 8\t\tYuen Long: 9" << endl;
    cout << "Kowloon: 10\t\tKwun Tong: 11\tSham Shui Po: 12" << endl;
    cout << "WongTaiSin: 13\tYauTsimMong: 14\tCentral/Western: 15" << endl;
    cout << "Eastern: 16\t\tSouthern: 17\tWan Chai: 18\n" << endl;

    cin.clear();
    cin.sync();
    cin.ignore();
    cin >> district;
    po->printDistrict(District(district), type);
}

void printForPostman(printType type)
{
    int district;
    int cc;
    cout << "Please enter the district number: " << endl;
    cout << "Islands: 1\t\tKwai Tsing: 2\tNorth: 3" << endl;
    cout << "Sai Kung: 4\t\tSha Tin: 5\t\tTai Po: 6" << endl;
    cout << "Tsuen Wan: 7\tTuen Mun: 8\t\tYuen Long: 9" << endl;
    cout << "Kowloon: 10\t\tKwun Tong: 11\tSham Shui Po: 12" << endl;
    cout << "WongTaiSin: 13\tYauTsimMong: 14\tCentral/Western: 15" << endl;
    cout << "Eastern: 16\t\tSouthern: 17\tWan Chai: 18\n" << endl;

    cin.clear();
    cin.sync();
    cin.ignore();
    cin >> district;
    cout << "Please enter the courier code: \n" << endl;
    cin.clear();
    cin.sync();
    cin.ignore();
    cin >> cc;
    po->printMailman(District(district), cc, type);
}

void printPO(printType type)
{
    switch (type) {
        case printType::inorder:
            po->printInOrder();
            break;
        case printType::postorder:
            po->printPostOrder();
            break;
        case printType::preorder:
            po->printPreOrder();
            break;
        default:
            break;
    }
}

int main()
{
    po = new BST_PostOffice;
    cout << "Welcome to Central Post Office!" << endl;
    while(true)
    {
        cout << "Please choose an option from the list below" << endl;
        cout << "1) Send a mail item" << endl;
        cout << "2) Remove a mail item from circulation" << endl;
        cout << "3) Print the current mail distribution report for district post offices (inorder)" << endl;
        cout << "4) Print the current mail distribution report for district post offices (postorder)" << endl;
        cout << "5) Print the current mail distribution report for district post offices (preorder)" << endl;
        cout << "6) Print the mail courier workload for today (inorder)" << endl;
        cout << "7) Print the mail courier workload for today (postorder)" << endl;
        cout << "8) Print the mail courier workload for today (preorder)" << endl;
        cout << "9) Print the mail system (inorder)" << endl;
        cout << "10) Print the mail system (postorder)" << endl;
        cout << "11) Print the mail system (preorder)" << endl;
        cout << "12) Exit Program" << endl;
        cout << "-------------------------------------------------------------------------" << endl;

        string i = "";
        int x = 0;
        bool exitFlag = false;
        cin >> i;
        // A quick note on how try-catch works:
        // If anything within a try block throws an error, then catch block starts to work, handling the error instead
        // of throwing a runtime error and shutting off the program.

        // see https://en.cppreference.com/w/cpp/language/try_catch for more details
        try
        {
            x = stoi(i);
        }
        catch (...)
        {
            cout << "Please enter a valid request." << endl;
            cout << "-------------------------------------------------------------------------" << endl;
            continue;
        }

        switch (x) {
            case 1:
                sendMail();
                break;
            case 2:
                removeMail();
                break;
            case 3:
                printForPostOffice(printType::inorder);
                break;
            case 4:
                printForPostOffice(printType::postorder);
                break;
            case 5:
                printForPostOffice(printType::preorder);
                break;
            case 6:
                printForPostman(printType::inorder);
                break;
            case 7:
                printForPostman(printType::postorder);
                break;
            case 8:
                printForPostman(printType::preorder);
                break;
            case 9:
                printPO(printType::inorder);
                break;
            case 10:
                printPO(printType::postorder);
                break;
            case 11:
                printPO(printType::preorder);
                break;
            case 12:
                exitFlag = true;
                break;
            default:
                break;
        }

        if(exitFlag)
        {
            cout << "Thank you for visiting the Central Post Office. Goodbye!" <<endl;
            break;
        }
    }
    return 0;
}