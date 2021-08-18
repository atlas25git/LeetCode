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

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
         //The number of rooms required will be the maximum sum of plotted
        //time stamps with +1/-1 in timeline for given activites
        map<int,int> map;

        for(auto x:intervals)
            map[x.start]++,map[x.end]--;
        int res=0;
        int rooms = 0;

        for(auto x : map)
        {
            res = max(res,rooms+=x.second);
        }
        return res;
    }
};