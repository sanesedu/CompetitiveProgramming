
import java.util.*;
import java.io.*;

class Main {
    
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        String s;

        String m, n;
        int a, b;

        while((s = br.readLine()) != null){
            
            st = new StringTokenizer(s);
            
            m = st.nextToken();
            a = Integer.parseInt(m);

            n = st.nextToken();
            b = Integer.parseInt(n);

            if(!(a == 0 && b == 0)){
                
                int u = (m.length() > n.length()) ? m.length() : n.length();

                int carries = 0;
                int c = 0;

                for(int i = u-1; i >= 0; i--){
                    
                    if(a%10 + b%10 + c > 9){
                        carries++;
                        c = 1;
                    } else {
                        c = 0;
                    }

                    a /= 10;
                    b /= 10;
                }

                if(a%10 + b%10 + c > 9){
                    carries++;
                }

                if(carries == 0){
                    System.out.println("No carry operation.");
                } else if (carries == 1){
                    System.out.println("1 carry operation.");
                } else {
                    System.out.println(carries + " carry operations.");
                }
    
            } else {
                break;
            }

        }
    }
}
