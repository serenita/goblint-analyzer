// TERM PARAM: --set "ana.activated[+]" termination --set ana.activated[+] apron --enable ana.int.interval --set ana.apron.domain polyhedra
#include <stdio.h>

void recursiveFunction(int i) {
    if (i <= 0) {
        return;
    }

    recursiveFunction(i--); // Post-increment leads to i as argument
}

int main()
{
  recursiveFunction(10);
  return 0;
}
