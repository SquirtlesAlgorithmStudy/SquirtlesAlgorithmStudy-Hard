#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

int N, M, K;
struct gridTopInfo {
	int attack;
	int recent;
};
gridTopInfo grid[11][11];
struct sortTopInfo {
	int attack;
	int recent;
	int r, c;
};


bool compare(sortTopInfo a, sortTopInfo b) {
	if (a.attack != b.attack) return a.attack < b.attack;
	if (a.recent != b.recent) return a.recent > b.recent;
	if (a.r + a.c != b.r + b.c) return a.r + a.c > b.r + b.c;
	return a.c > b.c;
}

vector<sortTopInfo> findTop(int turn) {
	vector<sortTopInfo> topList;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			sortTopInfo tmp;
			tmp.r = i;
			tmp.c = j;
			tmp.recent = grid[i][j].recent;
			tmp.attack = grid[i][j].attack;
			topList.push_back(tmp);
		}
	}
	sort(topList.begin(), topList.end(), compare);
	/*cout << "sorting topList: \n";
	for (sortTopInfo t : topList) cout << t.r << " " << t.c << " " << t.attack << " " << t.recent << "\n";*/

	// choose attackTop
	sortTopInfo attackTop;
	for (int i = 0; i < topList.size(); i++) {
		if (topList[i].attack <= 0)continue;
		topList[i].attack += N + M;
		grid[topList[i].r][topList[i].c].attack += N + M;
		topList[i].recent = turn;
		grid[topList[i].r][topList[i].c].recent = turn;
		attackTop = topList[i];
		break;
	}

	// choose targetTop
	sortTopInfo targetTop;
	for (int i = topList.size() - 1; i >= 0; i--) {
		if (topList[i].attack <= 0) continue;
		if (topList[i].r == attackTop.r && topList[i].c == attackTop.c) continue;
		targetTop = topList[i];
		break;
	}
	vector<sortTopInfo> result;
	result.push_back(attackTop);
	result.push_back(targetTop);
	return result;
}

void attack(int turn) {
	bool related[11][11] = { 0, };
	vector<sortTopInfo> tops = findTop(turn);
	sortTopInfo attackTop = tops[0];
	sortTopInfo targetTop = tops[1];

	related[attackTop.r][attackTop.c] = 1;
	related[targetTop.r][targetTop.c] = 1;

	/*cout << "attackTop: " << "(" << attackTop.r << "," << attackTop.c << ")\n";
	cout << "targetTop: " << "(" << targetTop.r << "," << targetTop.c << ")\n";*/

	queue<pair<int, int>> q;
	bool visited[11][11] = { 0, };
	int dr[4] = { 0,1,0,-1 }; // ¿ìÇÏÁÂ»ó
	int dc[4] = { 1,0,-1,0 };
	pair<int,int> parent[11][11];

	q.push({ attackTop.r, attackTop.c });
	visited[attackTop.r][attackTop.c] = 1;

	pair<int, int> curr;
	while (!q.empty()) {
		curr = q.front(); q.pop();
		visited[curr.first][curr.second] = 1;

		if (curr.first == targetTop.r && curr.second == targetTop.c) break;

		for (int i = 0; i < 4; i++) {
			int nr = curr.first + dr[i];
			int nc = curr.second + dc[i];
			if (nr < 1)nr = N;
			if (nr > N)nr = 1;
			if (nc < 1)nc = M;
			if (nc > M) nc = 1;

			if (visited[nr][nc]) continue;
			if (grid[nr][nc].attack <= 0) continue;

			visited[nr][nc] = 1;
			parent[nr][nc] = { curr.first, curr.second };
			q.push({ nr,nc });
		}
	}

	// laser attack is possible
	if (curr.first == targetTop.r && curr.second == targetTop.c) {
		//cout << "laser attack!!\n";
		vector<pair<int, int>> path;
		while (!(curr.first == attackTop.r && curr.second == attackTop.c)) {
			path.push_back(parent[curr.first][curr.second]);
			curr = parent[curr.first][curr.second];
		}
		path.pop_back();

		/*cout << "path: \n";
		for (pair<int, int> p : path)cout << "(" << p.first << "," << p.second << ")\n";*/

		for (int i = 0; i < path.size(); i++) {
			if (grid[path[i].first][path[i].second].attack <= 0) continue;
			grid[path[i].first][path[i].second].attack -= attackTop.attack / 2;
			related[path[i].first][path[i].second] = 1;
		}
		grid[targetTop.r][targetTop.c].attack -= attackTop.attack;
	}
	// potan attack
	else {
		//cout << "potan attack!!\n";
		int pdr[8] = { -1,-1,-1,0,0,1,1,1 };
		int pdc[8] = { -1,0,1,-1,1,-1,0,1 };

		for (int i = 0; i < 8; i++) {
			int nr = targetTop.r + pdr[i];
			int nc = targetTop.c + pdc[i];
			if (nr < 1)nr = N;
			if (nr > N)nr = 1;
			if (nc < 1)nc = M;
			if (nc > M) nc = 1;
			if (nr == attackTop.r && nc == attackTop.c) continue;

			if (grid[nr][nc].attack <= 0) continue;
			grid[nr][nc].attack -= attackTop.attack / 2;
			related[nr][nc] = 1;
		}
		grid[targetTop.r][targetTop.c].attack -= attackTop.attack;
	}
	
	// repair
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			if (related[r][c] == 0 && grid[r][c].attack > 0) grid[r][c].attack++;
			if (grid[r][c].attack < 0)grid[r][c].attack = 0;
		}
	}

}

int main() {
	FILE* fp;
	freopen_s(&fp, "[Testcase]_top_attack.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				gridTopInfo tmp;
				cin >> tmp.attack;
				tmp.recent = 0;
				grid[i][j] = tmp;
			}
		}

		for (int i = 1; i <= K; i++) {
			int cnt = 0;
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (grid[i][j].attack > 0) cnt++;
				}
			}
			if (cnt > 1) attack(i);
			else break;

			/*cout << "after attack " << i << "\n";
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					cout << left << setw(4) << grid[i][j].attack << " ";
				}
				cout << "\n";
			}*/
		}

		int answer = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (grid[i][j].attack > answer) {
					answer = grid[i][j].attack;
				}
			}
		}
		cout << "#" << t << " ";
		cout << answer << "\n";
	}
}