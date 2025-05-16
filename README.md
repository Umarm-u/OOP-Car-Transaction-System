# OOP-Car-Transaction-System 🚗

## Overview
This is a C++ Object-Oriented Programming project developed as a semester project for CS-1004 at FAST-NUCES. The system simulates a vehicle transaction portal with modules for **Buyers**, **Sellers**, and **Admins**. It supports secure authentication, vehicle auctions, maintenance tracking, and document management using file handling and OOP principles.

---

## Features

### 👤 Buyer Module
- Register/Login
- View vehicles (New, Used, Bikes)
- Sort/filter vehicles
- Contact seller
- View auctions
- Request inspection reports
- View notifications

### 🧑‍💼 Seller Module
- Register/Login
- Add/remove vehicles
- Register vehicles for auction
- View notifications

### 👨‍🔧 Admin Module
- Login
- Add/remove vehicles
- Handle inspection requests
- Add/remove notifications
- Rate vehicles

---

## File Structure

| File | Description |
|------|-------------|
| `main.cpp` | Driver program |
| `admin.cpp`, `admin.h` | Admin class |
| `buyer.cpp`, `buyer.h` | Buyer class |
| `seller.cpp`, `seller.h` | Seller class |
| `user.cpp`, `user.h` | Base user class |
| `usedcars.txt` | Used car data |
| `newcars.txt` | New car data |
| `bikes.txt` | Bike data |
| `userinfo.txt` | User authentication data |

---

## Concepts Implemented
- OOP Principles (Encapsulation, Inheritance, Polymorphism)
- File Handling in C++
- Operator Overloading
- Secure Authentication
- Menu-Driven Interface
- Dynamic Memory Allocation
- Polymorphism via Virtual Functions

---

## Setup and Run

```bash
g++ main.cpp admin.cpp buyer.cpp seller.cpp user.cpp -o program
./program
