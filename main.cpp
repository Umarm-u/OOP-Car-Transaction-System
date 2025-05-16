#include "User.h"
#include "Buyer.h"
#include "Seller.h"
#include "Admin.h"

int main() {
    int choice;

    cout << "option selection:" << endl << "1:register" << endl << "2:login" << endl;
    cin >> choice;

    User* loggedInUser = nullptr;

    if (choice == 1) {
        string username, password, userRole;
        cout << "Select a username: ";
        cin >> username;
        cout << "Select a password: ";
        cin >> password;
        cout << "Enter user role (BUYER, SELLER, ADMIN): ";
        cin >> userRole;

        if (userRole == "BUYER" || userRole == "buyer")
        {
            loggedInUser = new Buyer(username, password);
        }

        else if (userRole == "SELLER" || userRole == "seller")
        {
            loggedInUser = new Seller(username, password);
        }

        else if (userRole == "ADMIN" || userRole == "admin")
        {
            loggedInUser = new Admin(username, password);
        }

        else
        {
            cout << "please enter a valid role" << endl;
        }

        loggedInUser->setUsername(username);
        loggedInUser->setPassword(password);

        if (loggedInUser->registerUser()) {
            cout << "registeration successful" << endl;

            //loggedInUser->displayUserMenu();

            if (loggedInUser->login()) {
                cout << "login successful" << endl;
                loggedInUser->displayUserMenu();

            }

            else {
                cout << "login failed" << endl;
                delete loggedInUser;
                return 1;
            }
        }
        else {
            cout << "registeration failed" << endl;
            delete loggedInUser;
            return 1;
        }
    }

    else if (choice == 2) {
        string username, password, userRole;
        /*loggedInUser = new User; */
        cout << "Enter user role (BUYER, SELLER, ADMIN): ";
        cin >> userRole;
        if (loggedInUser->login()) {
            cout << "login successful" << endl;
            if (userRole == "BUYER" || userRole == "buyer")
            {
                loggedInUser = new Buyer(username, password);
            }

            else if (userRole == "SELLER" || userRole == "seller")
            {
                loggedInUser = new Seller(username, password);
            }

            else if (userRole == "ADMIN" || userRole == "admin")
            {
                loggedInUser = new Admin(username, password);
            }

            else
            {
                cout << "please enter a valid role" << endl;
            }

        }
        else if (!loggedInUser->login()) {
            cout << "login failed" << endl;
            delete loggedInUser;
            return 1;
        }
    }

    loggedInUser->displayUserMenu();
    loggedInUser = NULL;
    delete loggedInUser;


    return 0;
}