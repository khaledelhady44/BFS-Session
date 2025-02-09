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
vector<int> vis, levels, traversal_order;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    levels[start] = 0;


    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        traversal_order.push_back(cur);


        for (auto ch: graph[cur]) {
            if (!vis[ch]) {
                q.push(ch);
                vis[ch] = 1;
                levels[ch] = levels[cur] + 1;
            }
        }
    }



}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    graph.resize(n+1);
    vis.resize(n+1);
    levels.resize(n+1);


    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    bfs(1);

    for (auto i: traversal_order) {
        cout << i << " ";
    }
}

