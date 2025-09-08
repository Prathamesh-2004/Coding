#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> arrival(n), departure(n);
    for (int i = 0; i < n; i++) cin >> arrival[i];
    for (int i = 0; i < n; i++) cin >> departure[i];

    int i = 1, j = 0;
    int platforms_in_use = 0, max_platforms = 0;

    // Two-pointer technique
    while (i < n && j<n) {
       
        if (arrival[i] <= departure[j]) {
            platforms_in_use++;
            max_platforms = max(max_platforms, platforms_in_use);
            i++;
        } else {
            if(i==n-1)
            {
                break;
            }
            j++;
        }
    }

    cout << max_platforms << endl;
    return 0;
}
