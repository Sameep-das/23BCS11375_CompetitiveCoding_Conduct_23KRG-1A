import java.util.*;

public class JobScheduling {

    static class Job {
        int deadline;
        int profit;

        Job(int d, int p) {
            deadline = d;
            profit = p;
        }
    }

    public static ArrayList<Integer> jobSequencing(int[] deadlines, int[] profits) {
        int n = deadlines.length;
        List<Job> jobList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            jobList.add(new Job(deadlines[i], profits[i]));
        }
        jobList.sort(Comparator.comparingInt(j -> j.deadline));
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        int totalProfit = 0;
        for (Job job : jobList) {
            if (minHeap.size() < job.deadline) {
                minHeap.add(job.profit);
                totalProfit += job.profit;
            } else if (!minHeap.isEmpty() && minHeap.peek() < job.profit) {
                totalProfit -= minHeap.poll();
                minHeap.add(job.profit);
                totalProfit += job.profit;
            }
        }
        ArrayList<Integer> result = new ArrayList<>();
        result.add(minHeap.size());
        result.add(totalProfit);
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of jobs: ");
        int n = sc.nextInt();
        int[] deadlines = new int[n];
        int[] profits = new int[n];
        System.out.println("Enter deadlines:");
        for (int i = 0; i < n; i++) {
            deadlines[i] = sc.nextInt();
        }
        System.out.println("Enter profits:");
        for (int i = 0; i < n; i++) {
            profits[i] = sc.nextInt();
        }
        ArrayList<Integer> ans = jobSequencing(deadlines, profits);
        System.out.println("Jobs done: " + ans.get(0));
        System.out.println("Max Profit: " + ans.get(1));
        sc.close();
    }
}