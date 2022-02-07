#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {

    int N, people;
    
    cin >> N;
    vector <int> result(N);
    
    for(int i = 1;i <= N;i++){
        cin >> people;
        for(int j = 0;j < N;j++){
            if(people == 0 && result[j] == 0){
                result[j] = i;
                break;
            }
            else if(result[j] == 0) people--;
        }
    }
    
    for(int i = 0;i < N;i++)
        cout << result[i] << " ";
    
    cout << "\n";
    
    return 0;
}
