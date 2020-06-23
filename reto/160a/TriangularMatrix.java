
import java.util.*;

public class TriangularMatrix {

    public static boolean lower(int[][] data){
        boolean res = true;

        for (int i = 0; i < data.length; i++){
            for(int j = 0; j < data.length; j++){
                if (i > j){
                    if (data[i][j] != 0){
                        res = false;
                        break;
                    }
                }
            }
        }

        return res;
    }

    public static boolean upper(int[][] data){
        boolean res = true;

        for (int i = 0; i < data.length; i++){
            for(int j = 0; j < data.length; j++){
                if (i < j){
                    if (data[i][j] != 0){
                        res = false;
                        break;
                    }
                }
            }
        }

        return res;
    }

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		boolean b = true;

		while(b){
			int rows = input.nextInt();

			if (rows == 0){
			    b = false;
            } else {

			    int[][] matrix = new int[rows][rows];

			    for (int i = 0; i < rows; i++){
			        for(int j = 0; j < rows; j++){
			            matrix[i][j] = input.nextInt();
                    }
                }

                if (lower(matrix) || upper(matrix)){
                    System.out.println("SI");
                } else{
                    System.out.println("NO");
                }
            }
		}

	}

}
