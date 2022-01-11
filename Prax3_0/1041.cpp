class Solution {
    //     N
    // W       E
    //     S
public:
    bool isRobotBounded(string instructions) {
        int i=0,j=0,dir=0;
        
        // intitally taking our vector intialized as 0,0 and dir as N,represented by 0
        //N->0
        //E->1
        //S->2
        //W->3
        //R corresponds to E hence +1, and L corresponds to W hence +3
        
    //     W
    // S       N
    //     E
        
        for(auto c: instructions)
        {
            if(c == 'R')
            {
                dir = (dir+1)%4;
            }
            if(c == 'L')
                dir = (dir+3)%4;
            if(c== 'G')
            {
                int currDir = dir%4;
                if(currDir == 0)//N
                    i+=1;
                if(currDir == 1)//E
                    j-=1;
                if(currDir == 2)//S
                    i-=1;
                if(currDir == 3)//W
                    j+=1;
            }
        }
        
        
        if(dir || (!i && !j))return true;
        return false;
    }
};