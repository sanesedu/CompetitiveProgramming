import java.util.*;

public class Chessboards {

	public static void printBoard(int n, char c){
		int count = 0;
		for(int i = 0; i < 8*n + 2; i++){
			System.out.print("|");
			if(i == 0 || i == 8*n + 1){
				for(int j = 0; j < 8*n; j++){
					System.out.print("-");
				}
			} else{
				int temp = count%(2*n);
				if(temp < n){
					temp = 0;
				} else{
					temp = n;
				}
				for(int k = 0; k < 8; k++){
					for(int l = 0; l < n; l++){
						temp = temp%(2*n);
						if(temp < n){
							System.out.print(" ");
						} else{
							System.out.print(c);
						}
						temp++;
					}
				}
				count++;
			}
			System.out.print("|");
			System.out.println();
		}
	}

    public static void main(String[] args){

    	Scanner scanner = new Scanner(System.in);
		boolean b = true;
		while(b){
			int n = scanner.nextInt();

			if(n == 0){
				b = false;
				break;
			} else{
				char c = scanner.next().trim().charAt(0);
				printBoard(n, c);
			}
		}
    }

}
