#include <vector>
#include <algorithm>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    
    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }
    
    bool unite(int x,int y){
        int px=find(x), py=find(y);
        if(px==py) return false;
        
        if(rank[px]<rank[py])
            parent[px]=py;
        else if(rank[px]>rank[py])
            parent[py]=px;
        else{
            parent[py]=px;
            rank[px]++;
        }
        return true;
    }
};

class Solution {
public:
    
    int kruskal(int n, vector<vector<int>>& edges, int skip, int pick){
        DSU dsu(n);
        int weight=0;
        
        if(pick!=-1){
            dsu.unite(edges[pick][0], edges[pick][1]);
            weight+=edges[pick][2];
        }
        
        for(int i=0;i<edges.size();i++){
            if(i==skip) continue;
            
            if(dsu.unite(edges[i][0], edges[i][1])){
                weight+=edges[i][2];
            }
        }
        
        int root=dsu.find(0);
        for(int i=1;i<n;i++)
            if(dsu.find(i)!=root)
                return 1e9;
        
        return weight;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        int m=edges.size();
        
        for(int i=0;i<m;i++)
            edges[i].push_back(i);
        
        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });
        
        int mstWeight = kruskal(n, edges, -1, -1);
        
        vector<int> critical, pseudo;
        
        for(int i=0;i<m;i++){
            
            if(kruskal(n, edges, i, -1) > mstWeight)
                critical.push_back(edges[i][3]);
            
            else if(kruskal(n, edges, -1, i) == mstWeight)
                pseudo.push_back(edges[i][3]);
        }
        
        return {critical, pseudo};
    }
};
