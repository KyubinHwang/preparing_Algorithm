function solution(sizes) {
    var answer = 0;
    var arr1 = [];
    var arr2 = [];
    for (var i = 0; i < sizes.length;i++){
        if (sizes[i][0] > sizes[i][1]){
            arr1.push(sizes[i][0]);
            arr2.push(sizes[i][1]);
        } else {
            arr2.push(sizes[i][0]);
            arr1.push(sizes[i][1]);
        }
    }
    arr1.sort((a,b) => a - b);
    arr2.sort((a,b) => a - b);
    answer = arr1[sizes.length - 1] * arr2[sizes.length - 1]

    return answer;
}