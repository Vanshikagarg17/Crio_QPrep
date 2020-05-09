import java.io.*;
import java.util.*;

class MergeIntervals {
    // Implement your solution by completing the below function
    public int[][] merge(int[][] intervals) {

        return null;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] nums = new int[n][2];
        for (int i = 0; i < n; i++) {
            nums[i][0] = scanner.nextInt();
            nums[i][1] = scanner.nextInt();
        }
        scanner.close();

        int[][] results = new MergeIntervals().merge(nums);
        for (int i = 0; i < results.length; ++i)
            System.out.println(String.valueOf(results[i][0]) + " " + String.valueOf(results[i][1]));
    }
}
