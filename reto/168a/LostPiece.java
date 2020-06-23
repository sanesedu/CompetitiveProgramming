import java.util.*;

public class LostPiece {

	public static int sum(int a){
		return ((a)*(a+1))/2;
	}

    public static void main(String[] args){

    	Scanner scanner = new Scanner(System.in);
		boolean b = true;
		while(b){
			int n = Integer.parseInt(scanner.nextLine().trim());
			if(n == 0){
				b = false;
				break; 
			} else{
				int s = sum(n);
				String line = scanner.nextLine();
				String[] sp = line.split(" ");
				for(int i = 0; i < sp.length; i++){
					int a = Integer.parseInt(sp[i].trim());
					s -= a;
				}
				System.out.println(s);
			}
		}
    }

}
