import java.io.*;
import java.util.*;

public class CF165C {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int k = Integer.parseInt(br.readLine().trim());
        String s = br.readLine().trim();
        
        long count = 0;
        int prefix = 0;
        
        HashMap<Integer, Long> freq = new HashMap<>();
        freq.put(0, 1L);
        
        for (char ch : s.toCharArray()) {
            if (ch == '1') {
                prefix++;
            }
            
            if (freq.containsKey(prefix - k)) {
                count += freq.get(prefix - k);
            }
            
            freq.put(prefix, freq.getOrDefault(prefix, 0L) + 1);
        }
        
        System.out.println(count);
    }
}