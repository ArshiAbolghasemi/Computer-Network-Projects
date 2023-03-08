#include "UserEntity.hpp"

UserEntity::UserEntity(
    int _id,
    string _name,
    string _password,
    int _wallet,
    string _phoneNumber,
    string _address,
    bool _isAdmin
) : Entity(_id),
    name(_name), 
    password(_password), 
    wallet(_wallet), 
    phoneNumber(_phoneNumber),
    address(_address),
    isAdmin(_isAdmin) {}

string UserEntity::getJsonFilePath()
{
    return "../../config/UsersInfo.json";
}

string UserEntity::getTableName()
{
    return "users";
}

string UserEntity::getName()
{
    return this->name;
}

UserEntity* UserEntity::setName(string _name)
{
    this->name = _name;
    return this;
}

string UserEntity::getPassword()
{
    return this->password;
}

UserEntity* UserEntity::setPassword(string _password)
{
    this->password = _password;
    return this;
}

int UserEntity::getWallet()
{
    return this->wallet;
}

UserEntity* UserEntity::setWallet(int _wallet)
{
    this->wallet = _wallet;
    return this;
}

string UserEntity::getPhoneNumber()
{
    return this->phoneNumber;
}

UserEntity* UserEntity::setPhoneNumber(string _phoneNumber)
{
    this->phoneNumber = _phoneNumber;
    return this;
}

string UserEntity::getAddress()
{
    return this->address;
}

UserEntity* UserEntity::setAddress(string _address)
{
    this->address = _address;
    return this;
}

bool UserEntity::hasAdminAccess()
{
    return this-isAdmin;
}

UserEntity* UserEntity::setAdminAccess(bool _isAdmin)
{
    this->isAdmin = _isAdmin;
    return this;
}