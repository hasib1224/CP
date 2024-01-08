package Tree;

import java.util.ArrayList;

public class BinarySearchTree {

    public static class Node{
        int data;
        Node left;
        Node right;
        Node(int val){
            this.data=val;
        }
    }

    public static Node insertion (int val,Node root){
        if(root==null){
            return new Node(val);
        }
        if(val>root.data){
            root.right = insertion(val,root.right);
        } else if (val<root.data) {
            root.left = insertion(val,root.left);
        }
        return root;
    }

    public static Node buildTree(int[]values){
        Node root = null;
        for(int i=0;i<values.length;i++){
            root = insertion(values[i],root);
        }
        return root;
    }

    public static void inOrderTraverse(Node root){
        if(root==null){
            return;
        }
        inOrderTraverse(root.left);
        System.out.print(root.data+ " ");
        inOrderTraverse(root.right);
    }

    public static boolean searchInBST(int key, Node root){
        if(root==null){
            return false;
        }
        if(key>root.data){
            return searchInBST(key,root.right);
        } else if (key< root.data) {
            return searchInBST(key,root.left);
        } else  {
            return true;
        }
    }

    public static Node inOrderSuccessor(Node root){
        while (root!=null){
            if(root.left!=null){
                root=root.left;
            }else return root;
        }
        return root;
    }


    public static Node deleteNode(Node root,int val){
        if(root.data>val){
            root.left=deleteNode(root.left,val);
        }else if(root.data<val){
            root.right=deleteNode(root.right,val);
        }else {
            //case1
            if(root.left==null && root.right==null){
                return null;
            }
            //case2
            else if (root.right==null) {
                return root.left;
            }else if (root.left==null) {
                return root.right;
            }
            //case 3
            Node temp = inOrderSuccessor(root.right);
            root.data=temp.data;
            root.right=deleteNode(root.right,temp.data);
        }
        return root;
    }

    public static void PrintRange(Node root,int low,int high){
        if(root==null){
            return;
        }
        if(low>root.data){
            PrintRange(root.right,low,high);
        } else if (high<root.data) {
            PrintRange(root.left,low,high);
        } else if (low<=root.data && root.data<=high) {
            System.out.println(root.data+ " ");
            PrintRange(root.left,low,high);
            PrintRange(root.right,low,high);
        }
    }

    public static void printPathFromRoot(Node root, ArrayList<Integer> val){
        if(root==null){
            return;
        }
        val.add(root.data);
        if(root.left==null && root.right==null){
            for(int x:val){
                System.out.print(x + " ");
            }
            System.out.println();
            val.remove(val.size()-1);
            return;
        }
        printPathFromRoot(root.left,val);
        printPathFromRoot(root.right,val);
        val.remove(val.size()-1);
    }


    //Delete node..........................
     public class TreeNode {
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

    class Solution {
        public static TreeNode inOrderSuccessor(TreeNode root,int key){
            while(root.left!=null){
                root=root.left;
            }
            return root;
        }
        public TreeNode deleteNode(TreeNode root, int key) {
            if(root==null){
                return null;
            }

            if(root.val>key){
                root.left=deleteNode(root.left,key);
            }else if(root.val<key){
                root.right=deleteNode(root.right,key);
            }else{
                if(root.left==null && root.right==null){
                    return null;
                }
                if(root.left==null){
                    return root.right;
                }else if(root.right == null){
                    return root.left;
                }
                TreeNode temp = inOrderSuccessor(root.right,key);
                root.val=temp.val;
                root.right = deleteNode(root.right,temp.val);
                return root;

            }
            return root;

        }
    }

    //........................................









    public static void main(String[]args){
        int[]num={5,1,3,4,2,7};
        Node root = buildTree(num);
//        if(searchInBST(20,root)){
//            System.out.println("yes");
//        } else System.out.println("No");

//        System.out.println(deleteNode(root,1).data);
//        inOrderTraverse(root);
//        PrintRange(root,3,10);
        ArrayList<Integer> val = new ArrayList<>();
        printPathFromRoot(root,val);

    }
}
