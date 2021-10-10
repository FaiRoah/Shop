#include <iostream>
#include "Product.h"
#include "Purchase.h"
#include "Check.h"

using namespace std;

void menu();    //show the menu
void showProdList(vector<Product>& product);    //show the list of products
void addToCheck(vector<Product>& product, vector<Purchase*>& check);//add 
//a new product to the check

int main() {
    cout << "Hello! " << endl << endl;
    int selection;  //a number from the menu
    vector<Product> products;  //vector of products
    products.push_back(Product("Apple", 59.99));
    products.push_back(Product("Banana", 62.99));
    products.push_back(Product("Orange", 39.99));
    products.push_back(Product("Lemon", 49.99));
    products.push_back(Product("Strawberry", 199.99));
    products.push_back(Product("Tomato", 60.99));
    products.push_back(Product("Cucumber", 43.99));
    products.push_back(Product("Salad", 49.99));
    products.push_back(Product("Avocado", 289.99));
    vector<Purchase*> check;    //check that is containg buyed products
    while (1) {
        menu();     //show the menu
        cout << endl << "Enter a number from the menu: ";
        cin >> selection;
        switch (selection)
        {
        case 1:     //Show the product list
            showProdList(products);
            break;
                
        case 2:     //Choose a product and its amount to buy
            addToCheck(products, check);
            break;
        case 3:     //Show the shopping list
        {
            try {
                if (check.size() == 0) {     //if the check is empty
                    throw "Check is empty! Nothing to show...";
                }
            }
            catch (const char* errMsg) {
                cout << errMsg << endl << endl;
            }

            for (int i = 0; i < check.size(); i++) {
                cout << i + 1 << ". ";
                check[i]->printInfo();
            }
            break;
        }
        case 0:     //Exit
            cout << "Exiting the program. Have a nice day!" << endl;
            return 0;
            break;

        default:
            cout << "You entered wrong. Enter one of the number on the list." << endl << endl;
            break;
        }
    }
    return 0;
}

void menu() {
    cout << "1. Show the product list" << endl;
    cout << "2. Choose a product and its amount to buy" << endl;
    cout << "3. Show the shopping list" << endl;
    cout << "0. Exit" << endl;
}

void showProdList(vector<Product>& product) {

    for (int i = 0; i < product.size(); i++) { //product.size means amount of products
        cout << i + 1 << " ";
        product[i].printInfo();

    }
    cout << endl;

}

void addToCheck(vector<Product>& product, vector<Purchase*>& check) {
    showProdList(product);

    string tempNumber;  //for checking if the number is appropriate
    char secondTempNumber;  //for checking if the number is appropriate
    int number;

    string tempAmount;  //for checking if the amount is appropriate
    char secondTempAmount;  //for checking if the amount is appropriate
    int amount;

    cout << "Enter the number of a product: ";
    cin >> tempNumber;

    try {
        if (tempNumber.size() > 1) {
            throw "Programs don't like when people try to break them! Enter an appropriate number.";
            cin.clear();
            
        }
        secondTempNumber = tempNumber[0];
        if (secondTempNumber < 49 || secondTempNumber > 57) {
            throw "Programs don't like when people try to break them! Enter an appropriate number.";
            cin.clear();
            
        }
    }
    catch (const char* errMsg) {
        cout << errMsg << endl << endl;
        return;
    }
    number = secondTempNumber - '0';


    cout << endl << "Enter amount of the product (assuming you won't need more than 10 at once): ";
    cin >> tempAmount;

    try {
        if (tempAmount.size() > 1) {
            throw "Programs don't like when people try to break them! Enter an appropriate amount.";
            cin.clear();

        }
        secondTempAmount = tempAmount[0];
        if (secondTempAmount < 49 || secondTempAmount > 57) {
            throw "Programs don't like when people try to break them! Enter an appropriate amount.";
            cin.clear();

        }
    }
    catch (const char* errMsg) {
        cout << errMsg << endl << endl;
        return;
    }
    amount = secondTempAmount - '0';

    cout << endl;
    Check* newProduct = new Check(product[number - 1].getName(), amount,
        product[number - 1].getPrice(), product[number - 1].getPrice() * amount);
    check.push_back(newProduct);
}