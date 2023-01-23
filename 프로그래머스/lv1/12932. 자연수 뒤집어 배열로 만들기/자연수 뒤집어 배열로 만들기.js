function solution(n) {
    var answer = [];
    while (1){
        answer.push(n % 10)
        n = parseInt(n / 10)
        if (n <= 0){
            break}
    }
    return answer;
}