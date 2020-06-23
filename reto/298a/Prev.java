
import java.util.*;

class Node {
    
    int data;
    Node left, right;

    public Node(int val) {
        data = val;
    }

}

public class Main {

    static Scanner scn;
    
    static int val;

    public static void build(Node root) {
        
        val = scn.nextInt();

        if(val != -1) {
            root.left = new Node(val);
            build(root.left);
        }

        val = scn.nextInt();

        if(val != -1) {
            root.right = new Node(val);
            build(root.right);
        }
    }

    public static boolean isBST(Node root, int min, int max) {
        
        if(root == null) return true;
        if((min != -1 && root.data <= min) || (max != -1 && root.data >= max)) return false;

        return isBST(root.left, min, root.data) && isBST(root.right, root.data, max);

    }

    public static void main(String[] args) {
        
        scn = new Scanner(System.in);

        int q = scn.nextInt();

        while(q-- != 0) {
            
            val = scn.nextInt();

            if(val == -1) {
                System.out.println("SI");
            } else {
                
                Node root = new Node(val);

                build(root);

                if(isBST(root, -1, -1)) {
                    System.out.println("SI");
                } else {
                    System.out.println("NO");
                }
            }
        }

    }

}
