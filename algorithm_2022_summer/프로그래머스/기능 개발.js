function solution(progresses, speeds) {
    var answer = [];
    let count = 0;
    var complete = [];

    for(let i = 0;i < speeds.length;i++){
        count += Math.ceil((100 - progresses[i]) / speeds[i]);
        complete.push(count);
        count = 0;
    }

    while (complete.length !== 0){
        count = 1;
        let check = false;
        var tmp = complete.shift();
        while(!check){
            if(complete[0] <= tmp && check !== true){
                count += 1;
                complete.shift();
            }
            else{
                check = true;
            }
        }
        for(let i = 0;i < complete.length; i++) {
            if(complete[i] - tmp < 0)
                complete[i] = 0;
            else
                complete[i] -= tmp;
        }
        answer.push(count);
        count = 1;
    }

    return answer;
}