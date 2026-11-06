
#include <iostream>  // For input and output
#include <fstream>   // For reading and saving books
#include <string>    // For text variables
#include <vector>    // For storing books
#include <sstream>   // For separating book information
#include <limits>    // For handling invalid input

using namespace std;

// Class to store book information
class Book {
public:
    string title;
    string author;
    int pages;
    string bookID;
    bool status;
};

// Read books from the text file
vector<Book> loadBooks() {
    vector<Book> books;
    ifstream file("bookData.txt");
    string line;

    if (!file.is_open()) {
        cout << "Error: Cannot open bookData.txt" << endl;
        return books;
    }

    while (getline(file, line)) {
        stringstream ss(line);
        Book book;
        string pages, status;

        getline(ss, book.title, ',');
        getline(ss, book.author, ',');
        getline(ss, pages, ',');
        getline(ss, book.bookID, ',');
        getline(ss, status);

        if (pages.empty()) continue;

        book.pages = stoi(pages);
        book.status = (status == "true");
        books.push_back(book);
    }

    file.close();
    return books;
}

// Save updated books to the text file
void saveBooks(const vector<Book>& books) {
    ofstream file("bookData.txt");

    if (!file.is_open()) {
        cout << "Error: Cannot save book data." << endl;
        return;
    }

    for (const Book& book : books) {
        file << book.title << ","
             << book.author << ","
             << book.pages << ","
             << book.bookID << ","
             << (book.status ? "true" : "false") << endl;
    }

    file.close();
}

// Display information about one book
void displayBook(const Book& book) {
    cout << "\nBook ID: " << book.bookID << endl;
    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "Pages: " << book.pages << endl;
    cout << "Status: "
         << (book.status ? "Borrowed" : "Available") << endl;
}

// Display all books
void displayBooks(const vector<Book>& books) {
    cout << "\n=== Library Book List ===" << endl;

    for (const Book& book : books) {
        displayBook(book);
        cout << "------------------------" << endl;
    }
}

// View one book using its ID
void viewBook(const vector<Book>& books) {
    string searchID;
    cout << "Enter Book ID: ";
    cin >> searchID;

    for (const Book& book : books) {
        if (book.bookID == searchID) {
            cout << "\n=== Book Details ===" << endl;
            displayBook(book);
            return;
        }
    }

    cout << "Book not found." << endl;
}

// Borrow or return a book
void updateBook(vector<Book>& books, bool borrowing) {
    string searchID;

    cout << "Enter Book ID to "
         << (borrowing ? "borrow: " : "return: ");
    cin >> searchID;

    for (Book& book : books) {
        if (book.bookID == searchID) {
            if (book.status == borrowing) {
                cout << (borrowing
                    ? "This book is already borrowed."
                    : "This book is already available.") << endl;
                return;
            }

            book.status = borrowing;
            saveBooks(books);

            cout << (borrowing
                ? "Book borrowed successfully!"
                : "Book returned successfully!") << endl;
            return;
        }
    }

    cout << "Book not found." << endl;
}

// Main program
int main() {
    vector<Book> books = loadBooks();

    if (books.empty()) {
        cout << "No books available." << endl;
        return 1;
    }

    int choice;

    while (true) {
        cout << "\n=== Book Manager ===" << endl;
        cout << "1. View all books" << endl;
        cout << "2. View individual book" << endl;
        cout << "3. Borrow a book" << endl;
        cout << "4. Return a book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid choice. Enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            displayBooks(books);
        }
        else if (choice == 2) {
            viewBook(books);
        }
        else if (choice == 3) {
            updateBook(books, true);
        }
        else if (choice == 4) {
            updateBook(books, false);
        }
        else if (choice == 5) {
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

