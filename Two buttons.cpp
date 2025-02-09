#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int n, m;
map<int, int> vis;
map<int, int> level;

int bfs(int root){
    queue<int> q;
    q.push(root);
    vis[root] = 1;
    level[root] = 0;

    while(!q.empty()){
        int cur = q.front();
        if(cur == m){
            return level[m];
        }
        q.pop();

        if(cur && !vis[cur - 1]){
            q.push(cur - 1);
            vis[cur - 1] = 1;
            level[cur - 1] = level[cur] + 1;
        }
        if(cur < m && !vis[cur*2]){
            q.push(cur*2);
            vis[cur*2] = 1;
            level[cur*2] = level[cur] + 1;
        }
    }


}



signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //    freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);

    cin >> n >> m;
    cout << bfs(n);

}