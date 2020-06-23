
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        Stack<Integer> s = new Stack<Integer>();
        boolean b = true;

        while(b){
            
            int n = Integer.parseInt(br.readLine());

            if(n == 0){
                b = false;
                break;
            }

            s.clear();

            for(int i = 1; i <= n; i++){
                s.push(i);
            }

            int m = 2;

            while(s.size() >= m){
                int temp = 0;
                int si = s.size();
                for(int j = 0; j < si; j++){
                    if(temp == 0){
                        s.pop();
                        temp = (temp+1)%m;
                    } else {
                        s.push(s.pop());
                        temp = (temp + 1)%m;;
                    }
                }
                m++;
            }
            
            String st = n + ": ";

            for(int k = 0; k < s.size(); k++){
                st += s.pop() + " ";
            }

            System.out.println(st);
        }
    }
}
