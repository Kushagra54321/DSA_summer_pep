// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int findmin(vector<int>dist,vector<bool>visit){
    int idx=-1;
    int min=INF;
    for(int i=0;i<adj.size();i++){
        if(dist[i] < min && visit[i]==false){
            min=dist[i];
            idx=i;
        }
    }
    return idx;
}
vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int src) {
    vector<int>dist(adj.size(),INF);
    vector<bool>vist(adj.size(),false);
    dist[src]=0;
    
    for(int i=0;i<adj.size();i++){
        int u=findmin(dist,visit);
    }
    
    
    
    
}

int main() {
     int src = 0;

    vector<vector<pair<int,int>>> adj(5);
    adj[0] = {{1,4}, {2,8}};
    adj[1] = {{0,4}, {4,6}, {2,3}};
    adj[2] = {{0,8}, {3,2}, {1,3}};
    adj[3] = {{2,2}, {4,10}};
    adj[4] = {{1,6}, {3,10}};
    
    vector<int> result = dijkstra(adj, src);


    return 0;
}