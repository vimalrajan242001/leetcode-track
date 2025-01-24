public class Solution {
    public int MaximumWealth(int[][] accounts) {
        int max = 1; // since the minimum value of the inputs is 1
        foreach (var cust in accounts)
        {
            max = Math.Max(max, cust.Sum());
        }
        return max;
    }
}