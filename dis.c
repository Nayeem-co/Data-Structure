#include<stdio.h>
int no_vertices = 5;


void dfs(int adj[][no_vertices], int n, int sv,int * visited){
    int i;
    visited[sv] = 1;
    printf("%d ", sv);
    for(i = 0; i < n; i++){
        if(adj[sv][i] == 1 && visited[i] == 0){
            dfs(adj, n, i, visited);
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("Enter the number of vertices: ");
    scanf("%d",&no_vertices);
    int adj[no_vertices][no_vertices];
    printf("Enter the adjacency matrix: \n");
    for(int i=0;i<no_vertices;i++)
    {
        for(int j=0;j<no_vertices;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    int start;
    scanf("%d",&start);
    int visited[no_vertices];
    for(int i=0;i<no_vertices;i++)
    {
        visited[i] = 0;
    }
    dfs(adj, no_vertices, start, visited);
    return 0;
}
