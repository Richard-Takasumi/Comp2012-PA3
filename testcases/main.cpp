//
// Created by Yigit Sen on 16/11/2022.
//
#include <iostream>
#include "BST_PostOffice.h"
using namespace std;
void testcase1()
{
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    if(m->getAddressHash() == 2)
    {
        cout << "Address Hash Function Verified" << endl;
    }
    else
    {
        cout << "Address Hash Function NOT verified" << endl;
    }
    delete m;
}


// Covers adding and printing district based on inorder
void testcase2()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    po->printDistrict(District::SaiKung, printType::inorder);
    delete po;
}

// Covers adding and printing based on mailman
// How - we know from test case 1 that the mail m will have a hash value of 2
void testcase3()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    po->printMailman(District::SaiKung,2, printType::inorder);
    delete po;

}

// Adding two mails to the the same district
// How - we know from test case 1 that the mail m will have a hash value of 2
void testcase4()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address, Sai Kung Town", District::SaiKung, "Sample", "Hello there!");
    po->addMail(m2);
    po->printDistrict(District::SaiKung,printType::inorder);
    delete po;

}

// Adding two mails to the same mailman
// How - we know from test case 1 that the mail m will have a hash value of 2
void testcase5()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::SaiKung, "Sample", "Hello there!");
    po->addMail(m2);
    po->printDistrict(District::SaiKung,printType::inorder);
    delete po;

}

// Adding two mails to different districts
// How - we know from test case 1 that the mail m will have a hash value of 2
void testcase6()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    po->printDistrict(District::SaiKung,printType::inorder);
    po->printDistrict(District::CentralAndWestern,printType::inorder);
    po->printInOrder();
    delete po;

}

// Adding two mails to different districts
// How - we know from test case 1 that the mail m will have a hash value of 2
void testcase7()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);

    po->printDistrict(District::SaiKung,printType::inorder);
    po->printDistrict(District::CentralAndWestern,printType::inorder);
    po->printInOrder();
    delete po;
}

// Adding two mails to different districts
// How - we know from test case 1 that the mail m will have a hash value of 2
void testcase8()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail * find = po->find(District::CentralAndWestern, 4, "Sample");
    if(find == m4)
    {
        std::cout << "Pointers Match!" << std::endl;
    }
    delete po;
}
void testcase9()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    bool flag = po->remove(District::CentralAndWestern, 4, "Sample");
    if(flag == true)
    {
        std::cout << "Removed!" << std::endl;
    }
    delete po;
}

void testcase10()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    bool flag = po->remove(District::SaiKung, 4, "Sample");
    if(flag == false)
    {
        std::cout << "Successfully Not Removed!" << std::endl;
    }
    delete po;
}

void testcase11()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail * flag = po->find(District::CentralAndWestern, 4, "Sample 2");
    if(flag == nullptr)
    {
        std::cout << "Successfully Not Found!" << std::endl;
    }
    delete po;
}

void testcase12()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail *m5 = new Mail(5, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m5);

    Mail *m6 = new Mail(6, "New Sample Town", District::ShaTin, "Sample", "Hello there!");
    po->addMail(m6);

    Mail *m7 = new Mail(7, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m7);

    Mail *m8 = new Mail(8, "Sample Building, Sample 2 Street, Kennedy Town", District::Eastern, "Sample", "Hello there!");
    po->addMail(m8);

    Mail *m9 = new Mail(9, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m9);


    po->printInOrder();
    delete po;
}


