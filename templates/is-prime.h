#pragma once

/*
 * Template metaprogramming style isPrime method.
 */
template<unsigned p, unsigned d> // p: number to check, d: current divisor
struct DoIsPrime {
    static constexpr bool value = (p%d != 0) && DoIsPrime<p,d-1>::value;
};
template<unsigned p> // end recursion if divisor is 2
struct DoIsPrime<p,2> {
    static constexpr bool value = (p%2 != 0);
};
template<unsigned p> // primary template
struct IsPrime {
// start recursion with divisor from p/2:
    static constexpr bool value = DoIsPrime<p,p/2>::value;
};
// special cases (to avoid endless recursion with template instantiation):
template<>
struct IsPrime<0> { static constexpr bool value = false; };
template<>
struct IsPrime<1> { static constexpr bool value = false; };
template<>
struct IsPrime<2> { static constexpr bool value = true; };
template<>
struct IsPrime<3> { static constexpr bool value = true; };

/*
 * In C++11 constexpr functions were introduced with stringent limitations (e.g., each
constexpr function definition was essentially limited to consist of a return statement)
 */
constexpr bool
doIsPrime11 (unsigned p, unsigned d) // p: number to check, d: current divisor
{
    return d!=2 ? (p%d!=0) && doIsPrime11(p,d-1) // check this and smaller divisors
                : (p%2!=0); // end recursion if divisor is 2
}
constexpr bool isPrime11 (unsigned p)
{
    return p < 4 ? !(p<2) // handle special cases
                 : doIsPrime11(p,p/2); // start recursion with divisor from p/2
}


/*
 * With C++14, constexpr functions can make use of most control structures available in general
C++ code. So, instead of writing unwieldy template code or somewhat arcane one-liners, we can
now just use a plain for loop:
 */
constexpr bool isPrime14(unsigned int p)
{
    for (unsigned int d=2; d<=p/2; ++d) {
        if (p % d == 0) {
            return false; // found divisor without remainder
        }
    }
    return p > 1; // no divisor without remainder found
}