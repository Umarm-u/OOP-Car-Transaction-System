#include "User.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;


User::User(const string& name, const string& pword, const string& userR) : username(name), password(pword), userRole(userR) {}

string User::getUsername() const {
    return username;
}

string User::getPassword() const {
    return password;
}

string User::getRole() const {
    return userRole;
}

void User::setUsername(const string& name) {
    username = name;
}

void User::setPassword(const string& pword) {
    password = pword;
}

//void User::(const string& userR) {
  //  userRole = userR;
//}

bool User::registerUser()
{
    ofstream file("userinfo.txt", ios::app);  // Append kia takkay overwitting na ho jai jahan file end hui wahan sai hi start ho

    file << username << endl << password << endl << userRole << endl;
    file.close();
    return true;    //yai thora mai assume kar raha hoon kai hamesha hi write hoga isi lia false nahi dalla

}

bool User::login() {

    string iusername, ipassword, user, pass, userR; //idher different username(iusername) is lia likha kyun kai overload ho raha tha variable username or password
    cout << "enter username " << endl;
    cin >> iusername;
    cout << "enter password " << endl;
    cin >> ipassword;


    ifstream read("userinfo.txt");

    while (read >> user >> pass >> userR)
    {
        if (user == iusername && pass == ipassword)
        {
            userRole = userR;
            cout << "login successful" << endl;
            read.close();
            return true;
        }
    }


    cout << "invalid username and passwword" << endl;
    read.close();

    return false;

    /*ifstream read("userinfo.txt");

    getline(read, user);//idher getline use kar kai read kar lia file sai
    getline(read, pass);

    read.close();

    if (user == iusername && pass == ipassword)
    {
        cout << "logged in successsfully" << endl;
        return true;

    }
    else
    {
        return false;
    }*/
}