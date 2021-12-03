class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<bool> vi(n, false);
        vector<int> disc(n, 0), low(n, 0), parent(n, -1);
        vector<vector<int>> g(n, vector<int>()), res;
        for (auto& p : connections) {
            g[p.front()].push_back(p.back());
            g[p.back()].push_back(p.front());
        }
        for (int i = 0; i < n; ++i) {
            if (vi[i]) continue;
            h(i, vi, disc, low, parent, g, res);
        }
        return res;
    }

    void h(int u, vector<bool>& vi, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& g, vector<vector<int>>& res) {
        static int time = 0;
        vi[u] = true;
        disc[u] = low[u] = ++time;
        for (int v : g[u]) {
            if (!vi[v]) {
                parent[v] = u;
                h(v, vi, disc, low, parent, g, res);
                low[u] = min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    res.push_back({u, v});
                }

            } else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }

        }
    }

};