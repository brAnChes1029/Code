#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>

#include "toydesign.h"

using namespace std;

vector<vector<int>> designs;
vector<int> base;
int n,m,max_ops,ops;

vector<int> merge(vector<int> a, int p, int q) {
  int src = a[p];
  int dst = a[q];
  assert(src != dst);
  if (src < dst) swap(src, dst);
  for (auto& x : a) if (x == src) x = dst;
  return a;
}

int Connected(int a,int i,int j) {
    ++ops;
    if (ops > max_ops) {
        printf("Wrong answer: Number of operations exceeds the limit.\n");
        exit(0);        
    }
    --i; --j;
    if (a < 0 || a >= designs.size()) {
        printf("Wrong answer: Wrong design id.\n");
        exit(0);
    }
    vector<int> d = designs[a];
    if (d[i] == d[j]) {
        return a;
    } else {
        designs.push_back(merge(d, i, j));
        return designs.size() - 1;
    }
}

void DescribeDesign(vector <pair<int,int> > edges) {
    vector<int> have = base;
    int m;
    for (int ii = 0; ii < edges.size(); ++ii) {
        int i = edges[ii].first;
        int j = edges[ii].second;
        --i; --j;
        if (have[i] != have[j]) {
            have = merge(have, i, j);
        }
    }
    if (have == designs[0]) {
        printf("OK!\n");
        exit(0);
    }
    else {
        printf("Wrong answer: Incorrect design.\n");
        exit(0);
    }
}

int main(int argc, char **argv) {

	scanf("%d%d%d", &n, &m, &max_ops);
    base.resize(n);

    for (int i = 0; i < n; ++i)
        base[i] = i;

    designs.push_back(base);

    for (int i = 0; i < m; ++i) {
        int a,b;
	    scanf("%d%d", &a, &b);
        a--;
        b--;
        if (designs[0][a] != designs[0][b]) designs[0] = merge(designs[0], a, b);
    }

	ToyDesign(n, max_ops);

	return 0;
}
