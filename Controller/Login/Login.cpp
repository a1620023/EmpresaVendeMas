//
// Created by eceledon on 5/10/2022.
//
#include <string>
using namespace std;


#define USER "Roberto"
#define PASS "123456"

class Login {
private:
    string user = USER;
    string pass = PASS;

public:
    Login(){}

    string getUser() {
        return user;
    }

    string getPassword() {
        return pass;
    }
};