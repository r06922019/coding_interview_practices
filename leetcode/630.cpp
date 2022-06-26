class Solution
{
public:
    int scheduleCourse(vector<vector<int> > &courses)
    {
        sort(courses.begin(), courses.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });
        priority_queue<int> duration_pq;
        int time = 0;
        for (auto course : courses)
        {
            if (time + course[0] <= course[1])
            {
                time += course[0];
                duration_pq.push(course[0]);
            }
            else if (duration_pq.size() && duration_pq.top() > course[0])
            {
                time -= duration_pq.top();
                duration_pq.pop();
                time += course[0];
                duration_pq.push(course[0]);
            }
        }
        return duration_pq.size();
    }
};