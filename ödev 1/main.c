#include <stdio.h>
#include <stdlib.h>

truct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* add(Node* head, int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = head;
    return newNode;
}

void write(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* odd = NULL;   // Tek sayýlarý içeren baðlý liste
    Node* even = NULL;  // Çift sayýlarý içeren baðlý liste

    printf("Enter numbers (finish by entering -1)):\n");
    int num;

    while (1) {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num == -1) {
            break;  // -1 girildiðinde döngüyü sonlandýr
        }

        if (num % 2 == 1) {
            // Tek sayý ise, tekler listesine ekle
            odd = add(odd, num);
        } else {
            // Çift sayý ise, ciftler listesine ekle
            even = add(even, num);
        }
    }

    printf("conclusion:\n");
    printf("odd numbers: ");
    write(odd);
    printf("even numbers: ");
    write(even);

    // Bellek temizleme
    while (odd != NULL) {
        Node* temp = odd;
        odd = odd->next;
        free(temp);
    }
    while (even != NULL) {
        Node* temp = even;
        even = even->next;
        free(temp);
    }

    return 0;
}
