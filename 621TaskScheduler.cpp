public class Solution {
    public int LeastInterval(char[] tasks, int n) {
        var counts = new int[26];
        
        foreach(var task in tasks) {
            counts[task - 'A']++;
        }
        
        Array.Sort(counts);
        
        var fmax = counts[counts.Length - 1];
        var idle = (fmax - 1) * n;
        
        for(int i = counts.Length - 2; i >= 0; i--) {
            if(idle < 0) return tasks.Length;
            
            idle -= Math.Min(counts[i], fmax - 1);
        }
        
        return idle + tasks.Length;
    }