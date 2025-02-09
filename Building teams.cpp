#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

vector<int> dx = {0, 0,  1, -1, -1, 1, 1, 1};
vector<int> dy = {1, -1, 0, 0, -1, 0, 1, -1};

#define int long long

int n, m;
vector<vector<int>> graph;
vector<int> vis, color;

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    color[start] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();


        for (auto ch: graph[cur]) {
            if (!vis[ch]) {
                q.push(ch);
                vis[ch] = 1;
                color[ch] = 3 - color[cur];
            } else {
                if (color[cur] == color[ch]) {
                    return false;
                }
            }
        }
    }

    return true;

}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    graph.resize(n+1);
    vis.resize(n+1);
    color.resize(n+1);

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool f = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            f &= bfs(i);
        }
    }

    if (!f) cout << "IMPOSSIBLE" << endl;
    else {
        for (int i = 1; i <= n; i++) {
            cout << color[i] << " ";
        }
    }
    
}

