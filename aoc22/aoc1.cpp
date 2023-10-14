#include <regex>
#include <fstream>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

using namespace std;
using ll = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main(void)
{
    freopen("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt", "r", stdin);
    string line;
    long long sum = 0;
    vector<long long> k;

    while(getline(cin,line))
    {
        long long s=0;
        for (long long i = line.length()-1, j=0; i >= 0 ; --i,j++) {

            if(line[i] == '=')
            {
                s += pow(5,j)*(-2);
            }
            else if(line[i] == '-')
            {
                s += pow(5,j)*(-1);
            }
            else
            {
                string m;
                m += line[i];
                long long a = stoi(m);
                s += pow(5,j)*a;
            }
        }
        k.push_back(s);

    }
    for(auto b : k)
        sum += b;

    std::cout << sum << std::endl;


    long long total = 33078355623611;
    string anw = "";

    do
    {
        long long temp = total % 5;
        total = floor(total/5);

        if(temp > 2)
        {
            total += 1;
            anw += "   =-"[temp];
        }
        else
        {
            anw += to_string(temp);
        }
        std::cout << anw << std::endl;
    }while(total);

    std::cout << anw << std::endl;


}

/*
 * 1=-0-2
12111
2=0=
21
2=01
111
20012
112
1=-1=
1-12
12
1=
122
1 kac basamakli onu bul
2. her basamagi oradaki degerle carp
3. topla
*/

