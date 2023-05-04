import java.awt.*;
import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<Point> q = new LinkedList<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        int finished = 1;
        for(int i = 0; i < priorities.length; ++i){
            q.add(new Point(priorities[i], i));
            pq.add(-1 * priorities[i]);
        }
        while(!q.isEmpty()){
            Point now = q.poll();

            int now_p = -1 * pq.poll();
            if(now.x == now_p){
                if(now.y == location)
                    return finished;
                else
                    finished++;
            }else{
                q.add(now);
                pq.add( -1 * now_p);
            }
        }
        return answer;
    }
}