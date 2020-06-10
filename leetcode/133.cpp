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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        Node *start = new Node(node->val);
        unordered_map<int, vector<int>> id_to_neighbors;
        unordered_map<int, Node*> id_to_new_nodes = {{node->val, start}};

        stack<Node *> st;
        vector<bool> visited(101, false);

        visited[node->val] = true;
        st.push(node);

        while(st.size()) {
            Node *old_node = st.top();
            st.pop();

            int cur_id = old_node->val;
            if(id_to_new_nodes.find(cur_id) == id_to_new_nodes.end()) {
                id_to_new_nodes[cur_id] = new Node(cur_id);
            }
            for(auto &next : old_node->neighbors) {
                int &next_id = next->val;
                id_to_neighbors[cur_id].push_back(next_id);
                if(!visited[next_id]) {
                    visited[next_id] = true;
                    st.push(next);
                }
            }
        }

        for(auto &it : id_to_neighbors) {
            int node_id = it.first;
            for(int &neigh_id : it.second) {
                Node *neigh_node = id_to_new_nodes[neigh_id];
                id_to_new_nodes[node_id]->neighbors.push_back(neigh_node);
            }
        }
        return start;
    }
};