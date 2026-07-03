class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n);

        int hi = 0;

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            indegree[e[1]]++;
            hi = max(hi, e[2]);
        }

        auto check = [&](int mid)->bool {

            vector<long long> dp(n, LLONG_MAX);
            queue<int> q;
            vector<int> deg = indegree;

            for (int i = 0; i < n; i++)
                if (deg[i] == 0)
                    q.push(i);

            dp[0] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (auto &[v, w] : adj[u]) {

                    if (--deg[v] == 0)
                        q.push(v);

                    if (w < mid) continue;

                    if (v != n - 1 && !online[v]) continue;

                    if (dp[u] == LLONG_MAX) continue;

                    dp[v] = min(dp[v], dp[u] + (long long)w);
                }
            }

            return dp[n - 1] <= k;
        };

        int lo = 0;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};