class Project {
public:
    int capital, profit;
    Project(int _c, int _p){
        capital = _c;
        profit = _p;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<Project> projects;
        for(int i = 0; i < profits.size(); ++i) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end(), [](const Project &a, const Project &b) {
            return (a.capital < b.capital) || (a.capital == b.capital && a.profit > b.profit);
        });

        int index = 0;
        auto comp = [](const Project &a, const Project &b) {
            return a.profit < b.profit;
        };
        priority_queue<Project, vector<Project>, decltype(comp)> pq(comp);
        for(int i = 0; i < k; ++i) {
            while(index < projects.size() && projects[index].capital <= w) {
                pq.push(projects[index]);
                ++index;
            }
            if(pq.size()) {
                auto project = pq.top();
                pq.pop();
                w += project.profit;
            }
            else {
                break;
            }
        }
        return w;
    }
};