
import java.util.*;

public class Zapping {

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while(b){
		    int current = input.nextInt();
		    int goal = input.nextInt();

		    if (current == 0 && goal == 0){
		        b = false;
            } else {

		        int max = (current > goal)? current:goal;
		        int min = (current > goal)? goal:current;

		        int inv = 99 - max;

		        int up = Math.abs(goal - current);
		        int down = Math.abs(inv + min);

		        int res = (up < down)? up:down;
		        System.out.println(res);
            }
        }

	}

}
