#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    map<int, vector<int>> store;
    vector<int> vec;
    int q;
    cin >> q;
    while (q--) {
        int num;
        cin >> num;
        store[num].push_back(q);
        cout << store[num].size() << endl;
    }
}