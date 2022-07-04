#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n;
int point = 51;
vector<vector<int>> v(51);
bool visited[51];

int BFS(int id){
    
    queue <pair<int, int>> q;
    int dept = 0;
    q.push({id , 0});
    visited[id] = true;
    while(!q.empty()){
        int pos = q.front().first;
        int score = q.front().second;
        q.pop();
        dept = max(dept , score);
        for(int i = 0;i < v[pos].size();i++){
            if(!visited[v[pos][i]]){
                visited[v[pos][i]] = true;
                q.push({v[pos][i], score + 1});
            }
        }
    }
        
    return dept;
}

int main(int argc, const char * argv[]) {
    
    cin >> n;
    vector <int> result;
    while(1){
        int num1, num2;
        cin >> num1 >> num2;
        
        if(num1 == -1 && num2 == -1)
            break;
        
        v[num1].push_back(num2);
        v[num2].push_back(num1);
    }
    
    for(int i = 1;i <= n;i++){
        int point_temp = BFS(i);
        if(point == point_temp)
        {
            result.push_back(i);
        }
        else if(point > point_temp)
        {
            point = point_temp;
            result.clear();
            result.push_back(i);
        }
        memset(visited, false, sizeof(visited));
    }
    
    cout << point << " " << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}
