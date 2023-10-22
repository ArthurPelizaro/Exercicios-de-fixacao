#include <stdio.h>
#include <stdbool.h>
/* Simulação de um sistema de gerenciamento de biblioteca */
#define MAX_BOOKS 100

struct Book {
    char title[100];
    char author[100];
    int isAvailable;
};

struct Library {
    struct Book books[MAX_BOOKS];
    int numBooks;
};

void addBook(struct Library *library, const char *title, const char *author) {
    if (library->numBooks < MAX_BOOKS) {
        struct Book newBook;
        snprintf(newBook.title, sizeof(newBook.title), "%s", title);
        snprintf(newBook.author, sizeof(newBook.author), "%s", author);
        newBook.isAvailable = 1; // 1 means available
        library->books[library->numBooks] = newBook;
        library->numBooks++;
        printf("Livro adicionado com sucesso.\n");
    } else {
        printf("A biblioteca está cheia, não é possível adicionar mais livros.\n");
    }
}

void lendBook(struct Library *library, const char *title) {
    for (int i = 0; i < library->numBooks; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            if (library->books[i].isAvailable) {
                library->books[i].isAvailable = 0; // 0 means not available
                printf("Livro emprestado com sucesso.\n");
                return;
            } else {
                printf("O livro não está disponível para empréstimo.\n");
                return;
            }
        }
    }
    printf("Livro não encontrado na biblioteca.\n");
}

void checkBookStatus(struct Library *library, const char *title) {
    for (int i = 0; i < library->numBooks; i++) {
        if (strcmp(library->books[i].title, title) == 0) {
            if (library->books[i].isAvailable) {
                printf("O livro '%s' está disponível.\n", library->books[i].title);
            } else {
                printf("O livro '%s' não está disponível no momento.\n", library->books[i].title);
            }
            return;
        }
    }
    printf("Livro não encontrado na biblioteca.\n");
}

int main() {
    struct Library library;
    library.numBooks = 0;

    addBook(&library, "Harry Potter", "J.K. Rowling");
    addBook(&library, "To Kill a Mockingbird", "Harper Lee");

    lendBook(&library, "Harry Potter");

    checkBookStatus(&library, "Harry Potter");
    checkBookStatus(&library, "To Kill a Mockingbird");

    return 0;
}
