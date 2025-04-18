//
// Created by Miruna on 5/17/2024.
//

#include "UI.h"
#include "BancnoteValidator.h"
#include "EntityValidator.h"
#include <iostream>
#include <string>

UI::UI() = default;

UI::UI(Service &service1) {
    this -> service = service1;
}

UI::~UI() = default;

void UI::menu() {
    string role;
    cout << "Are you a user or an admin? ";
    cin >> role;
    if(role == "admin"){
        cout << "Enter security code: ";
        int password;
        cin >> password;
        if(password == 2604){
            adminMenu();
        }else {
            cout << "You don't have the right authorization to access this menu!:(";
        }
    }else if (role == "user"){
        userMenu();
    }

}

void UI::adminMenu() {
    bool isTrue = true;
    while (isTrue){
        cout << "~~~~~~*MENU*~~~~~~" << endl;
        cout << "1) Add a book" << endl;
        cout << "2) Delete a book" << endl;
        cout << "3) Update a book" << endl;
        cout << "4) Find a book by id" << endl;
        cout << "5) Show all books" << endl;
        cout << "6) Sort books by price" << endl;
        cout << "7) Generate the most expensive book in the store" << endl;
        cout << "8) Access user menu" << endl;
        cout << "0) Exit" << endl;
        int option;
        cout << "Choose an option: ";
        cin >> option;
        switch(option){
            case 1:
                add();
                break;
            case 2:
                remove();
                break;
            case 3:
                update();
                break;
            case 4:
                find();
                break;
            case 5:
                getAll();
                break;
            case 6:
                filterByPrice();
                break;
            case 7:
                topBook();
                break;
            case 8:
                userMenu();
            case 0:
                isTrue = false;
                break;
        }
    }

}

void UI::userMenu() {
    int opt = 1;
    cout << endl << "Hy and welcome to our dusty book shop!" << endl;
    vector<Book> commands;
    while(opt != 0){
        cout << "Take a look on what we have on our shelves: " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        getAll();
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << endl << "So, wanderer, what title caught your eye? (give me the id please): ";
        int id;
        cin >> id;
        int price = -1;
        vector<Book> entities = service.getAll();
        for(auto entity : entities){
            if (entity.getId() == id){
                price = entity.getPrice();
                commands.push_back(entity);
            }
        }
        if (price == -1){
            cout << "Invalid book id. Please give us a correct one!!" << endl;
            continue;
        }
        cout << "You'll owe us: " << price << " nickles" << endl;
        cout << "We accept payment in banknotes of 1, 5 or 10 nickles" << endl;
        cout << "Choose how you want to pay: ";
        int banknote;
        while(true) {
            cin >> banknote;
            BancnoteValidator val(1, 5, 10);
//        while(banknote != 1 && banknote != 5 && banknote != 10 ){
//            val.validate(banknote);
//            cin >> banknote;
//        }
            try {
                val.validate(banknote);
                break; // Ieșim din buclă dacă validarea a fost cu succes
            } catch (const std::exception &e) {
                cout << e.what() << " Please enter a valid banknote (1, 5, or 10 nickles): ";
            }
        }

        while (banknote < price){
            cout << "Knowledge is pricey, mate! Up the nickles!! ";
            int newBanknote;
            cin >> newBanknote;
            banknote += newBanknote;
        }
        int rest;
        rest = banknote - price;
//        while (price){
//            if (price >= 10){
//                service.updateBancnote(10, 10);
//                price -= 10;
//            }else if (price >= 5){
//                service.updateBancnote(5, 5);
//                price -= 1;
//            }
//        }
        cout << "You're all set! Your rest is: " << rest << " nickles!" << endl;
        cout << "Got another title on your mind? (Yes or No): ";
        string answer;
        cin >> answer;
        if(answer == "Yes")
            continue;
        else if(answer == "No")
            opt = 0;
        cout << "We'll have a gnome deliver your order! May we see you again, traveller!";
        cout << "Your commands were: ";
        for (int i = 0; i < commands.size(); i++)
            cout << commands[i].getTitle() << " , ";
        cout << endl;
        cout << "Good luck in your endeavours!" << endl;


    }

//    cout << "We'll have a gnome deliver your order! May we see you again, traveller!";
//    cout << "Your commands were: ";
//    for (int i = 0; i < commands.size(); i++)
//        cout << commands[i].getTitle() << " , ";
//    cout << endl;
//    cout << "Good luck in your endeavours!" << endl;


}

