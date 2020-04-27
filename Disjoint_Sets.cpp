// Disjoint Sets Data Structures (optimised with path compression & Union by rank)
#include<bits/stdc++.h>

using namespace std;

class DisjSet {
    private:
        int *parent, n;
    public:
        DisjSet(int n) {
            parent = new int[n]{0};
            memset(parent, -1, n * sizeof(int));
            this -> n = n;
        }
        int _find(int x) {
            // Path compression
            if(parent[x] >= 0) {
                parent[x] = _find(parent[x]);
            }
            else 
                return x; 
            return parent[x];
        }
        void _union(int x, int y) {
            int parent_x = _find(x);
            int parent_y = _find(y);
            if(parent_x == parent_y)
                return ;

            // Union by Rank
            if(abs(parent[parent_x]) < abs(parent[parent_y])) {
                parent[parent_x] = parent_y;
            }
            else if(abs(parent[parent_x]) > abs(parent[parent_y])) {
                parent[parent_y] = parent_x;
            }
            else {
                parent[parent_y] = parent_x;
                parent[parent_x] -= 1;
            }
        }
};

int main() {
    DisjSet obj(5);
    obj._union(1, 2); 
    obj._union(3, 4); 
    obj._union(4, 5);
    obj._union(1, 3);
    if (obj._find(4) == obj._find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
    if (obj._find(1) == obj._find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
    return 0;
}

// Application of Disjoint set Data Structures:
//  1. Kruskal minimum spanning tree Algorithm
//  2. Optimisation in job sequencing problem(O(n^2) to O(nlogn))
//  3. Cycle Detection

// Ancient Berland Roads
// K complete Word