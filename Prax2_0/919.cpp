class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &iv) {
        //Sorting acc to start time
        sort(iv.begin(),iv.end(),[](Interval a, Interval b){
            if(a.start == b.start)return a.end<b.end;
            else return a.start<b.start;
            });

        auto cmp = [](Interval a,Interval b){
            if(a.end == b.end)return a.start>b.start;
            else return a.end>b.end;
        };

        priority_queue<Interval,vector<Interval>,decltype(cmp)> pq(cmp);
        pq.push(iv[0]);
        int rooms = 1;
        for(int i=1;i<iv.size();i++)
        {
            if(pq.top().end<iv[i].start)
                {pq.pop();}
            else rooms++;
            pq.push(iv[i]);
        }
        return rooms;
    }
};