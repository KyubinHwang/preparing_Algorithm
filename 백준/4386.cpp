#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int point[100];

int Find_Parent(int A)
{
    if (A == point[A]) return A;
    else return point[A] = Find_Parent(point[A]);
}


int main(int argc, const char * argv[]) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector <pair<double, double>> v;
    for(int i = 0;i < n;i++){
        double x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    int index = 0;
    vector <pair <double, pair<int, int>>> v2;
    while(index != n){
        for(int i = index + 1;i < n;i++){
            double distance = 0;
            distance = sqrt(pow(v[index].first - v[i].first, 2) + pow(v[index].second - v[i].second, 2));
            v2.push_back({distance, make_pair(index, i)});
        }
        index++;
    }

    sort(v2.begin(), v2.end());

    double result = 0.0;

    for(int i = 0;i < n;i++){
        point[i] = i;
    }

    for(int i = 0;i < v2.size();i++){
        if(Find_Parent(v2[i].second.first) != Find_Parent(v2[i].second.second)){
            result += v2[i].first;
            point[Find_Parent(v2[i].second.second)] = Find_Parent(v2[i].second.first);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << result << "\n";

    return 0;
}
