/*
https://github.com/kimwalisch/primecount

Interesting subtask. If there was a hypothetical theoretical Project Leonhard Euler 861 task where the function was multiplicative on a simple prime exponent function and thus there could be at most 4 primes, and at most 1 prime > 10^6, in the factorisation then one could immediately Sieve and rapidly prune through much less than ~[1000 choose 3] subcases on the 1 then 2 then 3 then 3 minimal prime factors inducing the auxiliary >= maxnitriplet call maybe saving relevant calls for later sorting and reducing the task in to something like an optimised:

Sum Blah Blah PrimeCount[10^12/AAA]-PrimeCount[10^12/BBB]

Which could then be quite optimised in implementation as there are at most 10^6 relevant values beneath 10^6 and at most 10^6 relevant values between 10^6 and 10^12 e.g. is accepted with this runtime most likely for Gold Medal.
*/