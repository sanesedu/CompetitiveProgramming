
import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s;

        String r1 = "`1234567890-=";
        String r2 = "QWERTYUIOP[]\\\\";
        String r3 = "ASDFGJKL;'";
        String r4 = "ZXCVBNM,./";

        char[] arr;
        int c = 0;

        while((s = br.readLine()) != null){

            if(c != 0){
                System.out.println();
            }

            arr = s.toCharArray();

            for(int i = 0; i < arr.length; i++){
                if(r1.indexOf(arr[i]) != -1){
                    System.out.print(r1.charAt(r1.indexOf(arr[i]) -1));
                } else if(r2.indexOf(arr[i]) != -1){
                    System.out.print(r2.charAt(r2.indexOf(arr[i]) -1));
                } else if(r3.indexOf(arr[i]) != -1){
                    System.out.print(r3.charAt(r3.indexOf(arr[i]) -1));
                } else if(r4.indexOf(arr[i]) != -1){
                    System.out.print(r4.charAt(r4.indexOf(arr[i]) -1));
                } else {
                    System.out.print(arr[i]);
                }
            }
            c++;
        }

    }
}
