#ifndef BSDATA_H_INCLUDED
#define BSDATA_H_INCLUDED

/* generation */
extern void initializeGenerator();
extern int *generateUnboundedNumberOfIntegers(int numberOfIntegers);
extern int *generateUpperBoundedNumberOfIntegers(int numberOfIntegers, int bound);
extern int *generateLowerBoundedNumberOfIntegers(int numberOfIntegers, int bound);
extern int *generateBoundedNumberOfIntegers(int numberOfIntegers, int lowerBound, int upperBound);

/* output */
extern void printIntegerList(int *list, int length);

#endif
