/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    std::map<int, UndirectedGraphNode*> m;
    queue<UndirectedGraphNode*> q;

    q.push(node);

    while (!q.empty()) {
        auto n = q.front();
        q.pop();

        UndirectedGraphNode* new_node = nullptr;

        if (m.find(n->label) == m.end()) {
            // not exist in map
            new_node = new UndirectedGraphNode(n->label);
            m[n->label] = new_node;
        } else {
            // exist in map
            new_node = m[n->label];
        }

        for (auto neighbor: n->neighbors) {
            if (m.find(neighbor->label) == m.end()) {
                // not exist in map
                m[neighbor->label] = new UndirectedGraphNode(neighbor->label);
                new_node->neighbors.push_back(m[neighbor->label]);

                q.push(neighbor);
            } else {
                // exist in map
                new_node->neighbors.push_back(m[neighbor->label]);
            }
        }
    }

    return m[node->label];
}

