import java.util.*;

public class Abbey{
    
    public static int check(int[] arr){
        int max = arr[0];
        int num = 1;

        for(int j = 1; j < arr.length; j++){
            int curr = arr[j];

            if(curr > max){
                num++;
                max = curr;
            } 
        }   

        return num;
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        boolean b = true;

        while(b){
            int n = scanner.nextInt();

            if(n == 0){
                b = false;
            } else {
                int[] arr = new int[n];

                for(int i = n-1; i >= 0; i--){
                    arr[i] = scanner.nextInt();
                }

                System.out.println(check(arr));
            }
        }
    }
}
