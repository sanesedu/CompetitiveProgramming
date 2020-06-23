import java.util.*;

public class RomanShields {

	public static long getShields(long num){
		return num * (num + 4);
	}

    public static void main(String[] args){

    	Scanner scanner = new Scanner(System.in);
		boolean b = true;

		while(b){
			long n = scanner.nextLong();
			if(n == 0){
				b = false;
				break;
			} else{
				long totalShields = 0;
				while(n > 0){
					long square = (long)Math.floor(Math.sqrt(n));
					totalShields += getShields(square);
					n -= square * square;
				}

				System.out.println(totalShields);
			}
		}
    }

}
