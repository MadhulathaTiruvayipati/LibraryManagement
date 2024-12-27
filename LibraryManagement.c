#include <stdio.h>

struct Book {
    int id;
    char name[50];
    char author[50];
};

void addBook(struct Book *book) {
    printf("Enter Book ID: ");
    scanf("%d", &book->id);
    printf("Enter Book Name: ");
    scanf(" %[^\n]", book->name);
    printf("Enter Book Author: ");
    scanf(" %[^\n]", book->author);
}

void displayBook(struct Book book) {
    printf("\nBook ID: %d\n", book.id);
    printf("Book Name: %s\n", book.name);
    printf("Book Author: %s\n", book.author);
}

int main() {
    struct Book library[10];
    int choice, index = 0;
    
    while(1) {
        printf("\n1. Add Book\n2. Display Books\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                if (index < 10) {
                    addBook(&library[index]);
                    index++;
                } else {
                    printf("Library is full!\n");
                }
                break;
            case 2:
                for (int i = 0; i < index; i++) {
                    displayBook(library[i]);
                }
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
