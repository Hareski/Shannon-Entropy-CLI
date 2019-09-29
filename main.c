#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

// Print usage of executable
void usage() {
    printf("Shannon Entropy for a distribution with given probabilities\n"
           "   Usage: log_base probability_1 probability_2 [...]\n");
    exit(EXIT_SUCCESS);
}

// Print error and quit if errno is set
void checkErrno(char *funcName) {
    if (errno != 0) {
        perror(funcName);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    // Initialisation
    if (argc < 3) usage();
    long double base = strtold(argv[1], NULL);
    checkErrno("log_base to long double");
    long double entropySum = 0;
    long double probabilitySum = 0;

    // Sum of logarithm times probability
    for (int i = 2; i < argc; ++i) {
        long double val = strtold(argv[i], NULL);
        entropySum += val * (logl(val) / logl(base));
        probabilitySum += val;
        checkErrno("probability to long double");
    }

    // Output
    if (probabilitySum != 1) {
        printf("Warning: probability sum is %Lf\n", probabilitySum);
    }
    printf("H(x)=%Lf\n", -entropySum);
    return 0;
}