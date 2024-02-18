#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;
int n, m, q, fa[N][20], w[N][20], vis[N], dep[N];
vector<pair<int, int> > g[N];

struct edge{
	int u, v, w;
} e[N];
bool cmp(edge a, edge b){
	return a.w > b.w;
}

int f[N];
int gf(int x){
	if(x == f[x]){
		return x;
	}
	return f[x] = gf(f[x]);
}

void dfs(int x, int faa){
	vis[x] = 1;
	dep[x] = dep[faa] + 1;
	for(auto i : g[x]){
		int y = i.first, z = i.second;
		if(y == faa){
			continue;
		}
		fa[y][0] = x;
		w[y][0] = z;
		for(int i = 1; i < 20; ++ i){
			fa[y][i] = fa[fa[y][i-1]][i-1];
			w[y][i] = min(w[y][i-1], w[fa[y][i-1]][i-1]);
		}
		dfs(y, x);
	}
}
int lca(int x, int y){
	int ans = 0x3f3f3f3f;
	if(dep[x] < dep[y]){
		swap(x, y);
	}
	for(int i = 19; i >= 0; -- i){
		if(dep[fa[x][i]] >= dep[y]){
			ans = min(ans, w[x][i]);
			x = fa[x][i];
		}
	}
	if(x == y){
		return ans;
	}
	for(int i = 19; i >= 0; -- i){
		if(fa[x][i] != fa[y][i]){
			ans = min(ans, w[x][i]);
			ans = min(ans, w[y][i]);
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return min(ans, min(w[x][0], w[y][0]));
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1; i <= m; ++ i){
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	}
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= n; ++ i){
		f[i] = i; 
	}
	for(int i = 1; i <= m; ++ i){
		if(gf(e[i].u) != gf(e[i].v)){
			f[gf(e[i].u)] = gf(e[i].v);
			g[e[i].u].push_back(make_pair(e[i].v, e[i].w));
			g[e[i].v].push_back(make_pair(e[i].u, e[i].w));
		}
	}
	dep[0] = 1;
	for(int i = 1; i <= n; ++ i){
		if(!vis[i]){
			dfs(i, 0);
		}
	}
	for(int i = 1; i <= q; ++ i){
		int x, y;
		scanf("%d%d", &x, &y);
		if(gf(x) != gf(y)){
			puts("-1");
		} else {
			printf("%d\n", lca(x, y));
		}
	}
	return 0;
}