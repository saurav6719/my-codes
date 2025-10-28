#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 100000, "n");
    inf.readEoln();

    vector<int> a = inf.readInts(n, 1, 1000000000, "a[i]");
    inf.readEoln();

    int q = inf.readInt(1, 100000, "q");
    inf.readEoln();

    for (int i = 0; i < q; i++) {
        int l = inf.readInt(1, n, "l");
        inf.readSpace();
        int r = inf.readInt(l, n, "r");
        inf.readEoln();
    }

    inf.readEof();
}
