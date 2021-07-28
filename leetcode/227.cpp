class Solution {
public:
    void do_op(stack<int> &numbers, stack<char> &ops) {
        char op = ops.top();
        ops.pop();
        int b = numbers.top();
        numbers.pop();
        int a = numbers.top();
        numbers.pop();
        if(op == '+') {
            numbers.push(a+b);
        }
        else if(op == '-') {
            numbers.push(a-b);
        }
        else if(op == '*') {
            numbers.push(a*b);
        }
        else if(op == '/') {
            numbers.push(a/b);
        }
    }

    int calculate(string s) {
        s += " ";
        stack<int> numbers;
        stack<char> ops;
        unordered_map<char, int> priority = {
            {'+', 0}, {'-', 0},
            {'*', 1}, {'/', 1}
        };
        string number = "";
        for(auto &c : s) {
            // printf("%c\n", c);
            if(isdigit(c)) {
                number += c;
            }
            else {
                if(number.size()) {
                    numbers.push(stoi(number));
                    // printf("top : %d\n", numbers.top());
                    number = "";
                }
                if(priority.find(c) != priority.end()) {
                    while(ops.size() && priority[ops.top()] >= priority[c]) {
                        do_op(numbers, ops);
                    }
                    ops.push(c);
                }
            }
        }
        while(ops.size()) {
            do_op(numbers, ops);
        }
        return numbers.top();
    }
};