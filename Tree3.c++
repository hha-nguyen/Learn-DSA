#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int *parents = new int[n + 1];
    int *childs = new int[n + 1];
    int *countChilds = new int[n + 1];

    int edge = n - 1;

    for (int i = 0; i < n; i++) {
        cin >> parents[i] >> childs[i];
    }

    if (parents[n - 1] == 0 && childs[n - 1] == 0) {
        n--;
        edge--;
    }

    for (int i = 0; i < n; i++) {
        countChilds[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        countChilds[parents[i]]++;
    }

    bool check = true;
    for (int i = 0; i < n; i++) {
        if ((countChilds[i] > 2 || countChilds[i] == 1)) {
            //cout << i << " " << countChilds[i] << endl;
            check = false;
            break;
        }
    }

    if (check) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}