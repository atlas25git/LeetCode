// TC:: Since heap operations hare logN and we do atmost N of those
//hence O(nlogn)
// SC:: O(n)
class Solution {
public:
    /**
     * @param sticks: the length of sticks
     * @return: Minimum Cost to Connect Sticks
     */
    int MinimumCost(vector<int> &sticks) {
        priority_queue<int,vector<int>,greater<int>> pq;

        for(auto x:sticks)pq.push(x);
        int c = 0;
        while(pq.size()!=1)
        {
            int a = pq.top();pq.pop();
            int b = pq.top();pq.pop();
            c += a+b;
            pq.push(a+b);
        }
        return c;
    }
};