#include<iostream>
#include<cmath>

using namespace std;

class BinaryIndexedTree {
    private:
        long long *Table;
        int Size;    
    public:
        BinaryIndexedTree(int size) {
            Table = new long long[size + 1]{0};
            Size = size + 1;
        }

        long long getSum(int index) { // Time Complexity : O(log2n)
            long long sum = 0;
            while(index > 0) {
                sum += Table[index];
                index -= (index & (-index));
            }
            return sum;
        }

        void update(int index, int value) { // Time Complexity : O(log2n)
            while(index < Size) {
                Table[index] += value;
                index += (index & (-index));
            }
        }

        long long rangeSum(int index1, int index2) { // Time Complexity : O(log2n);
            long long a, b;
            a = getSum(index1 - 1);
            b = getSum(index2);
            return b - a;
        }

        // Find index with given cumulative frequency
        int find(int cum_Fre) {
            int idx = 0, k = log2(Size), bitmask = pow(2, k), tidx;
            while(bitmask != 0) {
                tidx = idx + bitmask;
                bitmask >>= 1;
                if(tidx >= Size)    continue;
                if(Table[tidx] == cum_Fre) 
                    return tidx;
                else if(cum_Fre > Table[tidx]) {
                    idx = tidx;
                    cum_Fre -= Table[tidx];
                }
            }
            return ((idx + 1 == Size)? -1: idx + 1);
        }
};

int main() {
    int n, q, index1, index2;
    string operation;// "find" or "add"
    cin >> n >> q;
    BinaryIndexedTree BIT(n);
    while(q--) {
        cin >> operation >> index1 >> index2;
        if(operation == "find")
            cout << BIT.rangeSum(index1, index2) << "\n";
        else 
            BIT.update(index1, index2);
    }
    int result = BIT.find(121);
    cout << result << "\n";
    return 0;
}
// 8 2 10 100 1 2 
