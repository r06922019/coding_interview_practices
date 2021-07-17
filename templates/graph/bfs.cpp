/**
 * Return the length of the shortest path between root and target node.
 */
int BFS(Node root, Node target) {
    Queue<Node> queue;  // store all nodes which are waiting to be processed
    int step = 0;       // number of steps neeeded from root to current node
    // initialize
    add root to queue;
    // BFS
    while (queue is not empty) {
        step = step + 1;
        // iterate the nodes which are already in the queue
        int size = queue.size();
        for (int i = 0; i < size; ++i) {
            Node cur = the first node in queue;
            return step if cur is target;
            for (Node next : the neighbors of cur) {
                add next to queue;
            }
            remove the first node from queue;
        }
    }
    return -1;          // there is no path from root to target
}

class Solution {
public:
    void enqueue_if_unvisited(queue<string> &q, unordered_set<string> &visited, string &s) {
        if(visited.find(s) == visited.end()) {
            q.push(s);
            visited.insert(s);
        }
    }

    void enqueue_if_unvisited(queue<string> &q, unordered_set<string> &visited, string &&s) {
        if(visited.find(s) == visited.end()) {
            q.push(s);
            visited.insert(s);
        }
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<string> q;

        int steps = 0;
        enqueue_if_unvisited(q, visited, "0000");
        while(q.size()) {
            int q_size = q.size();
            while(q_size--) {
                string cur = q.front();
                q.pop();
                if(cur == target) return steps;
                for(int i = 0; i < 4; ++i) {
                    int cur_digit = cur[i] - '0';

                    cur[i] = ((cur_digit+1) % 10) + '0';
                    enqueue_if_unvisited(q, visited, cur);

                    cur[i] = ((cur_digit+9) % 10) + '0';
                    enqueue_if_unvisited(q, visited, cur);

                    cur[i] = cur_digit + '0';
                }
            }
            ++steps;
        }
        return -1;
    }
};