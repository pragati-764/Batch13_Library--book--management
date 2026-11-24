#include <stdio.h>
struct Book
{
    int id;
    char title[50];
    char author[50];
    int issued;
};

struct Book books[50];
int count = 0;

// Save all books in a file
void saveBooks()
{
    FILE *fp = fopen("books.dat", "wb");

    if (fp == NULL)
    {
        printf("Error saving data!\n");
        return;
    }

    fwrite(&count, sizeof(count), 1, fp);
    fwrite(books, sizeof(struct Book), count, fp);

    fclose(fp);
}

// Load books from file when program starts
void loadBooks()
{
    FILE *fp = fopen("books.dat", "rb");

    if (fp == NULL)
    {
        // File does not exist yet
        count = 0;
        return;
    }

    fread(&count, sizeof(count), 1, fp);

    if (count < 0 || count > 50)
    {
        count = 0;
        fclose(fp);
        printf("Invalid data file!\n");
        return;
    }

    fread(books, sizeof(struct Book), count, fp);
    fclose(fp);
}

// Add a book
void addBook()
{
    int flag = 0;

    if (count >= 50)
    {
        printf("Library is full!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &books[count].id);

    for (int i = 0; i < count; i++)
    {
        if (books[i].id == books[count].id)
        {
            flag = 1;
            printf("ID already exists!\n");
            break;
        }
    }

    if (flag == 0)
    {
        printf("Enter Title: ");
        scanf(" %[^\n]", books[count].title);

        printf("Enter Author: ");
        scanf(" %[^\n]", books[count].author);

        books[count].issued = 0;

        count++;

        saveBooks();

        printf("Book added!\n");
    }
}

// Display all books
void displayBooks()
{
    if (count == 0)
    {
        printf("No books available.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("\nID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);

        if (books[i].issued == 1)
        {
            printf("Status: Issued\n");
        }
        else
        {
            printf("Status: Available\n");
        }
    }
}

// Search a book
void searchBook()
{
    int ID, found = 0;

    printf("Enter ID to search: ");
    scanf("%d", &ID);

    for (int i = 0; i < count; i++)
    {
        if (books[i].id == ID)
        {
            printf("\nBook Found!\n");
            printf("ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);

            if (books[i].issued == 1)
                printf("Status: Issued\n");
            else
                printf("Status: Available\n");

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Book not found.\n");
    }
}

// Issue a book
void issueBook()
{
    int id, found = 0;

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (books[i].id == id)
        {
            found = 1;

            if (books[i].issued == 1)
            {
                printf("Book is already issued.\n");
            }
            else
            {
                books[i].issued = 1;

                saveBooks();

                printf("Book issued!\n");
            }

            break;
        }
    }

    if (found == 0)
    {
        printf("Book not found.\n");
    }
}

// Return a book
void returnBook()
{
    int id, found = 0;

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++)
    {
        if (books[i].id == id)
        {
            found = 1;

            if (books[i].issued == 0)
            {
                printf("Book was not issued.\n");
            }
            else
            {
                books[i].issued = 0;

                saveBooks();

                printf("Book returned!\n");
            }

            break;
        }
    }

    if (found == 0)
    {
        printf("Book not found.\n");
    }
}

// Main function
int main()
{
    int sap, choice;
    char user[50];

    // Load previously saved books
    loadBooks();

    printf("--- LOGIN ---\n");

    printf("Enter First Name: ");
    scanf(" %[^\n]", user);

    printf("Enter SAP ID: ");
    scanf("%d", &sap);

    do
    {
        printf("\n--- LIBRARY MENU ---\n");
        printf("\nHello %s\n", user);

        printf("\n1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 0:
                printf("\nGoodbye %s!\n", user);
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
