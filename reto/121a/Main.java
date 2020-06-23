
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        boolean b = true;

        long give, receive, have;

        while(b) {
            st = new StringTokenizer(br.readLine());
            
            give = Long.parseLong(st.nextToken());
            receive = Long.parseLong(st.nextToken());
            have = Long.parseLong(st.nextToken());

            if(give == 0 && receive == 0 && have == 0) {
                b = false;
                break;
            }

            if(receive >= give && have >= give) {
                System.out.println("RUINA");
                continue;
            }

            if(have < give || receive == 0) {
                System.out.printf("%d %d\n", have, have);
                continue;
            }

            long eats = have, packs = 0;

            while(have >= give) {
                packs = have/give;
                eats += packs * receive;
                have = (packs * receive + have % give);
            }

            System.out.printf("%d %d\n", eats, have);

        }
    }
}
