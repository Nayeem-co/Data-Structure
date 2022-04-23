#include<stdio.h>
#include<stdlib.h>

int no_vertices;
// copilor genarated code

void dfs(int** edges, int n, int sv, int * v){
    
}
void bfs(int start, int adj[][no_vertices]){
    int visited[no_vertices];
    int queue[no_vertices];
    int front = -1;
    int rear = -1;
    int i, j;
    for(i = 0; i < no_vertices; i++){
        visited[i] = 0;
    }
    visited[start] = 1;
    queue[++rear] = start;
    while(front != rear){
        start = queue[++front];
        printf("%d ", start);
        for(j = 0; j < no_vertices; j++){
            if(adj[start][j] == 1 && visited[j] == 0){
                visited[j] = 1;
                queue[++rear] = j;
            }
        }
    }
}
// youtube guy code
void bfs(int adj[][no_vertices], int start){

	int visited[no_vertices],queue[no_vertices],front=-1,rear=-1;

	for(int i=0;i<no_vertices;i++)
		visited[i] =0;

	front++;
	queue[++rear] = start;
	visited[start] = 1;

	while(front<=rear)
	{
		start = queue[front++];
		printf("%d\t",start);

		for(int i=0;i<no_vertices;i++)
		{
			if(adj[start][i]==1 && visited[i] != 1)
			{
				queue[++rear] = i;
				visited[i] =1;
			}
		}


	}

}

int main(int argc, char const *argv[]){

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
    bfs(adj,start);
    
    return 0;
}
