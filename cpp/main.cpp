#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<string, vector<pair<string, double>>> adj;

    void addEdge(const string &u, const string &v, double w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void dijkstra(const string &source, const string &destination) {
        if (!adj.count(source) || !adj.count(destination)) {
            cout << "\nError: One or both locations do not exist.\n";
            return;
        }

        unordered_map<string, double> dist;
        unordered_map<string, string> parent;

        for (auto &p : adj) dist[p.first] = DBL_MAX;
        dist[source] = 0;

        using P = pair<double, string>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0.0, source});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            double currDist = top.first;
            string currNode = top.second;

            if (currDist > dist[currNode]) continue;

            for (auto &edge : adj[currNode]) {
                string next = edge.first;
                double weight = edge.second;

                if (dist[currNode] + weight < dist[next]) {
                    dist[next] = dist[currNode] + weight;
                    parent[next] = currNode;
                    pq.push({dist[next], next});
                }
            }
        }

        if (dist[destination] == DBL_MAX) {
            cout << "\nNo path found.\n";
            return;
        }

        vector<string> path;
        string cur = destination;
        while (true) {
            path.push_back(cur);
            if (cur == source) break;
            cur = parent[cur];
        }
        reverse(path.begin(), path.end());

        cout << "\nShortest Distance: " << dist[destination] << " minutes\n";
        cout << "Path: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i + 1 < path.size()) cout << " -> ";
        }
        cout << "\n";
    }
};

int main() {

    Graph g;

    g.addEdge("B1", "G2", 3);
    g.addEdge("G2", "LHC1", 5);
    g.addEdge("G2", "LHC2", 15);
    g.addEdge("G2", "Veg Mess", 2);
    g.addEdge("G2", "NonVeg Mess", 4);
    g.addEdge("G2", "Sports Complex", 10);
    g.addEdge("G2", "Main Gate", 20);
    g.addEdge("G2", "Library", 10);

    g.addEdge("B1", "LHC1", 3);
    g.addEdge("B1", "LHC2", 18);
    g.addEdge("B1", "Veg Mess", 5);
    g.addEdge("B1", "NonVeg Mess", 2);
    g.addEdge("B1", "Sports Complex", 15);
    g.addEdge("B1", "Main Gate", 17);
    g.addEdge("B1", "Library", 7);

    g.addEdge("Main Gate", "Library", 13);
    g.addEdge("Library", "LHC1", 5);
    g.addEdge("LHC1", "LHC2", 12);
    g.addEdge("Library", "NonVeg Mess", 10);
    g.addEdge("Library", "Veg Mess", 13);

    g.addEdge("Veg Mess", "Sports Complex", 8);
    g.addEdge("NonVeg Mess", "Sports Complex", 11);
    g.addEdge("Veg Mess", "Main Gate", 22);
    g.addEdge("NonVeg Mess", "Main Gate", 19);

   
        cout << R"(
=====================================================================
                       IIT JODHPUR - CAMPUS MAP
           (Distances shown in minutes of walking approximation)
=====================================================================


                               [ LHC2 ]
                                   |
                                 (15)
                                   |
                                 [ G2 ]
                     /       |         |        \ 
                  (3)       (5)       (4)      (10)
                 /          |         |         \
              [ B1 ]      [ LHC1 ]  [NonVeg]   [ Sports ]
                 |           |        Mess      Complex
                (7)         (3)       |           |
                 |           |        |           |
             [ Library ]     |        |           |
                 |           |       (3)          |
               (13)          |        |           |
                 |           |        |           |
             [ Main Gate ]   |      [ Veg Mess ]  |
                 |           |                    |
                (17)         |                    /
                 |           |                   /
                [ B1 ] ------+--------(15)-------



)";

    cout << "================ IITJ Campus Navigation System ================\n";

    cout << "\nAvailable Locations:\n";
    vector<string> locs;
    for (auto &kv : g.adj) locs.push_back(kv.first);
    sort(locs.begin(), locs.end());
    for (auto &s : locs) cout << " - " << s << "\n";

    cout << "\nEnter source: ";
    string source;
    getline(cin, source);

    cout << "Enter destination: ";
    string destination;
    getline(cin, destination);

    g.dijkstra(source, destination);

    return 0;
}
