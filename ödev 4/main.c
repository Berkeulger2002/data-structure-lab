#include <stdio.h>
#include <stdlib.h>

// ��renci yap�s� (ad ve numara i�erir)
struct Student {
    char name[50];
    int number;
};

// ��renci dizisi
struct Student students[100]; // �rne�in, 100 ��renci i�eren bir dizi kullan�yoruz

// ��renci ekleme fonksiyonu
void addStudent(const char* name, int number, int index) {
    if (index < 0 || index >= 100) {
        printf("Ge�ersiz indeks. 0 ile 99 aras�nda bir indeks kullan�n.\n");
        return;
    }
    strcpy(students[index].name, name);
    students[index].number = number;
}

// ��renci arama fonksiyonu
int searchStudent(const char* name) {
    for (int i = 0; i < 100; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i; // �ndeks bulundu�unda geri d�n
        }
    }
    return -1; // �ndeks bulunamad���nda -1 d�n
}

int main() {
    // ��rencileri ekleyin
    addStudent("Kamal", 101, 0);
    addStudent("Kaz�m", 102, 1);
    addStudent("Begum", 103, 2);

    // Arama yap�n
    char searchName[50];
    printf("Enter the namen: ");
    scanf("%s", searchName);

    int result = searchStudent(searchName);

    if (result != -1) {
        printf("%s foundu. no: %d\n", students[result].name, students[result].number);
    } else {
        printf("��renci bulunamad�.\n");
    }

    return 0;
}
