class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> fs(cells.size(),0),ns(cells.size(),0);
        
        //Generating first sequence of the cycle
        for(int i=1;i<cells.size()-1;i++)
            fs[i] = cells[i-1] == cells[i+1];
        cells = fs;
        
        n--;
        int cycle_size = 0;
        
        while((fs != ns || cycle_size == 0) && n>0)
        {
            for(int i=1;i<cells.size()-1;i++)
                ns[i] = cells[i-1] == cells[i+1];
            cells = ns;
            cycle_size++;
            n--;
        }
        if(n<1)return cells;
        
        n%=cycle_size;
        
        while(n--)
        {
            for(int i=1;i<cells.size()-1;i++)
                ns[i] = cells[i-1] == cells[i+1];
            cells = ns;
        }
        
        return cells;
    }
};