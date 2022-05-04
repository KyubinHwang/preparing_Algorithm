#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<stack<int>> b(board.size() + 1);
    stack <int> s;
    for(int i = board.size() - 1;i >= 0;i--){
        for(int j = 0;j < board[i].size();j++){
            if(board[i][j] != 0)
                b[j + 1].push(board[i][j]);
        }
    }
    for(int i = 0;i < moves.size();i++){
        if(!b[moves[i]].empty()){
            int temp = b[moves[i]].top();
            b[moves[i]].pop();
            if(!s.empty()){
                if(s.top() == temp)
                {
                    s.pop();
                    answer += 2;
                }
                else{
                    s.push(temp);
                }
            }
            else{
                s.push(temp);
            }
        }
    }
    return answer;
}
