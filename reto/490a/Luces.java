import java.util.*;
import java.io.*;

public class Luces {

    public static long reverse(long[] vals, int tovisit){
        long res = 0;
        long prev = 0;
        int counter = 0;
        for (int i = vals.length-1; i >= 0; i--){

            if (i == vals.length-1){

            } else {
                if (vals[i] < vals[i+1]){
                    res = (res - (vals[i+1] - vals[i]));
                } else{
                    res += (vals[i] - vals[i+1]);
                }
            }

            counter++;

            if (counter == tovisit){
                if (res > prev){
                    prev = res;
                }
                counter = tovisit-1;
                res -= (vals[i+tovisit-2] - vals[i+tovisit-1]);

            }
        }

        return prev;
    }

	public static void main(String[] args) throws IOException{
		
		Scanner reader = new Scanner(System.in);

		while(reader.hasNext()){

			int total = reader.nextInt();
			int tovisit = reader.nextInt();

			long res = 0;
			long prev = 0;
			int counter = 0;

			long[] vals = new long[total];

			for (int i = 0; i < total; i++){
			    vals[i] = reader.nextLong();

			    if (i == 0){

                } else {
			        if (vals[i] < vals[i-1]){
                        res = (res - (vals[i-1] - vals[i]));
                    } else{
                        res += (vals[i] - vals[i-1]);
                    }
                }

			    counter++;

			    if (counter == tovisit){
			        if (res > prev){
			            prev = res;
                    }
                    counter = tovisit-1;
			        res -= (vals[i-tovisit+2] - vals[i-tovisit+1]);

                }
            }

            long res2 = reverse(vals, tovisit);

			long max = (prev>res2)? prev:res2;

            System.out.println(max);

		}
		
	}

}
