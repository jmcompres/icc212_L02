#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

int main ( int argc, char * argv[]) {

   int i, u, v, nodes = 10, edges = 12;

   if( argc > 1) nodes =  stoi( argv[1] );
   if( argc > 2)  edges =  stoi( argv[2] );

   srand( (unsigned)time( NULL ) );

   cout<<nodes<<endl;

   for( i = 0; i < edges; i++ ) {
      u = rand() % nodes;
      v = rand() % nodes;
      cout  << u << ' ' << v << endl;
   }

   return 0;
}

