import java.io.*;
import java.util.*;

public class D_Monsters {
    static List<List<Integer>> graph;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


        String[] firstLine = br.readLine().split(" ");
        int n = Integer.parseInt(firstLine[0]);
        int m = Integer.parseInt(firstLine[1]);

 
        graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }


        for (int i = 0; i < m; i++) {
            String[] road = br.readLine().split(" ");
            int a = Integer.parseInt(road[0]);
            int b = Integer.parseInt(road[1]);
            graph.get(a).add(b);
            graph.get(b).add(a);
        }

 
        visited = new boolean[n + 1];
        List<Integer> representatives = new ArrayList<>();


        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {

                representatives.add(i);
                bfs(i);
            }
        }


        int k = representatives.size() - 1;
        bw.write(k + "\n");

        for (int i = 0; i < k; i++) {
            bw.write(representatives.get(i) + " " + representatives.get(i + 1) + "\n");
        }

        bw.flush();
    }

    private static void bfs(int start) {
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        visited[start] = true;

        while (!queue.isEmpty()) {
            int current = queue.poll();

            for (int neighbor : graph.get(current)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
    }
}
