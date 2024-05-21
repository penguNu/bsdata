#ifndef BSDATA_H_INCLUDED
#define BSDATA_H_INCLUDED

#include "shared.h"
#include "pubfuncs.h"

/* DATA TYPE GENERATION FLAGS */
/* These flags correspond to remembering which data type we're trying to generate.
 */
#define TYPE_INT        (1 << 0)
#define TYPE_FLOAT      (1 << 1)
#define TYPE_CHAR       (1 << 2)
#define TYPE_STRING     (1 << 3)

/* INT DATA TYPE FLAGS */
/* These flags correspond to details for int generation, including whether a lower
 * bound exists, whether an upper bound exists, etc.
 */
#define INT_BOUND_UNBOUNDED     (1 << 0)
#define INT_BOUND_LOWER         (1 << 1)
#define INT_BOUND_UPPER         (1 << 2)

/* DEFAULTS */
#define DEFAULT_DATA_TYPE       TYPE_INT
#define DEFAULT_LIST_LENGTH     10

#endif
