package Graph;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Graph {
     static class Edge{
        int src;
        int dest;
        public Edge (int src, int dest){
            this.src = src;
            this.dest = dest;
        }
    }

    public static void CreateGraph(ArrayList<Edge>graph[]){
        //node initialize with zero
        for (int i =0;i<graph.length;i++){
            graph[i]=new ArrayList<Edge>();
        }

        graph[0].add(new Edge(0,1));
        graph[0].add(new Edge(0,2));


        graph[1].add(new Edge(1,0));
        graph[1].add(new Edge(1,3));

        graph[2].add(new Edge(2,0));
        graph[2].add(new Edge(2,4));

        graph[3].add(new Edge(3,1));
        graph[3].add(new Edge(3,4));
        graph[3].add(new Edge(3,5));

        graph[4].add(new Edge(4,2));
        graph[4].add(new Edge(4,3));
        graph[4].add(new Edge(4,5));

        graph[5].add(new Edge(5,3));
        graph[5].add(new Edge(5,4));
        graph[5].add(new Edge(5,6));

        graph[6].add(new Edge(6,5));

    }

    public static void bfs(ArrayList<Edge>graph[],boolean[]visited, int v, int index){
        Queue<Integer>q = new LinkedList<>();
//        boolean [] visited = new boolean[v];
        q.add(index);
        int temp;
        while(!q.isEmpty()){
            temp = q.remove();
            if(!visited[temp]){
                System.out.printf(temp + " ");
                visited[temp]=true;
                for(int i=0;i<graph[temp].size();i++){
                    q.add(graph[temp].get(i).dest);
                }
            }
        }
     }

     public static void dfs (ArrayList<Edge>graph[], int curr, boolean visited[]){
         if(!visited[curr]){
             System.out.printf(curr + " ");
             visited[curr]=true;
             for(int i =0;i<graph[curr].size();i++){
                 dfs(graph,graph[curr].get(i).dest,visited);
             }
         }
     }



     public static void allPath_SrcToDest(ArrayList<Edge>graph[],int curr, int dest, boolean vis[], String path){
             if(curr==dest){
                 System.out.println(path);
//                 vis[curr]=false;
                 return;
             }
             for (int i =0;i<graph[curr].size();i++){
                 if(!vis[graph[curr].get(i).dest]){
//                     path=path.concat(String.valueOf(curr));
                     vis[curr]=true;
                     allPath_SrcToDest(graph,graph[curr].get(i).dest,dest,vis,path+graph[curr].get(i).dest);
                     vis[curr]=false;

                 }
             }

     }


    public static void main(String []args){
        int v=7;
        ArrayList<Edge>graph[] = new ArrayList[v];

        CreateGraph(graph);
//        for (int i=0;i<graph[2].size();i++){
//            Edge ed = graph[2].get(i);
//            System.out.print(ed.dest+ " ");
//        }

        boolean []vis=new boolean[v];

//        for (int i=0;i<graph.length;i++) {
//            if (!vis[i]) {
////                bfs(graph, vis, v, i);
//                dfs(graph,0,vis);
//            }
//        }

        String path="";
        allPath_SrcToDest(graph,0,5,vis,"0");
    }
}
