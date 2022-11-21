//
// Created by Yigit Sen on 27/10/2022.
//

#ifndef MAIL_H
#define MAIL_H
#include <string>
#include <iostream>

enum District
{
    Islands = 1,
    KwaiTsing,
    North,
    SaiKung,
    ShaTin,
    TaiPo,
    TsuenWan,
    TuenMun,
    YuenLong,
    Kowloon,
    KwunTong,
    ShamShuiPo,
    WongTaiSin,
    YauTsimMong,
    CentralAndWestern,
    Eastern,
    Southern,
    WanChai
};

const int HASH_MODULO = 10;

class Mail
{
private:
    //Each mail item will have a unique id
    const int id;
    const std::string address;
    const District district;
    const std::string streetName;
    const std::string content;
    int addressHash;
    void hashAddress();

public:
    // Constructor for the Mail object
    Mail(const int id,const std::string address,const District district,
         const std::string streetName, const std::string content);

    // Getter functions
    // As a mail in real life is unmodifiable after posting it, you won't need any setters.
    const int getId() const;
    const std::string &getAddress() const;
    const District getDistrict() const;
    const std::string &getContent() const;
    const int getAddressHash() const;
    const std::string getStreetName() const;

    // Prints the mail object stats
    void printMail() const;
};

#endif //BST_MAIL_H
