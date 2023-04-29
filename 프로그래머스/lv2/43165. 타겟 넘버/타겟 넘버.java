class Solution {
    int answer = 0;
    public void dfs(int i, int[] numbers, int now, int target){
        if(i == numbers.length){
            if(now == target)
                answer++;
            return;
        }
        dfs(i + 1, numbers, now + numbers[i], target);
        dfs(i + 1, numbers, now - numbers[i], target);
        return;
    }
    public int solution(int[] numbers, int target) {
        dfs(0, numbers, 0, target);
    
        return answer;
    }
}