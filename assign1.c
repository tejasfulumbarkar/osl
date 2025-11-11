#include <stdio.h>
#include <string.h>

struct Address {
    char name[50];
    char phone[20];
    char email[50];
};

struct Address book[100]; // Address book array
int count = 0; // Number of records

void createBook() {
    count = 0;
    printf("\nAddress Book Created (All previous records cleared)\n");
}

void viewBook() {
    if (count == 0) {
        printf("\nAddress Book is empty.\n");
        return;
    }

    printf("\nAddress Book:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s, Email: %s\n", i + 1, book[i].name, book[i].phone, book[i].email);
    }
}

void insertRecord() {
    printf("\nEnter Name: ");
    scanf("%s", book[count].name);
    printf("Enter Phone: ");
    scanf("%s", book[count].phone);
    printf("Enter Email: ");
    scanf("%s", book[count].email);

    count++;
    printf("Record Added Successfully!\n");
}

void deleteRecord() {
    char name[50];
    printf("\nEnter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                book[j] = book[j + 1];
            }
            count--;
            printf("Record Deleted Successfully!\n");
            return;
        }
    }
    printf("Record Not Found!\n");
}

void modifyRecord() {
    char name[50];
    printf("\nEnter name to modify: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, name) == 0) {
            printf("Enter New Phone: ");
            scanf("%s", book[i].phone);
            printf("Enter New Email: ");
            scanf("%s", book[i].email);
            printf("Record Updated Successfully!\n");
            return;
        }
    }
    printf("Record Not Found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n---- Address Book Menu ----\n");
        printf("1. Create Address Book\n");
        printf("2. View Address Book\n");
        printf("3. Insert a Record\n");
        printf("4. Delete a Record\n");
        printf("5. Modify a Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createBook(); break;
            case 2: viewBook(); break;
            case 3: insertRecord(); break;
            case 4: deleteRecord(); break;
            case 5: modifyRecord(); break;
            case 6: return 0;
            default: printf("\nInvalid Choice!\n");
        }
    }
}
