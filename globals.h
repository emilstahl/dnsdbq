#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED 1

#include "sort.h"

#ifdef MAIN_PROGRAM
#define EXTERN
#define INIT(...) = __VA_ARGS__
#else
#define EXTERN extern
#define INIT(...)
#endif

#ifndef MAIN_PROGRAM
extern const struct verb verbs[];
#endif

EXTERN	const char id_swclient[]	INIT("dnsdbq");
EXTERN	const char id_version[]		INIT("1.999");
EXTERN	const char *program_name	INIT(NULL);
EXTERN	const char path_sort[]		INIT("/usr/bin/sort");
EXTERN	const char json_header[]	INIT("Accept: application/json");
EXTERN	const char env_time_fmt[]	INIT("DNSDBQ_TIME_FORMAT");
EXTERN	verb_ct pverb			INIT(NULL);
EXTERN	pdns_system_ct psys		INIT(NULL);
EXTERN	int debug_level			INIT(0);
EXTERN	long query_limit		INIT(-1L);
EXTERN	long output_limit		INIT(-1L);
EXTERN	bool donotverify		INIT(false);
EXTERN	bool quiet			INIT(false);
EXTERN	bool info			INIT(false);
EXTERN	bool complete			INIT(false);
EXTERN	bool iso8601			INIT(false);
EXTERN	bool sort_byname		INIT(false);
EXTERN	bool sort_bydata		INIT(false);
EXTERN	bool gravel			INIT(false);
EXTERN	long offset			INIT(0L);
EXTERN	long max_count			INIT(0L);
EXTERN	sort_e sorted			INIT(no_sort);
EXTERN	present_e presentation		INIT(text);
EXTERN	present_t presenter		INIT(NULL);
EXTERN	struct timeval startup_time	INIT({0,0});
EXTERN	int exit_code			INIT(0);

#undef INIT
#undef EXTERN

void debug(bool, const char *, ...);
__attribute__((noreturn)) void usage(const char *, ...);
__attribute__((noreturn)) void my_exit(int);
__attribute__((noreturn)) void my_panic(bool, const char *);
const char *or_else(const char *, const char *);

#endif /*GLOBALS_H_INCLUDED*/