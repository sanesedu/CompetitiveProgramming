import java.util.*;
import java.io.*;

public class Main {

    public static Queue<Integer> q = new LinkedList<Integer>();

    public static int getValueAtPos(int pos){
        Iterator<Integer> iter = q.iterator();

        while(pos > 0){
            iter.next();
            pos--;
        }

        return iter.next();
    }

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());

        int a, pos, time;

        for(int i = 0; i < n; i++){
            a = Integer.parseInt(br.readLine());
            pos = Integer.parseInt(br.readLine());
            pos--;
            
            q.clear();
            time = 0;

            st = new StringTokenizer(br.readLine());

            for(int j = 0; j < a; j++){
                q.add(Integer.parseInt(st.nextToken()));
            }

            while(getValueAtPos(pos) != 0){
                
                int temp = q.poll();
                if(temp != 0){
                    q.add(temp-1);
                } else {
                    a--;
                }
                pos--;
                if(pos < 0){
                    pos = a - 1;
                }
                if(temp != 0){
                    time += 2;
                }
            }

            System.out.println(time);

        }
    }
}
