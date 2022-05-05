#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll tree[4040404];
ll arr[1010101];
int N, M, K;

ll merge(ll left, ll right){
    return left + right;
}

void build(int start=1, int end=N, int node=1){
    if (start == end) {
        tree[node] = arr[start-1];
        return;
    }
    int mid = start + end >> 1; // start + (end - start)/2
    build(start, mid, node<<1); // node*2
    build(mid+1, end, node<<1|1); // node*2+1
    tree[node] = merge(tree[node<<1], tree[node<<1|1]);
}

void update(int index, ll value, int start=1, int end=N, int node=1){
    if (start == end){
        tree[node] = value;
        return;
    }
    int mid = start + end >> 1; // start + (end - start)/2
    if (index <= mid) update(index, value, start, mid, node<<1); // node*2
    else update(index, value, mid+1, end, node<<1|1); // node*2+1
    tree[node] = merge(tree[node<<1], tree[node<<1|1]);
}

ll query(int left, int right, int start=1, int end=N, int node=1){
    if (end < left || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = start + end >> 1; // start + (end - start)/2
    return merge(query(left, right, start, mid, node<<1),
             query(left, right, mid+1, end, node<<1|1));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> K;
    for (int i=0; i<N; ++i) cin >> arr[i];
    build();
    int op; ll l, r;
    for (int i=0; i<M+K; ++i) {
        cin >> op >> l >> r;
        if (op == 1){
            update(l, r);
        } else {
            cout << query(l, r) << '\n';
        }
    }
}
