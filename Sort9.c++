#include <iostream>
#include <stack>
#include <vector>
#define MAX_SIZE 10000
using namespace std;

int hIndex(vector<int>& c) {
    int n = c.size();
    vector <int> bucket(n + 1);
    for(int i = 0; i < n; i++){
        int x = c[i];
        if(x >= n){
            bucket[n]++;
        } else {
            bucket[x]++;
        }
    }
    int cnt = 0;
    for(int i = n; i >= 0; i--){
        cnt += bucket[i];
        if(cnt >= i)return i;
    }
    return -1;
}
int main() {
    vector<int> vec;
    int n, count = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    int result = hIndex(vec);
    cout << result << endl;
}