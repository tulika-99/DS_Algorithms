public class TotalNodes {
    static class Node{
        Node left;
        Node right;
        int data;

        public Node(int data) {
            this.left = null;
            this.right = null;
            this.data = data;
        }
    }

    public int countNode(Node root){
        if(root==null)
            return 0;
        return 1 + countNode(root.left) + countNode(root.right);
    }

    public static void main(String[] args) {
        TotalNodes c = new TotalNodes();
        Node root = new Node(6);
        root.left = new Node(3);
        root.right = new Node(43);
        root.left.left = new Node(12);
        root.left.right = new Node(39);

        System.out.println("Number of nodes in given binary tree: " + c.countNode(root));
    }
}
