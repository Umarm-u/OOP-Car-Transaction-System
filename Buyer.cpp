#include "Buyer.h"


using namespace std;

Buyer::Buyer(const string& name, const string& pword) : User(name, pword, "BUYER")
{}

void Buyer::displayUserMenu() const {
    cout << "Welcome to buyer menu:" << endl;
    cout << "1. View Vehicles" << endl;
    cout << "2. View Auction" << endl;
    cout << "3. Request inspection report" << endl;
    cout << "4. Conatct Seller" << endl;
    cout << "5. View Notifications" << endl;
    cout << "6. Add a comment" << endl;
    cout << "7. Logout" << endl;

    int selection;
    cout << "your choice: ";
    cin >> selection;

    switch (selection)
    {
    case 1:
    {
        viewVehicles();
        break;
    }
    case 2:
    {
        viewauction();
        break;
    }
    case 4:
    {
        contactseller();
        break;
    }
    case 7:
    {
        cout << "logging you out now" << endl;
        break;
    }
    default:
    {
        cout << "please enter a valid choice" << endl;
        break;
    }

    }

}

void Buyer::contactseller() const
{
    int cat;
    cout << "chose the category of which you need seller detail.   1:used cars     2:new cars     3:bikes" << endl;
    cin >> cat;



    if (cat == 1) {
        string carname;
        cout << "enter the car name of which you the Seller details" << endl;
        cin >> carname;

        ifstream file("usedcars.txt");

        string name, company, model, city, sellerN, engine, fuel, color;
        int year, price, rating, contact;
        double mileage;

        bool vehiclepresent = false;
        while (file >> name >> company >> model >> city >> sellerN >> engine >> fuel >> color >> year >> price >> rating >> contact >> mileage) {
            if (name == carname)
            {
                vehiclepresent = true;
                break;
            }

        }

        file.close();
        cout << "Seller info :" << endl;
        cout << "Seller name :" << sellerN << endl;
        cout << "Seller contact :" << contact << endl;
    }
    if (cat == 2) {
        string carname;
        cout << "enter the car name of which you the Seller details" << endl;
        cin >> carname;

        ifstream file("newcars.txt");

        string name, company, model, city, sellerN, engine, fuel, color;
        int year, price, rating, contact;
        double mileage;

        bool vehiclepresent = false;
        while (file >> name >> company >> model >> city >> sellerN >> engine >> fuel >> color >> year >> price >> rating >> contact >> mileage) {
            if (name == carname)
            {
                vehiclepresent = true;

            }
            break;
        }

        file.close();
        cout << "Seller info :" << endl;
        cout << "Seller name :" << sellerN << endl;
        cout << "Seller contact :" << contact << endl;
    }
    if (cat == 3) {
        string carname;
        cout << "enter the car name of which you the Seller details" << endl;
        cin >> carname;

        ifstream file("bikes.txt");

        string name, company, model, city, sellerN, engine, fuel, color;
        int year, price, rating, contact;
        double mileage;

        bool vehiclepresent = false;
        while (file >> name >> company >> model >> city >> sellerN >> engine >> fuel >> color >> year >> price >> rating >> contact >> mileage) {
            if (name == carname)
            {
                vehiclepresent = true;

            }
            break;
        }

        file.close();
        cout << "Seller info :" << endl;
        cout << "Seller name :" << sellerN << endl;
        cout << "Seller contact :" << contact << endl;
    }
}

void Buyer::viewauction() const
{
    cout << "Below are all the categories of vehicles available" << endl << endl;
    cout << "****The new cars ****" << endl;
    viewCat("newcars.txt", "New Cars");
    cout << endl;
    cout << "****The used cars ****" << endl;
    viewCat("usedcars.txt", "Used Cars");
    cout << endl;
    cout << "****The bikes ****" << endl;
    viewCat("bikes.txt", "Bikes");

}

void Buyer::viewVehicles() const
{
    cout << "you chose to view vehicles. Below are the types of vehicles: " << endl << endl;
    cout << "1. New Cars" << endl;
    cout << "2. Used Cars" << endl;
    cout << "3. Bikes" << endl;

    int vehicle;
    cout << "enter the type of vehicle to view (1,2,3): ";
    cin >> vehicle;

    if (vehicle == 1)
    {
        viewCat("newcars.txt", "New Cars");
    }

    else if (vehicle == 2)
    {
        viewCat("usedcars.txt", "Used Cars");

    }

    else if (vehicle == 3)
    {
        viewCat("bikes.txt", "Bikes");
    }

    else
    {
        cout << "invalid choice" << endl;
    }
}

void Buyer::viewCat(const string& vehicleFile, const string& catName) const
{
    ifstream vehicle(vehicleFile);

    if (!vehicle.is_open()) {
        cout << "Error opening file: " << vehicleFile << endl;
        return;
    }

    string name, company, model, city, sellerN, engine, fuel, color;
    int year, price, rating, contact;
    double mileage;


    cout << "List of " << catName << " : " << endl << endl;

    while (vehicle >> name >> company >> model >> city >> sellerN >> engine >> fuel >> color >> year >> price >> rating >> contact >> mileage)
    {
        cout << "Name: " << name << "\tCompany: " << company << "\tModel: " << model << "\tCity: " << city << "\tSeller Name: " << sellerN
            << "\tEngine: " << engine << endl;
        cout << "Fuel: " << fuel << "\tColor: " << color << "\tYear: " << year << "\tPrice: " << price << "\tRating: " << rating << "\tContact: " << contact << "\tMileage: " << mileage << endl;

        cout << endl;
    }

    vehicle.close();
    //system("cls");


}