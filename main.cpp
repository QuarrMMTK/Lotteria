#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

/*
 * Author: Min Myat Thu Kha
 * Created on: 22/10/2024
 */

// Function to display the main menu
void displayMenu(string menuItems[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(2) << i+1 << ". " << menuItems[i] << endl;
    }
    cout << " 0. Exit Menu" << endl;
}

// Function to display the related menu items with prices, aligned for better readability
void displayRelatedMenu(string menuItems[], double price[], int size) {
    cout << left << setw(3) << "No" << setw(30) << "Item" << setw(10) << "Price" << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << setw(3) << i+1 << setw(30) << menuItems[i] << setw(10) << price[i] << endl;
    }
    cout << " 0. Exit Menu!" << endl;
}

// Function to display the bill voucher with cart items and total price
void voucher(string cartItems[], double cartPrice[], int cartSize) {
    cout << "\n------------ Bill Voucher ------------" << endl;
    double total = 0;
    cout << left << setw(3) << "No" << setw(30) << "Item" << setw(10) << "Price" << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = 0; i < cartSize; i++) {
        cout << setw(3) << i+1 << setw(30) << cartItems[i] << setw(10) << cartPrice[i] << endl;
        total += cartPrice[i];
    }
    cout << "-----------------------------------------------" << endl;
    cout << setw(33) << "Total Price: " << total << endl;
    cout << "Thanks for using Lotteria!" << endl;
}


