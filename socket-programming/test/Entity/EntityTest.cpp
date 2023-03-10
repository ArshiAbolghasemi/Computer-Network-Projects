#include <cassert>
#include <iostream>
#include "../../include/lib/EntityRepository.hpp"
#include "../../include/Entity/UserEntity.hpp"
#include "../../include/Entity/HotelRoomEntity.hpp"

void userEntityTest1()
{
    EntityRepository<UserEntity>* repo = new EntityRepository<UserEntity>();
    UserEntity* user  = repo->getById(1);
    
    assert(user->getId() == 1);
    assert(user->getName() == "Morad");
    assert(user->getPassword() == "1234");
    assert(user->hasAdminAccess() == false);
    assert(user->getWallet() == 1000);
    assert(user->getPhoneNumber() == "00945692356");
    assert(user->getAddress() == "Canada, Montral");

    std::cout << "User Entity Test#1 passed\n";
}

void userEntityTest2()
{
    EntityRepository<UserEntity>* repo = new EntityRepository<UserEntity>();
    UserEntity* user = repo->getById(0);

    assert(user->getId() == 0);
    assert(user->getName() == "Admin");
    assert(user->getPassword() == "admin");
    assert(user->hasAdminAccess() == true);
    assert(user->getWallet() == 0);
    assert(user->getPhoneNumber() == "");
    assert(user->getAddress() == "");

    std::cout << "User Entity Test#2 passed\n";
}

void hotelRoomEntityTest1()
{
    EntityRepository<HotelRoomEntity>* repo = new EntityRepository<HotelRoomEntity>();
    HotelRoomEntity* hotelRoomEntity = repo->getById(101);

    assert(hotelRoomEntity->getId() == 101);
    assert(hotelRoomEntity->getStatus() == 0);
    assert(hotelRoomEntity->getPrice() == 100);
    assert(hotelRoomEntity->getMaxCapacity() == 2);
    assert(hotelRoomEntity->getCapacity() == 2);
    assert(hotelRoomEntity->getAllUser().empty() == true);
    
    std::cout << "Hotel Room Entity Test#1 passed\n";
}

void hotelRoomEntityTest2()
{
    EntityRepository<HotelRoomEntity>* repo = new EntityRepository<HotelRoomEntity>();
    HotelRoomEntity* hotelRoomEntity = repo->getById(301);

    assert(hotelRoomEntity->getId() == 301);
    assert(hotelRoomEntity->getStatus() == 0);
    assert(hotelRoomEntity->getPrice() == 100);
    assert(hotelRoomEntity->getMaxCapacity() == 1);
    assert(hotelRoomEntity->getCapacity() == 0);
    assert(hotelRoomEntity->getAllUser().empty() == false);
    assert(hotelRoomEntity->getAllUser()[0]->userId == 2);
    assert(hotelRoomEntity->getAllUser()[0]->numOfBeds == 1);
    assert(hotelRoomEntity->getAllUser()[0]->reserveDate->toString() == "27-02-2023");
    assert(hotelRoomEntity->getAllUser()[0]->checkoutDate->toString() == "28-02-2023");
    assert(hotelRoomEntity->getAllUser()[1]->userId == 3);
    assert(hotelRoomEntity->getAllUser()[1]->numOfBeds == 1);
    assert(hotelRoomEntity->getAllUser()[1]->reserveDate->toString() == "25-02-2023");
    assert(hotelRoomEntity->getAllUser()[1]->checkoutDate->toString() == "26-02-2023");
    
    std::cout << "Hotel Room Entity Test#2 passed\n";
}

int main()
{
    userEntityTest1();
    userEntityTest2();

    hotelRoomEntityTest1();
    hotelRoomEntityTest2();

    return 0;
}