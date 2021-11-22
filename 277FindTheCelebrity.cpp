public class Solution extends Relation {
    public int findCelebrity(int n) {
        // Compare and eliminate one that is not celebrity. Compare with the next number until reaching the last number.
        int candidate = 0;
        for (int j = 1; j < n; j++)
            if (knows(candidate, j)) {
                candidate = j; // We get a final candidate by linear comparison
            }

        // Check if the final candidate is the celebrity
        for (int k = 0; k < n; k++) {
            if (candidate == k) continue;
            if (knows(candidate, k) || !knows(k, candidate)) { // If it knows someone, or someone doesn't know it, it's not a celebrity
                return -1;
            }
        }
        return candidate;
    }
}