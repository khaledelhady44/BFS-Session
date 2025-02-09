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
vector<int> vis, indegree, topo;

void bfs() {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            vis[i] = 1;
        }
    }


    while (!q.empty()) {
        int cur = q.top();
        q.pop();

        topo.push_back(cur);


        for (auto ch: graph[cur]) {
            if (!vis[ch]) {
                indegree[ch]--;
                if (indegree[ch] == 0) {
                    q.push(ch);
                    vis[ch] = 1;
                }
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
    indegree.resize(n+1);


    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }


    bfs();

    if (topo.size() < n) {
        cout << "Sandro fails." << endl;
    } else {
        for (auto i : topo) {
            cout << i << " ";
        }
    }
}

