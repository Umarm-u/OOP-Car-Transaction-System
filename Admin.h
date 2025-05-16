#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User {
public:
    Admin(const string& name, const string& pword);

    void addvehicle() const;
    void removeVehicle(string filename, string vehiclename) const;

    void displayUserMenu() const override;
};

#endif // ADMIN_H