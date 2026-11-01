class Solution {
public:
    void build_graph(vector<vector<int>>& graph, const vector<vector<int>>& edges){
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    void dfs(const vector<vector<int>>& graph, int v, unordered_set<int>& visited){
        for(int u : graph[v]){
            if(visited.find(u) == visited.end()){
                visited.insert(u);
                dfs(graph,u,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = 0;
        vector<vector<int>> graph(n);
        build_graph(graph,edges);
        unordered_set<int> visited;
        for(int i = 0; i < graph.size(); i++){
            if(visited.find(i) == visited.end()){
                res++;
                visited.insert(i);
                dfs(graph,i,visited);
            }
        }
        return res;
    }
    // time complexity - O(V+E)
    // space complexity - O(V+E)
};
