#include <cstdio>
#include "fibheap.h"

int main() {
    fibheap myheap = fibheap();
    printf("created heap");
    myheap.insert(4);
    myheap.insert(5);
    printf("%d", myheap.min_root->get_key());
    return 0;
}