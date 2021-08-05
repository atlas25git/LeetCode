class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        //building a freq array
        vector<int> freq(26,0);
        for(auto x: tasks)freq[x-'A']++;
        
        //sorting
        sort(freq.begin(),freq.end());
        
        //calcualting the idle time max as it'll be for the one 
        //with highest freq element
        //freq@highest - 1 becoz idle time is b/w 2 same tasks
        
        int idle = (freq[25]-1)*n;
        
        for(int i = 24;i>-1;i--)
        {
            //min for the case where 2 tasks in same freq are present
            //thus for this we need to substract n-1 not n
            //as latter would count the idle time of last interval which is 
            //not considered
            idle -= min(freq[i],freq[25]-1);
        }
        
        idle = idle>0?idle:0;
        return idle+tasks.size();
        
    }
};

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