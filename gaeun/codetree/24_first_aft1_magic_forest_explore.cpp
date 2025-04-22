#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int R, C, K;
struct golemInfo {
	int num;
	int r, c, d;
	int south;
};
vector<golemInfo> golemList;
vector<vector<int>> grid;
bool visited[71][71] = { 0, };
int theMostSouth = 0;
int answer = 0;

bool isSouth(int r, int c) {
	if (c-1 < 1 || c+1 > C || r+2 > R) return false;
	if (r == -1) {
		if (grid[r + 2][c] > 0) return false;
	}
	else {
		if (grid[r + 2][c] > 0) return false;
		if (grid[r + 1][c - 1] > 0) return false;
		if (grid[r + 1][c + 1] > 0) return false;
	}
	return true;
}

bool isWest(int r, int c) {
	if (c-2 < 1 || c > C || r+1 > R) return false;
	if (r == -1) return true;
	else if (r == 0) {
		if (grid[r + 1][c - 1] > 0) return false;
	}
	else if (r == 1) {
		if (grid[r][c - 2] > 0) return false;
		if (grid[r + 1][c - 1] > 0) return false;
	}
	else {
		if (grid[r - 1][c - 1] > 0) return false;
		if (grid[r][c - 2] > 0) return false;
		if (grid[r + 1][c - 1] > 0) return false;
	}
	
	return true;
}

bool isEast(int r, int c) {
	if (c < 1 || c+2 > C || r+1 > R) return false;
	if (r == -1) return true;
	else if (r == 0) {
		if (grid[r + 1][c + 1] > 0) return false;
	}
	else if (r == 1) {
		if (grid[r][c + 2] > 0) return false;
		if (grid[r + 1][c + 1] > 0) return false;
	}
	else {
		if (grid[r - 1][c + 1] > 0) return false;
		if (grid[r][c + 2] > 0) return false;
		if (grid[r + 1][c + 1] > 0) return false;
	}	
	return true;
}

void removeGolem(golemInfo g) {
	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };
	if (!(g.r < 1 || g.r > R || g.c < 1 || g.c > C)) grid[g.r][g.c] = 0;
	for (int i = 0; i < 4; i++) {
		if (g.r + dr[i] < 1 || g.r + dr[i] > R || g.c + dc[i] < 1 || g.c + dc[i] > C) continue;
		grid[g.r + dr[i]][g.c + dc[i]] = 0;
	}
}

void checkGolem(golemInfo g) {
	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };
	if (!(g.r < 1 || g.r > R || g.c < 1 || g.c > C)) grid[g.r][g.c] = g.num;
	for (int i = 0; i < 4; i++) {
		if (g.r + dr[i] < 1 || g.r + dr[i] > R || g.c + dc[i] < 1 || g.c + dc[i] > C) continue;
		grid[g.r + dr[i]][g.c + dc[i]] = g.num;
	}
}

bool moveGolem(golemInfo& g) {
	//cout << "g.r: " << g.r << ", gr.c: " << g.c << "\n";
	removeGolem(g);
	if (isSouth(g.r, g.c)) {
		g.r += 1;
		g.south = g.r + 1;
		checkGolem(g);
		return true;
	}
	if (isWest(g.r, g.c)) {
		if (isSouth(g.r, g.c-1)) {
			g.r += 1;
			g.c -= 1;
			g.d = (g.d - 1 + 4) % 4;
			g.south = g.r + 1;
			checkGolem(g);
			return true;
		}
	}
	if (isEast(g.r, g.c)) {
		if (isSouth(g.r, g.c+1)) {
			g.r += 1;
			g.c += 1;
			g.d = (g.d + 1) % 4;
			g.south = g.r + 1;
			checkGolem(g);
			return true;
		}
	}
	checkGolem(g);
	return false;
}

void moveWizard(golemInfo g) {
	int dr[4] = { -1, 0, 1, 0 };
	int dc[4] = { 0, 1, 0, -1 };
	int exitr = g.r + dr[g.d];
	int exitc = g.c + dc[g.d];
	visited[exitr][exitc] = 1;

	for (int i = 0; i < 4; i++) {
		int nexitr = exitr + dr[i];
		int nexitc = exitc + dc[i];
		if (nexitr < 1 || nexitr > R || nexitc < 1 || nexitc > C) continue;
		
		int nextGolemNum = grid[nexitr][nexitc];
		if (visited[golemList[nextGolemNum].r+dr[golemList[nextGolemNum].d]][golemList[nextGolemNum].c + dc[golemList[nextGolemNum].d]]) continue;
		if (nextGolemNum > 0) {
			if (golemList[nextGolemNum].south > theMostSouth) {
				 //cout << "curr golem: " << g.num << ", next golem: " << nextGolemNum << "\n";
				theMostSouth = golemList[nextGolemNum].south;
				
			}
			moveWizard(golemList[nextGolemNum]);
		}
	}
}

int main() {
	/*FILE* fp;
	freopen_s(&fp, "[testcase]_magical-forest-exploration_33.txt", "r", stdin);*/

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(visited, 0, sizeof(visited));
		theMostSouth = 0;
		answer = 0;

		cin >> R >> C >> K;
		golemList.clear();
		golemList.resize(K + 1);
		grid.resize(R + 1, vector<int>(C + 1, 0));
		grid.assign(R + 1, vector<int>(C + 1, 0));

		for (int i = 1; i <= K; i++) {
			golemInfo tmp;
			int c, d;
			cin >> c >> d;
			tmp.num = i;
			tmp.r = -1;
			tmp.c = c;
			tmp.d = d;
			tmp.south = 0;
			golemList[i] = tmp;
		}

		for (int i = 1; i <= K; i++) {
			// move golem
			while (moveGolem(golemList[i])) {}

			// debugging
			/*cout << "after moving golem " << i << "\n";
			for (int r = 1; r <= R; r++) {
				for (int c = 1; c <= C; c++) {
					cout << grid[r][c] << " ";
				}
				cout << "\n";
			}
			cout << "exit of golem " << i << ": " << golemList[i].d << "\n";*/

			// check out of range
			if (golemList[i].r - 1 < 1) {
				for (int r = 1; r <= R; r++) {
					for (int c = 1; c <= C; c++) {
						grid[r][c] = 0;
					}
				}
				continue;
			}

			//// move wizard
			theMostSouth = golemList[i].south;
			memset(visited, 0, sizeof(visited));
			moveWizard(golemList[i]);
			//golemList[i].south = theMostSouth;
			//cout << "current answer: " << answer << ", add the most south: " << theMostSouth << "\n\n";
			answer += theMostSouth;
		}

		cout << "#" << t << " ";
		cout << answer << "\n";
	}
}