int main() {

    cout << "Welcome to Lotteria!" << endl;

    string menuItems[] = {"Fried Chicken", "Burger", "Burger Set", "Rice", "Potato","Drink", "Coffee", "Dessert"};
    int menuItemsSize = std::size(menuItems);

    string friedChickenMenu[] = {"Fried Chicken", "Super Hot Chicken", "Mini Mala Chicken", " Mini Honey Chicken", "Fried Chicken(Half Pack)", "Fried Chicken(Full Pack)", "Korea Chicken(Half Pack)", "Korea Chicken(Full Pack)", "Cheesy Chicken(Half Pack)", "Cheesy Chicken(Full Pack)", "Crispy Shake Shake Chicken(Onion)", "Crispy Shake Shake Chicken(Chilli)", "Crispy Shake Shake Chicken(Cheese)", "Mini Tar Tar Chicken"};
    double friedChickenPrice[] = {3400, 5200, 5100, 5200, 13500, 30300, 5300, 10200, 5100, 9300, 5100, 5100, 5100, 5100};
    int friedChickenMenuSize = std::size(friedChickenMenu);

    string burgerMenu[] = {"Tender grilled Chicken Burger(Single)", "Thousand Chicken Burger", "Chicken Burger", "Chicken Gangjung Burger", "Hot Crispy Chicken Burger", "BBQ Pork Burger", "Crazy Hot Burger Single", "Rib Sand Burger", "Teri Burger", "Bulgogi Burger", "Cheese Burger", "Shrimp Burger", "Spicy Burger", "Teriyaki Chicken Burger"};
    double burgerPrice[] = {5800, 6300, 6900, 6900, 8200, 6900, 6900, 7400, 7700, 7700, 7900, 8200, 6700, 6300};
    int burgerMenuSize = std::size(burgerMenu);

    string burgerSetMenu[] = {"Tender grilled Chicken Burger(Set)", "Thousand Chicken Burger Set", "Teriyaki Chicken Burger Set", "Teriyaki Chicken Burger Set", "Chicken Burger(Set)", "Chicken Gangjung Burger(Set)", "Hot Crispy Chicken Burger(Set)", "BBQ Pork Burger(Set)","Crazy Hot Burger Single(Set)", "Rib Sand Burger(Set)", "Teri Burger(Set)", "Bulgogi Burger(Set)", "Cheese Burger(Set)", "Shrimp Burger(Set)", "Spicy Burger(Set)"};
    double burgerSetPrice[] = {10200, 10700, 10700, 11300, 11300, 12600, 11300, 11300, 11800, 12100, 12100, 12300, 12600, 11100, 12000};
    int burgerSetMenuSize = std::size(burgerSetMenu);

    string riceMenu[] = {"Korea Chicken Rice", "Mala Chicken Rice", "Honey Chicken Rice", "Chicken Rice"};
    double ricePrice[] = {6600, 6600, 6600, 6800};
    int riceMenuSize = std::size(riceMenu);

    string potatoMenu[] = {"French Fries", "Cheesy Fries", "Curly Fries", "Seasoning Fries"};
    double potatoPrice[] = {2700, 4000, 3200, 4100};
    int potatoMenuSize = std::size(potatoMenu);

    string drinkMenu[] = {"Plum Plum Juice", "Thai Milk Tea", "Fruit Punch", "Pepsi", "Orange Juice", "Ice Lemon Tea", "Milo", "Banana Milk", "Raspberry Cooler", "Lemon Mint", "Water", "Aloe Vera", "7 Up 16Oz"};
    double drinkPrice[] = {2900, 2800, 2200, 2200, 3100, 2700, 2900, 2900, 2900, 2900, 1200, 2900, 2700};
    int drinkMenuSize = std::size(drinkMenu);

    string coffeeMenu[] = {"Green Tea Latte", "Americano", "Caffe Latte", "Cappuccino", "Iced Coffee"};
    double coffeePrice[] = {5100, 3900, 4400, 4400, 2700};
    int coffeeMenuSize = std::size(coffeeMenu);

    string dessertMenu[] = {"Chicken Strip", "Natural Cheese Stick", "Crunch Shrimp", "Squid Ring", "Chicken Nugget", "Hot Sauce"};
    double dessertPrice[] = {5500, 4200, 5200, 5000, 4700, 1600};
    int dessertMenuSize = std::size(dessertMenu);

    string cartItems[100];
    double cartPrice[100];
    int cartSize = 0;


    bool exit = true;

    while (exit) {
        int choice;
        int mealChoice;

        displayMenu(menuItems, menuItemsSize);
        cin>>choice;

        switch(choice) {
            case 1:
                displayRelatedMenu(friedChickenMenu, friedChickenPrice, friedChickenMenuSize);
            cin>>mealChoice;
            if(mealChoice != 0) {
                --mealChoice;
                cartItems[cartSize] = friedChickenMenu[mealChoice];
                cartPrice[cartSize] = friedChickenPrice[mealChoice];
                cartSize++;
                break;
            }
            break;

            case 2:
                displayRelatedMenu(burgerMenu, burgerPrice, burgerMenuSize);
            cin>>mealChoice;
            if(mealChoice != 0) {
                --mealChoice;
                cartItems[cartSize] = burgerMenu[mealChoice];
                cartPrice[cartSize] = burgerPrice[mealChoice];
                cartSize++;
                break;
            }
            break;

            case 3:
                displayRelatedMenu(burgerSetMenu, burgerSetPrice, burgerSetMenuSize);
            cin>>mealChoice;
            if(mealChoice != 0) {
                --mealChoice;
                cartItems[cartSize] = burgerSetMenu[mealChoice];
                cartPrice[cartSize] = burgerSetPrice[mealChoice];
                cartSize++;
                break;
            }
            break;

            case 4:
                displayRelatedMenu(riceMenu, ricePrice, riceMenuSize);
            cin>>mealChoice;
            if(mealChoice != 0) {
                --mealChoice;
                cartItems[cartSize] = riceMenu[mealChoice];
                cartPrice[cartSize] = ricePrice[mealChoice];
                cartSize++;
                break;
            }
            break;

            case 5:
                displayRelatedMenu(potatoMenu, potatoPrice, potatoMenuSize);
            cin>>mealChoice;
            if(mealChoice != 0) {
                --mealChoice;
                cartItems[cartSize] = potatoMenu[mealChoice];
                cartPrice[cartSize] = potatoPrice[mealChoice];
                cartSize++;
                break;
            }
            break;

            case 6:
                displayRelatedMenu(drinkMenu, drinkPrice, drinkMenuSize);
            cin>>mealChoice;
            if(mealChoice != 0) {
                --mealChoice;
                cartItems[cartSize] = drinkMenu[mealChoice];
                cartPrice[cartSize] = drinkPrice[mealChoice];
                cartSize++;
                break;
            }
            break;

            case 7:
                displayRelatedMenu(coffeeMenu, coffeePrice, coffeeMenuSize);
            cin>>mealChoice;
            if(mealChoice != 0) {
                --mealChoice;
                cartItems[cartSize] = coffeeMenu[mealChoice];
                cartPrice[cartSize] = coffeePrice[mealChoice];
                cartSize++;
                break;
            }
            break;

            case 8:
                displayRelatedMenu(dessertMenu, dessertPrice, dessertMenuSize);
            cin>>mealChoice;
            if(mealChoice != 0) {
                --mealChoice;
                cartItems[cartSize] = dessertMenu[mealChoice];
                cartPrice[cartSize] = dessertPrice[mealChoice];
                cartSize++;
                break;
            }
            break;

            case 0:
                exit = false;
            break;

            default: cout << "Only Number Inputs Can Accept" << endl;
        }
    }
    voucher(cartItems, cartPrice, cartSize);
    return 0;
}
