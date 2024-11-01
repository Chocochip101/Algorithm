class Solution {
    public long solution(int n, int[] times) {

        // 시간범위 지정
        long start = 0; //시작시간(분)
        long end = 1000000000 * 1000000000L; //최대종료시간(분) (사람수 x 심시시간)
        
        // 이진탐색
        while(end>start){
            long minute = (start + end) / 2; //범위를 반으로 줄인다.

            if(isValidCheck(times,minute,n)){ //시간내 유효하면 
                end = minute; //최대종료시간 갱신

            }else{//시간내 유효하지 않으면
                start = minute+1; //시작시간 갱신, 
                                  //위에서 minute 시간 안에 못찾은 경우는 앞으로 고려하지않기 위해 minute+1 부터 시작
            }
        }
        return start;
    }
    
    // 유효성 체크 로직
    private boolean isValidCheck(int[] times, long minute, int n){
        long count = 0;
        for(int time : times){ //심사관들이 minute내에 심사할수 있는 최대 사람수 구하기
            count += minute/time;
        }
        return count >= n;
    }
}