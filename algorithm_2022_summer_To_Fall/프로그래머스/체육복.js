function solution(n, lost, reserve) {
    var answer = n - lost.length;
    var check = [];

    lost.map((val) => {
        if (reserve.includes(val)){
            reserve = reserve.filter((e) => e !== val);
            answer++;
        }
        else{
            check.push(val)
        }
    })

    lost = check

    lost.sort((a, b) => a - b);
    reserve.sort((a, b) => a - b);

    lost.map((val) => {
        if(reserve.includes(val - 1)){
            reserve = reserve.filter((e) => e !== val - 1);
            check = check.filter((e) => e !== val);
            answer++;
        }
        else if(reserve.includes(val + 1)){
            reserve = reserve.filter((e) => e !== val + 1);
            check = check.filter((e) => e !== val);
            answer++;
        }
    })

    return answer;
}