#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using PII = pair<int, int>;

bool can_all_be_eliminated(const vector<PII>& robots) {
    for (auto i = robots.begin(); i != robots.end() - 1;) {
         auto j = i + 1;
         if ((j->first > i->first && j->second < i->second)
          || (j->first < i->first && j->second > i->second))
             i += 2;
         else if ((j->first > i->first && j->second > i->second)
          || (j->first > i->first && j->second > i->second))
             i++;
         else
            break;
         if (i == robots.end())
             return true;
    }
    return false;
}

bool check_permutation(vector<PII> robots) {
    PII r_strongest = robots.back();

    int idx = -1;
    for (int i = 0; i < robots.size() - 1; i++) {
        if (robots[i].second > r_strongest.second) {
            idx = i;
            break;
        }
    }

    PII r_current = robots[idx];
    robots.erase(robots.begin() + idx);
    robots.push_back(r_current);

    if (can_all_be_eliminated(robots))
        return true;

    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n_robots;
    cin >> n_robots;

    if (n_robots == 0) {
        cout << "TAK";
        return 0;
    } else if (n_robots == 1) {
        cout << "NIE";
        return 0;
    }

    vector<PII> robots(n_robots);
    for (auto& i : robots)
        cin >> i.first >> i.second;

    sort(robots.begin(), robots.end());

    if (robots.back().first == robots.back().second) {
        cout << "NIE";
        return 0;
    }

    if (can_all_be_eliminated(robots)) {
        cout << "TAK";
        return 0;
    }

    cout << (check_permutation(robots) ? "TAK" : "NIE");

    return 0;
}