/*
void day_24()
{
    ifstream ifs;
    ifs.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");
    string line;
    vector<string> map;
    while (getline(ifs,line))
    {
        map.push_back(line);
    }
    int N = map.size();
    int M = map[0].size();

    vector<vector<vector<int>>> stats(N, vector<vector<int>>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if(map[i][j] == '>') stats[i][j].push_back(0);
            if(map[i][j] == 'v') stats[i][j].push_back(1);
            if(map[i][j] == '<') stats[i][j].push_back(2);
            if(map[i][j] == '^') stats[i][j].push_back(3);
        }
    }

    vector<vector<vector<int>>> curr(N, vector<vector<int>>(M, vector<int>(3)));
    curr[0][1][0] = 1;

    for(int step = 1; ;step++)
    {
        vector<vector<vector<int>>> statsNext(N, vector<vector<int>>(M));
        vector<vector<vector<int>>> currNext(N, vector<vector<int>>(M, vector<int>(3)));

        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                for (auto d : stats[i][j]){

                    int nx = i + dx[d], ny = j + dy[d];
                    if (nx == N-1) nx = 1;
                    if (nx == 0) nx = N-2;
                    if (ny == M-1) ny = 1;
                    if (ny == 0) ny = M-2;
                    statsNext[nx][ny].push_back(d);
                }
            }
        }
        stats = statsNext;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                for (int x = 0; x < 3; ++x) {
                    if(!curr[i][j][x]) continue;
                    for (int k = 0; k < 4; ++k) {
                        int nx = i + dx[k], ny = j + dy[k];
                        if(!(nx >= 0 && nx < N && ny >= 0 && ny < M)) continue;
                        if(map[nx][ny] != '#' && stats[nx][ny].empty())
                            currNext[nx][ny][x] = 1;
                    }
                    if(stats[i][j].empty()) currNext[i][j][x] = 1;
                }
            }
        }
        curr = currNext;
        if(curr[N-1][M-2][0]) curr[N-1][M-2][1] = 1;
        if(curr[0][1][1]) curr[0][1][2] = 1;
        if(curr[N-1][M-2][2])
        {
            std::cout << step << std::endl;
            break;
        }
    }

}
*/
/*
void day_21_p1()
{


    ifstream ifsData;

    freopen("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt", "r", stdin);
    string line;
    map<string, int> deg_o;
    map<string, vector<string>> adj;
    map<string, string> ops;
    map<string, ll> val_o;
    map<string, string> froma;
    map<string, string> fromb;
    queue<string> q_o;
    while (getline(cin, line)){
        istringstream iss(line);
        string name; iss >> name;
        name = name.substr(0, 4);
        if (line[6] >= '0' && line[6] <= '9'){
            ll x; iss >> x;
            val_o[name] = x;
            q_o.push(name);
        }
        else{
            string a, op, b;
            iss >> a >> op >> b;
            ops[name] = op;
            adj[a].push_back(name);
            adj[b].push_back(name);
            froma[name] = a;
            fromb[name] = b;
            deg_o[name] = 2;
        }
    }
    ll lo = 0, hi = 5615010794218;
    while (lo < hi){
        ll guess = (lo + hi) >> 1;
        auto q = q_o;
        map<string, ll> val = val_o;
        map<string, int> deg = deg_o;
        val["humn"] = guess;
        while (!q.empty()){
            string v = q.front(); q.pop();
            if (!val.count(v)){
                if (ops[v] == "+"){
                    val[v] = val[froma[v]] + val[fromb[v]];
                }
                if (ops[v] == "-"){
                    val[v] = val[froma[v]] - val[fromb[v]];
                }
                if (ops[v] == "*"){
                    val[v] = val[froma[v]] * val[fromb[v]];
                }
                if (ops[v] == "/"){
                    val[v] = val[froma[v]] / val[fromb[v]];
                }
            }
            for (string to : adj[v]){
                deg[to]--;
                if (deg[to] == 0){
                    q.push(to);
                }
            }
        }
        cout << guess << " " << val["jsrw"] << " " << val["ptvl"] << '\n';
        cout.flush();
        if (val["jsrw"] >= val["ptvl"]){
            lo = guess + 1;
        }
        else{
            hi = guess;
        }
    }
    std::cout << val_o["root"] << std::endl;

}
/*
void p_2()
{
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string line;
    vector<string> g;
    while (getline(cin, line)){
        g.push_back(line);
    }
    string s = g.back();
    g.pop_back();
    g.pop_back();

    int N = g.size();
    int M = 0;
    for (int i = 0; i < N; ++i){
        M = max(M, (int)g[i].size());
    }
    for (int i = 0; i < N; ++i){
        while (g[i].size() < M) g[i] += " ";
    }

    int dir = 0;
    int y = find(g[0].begin(), g[0].end(), '.') - g[0].begin();
    int x = 0;
    const int SZ = 50;
    auto step = [&]() -> void{
        int sx = x, sy = y, sdir = dir;
        x += dx[dir];
        y += dy[dir];
        x = (x + N) % N;
        y = (y + M) % M;

        if (dir == 1){
            // 4v
            if (x == 3*SZ && y < 2*SZ && y >= 1*SZ){
                dir = 2; // <
                x = (y - 1*SZ) + 3*SZ;
                y = 1*SZ - 1;
            }

                // 2v
            else if (x == 1*SZ && y < 3*SZ && y >= 2*SZ){
                dir = 2;
                x = (y - 2*SZ) + 1*SZ;
                y = 2*SZ - 1;
            }
                // 6v
            else if (x == 0 && y < 1*SZ && y >= 0){
                x = 0;
                y += 2*SZ;
            }
        }

        else if (dir == 3){
            // 5^
            if (x == 2*SZ - 1 && y < 1*SZ && y >= 0){
                dir = 0; // >
                x = (y - 0*SZ) + 1*SZ;
                y = 1*SZ;
            }

                // 1^
            else if (x == 4*SZ - 1 && y < 2*SZ && y >= 1*SZ){
                dir = 0; // >
                x = (y - 1*SZ) + 3*SZ;
                y = 0*SZ;
            }

                // 2^
            else if (x == 4*SZ - 1 && y < 3*SZ && y >= 2*SZ){
                y -= 2*SZ;
            }

        }

        else if (dir == 0){
            // 2>
            if (y == 0 && x < 1*SZ && x >= 0){
                dir = 2; // <
                x = (SZ - (x - 0*SZ) - 1) + 2*SZ;
                y = 2*SZ - 1;
            }

                // 3>
            else if (y == 2*SZ && x < 2*SZ && x >= 1*SZ){
                dir = 3; // ^
                y = (x - 1*SZ) + 2*SZ;
                x = 1*SZ - 1;
            }

                // 4>
            else if (y == 2*SZ && x < 3*SZ && x >= 2*SZ){
                dir = 2; // <
                x = (SZ - (x - 2*SZ) - 1) + 0*SZ;
                y = 3*SZ - 1;
            }

                // 6>
            else if (y == 1*SZ && x < 4*SZ && x >= 3*SZ){
                dir = 3; // ^
                y = (x - 3*SZ) + 1*SZ;
                x = 3*SZ-1;
            }
        }

        else if (dir == 2){
            // 6< -> (top of 1)
            if (y == 3*SZ - 1 && x < 4*SZ && x >= 3*SZ){
                dir = 1; // v
                y = (x - 3*SZ) + 1*SZ;
                x = 0;
            }

                // 5< -> (left of 1, flipped)
            else if (y == 3*SZ - 1 && x < 3*SZ && x >= 2*SZ){
                dir = 0; // >
                x = (SZ - (x - 2*SZ) - 1) + 0*SZ;
                y = 1*SZ;
            }

                // 3< -> (top of 5)
            else if (y == 1*SZ - 1 && x < 2*SZ && x >= 1*SZ){
                dir = 1; // v
                y = (x - 1*SZ) + 0*SZ;
                x = 2*SZ;
            }

                // 1< -> (left of 5, flipped)
            else if (y == 1*SZ - 1 && x < 1*SZ && x >= 0){
                dir = 0; // v
                x = (SZ - (x - 0*SZ) - 1) + 2*SZ;
                y = 0;
            }

        }

        if (g[x][y] == ' '){
            cout << sx << " " << sy << " " << sdir << " | " << x << " " << y << " " << dir << '\n';
            cout.flush();
        }
        assert(g[x][y] != ' ');
        if (g[x][y] != '#'){
            sx = x, sy = y, sdir = dir;
        }
        x = sx, y = sy, dir = sdir;
    };
    istringstream iss(s);
    int steps; char cd;
    while (iss >> steps){
        for (int i = 0; i < steps; ++i){
            step();
        }
        if (iss >> cd){
            if (cd == 'L') dir = (dir + 3) % 4;
            else dir = (dir + 1) % 4;
        }
    }
    cout << 1000 * (x+1) + 4 * (y+1) + (dir) << '\n';
}

void day22_p1()
{
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};

    ifstream ios;
    std::string line;
    freopen("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt", "r", stdin);
    vector<string> g;
    while (getline(cin, line)){
        g.push_back(line);
    }
    string s = g.back();
    g.pop_back();
    g.pop_back();

    int N = g.size();
    int M = 0;
    for (int i = 0; i < N; ++i){
        M = max(M, (int)g[i].size());
    }
    for (int i = 0; i < N; ++i){
        while (g[i].size() < M) g[i] += " ";
    }

    int dir = 0;
    int y = find(g[0].begin(), g[0].end(), '.') - g[0].begin();
    int x = 0;
    auto step = [&]() -> void{
        int sx = x, sy = y;
        do{
            x += dx[dir];
            y += dy[dir];
            x = (x + N) % N;
            y = (y + M) % M;
            if (g[x][y] == '.'){
                sx = x, sy = y;
            }
        } while (g[x][y] == ' ');
        x = sx, y = sy;
    };
    istringstream iss(s);
    int steps; char cd;
    while (iss >> steps){
        cout << x << " " << y << '\n';
        cout.flush();
        for (int i = 0; i < steps; ++i){
            step();
        }
        if (iss >> cd){
            if (cd == 'L') dir = (dir + 3) % 4;
            else dir = (dir + 1) % 4;
        }
    }
    cout << 1000 * (x+1) + 4 * (y+1) + (dir) << '\n';

}


 class Command;

std::vector<Command*> CommandQueue;

class OreCollector
{

};
class ClayCollector
{

};

class CommandInterface
{
public:
     void OreCollectorCommand() { std::cout << " Ore " << std::endl; }
     void ClayCollectorCommand() { std::cout << " Clay " << std::endl; }
};

class Command
{
public:
    virtual ~Command()= default;

    virtual void Execute() { };
};

class OreCollectorCommand : public Command
{
    CommandInterface commandInterface;
public:
    explicit OreCollectorCommand(CommandInterface commandInterface1) : commandInterface(commandInterface1) {}

    void Execute() override
    {
        commandInterface.OreCollectorCommand();

    }

};

class ClayCollectorCommand : public Command
{
    CommandInterface commandInterface;
public:
    explicit ClayCollectorCommand(CommandInterface commandInterface1) : commandInterface(commandInterface1) {}

    void Execute() override
    {
        commandInterface.ClayCollectorCommand();
    }

};

int main() {

    CommandInterface commandInterface;

    Command* oreCommand = new OreCollectorCommand(commandInterface);

    CommandQueue.push_back(oreCommand);

    CommandQueue[0]->Execute();


}

 void day_18_p2()
{

    ifstream ifsData;
    std::string line;

    ifsData.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");

    vector<vector<int>> c;
    vector<vector<int>> answer;
    int a[3];

    while(getline(ifsData,line))
    {
        const char *lines = line.c_str();

        sscanf(lines, "%d,%d,%d", &a[0], &a[1], &a[2]);
        c.push_back({a[0],a[1],a[2]});

    }
//2,2,5*
    set<int> x;
    set<int> y;
    set<int> z;
    auto countMe = [&](vector<int> a)
    {
        bool flag = true;
        int count = 6;

        for (auto & i : c) {
            if((a[2] == i[2] && a[1] == i[1] && (a[0]) == i[0]))
                continue;

            if(a[2] == i[2] && a[1] == i[1] && (a[0]-1) != i[0] && (a[0]+1) != i[0])
            {
                for(auto &j : c)
                {
                    if(j[0] == abs(i[0]-1) && j[0] == abs(i[0]+1) && j[1] == i[1] && j[2] == i[2])
                        flag = false;
                    if(j[0] == abs(a[0]-1)&& j[0] == abs(i[0]+1) && j[1] == i[1] && j[2] == i[2])
                        flag = false;
                }
                if(flag && a[0] <= i[0])
                {
                    x.insert(i[0]-1);
                }


                flag = true;
            }

            if((a[2] == i[2]) && (a[1]-1 != i[1]) && (a[1]+1 != i[1]) && (a[0]) == i[0])
            {
                for(auto &j : c)
                {
                    if(j[1] == abs(i[1]-1) && j[1] == abs(i[1]+1) && j[2] == i[2] && j[0] == i[0])
                        flag = false;
                    if(j[1] == abs(a[1]-1) && j[1] == abs(i[1]+1) && j[2] == i[2] && j[0] == i[0])
                        flag = false;
                }
                if(flag && a[1] <= i[1])
                    y.insert(i[1]-1);

                flag = true;
            }


            if((a[2]-1 != i[2]) && (a[2]+1 != i[2]) && a[1] == i[1] && (a[0]) == i[0])
            {
                for(auto &j : c)
                {
                    if(j[2] == abs(i[2]-1) && j[1] == abs(i[1]+1) && j[1] == i[1] && j[0] == i[0])
                        flag = false;
                    if(j[2] == abs(a[2]-1) && j[1] == abs(i[1]+1) && j[1] == i[1] && j[0] == i[0])
                        flag = false;
                }
                if(flag && a[2] <= i[2])
                    z.insert(i[2]-1);

                flag = true;
            }

        }
        return count;
    };

    int count = 0;
    for(auto s : c)
    {
        countMe(s);
    }


    multiset<vector<int>> temp;
    for(const auto& x1 : x)
    {
        for(const auto& y1 : y)
        {

            for(const auto &z1 : z)
            {

                vector<int> temp2;
                temp2.push_back(x1);
                temp2.push_back(y1);
                temp2.push_back(z1);
                temp.insert(temp2);

            }
        }
    }

    for(auto &sa : temp)
    {
        if(!std::count(c.begin(), c.end(),sa))
            std::cout << sa[0] << " "<< sa[1] << " "<< sa[2] << " " << std::endl;
    }


}
void day_18_p1()
{


    ifstream ifsData;
    std::string line;

    ifsData.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");

    vector<vector<int>> c;
    int a[3];

    while(getline(ifsData,line))
    {
        const char *lines = line.c_str();

        sscanf(lines, "%d,%d,%d", &a[0], &a[1], &a[2]);
        c.push_back({a[0],a[1],a[2]});

    }

    auto countMe = [&](vector<int> a)
    {
        int count = 6;

        for (auto & i : c) {
            if((a[2] == i[2] && a[1] == i[1] && (a[0]) == i[0]))
                continue;
            if(a[2] == i[2] && a[1] == i[1] && (a[0]-1) == i[0])
                count--;
            if(a[2] == i[2] && a[1] == i[1] && (a[0]+1) == i[0])
                count--;
            if(((a[2]-1) == i[2] && a[1] == i[1] && (a[0]) == i[0]))
                count--;
            if(((a[2]+1) == i[2] && a[1] == i[1] && (a[0]) == i[0]))
                count--;
            if((a[2] == i[2] && (a[1]+1) == i[1] && (a[0]) == i[0]))
                count--;
            if((a[2] == i[2] && (a[1]-1) == i[1] && (a[0]) == i[0]))
                count--;
        }
        return count;
    };

    int count = 0;
    for(auto s : c)
    {
        std::cout << countMe(s) << std::endl;
        count += countMe(s);
    }
    std::cout << count << std::endl;


}
void day_17()
{


    ifstream ifsData;
    std::string line;

    ifsData.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");
    getline(ifsData,line);
    set<pair<int,int>> seen;
    int height = 0;
    int ind = 0;

    auto insert = [&](pair<int,int> x){
        seen.insert(x);
        height = max(height, x.second + 1);
    };

    auto good = [&](pair<int,int> p){
        return p.first >= 0 && p.first < 7 && !seen.count(p) && p.second >= 0;
    };

    auto shift = [&](set<pair<int, int>> cur, int dx, int dy) -> set<pair<int, int>>{
        set<pair<int, int>> nxt;
        for (auto p : cur){
            pair<int, int> pp = {p.first + dx, p.second + dy};
            if (!good(pp)) return {};
            nxt.insert(pp);
        }
        return nxt;
    };

    set<pair<int, int>> ctemp;
/*
    for(int i=0; i < 5; i++)
    {
        int startX = 2, startY = height + 3;
        for(pair<int,int> mod : shapes[i%5])
        {
            std::cout <<  mod.first + startX << " " <<mod.second + startY << std::endl;
            ctemp.insert({mod.first + startX,mod.second + startY});
        }
        std::cout << " : " <<std::endl;

    }


    bool flag = true;
    int count = 0;
    set<pair<int, int>> ctemp2;
    for(int i = 0; i < 2000; i++)
    {

        set<pair<int, int>> c;
        int startX = 2, startY = height + 3;

        for(pair<int,int> mod : shapes[i%5])
        {
            c.insert({mod.first + startX,mod.second + startY});
        }

        while(true)
        {
            set<pair<int, int>> temp;

            if(line[ind%line.size()] == '<') temp = shift(c,-1,0);
            if(line[ind%line.size()] == '>') temp = shift(c,1,0);
            ind++;
            if(!temp.empty()) c = temp;
            temp = shift(c,0,-1);
            if(temp.empty())
            {
                for(auto p : c)
                    insert(p);
                break;
            }
            else c = temp;
        }


        if(count == 5)
        {
            flag = false;
            if(ctemp2 == ctemp)
                std::cout << " hello world ! " << i  << std::endl;

            count = 0;
        }
        count++;

        if(flag)
        {
            for(auto a : c)
            {
                std::cout << a.first  << " " << a.second << std::endl;
                ctemp2.insert({a.first, a.second});
            }

        }

        std::cout << " :: " <<std::endl;

    }
    cout << height << '\n';
    for (int i = height+10; i >= 0; --i){
        for (int x = 0; x < 7; ++x){
            if (seen.count({x, i})) cout << '#';
            else cout << '.';
        }
        cout << " " << i << " ";
        cout << '\n';
    }

}

void day_14()
{


    /*
    while(getline(ifsData,lis))
    {
        const char *lines = lis.c_str();

        sscanf(lines, "Sensor at x=%lf, y=%lf: closest beacon is at x=%lf, y=%lf", &a[0], &a[1], &a[2],&a[3]);

        for(int i =0 ; i < 4 ; i++)
        {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    for(auto &a : data)
    {
        std::cout << a.first << " : " << a.second << std::endl;
    }


    ifsData.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");
    string line;
    struct beacon{ ll x, y, d; };
    vector<beacon> vec;
    set<pair<ll, ll>> beacons;

    while(getline(ifsData,lis)){
        int x, y, sx, sy;
        const char *lines = lis.c_str();

        sscanf(lines, "Sensor at x=%lf, y=%lf: closest beacon is at x=%lf, y=%lf", &a[0], &a[1], &a[2],&a[3]);

        x = a[0];
        y = a[1];
        sx = a[2];
        sy = a[3];
        vec.push_back({x, y, abs(x-sx) + abs(y-sy)});
        beacons.insert({sx, sy});
    }

    for(auto &a : vec)
    {
        std::cout << a.x << " " << a.y << " " << a.d << std::endl;
    }
    std::cout << " ---------- " << std::endl;
    for(auto &a : beacons)
    {
        std::cout << a.first << " " << a.second << std::endl;
    }
    std::cout << " ---------- " << std::endl;

    for (int i = 0; i <= 4000000; ++i){

        for(int j = 0; j < vec.size(); j++)
        {
            int nx =  vec[j].x;
            int ny =  vec[j].y;
            int nd =  vec[j].d;

            int del = nd - abs(i-nx);
            std::cout << del << " " << nd << " " << i << " " <<nx << std::endl;

            if(del >= 0)
            {
                std::cout << ny-del << " " << ny+del << std::endl;
            }

        }
        break;

    }

// OLUSAN ELMASLARIN BI OTESINI KONTROL ET YETER
/*
for (int i = 0; i <= 4000000; ++i){
    vector<pii> ints;
    for (auto [x, y, d] : vec){
        int del = d - abs(i-x);
        if (del >= 0){
            ints.push_back({y-del, y+del});
        }
    }
    sort(ints.begin(), ints.end());
    int lst = 0;
    for (auto [a, b] : ints){
        if (a > lst){
        cout << i * 4000000LL + (a-1) << '\n';
        return 0;
        }
        lst = max(lst, b);
    }
}
*/

