class Solution {
public:
    void perform(stack<int> &num_stack, stack<char> &op_stack) {
        int b = num_stack.top();
        num_stack.pop();
        int a = num_stack.top();
        if(op_stack.top() == '+') {
            num_stack.top() = (a+b);
        }
        else if(op_stack.top() == '-') {
            num_stack.top() = (a-b);
        }
        else if(op_stack.top() == '*') {
            num_stack.top() = (a*b);
        }
        else if(op_stack.top() == '/') {
            num_stack.top() = (a/b);
        }
        op_stack.pop();

        return ;
    }

    int calculate(string s) {
        unordered_map<char, int> priority = {
            {'+', 0},
            {'-', 0},
            {'*', 1},
            {'/', 1},
        };

        stack<int> num_stack;
        stack<char> op_stack;
        int num = 0, i = 0;
        while(i < s.size()) {
            char &c = s[i];
            if(isdigit(c)) {
                while(i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                num_stack.push(num);
                num = 0;
                --i;
            }
            else if(c == ')') {
                while(op_stack.size() && op_stack.top() != '(') {
                    perform(num_stack, op_stack);
                }
                op_stack.pop();
            }
            else if(c == '(') {
                op_stack.push(c);
            }
            else if(c != ' ') {
                while(op_stack.size() && op_stack.top() != '(' && priority[c] <= priority[op_stack.top()]) {
                    perform(num_stack, op_stack);
                }
                op_stack.push(c);
                printf("pushing %c\n", c);
            }
            ++i;
        }
        while(op_stack.size()) {
            perform(num_stack, op_stack);
        }
        return num_stack.top();
    }
};