#include <iostream>
#include <vector>
#include <string>
using namespace std;
int M;
bool S[21];

void add(int x) {
    S[x] = true;
}

void remove(int x) {
    S[x] = false;
}

void check(int x) {
    if(S[x] == true)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}

void toggle(int x) {
    if(S[x] == true)
        S[x] = false;
    else
        S[x] = true;
}

void all() {
    for(int i = 1;i <= 20;i++){
        S[i] = true;
    }
}

void empty() {
    for(int i = 1;i <= 20;i++){
        S[i] = false;
    }
}

int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M;
    string calculate;
    for(int i = 0;i < M;i++){
        cin >> calculate;
        if(calculate == "all")
            all();
        else if(calculate == "empty")
            empty();
        else
        {
            int num;
            cin >> num;
            if(calculate == "add")
                add(num);
            else if(calculate == "remove")
                remove(num);
            else if(calculate == "check")
                check(num);
            else
                toggle(num);
        }
    }
    
    return 0;
}
