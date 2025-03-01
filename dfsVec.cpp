// https://www.programiz.com/dsa/graph-dfs
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

class Graph {
  int n;
  vector<vi> adjList;
  vb visited;
  vi toposort;
  stack<int> stc;

  public:
    Graph(int n){
       this->n = n;
       adjList.assign(n, vi());
       visited.assign(n, false);
       toposort.assign(n,-1);
    }

    void addEdge(int u, int v){
       adjList[u].push_back(v);
    }

    void dfs(int u){
       visited[u] = true;
       for(int j  = 0; j < (int)adjList[u].size(); j++){
          int v = adjList[u][j];
          if(!visited[v])
            dfs(v);
       }
       toposort.push_back(u);
       stc.push(u);
    }

   void do_dfs(){
     toposort.clear();
     visited.assign(n,false);
     for(int i = 0; i < n; i++)
        if(!visited[i])
           dfs(i);
//     impreTop();
   }

   void impreTopo(vi top){
      int size  = top.size();
      const int maxi  = 10;
      if(size <= maxi){
        for(int i = 0; i < size; i++)
           printf("%d ", top[i]);
      }else{
        for(int i = 0; i < maxi; i++)
           printf("%d ", top[i]);
        printf("\n");
        for(int i = size - maxi; i < size; i++)
           printf("%d ", top[i]);
      }
      printf("\n");
   }

   void impreTop(){
      int size  = stc.size();
      const int maxi  = 15;
      int count = 0;
      while(!stc.empty()){
	 int u = stc.top();
         stc.pop();
	 count++;
         if(count <= maxi){
              printf("%d ", u);
         }else{
              if((size - count) == maxi)
                  printf(" \n ------------  \n");
              if((size - count) <= maxi)
                  printf("%d ", u);
        }
     }
     printf("\n");
   }

   vi getTopoVec()
   {
      return toposort;
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
    int  n,m,u,v;
    scanf("%d", &n );

    while (  scanf("%d %d",&u, &v  ) != EOF) {
	pairTwo.first  = u;
	pairTwo.second = v;
        vecTwo.push_back(pairTwo);
    }

    m = vecTwo.size();

    printf("n = %d  m = %d\n", n, m);
    display(vecTwo);
    cout << endl;
    cout << "Recorrido dfs: topologia" << endl;

    Graph g =  Graph(n);

    for (int i = 0; i < m; ++i) {
	 u = vecTwo[i].first;
	 v = vecTwo[i].second;
	 g.addEdge(u,v);
      }

    auto start = high_resolution_clock::now();
    g.do_dfs();
    auto stop = high_resolution_clock::now();

    vi toposort = g.getTopoVec();
    reverse(toposort.begin(), toposort.end());
    g.impreTopo(toposort);

    auto duration = duration_cast<microseconds>(stop - start);

     cout << endl << "Duracion: " ;
     cout    << duration.count() << " microsegundos" << endl;
      cout << endl;

  return 0;
}
