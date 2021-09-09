//
// Created by mattia on 26/08/21.
//

#include "View.h"

void View::update(string &name, bool oS, int a, bool lS, int x) {
    if (x == 1) {
        if (lS) {
            cout << "\nLA LISTA " << name << " È STATA AGGIUNTA CORRETTAMENTE. \n";
        } else {
            cout << "\nLA LISTA " << name << " È STATA RIMOSSA CORRETTAMENTE. \n";
        }
    } else {
        if (oS) {
            cout << "\nL'ARTICOLO " << name << " È STATO AGGIUNTO CORRETTAMENTE. \n";
            goto label1;
        } else {
            cout << "\nL'ARTICOLO " << name << " È STATO RIMOSSO CORRETTAMENTE. \n";
            goto label1;
        }
        label1:
        cout << "\nIL NUMERO TOTALE DI ARTICOLI DELLA LISTA SELEZIONATA È: " << a << endl;
    }
}

void View::addNewObjectButton() {
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


void View::removeOldObjectButton() {
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

void View::purchaseButton() {
    string answer, answer1;
    cout << "DIGITARE NOME LISTA: ";
    cin >> answer1;
    cout << "DIGITARE NOME OGGETTO: ";
    cin >> answer;
    try { controller->buyAnObject(answer, answer1); }
    catch (invalid_argument &e) {
        cerr << e.what() << endl;
    }
}

void View::untickPurchaseButton() {
    string answer, answer1;
    cout << "DIGITARE NOME LISTA: ";
    cin >> answer1;
    cout << "DIGITARE NOME OGGETTO: ";
    cin >> answer;
    try { controller->deselectObjectToBuy(answer, answer1); }
    catch (invalid_argument &e) {
        cerr << e.what() << endl;
    }
}