// p1
/*
    int iy = 2000000;
    int count = 0;
    bool fail;
    for (int i = -20000000; i <= 20000000; ++i){

        fail = 0;

        for(int j = 0; j < vec.size(); j++)
        {
            int nx =  vec[j].x;
            int ny =  vec[j].y;
            int nd =  vec[j].d;
            if (abs(nx-i) + abs(ny-iy) <= nd) fail = 1;

        }

        if (beacons.count({i, iy})) fail = 0;

        count += fail;
    }
    std::cout << count << std::endl;

}*/

void day_13_uh()
{

    /*
    std::string inp = "498,4 -> 498,6 -> 496,6\n"
                      "503,4 -> 502,4 -> 502,9 -> 494,9\n";
    std::vector<std::vector<int>> inpN;

    std::vector<int> temp;
    std::string tempData;

    for(int j = 0; j < inp.length()  ; j++)
    {

        if(inp[j] != '\n')
        {
            if(inp[j] != ',' && inp[j] != '-' && inp[j] != '>' && inp[j] != ' ')
            {
                tempData += inp[j];
            }
            else
            {
                if(tempData[0] != NULL)
                {

                    int c = std::stoi(tempData);
                  //  std::cout << c << std::endl;
                    temp.push_back(c);
                    tempData = "";
                }

            }
        }
        else
        {
            tempData += inp[j];
            if(tempData[0] != NULL)
            {

                int c = std::stoi(tempData);
           //     std::cout << c << std::endl;
                temp.push_back(c);
                tempData = "";
            }

            inpN.push_back(temp);
            temp.clear();
       //     std::cout << std::endl;

        }
    }


    for(auto a : inpN)
    {
        for(auto b : a)
            std::cout << b << " ";
        std::cout << std::endl;

    }
    std::vector<std::vector<std::string>> map;
    for (int i = 0; i < 20; ++i) {
        std::vector<std::string> tempc;
        for (int j = 0; j < 600; ++j) {
            tempc.push_back(".");
        }
        map.push_back(tempc);
        tempc.clear();
    }


    for(int j = 0; j < inpN.size(); j++)
    {
        int x=0,y=0;

        for(int i =0; i < inpN[j].size()-1; i+=2)
        {

            std::cout << x << ":" << y << " , " <<inpN[j][i] << ":" <<inpN[j][i+1] << std::endl;

            if(inpN[j][i] == x)
            {
                for(int l=y; l <= inpN[j][i+1] ; l++)
                {
                    map[l][inpN[j][i]] = '#';
                }
            }
            if(inpN[j][i+1] == y)
            {
                int h = x - inpN[j][i];
                for(; 0 <= h ; h--)
                {
                    map[y][x-h] = '#';
                }
            }
            x = inpN[j][i];
            y = inpN[j][i+1];


        }

    }
    map[0][500] = "+";

    while(true)
    {
        for(int i = 0; i < map.size(); i++)
        {
            if(map[i][500] == "#")
            {
                map[i-1][500] = "o";
            }
            if(map[i][500] == "o")
            {
                std::cout << " hl " << std::endl;
                if(map[i][500-1] == ".")
                    map[i][500-1] = "o";
                else if(map[i][500+1] == ".")
                    map[i][500+1] = "o";

            }
        }


        break;
    }
*/

}
/*
void day_12_relax()
{

    freopen("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt", "r", stdin);

    string a, b;
    int idx = 1;

    auto split = [&](string a) -> vector<string>{
        vector<string> ret;
        string cur; int cnt = 0;
        for (int i = 1; i < a.size()-1; ++i){
            if (a[i] == '[') cnt++;
            if (a[i] == ']') cnt--;
            if (!cnt && a[i] == ',') ret.push_back(cur), cur = "";
            else cur += a[i];
        }
        if (cur != "") ret.push_back(cur);
        return ret;
    };

    auto leq = [&](auto self, string a, string b) -> int{
        if (a.empty()) return -1;
        if (b.empty()) return 1;
        bool ba = 0, bb = 0;
        if (a[0] == '[' && a.back() == ']') ba = 1;
        if (b[0] == '[' && b.back() == ']') bb = 1;
        if (ba || bb){
            if (!ba) a = "[" + a + "]";
            if (!bb) b = "[" + b + "]";
            vector<string> nxta = split(a);
            vector<string> nxtb = split(b);
            for (int i = 0; i < min(nxta.size(), nxtb.size()); ++i){
                int ret = self(self, nxta[i], nxtb[i]);
                if (ret) return ret;
            }
            if (nxta.size() < nxtb.size()) return -1;
            if (nxta.size() > nxtb.size()) return 1;
            return 0;
        }
        else{
            if (stoi(a) < stoi(b)) return -1;
            if (stoi(a) > stoi(b)) return 1;
            return 0;
        }
    };
    int ans = 0;
    vector<string> vec;
    while (getline(cin, a)){
        getline(cin, b);
        string filler; getline(cin, filler);
        vec.push_back(a);
        vec.push_back(b);
    }
    vec.push_back("[[2]]");
    vec.push_back("[[6]]");
    sort(vec.begin(), vec.end(), [&](string a, string b){
        return (leq(leq, a, b)) < 0;
    });
    int i = find(vec.begin(), vec.end(), "[[2]]") - vec.begin() + 1;
    int j = find(vec.begin(), vec.end(), "[[6]]") - vec.begin() + 1;
    std::cout << i*j << '\n';


    std::ifstream ifs;
    ifs.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");

    std::string line;
    int inc= 0, outc = 0;

    std::vector<std::string> inp;
    std::vector<std::string> data1;
    std::vector<std::string> data2;

    while(getline(ifs, line))
    {
        if(line.size())
        {
            inp.push_back(line);
        }
        else
        {
            int special=0;
            while(true)
            {
                std::string temp= "";
                for (int i = 0; i < inp[0].length(); ++i) {
                    if(inp[0][i] == '1' && inp[0][i+1] == '0')
                    {
                        temp.push_back(inp[0][i]);
                        temp.push_back(inp[0][i+1]);
                        data1.push_back(temp);
                   //     std::cout << temp << " ";
                        temp = "";
                        continue;
                    }
                    if(inp[0][i] == ',' || inp[0][i] == '[' || inp[0][i-1] == '1')
                    {
                        continue;

                    }
                    std::string k;
                    k = inp[0][i];
                    data1.push_back(k);
                //    std::cout << inp[0][i] << " ";

                }
                temp = "";

                std::cout << std::endl;

                temp = "";
                std::cout << std::endl;
                for (int i = 0; i < inp[1].length(); ++i) {
                    if(inp[1][i] == '1' && inp[1][i+1] == '0')
                    {
                        temp.push_back(inp[1][i]);
                        temp.push_back(inp[1][i+1]);
                        data2.push_back(temp);
                      //  std::cout << temp << " ";
                        temp = "";

                        continue;
                    }
                    if(inp[01][i] == ',' || inp[01][i] == '[' || inp[01][i-1] == '1')
                        continue;
                    std::string k;
                    k = inp[1][i];
                    data2.push_back(k);
                    std::cout << inp[1][i] << " ";

                }
                std::cout << std::endl;
                std::cout << std::endl;

//                std::cout << data1.size() << std::endl;
  //              std::cout << data2.size() << std::endl;

                int i = -1,j = -1;
                int u,d;
                int a1 = data1.size() - 1;
                int a2 = data2.size() - 1;
                while(1==1)
                {

                    if(a1 <= i || a2 <= j)
                    {
                        std::cout << i<< " breaked!" << std::endl;
                        break;
                    }
                    else
                    {
                        i++;
                        j++;
                    }

                    if(data1[i][0] == ']')
                    {
                        for(int k = i; k < data1.size(); k++)
                        {
                            if(data1[k][0] != ']')
                            {
                                i = k;
                                break;
                            }
                        }
                    }
                    if(data2[j][0] == ']')
                    {
                        for(int k = j; k < data2.size(); k++)
                        {
                            if(data1[k][0] != ']')
                            {
                                j = k;
                                break;
                            }
                        }
                    }

                    if(data1[i][0] == ']' || data2[i][0] == ']')
                    {
                        if(data1[i+1][0] != NULL || data2[i+1][0] != NULL)
                            if(data1[i+1][0] == ']' && data2[i+1][0] == ']')

                    }

                    if(stoi(data1[i]) < stoi(data2[j]))
                    {
                    }

                    std::cout << " new: "<< data1[i]<< " " << data2[j] << std::endl;


                }

                data1.clear();
                data2.clear();
                break;
            }

            inp.clear();

        }

    }
}
*/



