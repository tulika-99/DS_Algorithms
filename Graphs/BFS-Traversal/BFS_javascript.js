// BFS

// Graph Implementation
class Graph {
  constructor() {
    this.adjacencyList = {};
  }
  addVertex(vertex) {
    if (!this.adjacencyList[vertex]) {
      this.adjacencyList[vertex] = [];
    }
  }
  addEdge(source, destination) {
    if (!this.adjacencyList[source]) {
      this.addVertex(source);
    }
    if (!this.adjacencyList[destination]) {
      this.addVertex(destination);
    }
    this.adjacencyList[source].push(destination);
    this.adjacencyList[destination].push(source);
  }
  removeEdge(source, destination) {
    this.adjacencyList[source] = this.adjacencyList[source].filter(vertex => vertex !== destination);
    this.adjacencyList[destination] = this.adjacencyList[destination].filter(vertex => vertex !== source);
  }
  removeVertex(vertex) {
    while (this.adjacencyList[vertex]) {
      const adjacentVertex = this.adjacencyList[vertex].pop();
      this.removeEdge(vertex, adjacentVertex);
    }
    delete this.adjacencyList[vertex];
  }
  printGraph(){
    var i
    for (i in this.adjacencyList){
      console.log(i , " : " , this.adjacencyList[i]);
    }
  }
}

// Adding BFS function to the Graph using Queue
Graph.prototype.bfs = function(start) {
    const queue = [start];
    const result = [];
    const visited = {};
    visited[start] = true;
    let currentVertex;
    while (queue.length) {
      currentVertex = queue.shift();
      result.push(currentVertex);
      this.adjacencyList[currentVertex].forEach(neighbor => {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          queue.push(neighbor);
        }
      });
    }
    return result;
}


// Driver Code
g = new Graph()
g.addVertex(1)
g.addVertex(2)
g.addVertex(3)
g.addVertex(4)

g.addEdge(1,2)
g.addEdge(2,3)
g.addEdge(1,3)
g.addEdge(3,4)

console.log("Graph Adjacency List")
g.printGraph()
var node;
for (node = 1; node<=4; node++){
    console.log("BFS from " + node + " => "+ g.bfs(node))
}

/*
Output

Graph Adjacency List
1  :  [ 2, 3 ]
2  :  [ 1, 3 ]
3  :  [ 2, 1, 4 ]
4  :  [ 3 ]
BFS from 1 => 1,2,3,4
BFS from 2 => 2,1,3,4
BFS from 3 => 3,2,1,4
BFS from 4 => 4,3,2,1
*/