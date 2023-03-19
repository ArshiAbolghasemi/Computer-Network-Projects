#ifndef __USER_ENTITY_HPP
#define __USER_ENTITY_HPP

#include "Entity.hpp"
#include <string>
#include "../lib/json.hpp"

class UserEntity : public Entity
{
private:
    int id;

    std::string name;

    std::string password;

    double wallet;

    std::string phoneNumber;

    std::string address;
    
    bool isAdmin;

    int file_d;
public:
    UserEntity(
        int _id,
        std::string _name,
        std::string _password,
        double _wallet,
        std::string _phoneNumber,
        std::string _address,
        bool _isAdmin
    );

    static std::string getJsonFilePath();

    static std::string getTableName();

    static UserEntity* getInstance(nlohmann::json jsonData);

    std::string getName();

    UserEntity* setName(std::string _name);

    std::string getPassword();

    UserEntity* setPassword(std::string _password);

    double getWallet();

    UserEntity* setWallet(double _wallet);

    std::string getPhoneNumber();

    UserEntity* setPhoneNumber(std::string _phoneNumber);

    std::string getAddress();

    UserEntity* setAddress(std::string _address);

    bool hasAdminAccess();

    UserEntity* setAdminAccess(bool _isAdmin);
};

#endif