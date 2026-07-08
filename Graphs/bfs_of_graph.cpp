// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>>graph(5);
vector<int> bfs(int s){
    vector<bool>visit(5,false);
    vector<int> result;
    queue<int>q;
    q.push(s);
    visit[s] = true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        result.push_back(curr);
        for(int i=0;i<graph[s].size();i++){
            int v=graph[curr][i];
            if(visit[v]==false){
                visit[v]=true;
                q.push(v);
            }
        }
    }
    return result;
}
void addedge(int u,int v){
    graph[u].push_back(v);
}
int main() {
    // int n=5;
    // vector<vector<int>>graph(5);
    addedge(0,1);
    addedge(0,2);
    addedge(1,0);
    addedge(1,3);
    addedge(1,4);
    addedge(2,0);
    addedge(2,3);
    addedge(3,1);
    addedge(3,2);
    addedge(3,4);
    addedge(4,1);
    addedge(4,3);
    vector<int> res = bfs(0);

    for (int i : res)
        cout << i << " ";
    
    return 0;
}