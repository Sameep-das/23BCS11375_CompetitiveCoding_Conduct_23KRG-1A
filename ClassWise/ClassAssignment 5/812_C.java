import java.util.*;

public class C_Sagheer_and_Nubian_Market{

    static int n;
    static long S;
    static long[] a;


    static long costForK(int k) {
        if (k == 0) return 0;

        long[] b = new long[n];

        for (int i = 0; i < n; i++) {
            b[i] = a[i] + (long)(i + 1) * k;
        }

        Arrays.sort(b);

        long sum = 0;
        for (int i = 0; i < k; i++) {
            sum += b[i];
            if (sum > S) return sum;
        }

        return sum;
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            n = sc.nextInt();
            S = sc.nextLong();
            a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
            }   
            
            int lo = 0, hi = n;
            int bestK = 0;
            long bestCost = 0;

            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                
                long cost = costForK(mid);
                
                if (cost <= S) {
                    bestK = mid;
                    bestCost = cost;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }   System.out.println(bestK + " " + bestCost);
        }
    }
}
