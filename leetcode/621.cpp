class Task{
public:
    int next_valid_time;
    char name;
    Task(int _next_valid_time, char _name) {
        next_valid_time = _next_valid_time;
        name = _name;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counter;
        for(auto &task : tasks) {
            ++counter[task];
        }

        auto comp = [](const Task &a, const Task &b) {
            return a.next_valid_time > b.next_valid_time ||
                (a.next_valid_time == b.next_valid_time && a.name > b.name);
        };
        priority_queue<Task, vector<Task>, decltype(comp)> time_pq(comp);

        auto comp1 = [&](const Task &a, const Task &b) {
            return counter[a.name] < counter[b.name] ||
                (counter[a.name] == counter[b.name] && a.name > b.name);
        };
        priority_queue<Task, vector<Task>, decltype(comp1)> valid_pq(comp1);

        int cur_time = 0;
        for(auto &p : counter) {
            time_pq.push({0, p.first});
        }
        while(counter.size()) {
            if(valid_pq.empty())
                cur_time = max(cur_time, time_pq.top().next_valid_time);
            while(time_pq.size() && time_pq.top().next_valid_time <= cur_time) {
                auto top = time_pq.top();
                time_pq.pop();
                valid_pq.push(top);
            }
            auto top = valid_pq.top();
            valid_pq.pop();
            // printf("cur_time %d: %c\n", cur_time, top.name);
            --counter[top.name];
            ++cur_time;
            // printf("%d to go\n", counter[top.name]);
            if(counter[top.name] > 0) {
                time_pq.push({cur_time+n, top.name});
            }
            else {
                counter.erase(top.name);
            }
        }
        return cur_time;
    }
};