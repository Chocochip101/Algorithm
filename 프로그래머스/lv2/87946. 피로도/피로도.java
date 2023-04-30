class Solution {
    int answer = -1;
    boolean[] visited;
    public void dfs(int idx, int res, int cnt, int[][] dungeons){
        answer = Math.max(answer, cnt);
        for(int i = 0; i < dungeons.length; ++i)
            if(idx != i && !visited[i] && res >= dungeons[i][0]){
                visited[i] = true;
                dfs(i, res - dungeons[i][1], cnt + 1, dungeons);
                visited[i] = false;
            }
    }
    public int solution(int k, int[][] dungeons) {
        visited = new boolean[dungeons.length];
        dfs(-1, k, 0, dungeons);
        return answer;
    }
}