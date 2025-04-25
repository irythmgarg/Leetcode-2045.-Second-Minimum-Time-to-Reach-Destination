class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        using p = pair<int, int>;  // Pair of (time, node)
        
        // Build undirected graph using adjacency list
        unordered_map<int, vector<int>> mp;
        for (auto edge : edges) {
            int from = edge[0];
            int to = edge[1];
            mp[from].push_back(to);
            mp[to].push_back(from);
        }

        // Queue for BFS traversal storing (time, node)
        queue<p> q;
        q.push({0, 1});  // Start from node 1 at time 0

        // Vectors to store the shortest and second shortest arrival times
        vector<int> small(n + 1, INT_MAX);   // shortest time to reach each node
        vector<int> small2(n + 1, INT_MAX);  // second shortest time to reach each node
        small[1] = 0;  // shortest time to reach node 1 is 0

        while (!q.empty()) {
            int s = q.size();

            // Process all nodes at the current BFS level
            while (s--) {
                auto top = q.front(); q.pop();
                int timetill = top.first;
                int node = top.second;

                // Handle red light waiting time
                int div = timetill / change;
                if (div % 2 != 0) {
                    // If currently in a red light interval, wait until it turns green
                    timetill = (div + 1) * change;
                }

                // Traverse all neighbors
                for (int neighbor : mp[node]) {
                    int arrival = timetill + time;  // time to reach neighbor

                    // If this is the shortest time to reach neighbor
                    if (arrival < small[neighbor]) {
                        small2[neighbor] = small[neighbor];
                        small[neighbor] = arrival;
                        q.push({arrival, neighbor});
                    }
                    // If this is the second shortest (and distinct) time
                    else if (arrival < small2[neighbor] && arrival != small[neighbor]) {
                        small2[neighbor] = arrival;
                        q.push({arrival, neighbor});
                    }
                }
            }
        }

        // Return the second shortest time to reach the destination node n
        return small2[n];
    }
};
