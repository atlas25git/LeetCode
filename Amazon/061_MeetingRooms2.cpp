/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

struct cmp{
    bool operator()(Interval a,Interval b)
    {
        if(a.end == b.end)return a.start>b.start;
        else return a.end>b.end;
    }
};

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */

    //The question is different from meeting rooms, there we'd
    //only one room, but here multiple rooms could be there and since 
    //we need to optimally track the earliest relived room, we use a min
    //heap with ending time.

    int minMeetingRooms(vector<Interval> &intervals) {
        if(intervals.size() == 0)return 0;
        
        auto cmp1 = [](Interval a,Interval b) -> bool
        {   
            //redundant as only ending time has to be seen
            if(a.end == b.end)return a.start<b.start;

            else return a.end>b.end;
        };
        priority_queue<Interval,vector<Interval>,decltype(cmp1)> pq(cmp1);
        
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b)
        {if(a.start == b.start)return a.end<b.end;
        else return a.start<b.start;});

        int rooms = 0;
        pq.push(intervals[0]);
        rooms++;

        for(int i=1;i<intervals.size();i++)
        {   
            //The condn is proved as there could be a state when
            //the earliest ending meeting is ending later than the starting of current meeting
            //but the current meeting ends prior to the former meeting in the queue.decltype
            //Hene justifies the use of priority queue.
            if(intervals[i].start < pq.top().end)
                rooms++;
            else pq.pop();
            pq.push(intervals[i]);
        }

        return rooms;
    }
};