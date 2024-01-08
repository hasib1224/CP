package Graph;

import java.util.*;

public class Graph {
     static class Edge{
        int src;
        int dest;
        public Edge (int src, int dest){
            this.src = src;
            this.dest = dest;
        }
    }

    public static void CreateUndirectGraph(ArrayList<Edge>graph[]){
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

    public static void CreateDirectGraph(ArrayList <Edge> graph[]){
         for(int i=0;i< graph.length;i++){
             graph[i]=new ArrayList<Edge>();
         }
         graph[0].add(new Edge(0,2));

         graph[1].add(new Edge(1,0));

         graph[2].add(new Edge(2,3));

//         graph[3].add(new Edge(3,0));


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

    public static boolean isCycleDirectedGraph(ArrayList<Edge>graph[],boolean visited[],boolean recStack[], int curr){
     visited[curr]=true;
     recStack[curr]=true;

     for(int i=0;i<graph[curr].size();i++){
         if(!visited[graph[curr].get(i).dest]){
           if(isCycleDirectedGraph(graph,visited,recStack,graph[curr].get(i).dest)){
               return true;
           }
         }else if(recStack[graph[curr].get(i).dest]){
             return true;
         }
     }
     recStack[curr]=false;

     return false;
    }






        public static class Cell{
            int row;
            int col;
            public Cell(int x, int y){
                this.row=x;
                this.col=y;
            }
        }


    public static int orangesRotting(int[][] grid) {
        Queue<Cell>q = new LinkedList<>();
        int [][]dirs={{1,0},{-1,0},{0,1},{0,-1}};
        int total=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==2){
                    q.add(new Cell(i,j));
                    total++;
                }else if(grid[i][j]==1){
                    total++;
                }
            }
        }

        int minimumMin=0;
        if(q.size()==total){
            return minimumMin;
        }else{
            total=total-q.size();
            while(!q.isEmpty() && total>0){
                minimumMin++;
                int qSize=q.size();
                for(int i=0;i<qSize;i++){
                    Cell temp=q.remove();
                    int r=temp.row;
                    int c=temp.col;
                    for(int[]dir: dirs){
                        int nr=r+dir[0];
                        int nc=c+dir[1];
                        if (nr>=0 && nc>=0 && nr<grid.length && nc<grid[0].length && grid[nr][nc]==1){
                            grid[nr][nc]=2;
                            q.add(new Cell(nr,nc));
                            --total;
                        }
                    }
                }

            }
            if(total==0){
                return minimumMin;
            }else return -1;

        }

    }


    //...................Nearest Exit from mazeeee...............
   static class Solution {
        public static class Cell {
            int row;
            int col;
            int dis;
            public Cell(int row, int col,int dis){
                this.row=row;
                this.col=col;
                this.dis=dis;
            }
        }

        public int nearestExit(char[][] maze, int[] entrance) {
            int [][]dirs={{0,1},{-1,0},{1,0},{0,-1}};
            Queue <Cell>q=new LinkedList<>();
            q.add(new Cell(entrance[0],entrance[1],0));

            while(!q.isEmpty()){
                Cell temp = q.remove();
                int row=temp.row;
                int col=temp.col;
                int dis=temp.dis;
                if((row==0||col==0||row==maze.length-1||col==maze[0].length-1) &&(row!=entrance[0] || col!=entrance[1])){
                    return dis;
                }

                for(int[]dir:dirs){
                    int nr=row+dir[0];
                    int nc=col+dir[1];
                    if(nr>=0 && nc>=0 && nr<maze.length && nc<maze[0].length && maze[nr][nc]!='+'){
                        q.add(new Cell(nr,nc,dis+1));
                        maze[nr][nc]='+';
                    }
                }
                // maze[row][col]='+';

            }
            return -1;
        }
    }

    //...............Rotting Oranges.............
    static class Solution2 {
        public static class Cell{
            int row;
            int col;
            public Cell(int x, int y){
                this.row=x;
                this.col=y;
            }
        }
        public static int orangesRotting(int[][] grid) {
            Queue<Cell>q = new LinkedList<>();
            int [][]dirs={{1,0},{-1,0},{0,1},{0,-1}};
            int total=0;
            for(int i=0;i<grid.length;i++){
                for(int j=0;j<grid[0].length;j++){
                    if(grid[i][j]==2){
                        q.add(new Cell(i,j));
                        total++;
                    }else if(grid[i][j]==1){
                        total++;
                    }
                }
            }

            int minimumMin=0;
            if(q.size()==total){
                return minimumMin;
            }else{
                total=total-q.size();
                while(!q.isEmpty() && total>0){
                    minimumMin++;
                    int qSize=q.size();
                    for(int i=0;i<qSize;i++){
                        Cell temp=q.remove();
                        int r=temp.row;
                        int c=temp.col;
                        for(int[]dir: dirs){
                            int nr=r+dir[0];
                            int nc=c+dir[1];
                            if (nr>=0 && nc>=0 && nr<grid.length && nc<grid[0].length && grid[nr][nc]==1){
                                grid[nr][nc]=2;
                                q.add(new Cell(nr,nc));
                                --total;
                            }
                        }
                    }
                }
                if(total==0){
                    return minimumMin;
                }else return -1;

            }
        }
    }




    public static void main(String []args){
        int v=7;
        ArrayList<Edge>graph[] = new ArrayList[v];

        CreateUndirectGraph(graph);

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

//        String path="";
//        allPath_SrcToDest(graph,0,5,vis,"0");


        CreateDirectGraph(graph);
        boolean [] visited=new boolean[4];
        boolean[] recStack=new boolean[4];
        boolean ans=false;
//        for(int i=0;i<4;i++){
//            ans=isCycleDirectedGraph(graph,visited,recStack,0);
//            if(ans){
//                System.out.println("Cycle Asee vaiya");
//                break;
//            }
//        }
//        if(!ans){
//            System.out.println("Cycle nehi hain");
//        }


//        int [][]grid = {{2,1,1},{1,1,0},{0,1,1}};
//        System.out.println(orangesRotting(grid));
//        orangesRotting(grid);

        long a=(long)Math.pow(31,12);
        System.out.println((long)Math.pow(31,12));
        System.out.println((long)Math.pow(31,12)%(long)24);
        System.out.println(a%10);




    }
}
