#include "View.h"
#include "Controller.h"

int main() {

    User user;
    user.setUserName("MATTIA");

    Controller controller(&user);

    View view(&controller, &user);

    view.addNewListButton();
    view.addNewObjectButton();
    view.addNewObjectButton();

    view.removeOldObjectButton();
    view.removeOldObjectButton();
    view.removeListButton();

    return 0;
}
