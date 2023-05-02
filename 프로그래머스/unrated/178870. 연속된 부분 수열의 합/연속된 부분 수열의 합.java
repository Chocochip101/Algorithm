class Solution {
    public int[] solution(int[] sequence, int k) {
        int[] answer = {0, sequence.length + 1};
        int s = 0;
        int e = 1;
        int parSum = sequence[0];
        while(s < sequence.length){
            if(parSum == k)
                if(answer[1] - answer[0] > e - s){
                    answer[0] = s;
                    answer[1] = e;
                }
            
            if(parSum <= k){
                if(e == sequence.length)
                    break;
                parSum += sequence[e];
                e += 1;
            }else{
                parSum -= sequence[s];
                s += 1;
            }
        }
        answer[1] -= 1;
        return answer;
    }
}