#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>

char* findname(char namelist[][30], int boyut);

int main() {
    char namelist[7][30]; // 5 isim için 30 karakter uzunluðunda bir dizi
    strcpy(namelist[0], "Efe");
    strcpy(namelist[1], "Berke");
    strcpy(namelist[2], "Furkan");
    strcpy(namelist[3], "Ýzem");
    strcpy(namelist[4], "Abdulkadir");
    strcpy(namelist[5], "Melek");
    strcpy(namelist[6], "Abdurrahman");

    char* longestname = findname(namelist, 7);

    if (longestname != NULL) {
        printf("the longest other name: %s\n", longestname);
        printf("long: %lu\n", strlen(longestname));
    } else {
        printf("empty.\n");
    }

    return 0;
}

char* findname(char namelist[][30], int boyut) {
    if (boyut <= 0) {
        return NULL; // Dizi boþsa veya geçersizse NULL döner.
    }

    char* longestname = namelist[0];

    for (int i = 1; i < boyut; i++) {
        if (strlen(namelist[i]) > strlen(longestname)) {
            longestname = namelist[i];
        }
    }

    return longestname;
}

