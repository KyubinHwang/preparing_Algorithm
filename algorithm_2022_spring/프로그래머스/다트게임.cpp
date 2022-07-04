#include <string>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int count = 0;
    int power = 1;
    int star = 1;
    int acha = 1;
    for(int i = dartResult.size() - 1;i >= 0;i--){
        if(dartResult[i] == '*'){
            star *= 2;
        }
        else if(dartResult[i] == '#'){
            acha *= -1;
        }
        else if(dartResult[i] == 'S'){
            power = 1;
        }
        else if(dartResult[i] == 'D'){
            power = 2;
        }
        else if(dartResult[i] == 'T'){
            power = 3;
        }
        else {
            int score = int(dartResult[i]) - 48;
            if(i - 1 >= 0 && int(dartResult[i - 1]) - 48 == 1){
                score = 10;
                i--;
            }
            answer += pow(score, power) * acha * star;
            if(star == 2){
                count++;
                if(count == 2){
                    star = 1;
                    count = 0;
                }
            }
            else if(star == 4){
                star = 2;
                count = 1;
            }
            acha = 1;
            power = 1;
        }
    }
    return answer;
}
