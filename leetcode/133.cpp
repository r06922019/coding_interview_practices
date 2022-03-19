/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    unordered_map<Node *, Node *> node_table = {{nullptr, nullptr}};
    Node *cloneGraph(Node *node)
    {
        Node *new_node;
        auto it = node_table.find(node);
        if (it == node_table.end())
        {
            new_node = new Node(node->val);
            node_table[node] = new_node;
            for (auto n : node->neighbors)
            {
                new_node->neighbors.push_back(cloneGraph(n));
            }
        }
        else
        {
            new_node = node_table[node];
        }
        return new_node;
    }
};