#include "Graph.h"


Node* Graph::addNode(int value){
    // TODO 
    // Hint: use findNode() to check if the node exists
    if (findNode(value) != nullptr) {
        return findNode(value);
    }
    else {
        Node* node = new Node(value);
        nodes.push_back(node);
        visited[node] = false;
        return node;
    }
}

Node* Graph::findNode(int value){
    // TODO 
    // Return the node if it exists, otherwise return nullptr
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->value == value) {
            return nodes[i];
        }
    }
    return nullptr;
}

Edge* Graph::addEdge(Node* node1, Node* node2){
    // TODO 
    // Hint: use findEdge() to check if the edge exists
    if (findEdge(node1, node2) != nullptr) {
        return findEdge(node1, node2);
    }
    else {
        Edge* edge = new Edge(node1, node2);
        node1->neighbors.push_back(node2);
        node2->neighbors.push_back(node1);
        edges.push_back(edge);
        return edge;
    }
    
}

Edge* Graph::findEdge(Node* node1, Node* node2){
    // TODO 
    // Return the edge if it exists, otherwise return nullptr
    for (int i = 0; i < edges.size(); i++) {
        if ( (edges[i]->node1 == node1 && edges[i]->node2 == node2) ||
             (edges[i]->node1 == node2 && edges[i]->node2 == node1)    ) {
            return edges[i];
        }
    }
    return nullptr;
}

void Graph::BFS(vector<int>& answer){
    // TODO
    // Implement BFS using a queue
    // Hint: Node* startNode = nodes[0];
    // Hint: Use a queue
    queue<Node* > bfs;
    bfs.push(nodes[0]);
    visited[nodes[0]] = true;
    while (!bfs.empty()) {
        Node* node = bfs.front();
        bfs.pop();
        answer.push_back(node->value);
        for (int i = 0; i < node->neighbors.size(); i++) {
            if (visited.at(node->neighbors[i]) == false) {
                bfs.push(node->neighbors[i]);
                visited[node->neighbors[i]] = true;
            }
        }
    }
}
