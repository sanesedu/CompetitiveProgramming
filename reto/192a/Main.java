
import java.util.*;
import java.io.*;

public class Main {

    public static int[] memo = new int[100000];
    public static int[] temp = new int[100000];
    public static int counter = 0;

    public static boolean check(int n){

        if(memo[n] == -1) {
            return false;
        }

        if(memo[n] == 1){
            return true;
        }

        temp[counter] = n;
        counter++;

        if(n == 1){
            return true;
        } else if(n < 3){
            return false;
        } else if(n/3 == 1 && n % 3 == 0){
            return check(n/3);
        } else if(n-5 == 1){
            return check(n-5);
        } else if(n % 3 == 0){
            return check(n/3);
        } else {
            return check(n-5);
        }
    }

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean b = true;

        memo[1] = 1;

        while(b){
        
            counter = 0;
            Arrays.fill(temp, 0);

            int n = Integer.parseInt(br.readLine());

            if(n == 0){
                b = false;
                break;
            } 

            boolean res = check(n);

            if(res){
                System.out.println("SI");

                for(int j = 0; j < counter; j++){
                    memo[temp[j]] = 1;
                }
            } else {
                System.out.println("NO");
                for(int j = 0; j < counter; j++){
                    memo[temp[j]] = -1;
                }
            }
        }
    }

}
