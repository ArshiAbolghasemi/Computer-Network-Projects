#ifndef __USER_ENTITY_HPP
#define __USER_ENTITY_HPP

#include <string>
#include "Entity.hpp"

using namespace std;

class UserEntity : public Entity
{
private:
    int id;

    string name;

    string password;

    double wallet;

    string phoneNumber;

    string address;
    
    bool isAdmin;
public:
    UserEntity(
        int _id,
        string _name,
        string _password,
        double _wallet,
        string _phoneNumber,
        string _address,
        bool _isAdmin
    );

    static string getJsonFilePath();

    static string getTableName();

    static UserEntity* getInstance(json jsonData);

    string getName();

    UserEntity* setName(string _name);

    string getPassword();

    UserEntity* setPassword(string _password);

    double getWallet();

    UserEntity* setWallet(double _wallet);

    string getPhoneNumber();

    UserEntity* setPhoneNumber(string _phoneNumber);

    string getAddress();

    UserEntity* setAddress(string _address);

    bool hasAdminAccess();

    UserEntity* setAdminAccess(bool _isAdmin);
};

#endif