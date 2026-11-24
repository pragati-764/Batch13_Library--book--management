1.Library Book Management System
C Programming Mini Hackathon — Problem 2

2. Problem Statement------
Create a program to maintain a small collection of library books and track their availability.
Requirements:
- Store the book ID, title, and availability status for at least 10 books.
- Display all books and search for a book using its ID.
- Allow books to be issued and returned.
- Prevent a book from being issued if it is already issued.
Expected output: A book list, search results, and updated availability status.
------- Proposed Solution---------
-We developed a menu-driven Library Book Management System in C.
- It stores each book's ID, title, author, and issue status.
 -Users can add books, view the collection, search by ID, issue books, and return books.
 -The program uses file handling to save records in (books.dat), so records can be loaded the next time the program starts.

------- Project and Team Details------
 Project Title --Library Book Management System 
 Team Name --Self and Syntax 
 Batch -- 13 
 Team Member 1 -- Hetarth Barot 
 Team Member 2 -- Anshul Chaurasia 
 Team Member 3 -- Pragati 
 Programming Language -- C

-----------Objectives----------
- Maintain a simple digital record of library books.
- Find books quickly using their unique IDs.
- Keep track of whether books are available or issued.
- Stop duplicate book IDs and repeated issuing of the same book.
- Save the library data for later use.
- 
----------- Main Features-------------
1. User details: Asks for a name and SAP ID at startup. This is a basic greeting/input step, not password-based authentication.
2. Add Book: Adds an ID, title, and author, with a check for duplicate IDs.
3. Display Books: Shows all stored books and their availability status.
4. Search Book: Searches for a book using its ID.
5. Issue Book: Marks an available book as issued and blocks issuing it again.
6. Return Book: Marks an issued book as available and blocks returning a book that was not issued.
7. File Handling: Saves changes to books.dat and loads them at startup.
8. Capacity: Stores up to 50 books, which supports the requirement of at least 10 books.
   
---------Algorithm / Pseudocode---------
-START
-Load saved book records from books.dat (if the file exists)
-Ask user for name and SAP ID
-REPEAT
 -   Display menu
 -  Read user's choice
 -   IF choice = 1: Add book if library is not full and ID is unique; save
 -   ELSE IF choice = 2: Display all books
 -   ELSE IF choice = 3: Search for a book by ID
 -   ELSE IF choice = 4: Find book; if available, mark issued and save
 -   ELSE IF choice = 5: Find book; if issued, mark available and save
 -   ELSE IF choice = 0: Display goodbye message
 -   ELSE: Display invalid choice
-UNTIL choice = 0
-STOP
----flowchart---
   A([Start]) --> B[Load books.dat]
    B --> C[Enter name and SAP ID]
    C --> D[Display library menu]
    D --> E{Menu choice?}
    E -->|1 Add| F[Check capacity and duplicate ID; add and save]
    E -->|2 Display| G[Show all books and status]
    E -->|3 Search| H[Find book by ID]
    E -->|4 Issue| I[Check availability; issue and save if allowed]
    E -->|5 Return| J[Check issue status; return and save if allowed]
    E -->|0 Exit| K([Goodbye / Stop])
    E -->|Other| L[Invalid choice]
    F --> D
    G --> D
    H --> D
    I --> D
    J --> D
    L --> D
    
---------- Program Logic and Implementation--------------------
The program defines a struct Book with four fields: id, title, author, and issued.
It uses a global array books[50] to store up to 50 records and count to track how many records are stored. 
The issued field is 0 for available and 1 for issued.
Function	Purpose
loadBooks()	Reads saved records from (books.dat) when the program starts.
saveBooks()	Writes the book count and book records to books.dat.
addBook()	Adds a new book if capacity allows and its ID is not already used.
displayBooks()	Prints all book records and their status.
searchBook()	Finds a book using its ID.
issueBook()	Issues a book only when it is available.
returnBook()	Returns a book only when it is currently issued.
main()	Reads user details and runs the menu using a do-while loop and switch.

--------------- C programming concepts used-------------------------
-Structures: struct Book groups information about each book.
-Arrays: books[50] stores multiple book records.
-Functions: Each library operation is handled by a separate function.
-Loops: for loops search/display books; do-while repeats the menu.
-Conditional statements: if-else checks IDs and availability.
-Switch-case: Selects the operation from the menu.
-File handling: FILE, fopen, fread, fwrite, and fclose save and load data.
-Global variables: books and count are shared by the functions.
-Input/output: printf and scanf interact with the user.

-------- How to Compile and Execute the program -----------
Requirements: A C compiler such as GCC, and a terminal or C development environment.
1. Save the complete C source code as library_management.c.
2. Open a terminal in the folder containing the source file.
3. Compile the program:
   gcc -std=c99 library_management.c -o library_management
4. Run it on Windows:
   .\library_management.exe
   Or on Linux/macOS:
   ./library_management
5. Enter your name and SAP ID, then choose a menu option from 0 to 5.
6. The program automatically creates or updates (books.dat) when a book is successfully added, issued, or returned.
 Keep this file in the working directory to preserve records between runs.
Note: On first run, the library starts empty. Add at least 10 books to demonstrate the required capacity. There is no preloaded set of 10 books.
-------sample test cases----------
   
--- LOGIN ---
Enter First Name: arya
Enter SAP ID: 590057898
--- LIBRARY MENU ---
Hello arya
1. Add Book
2. Display Books
3. Search Book
4. Issue Book
5. Return Book
0. Exit
Enter choice: 1
Enter Book ID: 101
ID already exists!

--- LIBRARY MENU ---
Hello arya
2. Add Book
3. Display Books
4. Search Book
5. Issue Book
6. Return Book
0. Exit
Enter choice: 1
Enter Book ID: 102
Enter Title: Aldof Hitler
Enter Author: Alan
Book added!

--- LIBRARY MENU ---
Hello arya
2. Add Book
3. Display Books
4. Search Book
5. Issue Book
6. Return Book
0. Exit
Enter choice: 2
ID: 101
Title: morphy
Author: roy
Status: Issued
ID: 102
Title: Aldof Hitler
Author: Alan
Status: Available

--- LIBRARY MENU ---
Hello arya
1. Add Book
2. Display Books
3. Search Book
4. Issue Book
5. Return Book
0. Exit
Enter choice: 3
Enter ID to search: 102
Book Found!
ID: 102
Title: Aldof Hitler
Author: Alan
Status: Available

--- LIBRARY MENU ---
Hello arya
1. Add Book
2. Display Books
3. Search Book
4. Issue Book
5. Return Book
0. Exit
Enter choice: 4
Enter Book ID to issue: 101
Book is already issued.

--- LIBRARY MENU ---
Hello arya
1. Add Book
2. Display Books
3. Search Book
4. Issue Book
5. Return Book
0. Exit
Enter choice: 5
Enter Book ID to return: 101
Book returned!




   
