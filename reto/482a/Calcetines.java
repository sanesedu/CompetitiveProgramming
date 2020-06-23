import java.util.*;
import java.io.*;

public class Calcetines {

	public static void main(String[] args) throws IOException{
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		boolean b = true;

		while(b){

			String line = reader.readLine();

			String[] sp = line.split("\\s+");

			if (sp[0].equalsIgnoreCase(".")){
			    break;
            } else {

                boolean exit = true;

                int nCount = 0;
                int gCount = 0;

                for (int i = 0; i < sp.length && exit; i++){
                    if (sp[i].equalsIgnoreCase(".")){
                        break;
                    } else if (sp[i].equalsIgnoreCase("N")){
                        nCount++;
                    } else if (sp[i].equalsIgnoreCase("G")){
                        gCount++;
                    }
                }

                boolean nEven = nCount % 2 == 0;
                boolean gEven = gCount % 2 == 0;

                if (nEven && gEven){
                    System.out.println("EMPAREJADOS");
                } else if (!nEven && gEven){
                    System.out.println("NEGRO SOLITARIO");
                } else if (!gEven && nEven){
                    System.out.println("GRIS SOLITARIO");
                } else {
                    System.out.println("PAREJA MIXTA");
                }
            }


		}
		
	}

}
