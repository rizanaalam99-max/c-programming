#include <stdio.h>
#define MAX 20
struct edge {
    int u, v, w;
};
int parent[MAX];
int find(int i) {
	while (parent[i] != i)
	     i = parent[i];
	return i;	
}
void union_set(int i, int j) {
	int a = find(i);
	int b = find(j);
	parent[a] = b; 
}
int main() {
	struct edge edges[MAX];
	int n, e;
	int totalcost = 0;
	 
	printf("enter number of vertices: ");
	scanf("%d", &n);
	printf("enter number of edges: ");
	scanf("%d", &e);
	
	printf("enter each edge (u v weight):\n");
	for (int i = 0; i < e; i++) {
		scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
	}
	for (int i = 0; i < e - 1; i++) {
		for (int j = 0; j < e - 1; j++){
			if (edges[j].w > edges[j + 1].w) {
				struct edge temp = edges[j];
				edges[j] = edges[j + 1];
				edges[j + 1] = temp;
			}
		}
		
	}
	    for (int i = 0; i < n; i++)
	    parent[i] = i;
	printf("\nedges in the minimum spanning tree:\n");
	int count = 0;
	for (int i = 0; i < e && count < n - 1; i++) {
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;
		int pu = find(u);
		int pv = find(v);
		 if (pu != pv) {
		 	printf("%d - %d\n", u, v, w);
		 	totalcost += w;
		 	union_set(pu, pv);
		 	count++;
		 }	
	}  
	printf("\ntotal cost of MST = %d\n", totalcost);
	return 0;  
 
 }