/*
void day_11_notbad()
{

    std::ifstream ifs;

    ifs.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");

    string line;

    std::vector<std::vector<int>> data;

    int ey=0,ex=0,sx=0,sy=0,Nx=0,Ny=0;

    int tempy= 0;
    while(getline(ifs,line))
    {
        std::vector<int> temp;
        for(int i = 0; i < line.size(); i++)
        {
            if(line[i] == 'S') { sx = i; sy = tempy; line[i] = 'a'; }
            else if(line[i] == 'E') { ex = i; ey = tempy; line[i] = 'z'; }

            temp.push_back(line[i]);
        }

        data.push_back(temp);
        temp.clear();
        tempy++;
    }
    Nx = data.size();
    Ny = data[0].size();
    std::cout << sx << " " << sy << " " << ex << " " << ey << std::endl;


    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};

    auto check = [&](int n, int m){
        return n >= 0 && m >= 0 && n <=Nx && m <= Ny;
    };

    vector<vector<int>> dist(Nx, vector<int>(Ny, 1e9));

    vector<vector<int>> find;
    queue<std::pair<int,int>> queue1;
    queue1.push({sx, sy});
    while(!queue1.empty())
    {
        auto [x,y] = queue1.front(); queue1.pop();
        for(int i = 0; i < 4; i++)
        {
            int n = x + dx[i];
            int m = y + dy[i];

            if(!check(n,m)) continue;
            std::cout <<data[n][m] <<" " << data[x][y] + 1 <<" "<< std::endl;
            std::cout <<n <<" " << m <<" " << x << " " << std::endl;

        }
        break;
    }


    for(auto &a : find)
    {
        for(auto &b : a)
            std::cout << b << " ";
        std::cout << std::endl;
    }

    for(auto &a : data)
    {
        for(auto &b : a)
            std::cout << b << " ";
        std::cout << std::endl;
    }


}




vector<vector<int>> PassMonkey =
        {
                {6, 7},
                {5, 2},
                {4, 5},
                {6, 0},
                {0, 3},
                {3, 4},
                {1, 7},
                {2, 1}
        };

vector<vector<int>> stuff =
        {
                {66, 79},
                {84, 94, 94, 81, 98, 75},
                {85, 79, 59, 64, 79, 95, 67},
                {70},
                {57, 69, 78, 78},
                {65, 92, 60, 74, 72},
                {77, 91, 91},
                {76, 58, 57, 55, 67, 77, 54, 99}
        };

void Day_11_rez()
{

    vector<int> count(8);

    long long mod = 9999999;
    auto operation = [&](int id, int worry) {
        switch (id) {
            case 0:
                worry *= 11;
                worry %= mod;
                break;
            case 1:
                worry *= 17;
                worry %= mod;
                break;
            case 2:
                worry += 8;
                worry %= mod;
                break;
            case 3:
                worry += 3;
                worry %= mod;
                break;
            case 4:
                worry += 4;
                worry %= mod;
                break;
            case 5:
                worry += 7;
                worry %= mod;
                break;
            case 6:
                worry *= worry;
                worry %= mod;
                break;
            case 7:
                worry += 6;
                worry %= mod;
                break;
        }

        return worry;
    };

    auto test = [&](int id, int worry) {
        switch (id) {
            case 0:
                worry %= 7;
                return worry == 0 ? 1 : 0;
                break;
            case 1:
                worry %= 13;
                return worry == 0 ? 1 : 0;
                break;
            case 2:
                worry %= 5;
                return worry == 0 ? 1 : 0;
                break;
            case 3:
                worry %= 3;
                return worry == 0 ? 1 : 0;
                break;
            case 4:
                worry %= 2;
                return worry == 0 ? 1 : 0;
                break;
            case 5:
                worry %= 11;
                return worry == 0 ? 1 : 0;
                break;
            case 6:
                worry %= 17;
                return worry == 0 ? 1 : 0;
                break;
            case 7:
                worry %= 3;
                return worry == 0 ? 1 : 0;
                break;
        }
    };

    for (int j = 0; j < 10000; ++j){
        for (int i = 0; i < 8; ++i){
            for (auto &x : stuff[i]){
                count[i]++;
                long long y;
                if (test(i,operation(i,x))){
                    stuff[PassMonkey[i][0]].push_back(y);
                } else{
                    stuff[PassMonkey[i][1]].push_back(y);
                }

            }
            stuff[i].clear();
        }
    }
    sort(count.begin(), count.end());

    for (auto &x : count)
        std::cout << x << " ";


    /*
      std::ifstream ifs;


      ifs.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");

      std::string line;
      int sum = 0;
      int count = 20;
      int cycle = 0;
      int value = 1;
      std::vector<std::vector<int>> monkey;

  /*
     for(int i = 0; i < 8; i++)
      {
          std::vector<int> mon;
          mon.push_back(i);
          monkey.push_back(mon);
      }
      */
