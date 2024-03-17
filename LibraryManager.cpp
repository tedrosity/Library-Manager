#include <iostream>
#include <string>

using namespace std;

class BookManager {
private:
    struct Node {
        int id;
        string title, author, genre;
        Node* next;
    };
    Node* head;

public:
    BookManager() : head(NULL) {}

    void insertBook() {
        Node* newBook = new Node;

        cout << "\nEnter Book ID: ";
        cin >> newBook->id;

        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, newBook->title);

        cout << "Enter Book Author: ";
        getline(cin, newBook->author);

        cout << "Enter Book Genre: ";
        getline(cin, newBook->genre);

        newBook->next = NULL;

        if (head == NULL) {
            head = newBook;
        } else {
            Node* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newBook;
        }
        cout << "\nNew Book Added Successfully!" << endl;
    }

    void searchBook() {
        int bookId;
        cout << "\nEnter Book ID: ";
        cin >> bookId;

        Node* ptr = head;
        while (ptr != NULL) {
            if (bookId == ptr->id) {
                cout << "\nBook ID: " << ptr->id << endl;
                cout << "Book Title: " << ptr->title << endl;
                cout << "Book Author: " << ptr->author << endl;
                return;
            }
            ptr = ptr->next;
        }
        cout << "\nBook Not Found." << endl;
    }

    void updateBook() {
        int bookId;
        cout << "\nEnter Book ID: ";
        cin >> bookId;

        Node* ptr = head;
        while (ptr != NULL) {
            if (bookId == ptr->id) {
                cout << "\nBook ID: " << ptr->id << endl;
                cout << "Enter Updated Book Title: ";
                cin.ignore();
                getline(cin, ptr->title);
                cout << "Enter Updated Book Author: ";
                getline(cin, ptr->author);
                cout << "\nBook Record Successfully Updated." << endl;
                return;
            }
            ptr = ptr->next;
        }
        cout << "\nBook Not Found." << endl;
    }

    void deleteBook() {
        int bookId;
        cout << "\nEnter Book ID: ";
        cin >> bookId;

        if (head == NULL) {
            cout << "\nBook List is Empty!" << endl;
            return;
        }

        if (bookId == head->id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "\nBook Record Successfully Deleted!" << endl;
            return;
        }

        Node* prev = head;
        Node* curr = head->next;
        while (curr != NULL) {
            if (bookId == curr->id) {
                prev->next = curr->next;
                delete curr;
                cout << "\nBook Record Successfully Deleted!" << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "\nBook Not Found." << endl;
    }

    void showBooks() {
        Node* ptr = head;
        while (ptr != NULL) {
            cout << "\nBook ID: " << ptr->id << endl;
            cout << "Book Title: " << ptr->title << endl;
            cout << "Book Author: " << ptr->author << endl;
            ptr = ptr->next;
        }
    }

    void searchByGenre() {
        string genre;
        cout << "\nEnter Book Genre: ";
        cin.ignore();
        getline(cin, genre);

        Node* ptr = head;
        bool found = false;
        while (ptr != NULL) {
            if (genre == ptr->genre) {
                if (!found) {
                    cout << "\nBooks In Genre: " << genre << endl;
                    found = true;
                }
                cout << "\nBook ID: " << ptr->id << endl;
                cout << "Book Title: " << ptr->title << endl;
                cout << "Book Author: " << ptr->author << endl;
            }
            ptr = ptr->next;
        }
        if (!found) {
            cout << "\nNo Books Found in This Genre: " << genre << endl;
        }
    }

    void menu() {
        int choice;
        while (true) {
            cout << "\n\tLibrary Management System";
            cout << "\n\n  Functions         Description" << endl;
            cout << "\n1\t Add Book\t\tInsert New Book";
            cout << "\n2\t Search Book\t\tSearch Book by ID";
            cout << "\n3\t Update Book\t\tUpdate Book Record";
            cout << "\n4\t Delete Book\t\tDelete Book by ID";
            cout << "\n5\t Show Books\t\tShow All Books";
            cout << "\n6\t Search By Genre\tSearch Book by Genre";
            cout << "\n7\t Exit" << endl;

            cout << "Enter Your Choice: ";

            cin >> choice;

            switch (choice) {
                case 1:
                    insertBook();
                    break;
                case 2:
                    searchBook();
                    break;
                case 3:
                    updateBook();
                    break;
                case 4:
                    deleteBook();
                    break;
                case 5:
                    showBooks();
                    break;
                case 6:
                    searchByGenre();
                    break;
                case 7:
                    return;
                default:
                    cout << "Invalid Choice." << endl;
            }
        }
    }
};

int main() {
    BookManager bookManager;
    bookManager.menu();
    return 0;
}
