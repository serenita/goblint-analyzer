open OUnit2

let memset_desc: LibraryDesc.desc = LibraryDsl.(
  ["dest" >~ [w]; "ch" >~ []; "count" >~ []] >> `Unknown
)

let pthread_mutex_lock_desc: LibraryDesc.desc = LibraryDsl.(
  [__ [r]] >> fun e -> `Lock e
)

let pthread_create_desc: LibraryDesc.desc = LibraryDsl.(
  ["thread" >: [w]; "attr" >~ [r]; "start_routine" >: [r]; "arg" >: [r]] >> fun thread start_routine arg -> `ThreadCreate (thread, start_routine, arg)
)

let realloc_desc: LibraryDesc.desc = LibraryDsl.(
  ["ptr" >: [r; f]; "size" >: []] >> fun ptr size -> `Realloc (ptr, size)
)

let tests =
  "libraryDslTest" >::: [

  ]
