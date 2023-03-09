#include <cassert>
#include <iostream>
#include "../../src/Entity/UserEntity.hpp"

using namespace std;

void test1()
{
    UserEntity* user  = UserEntity::getById<UserEntity>(1);
    
    assert(user->getId() == 1);
    assert(user->getName() == "Morad");
    assert(user->getPassword() == "1234");
    assert(user->hasAdminAccess() == false);
    assert(user->getWallet() == 1000);
    assert(user->getPhoneNumber() == "00945692356");
    assert(user->getAddress() == "Canada, Montral");

    cout << "Test 1 passed\n";
}

int main()
{
    test1();

    return 0;
}