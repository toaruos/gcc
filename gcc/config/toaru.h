/* Operating system specific defines for ToaruOS */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS() \
  do { \
    builtin_define_std ("toaru"); \
    builtin_define_std ("unix"); \
    builtin_assert ("system=toaru"); \
    builtin_assert ("system=unix"); \
  } while (0);

/* Standard crt stuff */
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "%{!shared: %{!pg:crt0.o%s}} crti.o%s %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC "%{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s"

/* There is no -lpthread, libc has pthreads by default. */
#undef LIB_SPEC
#define LIB_SPEC "%{pthread:} %{!shared:%{!symbolic:-lc}}"

/* Support -rdynamic, -shared, -symbolic, set dynamic linker path */
#undef LINK_SPEC
#define LINK_SPEC \
   "%{shared:-shared} \
    %{static:-static} \
    %{!shared: \
      %{rdynamic:-export-dynamic} \
      %{!static: \
        %{!dynamic-linker:-dynamic-linker /lib/ld.so} \
      } \
    } \
    %{symbolic:-Bsymbolic}"

/*
 * TODO:
 *  Are there other things we can add here to make linking with, eg., ToaruOS libraries easier? Kernel stuff?
 */
