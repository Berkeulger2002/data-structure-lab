#include <stdio.h>
#include <stdlib.h>

struct Nodee {
    int data;
    struct Nodee* next;
};

// Ba�l� listeye eleman eklemek i�in fonksiyon
void addlist(struct Node** start, int newdata) {
    struct Nodee* newloop = (struct Node*)malloc(sizeof(struct Nodee));
    newloop->data = newdata;
    newloop->next = (*start);
    (*start) = newloop;
}

void listorder(struct Nodee* loop) {
    struct Nodee* this, * next;
    int unstable;
    for (this = loop; this != NULL; this = this->next) {
        for (next = this->next; next != NULL; next = next->next) {
            if (this->data > next->data) {  // B�y�kten k����e s�ralama i�in "simdiki->veri >
                unstable = this->data;
                this->data = next->data;
                next->data = unstable;
            }
        }
    }
}


int main() {
    struct Nodee* start = NULL;

    srand(time(0)); // Rastgele say� �retimi i�in rastgele bir ba�lang�� noktas� belirliyoruz

    // Ba�l� listeye rastgele 100 say� ekliyoruz
    for (int i = 0; i < 100; i++) {
        addlist(&start, rand() % 1000); // 0 ile 999 aras�nda rastgele say�lar
    }

    // Ba�l� listeyi b�y�kten k����e s�ral�yoruz
    listorder(start);

    // S�ralanm�� say�lar� ekrana yazd�rma
   printf("numbers: ");
    struct Nodee* now = start;
    while (now != NULL) {
        printf("%d", now->data);
        if (now->next != NULL) {
            printf("->");
        }
        now = now->next;
    }
    printf("\n");
    return 0;
}
