#pragma once
#ifndef SELLER_H
#define SELLER_H

#include "User.h"

class Seller : public User {
public:
    Seller(const string& name, const string& pword);

    void viewVehicles() const;
    void addvehicle() const;
    void removeVehicle(string filename, string vehiclename) const;

    void displayUserMenu() const override;

private:
    void viewCat(const string& vehicleFile, const string& catName) const;
};

#endif // SELLER_H