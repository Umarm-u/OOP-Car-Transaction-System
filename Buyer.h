#pragma once
#ifndef BUYER_H
#define BUYER_H

#include "User.h"

class Buyer : public User {
public:
    Buyer(const string& name, const string& pword);

    void viewVehicles() const;
    void viewauction() const;
    void contactseller() const;
    void viewCat(const string& vehicleFile, const string& catName) const;

    void displayUserMenu() const override;
};

#endif // BUYER_H