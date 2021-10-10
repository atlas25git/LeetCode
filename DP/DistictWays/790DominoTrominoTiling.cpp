class Solution {
public:
    int m = 1e9+7;
    int numTilings(int N) {
        //our approach here will be to first establish the recurrence relation
        //so basically we've a total of 6 kind of shapes, let's examin:
        //For the domino no of shapes:
        // 1: --
        // 2: |
        //For tromino:
        // 3: |"
        // 4: |.
        // 5: "|
        // 6: .|
        
        // So for the last cell we can form recurrences for the shapes 1,2,5,6
        //1: if we fill the last cell with shape 1:
        //      T(n) = T(n-2), since 2 cells stacked vertically will be filled in this manner
        //2: if we fill the last cell with shape 2:
        //      T(n) = T(n-1), only one cell engaged
        //3: Shape 5
        //      T(n) = T_down(n-1)
        //   Delineating further:
        //                  |.          --  
        //      T_down(n) = T(n-2) + T_up(n-1);
        //4: Shape 6
        //      T(n) = T_up(n-1)
        //                  |"          --
        //      T_up(n) = T(n-2) + T_down(n-1)
        
        //Starting our computation from N=2
        // Deriving base cases from shapes to be filled
        // Shape 1:
        // T(2) = T(1) : 1
        // Shape 2:
        // T(2) = T(0) : 1
        //Shape 5:
        // T(2) = T_down(1) : 0
        //Shape 6: 
        // T(2) = T_up(1) : 0
        
        //Bottom up solution
        
        int t_0 = 1, t_1 = 1;
        int t_down_1 = 0;
        int t_up_1 = 0;
        
        for(int n=2;n<=N;n++)
        {
            int t_curr = (int)((0L +t_0 + t_1 + t_down_1 + t_up_1)%m);
            int t_up_curr  = (t_down_1 + t_0)%m;
            int t_down_curr = (t_up_1 + t_0)%m;
            
            t_up_1 = t_up_curr;
            t_down_1 = t_down_curr;
            
            t_0 = t_1;
            t_1 = t_curr;
        }
         return t_1;
    }
};