void UI::add() {
    try {
        int id;
        cout << "Enter id: ";
        cin >> id;
        string title;
        cout << "Enter book title: ";
        cin >> title;
        int price;
        cout << "Enter book price: ";
        cin >> price;
        int ok = false;
        vector<Book> entities = service.getAll();
        for (auto entity: entities) {
            if (entity.getId() == id) {
                ok = true;
            }
        }
        if (ok == false) {
            service.add(id, title, price);
        } else {
            EntityValidator val(service.size());
            val.validate(id);
        }
    }catch (InvalidCodeException &e){
        cout << "Exception: " << e.what() << endl;
    }catch (const std::exception &e){
        cout << "An unexpected error just occured: " << e.what() << endl;
    }

}

void UI::remove() {
    try {
    int id;
    bool ok = false;
    cout << "Enter id: ";
    cin >> id;
    cout << endl;
    vector <Book> entities = service.getAll();
    for (auto entity : entities){
        if (entity.getId() == id){
            ok = true;
            service.remove(entity.getId(), entity.getTitle(), entity.getPrice());
            break;
        }
    }
    if (!ok) {
        throw ElementNotFoundException("The product wasn't found!!");
    }
    }catch (ElementNotFoundException &e){
        cout << "Exception: " << e.what() << endl;
    } catch (const std::exception &e) {
        cout << "An unexpected error occured: " << e.what() << endl;
    }
}

void UI::update() {
    try {
        int id;
        bool ok = false;
        cout << "Enter the id: ";
        cin >> id;
        int newId;
        cout << "Enter new id: ";
        cin >> newId;
        string newTitle;
        cout << "Enter new title: ";
        cin >> newTitle;
        int newPrice;
        cout << "Enter new price: ";
        cin >> newPrice;
        cout << endl;
        vector<Book> entities = service.getAll();
        for (auto entity: entities) {
            if (entity.getId() == id) {
                ok = true;
                service.update(entity.getId(), entity.getTitle(), entity.getPrice(), newId, newTitle, newPrice);
            }
        }
        if (!ok) {
            throw ElementNotFoundException("The product wasn't found!!");
        }
    }catch (ElementNotFoundException &e) {
        cout << "Exception: " << e.what() << endl;
    }catch(std::invalid_argument &e){
        cout << "Invalid input: " << e.what() << endl;
    }catch (const std:: exception &e){
        cout << "An unexpected error occured: " << e.what() << endl;
    }
}

void UI::find() {
    try {
        int id;
        cout << "Enter book id: " << endl;
        cin >> id;
        bool ok = false;
        vector<Book> entities = service.getAll();
        for (auto entity: entities) {
            if (entity.getId() == id) {
                ok = true;
                cout << entity.getId() << " " << entity.getTitle() << " " << entity.getPrice() << endl;
            }
        }
        if (ok == false) {
            throw ElementNotFoundException("The book wasn't found!!");
        }
    }catch(ElementNotFoundException &e) {
        cout << "Exception: " << e.what() << endl;
    } catch (const std::invalid_argument &e) {
        cout << "Invalid input: " << e.what() << endl;
    } catch (const std::exception &e) {
        cout << "An unexpected error occurred: " << e.what() << endl;
    }


}

void UI::getAll() {
    vector<Book> entities = service.getAll();
    for (auto& entity : entities) {
        cout << entity.getId() << " " << entity.getTitle() << " " << entity.getPrice() << endl;
    }
}

void UI::filterByPrice() {
    vector<Book> sortEntities = service.filterByPrice();
    for (const auto& entity : sortEntities) {
        cout << entity << endl;
    }
}

void UI::topBook() {
    cout<<service.getTopBook()<<endl;

}






