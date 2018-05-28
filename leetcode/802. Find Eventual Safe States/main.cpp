//https://leetcode.com/problems/find-eventual-safe-states/description/
/*
In a directed graph, we start at some node and every turn, walk along a directed edge of the graph.
If we reach a node that is terminal (that is, it has no outgoing directed edges), we stop.

Now, say our starting node is eventually safe
if and only if we must eventually walk to a terminal node.
More specifically, there exists a natural number K so that for any choice of where to walk,
we must have stopped at a terminal node in less than K steps.

Which nodes are eventually safe?  Return them as an array in sorted order.

The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the length of graph.
The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph.

Example:
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Here is a diagram of the above graph.

Illustration of graph

Note:
graph will have length at most 10000.
The number of edges in the graph will not exceed 32000.
Each graph[i] will be a sorted list of different integers, chosen within the range [0, graph.length - 1].
*/

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {


    public:
    // topological sorting with dp
    bool dfs(vector<vector<int>>& graph, vector<int> &dp, int src) {
        if (dp[src])
            return 1 == dp[src];

        dp[src] = -1; // by default mark it as "cannnot be topologically sorted"
        for (auto node : graph[src])
            if (false == dfs(graph, dp, node))
                return false;
        return dp[src] = true; // next node with zero outdegree
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int total_nodes = graph.size();
        vector<int> result, dp(total_nodes, 0);
        for (int i = 0; i < total_nodes; i++)
            if (dfs(graph, dp, i))
                result.push_back(i);

        return result;
    }
};

int main()
{
    vector<vector<int>> graph = { {1,2},{2,3},{5},{0},{5},{},{} };
    auto result = Solution().eventualSafeNodes(graph);
    for (auto i : result) {
        
    }
    return 0;
}