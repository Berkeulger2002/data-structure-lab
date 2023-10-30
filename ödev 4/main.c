#include <stdio.h>
#include <stdlib.h>

// Öðrenci yapýsý (ad ve numara içerir)
struct Student {
    char name[50];
    int number;
};

// Öðrenci dizisi
struct Student students[100]; // Örneðin, 100 öðrenci içeren bir dizi kullanýyoruz

// Öðrenci ekleme fonksiyonu
void addStudent(const char* name, int number, int index) {
    if (index < 0 || index >= 100) {
        printf("Geçersiz indeks. 0 ile 99 arasýnda bir indeks kullanýn.\n");
        return;
    }
    strcpy(students[index].name, name);
    students[index].number = number;
}

// Öðrenci arama fonksiyonu
int searchStudent(const char* name) {
    for (int i = 0; i < 100; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i; // Ýndeks bulunduðunda geri dön
        }
    }
    return -1; // Ýndeks bulunamadýðýnda -1 dön
}

int main() {
    // Öðrencileri ekleyin
    addStudent("Kamal", 101, 0);
    addStudent("Kazým", 102, 1);
    addStudent("Begum", 103, 2);

    // Arama yapýn
    char searchName[50];
    printf("Enter the namen: ");
    scanf("%s", searchName);

    int result = searchStudent(searchName);

    if (result != -1) {
        printf("%s foundu. no: %d\n", students[result].name, students[result].number);
    } else {
        printf("Öðrenci bulunamadý.\n");
    }

    return 0;
}
