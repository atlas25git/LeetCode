class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        //simple priority schduling algorithm with preemption there by maintaing a 
        //current buffer which sorts tasks as per the assigned priority.
        //sorting acc to start time
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int res = 0;
        int day = 0;
        int i = 0;
        int n = size(events);
        
        while(i<n || pq.size())
        {
            if(pq.size() == 0)
                    day = events[i][0];
            
            //inserting all the jobs available
            while(i<n && events[i][0] == day)
                    pq.push(events[i++][1]);
            //atteding the earliest ending event
            pq.pop();
            res++;
            day++;
            //removing the ones which can't be attended now
            
            while(pq.size() && pq.top()<day)pq.pop();
        }
        
        return res;
    }
};