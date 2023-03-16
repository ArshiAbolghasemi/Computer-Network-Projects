ALL_PROJECT_LIB_DIR := ../lib
JSON_LIB_DIR := $(ALL_PROJECT_LIB_DIR)/json
ALL_PROJECT_SERVICE_DIR := ../service

SP_PROJECT_SOURCE_DIR := ./src
SP_PROJECT_TEST_DIR := ./test 
SP_PROJECT_TEST_ENTITY_DIR := $(SP_PROJECT_TEST_DIR)/Entity
SP_PROJECT_ENTITY_DIR := $(SP_PROJECT_SOURCE_DIR)/Entity
SP_PROJECT_LIB_DIR := $(SP_PROJECT_SOURCE_DIR)/lib
SP_PROJECT_SERVICE_DIR := $(SP_PROJECT_SOURCE_DIR)/service

CC := gcc
CPP := g++ 
CPP_VERSION := -std=c++11
CPPFALGS := $(CPP_VERSION) -c
CCFALGS := -c

entity_test: EntityTest

EntityTest: EntityRepository.o Entity.o UserEntity.o HotelRoomEntity.o EntityService.o SPJsonService.o DateTime.o EntityTest.o 
	$(CPP) $(CPP_VERSION) UserEntity.o Entity.o HotelRoomEntity.o EntityRepository.o EntityService.o DateTime.o SPJsonService.o EntityTest.o -o EntityTest.out

EntityTest.o: ./test/Entity/EntityTest.cpp ./include/lib/EntityRepository.hpp ./include/Entity/UserEntity.hpp ./include/Entity/HotelRoomEntity.hpp 
	$(CPP) $(CPPFALGS) -I ./include ./test/Entity/EntityTest.cpp -o EntityTest.o

UserEntity.o: ./src/Entity/UserEntity.cpp ./include/Entity/UserEntity.hpp ./include/Entity/Entity.hpp
	$(CPP) $(CPPFALGS) -I ./include ./src/Entity/UserEntity.cpp -o UserEntity.o

HotelRoomEntity.o: ./src/Entity/HotelRoomEntity.cpp ./include/Entity/HotelRoomEntity.hpp ./include/Entity/Entity.hpp ./include/lib/DateTime.hpp ./include/service/EntityService.hpp
	$(CPP) $(CPPFALGS) -I ./include ./src/Entity/HotelRoomEntity.cpp -o HotelRoomEntity.o

Entity.o: ./src/Entity/Entity.cpp ./include/Entity/Entity.hpp
	$(CPP) $(CPPFALGS) -I ./include ./src/Entity/Entity.cpp -o Entity.o

EntityRepository.o: ./src/lib/EntityRepository.cpp ./include/lib/EntityRepository.hpp ./include/Entity/UserEntity.hpp ./include/Entity/HotelRoomEntity.hpp ./include/service/SPJsonService.hpp
	$(CPP) $(CPPFALGS) -I ./include ./src/lib/EntityRepository.cpp -o EntityRepository.o

EntityService.o: ./src/service/EntityService.cpp ./include/service/EntityService.hpp ./include/lib/HotelRoomUserInfo.hpp ./include/lib/DateTime.hpp
	$(CPP) $(CPPFALGS)  -I ./include ./src/service/EntityService.cpp -o EntityService.o

SPJsonService.o: ./src/service/SPJsonService.cpp ./include/service/SPJsonService.hpp
	$(CPP) $(CPPFALGS)  -I ./include ./src/service/SPJsonService.cpp -o SPJsonService.o

DateTime.o: ./src/lib/DateTime.cpp ./include/lib/DateTime.hpp
	$(CPP) $(CPPFALGS) -I ./include ./src/lib/DateTime.cpp -o DateTime.o

LogService.o: ./src/service/LogService.c ./include/service/LogService.h
	$(CC) $(CCFALGS) -I ./include ./src/service/LogService.c -o LogService.o

SocketService.o: ./src/service/SocketService.c ./include/service/SocketService.h ./include/service/LogService.h
	$(CC) $(CCFALGS) -I ./include ./src/service/SocketService.c -o SocketService.o

clean:
	rm -rf *.o EntityTest.out