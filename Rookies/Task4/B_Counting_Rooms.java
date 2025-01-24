import java.util.*;




//////////////////////////////////////////////////////////////
/// chnage class name to "Main" before testing with vjudge ///
//////////////////////////////////////////////////////////////




public class B_Counting_Rooms {

    static int n, m;
    static char[][] buildingMap;
    static boolean[][] visited;
    
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        n = scanner.nextInt();
        m = scanner.nextInt();
        scanner.nextLine();
        
        buildingMap = new char[n][m];
        visited = new boolean[n][m];
        for (int i = 0; i < n; i++) buildingMap[i] = scanner.nextLine().toCharArray();
        scanner.close();
        
        int roomCount = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (buildingMap[i][j] == '.' && !visited[i][j]) {
                    bfs(i, j);
                    roomCount++;
                }
            }
        }
        
        System.out.println(roomCount);
    }
    
    private static void bfs(int x, int y) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{x, y});
        visited[x][y] = true;
        
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int cx = current[0];
            int cy = current[1];
            
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                
                if (nx >= 0 &&
                    nx < n &&
                    ny >= 0 &&
                    ny < m &&
                    !visited[nx][ny] &&
                    buildingMap[nx][ny] == '.'
                ) {
                    visited[nx][ny] = true;
                    queue.add(new int[]{nx, ny});
                }
            }
        }
    }
}
