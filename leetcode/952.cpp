class Solution {
public:
    vector<int> prime_list;

    void get_prime_list() {
        // int N = max_num + 1;
        int N = 1e5;
        int sqrt_n = ceil(sqrt(N));
        // printf("building table of size %d\n", N);
        vector<bool> table(N, true);
        table[0] = table[1] = false;

        for(int i = 4; i < N; i += 2)
            table[i] = false;

        for(int i = 3; i <= sqrt_n; i += 2) {
            if(table[i]) {
                for(int j = i*i; j < N; j += i) {
                    table[j] = false;
                }
            }
        }

        prime_list.push_back(2);
        for(int i = 3; i < N; i += 2)
            if(table[i])
                prime_list.push_back(i);

        // printf("finishing building table of size %d\n", prime_list.size());
        return ;
    }

    void factorize_num(int num, vector<int> &result, unordered_map<int, int> &parent) {
        // printf("factorizing %d\n", num);
        result.clear();
        for(int &p : prime_list) {
            if(num % p == 0) {
                result.push_back(p);
                while(num % p == 0) num /= p;
            }
            if(parent.find(num) != parent.end()) {
                result.push_back(num);
                num = 1;
            }
            if(num == 1) break;
        }
        // printf("finish factorizing %d, returning size = %d\n", num, result.size());
        return ;
    }

    int find_root(int group, unordered_map<int, int> &parent) {
        int root = parent[group];
        if(root != group) {
            root = find_root(root, parent);
        }
        parent[group] = root;
        return root;
    }

    void merge_group(int group1, int group2, unordered_map<int, int> &parent, unordered_map<int, int> &group_counts, int &max_val) {

        int root1 = find_root(group1, parent);
        int root2 = find_root(group2, parent);

        if(root1 != root2) {
            parent[root2] = root1;
            group_counts[root1] += group_counts[root2];
            max_val = max(max_val, group_counts[root1]);
            group_counts.erase(root2);
        }
        return ;
    }

    int largestComponentSize(vector<int>& A) {
        if(prime_list.empty()) get_prime_list();

        unordered_map<int, int> parent;
        for(int &p : prime_list) {
            parent[p] = p;
        }

        unordered_map<int, int> group_counts;

        int max_group_size = 0;
        vector<int> factors;
        for(int &num : A) {
            if(num == 1) {
                ++group_counts[1];
                max_group_size = max(max_group_size, group_counts[1]);
            }
            else {
                factorize_num(num, factors, parent);
                int root0 = find_root(factors[0], parent);
                ++group_counts[root0];
                max_group_size = max(max_group_size, group_counts[root0]);
                for(int i = 1; i < factors.size(); ++i) {
                    merge_group(factors[0], factors[i], parent, group_counts, max_group_size);
                }
            }
        }

        return max_group_size;
    }
};
