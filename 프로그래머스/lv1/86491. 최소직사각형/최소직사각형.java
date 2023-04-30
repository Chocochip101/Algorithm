import java.util.*;

class Solution {
    long answer = 987654433211L;
    public void dfs(int idx, int now_w, int now_h, int[][] sizes){
        if(idx >= sizes.length){
            answer = Math.min(now_w * now_h, answer);
            return;
        }
        if((sizes[idx][0] <= now_w && sizes[idx][1] <= now_h) || (sizes[idx][1] <= now_w && sizes[idx][0] <= now_h)){
            dfs(idx + 1, now_w, now_h, sizes);
        }
         else{
             dfs(idx + 1, Math.max(sizes[idx][0], now_w), Math.max(sizes[idx][1], now_h), sizes);
            dfs(idx + 1, Math.max(sizes[idx][1], now_w), Math.max(sizes[idx][0], now_h), sizes);
         }
        return;
    }
    public long solution(int[][] sizes) {
        dfs(0, 0, 0, sizes);
        return answer;
    }
}