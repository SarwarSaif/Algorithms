#include <bits/stdc++.h>

using namespace std;

int vt,ed,t;
int parent[100],color[100];
int white = 0,gray = 1 , black = 2;
bool grid[100][100];
stack <int> S;

void DFS(int u)
{
    int i,j;
    color[u] = gray;
    for(i = 1 ; i <= vt ; i++)
    {
        if(grid[u][i] != false)
        {
            if(color[i] == white)
            {
                
                DFS(i);
            }
        }
    }
    color[u] = black;
    S.push(u);
}

int main()
{
    int a,b;
    int topo[100];
    int c = 1;
    printf("Vertex : ");
    scanf("%d",&vt);
    printf("Edge : ");
    scanf("%d",&ed);
    printf("Enter Relations (u,v) \n\n");
    for(int i = 1 ; i <= ed ; i++)
    {
        scanf("%d%d",&a,&b);
        grid[a][b]=true;
    }
    for(int i = 1 ; i <= vt ; i++)
    {
        //parent[i] = -1;
        color[i] = white;
    }
    t = 0;
    for(int i = 1 ; i <= vt ; i++)
    {
        if(color[i] == white)
        {
            DFS(i);
        }
    }
    while(S.empty()!= true)
    {
        topo[c++] = S.top();
        cout<<S.top()<<" ";
        S.pop();
    }
    
}
