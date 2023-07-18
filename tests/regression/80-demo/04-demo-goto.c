// TERM PARAM: --set "ana.activated[+]" termination --set ana.activated[+] apron --enable ana.int.interval --set ana.apron.domain polyhedra
int main()
{
  int i = 0;
  end: // Set at wrong place

  if (i) {
    goto end;
  } else {
    return 1;
  }

  return 0;
}
