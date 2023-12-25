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








    public static void main(String[]args){
        int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
        buildTree treeBuild =new buildTree();
        Node root = treeBuild.build(nodes);

        System.out.println("Root Node is :"+root.data);
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
        List<Integer> view =  rightView(root);
        System.out.println("dbdjhf");
        for(int num:view){
            System.out.println(num);
        }


    }





}
