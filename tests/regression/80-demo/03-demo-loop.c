// TERM PARAM: --set "ana.activated[+]" termination --set ana.activated[+] apron --enable ana.int.interval --set ana.apron.domain polyhedra
int main()
{
  int i = 0;

  while (i < 10)
  {
    i--; // wrong direction --/++
  }

  return 0;
}
