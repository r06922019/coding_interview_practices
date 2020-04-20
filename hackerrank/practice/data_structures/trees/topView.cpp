// level bfs
void topView(Node * root) {
    if(root == nullptr) return ;
    map<int, int> result;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        for(int i = 0, q_size = q.size(); i < q_size; ++i) {
            pair<Node *, int> p = q.front();
            q.pop();
            Node *cur = p.first;
            int index = p.second;
            if(result.find(index) == result.end()) {
                result[index] = cur->data;
            }
            if(cur->left) {
                q.push({cur->left, index-1});
            }
            if(cur->right) {
                q.push({cur->right, index+1});
            }
        }
    }

    // print
    for(auto &it : result) {
        printf("%d ", it.second);
    }
    printf("\n");
    return;
}
