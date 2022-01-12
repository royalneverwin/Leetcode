class Solution {
public:
    // 法1: 提前结束的BFS
    // 我们可以看到障碍物不超过200个, 且步数无限制
    // 那么不能到达的唯一条件是障碍物包围source或包围target
    // 200个障碍物最多能包围多少个非障碍物？
    // 在边角包围, n个障碍物最多包围n(n-1) / 2个
    // 10^12太大了, 不能用bool判断是否访问过, 也不可以用set存放访问过的点, 一个超时, 一个超时间
    // 用unordered, 也不能直接用. 因为pair没有hash函数, 所以要自定义hash函数

    // 进一步简化, 先把pair转化int再存到unordered_set

    typedef pair<int, int> pair;
    // return 1表示到终点了, return 0表示没到终点
    bool Insert(int x, int y, queue<pair>& qu, unordered_set<long long>& us,
                vector<int>& point, int& cnt){
        if(x == point[0] && y == point[1]){ // 到终点
            return true;
        }
        else if(us.find(((long long)x << 20) + (long long)y) == us.end()){ // 不是block也没被访问过
            qu.push(make_pair(x, y));
            us.insert(((long long)x << 20) + (long long)y);
            cnt++;
        }
        return false;
    }

    bool isSubEscape(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target, int n){
        queue<pair> qu;
        qu.push(make_pair(source[0], source[1]));
        unordered_set<long long> us;
        // 把blocked全存进去
        for(int i = 0; i < blocked.size(); i++){
            us.insert(((long long)blocked[i][0] << 20) + (long long)blocked[i][1]);
        }
        us.insert(((long long)source[0] << 20) + (long long)source[1]);
        int cnt = 1;
        while(!qu.empty()){
            pair tmp = qu.front();
            qu.pop();
            if(tmp.first != 0){
                if(Insert(tmp.first - 1, tmp.second, qu, us, target, cnt))
                    return true;
            }
            if(tmp.first != 1000000 - 1){
                if(Insert(tmp.first + 1, tmp.second, qu, us, target, cnt))
                    return true;
            }
            if(tmp.second != 0){
                if(Insert(tmp.first, tmp.second - 1, qu, us, target, cnt))
                    return true;
            }
            if(tmp.second != 1000000 - 1){
                if(Insert(tmp.first, tmp.second + 1, qu, us, target, cnt))
                    return true;
            }
            if(cnt > n)
                break;
        }
        if(cnt <= n)
            return false;
        return true;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int n = blocked.size();
        n = n * (n + 1) / 2;
        // 先判断起点有没有被围住, 再判断终点有没有被位置
        if(isSubEscape(blocked, source, target, n) && isSubEscape(blocked, target, source, n))
            return true;
        return false;
    }
};





class Solution {
public:
    // 难点一: 提前结束的BFS
    // 我们可以看到障碍物不超过200个, 且步数无限制
    // 那么不能到达的唯一条件是障碍物包围source或包围target
    // 200个障碍物最多能包围多少个非障碍物？
    // 在边角包围, n个障碍物最多包围n(n-1) / 2个
    // 难点二：自定义hash函数的unordered_set
    // 10^12太大了, 不能用bool判断是否访问过, 也不可以用set存放访问过的点, 一个超时, 一个超时间
    // 用unordered, 也不能直接用. 因为pair没有hash函数, 所以要自定义hash函数

