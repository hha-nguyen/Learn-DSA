#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <list>
#include <vector>
#include <set>
#include <iterator>
using namespace std;

template <typename T>
class Graph {
    unordered_map <T, list <pair<T, int>>> map;

    public:
        void addEdge(T u, T v, int dist, bool bidir = true) {
            map[u].push_back(make_pair(v, dist));
            if (bidir) {
                map[v].push_back(make_pair(u, dist));
            }
        }
        void printAdj() {
            for (auto node : map) {
                cout << node.first << " -> ";
                for (auto neighbor : node.second) {
                    cout << neighbor.first << "(";
                    cout << neighbor.second << ") ";
                }
                cout << endl;
            }
        }
        void dijsktraSSP(T src, T des) {
            unordered_map <T, int> dist;

            for (auto item : map) {
                dist[item.first] = INT8_MAX;
            }

            set <pair<int, T>> s;
            dist[src] = 0;
            s.insert(make_pair(0, src));

            while (!s.empty()) {
                auto p = *(s.begin());
                T node = p.second;
                int nodeDist = p.first;
                s.erase(s.begin());

                for (auto neighbor : map[node]) {
                    if (nodeDist + neighbor.second < dist[neighbor.first]) {
                        T dest = neighbor.first;
                        auto f = s.find(make_pair(dist[dest], dest));
                        if (f != s.end()) {
                            s.erase(f);
                        }
                        dist[dest] = nodeDist + neighbor.second;
                        s.insert(make_pair(dist[dest], dest));
                    }
                }
            }

            for (auto item : dist) {
                if (item.first == des) {
                    cout << item.second << endl;
                    break;
                }
            }
        }
};

int main() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    Graph<int> graph;
    int k = M;
    while (k > 0) {
        k--;
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w, true);
    }

    graph.dijsktraSSP(s, t);

    return 0;
}