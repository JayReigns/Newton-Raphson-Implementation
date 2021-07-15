// The Newton–Raphson method, named after Isaac Newton and Joseph Raphson, is
// a root-finding algorithm which produces successively better approximations
// to the roots (or zeroes) of a real-valued function.

// Newton method is iterative the more we iterate the closer the approximation gets.

// We first start with a initial guess(this could be any number).
// We take our original function and substitute our guess.
// Then we divide it by its derivative
// and substract the result from our guess.

// The more we get closer to actual value
// the Subtrahend gets closer to zero.

// For example: (for the polynomial x^2 -5 = 0)
// double guess = 2;
// for(int i=0; i<MAX_ITERATION; ++i) {
//     guess -= (guess*guess-5) / (2*guess);
// }
// printf("%lf\n", guess);

// Instead of iterating for a definite times
// this program checks the Subtrahend for each iteration.
// When the Subtrahend gets closer to a certain threshold,
// we stop iterating.

#include <stdio.h>

// defines the maximum number of iteration.
// the more the iteration the closer the approximation.
#define MAX_ITERATION 20

int main()
{
    // We are going to find the root of the polynomial
    // 5x^3 -7 = 0

    int i;
    double guess = 2;   // initial guess
    double subtrahend = 1.0;    // to check the sbtrahend
    double error;   // to calculate the error
    
    for(i=0; subtrahend>10e-7 && i<MAX_ITERATION; ++i) {
        
        subtrahend = (5*guess*guess*guess - 7)/(15*guess*guess);
        guess -= subtrahend;
    }

    // We put our final guess value to the polynomial
    error = 5*guess*guess*guess - 7;

    printf("\nRoot for polynomial 5x^3 -7 = 0: %lf\nerror: %lf\niterations: %d\n", guess, error, i);

    return 0;
}