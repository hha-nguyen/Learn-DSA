#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<int, string> store;
    int q;
    cin >> q;
    while(q--) {
        int q1;
        cin >> q1;
        if (q1 == 1) {
            int id;
            string st;
            cin >> id >> st;
            store[id] = st;
        } else if (q1 == 2) {
            int id;
            cin >> id;
            store.erase(id);
        } else {
            int id;
            cin >> id;
            if (store.count(id) > 0) {
                cout << store[id] << endl;
            } else if (store.count(id) == 0) {
                cout << "n/a" << endl;
            }     
        }
    }
}