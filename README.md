# 🚗 Vehicle Marketplace

A console-based **Vehicle Marketplace** (buy and sell vehicles, inspired by PakWheels) developed in **C** for the Programming Fundamentals project at **National University of Computer & Emerging Sciences (FAST-NUCES)**.

Sellers can post vehicles for sale, and buyers can browse, filter, and contact sellers directly using the phone number shown on the ad.

## 📌 Project Overview

The Vehicle Marketplace allows users to buy and sell vehicles through a simple console-based interface.

It provides functionality for:

- Posting a vehicle for sale
- Editing and deleting ads
- Marking a vehicle as sold
- Browsing all vehicles for sale
- Searching and filtering vehicles
- Viewing full vehicle details with seller contact information
- Permanently storing ads using files

## ❗ Problem Statement

Buying and selling vehicles through word of mouth, notice boards, or scattered messages can lead to:

- Difficulty finding vehicles that match a budget or city
- No central place to compare available vehicles
- Outdated listings of vehicles that are already sold
- Difficulty contacting the right seller
- Increased time and effort for both buyers and sellers

This project provides a computerized marketplace where sellers can list vehicles and buyers can search them quickly.

## 💡 Proposed Solution

The system works like a small online classifieds website in the console. Sellers post ads with complete vehicle details, and buyers browse or filter those ads and contact the seller by phone. Ads that are sold are automatically hidden from browse and search.

## ✨ Features

### Seller Side (CRUD)
- **Create:** Post a vehicle for sale (brand, model, year, price, kilometers, fuel, transmission, city, description)
- **Read:** View all of my ads
- **Update:** Edit price, kilometers, city, and description
- **Delete:** Remove an ad (with confirmation)
- Mark a vehicle as **Sold**
- Seller verifies ownership with the phone number used on the ad

### Buyer Side
- Browse all vehicles currently for sale
- Search and filter by:
  - Brand or model (case-insensitive, partial match)
  - City
  - Maximum price
  - Minimum year
- View full vehicle details
- See seller name and phone number to make contact

### Input Validation
- Numbers are checked against valid ranges (year, price, kilometers)
- Letters typed in place of numbers do not crash the program
- Required text fields cannot be left empty
- Fuel type and transmission are chosen from fixed menus

### File Handling
- Store ads permanently in a binary file (`ads.dat`)
- Load previously saved ads when the program starts
- Ad IDs are generated automatically

## 🗂️ Project Structure

| File | Purpose |
|---|---|
| `vehicle.h` | `Ad` structure, constants, and function prototypes |
| `main.c` | Main menu and program flow |
| `vehicle_crud.c` | Seller functions (post, view, edit, delete, mark sold) and buyer functions (browse, search, view details) |
| `file_handler.c` | Loading and saving ads to the file |
| `utils.c` | Safe input helpers, text search helper, fuel and transmission menus, table printing |

## ▶️ How to Compile and Run

```bash
gcc main.c vehicle_crud.c file_handler.c utils.c -o marketplace
./marketplace
```

On Windows (PowerShell or Command Prompt):

```bash
gcc main.c vehicle_crud.c file_handler.c utils.c -o marketplace.exe
marketplace.exe
```

## 🧭 Menu Overview

```
--- Buy ---
[1] Browse vehicles for sale
[2] Search / filter vehicles
--- Sell ---
[3] Post a vehicle for sale
[4] My ads
[5] Edit my ad
[6] Delete my ad
[7] Mark my ad as sold
[0] Exit
```

## ⚠️ Limitations

- There are no user accounts. Sellers prove ownership by typing the phone number used when posting the ad, which is not secure and is suitable only for a learning project.
- Maximum of 200 ads can be stored.
- Data is stored in a binary file, so it cannot be opened in a text editor. Delete `ads.dat` if the `Ad` structure is changed.

## 🚀 Future Improvements

- User registration and login with passwords
- Admin panel to remove fake ads and view statistics
- Favorites list for buyers
- Price offers from buyers to sellers
- Sorting results by price or year

## 🛠️ Technologies Used

| Technology | Usage |
|---|---|
| **C** | Programming Language |
| **Visual Studio Code** | IDE / Code Editor |
| **GCC** | Compiler |
| **Windows** | Operating System |
| **Console** | User Interface |
| **File Handling** | Permanent Data Storage |