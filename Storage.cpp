#include "Storage.h"
#include <fstream>
#include <iostream>

char fpath[] = "/home/13331091/Desktop/testForAgenda";  // for test

Storage * Storage::instance_ = NULL;

//DISALLOW_COPY_AND_ASSIGN(Storage) {}

Storage::Storage() {
    bool successfullRead = readFromFile(fpath);
    if (!successfullRead) {
        // exception
    }
}

bool Storage::readFromFile(const char *fpath) {
    std::fstream inFile;
    inFile.open(fpath);
    //read from the 2 lists
    inFile.close();
    if (1)  // the original thought is to check read successfully or not by checking a specil word
        return false;
    else
        return true;
}

bool Storage::writeToFile(const char *fpath) {
    //write in the files
}

Storage * Storage::getInstance(void) {
    if (instance_ == NULL) {
        instance_ = new Storage();
    }
    return instance_;
}

Storage::~Storage() {
    bool successfullyWrite = writeToFile(fpath);
	if (successfullyWrite) {
		std::cout << "Save successfully!" << std::endl;
	} else {
		std::cout << "Save fail!" << std::endl;
	}
}

void Storage::createUser(const User & newUser) {
    userList_.push_back(newUser);
}

std::list<User> Storage::queryUser(std::function<bool(const User&)> filter) {
    std::list<User> foundUser;
    for (auto iter = userList_.begin(); iter != userList_.end(); iter++) {
        if (filter(*iter)) {
            foundUser.push_back(*iter);
        }
    }
    return foundUser;
}

int Storage::updateUser(std::function<bool(const User&)> filter, std::function<void(User&)> switcher) {
    int counter = 0;
    for (auto iter = userList_.begin(); iter != userList_.end(); iter++) {
        if (filter(*iter)) {
            switcher(*iter);
            counter++;
        }
    }
    return counter;
}

int Storage::deleteUser(std::function<bool(const User&)> filter) {
    int counter = 0;
    for (auto iter = userList_.begin(); iter != userList_.end(); iter++) {
        if (filter(*iter)) {
            userList_.erase(iter);
            counter++;
        }
    }
    return counter;
}

void Storage::createMeeting(const Meeting & newMeeting) {
    meetingList_.push_back(newMeeting);
}

std::list<Meeting> Storage::queryMeeting(std::function<bool(const Meeting&)> filter) {
    std::list<Meeting> foundMeeting;
    for (auto iter = meetingList_.begin(); iter != meetingList_.end(); iter++) {
        if (filter(*iter)) {
            foundMeeting.push_back(*iter);
        }
    }
    return foundMeeting;
}

int Storage::updateMeeting(std::function<bool(const Meeting&)> filter, std::function<void(Meeting&)> switcher) {
    int counter = 0;
    for (auto iter = meetingList_.begin(); iter != meetingList_.end(); iter++) {
        if (filter(*iter)) {
            switcher(*iter);
            counter++;
        }
    }
    return counter;
}

int Storage::deleteMeeting(std::function<bool(const Meeting&)> filter) {
    int counter = 0;
    for (auto iter = meetingList_.begin(); iter != meetingList_.end(); iter++) {
        if (filter(*iter)) {
            meetingList_.erase(iter);
            counter++;
        }
    }
    return counter;
}

bool Storage::sync(void) {
    return writeToFile(fpath);
}


