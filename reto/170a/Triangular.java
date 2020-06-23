
import java.util.*;

public class Triangular {


    //returns an array whose first element is 1 if n is a triangular number and 0 if not
    // and the second element if the number of sides of the triangle

    public static int[] isTriangular(int n){

        int[] res = new int[2];
        res[0] = 0;
        int a = 0;
        int add = 1;

        while(a < n){
            a += add;
            add++;
        }

        if (a == n ){
            res[0] = 1;
        }

        res[1] = add - 1;

        return res;
    }

    public static int numFromSides(int sides){

        int a = 0;
        int add = 1;

        while(add <= sides){
            a += add;
            add++;
        }

        return a;

    }

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean end = true;

		while(end){

		    int n = input.nextInt();

		    if (n == 0){
		        end  = false;
            } else{
                int sides;

                int[] res = isTriangular(n);

                int temp = n;

                sides = res[1];

                if (res[0] == 0){
                    sides--;
                }

                int or = numFromSides(sides);

                int diff = n - or;

                System.out.println(sides + " " + diff);
            }

        }


	}

}
