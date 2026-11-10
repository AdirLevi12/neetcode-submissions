class Solution {
public:
    void build_graph(const vector<vector<int>>& prerequisites, vector<vector<int>>& graph, vector<int>& in_degree){
        for(auto& edge: prerequisites){
            graph[edge[1]].push_back(edge[0]);
            in_degree[edge[0]]++;
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses);
        build_graph(prerequisites, graph, in_degree);
        queue<int> q;

        
        for(int i = 0; i < in_degree.size(); i++){
            if(in_degree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int v = q.front();
            q.pop();
            res.push_back(v);
            for(int u : graph[v]){
                in_degree[u]--;
                if(in_degree[u] == 0){
                    q.push(u);
                }
            }
        }
        vector<int> empty;
        return res.size() == numCourses ? res : empty;
    }
};
