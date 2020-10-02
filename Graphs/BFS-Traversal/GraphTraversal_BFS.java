import java.util.*;

public class Main {
    public static void main(String args[] ) throws Exception {

        Scanner scn=new Scanner(System.in);

        int n = scn.nextInt(); // number of nodes
        int e = scn.nextInt(); // number of edges

        HashMap<Integer,Integer>[] graph=new HashMap[n];
        for(int i=0;i<e;i++)
        {
            int a=scn.nextInt();
            int b=scn.nextInt();

            if(graph[a-1]!=null)
            {
                if(!graph[a-1].containsKey(b-1))
                    graph[a-1].put(b-1,1);
            }
            else
            {
                graph[a-1]=new HashMap<Integer,Integer>();
                graph[a-1].put(b-1,1);
            }

            if(graph[b-1]!=null)
            {
                if(!graph[b-1].containsKey(a-1))
                    graph[b-1].put(a-1,1);
            }
            else
            {
                graph[b-1]=new HashMap<Integer,Integer>();
                graph[b-1].put(a-1,1);
            }
        }

        // BFS
        HashMap<Integer,Boolean> processed =new HashMap<>();

        LinkedList<Integer> Queue=new LinkedList<>();
        Queue.add(0);
        processed.put(0,true);
        
        while(!Queue.isEmpty())
        {
            int node=Queue.remove(0);

            if(graph[node]!=null)
            {
                System.out.println(node+1);
                for(int key: graph[node].keySet())
                {   
                    if(!processed.containsKey(key))
                    {
                        Queue.add(key);
                        processed.put(key,true);
                    }
                }
            }
        }
    }
}
