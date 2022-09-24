function solution(n) {
    var answer = 0;

    const backtracking = (chess, len) => {
        if (len === n) 
            answer++;
        else{
            for(let i = 0;i < n;i++){
                chess[len] = i;
                if (check(chess, len)) backtracking(chess, len + 1);
            }
        }
    }

    const check = (chess, len) => {
        for (let i = 0;i < len;i++){
            if (chess[i] === chess[len]) return false;
            if (Math.abs(chess[i] - chess[len]) === Math.abs(i - len)) 
                return false; 
        }
        return true;
    }

    for(let i = 0;i < n;i++){
        const chess = new Array(n).fill(0);
        chess[0] = i;
        backtracking(chess, 1);
    }

    return answer;
}