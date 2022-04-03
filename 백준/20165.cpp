#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int domino[101][101];
char state[101][101];
int N, M, R;

int main(int argc, const char * argv[]) {
    
    cin >> N >> M >> R;
    memset(state, 'S', sizeof(state));
    
    for(int i = 1;i <= N;i++){
        for(int j = 1;j <= M;j++){
            cin >> domino[i][j];
        }
    }
    int result = 0;
    while(R--){
        int n, m;
        char way;
        cin >> n >> m >> way;
        int count = domino[n][m];
        if(way == 'E'){
            while(count != 0 && m <= M){
                if(state[n][m] == 'S'){
                    count = max(count, domino[n][m]);
                    state[n][m] = 'F';
                    result++;
                }
                m++;
                count--;
            }
        }
        else if(way == 'W'){
            while(count != 0 && m > 0){
                if(state[n][m] == 'S'){
                    count = max(count, domino[n][m]);
                    state[n][m] = 'F';
                    result++;
                }
                m--;
                count--;
            }
        }
        else if(way == 'S'){
            while(count != 0 && n <= N){
                if(state[n][m] == 'S'){
                    count = max(count, domino[n][m]);
                    state[n][m] = 'F';
                    result++;
                }
                n++;
                count--;
            }
        }
        else{
            while(count != 0 && n > 0){
                if(state[n][m] == 'S'){
                    count = max(count, domino[n][m]);
                    state[n][m] = 'F';
                    result++;
                }
                n--;
                count--;
            }
        }
        int standX, standY;
        cin >> standX >> standY;
        state[standX][standY] = 'S';
    }
    cout << result << "\n";
    
    for(int i = 1;i <= N;i++){
        for(int j = 1;j <= M;j++){
            cout << state[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
