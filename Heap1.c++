#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec, st;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        if (q == 1) {
            int temp;
            cin >> temp;
            vec.push_back(temp);
            push_heap(vec.begin(), vec.end());
        } else {
            st.push_back(vec.front());
            pop_heap(vec.begin(), vec.end());
            vec.pop_back();
        }
    }
    for (int i = 0; i < st.size(); ++i) {
        cout << st[i] << endl;
    }
}