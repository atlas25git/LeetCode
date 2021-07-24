public class Solution {
    public int DepthSum(IList<NestedInteger> nestedList) {
        return GetSum(nestedList, 1, 0);        
    }
    
    int GetSum(IList<NestedInteger> list, int depth, int sum) {
        foreach(var item in list) {
            sum = item.IsInteger()
                ? sum + depth * item.GetInteger()
                : GetSum(item.GetList(), depth + 1, sum);
        }
        
        return sum;
    }
}