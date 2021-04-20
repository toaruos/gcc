#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS() \
	do { \
		builtin_define_std ("toaru"); \
		builtin_define_std ("unix"); \
		builtin_assert ("system=toaru"); \
		builtin_assert ("system=unix"); \
	} while (0);

#undef STARTFILE_SPEC
#define STARTFILE_SPEC "%{!shared: %{!pg:crt0.o%s}} crti.o%s %{!shared:crtbegin.o%s}"

#undef ENDFILE_SPEC
#define ENDFILE_SPEC "%{!shared:crtend.o%s} crtn.o%s"

#undef LIB_SPEC
#define LIB_SPEC "%{pthread:-lpthread} -lc"

#undef LINK_SPEC
#define LINK_SPEC "%{shared:-shared} %{static:-static} %{!shared: %{!static: %{rdynamic:-export-dynamic} %{!dynamic-linker:-dynamic-linker /lib/ld.so}}}"

