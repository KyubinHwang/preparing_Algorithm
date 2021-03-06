# 5582번 공통 부분 문자열

## - 문제
두 문자열이 주어졌을 때, 두 문자열에 모두 포함된 가장 긴 공통 부분 문자열을 찾는 프로그램을 작성하시오.

어떤 문자열 s의 부분 문자열 t란, s에 t가 연속으로 나타나는 것을 말한다. 예를 들어, 문자열 ABRACADABRA의 부분 문자열은 ABRA, RAC, D, ACADABRA, ABRACADABRA, 빈 문자열 등이다. 하지만, ABRC, RAA, BA, K는 부분 문자열이 아니다.

두 문자열 ABRACADABRA와 ECADADABRBCRDARA의 공통 부분 문자열은 CA, CADA, ADABR, 빈 문자열 등이 있다. 이 중에서 가장 긴 공통 부분 문자열은 ADABR이며, 길이는 5이다. 또, 두 문자열이 UPWJCIRUCAXIIRGL와 SBQNYBSBZDFNEV인 경우에는 가장 긴 공통 부분 문자열은 빈 문자열이다.

입력

첫째 줄과 둘째 줄에 문자열이 주어진다. 문자열은 대문자로 구성되어 있으며, 길이는 1 이상 4000 이하이다.

출력

첫째 줄에 두 문자열에 모두 포함 된 부분 문자열 중 가장 긴 것의 길이를 출력한다.
## - 풀이 방법
이전에 풀었던 LCS와 유사하지만 문자가 띄어진 것이 아닌 문자열이 공통된 부분의 길이를 찾는 점에서 다른 문제였다. 이차원 벡터를 이용하여 입력받은 문자열 두개의 길이를 n개의 행, m개의 열로 표현하여 공통된 부분의 dp를 구하였다. 

이 때 공통되는 부분의 수열이 나타나면 이전 대각선 상단의 dp에 1을 더해주어 길이의 최대를 구할 수 있었다.

그렇지 못하다면 그 dp의 값은 0으로 초기화 해주어 두 문자열의 현재 인덱스의 값이 일치하지 않음을 표현하였다.

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (str1[i - 1] == str2[j - 1]) {
            v[i][j] = v[i - 1][j - 1] + 1;
            result = max(result, v[i][j]);
          }
          else
            v[i][j] = 0;
        }
      }
