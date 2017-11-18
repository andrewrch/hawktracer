#ifndef HAWKTRACER_MONOTONIC_CLOCK_H
#define HAWKTRACER_MONOTONIC_CLOCK_H

#include <hawktracer/base_types.h>
#include <hawktracer/macros.h>

HT_DECLS_BEGIN

HT_TimestampNs ht_monotonic_clock_get_timestamp();

HT_DECLS_END

#endif /* HAWKTRACER_MONOTONIC_CLOCK_H */
