class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        int totalTiles = brown + yellow;
        for(int r = 3; r <= Math.sqrt(totalTiles); ++r){
            if(totalTiles % r == 0){
                int c = totalTiles / r;
                if(brown == 2 * r + 2 * c - 4 ){
                    answer[0] = c;
                    answer[1] = r;
                }
            }
        }
        return answer;
    }
}