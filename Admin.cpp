#include "Admin.h"
#include<sstream>

using namespace std;

Admin::Admin(const string& name, const string& pword) : User(name, pword, "ADMIN")
{}

void Admin::displayUserMenu() const {
    cout << "Welcome to admin menu:" << endl;
    cout << "1. Add Vehicles" << endl;
    cout << "2. Remove Vehicles" << endl;
    cout << "3. Manage inspection requests" << endl;
    cout << "4. Add Notification" << endl;
    cout << "5. Remove Notification" << endl;
    cout << "6. Rate a vehicle" << endl;
    cout << "7. Logout" << endl;
    int selection;
    cout << "your choice: ";
    cin >> selection;

    switch (selection)
    {
    case 1:
    {

        addvehicle();
        break;
    }
    case 2:
    {
        cout << "Choose the category to remove vehicle" << endl;
        cout << "1: Used cars" << endl << "2: New cars" << endl << "3: Bikes" << endl;
        int choose;
        cin >> choose;

        cout << "enter the car name to remove" << endl;
        string carname;
        cin >> carname;

        if (choose == 1) {
            removeVehicle("usedcars.txt", carname);
            break;
        }
        else if (choose == 2) {
            removeVehicle("newcars.txt", carname);
            break;
        }
        else if (choose == 3) {
            removeVehicle("bikes.txt", carname);
            break;
        }

    }

    }
}


void Admin::addvehicle() const
{
    cout << "what category you want to add?" << endl;
    cout << "1: For used car." << endl << "2: For New car." << endl << "3: For bikes" << endl;
    int category;

    cout << "enter the category you want to add (1,2,3)" << endl;
    cin >> category;
    if (category == 1)
    {
        string name, company, model, city, sellerN, engine, fuel, color;
        int year, price, rating, contact;
        double mileage;
        cout << "enter the info of the car you want to add" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Company: ";
        cin >> company;
        cout << "Model: ";
        cin >> model;
        cout << "City: ";
        cin >> city;
        cout << "Seller Name: ";
        cin >> sellerN;
        cout << "Engine: ";
        cin >> engine;
        cout << "Fuel: ";
        cin >> fuel;
        cout << "Color: ";
        cin >> color;
        cout << "Year: ";
        cin >> year;
        cout << "Price: ";
        cin >> price;
        cout << "Rating: ";
        cin >> rating;
        cout << "Contact: ";
        cin >> contact;
        cout << "Mileage: ";
        cin >> mileage;


        ofstream file;
        file.open("usedcars.txt", ios::app);  // Append kia takkay overwitting na ho jai jahan file end hui wahan sai hi start ho
        if (file.is_open())
        {
            file << name << '\t' << company << '\t' << model << '\t' << city << '\t' << sellerN << '\t' << engine << '\t'
                << fuel << '\t' << color << '\t' << year << '\t' << price << '\t' << rating << '\t' << contact << '\t' << mileage << '\t' << endl;

            file.close();
            cout << "vehicle addes" << endl;
        }
    }
    else if (category == 2)
    {
        string name, company, model, city, sellerN, engine, fuel, color;
        int year, price, rating, contact;
        double mileage;
        cout << "enter the info of the car you want to add" << endl;

        cout << "Name: ";
        cin >> name;
        cout << "Company: ";
        cin >> company;
        cout << "Model: ";
        cin >> model;
        cout << "City: ";
        cin >> city;
        cout << "Seller Name: ";
        cin >> sellerN;
        cout << "Engine: ";
        cin >> engine;
        cout << "Fuel: ";
        cin >> fuel;
        cout << "Color: ";
        cin >> color;
        cout << "Year: ";
        cin >> year;
        cout << "Price: ";
        cin >> price;
        cout << "Rating: ";
        cin >> rating;
        cout << "Contact: ";
        cin >> contact;
        cout << "Mileage: ";
        cin >> mileage;


        ofstream file;
        file.open("newcars.txt", ios::app);  // Append kia takkay overwitting na ho jai jahan file end hui wahan sai hi start ho
        if (file.is_open())
        {
            file << name << '\t' << company << '\t' << model << '\t' << city << '\t' << sellerN << '\t' << engine << '\t'
                << fuel << '\t' << color << '\t' << year << '\t' << price << '\t' << rating << '\t' << contact << '\t' << mileage << '\t' << endl;

            file.close();
            cout << "vehicle addes" << endl;
        }

    }
    else if (category == 3)
    {
        string name, company, model, city, sellerN, engine, fuel, color;
        int year, price, rating, contact;
        double mileage;
        cout << "enter the info of the car you want to add" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Company: ";
        cin >> company;
        cout << "Model: ";
        cin >> model;
        cout << "City: ";
        cin >> city;
        cout << "Seller Name: ";
        cin >> sellerN;
        cout << "Engine: ";
        cin >> engine;
        cout << "Fuel: ";
        cin >> fuel;
        cout << "Color: ";
        cin >> color;
        cout << "Year: ";
        cin >> year;
        cout << "Price: ";
        cin >> price;
        cout << "Rating: ";
        cin >> rating;
        cout << "Contact: ";
        cin >> contact;
        cout << "Mileage: ";
        cin >> mileage;


        ofstream file;
        file.open("bikes.txt", ios::app);  // Append kia takkay overwitting na ho jai jahan file end hui wahan sai hi start ho
        if (file.is_open())
        {
            file << name << '\t' << company << '\t' << model << '\t' << city << '\t' << sellerN << '\t' << engine << '\t'
                << fuel << '\t' << color << '\t' << year << '\t' << price << '\t' << rating << '\t' << contact << '\t' << mileage << '\t' << endl;

            file.close();
            cout << "vehicle addes" << endl;
        }

    }
    else
    {
        cout << "invalid choice" << endl;
    }
    displayUserMenu();

}

void Admin::removeVehicle(string filename, string vehiclename) const
{

    fstream file;
    string line;
    bool vehiclefound = false;

    file.open(filename, ios::in);

    if (file.is_open())
    {
        //temp file
        ofstream tempFile("temp.txt");

        while (getline(file, line))
        {
            stringstream s(line);
            string currentVehicleName;
            s >> currentVehicleName; // first word read

            if (currentVehicleName == vehiclename)
            {
                vehiclefound = true;
            }

            else
            {
                tempFile << line << endl; // Write the line to the temporary file
            }
        }

        file.close();
        tempFile.close();

        // Remove the old file and rename the temporary file
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
    }

    if (vehiclefound) {
        cout << "Vehicle removed successfully." << endl;
    }
    else {
        cout << "Vehicle not found." << endl;
    }

    displayUserMenu();
}