# 9252번 LCS 2
## - 문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력

첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력

첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력한다.

LCS가 여러 가지인 경우에는 아무거나 출력하고, LCS의 길이가 0인 경우에는 둘째 줄을 출력하지 않는다.
## - 풀이 방법
LCS문제의 연속으로 이번에는 LCS를 직접 출력해보는 것까지 구하는 문제였다. LCS구하는 방법은 앞서 다른 문제에서 설명하였으니 같은 방법으로 구하면 되고 LCS의 경우에는 공통부분의 문자일 경우와 아닐 때를 나눠서 생각하면 되었다.

만약 같은 문자의 경우에는 LCS의 길이를 구했을 때와 마찬가지로 현재 LCS에 대각선 상단의 LCS의 값에 공통되는 문자를 더해주어서 값을 정하면된다. 만약 다를 경우에는 좌측, 또는 상단의 LCS의 길이가 긴것을 따라가면 된다.

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
          if (LCS1[i - 1] == LCS2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
            L[i][j] = L[i][j] + L[i - 1][j - 1] + LCS1[i - 1];
          }
          else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (L[i - 1][j].length() > L[i][j - 1].length()) {
              L[i][j] = L[i - 1][j];
            }
            else
              L[i][j] = L[i][j - 1];
          }
        }
      }
      
위처럼 된다~~~
