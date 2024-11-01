import java.util.*;

class Solution {
    public int[][] triangle;
    public int[][] cache;
    
    public int solution(int[][] tg) {
        triangle = tg;
        
        cache = new int[tg.length][tg.length];
        for(int i = 0; i < tg.length; i++){
            Arrays.fill(cache[i], -1);
        }
        return solve(0,0);
    }
    
    public int solve(int i, int j){
        if(cache[i][j] != -1){
            return cache[i][j];
        }
        if(i == cache.length - 1){
            return triangle[i][j];
        }
        int result = triangle[i][j] + Math.max(solve(i + 1, j), solve(i + 1, j + 1));
        
        cache[i][j] = result;
        return result;
    }
}