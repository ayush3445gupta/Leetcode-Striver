class Solution {
public:
// i have to detect whether a cycle is present or not
// if it is cyclic then return false
// using TOPO SORT for DAG
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
   vector<vector<int>>adj(numCourses);
    for(auto it:prerequisites)adj[it[0]].push_back(it[1]);

   		vector<int>indegree(numCourses,0);
		for (int i = 0; i < numCourses; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < numCourses; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		if (topo.size() == numCourses) return true;
		return false;


	}
int main(){
    return 0;
}
};