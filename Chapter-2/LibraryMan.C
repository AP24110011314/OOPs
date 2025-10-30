#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// ---------------- Book Class ----------------
class Book {
private:
    int id;
    string title;
    string author;
    bool isIssued;
    time_t dueDate;

public:
    Book(int id, string title, string author)
        : id(id), title(title), author(author), isIssued(false), dueDate(0) {}

    int getId() { return id; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    bool getIssuedStatus() { return isIssued; }

    void showStatus() {
        cout << "Book ID: " << id << " | Title: " << title << " | Author: " << author;
        if (isIssued) {
            cout << " | Status: Issued | Due Date: " << ctime(&dueDate);
        } else {
            cout << " | Status: Available\n";
        }
    }

    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            // Set due date as 7 days from now
            dueDate = time(0) + 7 * 24 * 60 * 60;
            cout << "Book issued successfully. Due Date: " << ctime(&dueDate);
        } else {
            cout << "Book is already issued!\n";
        }
    }

    void returnBook() {
        if (isIssued) {
            isIssued = false;
            dueDate = 0;
            cout << "Book returned successfully.\n";
        } else {
            cout << "This book was not issued.\n";
        }
    }

    time_t getDueDate() { return dueDate; }
};

// ---------------- Account Class ----------------
class Account {
private:
    int userId;
    double fine;

public:
    Account(int userId) : userId(userId), fine(0.0) {}

    void alertDueDate(Book &book) {
    if (book.getIssuedStatus()) {
        time_t due = book.getDueDate();
        cout << "Reminder: Book '" << book.getTitle() 
             << "' is due on " << ctime(&due);
    }
}

    void calculateFine(Book &book) {
        if (book.getIssuedStatus()) {
            time_t now = time(0);
            if (now > book.getDueDate()) {
                double daysLate = difftime(now, book.getDueDate()) / (60 * 60 * 24);
                fine = daysLate * 5; // Rs.5 per day late
                cout << "Fine for late return: Rs." << fine << endl;
            } else {
                cout << "No fine. Book is within due date.\n";
            }
        }
    }

    void payFine() {
        if (fine > 0) {
            cout << "Fine of Rs." << fine << " paid successfully.\n";
            fine = 0;
        } else {
            cout << "No fine pending.\n";
        }
    }
};

// ---------------- User Class ----------------
class User {
protected:
    int id;
    string name;
    Account account;

public:
    User(int id, string name) : id(id), name(name), account(id) {}

    virtual void displayRole() { cout << "User\n"; }

    void borrowBook(Book &book) { book.issueBook(); }

    void returnBook(Book &book) { book.returnBook(); }

    void payFine() { account.payFine(); }

    void searchBook(vector<Book> &books, string keyword) {
        cout << "Search Results for: " << keyword << "\n";
        for (auto &book : books) {
            if (book.getTitle().find(keyword) != string::npos ||
                book.getAuthor().find(keyword) != string::npos) {
                book.showStatus();
            }
        }
    }

    Account &getAccount() { return account; }
};

// ---------------- Librarian Class ----------------
class Librarian : public User {
public:
    Librarian(int id, string name) : User(id, name) {}

    void displayRole() override { cout << "Librarian\n"; }

    void issueBook(Book &book) { book.issueBook(); }

    void depositBook(Book &book) { book.returnBook(); }

    void enterBook(vector<Book> &books, int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully.\n";
    }

    void deleteBook(vector<Book> &books, int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getId() == id) {
                books.erase(it);
                cout << "Book deleted successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

// ---------------- Main ----------------
int main() {
    vector<Book> books;
    books.push_back(Book(1, "C++ Programming", "Bjarne Stroustrup"));
    books.push_back(Book(2, "Data Structures", "Mark Weiss"));
    books.push_back(Book(3, "Algorithms", "CLRS"));

    User user1(101, "Alice");
    Librarian librarian(201, "Mr. Smith");

    int choice;
    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Show Books\n2. Borrow Book\n3. Return Book\n4. Pay Fine\n5. Search Book\n";
        cout << "6. Librarian: Add Book\n7. Librarian: Delete Book\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (auto &book : books) book.showStatus();
        } else if (choice == 2) {
            int id;
            cout << "Enter Book ID to borrow: ";
            cin >> id;
            for (auto &book : books) {
                if (book.getId() == id) {
                    user1.borrowBook(book);
                    user1.getAccount().alertDueDate(book);
                }
            }
        } else if (choice == 3) {
            int id;
            cout << "Enter Book ID to return: ";
            cin >> id;
            for (auto &book : books) {
                if (book.getId() == id) {
                    user1.returnBook(book);
                    user1.getAccount().calculateFine(book);
                }
            }
        } else if (choice == 4) {
            user1.payFine();
        } else if (choice == 5) {
            string keyword;
            cout << "Enter keyword to search: ";
            cin.ignore();
            getline(cin, keyword);
            user1.searchBook(books, keyword);
        } else if (choice == 6) {
            int id;
            string title, author;
            cout << "Enter new Book ID, Title, Author: ";
            cin >> id;
            cin.ignore();
            getline(cin, title);
            getline(cin, author);
            librarian.enterBook(books, id, title, author);
        } else if (choice == 7) {
            int id;
            cout << "Enter Book ID to delete: ";
            cin >> id;
            librarian.deleteBook(books, id);
        }
    } while (choice != 8);

    return 0;
}