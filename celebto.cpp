#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ll_n long long int
#define w_loop(t) \
    int t;        \
    cin >> t;     \
    while (t--)
#define pb push_back
#define que queue<int>
#define p_tt pair<int, int>
#define p_ll pair<long long, long long>
#define vp_ll vector<pair<long long, long long>>
#define vec vector<int>
#define vl vector<long long>
#define mpp map<int, int>
#define mpp_ll map<long long, long long>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vec, greater<int>>
#define mod 1000000007
#define ll long long
#define inf_max INT_MAX
#define inf_min INT_MIN
#define f(i, n) for (ll i = 0; i < (ll)n; i++)
#define f1(i, n) for (int i = 1; i < (int)n; i++)
#define loop_rep(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define loop_rep1(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define Yes() cout << "YES" << endl
#define No() cout << "NO" << endl
#define endl '\n'
#define loop_repNeg(i, a, b) for (int i = (int)a; i >= (int)b; i--)
#define all(matches_permu) matches_permu.begin(), matches_permu.end()
#define sz matches_permu.size()
#define m_set multiset<int>
#define trac(x, matches_permu) for (auto x : matches_permu)
#define irt(x) insert(x)
#define unMap map<int, int>
#define unCharMpp map<int, char>
#define unSett set<int>
#define vec_b vector<bool>
#define st_ct static_cast<int>
#define trac_char(x, s) for (char x : s)
#define vec_un_sett_matches_permur vector<un_sett_matches_permuring>
#define vec_ll vector<long long>
#define MOD_e 1e9
#define un_MPP unordered_map<un_sett_matches_permuring, int>
#define un_set unordered_set<int>
#define un_Int unordered_map<int, int>
#define srt(matches_permu) sort(matches_permu.begin(), matches_permu.end())
#define mp make_pair
#define F firun_sett_matches_permu
#define S second
#define vec_pair vector<pair<int, int>>
#define vec_str vector<string>
#define map_sett map<int, set<int>>
#define vec_o vector<vector<int>>
#define up_bo() upper_bound()
#define pba pop_back()
#define fr front()
#define un_sett_matches_permu_prec setprecision

void pmatches_permu(vl matches_permu)
{
    for (auto it : matches_permu)
    {
        cout << it << " ";
    }
    cout << endl;
}

void init_code()
{
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
}
struct City
{
    string name;
    int cost;
    int reward;
};

struct Connection
{
    string from;
    string to;
    int travelCost;
};

struct State
{
    string city;
    int timeSpent;
    int reward;

    bool operator<(const State &other) const
    {
        return reward < other.reward;
    }
};

int Planning(string origin, string destination, int availableTime,
             vector<City> &cities, vector<Connection> &connections)
{
    unordered_map<string, City> cityMap;
    for (const auto &city : cities)
    {
        cityMap[city.name] = city;
    }

    unordered_map<string, vector<pair<string, int>>> graph;
    for (const auto &conn : connections)
    {
        graph[conn.from].emplace_back(conn.to, conn.travelCost);
    }

    priority_queue<State> pq;
    pq.push({origin, 0, 0});

    unordered_map<string, int> maxReward;
    maxReward[origin] = 0;

    while (!pq.empty())
    {
        State current = pq.top();
        pq.pop();

        if (current.timeSpent > availableTime)
            continue;

        if (current.city == destination)
        {
            return current.reward;
        }

        for (const auto &[nextCity, travelCost] : graph[current.city])
        {
            int nextTime = current.timeSpent + travelCost + cityMap[nextCity].cost;
            int nextReward = current.reward + cityMap[nextCity].reward;

            if (nextTime <= availableTime && nextReward > maxReward[nextCity])
            {
                maxReward[nextCity] = nextReward;
                pq.push({nextCity, nextTime, nextReward});
            }
        }
    }

    return -1;
}

void trip()
{
    vector<City> cities = {
        {"CITY_A", 100, 500},
        {"CITY_B", 200, 1000},
        {"CITY_C", 150, 800},
        {"CITY_D", 50, 600}};

    vector<Connection> connections = {
        {"CITY_A", "CITY_B", 200},
        {"CITY_A", "CITY_D", 150},
        {"CITY_B", "CITY_C", 300},
        {"CITY_D", "CITY_C", 200}};

    string origin = "CITY_A";
    string destination = "CITY_C";
    int availableTime = 800;

    int bestReward = Planning(origin, destination, availableTime, cities, connections);

    if (bestReward != -1)
    {
        cout << "Maximum Reward: " << bestReward << endl;
    }
    else
    {
        cout << "No valid trip possible within the given time." << endl;
    }
}

int main()
{
    trip();
    return 0;
}