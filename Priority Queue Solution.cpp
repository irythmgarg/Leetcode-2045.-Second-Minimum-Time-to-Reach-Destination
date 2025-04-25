/*
    Problem: Find the second minimum time to reach from node 1 to node n in a graph,
    where each edge takes a fixed amount of time, and you can only travel during green lights
    (green/red cycle is defined by 'change').

    Idea:
    - Use modified Dijkstra's algorithm with priority queue.
    - Maintain two shortest arrival times per node: `small` and `small2`.
    - While traversing, account for traffic light delays before moving to neighbors.
*/

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        using pii = pair<int, int>;

        // Build the adjacency list for the undirected graph
        unordered_map<int, vector<int>> mp;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        // Min heap to process (arrival time, node)
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        // Stores the shortest and second shortest arrival times to each node
        vector<int> small(n + 1, INT_MAX);
        vector<int> small2(n + 1, INT_MAX);

        // Start from node 1 at time 0
        pq.push({0, 1});
        small[1] = 0;

        while (!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();

            // Calculate waiting time due to red light
            int phase = currTime / change;
            if (phase % 2 != 0) {
                // Wait till the start of next green
                currTime = (phase + 1) * change;
            }

            // Traverse neighbors
            for (int neighbor : mp[node]) {
                int nextTime = currTime + time;

                // If it's the first shortest time to this neighbor
                if (nextTime < small[neighbor]) {
                    small2[neighbor] = small[neighbor];
                    small[neighbor] = nextTime;
                    pq.push({nextTime, neighbor});
                }
                // If it's the second shortest and not equal to the shortest
                else if (nextTime > small[neighbor] && nextTime < small2[neighbor]) {
                    small2[neighbor] = nextTime;
                    pq.push({nextTime, neighbor});
                }
            }
        }

        // Return the second minimum time to reach node n
        return small2[n];
    }
};
