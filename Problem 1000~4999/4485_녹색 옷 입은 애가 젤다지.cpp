int bfs() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			dist[i][j] = INF;

	queue<p> q;
	q.push({ 0, 0 });
	dist[0][0] = board[0][0];

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = x + Dir[i].first;
			int ny = y + Dir[i].second;
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				// ºñ¿ëÀÌ ´õ Å¬ °æ¿ì, update
				if (dist[nx][ny] > dist[x][y] + board[nx][ny]) {
					dist[nx][ny] = dist[x][y] + board[nx][ny];
					q.push({ nx, ny });
				}
			}
		}
	}
	return dist[n - 1][n - 1];
}
