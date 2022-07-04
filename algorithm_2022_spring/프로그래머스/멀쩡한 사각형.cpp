using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    long long a = w;
    long long b = h;
    long long mod = a % b; 
    while (mod > 0) {
        a = b; 
        b = mod; 
        mod = a % b; 
    }
    
    answer = (long long)w * (long long)h - (w + h - b);
    return answer;
}
