#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Hash table using chaining
class HashTable {
private:
    vector<list<int>> table;
    int capacity;

    int hash(int key) {
        return key % capacity;
    }

public:
    HashTable(int size) : capacity(size) {
        table.resize(size);
    }

    void insertItem(int key) {
        int index = hash(key);
        table[index].push_front(key);
    }

    bool deleteItem(int key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                table[index].erase(it);
                cout << key << ":DELETED;" << endl;
                return true;
            }
        }
        cout << key << ":DELETE_FAILED;" << endl;
        return false;
    }

    bool searchItem(int key) {
        int index = hash(key);ff
        int count = 0;
        for (int it : table[index]) {
            if (it == key) {
                cout << key << ":FOUND_AT" << index << "," << count << ";" << endl;
                return true;
            }
            count++;
        }
        cout << key << ":NOT_FOUND;" << endl;
        return false;
    }

    void displayHash() {
        for (int i = 0; i < capacity; i++) {
            cout << i << ":";
            for (int x : table[i]) {
                cout << x << "->";
            }
            cout << ";" << endl;
        }
    }
};

int main() {
    int hashSize;
    cin >> hashSize;
    HashTable ht(hashSize);

    string input;
    bool repeat = true;

    do {
        cin >> input;
        int number = 0;
        // Create integer if required by function
        for (int i = 1; i < input.size(); i++) {
            int digit = input[i] - '0';
            number = 10 * number + digit;
        }

        switch (input[0]) {
            case 'i':
                ht.insertItem(number);
                break;
            case 'd':
                ht.deleteItem(number);
                break;
            case 's':
                ht.searchItem(number);
                break;
            case 'o':
                ht.displayHash();
                break;
            case 'e':
                repeat = false;
                break;
            default:
                cout << "INVALID INPUT" << endl;
                break;
        }
    } while (repeat);

    return 0;
}
