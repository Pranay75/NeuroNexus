#include <bits/stdc++.h>
using namespace std;

vector<Book> books;
vector<Borrower> borrowers;

const double fineRate = 0.50; // Fine rate per day

struct Book {//struct to get book unit all details
    string title;
    string author;
    string ISBN;
    bool isAvailable;
    time_t borrowedDate;

    Book(string t, string a, string i)
        : title(t), author(a), ISBN(i), isAvailable(true), borrowedDate(0) {}
};

struct Borrower {
    string name;
    vector<string> borrowedBooks;

    Borrower(string n) : name(n) {}
};



void loadBooks() {
    ifstream file("books.txt");//creating a file for books info
    if (!file) return;
    string title, author, ISBN, status;
    while (file >> title >> author >> ISBN >> status) {
        bool available = (status == "available");
        books.push_back(Book(title, author, ISBN));
        books.back().isAvailable = available;
    }
    file.close();
}

void saveBooks() {
    ofstream file("books.txt");
    for (const auto &book : books) {
        file << book.title << " " << book.author << " " << book.ISBN << " "
             << (book.isAvailable ? "available" : "borrowed") << "\n";//writing into books file
    }
    file.close();
}


void addBook() {
    string title, author, ISBN;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter author: ";
    cin >> author;
    cout << "Enter ISBN: ";
    cin >> ISBN;
    books.push_back(Book(title, author, ISBN));
    saveBooks();// adding that vector into book file
    cout << "Book added successfully.\n";
}



void searchBooks() {
    string query;
    cout << "Enter title, author, or ISBN to search: ";
    cin >> query;
    for (const auto &book : books) {
        if (book.title == query || book.author == query || book.ISBN == query) {//getting the users needed book
            cout << "Title: " << book.title << ", Author: " << book.author
                 << ", ISBN: " << book.ISBN
                 << ", Status: " << (book.isAvailable ? "Available" : "Borrowed")
                 << "\n";
        }
    }
}
void checkoutBook() {
    string ISBN, borrowerName;
    cout << "Enter ISBN of the book to checkout: ";
    cin >> ISBN;
    cout << "Enter borrower's name: ";
    cin >> borrowerName;

    for (auto &book : books) {
        if (book.ISBN == ISBN && book.isAvailable) {
            book.isAvailable = false;//making book as unavailable because it is checked out
            book.borrowedDate = time(nullptr);

            bool borrowerExists = false;
            for (auto &borrower : borrowers) {
                if (borrower.name == borrowerName) {
                    borrower.borrowedBooks.push_back(ISBN);
                    borrowerExists = true;
                    break;
                }
            }


            if (!borrowerExists) {
                Borrower newBorrower(borrowerName);
                newBorrower.borrowedBooks.push_back(ISBN);
                borrowers.push_back(newBorrower);
            }

            saveBooks();
            cout << "Book checked out successfully.\n";
            return;
        }
    }
    cout << "Book is not available or does not exist.\n";
}

void returnBook() {
    string ISBN;
    cout << "Enter ISBN of the book to return: ";
    cin >> ISBN;

    for (auto &book : books) {
        if (book.ISBN == ISBN && !book.isAvailable) {
            time_t currentDate = time(nullptr);
            double daysBorrowed = difftime(currentDate, book.borrowedDate) / (60 * 60 * 24);
            double fine = (daysBorrowed > 14) ? (daysBorrowed - 14) * fineRate : 0;

            book.isAvailable = true;//making book available because it is returned
            book.borrowedDate = 0;
            saveBooks();

            for (auto &borrower : borrowers) {
                for (auto it = borrower.borrowedBooks.begin(); it != borrower.borrowedBooks.end(); ++it) {
                    if (*it == ISBN) {
                        borrower.borrowedBooks.erase(it);
                        break;
                    }
                }
            }

            cout << "Book returned successfully.\n";
            if (fine > 0) {
                cout << "Fine for late return: $" << fine << "\n";
            }
            return;
        }
    }
    cout << "Book was not borrowed or does not exist.\n";
}

void displayMenu() {
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Search Books\n";
    cout << "3. Checkout Book\n";
    cout << "4. Return Book\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    loadBooks();
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBooks();
                break;
            case 3:
                checkoutBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}
