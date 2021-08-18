class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    int l = 0;
    int r = arr.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (arr[m] - (m + 1) >= k)
        r = m;
      else
        l = m + 1;
    }
    return l + k;
  }
};

class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    unordered_set<int> s(begin(arr), end(arr));
    for (int i = 1; i <= arr.back(); ++i) {
      if (!s.count(i)) --k;
      if (k == 0) return i;
    }
    return arr.back() + k;
  }
};

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
    static bool cmp(Interval a,Interval b)
    {
        if(a.end == b.end)return a.start>b.start;
        return a.end<b.end;
    }

    int minMeetingRooms(vector<Interval> &intervals) {
        
        
        sort(intervals.begin(),intervals.end(),cmp);
        for(auto x:intervals)cout<<x.start<<" "<<x.end<<endl;
        int count=1;

        int end = intervals[0].end;

        for(int i=1;i<intervals.size();i++)
            {
                if(intervals[i].start < end)
                        count++;
                end = intervals[i].end;
            }

    return count;
    }
};