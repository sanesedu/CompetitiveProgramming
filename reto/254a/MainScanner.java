
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	  public static void main(String[] args) {
	    Scanner entrada = new Scanner(System.in);
	    int n = Integer.parseInt(entrada.nextLine());

	    while (n != 0) {

	      int[] heights = new int[n];
	      for (int i = 0; i < heights.length; i++) {
	        heights[i] = entrada.nextInt();
	      }
	      int[] lengths = new int[n];
	      for (int i = 0; i < lengths.length; i++) {
	        lengths[i] = entrada.nextInt();
	      }
	      Arrays.sort(heights);
	      Arrays.sort(lengths);
	      int sum = 0;
	      for (int i = 0; i < heights.length; i++) {
	        sum += Math.abs(heights[i] - lengths[i]);
	      }
	        System.out.println(sum);
	        n = entrada.nextInt();
	    }
	    entrada.close();
	  }
}
