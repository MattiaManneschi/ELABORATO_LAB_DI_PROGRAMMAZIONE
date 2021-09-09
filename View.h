//
// Created by mattia on 26/08/21.
//

#ifndef ELABORATO_LAB_DI_PROGRAMMAZIONE_VIEW_H
#define ELABORATO_LAB_DI_PROGRAMMAZIONE_VIEW_H

#include "Observer.h"
#include "Controller.h"
#include "User.h"

class View : public Observer {

public:

    explicit View(Controller *c, User *u) : controller(c), user(u) {
        controller->user->registerObserver(this);
        this->userAdded = true;
    };

    void createNewArticle(string answer1, string answer, int qty) {
        controller->createArticle(answer, qty, answer1);
    }

    void deleteOldArticle(string answer1, string answer) {
        controller->removeOldArticle(answer1, answer);
    }


    void update(string &name, bool oS, int a, bool lS, int x) override;

    void addNewListButton() {
        string answer;
        cout << "\nDIGITARE NOME NUOVA LISTA: ";
        cin >> answer;
        controller->createNewList(answer);
    }

    void removeListButton() {
        string answer;
        cout << "\nDIGITARE NOME LISTA DA RIMUOVERE: ";
        cin >> answer;
        controller->removeList(answer);
    }

    void addNewObjectButton();

    void removeOldObjectButton();

    ~View() override {
        controller->user->removeObserver(this);
    }


    bool isUserAdded() const {
        return userAdded;
    }

    void purchaseButton();

    void untickPurchaseButton();


protected:
    Controller *controller;
    User *user;
    bool userAdded = false;
};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_VIEW_H