/*



    std::vector<std::vector<int>> temp;
    temp.reserve(8);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int news = operation(i,monkey[i][j]);
            int id = test(i,news);
            monkey[i].erase(monkey.begin() + j);
            temp[id].push_back(monkey[i][j]);
        }
    }
    std::cout << temp.size() << ". ";
*/
/*
}
*/
/*
void Day_10_ez()
{
    std::ifstream ifs;


    ifs.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");

    std::string line;

    int sum = 0;
    int count = 20;
    int cycle = 0;
    int value = 1 ;
    std:vector<int> result;

    auto steps = [&](){
        int y = (cycle - 1) % 40;
        if (abs(y - value) <= 1) cout << '#';
        else cout << '.';
        if (cycle % 40 == 0) cout << '\n';
    };

    while (getline(ifs, line)){

        if (line[0] == 'a')
        {
            cycle++;

            steps();

            /*
            if(cycle == count)
            {
                result.push_back(value * count);
                count += 40;
            }
*/
/*
            /// operations
            cycle++;
            steps();
            /*
            if(cycle == count)
            {
                result.push_back(value * count);
                count += 40;
            }
             */
/*
            long i = std::stoi(line.substr(line.find(" ") + 1, line.size() - line.find(" ")));
            value += i;
        }

        else {

            cycle++;
            steps();
        }


    }

    /*
    std::cout << value << std::endl;
    std::cout << cycle << std::endl;
    for(auto &a : result)
    {
        sum += a;
    }
        std::cout << sum << std::endl;
*/

