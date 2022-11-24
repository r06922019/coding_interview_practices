class Solution {
public:
    void do_ops(stack<int> &nums, stack<char> &ops) {
        char op = ops.top();
        ops.pop();
        int b = nums.top();
        nums.pop();
        int a = 0;
        if(op == '-') {
            if(nums.size()) {
                a = nums.top();
                nums.pop();
            }
        }
        else {
            a = nums.top();
            nums.pop();
        }
        // printf("%d%c%d\n", a, op, b);
        if(op == '+') {
            nums.push(a+b);
        }
        else if(op == '-') {
            nums.push(a-b);
        }
        else if(op == '*') {
            nums.push(a*b);
        }
        else if(op == '/') {
            nums.push(a/b);
        }
    }

    int calculate(string s) {
        unordered_map<char, int> priority = {
            {'(', -1},
            {'+', 0}, {'-', 0},
            {'*', 1}, {'/', 1}
        };

        s += " ";
        string num;
        stack<int> nums;
        stack<char> ops;
        for(auto &c : s) {
            // printf("%c\n", c);
            if(isdigit(c)) {
                num += c;
            }
            else {
                if(num.size()) {
                    nums.push(stoi(num));
                    printf("pushed %s\n", num);
                    num = "";
                }
                if(c == '(') {
                    ops.push(c); // (
                    printf("pushed (\n");
                }
                else if(c == ')') {
                    while(ops.top() != '(') {
                        do_ops(nums, ops);
                    }
                    ops.pop(); // (
                }
                else if(priority.find(c) != priority.end()) {
                    while(ops.size() && priority[ops.top()] >= priority[c]) {
                        do_ops(nums, ops);
                    }
                    ops.push(c);
                }
                else {
                    continue;
                }
            }
        }
        while(ops.size()) {
            do_ops(nums, ops);
        }
        return nums.top();
    }
};