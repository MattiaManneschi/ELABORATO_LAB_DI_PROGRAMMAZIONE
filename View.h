//
// Created by mattia on 26/08/21.
//

#ifndef ELABORATO_LAB_DI_PROGRAMMAZIONE_VIEW_H
#define ELABORATO_LAB_DI_PROGRAMMAZIONE_VIEW_H

#include "Observer.h"
#include "Controller.h"
#include "User.h"
#include <unistd.h>

class View : public Observer {

public:

    explicit View(Controller *c, User *u) : controller(c), user(u) {
        controller->user->registerObserver(this);
    };

    void createNewArticle(string answer1, string answer, int qty) {
        controller->createArticle(answer, qty, answer1);
    }

    void deleteOldArticle(string answer1, string answer) {
        controller->removeOldArticle(answer1, answer);
    }


    void update(string &name, bool oS, int a) override {
        if (oS) {
            cout << "\nL'ARTICOLO " << name << " È STATO AGGIUNTO CORRETTAMENTE. ";
        } else {
            cout << "\nL'ARTICOLO " << name << " È STATO RIMOSSO CORRETTAMENTE.";
        }
        label1:
        cout << "\nIL NUMERO TOTALE DI ARTICOLI DELLA LISTA SELEZIONATA È: " << a << endl;
    }

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


    void addNewObjectButton() {
        string answer, answer1;
        cout << "\nINSERIRE NOME LISTA DESTINAZIONE: ";
        cin >> answer1;
        cout << "INSERIRE NOME NUOVO ARTICOLO: ";
        cin >> answer;
        cout << "INSERIRE QUANTITÀ NUOVO ARTICOLO: ";
        int qty;
        cin >> qty;
        try {
            this->createNewArticle(answer1, answer, qty);
        }
        catch (invalid_argument &e) {
            cerr << e.what() << endl;
        }
    }

    void removeOldObjectButton() {
        string answer, answer1;
        cout << "\nINSERIRE NOME LISTA ORIGINE: ";
        cin >> answer1;
        cout << "INSERIRE NOME ARTICOLO DA RIMUOVERE: ";
        cin >> answer;
        try { this->deleteOldArticle(answer1, answer); }
        catch (invalid_argument &e) {
            cerr << e.what() << endl;
        }
    }

    ~View() override {
        controller->user->removeObserver(this);
    }

protected:
    Controller *controller;
    User *user;
};


#endif //ELABORATO_LAB_DI_PROGRAMMAZIONE_VIEW_H
