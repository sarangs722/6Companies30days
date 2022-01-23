typedef pair<int, pair<int, int>> pai;

pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
{
    // code here
    pair<int, int> ans;
    int mini = INT_MAX, mx = 0, minele = INT_MAX, maxele = INT_MIN, range = INT_MAX;
    pair<int, int> min_idx;
    priority_queue<pai, vector<pai>, greater<pai>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(make_pair(KSortedArray[i][0], make_pair(i, 0)));
        mx = max(mx, KSortedArray[i][0]);
    }
    while (1)
    {
        mini = pq.top().first;
        min_idx = pq.top().second;
        pq.pop();
        if (mx - mini < range)
        {
            maxele = mx;
            minele = mini;
            range = (mx - mini);
            ans = make_pair(mini, mx);
        }
        int x = min_idx.first;
        int y = min_idx.second + 1;
        if (y == n)
            break;
        if (KSortedArray[x][y] > mx)
            mx = KSortedArray[x][y];
        pq.push(make_pair(KSortedArray[x][y], make_pair(x, y)));
    }
    return ans;
}
