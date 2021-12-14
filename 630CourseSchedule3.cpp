class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        sort(courses.begin(), courses.end(), [](vector<int> &v1, vector<int> &v2){
            return v1[1] < v2[1];
        });
        
        priority_queue<int> que;
        int total = 0;
        for (auto &course : courses)
        {
            int duration = course[0], lastday = course[1];
            if (total + duration <= lastday)
            {
                total += duration;
                que.push(duration);
            }
            else if (!que.empty() && que.top() > duration)
            {
                total = total - que.top() + duration;
                que.pop(), que.push(duration);
            }
        }
        return que.size();
    }
};