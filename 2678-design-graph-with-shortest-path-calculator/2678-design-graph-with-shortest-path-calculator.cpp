class Graph {
public:
    unordered_map<int ,vector<pair<int,int>>>mp;
    int N;
    vector<int> result;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    Graph(int n, vector<vector<int>>& edges) {
        N=n;
        for(vector<int> &vec:edges){
            int from = vec[0];
            int to = vec[1];
            int wt = vec[2];

            mp[from].push_back({to,wt});

        }
    }
    
    void addEdge(vector<int> edge) {
        mp[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
vector<int> result(N, INT_MAX);

		result[node1] = 0;
		pq.push({0, node1});

		while(!pq.empty()) {

		    int d  = pq.top().first;
		    int node = pq.top().second;
		    pq.pop();

		    for(auto &vec : mp[node]) {

			int adjNode = vec.first;
			int dist    = vec.second;

			if(d + dist < result[adjNode]) {

			    result[adjNode] = d + dist;
			    pq.push({d+dist, adjNode});

			}

		    }

		}
        
        return result[node2] == INT_MAX ? -1 : result[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */