import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for(int c = 0; c < commands.length; c++){
            int i = commands[c][0];
            int j = commands[c][1];
            int k = commands[c][2];
            answer[c] = getAnswer(array, i, j, k);
        }
        return answer;
    }
    
    private int getAnswer(int[] array, int i, int j, int k){
        int[] sliced = Arrays.copyOfRange(array, i - 1, j);
        Arrays.sort(sliced);
        return sliced[k - 1];
    }
}