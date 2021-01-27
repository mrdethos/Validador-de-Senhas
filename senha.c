#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool upper(char str[]);
bool lower(char str[]);
bool number(char str[]);
bool punc(char str[]);
bool acen(char str[]);
bool space(char str[]);
bool alphan(char str[]);
bool tam(char str[]);

int main() {
    bool valido = false;
    char str[256];
    while (scanf (" %255[^\n]", str) != EOF) {

        if (upper(str) && lower(str) && number(str) && punc(str) && acen(str) && space(str) && alphan(str) && tam(str)) {
            valido = true;
        }
        else {
            valido = false;
        }

        if (valido == false) {
            printf("Senha invalida\n");
        }
        else {
            printf("Senha valida\n");
        }
    }
    return 0;
}

//A função upper vai checar se a string possui uma letra maiúscula.
bool upper(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            return true;
        }
    }
    return false;
}

//A função lower vai checar se a string possui uma letra minúscula.
bool lower(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            return true;
        }
    }
    return false;
}

//A função number vai checar se a string possui um número.
bool number(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit (str[i])) {
            return true;
        }
    }
    return false;
}

//A função punc vai checar se a string possui algum caractere de pontuação.
bool punc(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.' || str[i] == ',' || str[i] == ';' || str[i] == ':' || str[i] == '?') {
            return false;
        }
    }
    return true;
}

//A função acen vai checar se a string possui algum caractere de acentuação.
bool acen(char str[]) {
    for(int i = 0; str[i] != '\0'; i++) {
        //Em ASCII, os caracteres com acento sempre terão um número negativo.
        if(str[i] < 0) {
            return false;
            }
        }
    return true;
}

//A função space vai checar se a string possui algum espaço.
bool space(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            return false;
        }
    }
    return true;
}

//A função alphan vai checar se a string possui um caractere não alfanumérico.
bool alphan(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i]) == 0) {
            return true;
        }
    }
    return false;
}

//A função tam vai checar se a string tem entre 6 a 32 caracteres.
bool tam(char str[]) {
    if (strlen(str) < 6 || strlen(str) > 32) {
        return false;
    }
    return true;
}