/*
    string s;
    int cy = 0;
    int tot = 0, cur = 1;

    auto step = [&](){
        cy++;
        int y = (cy - 1) % 40;
        if (abs(y - cur) <= 1) cout << '#';
        else cout << '.';
        if (cy % 40 == 0) cout << '\n';
    };

    while (getline(ifs, line)){
        if (s == "addx"){
            long vx = std::stoi(line.substr(line.find(" ") + 1, line.size() - line.find(" ")));
            step();
            step();
            cur += vx;
        }
        else{
            step();
        }
    }
*/
/*
}
void fucking_Day_9()
{
    std::ifstream ifs;

    using pii = pair<int, int>;
    map<char, pii> mv = {{'R',{0,1}},{'L',{0,-1}},{'D',{1,0}},{'U',{-1,0}}};
    set<pii> seen;

    ifs.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");

    int cnt;
    char dir;

    vector<pii> rope(10, {0, 0});
    seen.insert(rope[9]);

    while (cin >> dir >> cnt){






        for (int x = 0; x < cnt; ++x){
            rope[0].first += mv[dir].first;
            rope[0].second += mv[dir].second;
            for (int i = 1; i < 10; ++i){
                pii &h = rope[i-1];
                pii &t = rope[i];
                if (max(abs(h.first - t.first), abs(h.second - t.second)) == 2){
                    if (abs(h.first - t.first) == 2)
                        t.first = (h.first + t.first) / 2;
                    else
                        t.first = h.first;
                    if (abs(h.second - t.second) == 2)
                        t.second = (h.second + t.second) / 2;
                    else
                        t.second = h.second;
                }
            }
            seen.insert(rope[9]);
        }
    }
    cout << seen.size() << '\n';
  //  fclose(fp);
}

void spagetti_day_8()
{
    std::ifstream ifs;
    std::string line;
    std::vector<std::vector<int>> up;
    std::vector<int> TreeScore;
    ifs.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");

    std::vector<std::string> input = {"30373\n"
                                      "25512\n"
                                      "65332\n"
                                      "33549\n"
                                      "35390"
    };

    input = splitString(input[0]);

    for(int i = 0; i < input.size(); i++)
    {
        std::vector<int> a;
        for(int j = 0; j < input[i].size(); j++)
        {
            a.push_back(input[i][j]-48);
        }
        up.push_back(a);

    }
    for(auto &a : input)
    {
        for(auto &b : a)
            std::cout << b << " " ;
        std::cout << std::endl;

    }
    int count = 0;

    int score = 0;
    int multiplied = 1;

    for(int i =0; i < input.size(); i++)
    {
        for(int j =0; j < input[i].size(); j++)
        {
            bool visible = true;


            for(int k = i-1; k >= 0; k--) // upper
            {

                if(k == -1)
                {
                    visible = true;
                    score = 0;
                    break;
                }

                if(input[i][j] <= input[k][j])
                {
                    score++;
                    visible = false;
                    break;
                }
                else
                {
                    score++;
                    visible = true;
                }

            }


            std::cout << score << " ";
            multiplied *= score;
            score = 0;

/*
            if(visible) {
                std::cout << input[i][j] << " ";
                count++;
                continue;
            }
              //          visible = true;

*/
/*
            for(int k = i+1; k < input[i].size(); k++) // down
            {

                if(input[i][j] <= input[k][j])
                {
                    // assa
                    score++;

                    break;
                }
                else
                {
                    score++;
                }
            }


            std::cout << score << " ";
            multiplied *= score;
            score = 0;

/*
            if(visible)
            {
                std::cout << input[i][j] << " ";
                count++;
                continue;
            }

            visible = true;*/
/*
            for(int k = j-1; k >= 0; k--) // sola
            {
                if(k == -1)
                {
                    visible = true;
                    score = 0;
                    break;
                }

                if(input[i][j] <= input[i][k])
                {
                    visible = false; // sola
                    score++;

                    break;
                }
                else
                {
                    score++;

                    visible = true;
                }

            }
            std::cout << score << " ";
            multiplied *= score;
            score = 0;

            /*
            if(visible)
            {
                std::cout << input[i][j] << " ";
                count++;
                continue;
            }

            visible = true;
             */
