import java.util.*;

public class Dijkstra {

    HashMap<String,ArrayList<Node>> hm;

    public class Node {
        String vertex;
        int weight;

        Node(String v, int w) {
            this.vertex = v;
            this.weight = w;
        }
    }

    Dijkstra() {
        hm = new HashMap<String,ArrayList<Node>>();
    }

    public static void main(String [] args) throws Exception {

        Dijkstra ob = new Dijkstra();
        ob.addVertex("A");
        ob.addVertex("B");
        ob.addVertex("C");
        ob.addVertex("D");
        ob.addVertex("E");
        ob.addVertex("F");
        ob.addEdge("A", "B", 4);
        ob.addEdge("A", "C", 2);
        ob.addEdge("C", "D", 2);
        ob.addEdge("C", "F", 4);
        ob.addEdge("D", "F", 1);
        ob.addEdge("B", "E", 3);
        ob.addEdge("E", "D", 3);
        ob.addEdge("F", "E", 1);

        //shortest path A to E 
        System.out.println("Shortest Path from A to E : ");
        ob.dijkstraShortestPath("A", "E");
        
    }

    public void addVertex(String v) {
        this.hm.put(v, new ArrayList<Node>());
    }

    public void addEdge(String v1, String v2, int weight) {
        if(this.hm.containsKey(v1) == false || this.hm.containsKey(v2) == false)
            return;
        Node node1 = new Node(v2, weight);
        Node node2 = new Node(v1, weight);
        this.hm.get(v1).add(node1);
        this.hm.get(v2).add(node2);
    }

    public void print() {
        for(String i : this.hm.keySet()) {
            System.out.println("Vertex " + i + " Edges -> " );
            for(Node n : this.hm.get(i)) 
                System.out.println(n.vertex + " " + n.weight);
        }
    }

    public class QueueNode {
        String val;
        int priority;
        QueueNode(String str, int priority) {
            this.val = str;
            this.priority = priority;
        }
    }

    public class MyComparator implements Comparator<QueueNode> {
        @Override
        public int compare(QueueNode o1, QueueNode o2) {
            return o1.priority - o2.priority;
        }
    }

    public void dijkstraShortestPath(String src, String dest) {
        PriorityQueue<QueueNode> queue = new PriorityQueue<QueueNode>(new MyComparator()); 
        HashMap<String, Integer> table = new HashMap<>();
        HashMap<String, Boolean> visited = new HashMap<>();
        HashMap<String, String> previous = new HashMap<>();
        
        for(String s : this.hm.keySet()) {
            if(s.equals(src)) {
                QueueNode node = new QueueNode(s, 0);
                queue.add(node);
                table.put(s, 0);
            }
            else {
                table.put(s, Integer.MAX_VALUE);
            }
            visited.put(s, false);
            previous.put(s, null);
        }

        
        while(!queue.isEmpty()) {

            String smallest = queue.remove().val;
            ArrayList<Node> neighbours = this.hm.get(smallest);
            visited.put(smallest, true);

            for(Node n : neighbours) {
                String v = n.vertex;
                int w = n.weight;

                if(visited.get(v) == false) {
                    if(w + table.get(smallest) < table.get(v)) {
                        table.put(v, w + table.get(smallest));
                        previous.put(v, smallest);
                        QueueNode q = new QueueNode(v, w + table.get(smallest));
                        queue.add(q);
                    }
                }
            }

        }

        String s = previous.get(dest);
        ArrayList<String> soln = new ArrayList<>();

        while(!s.equals(src)) {
            soln.add(s);
            s = previous.get(s);
        }

        System.out.print(src + " ");
        for(int i = soln.size() - 1; i >= 0; i--) {
            System.out.print(soln.get(i)+ " ");
        }
        System.out.print(dest + " ");
        System.out.println();
  
    }
    
}