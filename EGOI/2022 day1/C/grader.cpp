#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <set>

#include <iostream>

#include "socialengineering.h"

/* Messages:
*/
/* Correct:
   C 1: Correct because Maria gave up
   C 2: Correct because solution gave up in losing position
*/
/* Error messages:
   W 1: GetMove called in someone else's turn
   W 2: MakeMove called in Maria's turn
   W 3: Incorrect move. No such edge, or already challenged.
   W 4: Gave up even though a winning strategy existed.
   W 5: Ended the game early
*/

using namespace std;

vector<vector<int>> _graph;

int _turn;
int _moved = 0;
int _winning = 1; // the sample grades assumes a winning strategy always exists, which may not be the case in some test inputs

set<pair<int,int>> _edges;

bool _CanChallenge(int u, int v){
        return _edges.find({u, v}) != _edges.end();
}

int GetMove() {
        _moved = 1;
        if (_turn!=1) {
                printf("GetMove called in someone else's turn.\n");
		exit(0);
        }

        // The strategy below is an arbitray one, not the winning strategy implemented by the actual grader
        while(_graph[1].size() > 0){
                int v = _graph[1].back();
                _graph[1].pop_back();
                if(!_CanChallenge(1, v)) continue;
                _turn = v;
                _edges.erase({1, v});
                _edges.erase({v, 1});
                return v;
        }
        return 0;
}

void MakeMove(int v) {
        if (_turn==1)
        {
                printf("MakeMove called in Maria's turn\n");
		exit(0);
        }
        if (!_CanChallenge(_turn, v)) {
                printf("Incorrect move. No such edge, or already challenged.\n");
		exit(0);
        }
        else
        {
                _edges.erase({_turn, v});
                _edges.erase({v, _turn});
                _turn = v;
        }
}

int main() {

        int n,m;

	scanf("%d%d", &n, &m);

        _turn = 1;
        _graph.resize(n+1);
        vector<pair<int,int> > edges;

	for (int i = 0; i < m; ++i) {
                int u, v;
		scanf("%d%d", &u, &v);
                _edges.insert({u, v});
                _edges.insert({v, u});
                _graph[u].push_back(v);
                _graph[v].push_back(u);
                edges.push_back({u, v});
	}

	SocialEngineering(n, m, edges);

        if (_moved==0) {
                if(_winning){
                        printf("Gave up even though a winning strategy existed.\n");
                }
                else{
                        // Accepted: gave up in a losing position
                        printf("Correct because solution gave up in losing position.\n");
                }
        }
        else if (GetMove()==0) {
                printf("Correct because Maria gave up.\n");
        }
        else {
                printf("Ended the game early.\n");
        }
	return 0;
}