/*
            for(int k = j+1; k < input[i].size(); k++) // saga
            {
                if(input[i][j] <= input[i][k])
                {

                    visible = false; // saga
                    score++;
                    break;
                }
                else
                {
                    visible = true;
                    score++;

                }
            }
            std::cout << score << " ";

            multiplied *= score;

            std::cout << multiplied << " ";
            TreeScore.push_back(multiplied);
            score = 0;
            multiplied = 1;
            std::cout << ":" << " ";
        }
        std::cout << std::endl;
        std::cout << " --------  "<<std::endl;
    }
    std::sort(TreeScore.begin(),TreeScore.end());
    for(auto &a : TreeScore)
        std::cout << a << std::endl;

}


struct files
{
public:
    long size = 0;
    std::vector<files*> dirVector;
    std::vector<std::string> fileVector;
    std::string name;
    struct files* parent = nullptr;


    files& operator=(files &other)
    {
        return *this;
    }


};

files *newFile()
{
    files *temp = new files;
    return temp;
}

void shit_day_7()
{
    std::ifstream ifs;
    std::string line;
    ifs.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");
    struct files* root = new files();

    root->parent = nullptr;
    root->name = "/";
    bool flag = true;

    while(getline(ifs, line))
    {
        if(line[0] == '$')
        {
            if(line[line.size()-2] != '.' && line[2] == 'c')
            {

                if(root->dirVector.size() != 0)
                {
                    for(int i = 0; i < root->dirVector.size(); i++)
                    {
                        if(root->dirVector[i]->name == line.substr(4, line.size()))
                        {
                            root = root->dirVector[i];
                            flag = true;
                        }
                    }
                }

            }
            else if(line[2] != 'l')
            {
                root = root->parent;
                flag = false;
            }
            else{}
        }
        else
        {
            if(flag)
            {
                if(line.substr(0, 3) == "dir")
                {
                    files *child2 = newFile();
                    child2->parent = root;
                    child2->name = line.substr(3, line.size());
                    root->dirVector.push_back(child2);
                }
                else
                {
                    root->fileVector.push_back(line);
                    long i = std::stoi(line.substr(0, line.find(" ")));

                    root->size += i;

                    files *temp = root;
                    for(root; root->parent != nullptr;)
                    {
                        root = root->parent;
                        root->size += i;
                    }
                    root = temp;

                }

            }

        }

    }

    long sum = 0;
    std::vector<long> temp;
    if(root->dirVector.size() == 0)
        root = root->parent;

    while(root->dirVector.size() != 0)
    {
        while(1)
        {
            if(root->dirVector.empty())
                break;
            root = root->dirVector[0];

        }

//        part2
        if(8381165 <= root->size)
        {
            std::cout << root->size << std::endl;
            temp.push_back(root->size);
        }
//        part1
        if(100000 >= root->size)
        {
            std::cout << root->size << std::endl;
            sum += root->size;

        }


        root = root->parent;

        root->dirVector.erase(root->dirVector.begin());

        if(root->dirVector.size() == 0 && root->parent != nullptr)
            root = root->parent;

        if(8381165 <= root->size)
        {
            std::cout << root->size << std::endl;
            temp.push_back(root->size);
        }

    }
    std::cout << sum << std::endl;


}

void day6_my_sol()
{
    std::ifstream ifs;
    std::string line;
    std::vector<char> subData;
    std::set<char> data;
    ifs.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");

    int i = 0;

    getline(ifs,line);
    while(1)
    {
        data.insert(line.begin()+i,line.begin()+ i +14);
        if(data.size() == 14)
        {
            std::cout << i+14 << std::endl;
            break;
        }
        else
        {
            i++;
            data.clear();
        }

    }


    for(auto &a : data)
    {
        std::cout << a << " ";
        std::cout << std::endl;

    }
}


void day5_my_sol()
{
    std::ifstream ifs;
    std::ifstream ifsData;
    std::string line;
    std::string size;
    std::string sData;
    std::vector<std::vector<char>> data;
    std::vector<char> subData;

    size = "[P] [H] [P] [Q] [P] [M] [P] [F] [D]";

    for(int j = 1; j < size.length() ; j+=4 )
    {
        ifs.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");

        for(int i = 0; i < 8; i++)
        {
            getline(ifs,line);

            if(line[j] == ' ')
            {
                continue;
            }
            else
            {
                subData.push_back(line[j]);
            }
        }
        if(subData[0] == subData[subData.size()-1])
            subData.erase(subData.begin());

        ifs.close();
        data.push_back(subData);
        subData.clear();
    }


    int a[3];
    ifsData.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/Data.txt");

    while(getline(ifsData,line))
    {
        const char *lines = line.c_str();

        sscanf(lines, "move %d from %d to %d", &a[0], &a[1], &a[2]);

        for(int i=0; i < a[0]; i++)
        {
            data[a[2]-1].insert(data[a[2]-1].begin(),data[a[1]-1][a[0]-1 - i]); // part2
            data[a[2]-1].insert(data[a[2]-1].begin(),data[a[1]-1][i]); // part1
        }
        data[a[1]-1].erase(data[a[1]-1].begin(), data[a[1]-1].begin() + a[0]);

    }

    for(auto &a : data)
    {
        for(auto &b : a)
            std::cout << b << " ";
        std::cout << std::endl;

    }

}

void day4_another_solution() // by https://www.reddit.com/user/ednl/
{
    int a[4], part1 = 0, part2 = 0;
    FILE *f = fopen("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt", "r");
    while (fscanf(f, "%d-%d,%d-%d", &a[0], &a[1], &a[2], &a[3]) == 4) {
        part1 += (a[0] >= a[2] && a[1] <= a[3]) || (a[0] <= a[2] && a[1] >= a[3]);
        part2 += a[0] <= a[3] && a[1] >= a[2];
    }

    fclose(f);
    printf("%d\n%d\n", part1, part2);

}
void day4() // my
{
    std::ifstream ifs;
    std::string line;
    std::string f,s;
    int h1,l1,h2,l2;
    ifs.open("/home/xamblot/CLionProjects/CppExamplePractices/aoc22/input.txt");

    int count = 0;

    while(getline(ifs,line))
    {
        f = line.substr(0,line.find(','));
        s = line.substr(line.find(',')+1);

        l2 = std::stoi(s.substr(0, s.find("-")));
        h2 = std::stoi(s.substr(s.find("-")+1));

        l1 = std::stoi(f.substr(0, f.find("-")));
        h1 = std::stoi(f.substr(f.find("-")+1));

        //part2
        if(l2 <= h1 && l1 <= h2)
            count++;
        //part 1
        if((l1 >= l2 && h1 <= h2) || (l2 >= l1 && h2 <= h1) )
            count++;

    }
    std::cout << count << std::endl;

}
void day3_my_imp_not_clean() // my bad
{

    std::vector<std::string> input = {"vJrwpWtwJgWrhcsFMMfFFhFp\n"
                                      "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL\n"
                                      "PmmdzqPrVvPwwTWBwg\n"
                                      "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn\n"
                                      "ttgJtRGJQctTZtZT\n"
                                      "CrZsJsPPZsGzwwsLwLmpwMDw"};
    std::vector<std::string> newInput = {""};
    std::vector<std::string> Chars = {""};
    input = splitString(input[0]);

/*
    // prepare input for part 1
    for(auto&k : input)
    {
        std::string b = k.substr(0,k.length()/2);
        std::string c = k.substr(k.length()/2,k.length());
        std::string m = "";

        for(int i = 0; i < b.length(); i++)
        {
            for(int j = 0; j < c.length(); j++)
            {
                if(b[i] == c[j])
                {
                    m = b[i];
                    Chars.push_back(m);
                    break;
                }
            }
            if(b[i] == m[0])
                break;

        }
    }
*/
/*
    // prepare input part 2
    for(int i =0; i < input.size(); i +=3 )
    {
        std::string temp = "";
        for(int k = 0 ; k < input[i].length() ; k++)
        {
            for(int l = 0 ; l < input[i+1].length() ; l++)
                if(input[i][k] == input[i+1][l])
                    for(int n = 0 ; n < input[i+2].length() ; n++)
                    {
                        if(temp[0] == input[i][k])
                            break;
                        if(input[i][k] == input[i+2][n])
                        {
                            temp = input[i][k];
                            Chars.push_back(temp);
                            break;
                        }
                    }

            if(temp[0] == input[i][k])
                break;
            if(temp[0] == input[i][k])
                break;
        }
    }
*/
/*
    // get answer, just remove comment, for which part u want
    int sum = 0;
    for(auto &a : Chars)
    {
        if(a[0] != 0)
        {
            std::cout << (int)a[0]<< std::endl;

            if(islower(a[0]))
                sum += (int)a[0]-96;
            else
                sum += (int)a[0]-(65-27);
        }

    }

    std::cout << sum << std::endl;

}
void day3_clean()
{
    /* ex input
vJrwpWtwJgWrhcsFMMfFFhFp
jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
PmmdzqPrVvPwwTWBwg
wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
ttgJtRGJQctTZtZT
CrZsJsPPZsGzwwsLwLmpwMDw
 */
