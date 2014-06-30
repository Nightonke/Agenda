#include "AgendaService.h"

AgendaService() {
    storage_ = Storage::getInstance();
}

~AgendaService() {
    if (storage_) {
        delete storage_;
    }
}

bool userLogIn(std::string userName, std::string password) {
    for (auto iter = storage->userList_.begin(); iter != storage->userList_.end(); iter++) {
        if (userName == iter->getName() && passWord == iter->getPassword()) {
            return true;
        }
    }
    return false;
}

bool userRegister(std::string userName, std::string password,
                  std::string email, std::string phone) {
    //judge the if it is valid
    storage->createUser(User(userName, password, email, phone));
    return true;  // if it is valid
}

bool deleteUser(std::string userName, std::string password) {
    int deletedMeeting = storage_->deleteMeeting(); // delete the meetings according the user(sponsor or paticipator)
    //std::cout << "There are " << deletedMeeting << " will be deleted, are you sure to go on?" << std::endl;
    int deletedUser = storage_->deleteUser(); // delete according to name
    if (deletedUser == 0) {
        return false;
    } else {
        return true;
}

std::list<User> listAllUsers(void) {
    for (auto iter = storage_->)
