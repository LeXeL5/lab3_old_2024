#include <iostream>
using namespace std;
void menu() {
    cout << "(0) shutdown program" << endl;
    cout << "(1) add(int value)" << endl;
    cout << "(2) insert(int index, int value)" << endl;
    cout << "(3) removeAt(int index)" << endl;
    cout << "(4) elementAt(int index)" << endl;
    cout << "(5) count()" << endl;
    cout << "(6) insertBeforeNegative()" << endl;
    cout << "(7) removeNegative()" << endl;
    cout << "(8) count(int value)" << endl;
    cout << "(9) clear()" << endl;
}
struct Node {
    int value = 0;
    Node* next = nullptr;
};
struct List {
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* current = nullptr;
    int size = 0;
    void toFirst() {
        current = head;
    }
    void toNext() {
        current = current->next;
    }
    bool isEmpty() {
        return !size;
    }

    void add(int value) {
        Node* newNode = new Node;
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        newNode->value = value;
        newNode->next = head;
        size++;
    }
    void insert(int index, int value) {
        if (isEmpty()) {
            add(value);
        }
        else {
            if (index >= 0) {
                while (index > size) {
                    index -= size;
                }
                if (index == size) {
                    add(value);
                }
                else {
                    Node* newNode = new Node;
                    newNode->value = value;
                    Node* prev = tail;
                    toFirst();
                    while (index) {
                        prev = current;
                        toNext();
                        index--;
                    }
                    if (current == head) {
                        head = newNode;
                    }
                    prev->next = newNode;
                    newNode->next = current;
                    size++;
                }
            }
        }

    }
    void removeAt(int index) {
        if (!isEmpty()) {
            if (index >= 0) {
                while (index >= size) {
                    index -= size;
                }
                Node* prev = tail;
                toFirst();
                while (index) {
                    prev = current;
                    toNext();
                    index--;
                }
                prev->next = current->next;
                if (head == current) {
                    head = current->next;
                }
                if (tail == current) {
                    tail = prev;
                }
                delete current;
                size--;
            }
        }
    }
    int elementAt(int index) {
        if (!isEmpty()) {
            if (index >= 0) {
                while (index > size) {
                    index -= size;
                }
            }
            toFirst();
            while (index) {
                toNext();
                index--;
            }
            return current->value;
        }
    }
    int count() {
        return size;
    }
    void insertBeforeNegative() {
        if (!isEmpty()) {
            Node* prev = tail;
            toFirst();
            int iteration = size;
            while (iteration) {
                if (current->value < 0) {
                    Node* newNode = new Node;
                    newNode->value = 1;
                    prev->next = newNode;
                    newNode->next = current;
                    size++;
                    if (current == head) {
                        head = newNode;
                    }
                }
                prev = current;
                toNext();
                iteration--;
            }
        }
    }
    void removeNegative() {
        if (!isEmpty()) {
            Node* prev = tail;
            toFirst();
            int iteration = size;
            while (iteration) {
                if (current->value < 0) {
                    if (current == tail) {
                        tail = prev;
                    }
                    if (current == head) {
                        head = current->next;
                    }
                    prev->next = current->next;
                    delete current;
                    size--;
                    current = prev->next;
                }
                else {
                    prev = current;
                    toNext();
                }
                iteration--;
            }
        }
    }
    int count(int value) {
        int counter = 0;
        if (!isEmpty()) {
            toFirst();
            int iteration = size;
            while (iteration) {
                if (current->value == value) {
                    counter++;
                }
                toNext();
                iteration--;
            }
        }
        return counter;
    }
    void clear() {
        while (size) {
            removeAt(0);
        }
    }
};
void main(int argc, char* argv[]) {
    bool interface = true;
    string argument;
    if (argc > 1) { argument = argv[1]; }
    if (argument == "false" || argument == "0") { interface = false; }

    List list;
    int value = 0;
    int count_what = 0;
    int index = 0;
    if (interface) {
        int switch_on = 1;
        while (switch_on) {
            system("cls");
            menu();
            cout << "Choice: ";
            cin >> switch_on;
            switch (switch_on) {
            case (0): {
                break;
            }
            case (1): {
                cout << "Value: ";
                cin >> value;
                cout << endl;
                list.add(value);
                break;
            }
            case (2): {
                cout << "Index and value: ";
                cin >> index;
                cin >> value;
                cout << endl;
                list.insert(index, value);
                break;
            }
            case (3): {
                cout << "Index: ";
                cin >> index;
                cout << endl;
                list.removeAt(index);
                break;
            }
            case (4): {
                if (!list.isEmpty()) {
                    cout << "Index: ";
                    cin >> index;
                    cout << endl;
                    cout << "Value: " << list.elementAt(index) << endl;
                }
                else {
                    cout << "List is empty " << endl;
                }
                break;
            }
            case (5): {
                cout << "List size: " << list.count() << endl;
                break;
            }
            case (6): {
                list.insertBeforeNegative();
                break;
            }
            case (7): {
                list.removeNegative();
                break;
            }
            case (8): {
                cout << "Value: ";
                cin >> count_what;
                cout << endl;
                cout << "Number of occurrences: " << list.count(count_what) << endl;
                break;
            }
            case (9): {
                list.clear();
                break;
            }
            default: {
                cout << "Unknown command, try again" << endl;
                break;
            }
            }
            system("pause");
        }
    }
    else {
        while (true) {
            cin >> value;
            if (value != 0) {
                list.add(value);
            }
            else {
                break;
            }
        }
        list.insertBeforeNegative();
        list.removeNegative();
        cin >> count_what;
        cout << list.count(count_what) << endl;
        list.clear();
    }
}