
import java.util.*;
import java.io.*;

class Main {
    
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s;

        boolean end = false;

        int c = 0;

        while((s = br.readLine()) != null){
            
            if(c != 0){
                System.out.println();
            }

            char[] arr = s.toCharArray();

            for(int i = 0; i < arr.length; i++){
                if(arr[i] == '\"'){
                    if(end){
                        System.out.print("''");
                        end = false;
                    } else {
                        System.out.print("``");
                        end = true;
                    }
                } else {
                    System.out.print(arr[i]);
                }
            }

            c++;

        }
    }
}
