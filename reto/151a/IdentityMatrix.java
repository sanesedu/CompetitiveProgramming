
import java.util.*;

public class IdentityMatrix {

	public static void main(String[] args) {
		
		Scanner input = new Scanner( System.in ).useLocale( Locale.US );

		while (input.hasNext()){

			int rows = input.nextInt();

			if (rows == 0){
			    break;
            } else{
			    boolean id = true;
			    int[][] matrix = new int[rows][rows];

			    for (int row = 0; row < rows; row++){
			        for (int col = 0; col < rows; col++){
			            matrix[row][col] = input.nextInt();
                        if (matrix[row][col] != 0 &&  matrix[row][col] != 1){
                            id = false;
                        }
                    }

                }

                if (!id){
                    System.out.println("NO");
                } else{
                    for (int row = 0; row < rows; row++){
                        for (int col = 0; col < rows; col++){
                            if (col == row){
                                if(matrix[row][col] != 1){
                                    id = false;
                                    break;
                                }
                            } else {
                                if(matrix[row][col] != 0){
                                    id = false;
                                    break;
                                }
                            }

                        }
                        if (!id){
                            break;
                        }
                    }

                    if (id){
                        System.out.println("SI");
                    } else{
                        System.out.println("NO");
                    }
                }

            }
		}
	}

}
