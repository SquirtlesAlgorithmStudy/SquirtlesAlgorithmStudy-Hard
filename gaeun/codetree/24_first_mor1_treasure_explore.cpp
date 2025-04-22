#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int K, M;
vector<vector<int>> grid(6, vector<int>(6));
vector<int> wallNumbers;
bool visited[6][6] = { 0, };
vector<pair<int, int>> coord;
int cnt;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int seq = 0;
vector<int> result;
int turn = 1;

void rotate(int r, int c) {
	vector<vector<int>> tmp(6, vector<int>(6));
	tmp = grid;
	for (int i = r - 1; i <= r + 1; i++) {
		for (int j = c - 1; j <= c + 1; j++) {
			grid[r+j-c][c+r-i] = tmp[i][j];
		}
	}
}

void dfs(int r, int c) {
	visited[r][c] = 1;
	cnt++;
	coord.push_back({ r,c });

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 1 || nr>5 || nc < 1 || nc>5) continue;
		if (visited[nr][nc]) continue;
		if (grid[nr][nc] != grid[r][c]) continue;

		dfs(nr, nc);
	}
}

int getTreasure() {
	int totalTreasure = 0;
	coord.clear();
	memset(visited, 0, sizeof(visited));

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (!visited[i][j]) {
				cnt = 0;
				dfs(i, j);
				if (cnt > 2) {
					totalTreasure += cnt;
					for (int k = 0; k < coord.size(); k++) {
						pair<int, int> p = coord[k];
						grid[p.first][p.second] = 0;
					}
				}
				coord.clear();
			}			
		}
	}
	return totalTreasure;
}

void makeNew() {
	for (int j = 1; j <= 5; j++) {
		for (int i = 5; i >= 1; i--) {
			if (grid[i][j] == 0) {
				grid[i][j] = wallNumbers[seq];
				seq++;
			}
		}
	}
}

void explore() {
	int maxTreasure = 0;
	int degree = 270;
	vector<vector<int>> gridAfterGetTresure(6, vector<int>(6));
	vector<vector<int>> original(6, vector<int>(6));
	original = grid;
	int ansr, ansc;

	for (int c = 4; c >= 2; c--) {
		for (int r = 4; r >= 2;r--) {
			//cout << "rotate at (" << r << "," << c << ")\n";
			rotate(r, c);
			rotate(r, c);
			rotate(r, c);
			int treasure = getTreasure();
			//cout << "270: " << treasure << "\n";
			if (maxTreasure < treasure) {
				maxTreasure = treasure;
				degree = 270;
				gridAfterGetTresure = grid;
				ansr = r;
				ansc = c;
			}
			if (maxTreasure == treasure) {
				if (degree >= 270) {
					maxTreasure = treasure;
					degree = 270;
					gridAfterGetTresure = grid;
					ansr = r;
					ansc = c;
				}
			}
			grid = original;

			rotate(r, c);
			rotate(r, c);
			treasure = getTreasure();
			//cout << "180: " << treasure << "\n";
			if (maxTreasure < treasure) {
				maxTreasure = treasure;
				degree = 180;
				gridAfterGetTresure = grid;
				ansr = r;
				ansc = c;
			}
			if (maxTreasure == treasure) {
				if (degree >= 180) {
					maxTreasure = treasure;
					degree = 180;
					gridAfterGetTresure = grid;
					ansr = r;
					ansc = c;
				}
			}
			grid = original;

			rotate(r, c);
			treasure = getTreasure();
			/*cout << "90: " << treasure << "\n";*/
			if (maxTreasure < treasure) {
				maxTreasure = treasure;
				degree = 90;
				gridAfterGetTresure = grid;
				ansr = r;
				ansc = c;
			}
			if (maxTreasure == treasure) {
				if (degree >= 90) {
					maxTreasure = treasure;
					degree = 90;
					gridAfterGetTresure = grid;
					ansr = r;
					ansc = c;
				}
			}
			grid = original;

			/*cout << "max: " << maxTreasure << "\n";
			cout << "degree: " << degree << "\n\n";*/
		}
	}
	grid = gridAfterGetTresure;
	cout << "selected: (" << ansr << "," << ansc << "), degree: " << degree << "\n";
	cout << "\nAfter decide rotation\n";
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}

	if (maxTreasure == 0) {
		turn = K+1;
		return;
	}
	
	int n = maxTreasure;
	while (n > 0) {
		makeNew();
		cout << "\nAfter make new\n";
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 5; j++) {
				cout << grid[i][j] << " ";
			}
			cout << "\n";
		}
		n = getTreasure();
		cout << "\nAfter get additionally\n";
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 5; j++) {
				cout << grid[i][j] << " ";
			}
			cout << "\n";
		}
		maxTreasure += n;
	}
	cout << "turn" << turn << ": " << maxTreasure << "\n";
	result.push_back(maxTreasure);
	turn++;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> K >> M;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int w;
		cin >> w;
		wallNumbers.push_back(w);
	}

	while (turn <= K) {
		explore();
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}

//int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
//
//	int T;
//	cin >> T;
//	
//	for (int t = 1; t <= T; t++) {
//		wallNumbers.clear();
//		memset(visited, 0, sizeof(visited));
//		seq = 0;
//		result.clear();
//		turn = 1;
//
//		cin >> K >> M;
//		for (int i = 1; i <= 5; i++) {
//			for (int j = 1; j <= 5; j++) {
//				cin >> grid[i][j];
//			}
//		}
//		for (int i = 0; i < M; i++) {
//			int w;
//			cin >> w;
//			wallNumbers.push_back(w);
//		}
//
//		while (turn <= K) {
//			explore();
//		}
//
//		cout << "#" << t << " ";
//		for (int i = 0; i < result.size(); i++) {
//			cout << result[i] << " ";
//		}
//	}	
//}