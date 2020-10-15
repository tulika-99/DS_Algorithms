// DFS

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

// Adding DFS function to the Graph using Recursion
Graph.prototype.dfsRecursive = function(start) {
    const result = [];
    const visited = {};
    const adjacencyList = this.adjacencyList;
    (function dfs(vertex){
      if (!vertex) return null;
      visited[vertex] = true;
      result.push(vertex);
      adjacencyList[vertex].forEach(neighbor => {
          if (!visited[neighbor]) {
            return dfs(neighbor);
          }
      })
    })(start);
    return result;
}

// Adding DFS function to the Graph using Stack
Graph.prototype.dfsIterative = function(start) {
    const result = [];
    const stack = [start];
    const visited = {};
    visited[start] = true;
    let currentVertex;
    while (stack.length) {
      currentVertex = stack.pop();
      result.push(currentVertex);
      this.adjacencyList[currentVertex].forEach(neighbor => {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          stack.push(neighbor);
        }
      });
    }
    return result;
}

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
    console.log("DFS from " + node + " => "+ g.dfsRecursive(node))
}

/*
Output

Graph Adjacency List
1  :  [ 2, 3 ]
2  :  [ 1, 3 ]
3  :  [ 2, 1, 4 ]
4  :  [ 3 ]
DFS from 1 => 1,2,3,4
DFS from 2 => 2,1,3,4
DFS from 3 => 3,2,1,4
DFS from 4 => 4,3,2,1
*/