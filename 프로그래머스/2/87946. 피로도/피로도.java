class Solution {
    int N;
    boolean[] visited;
    int[][] dungeons;
    public int solution(int k, int[][] d) {
        dungeons = d;
        N = dungeons.length;
        visited = new boolean[N];
        
        int answer = -1;
        for(int i = 0; i < N; i++){
            if(k >= dungeons[i][0]){
                visited[i] = true;
                answer = Math.max(answer, maxVisit(i, k));
                visited[i] = false;
            }
        }
        return answer;
    }
    
    private int maxVisit(int now, int k){
        int result = 0;
        visited[now] = true;
        k -= dungeons[now][1];
        for(int next = 0; next < N; next++){
            if(!visited[next] && k >= dungeons[next][0]){
                result = Math.max(result, maxVisit(next, k));
            }
        }
        visited[now] = false;
        return result + 1;
    }
}