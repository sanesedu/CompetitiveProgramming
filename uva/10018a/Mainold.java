
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

        int a, t = 0, l;

        for(int i = 0; i < n; i++){
            a = Integer.parseInt(br.readLine());

            boolean found = false;
            
            int c = 0;

            while(!found){

                t = calc(a, String.valueOf(a).length()-1);

                String s = String.valueOf(t);

                boolean temp = true;

                for(int j = 0; j < s.length()/2 && temp; j++){
                    temp = s.charAt(j) == s.charAt(s.length()-1-j);
                }

                found = temp; 

                c++;
            }

            System.out.printf("%d %d\n", c, t);
        }
    }
}
