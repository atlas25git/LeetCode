class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        // cout<<candidates.size()<<endl;
        int sum = accumulate(candidates.begin(),candidates.end(),0);
        if(sum<target || target<candidates.front())return res;
 
        if(candidates.front() == candidates.back() && target%candidates.front() == 0) 
        {res.push_back(vector<int>(target/candidates.front(),candidates.front()));
        return res;}
        
        vector<int> curr;
        fill(res,curr,0,candidates,target);
        if(res.size() == 0)return res;
        set<multiset<int>> s;
        for(auto x: res)
            s.insert(multiset<int>(x.begin(),x.end()));
        
        vector<vector<int>> res1;
        for(auto x: s)res1.push_back(vector<int>(x.begin(),x.end()));
        return res1;
    }
    void fill(vector<vector<int>>& res, vector<int> curr,int ind, vector<int>& cand,int target)
    {
        //base case
        if(!target)
        {   
            res.push_back(curr);
            return;
        }
        
        if(target<0 || ind>=cand.size())
                return;
        
        //Not Considering
        fill(res,curr,ind+1,cand,target);
        
        //considering elment at ind
        // if(find(curr.begin(),curr.end(),cand[ind])==curr.end())
            {curr.push_back(cand[ind]),
            fill(res,curr,ind+1,cand,target-cand[ind]);
        
        //backTrack
        curr.pop_back();
            }
    }
};


class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        // container to hold the final combinations
        List<List<Integer>> results = new ArrayList<>();
        LinkedList<Integer> comb = new LinkedList<>();

        HashMap<Integer, Integer> counter = new HashMap<>();
        for (int candidate : candidates) {
            if (counter.containsKey(candidate))
                counter.put(candidate, counter.get(candidate) + 1);
            else
                counter.put(candidate, 1);
        }

        // convert the counter table to a list of (num, count) tuples
        List<int[]> counterList = new ArrayList<>();
        counter.forEach((key, value) -> {
            counterList.add(new int[]{key, value});
        });

        backtrack(comb, target, 0, counterList, results);
        return results;
    }

    private void backtrack(LinkedList<Integer> comb,
                           int remain, int curr,
                           List<int[]> counter,
                           List<List<Integer>> results) {

        if (remain <= 0) {
            if (remain == 0) {
                // make a deep copy of the current combination.
                results.add(new ArrayList<Integer>(comb));
            }
            return;
        }

        for (int nextCurr = curr; nextCurr < counter.size(); ++nextCurr) {
            int[] entry = counter.get(nextCurr);
            Integer candidate = entry[0], freq = entry[1];

            if (freq <= 0)
                continue;

            // add a new element to the current combination
            comb.addLast(candidate);
            counter.set(nextCurr, new int[]{candidate, freq - 1});

            // continue the exploration with the updated combination
            backtrack(comb, remain - candidate, nextCurr, counter, results);

            // backtrack the changes, so that we can try another candidate
            counter.set(nextCurr, new int[]{candidate, freq});
            comb.removeLast();
        }
    }
}