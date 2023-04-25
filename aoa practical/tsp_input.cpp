#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n; // number of cities
    vector<int> cities(n);
    for (int i = 0; i < n; i++) {
        cities[i] = i;
    }
    int dist[n][n]; // distance matrix
    cout << "Enter the distance matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
 
        }
    }
    int ans = 1e9; // initialize answer to a large number
    do {
        int cost = 0;
        for (int i = 0; i < n-1; i++) {
            cost += dist[cities[i]][cities[i+1]];
        }
        cost += dist[cities[n-1]][cities[0]]; // return to starting city
        ans = min(ans, cost);
    } while (next_permutation(cities.begin()+1, cities.end())); // generate all permutations
    cout << "The shortest tour has length " << ans << "." << endl;
    return 0;
}