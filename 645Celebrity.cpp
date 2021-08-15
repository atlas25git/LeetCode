// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n) {
        // Write your code here
        //the main task here is to minimize the no of calls
        //this using moore's voting algorithm
        //starting from 0, naively checking the candidates known by 
        //former
        int candidate = 0;
        for(int i=1;i<n;i++)
            if(knows(candidate,i))
                candidate = i;
        
        //confirmatory step
        return check(candidate,n)?candidate:-1;
    }
    
    bool check(int candidate,int n)
    {
        for(int i=0;i<n;i++)
            {
                if(i==candidate)continue;
                if(knows(candidate,i) || !knows(i,candidate))
                    return false;
            }
        return true;
    }

};

class Solution {
public:
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    int findCelebrity(int n) {
        // Write your code here
    int candidate = 0;
        
        for(int i = 1; i < n; i++) {
            if(knows(candidate, i)) {
                candidate = i;
            }
        }
        
        return IsCelebrity(candidate, n) ? candidate : -1;
    }
    
    bool IsCelebrity(int candidate, int n) {
        for(int i = 0; i < n; i++) {
            if(i == candidate) continue;
            if(knows(candidate, i) || !knows(i, candidate)) return false;
        }
        
        return true;
    }
};