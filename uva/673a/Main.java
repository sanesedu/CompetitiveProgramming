
import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());

        char[] carr;
        int[] iarr;

        for(int i = 0; i < n; i++){
            
            carr = br.readLine().trim().toCharArray();
            iarr = new int[carr.length];

            for(int j = 0; j < iarr.length; j++){
                if(carr[j] == '('){
                    iarr[j] = -1;
                } else if(carr[j] == ')'){
                    iarr[j] = 1;
                } else if(carr[j] == '['){
                    iarr[j] = -2;
                } else if(carr[j] == ']'){
                    iarr[j] = 2;
                }
            }

            Stack<Integer> st = new Stack<Integer>();

            for(int k = 0; k < iarr.length; k++){
                if(iarr[k] != 0){
                    if(st.empty()){
                        st.push(iarr[k]);
                    } else{
                        if(st.peek() + iarr[k] == 0 && st.peek() < 0){
                            st.pop();
                        } else {
                            st.push(iarr[k]);
                        }
                    }
                }
            }

            if(st.empty()){
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
            
        }
    }
}
