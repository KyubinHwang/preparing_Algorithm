#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int N, M;
    string S;

    int result = 0;
    
    cin >> N >> M >> S;
    for(int i = 0;i < M;i++){
        int count = 0;
        if(S[i] == 'I'){
            while(S[i + 1] == 'O' && S[i + 2] == 'I'){
                i += 2;
                count++;
                if(count == N){
                    result++;
                    count--;
                }
            }
            
        }
    }
    
    cout << result << "\n";
    return 0;
}
