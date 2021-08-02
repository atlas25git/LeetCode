class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> count(26);
        for(auto x: tasks)count[x-'A']++;
        
        sort(count.begin(),count.end());
        
        int fmax = count[25];
        int idle = (fmax-1)*n;
        
        for(int i=count.size()-2;i>-1;i--)
        {
            if(idle<0)return tasks.size();
            if(fmax-1>count[i])
                idle-=count[i];
            //the time which rate determiner would require
            //-1 because it'll have n-1 b/w n subsequent executions
            //others will accomodate in b/w but this one won't
            else idle -= fmax -1;
        }
        // int j(0);
        // cout<<j<<endl;
        return idle+tasks.size();
    }
};