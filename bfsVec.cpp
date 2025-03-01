#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 0X7FFFFFFF

class Graph {
  int n;
  vi  dist;
  queue <int> qbfs;
  queue<int> q;
  vector<vi> adjList;
  public:
    Graph(int n) {
      this->n = n;
      adjList.assign(n,vi());
      dist.assign(n, INF);
     }

    void addEdge(int u, int v){
         adjList[u].push_back(v); // doble si indirecto
    }

   void bfs(int s){
      dist[s] = 0;
      q.push(s);
      while (!q.empty()) {
         int u = q.front(); q.pop();
         qbfs.push(u);
         for (int v : adjList[u]) {
            if (dist[v] == INF) {
               dist[v] = dist[u] + 1;
               q.push(v);
            }
         }
      }
   }

   void do_bfs()
   {
     dist.assign(n,INF);
     for(int i = 0; i < n; i++)
        if(dist[i] == INF)
           bfs(i);
   }

    void printPath(){
      const int maxi  = 15;
      int size = qbfs.size();
      int count = 0;
      printf(" %d \n", size);
      while( !qbfs.empty()){
         count++;
	 int v = qbfs.front(); qbfs.pop();
	 if (count < maxi) printf(" %d ", v);
	 if (count == maxi) printf(" \n");
	 if (size > maxi)
	    if((size - count) <= maxi )  printf(" %d ", v);
      }
      printf(" \n");
   }

 };

 void display(vii vec){
      const int maxi  = 15;
      int size  = (int)vec.size();
      if(size <= maxi){
        for(int i = 0; i < size; i++)
           printf("%d %d - ", vec[i].first, vec[i].second);
      }else{
        for(int i = 0; i < maxi; i++)
           printf("%d %d - ", vec[i].first, vec[i].second);
        printf("\n");
        for(int i = size - maxi; i < size; i++)
           printf("%d %d - ", vec[i].first, vec[i].second);
      }
      printf("\n");
 }

int main() {
    string str;
    ii  pairTwo;
    vii vecTwo;
    int  N, M, u,v,w,n,m;
//    scanf("%d %d", &N, &M);
    scanf("%d", &n);
    while (  scanf("%d %d ",&u, &v) != EOF) {
	pairTwo.first = u;
	pairTwo.second= v;
        vecTwo.push_back(pairTwo);
    }
   m = vecTwo.size();
    printf("n = %d  m = %d\n", n, m);
    display(vecTwo);

     //prevStart

    Graph g =  Graph(n);
    for (int i = 0; i < m; ++i) {
	 u = vecTwo[i].first;
	 v = vecTwo[i].second;
	 g.addEdge(u,v);
      }
      u = vecTwo[0].first;

      auto start = high_resolution_clock::now();
      g.do_bfs();
      auto stop = high_resolution_clock::now();

      printf("printPath \n");
      g.printPath();

    //prevstop
    auto duration = duration_cast<microseconds>(stop - start);

     cout << endl  << "Duracion: "
         << duration.count() << " microsegundos" << endl;
      cout << endl;

    return 0;
}