void testcase13()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail *m5 = new Mail(5, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m5);

    Mail *m6 = new Mail(6, "New Sample Town", District::ShaTin, "Sample", "Hello there!");
    po->addMail(m6);

    Mail *m7 = new Mail(7, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m7);

    Mail *m8 = new Mail(8, "Sample Building, Sample 2 Street, Kennedy Town", District::Eastern, "Sample", "Hello there!");
    po->addMail(m8);

    Mail *m9 = new Mail(9, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m9);
    po->printPreOrder();
    delete po;
}
void testcase14()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail *m5 = new Mail(5, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m5);

    Mail *m6 = new Mail(6, "New Sample Town", District::ShaTin, "Sample", "Hello there!");
    po->addMail(m6);

    Mail *m7 = new Mail(7, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m7);

    Mail *m8 = new Mail(8, "Sample Building, Sample 2 Street, Kennedy Town", District::Eastern, "Sample", "Hello there!");
    po->addMail(m8);

    Mail *m9 = new Mail(9, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m9);
    po->printPostOrder();
    delete po;
}


void testcase15()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail *m5 = new Mail(5, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m5);

    Mail *m6 = new Mail(6, "New Sample Town", District::ShaTin, "Sample", "Hello there!");
    po->addMail(m6);

    Mail *m7 = new Mail(7, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m7);

    Mail *m8 = new Mail(8, "Sample Building, Sample 2 Street, Kennedy Town", District::Eastern, "Sample", "Hello there!");
    po->addMail(m8);

    Mail *m9 = new Mail(9, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m9);
    po->printDistrict(District::CentralAndWestern, printType::inorder);
    delete po;
}

void testcase16()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail *m5 = new Mail(5, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m5);

    Mail *m6 = new Mail(6, "New Sample Town", District::ShaTin, "Sample", "Hello there!");
    po->addMail(m6);

    Mail *m7 = new Mail(7, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m7);

    Mail *m8 = new Mail(8, "Sample Building, Sample 2 Street, Kennedy Town", District::Eastern, "Sample", "Hello there!");
    po->addMail(m8);

    Mail *m9 = new Mail(9, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m9);
    po->printDistrict(District::CentralAndWestern, printType::preorder);
    delete po;
}
void testcase17()
{
    BST_PostOffice *po = new BST_PostOffice;
    Mail *m = new Mail(1, "Starbucks, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m);
    Mail *m2 = new Mail(2, "Sample Address 3, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m2);
    Mail *m3 = new Mail(3, "Bookstore, Academic Concourse, HKUST, Clear Water Bay, Sai Kung, NT", District::SaiKung, "HKUST", "Please give students more discount");
    po->addMail(m3);
    Mail *m4 = new Mail(4, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m4);
    Mail *m5 = new Mail(5, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m5);

    Mail *m6 = new Mail(6, "New Sample Town", District::ShaTin, "Sample", "Hello there!");
    po->addMail(m6);

    Mail *m7 = new Mail(7, "HSBC, Sai Kung Town", District::CentralAndWestern, "Sample", "Hello there!");
    po->addMail(m7);

    Mail *m8 = new Mail(8, "Sample Building, Sample 2 Street, Kennedy Town", District::Eastern, "Sample", "Hello there!");
    po->addMail(m8);

    Mail *m9 = new Mail(9, "HSBC Building, Central", District::CentralAndWestern, "Queens Road Central", "Hello there!");
    po->addMail(m9);
    po->printDistrict(District::CentralAndWestern, printType::postorder);
    delete po;
}


int main()
{
    int testcase = 0;
    cin >> testcase;
    switch(testcase)
    {
        case 1:
            testcase1();
            break;
        case 2:
            testcase2();
            break;
        case 3:
            testcase3();
            break;
        case 4:
            testcase4();
            break;
        case 5:
            testcase5();
            break;
        case 6:
            testcase6();
            break;
        case 7:
            testcase7();
            break;
        case 8:
            testcase8();
            break;
        case 9:
            testcase9();
            break;
        case 10:
            testcase10();
            break;
        case 11:
            testcase11();
            break;
        case 12:
            testcase12();
            break;
        case 13:
            testcase13();
            break;
        case 14:
            testcase14();
            break;
        case 15:
            testcase15();
            break;
        case 16:
            testcase16();
            break;
        case 17:
            testcase17();
            break;
    }
}