    typedef pair<int, int> pair;
    class MyHash{
    public:
        size_t operator () (const pair& p) const noexcept{
            return (p.first << 5) + p.second;
        }
    };

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int length = blocked.size();
        // 10^12太大了, 没必要用bool判断是否访问过, 可以用set存放访问过的点（不能用unordered）
        int x, y;
        int cnt = 1;
        int n = blocked.size();
        n = n * (n + 1) / 2;
        // 先判断起点有没有被围住
        queue<pair> qu;
        qu.push(make_pair(source[0], source[1]));
        MyHash myhash;
        unordered_set<pair, MyHash> us;
        // 把blocked全存进去
        for(int i = 0; i < blocked.size(); i++){
            us.insert(make_pair(blocked[i][0], blocked[i][1]));
        }
        us.insert(make_pair(source[0], source[1]));
        while(!qu.empty()){
            pair tmp = qu.front();
            qu.pop();
            if(tmp.first != 0){
                x = tmp.first - 1;
                y = tmp.second;
                vector<int> tmp = {x, y};
                if(tmp == target) // 到终点
                    return true;
                else if(us.find(make_pair(tmp[0], tmp[1])) == us.end()){ // 不是block也没被访问过
                    qu.push(make_pair(tmp[0], tmp[1]));
                    us.insert(make_pair(tmp[0], tmp[1]));
                    cnt++;
                }
            }
            if(tmp.first != 1000000 - 1){
                x = tmp.first + 1;
                y = tmp.second;
                vector<int> tmp = {x, y};
                if(tmp == target) // 到终点
                    return true;
                else if(us.find(make_pair(tmp[0], tmp[1])) == us.end()){ // 不是block也没被访问过
                    qu.push(make_pair(tmp[0], tmp[1]));
                    us.insert(make_pair(tmp[0], tmp[1]));
                    cnt++;
                }
            }
            if(tmp.second != 0){
                x = tmp.first;
                y = tmp.second - 1;
                vector<int> tmp = {x, y};
                if(tmp == target) // 到终点
                    return true;
                else if(us.find(make_pair(tmp[0], tmp[1])) == us.end()){ // 不是block也没被访问过
                    qu.push(make_pair(tmp[0], tmp[1]));
                    us.insert(make_pair(tmp[0], tmp[1]));
                    cnt++;
                }
            }
            if(tmp.second != 1000000 - 1){
                x = tmp.first;
                y = tmp.second + 1;
                vector<int> tmp = {x, y};
                if(tmp == target) // 到终点
                    return true;
                else if(us.find(make_pair(tmp[0], tmp[1])) == us.end()){ // 不是block也没被访问过
                    qu.push(make_pair(tmp[0], tmp[1]));
                    us.insert(make_pair(tmp[0], tmp[1]));
                    cnt++;
                }
            }
            if(cnt > n)
                break;
        }
        if(cnt <= n)
            return false;
        // 再判断终点有没有被位置
        cnt = 1;
        while(!qu.empty())
            qu.pop();
        us.clear();
        qu.push(make_pair(target[0], target[1]));
        // 把blocked全存进去
        for(int i = 0; i < blocked.size(); i++){
            us.insert(make_pair(blocked[i][0], blocked[i][1]));
        }
        us.insert(make_pair(target[0], target[1]));
        while(!qu.empty()){
            pair tmp = qu.front();
            qu.pop();
            if(tmp.first != 0){
                x = tmp.first - 1;
                y = tmp.second;
                vector<int> tmp = {x, y};
                if(tmp == source) // 到起点
                    return true;
                else if(us.find(make_pair(tmp[0], tmp[1])) == us.end()){ // 不是block也没被访问过
                    qu.push(make_pair(tmp[0], tmp[1]));
                    us.insert(make_pair(tmp[0], tmp[1]));
                    cnt++;
                }
            }
            if(tmp.first != 1000000 - 1){
                x = tmp.first + 1;
                y = tmp.second;
                vector<int> tmp = {x, y};
                if(tmp == source) // 到起点
                    return true;
                else if(us.find(make_pair(tmp[0], tmp[1])) == us.end()){ // 不是block也没被访问过
                    qu.push(make_pair(tmp[0], tmp[1]));
                    us.insert(make_pair(tmp[0], tmp[1]));
                    cnt++;
                }
            }
            if(tmp.second != 0){
                x = tmp.first;
                y = tmp.second - 1;
                vector<int> tmp = {x, y};
                if(tmp == source) // 到起点
                    return true;
                else if(us.find(make_pair(tmp[0], tmp[1])) == us.end()){ // 不是block也没被访问过
                    qu.push(make_pair(tmp[0], tmp[1]));
                    us.insert(make_pair(tmp[0], tmp[1]));
                    cnt++;
                }
            }
            if(tmp.second != 1000000 - 1){
                x = tmp.first;
                y = tmp.second + 1;
                vector<int> tmp = {x, y};
                if(tmp == source) // 到起点
                    return true;
                else if(us.find(make_pair(tmp[0], tmp[1])) == us.end()){ // 不是block也没被访问过
                    qu.push(make_pair(tmp[0], tmp[1]));
                    us.insert(make_pair(tmp[0], tmp[1]));
                    cnt++;
                }
            }
            if(cnt > n)
                break;
        }
        if(cnt <= n)
            return false;
        return true;
    }
};