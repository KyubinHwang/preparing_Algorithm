#include <iostream>
#include <queue>
using namespace std;
int N, M;
queue<int> q;
int game[101];
int check[101];

void BFS(){
    while(!q.empty()){
        int start = q.front();
        q.pop();
        for(int i = 1;i <= 6;i++){
            int rolled = start + i;
            if(rolled > 100) continue;
            rolled = check[rolled];
            if(game[rolled] == -1){
                game[rolled] = game[start] + 1;
                q.push(rolled);
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    for(int i = 1;i <= 100;i++){
        if(i == 1)
            game[1] = 0;
        else
            game[i] = -1;
        
        check[i] = i;
    }
    cin >> N >> M;
    
    for(int i = 0;i < N;i++){
        int a, b;
        cin >> a >> b;
        check[a] = b;
    }
    
    for(int i = 0;i < M;i++){
        int a, b;
        cin >> a >> b;
        check[a] = b;
    }
    
    q.push(1);
    BFS();
    
    cout << game[100] << "\n";
    
    return 0;
}
