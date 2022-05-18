class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dfn = vector<int>(n, -1);
        low = vector<int>(n, -1);
        visited = vector<bool>(n, false);
        connectTo = vector<vector<int>>(n);
        time = 0;
        for (vector<int> connection : connections) {
            connectTo[connection[0]].push_back(connection[1]);
            connectTo[connection[1]].push_back(connection[0]);
        }
        tarjan(0, -1);
        return ans;
    }

private:
    int time;
    vector<int> dfn;
    vector<int> low;
    vector<bool> visited;
    vector<vector<int>> connectTo;
    vector<vector<int>> ans;

    void tarjan(int node, int parent) {
        time++;
        dfn[node] = time;
        low[node] = time;
        visited[node] = true;
        for (int adjacentNode : connectTo[node]) {
            if (!visited[adjacentNode]) {
                tarjan(adjacentNode, node);
                low[node] = min(low[node], low[adjacentNode]);
                if (low[adjacentNode] > dfn[node])
                    ans.push_back({node, adjacentNode});
            }
            else {
                if (adjacentNode == parent)
                    continue;
                low[node] = min(low[node], dfn[adjacentNode]);
            }
        }
    }
};