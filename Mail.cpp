
#include "Mail.h"

Mail::Mail(int id, std::string address, District district, std::string streetName, std::string content) :
address(address), district(district), streetName(streetName), content(content), id(id)
{
    hashAddress();
}


// TODO: Calculate Hash Address
void Mail::hashAddress()
{
}

// DO NOT TOUCH REST OF THE FUNCTIONS!
void Mail::printMail() const
{
    std::cout << "------------" << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Hash: " << addressHash << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "District: " << District(district) << std::endl;
    std::cout << "Street Name: " << streetName << std::endl;
    std::cout << "Content: " << content << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << std::endl;
}


const std::string Mail::getStreetName() const
{
    return streetName;
}

const int Mail::getId() const
{
    return id;
}

const std::string &Mail::getAddress() const
{
    return address;
}

const District Mail::getDistrict() const
{
    return district;
}

const std::string &Mail::getContent() const
{
    return content;
}

const int Mail::getAddressHash() const
{
    return addressHash;
}