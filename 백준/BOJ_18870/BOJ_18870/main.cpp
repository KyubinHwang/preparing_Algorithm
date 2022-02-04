#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
   
    int N;
    int n = 0;
    cin >> N;
    vector <int> v(N);
    vector <int> resultV(N);
    map <int,int> m;
    
    for(int i = 0;i < N;i++){
        cin >> v[i];
        resultV[i] = v[i];
    }
    sort(v.begin(), v.end());
    
    for(int i = 0;i < N;i++){
        if(m.find(v[i]) == m.end()){
            m.insert({v[i], n});
            n++;
        }
    }
    for(int i = 0;i < v.size();i++){
        cout << m[resultV[i]] << " ";
    }
    
    return 0;
}
