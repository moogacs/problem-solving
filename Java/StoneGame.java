// Problem link: https://leetcode.com/problems/stone-game/description/
/*
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.
Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.
Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
 
Example 1:
Input: [5,3,4,5]
Output: true
Explanation: 
    Alex starts first, and can only take the first 5 or the last 5.
    Say he takes the first 5, so that the row becomes [3, 4, 5].
    If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
    If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
    This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
 
Note:
    2 <= piles.length <= 500
    piles.length is even.
    1 <= piles[i] <= 500
    sum(piles) is odd.

*/

import java.util.Arrays;

public class StoneGame {
    static int[][] dp;
    public static boolean stoneGame(int[] piles) {
        int n = piles.length;
        dp = new int[n+1][n+1]; // dp[i][j] = max score player 1 can get from piles[i,j)
        for (int i=0; i<=n; i++) Arrays.fill(dp[i], -1);
        int total = 0;
        for (int i : piles) total += i;
        int score1 = getScore(piles, 0, n);
        return score1 >= total/2;
    }
    private static int getScore(int[] piles, int i, int j) {
        if (i == j) return 0;
        if (i+1 == j) return piles[i];
        if (dp[i][j] != -1) return dp[i][j];
        int result = Math.max(piles[i]+Math.min(getScore(piles, i+2, j), getScore(piles, i+1, j-1)), 
                              piles[j-1]+Math.min(getScore(piles, i, j-2), getScore(piles, i+1, j-1)));
        dp[i][j] = result;
        return result;
    }
    public static void main(String[] args) {
        int[] piles = {5, 3, 4, 5};
        boolean result = stoneGame(piles);
        System.out.println(result);
    }
}