#include <iostream>
using namespace std;

#define INT_MAX 99999999;
int n = 4;
//mang sau de luu khoang cach giua cac dinh
int dist[1000][1000];
//mang sau de luu cac khoang cach da duoc tinh truoc (quy hoach dong):
int tempDist[1000][1000];
//string luu tien trinh di:
int path[1000][1000];
int VISITED_ALL = (1 << n) - 1;
int start;

int TSP(int mask, int pos) {
    //neu da tham het cac dinh thi return:
    if (mask == VISITED_ALL) {
        return dist[pos][0];
    }

    //neu khoang cach da duoc tinh truoc thi tai su dung:
    if (tempDist[mask][pos] != -1) {
        return tempDist[mask][pos];
    }

    int minWeight = INT_MAX;
    int minPos = INT_MAX;
    //dung for de tim den nhung dinh chua duoc tham
    for (int i = 0; i < n; i++) {
        //neu chua dinh chua duoc tham thi:
        if ((mask & (1 << i)) == 0) {
            int newWeight = dist[pos][i] + TSP(mask | (1 << i), i);
            if (minWeight > newWeight) {
                minWeight = newWeight;
                minPos = i;
            }
        }
    }
    //luu vi tri cac dinh de quang duong ngan nhat
    path[mask][pos] = minPos;

    return tempDist[mask][pos] = minWeight;
}
//ham chay sau khi da tinh duoc TSP
void showPath_TSP(int mask, int pos) {
    if (pos == start) {
        cout << "(" << start << ") -> ";
    }
    if (path[mask][pos] != -1) {
        int minPos = path[mask][pos];
        cout << "(" << minPos << ") " << "-> ";
        showPath_TSP(mask | (1 << minPos), minPos);
    } else {
        cout << "return (" << start << ") ";
    }
}

int main() {
    //du lieu vao:
    cin >> n >> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    VISITED_ALL = (1 << n) - 1;
    //khoi tao 1 mang ban luu khoang cach da duoc tinh, gia tri ban dau la -1
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            tempDist[i][j] = -1;
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            path[i][j] = -1;
        }
    }

    cout << "The distance: " << TSP(1, start) << endl;
    cout << "The path: ";
    showPath_TSP(1, start);

    cout << endl;
    return 0;
}
