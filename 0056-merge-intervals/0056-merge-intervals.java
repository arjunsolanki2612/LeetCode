import java.util.*;

class Solution {
    public int[][] merge(int[][] intervals) {
        // Step 1: Sort the intervals based on start time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        // Step 2: Use a list to store merged intervals dynamically
        List<int[]> merged = new ArrayList<>();

        // Step 3: Iterate through all intervals
        for (int[] interval : intervals) {
            // If merged list is empty OR no overlap, add the interval
            if (merged.isEmpty() || merged.get(merged.size() - 1)[1] < interval[0]) {
                merged.add(interval);
            } 
            // If overlapping, merge by updating the end time
            else {
                merged.get(merged.size() - 1)[1] = 
                    Math.max(merged.get(merged.size() - 1)[1], interval[1]);
            }
        }

        // Step 4: Convert list back to int[][]
        return merged.toArray(new int[merged.size()][]);
    }
}
