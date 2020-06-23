import java.util.*;

public class MultPers {

    public static int pers(int a){
        
        int c = 0;

        while(a/10 != 0){
            int[] arr = digs(a);

            a = 1;

            for(int j = 0; j < arr.length; j++){
                a *= arr[j];
            }

            c++;
        }

        return c;
    }

    public static int[] digs(int a){
        int l = 0;

        int temp = a;

        while(temp != 0){
            temp /= 10;
            l++;  
        }

        int[] arr = new int[l];

        for(int i = l-1; i >= 0; i--){
            arr[i] = a%10;
            a/=10;

        }

        return arr;
    }

    public static void main(String[] args){
        
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        for(int i = 0; i < n; i++){
            int a = scanner.nextInt();
            System.out.println(pers(a));
        }
    }
}
