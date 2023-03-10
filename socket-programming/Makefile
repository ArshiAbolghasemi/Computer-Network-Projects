ALL_PROJECT_LIB_DIR := ../lib
JSON_LIB_DIR := $(ALL_PROJECT_LIB_DIR)/json
ALL_PROJECT_SERVICE_DIR := ../service

SP_PROJECT_SOURCE_DIR := ./src
SP_PROJECT_TEST_DIR := ./test 
SP_PROJECT_TEST_ENTITY_DIR := $(SP_PROJECT_TEST_DIR)/Entity
SP_PROJECT_ENTITY_DIR := $(SP_PROJECT_SOURCE_DIR)/Entity
SP_PROJECT_LIB_DIR := $(SP_PROJECT_SOURCE_DIR)/lib
SP_PROJECT_SERVICE_DIR := $(SP_PROJECT_SOURCE_DIR)/service

CC := g++ 
CPP_VERSION := -std=c++11
CFLAGS := $(CPP_VERSION) -c

entity_test: EntityTest

EntityTest: EntityRepository.o Entity.o UserEntity.o HotelRoomEntity.o EntityService.o SPJsonService.o JsonService.o DateTime.o EntityTest.o 
	$(CC) $(CPP_VERSION) UserEntity.o Entity.o HotelRoomEntity.o EntityRepository.o EntityService.o DateTime.o JsonService.o SPJsonService.o EntityTest.o -o EntityTest.out

EntityTest.o: ./test/Entity/EntityTest.cpp ./src/lib/Repository/EntityRepository.hpp ./src/Entity/UserEntity.hpp ./src/Entity/HotelRoomEntity.hpp
	$(CC) $(CFLAGS) ./test/Entity/EntityTest.cpp -o EntityTest.o

UserEntity.o: ./src/Entity/UserEntity.cpp ./src/Entity/UserEntity.hpp ./src/Entity/Entity.hpp ../lib/json/json.hpp
	$(CC) $(CFLAGS) ./src/Entity/UserEntity.cpp -o UserEntity.o

HotelRoomEntity.o: ./src/Entity/HotelRoomEntity.cpp ./src/Entity/HotelRoomEntity.hpp ./src/Entity/Entity.hpp ../lib/json/json.hpp ./src/lib/DateTime.hpp ./src/service/EntityService.hpp
	$(CC) $(CFLAGS) ./src/Entity/HotelRoomEntity.cpp -o HotelRoomEntity.o

Entity.o: ./src/Entity/Entity.cpp ./src/Entity/Entity.hpp
	$(CC) $(CFLAGS) ./src/Entity/Entity.cpp -o Entity.o

EntityRepository.o: ./src/lib/Repository/EntityRepository.cpp ./src/lib/Repository/EntityRepository.hpp ./src/Entity/UserEntity.hpp ./src/Entity/HotelRoomEntity.hpp ./src/service/SPJsonService.hpp ../lib/json/json.hpp ../service/JsonService.hpp
	$(CC) $(CFLAGS) ./src/lib/Repository/EntityRepository.cpp -o EntityRepository.o

EntityService.o: ./src/service/EntityService.cpp ./src/service/EntityService.cpp ./src/lib/HotelRoomUserInfo.hpp ../lib/json/json.hpp ./src/lib/DateTime.hpp
	$(CC) $(CFLAGS) ./src/service/EntityService.cpp -o EntityService.o

SPJsonService.o: ./src/service/SPJsonService.cpp ./src/service/SPJsonService.hpp ../service/JsonService.hpp ../lib/json/json.hpp
	$(CC) $(CFLAGS) ./src/service/SPJsonService.cpp -o SPJsonService.o

JsonService.o: ../service/JsonService.cpp ../service/JsonService.hpp ../lib/json/json.hpp
	$(CC) $(CFLAGS) ../service/JsonService.cpp -o JsonService.o

DateTime.o: ./src/lib/DateTime.cpp ./src/lib/DateTime.hpp
	$(CC) $(CFLAGS) ./src/lib/DateTime.cpp -o DateTime.o

clean:
	rm -rf *.o EntityTest.out