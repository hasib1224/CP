package Tree;
import java.util.*;
import java.lang.Math;


public class BinaryTree {
    static class  Node {
        int data;
        Node left;
        Node right;
        Node(int value){
            this.data=value;
        }
    }

    static class treeInfo{
        int height;
        int diameter;
        treeInfo(int height,int diameter){
            this.diameter=diameter;
            this.height=height;
        }
    }

    static class buildTree{
        int index=-1;

        public Node build(int[]nodes){
            index++;
            Node newNode = new Node(nodes[index]);
            if(nodes[index]==-1){
                return null;
            } else  {
                newNode.left=build(nodes);
                newNode.right=build(nodes);
                return newNode;
            }

        }
    }

    public static void preOrder(Node root){
        if(root!=null) {
            System.out.print(root.data + " ");
        }else return;
        preOrder(root.left);
        preOrder(root.right);
    }

    public static void inOrder(Node root){
        if(root==null){
            return;
        }
        inOrder(root.left);
        System.out.print(root.data+ " ");
        inOrder(root.right);
    }

    public static void postOrder (Node root){
        if(root==null){
            return;
        }
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.data + " ");
    }

    public static void levelOrderTraverse(Node root){
        if(root==null){
            return;
        }
        Queue<Node>nodes=new LinkedList<>();
        nodes.add(root);
        nodes.add(null);

        while(!nodes.isEmpty()){
            Node currNode = nodes.remove();
            if(currNode==null){
                System.out.println();
                if(!nodes.isEmpty()){
                    nodes.add(null);
                }else{
                    break;
                }
            }else {
                System.out.print(currNode.data+" ");
                if(currNode.right!=null){
                    nodes.add(currNode.right);
                }
                if(currNode.left!=null){
                    nodes.add(currNode.left);
                }
            }
        }
    }

    public static List<Integer>rightView (Node root){
        Queue <Node> level = new LinkedList<>();
       List<Integer>rightSide = new ArrayList<>();

        level.add(root);
        level.add(null);
        while(!level.isEmpty()){
            Node currNode = level.remove();
            if(currNode==null){
                if(!level.isEmpty()){
                    level.add(null);
                }else{
                    break;
                }
            }else{
                if(level.peek()==null){
                    rightSide.add(currNode.data);
                }
                if(currNode.right!=null){
                    level.add(currNode.right);
                }
                if (currNode.left!=null) {
                    level.add(currNode.left);
                }
            }
        }
        return rightSide;
    }


    public static int nodeCounts(Node root){
        if(root==null){
            return 0;
        }
        int right;
        int left;
        left=nodeCounts(root.left);
        right=nodeCounts(root.right);
        return left+right +1;
    }

    public static int sumOfNodes(Node root){
        if(root==null){
            return 0;
        }
        int leftSum;
        int rightSum;
        leftSum=sumOfNodes(root.left);
        rightSum=sumOfNodes(root.right);
        return leftSum+rightSum +root.data;
    }

    public static int heightOfTree(Node root){
        if(root==null){
            return 0;
        }
        int leftHeight = heightOfTree(root.left);
        int rightHeight = heightOfTree(root.right);
        if(leftHeight>=rightHeight){
            return leftHeight +1;
        }else {
            return rightHeight +1;
        }
    }

    public static int diameterOfTree1(Node root){
        if(root==null){
            return 0;
        }
        int leftSubDiameter = diameterOfTree1(root.left);
        int rightSubDiameter= diameterOfTree1(root.right);
        int leftHeight=heightOfTree(root.left);
        int rightHeight=heightOfTree(root.right);
        int height = leftHeight+rightHeight+1;
        return Math.max(Math.max(leftSubDiameter,rightSubDiameter),height);
    }

    public static treeInfo diameterOftree2(Node root){

        if(root==null){
            return new treeInfo(0,0);
        }

        treeInfo leftDiam= diameterOftree2(root.left);
        treeInfo rightDiam=diameterOftree2(root.right);

        int myHeight = Math.max(leftDiam.height,rightDiam.height)+1;

        int diam1 = leftDiam.diameter;
        int diam2 = rightDiam.diameter;
        int diam3 = leftDiam.height + rightDiam.height +1;
        int diam=Math.max(Math.max(diam1,diam2),diam3);

        treeInfo info = new treeInfo(myHeight,diam);
        return info;

    }


    //..........Binary treee right side View...........

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
              this.val = val;
              this.left = left;
              this.right = right;
        }
    }


    static class Solution {

        public LinkedList<Integer>traverse(TreeNode root,int height,LinkedList<Integer>list){
            if(root==null){
                return list;
            }else{
                height++;
                if(list.size()<height){
                    list.add(root.val);
                }
                traverse(root.right,height,list);
                traverse(root.left,height,list);
                height--;
            }
            return list;
        }

        //...........................




        public List<Integer> rightSideView(TreeNode root) {

            LinkedList<Integer>rightSide = new LinkedList<>();
            rightSide = traverse(root,0,rightSide);

            return rightSide;

        }
    }


    //.....979. Distribute Coins in Binary Tree.....
    static int result=0;
    public static int soltn(Node root){
        int moves;
        if(root==null){
            return 0;
        }

        int lmoves=soltn(root.left);
        int rmoves=soltn(root.right);
        result=result+Math.abs(lmoves)+Math.abs(rmoves);

        return root.data-1+lmoves+rmoves;

    }

    public static int distributeCoins(Node root) {
        int moves=soltn(root);
        return result;

    }

    //.............................................


