#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "lista_sequencial.h"
//#include "lista_sequencial.c"

int main(){

    setlocale(LC_ALL, "Portuguese");

    Lista *li;

    li = cria_Lista();
    menu(li);
    libera_lista(li);

    return 0;
}
