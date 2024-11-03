import java.util.*;
class Solution {
    
    private int[] dx = {1, 0, 0, -1};
    private int[] dy = {0, -1, 1, 0};
    private String[] sym = {"d", "l", "r", "u"};
    
    public String solution(int n, int m, int x, int y, int r, int c, int k) {
        if(!canMove(x, y, r, c, k)){
            return "impossible";
        }
        
        return solve(n, m, x, y, r, c, k);
    }
    private String solve(int n, int m, int x, int y, int r, int c, int k){
        x -= 1;
        y -= 1;
        r -= 1;
        c -= 1;
        
        String answer = "";
        while(k > 0){
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(!isValid(n, m, nx, ny)){
                    continue;
                }
                
                int distance = Math.abs(nx - r) + Math.abs(ny - c);
                if(distance <= k - 1){
                   k--;
                   x = nx; y = ny;
                   answer += sym[i];
                   break;
                }
            }
        }
        return answer;
    }

    private boolean canMove(int x, int y, int r, int c, int k){
        int dist = Math.abs(x - r) + Math.abs(y - c);
        if(dist > k){
            return false;
        }
        if((k - dist) % 2 == 0){
            return true;
        }
        return false;
    }
    
    
    private boolean isValid(int n, int m, int nx, int ny){
        return 0 <= nx && nx < n && 0 <= ny && ny < m;
    }
}