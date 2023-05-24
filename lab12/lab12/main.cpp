#include "Agenda.h"
#include <iostream>
#include <vector>
using namespace std;
int main() {
    Agenda a;
    Contact* andrei = new Prieten("Andrei","0750522902", "Str.Zavoiului nr.152", "01.05.2003");
    Contact* maria = new Coleg("Maria", "0750522902", "Str.Zavoiului nr.152", "Amazon");
    Contact* bogdan = new Cunoscut("Bogdan", "0750522902");
    a.add_contact(andrei);
    a.add_contact(maria);
    a.add_contact(bogdan);

    auto p = a.get_friends();
    for (auto i : p)
        cout << i->get_name() << ' ' << i->get_phone() << ' ' << i->get_addr() << ' ' << i->get_birth();

    a.delete_by_name("Andrei");
    a.delete_by_name("Maria");
    a.delete_by_name("Bogdan");

    return 0;
}