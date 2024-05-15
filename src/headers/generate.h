#ifndef GENERATE_H_INCLUDED
#define GENERATE_H_INCLUDED

int *generateUnboundedNumberOfIntegers(int numberOfIntegers);
int *generateUpperBoundedNumberOfIntegers(int numberOfIntegers, int bound);
int *generateLowerBoundedNumberOfIntegers(int numberOfIntegers, int bound);
int *generateBoundedNumberOfIntegers(int numberOfIntegers, int lowerBound, int upperBound);

#endif
