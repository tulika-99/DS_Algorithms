import java.util.*;
public class LevelOrderTraversal{
    public static void main(String[] args){

        TreeNode root = formSampleTree();
        ArrayList<ArrayList<Integer>> levelOrderList = getLevelOrderTraversal(root);
        
        if(levelOrderList!=null){
            int counter = 1;
            for(ArrayList<Integer> eachLevel : levelOrderList){
                System.out.println("Level #"+(counter++)+" "+eachLevel);
            }
        }
        
    }

    private static ArrayList<ArrayList<Integer>> getLevelOrderTraversal(TreeNode root){

        if(root == null){
            return null;
        }
        ArrayList<ArrayList<Integer>> levelOrderTraversal = new ArrayList<ArrayList<Integer>>();
        Queue<TreeNode> queue = new LinkedList<TreeNode>();

        queue.add(root);
        while(!queue.isEmpty()){

            int levelSize = queue.size();
            ArrayList<Integer> eachLevel = new ArrayList<Integer>();
            for(int i=0;i<levelSize;i++){
                TreeNode node = queue.remove();
                eachLevel.add(node.data);
                if(node.left!=null){
                    queue.add(node.left);
                }
                if(node.right!=null){
                    queue.add(node.right);
                }
            }

            levelOrderTraversal.add(eachLevel);

        }
        return levelOrderTraversal;
    }

    private static TreeNode formSampleTree(){

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);

        return root;
    }

}

class TreeNode{
    protected int data ;
    protected TreeNode left;
    protected TreeNode right;

    TreeNode(int data){
        this.data = data;
    }
}