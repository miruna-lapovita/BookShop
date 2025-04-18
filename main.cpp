#include <iostream>
#include "Tests.h"
#include "UI.h"
#include "Book.h"
#include "Bancnote.h"
#include <string>

int main() {
    tests();
    cout << endl;
    RepositoryFile<Book> entity(R"(C:\Users\Miruna\CLionProjects\Lab 11-12OOP\book.txt)");
    RepositoryFile<Bancnote> bancnote(R"(C:\Users\Miruna\CLionProjects\Lab 11-12OOP\bancnote.txt)");
    Service service(entity, bancnote);
    UI ui(service);
    ui.menu();

    return 0;
}