/*
    std::ifstream ifs;
    std::string line;
    ifs.open("input.txt");

    std::set<char> char_set;
    std::set<char> char_set2;
    std::map<char, size_t> char_Priority;
    int p1 = 0,p2=0;

    for(int i = 0; i < 26; i++)
    {
        char_Priority['a' + i] = i+1;
        char_Priority['A' + i] = i+27;
    }


    int PART1 = 0;
    int countP2 = 0;
    while(std::getline(ifs, line))
    {
        if(PART1)
        {
            // p1
            for(int i = 0 ; i < line.size()/2; i++)
                char_set.insert(line[i]);
            for(int i = line.size()/2; i < line.size(); i++ )
                if(char_set.contains(line[i]))
                {
                    p1 += char_Priority[line[i]];
                    break;
                }
            char_set.clear();
        }
        else
        {
            //p2
            switch (countP2 ) {
                case 0:
                    for (size_t i = 0; i < line.size(); ++i) {
                        char_set.insert(line[i]);
                    }
                    break;
                case 1:
                    for (size_t i = 0; i < line.size(); ++i) {
                        char_set2.insert(line[i]);
                    }
                    break;
                case 2:
                    for (size_t i = 0; i < line.size(); ++i) {
                        if (char_set.contains(line[i]) && char_set2.contains(line[i])) {
                            p2 += char_Priority[line[i]];
                            break;
                        }
                    }
                    break;
            }
            ++countP2;
            if (countP2 % 3) {
                countP2 = 0;
                char_set.clear();
                char_set2.clear();
            }
        }
    }
    std::cout << p1 << p2 << std::endl;
}

void day2()
{
    int score = 0;
    std::vector<std::string> input = {""};
    input = splitString(input[0]);
    input.push_back("q");
    std::string temp;

    for (int i = 0; i < input.size()*3; ++i) {
        if(input[i][2] == 'X')
        {
            if(input[i][0] == 'C')
                input[i][2] = 'Y';
            if(input[i][0] == 'A')
                input[i][2] = 'Z';
        }
        else if(input[i][2] == 'Y')
        {
            if(input[i][0] == 'A')
                input[i][2] = 'X';
            if(input[i][0] == 'C')
                input[i][2] = 'Z';
        }
        else if(input[i][2] == 'Z')
        {
            if(input[i][0] == 'C')
                input[i][2] = 'X';
            if(input[i][0] == 'A')
                input[i][2] = 'Y';
        }

        if(input[i][2] == 'X'){

            score += 1;

            temp = input[i][0];
            if(temp == "A"){
                score += 3;
            }
            else if(temp == "B")
            {
                score += 0;
            }
            else{
                score += 6;
            }
            std::cout << "x" << score << std::endl;

        }

        if(input[i][2] == 'Y'){

            score += 2;

            temp = input[i][0];
            if(temp == "A"){
                score += 6;
            }
            else if(temp == "B")
            {
                score += 3;
            }
            else{
                score += 0;
            }
            std::cout << "y" << score << std::endl;

        }
        if(input[i][2] == 'Z'){

            score += 3;

            temp = input[i][0];
            if(temp == "A"){
                score += 0;
            }
            else if(temp == "B")
            {
                score += 6;
            }
            else{
                score += 3;
            }
            std::cout << "z" << score << std::endl;

        }
        std::cout <<input[i] << std::endl;

        if(input[i][0] == 'q')
            break;
    }
    std::cout << score << std::endl;


}
void day1()
{
    std::vector<std::string> newInput;
    std::vector<int> newIntInput;
    std::vector<int> newSums;
    std::vector<std::string> input = {""};

    newInput = splitString(input[0]);

    for (auto const &token: newInput) {
        int value = 0;
        std::string_view k = token;
        std::from_chars(k.begin(), k.end(), value);
        if(token.size() == 0)
            newIntInput.push_back(-1);
        newIntInput.push_back(value);
    }

    newIntInput.push_back(-1);
    int big = 0;
    for(auto const &t : newIntInput)
    {

        if(t == -1)
        {
            newSums.push_back(big);
            big = 0;
            continue;
        }
        big += t;

    }
    sort(newSums.rbegin(), newSums.rend());

    for(auto &k : newSums)
    {
        std::cout << k <<std::endl;
    }


    int sum =0;
    int count = 0;
    for(auto &k : newSums)
    {
        if(count == 3)
            break;
        sum += k;
    }
    std::cout << sum << std::endl;

/*
    int newBig = 0;
    int temp = 0;
    for(auto const &t : newSums)
    {
        if(newBig < t)
            newBig = t;

    }

    std::cout << newBig << std::endl;
*/
/*
}

std::vector<std::string> splitString(const std::string& str)
{
    std::vector<std::string> tokens;

    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find('\n', prev)) != std::string::npos) {
        tokens.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }
    tokens.push_back(str.substr(prev));

    return tokens;

}


 */