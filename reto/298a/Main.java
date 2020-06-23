import java.io.*;

class Node {
    int val;
    Node left, right;
    Node(int x) { 
        val = x; 
    }
}

public class Main {

    final static FastReader r = new FastReader(System.in);

    static void build(Node node) {

        int value = r.readInt();

        if (value != -1) {
            node.left = new Node(value);
            build(node.left);
        }

        value = r.readInt();

        if (value != -1) {
            node.right = new Node(value);
            build(node.right);
        }
    }

    static boolean isBST(Node node, int min, int max) {
        
        if (node == null) return true;
        
        if ((min != -1 && node.val <= min) || (max != -1 && node.val >= max)) {
            return false;
        }

        return  isBST(node.left, min, node.val) && isBST(node.right, node.val, max);
    }

    public static void main(String[] args) {

        int rootValue;

        for (int i = r.readInt(); i > 0; i--) {

            rootValue = r.readInt();
        
            if (rootValue == -1) {
                System.out.println("SI");
            } else {
            
                Node root = new Node( rootValue );
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

class FastReader {
    
    private InputStream stream;
    private byte[] buf = new byte[1024];

    private int curChar;

    private int numChars;

    public FastReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new RuntimeException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new RuntimeException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public String readString() {
        final StringBuilder stringBuilder = new StringBuilder();
        int c = read();
        while (isSpaceChar(c))
            c = read();
        do {
            stringBuilder.append(c);
            c = read();
        } while (!isSpaceChar((char) c));
        return stringBuilder.toString();
    }

    public int readInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public long readLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
}
