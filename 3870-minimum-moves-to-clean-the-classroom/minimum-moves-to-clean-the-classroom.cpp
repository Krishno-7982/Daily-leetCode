class Solution {
public:

    vector<pair<int,int>> movements = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };

    int bfs(
        int sx,
        int sy,
        int energy,
        int mask,
        vector<vector<vector<int>>>& maxEnergy,
        int L,
        vector<string>& classroom,
        vector<vector<int>>& litterIndex
    ) {

        int m = classroom.size();
        int n = classroom[0].size();

        // x, y, remaining energy, mask
        queue<array<int,4>> q;

        q.push({sx, sy, energy, 0});

        maxEnergy[sx][sy][0] = energy;

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto curr = q.front();
                q.pop();

                int x = curr[0];
                int y = curr[1];
                int e = curr[2];
                int mask = curr[3];

                // All litter collected
                if (mask == (1 << L) - 1) {
                    return moves;
                }

                // No energy -> cannot move
                if (e == 0) {
                    continue;
                }

                for (auto movement : movements) {

                    int nx = x + movement.first;
                    int ny = y + movement.second;

                    // Outside
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                        continue;
                    }

                    // Obstacle
                    if (classroom[nx][ny] == 'X') {
                        continue;
                    }

                    int ne = e - 1;
                    int nmask = mask;

                    // Collect litter
                    if (classroom[nx][ny] == 'L') {
                        nmask |= (1 << litterIndex[nx][ny]);
                    }

                    // Reset energy
                    if (classroom[nx][ny] == 'R') {
                        ne = energy;
                    }

                    // If we have already reached this
                    // position + mask with MORE energy,
                    // this state is useless.
                    if (maxEnergy[nx][ny][nmask] >= ne) {
                        continue;
                    }

                    maxEnergy[nx][ny][nmask] = ne;

                    q.push({nx, ny, ne, nmask});
                }
            }

            moves++;
        }

        return -1;
    }


    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int L = 0;

        int sx = 0, sy = 0;

        vector<vector<int>> litterIndex(
            m,
            vector<int>(n, -1)
        );

        // Find S and assign IDs to litter
        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'L') {
                    litterIndex[i][j] = L++;
                }

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }

        // maxEnergy[x][y][mask]
        vector<vector<vector<int>>> maxEnergy(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << L, -1)
            )
        );

        return bfs(
            sx,
            sy,
            energy,
            0,
            maxEnergy,
            L,
            classroom,
            litterIndex
        );
    }
};