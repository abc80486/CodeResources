#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

typedef  int State[9];
const int MAXSTATE=1000000;
State st[MAXSTATE],goal;
int dist[MAXSTATE];

set<int> vis;
void init_lookup