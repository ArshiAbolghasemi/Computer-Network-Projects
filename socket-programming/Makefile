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

user_entity_test: UserEntityTest

UserEntityTest: UserEntityTest.o UserEntity.o Entity.o SPJsonService.o JsonService.o DateTime.o
	$(CC) $(CPP_VERSION) UserEntityTest.o UserEntity.o Entity.o SPJsonService.o JsonService.o DateTime.o -o UserEntityTest.out

UserEntityTest.o : ./test/Entity/UserEntityTest.cpp ./src/Entity/UserEntity.hpp
	$(CC) $(CFLAGS) ./test/Entity/UserEntityTest.cpp -o UserEntityTest.o

UserEntity.o : ./src/Entity/UserEntity.cpp ./src/Entity/UserEntity.hpp
	$(CC) $(CFLAGS) ./src/Entity/UserEntity.cpp -o UserEntity.o

Entity.o: ./src/Entity/Entity.cpp ./src/Entity/Entity.hpp ./src/service/SPJsonService.hpp
	$(CC) $(CFLAGS) ./src/Entity/Entity.cpp -o Entity.o

SPJsonService.o: ./src/service/SPJsonService.cpp ./src/service/SPJsonService.hpp ./src/lib/HotelRoomUserInfo.hpp ../service/JsonService.hpp
	$(CC) $(CFLAGS) ./src/service/SPJsonService.cpp -o SPJsonService.o

JsonService.o: ../service/JsonService.cpp ../service/JsonService.hpp ../lib/json/json.hpp
	$(CC) $(CFLAGS) ../service/JsonService.cpp -o JsonService.o

DateTime.o: ./src/lib/DateTime.cpp ./src/lib/DateTime.hpp
	$(CC) $(CFLAGS) ./src/lib/DateTime.cpp -o DateTime.o

clean:
	rm -rf *.o UserEntityTest.out

