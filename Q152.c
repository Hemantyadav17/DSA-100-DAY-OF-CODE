// Given a reference of a node in a connected undirected graph. Return a deep copy (clone) of the graph. 
//Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

#include <stdio.h>
#include <stdlib.h>

#define MAX 101

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

// map: original -> cloned
struct Node* visited[MAX];

struct Node* cloneGraph(struct Node* node) {
    if (node == NULL) return NULL;

    // if already cloned
    if (visited[node->val] != NULL)
        return visited[node->val];

    // create new node
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    visited[node->val] = clone;

    // clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = cloneGraph(node->neighbors[i]);
    }

    return clone;
}