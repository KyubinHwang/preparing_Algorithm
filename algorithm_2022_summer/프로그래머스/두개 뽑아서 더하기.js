function solution(numbers) {
    var answer = [];
    numbers.sort((a, b) => a - b);

    for(var i = 0;i < numbers.length;i++){
        for (var j = i + 1;j < numbers.length;j++){
            if (answer.includes(numbers[i] + numbers[j])){
                continue;
            } else {
                answer.push(numbers[i] + numbers[j]);
            }
        }
    }

    answer.sort((a, b) => a - b)

    return answer;
}