//...................calculate coin : Hard Problem.................
//    class Solution2 {
        public static long calculateCoin(ArrayList<Integer>tempCoin) {
            ArrayList<Integer> coinList = new ArrayList<>(tempCoin);

            int n = coinList.size();
            long coin;

            coin = Math.max(((long)coinList.get(0) * coinList.get(1) * coinList.get(n - 1)),((long)coinList.get(n - 1) * coinList.get(n - 2) * coinList.get(n - 3)));

            return Math.max(coin, 0);
        }


        public static ArrayList<Integer> subTreeCoin(ArrayList<Integer> tempCoin) {
            ArrayList<Integer> subTCoin = new ArrayList<>();
            int n = tempCoin.size();

            if (n >= 5) {
                subTCoin.add(tempCoin.get(0));
                subTCoin.add(tempCoin.get(1));
                subTCoin.add(tempCoin.get(n - 3));
                subTCoin.add(tempCoin.get(n - 2));
                subTCoin.add(tempCoin.get(n - 1));

                return subTCoin;
            } else {
                return tempCoin;
            }
        }


        public static ArrayList<Integer> dfsToPlaceCoin(ArrayList<ArrayList<Integer>>graph, int i, int [] cost, long [] coin, int[]vis){
            vis[i]=1;
            ArrayList<Integer>edges = new ArrayList<Integer>();
            ArrayList<Integer>subTree = new ArrayList<Integer>();
            edges= graph.get(i);

            for(int node:edges){
                if(vis[node]!=1){
                    subTree.addAll(dfsToPlaceCoin(graph,node,cost,coin,vis));
                }
            }
            subTree.add(cost[i]);

            if(subTree.size()<3){
                coin[i]=1;
            }else{
                Collections.sort(subTree);
                coin[i]=calculateCoin(subTree);
            }
            return subTreeCoin(subTree);
        }

        public static <integer> long[] placedCoins(int[][] edges, int[] cost) {
            int n = cost.length;
            ArrayList<ArrayList<Integer>>graph = new ArrayList<>();

            for(int i=0;i<n;i++){
                graph.add(new ArrayList<>());
            }

            for(int [] edge:edges){
                graph.get(edge[0]).add(edge[1]);
                graph.get(edge[1]).add(edge[0]);
            }
            long []coin = new long[n];
            int[]vis = new int[n];

            ArrayList<Integer>subTree2=dfsToPlaceCoin(graph,0,cost,coin,vis);

            for( Integer t:subTree2){
                System.out.println(t);
            }
            System.out.println(calculateCoin(subTree2));


            return coin;

        }
//    }
    //..................................................................





    public static void main(String[]args){
//        int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
//        int nodes[]={0,3,-1,-1,0,-1,-1};
//        int[][]edges = {{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9},{0,10},{0,11},{0,12},{0,13},{0,14},{0,15},{0,16},{0,17},{0,18},{0,19},{0,20},{0,21},{0,22},{0,23},{0,24},{0,25},{0,26},{0,27},{0,28},{0,29},{0,30},{0,31},{0,32},{0,33},{0,34},{0,35},{0,36},{0,37},{0,38},{0,39},{0,40},{0,41},{0,42},{0,43},{0,44},{0,45},{0,46},{0,47},{0,48},{0,49},{0,50},{0,51},{0,52},{0,53},{0,54},{0,55},{0,56},{0,57},{0,58},{0,59},{0,60},{0,61},{0,62},{0,63},{0,64},{0,65},{0,66},{0,67},{0,68},{0,69},{0,70},{0,71},{0,72},{0,73},{0,74},{0,75},{0,76},{0,77},{0,78},{0,79},{0,80},{0,81},{0,82},{0,83},{0,84},{0,85},{0,86},{0,87},{0,88},{0,89},{0,90},{0,91},{0,92},{0,93},{0,94},{0,95},{0,96},{0,97},{0,98},{0,99}};
//        int []cost ={-5959,602,-6457,7055,-1462,6347,7226,-8422,-6088,2997,-7909,6433,5217,3294,-3792,7463,8538,-3811,5009,151,5659,4458,-1702,-1877,2799,9861,-9668,-1765,2181,-8128,7046,9529,6202,-8026,6464,1345,121,1922,7274,-1227,-9914,3025,1046,-9368,-7368,6205,-6342,8091,-6732,-7620,3276,5136,6871,4823,-1885,-4005,-3974,-2725,-3845,-8508,7201,-9566,-7236,-3386,4021,6793,-8759,5066,5879,-5171,1011,1242,8536,-8405,-9646,-214,2251,-9934,-8820,6206,1006,1318,-9712,7230,5608,-4601,9185,346,3056,8913,-2454,-3445,-4295,4802,-8852,-6121,-4538,-5580,-9246,-6462};
//        placedCoins(edges,cost);


//        buildTree treeBuild =new buildTree();
//        Node root = treeBuild.build(nodes);
//        distributeCoins(root);
//
//        System.out.println(result);

//        System.out.println("Root Node is :"+root.data);

//        preOrder(root);
//        inOrder(root);
//        postOrder(root);
//        levelOrderTraverse(root);
//        System.out.println(nodeCounts(root));
//        System.out.println(sumOfNodes(root));
//        System.out.println(heightOfTree(root));
//        System.out.println(diameterOfTree1(root));

//        treeInfo info = diameterOftree2(root);
//        System.out.println(info.diameter);


//        List<Integer> view =  rightView(root);
//        System.out.println("dbdjhf");
//        for(int num:view){
//            System.out.println(num);
        }


    }






