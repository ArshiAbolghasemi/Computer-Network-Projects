#include "UserEntity.hpp"

UserEntity::UserEntity(
    int _id,
    std::string _name,
    std::string _password,
    double _wallet,
    std::string _phoneNumber,
    std::string _address,
    bool _isAdmin
) : Entity(_id),
    name(_name), 
    password(_password), 
    wallet(_wallet), 
    phoneNumber(_phoneNumber),
    address(_address),
    isAdmin(_isAdmin) {}

std::string UserEntity::getJsonFilePath()
{
    return "UsersInfo.json";
}

std::string UserEntity::getTableName()
{
    return "users";
}

UserEntity* UserEntity::getInstance(nlohmann::json jsonData)
{
    return (new UserEntity(
        jsonData.at("id"),
        jsonData.at("name"),
        jsonData.at("password"),
        jsonData.value("wallet", 0),
        jsonData.value("phoneNumber", ""),
        jsonData.value("address", ""),
        jsonData.at("admin")
    )); 
}

std::string UserEntity::getName()
{
    return this->name;
}

UserEntity* UserEntity::setName(std::string _name)
{
    this->name = _name;
    return this;
}

std::string UserEntity::getPassword()
{
    return this->password;
}

UserEntity* UserEntity::setPassword(std::string _password)
{
    this->password = _password;
    return this;
}

double UserEntity::getWallet()
{
    return this->wallet;
}

UserEntity* UserEntity::setWallet(double _wallet)
{
    this->wallet = _wallet;
    return this;
}

std::string UserEntity::getPhoneNumber()
{
    return this->phoneNumber;
}

UserEntity* UserEntity::setPhoneNumber(std::string _phoneNumber)
{
    this->phoneNumber = _phoneNumber;
    return this;
}

std::string UserEntity::getAddress()
{
    return this->address;
}

UserEntity* UserEntity::setAddress(std::string _address)
{
    this->address = _address;
    return this;
}

bool UserEntity::hasAdminAccess()
{
    return this->isAdmin;
}

UserEntity* UserEntity::setAdminAccess(bool _isAdmin)
{
    this->isAdmin = _isAdmin;
    return this;
}