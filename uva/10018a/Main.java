
import java.util.*;
import java.io.*;

class Main {

    public static int calc(int a, int l){
    
        int rev = 0;
        int temp;
        int tl = l;
        int perm = a;

        for(int i = 0; i <= l; i++){
            temp = a%10;
            for(int j = 0; j < tl-1; j++){
                temp *= 10;
            } 
            rev += temp;
            a /= 10;
            tl--;
        }
        
        return rev + perm;
    }

    public static void main(String[] args) throws IOException {
       
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

       int n = Integer.parseInt(br.readLine());

       for(int j = 0; j < n; j++){
           
           int a = Integer.parseInt(br.readLine()); 

           int c = 0;
           int t = 0;

           boolean found = false;

           while(!found){       
               String st = String.valueOf(a);
               int lt = st.length();
               t = calc(a, lt);  
               String s = String.valueOf(t);
               int l = s.length();

               boolean b = true;

               for(int i = 0; i < l/2 && b; i++){
                b = s.charAt(i) == s.charAt(s.length() - 1 - i);
               }
                
               found = b;
               a = t;
               c++;
           }
           System.out.printf("%d %d\n", c, t);
       }
    }
}
