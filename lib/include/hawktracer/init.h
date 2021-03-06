#ifndef HAWKTRACER_INIT_H
#define HAWKTRACER_INIT_H

#include <hawktracer/macros.h>

HT_DECLS_BEGIN

/**
 * Initializes HawkTracer library.
 *
 * This function must be called before any other function
 * from this library. The only exception is ht_allocator_set(),
 * which must be called before ht_init().
 *
 * @param argc a number of arguments of the @a argv array.
 * @param argv an array of strings - arguments for HawkTracer library.
 */
HT_API void ht_init(int argc, char** argv); /* TODO: consider passing allocator here */

/**
 * Uninitializes HawkTracer library.
 *
 * This function must be called as a last function
 * of the library in the program. The only exception is
 * ht_timeline_deinit() which might be called after ht_deinit(),
 * however, it's highly not recommended and should be avoided
 * when possible.
 */
HT_API void ht_deinit(void);

HT_DECLS_END

#endif /* HAWKTRACER_INIT_H */
