#include "../../include/lib/EntityRepository.hpp"

template<class T>
T* EntityRepository<T>::getById(int id)
{
    return this->getByField<int>("id", id);
}

template class EntityRepository<UserEntity>;
template class EntityRepository<HotelRoomEntity>;