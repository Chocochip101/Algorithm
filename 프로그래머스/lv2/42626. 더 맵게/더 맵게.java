import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int sc: scoville)
            pq.add(sc);

        while(true){
            int now = pq.poll();
            if(pq.isEmpty() && now < K)
                return -1;
            if(now >= K)
                break;
            answer++;
            
            pq.add(now + pq.poll() * 2);
        }
        return answer;
    }
}