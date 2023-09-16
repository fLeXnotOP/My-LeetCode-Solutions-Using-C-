class Solution {
public: 
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

    vector<int> p(edges.size() + 1, -1);
    vector<int> rank(edges.size() + 1, 1);
    
    function<int(int)> find;
    
    find = [&p, &find] (int x) {
        if (p[x] == -1) return x;
        return p[x] = find(p[x]);
    };
    
    auto dunion = [&p, &rank](int px, int py){
        if (rank[px] < rank[py]){
            p[px] = py;
        } else if (rank[px] > rank[py]) {
            p[py] = px;
        } else {
            p[px] = py;
            ++rank[py];
        }
    };
    for (auto &edge : edges){
        int px = find(edge[0]);
        int py = find(edge[1]);
        if (px == py)
            return edge;
        dunion(px, py);
    }
    
    return vector<int>();
}
};