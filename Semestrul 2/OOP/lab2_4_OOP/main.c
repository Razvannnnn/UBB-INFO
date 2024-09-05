#include "ui.h"
#include "teste.h"
#include "repository.h"

int main() {
    run_all_tests();
    MyList* repo = creazaLista();
    MyList* undolist = creazaLista();
    main_menu(repo, undolist);
    return 0;
}
