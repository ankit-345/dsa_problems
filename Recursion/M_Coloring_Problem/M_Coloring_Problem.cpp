// Problem Statement: Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color.


// Input: 
// N = 4
// M = 3
// E = 5
// Edges[] = { (0, 1), (1, 2), (2, 3), (3, 0), (0, 2) }
// Output: 1

// Explanation: It is possible to colour the given graph using 3 colours.

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], int m, int N, bool graph[101][101], int col){
    for(int k=0; k<N; k++){              // traversing the graph
        if(k != node && graph[k][node] == 1 && color[k] == col){   // checking whether the adjacent node have same color or not
//       (K!=node => should not be a same node, 
//        graph[k][101] == 1 => whether adjacent node exist or not, 
//       color[k] == col => whether the color is the same or not )
            return false;                                         // if Yes, then return false
        }
    }
    return true;                        // If there is not same color, then return true
}

bool solve(int node, int color[], int m, int N, bool graph[101][101]){
    if(node == N){
        return true;
    }

    for(int i=1; i<=m; i++){    // Here we are trying out every colors from 1 to m at every node
        if(isSafe(node, color, m, N, graph, i)){   // Checking if it is possible to color the node, 
            color[node] = i;                       // it it is, then color the node
            if(solve(node+1, color, m, N, graph)){   // and move to the next node, if upon returning it return true, that means we got our answer ,then return true
                return true;
            }
            color[node] = 0;                            // If upon returning it return false, then remove the color which was added above
        }
    }
    return false;              // If none of the colors is possible from 1 to m, then return false.
}


bool graphColoring(bool graph[101][101], int m, int N){
    int color[N] = {0};
    if(solve(0, color, m, N, graph)) return true;
    return false;
}

int main(){
    int N=4;
    int m=3;

    bool graph[101][101];
  memset(graph, false, sizeof graph);

  // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
  graph[0][1] = 1; graph[1][0] = 1;
  graph[1][2] = 1; graph[2][1] = 1;
  graph[2][3] = 1; graph[3][2] = 1;
  graph[3][0] = 1; graph[0][3] = 1;
  graph[0][2] = 1; graph[2][0] = 1;
  
  cout << graphColoring(graph, m, N);

}