
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        boolean b = true;

        while(b){
        
            st = new StringTokenizer(br.readLine());

            int first = Integer.parseInt(st.nextToken());

            if(first == -1){
                b = false;
                break;
            }

            boolean a = true;

            Stack<Integer> stack = new Stack<Integer>();

            stack.push(first);

            while(a){
                int n = Integer.parseInt(st.nextToken());
                if(n == -1){
                    a = false;
                    break;
                } else {
                    stack.push(n);
                }

            }

            st = new StringTokenizer(br.readLine());

            int flips = Integer.parseInt(st.nextToken());
            

            for(int i = 0; i < flips; i++){
                int f = Integer.parseInt(st.nextToken());
                
                int[] temp = new int[f];

                for(int j = 0; j < f; j++){
                    temp[j] = stack.pop();
                }

                for(int k = 0; k < f; k++){
                    stack.push(temp[k]);
                }
                
            }

            System.out.println(stack.peek());

        }
    }
}
