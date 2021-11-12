#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int *parents = new int[n];
    int *childs = new int[n];
    int *countChilds = new int[n + 1];

    int edge = n - 1;

    for (int i = 0; i < edge; i++) {
        cin >> parents[i] >> childs[i];
    }

    for (int i = 0; i < n; i++) {
        countChilds[i] = 0;
    }
    for (int i = 0; i < edge; i++) {
        countChilds[parents[i]]++;
    }

    bool check = true;
    int nodeBottomStart = (n) / 2;
    for (int i = nodeBottomStart; i <= n; i++) {
            if (countChilds[i] > 0) {
                check = false;
                break;
            }
        }

    if (check) cout << "yes" << endl;
    else cout << "no" << endl;
    

    return 0;
}