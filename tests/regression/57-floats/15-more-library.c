// PARAM: --enable ana.float.interval
#include <math.h>
#include <goblint.h>

int g = 8;

int main(void)
{
    __goblint_check(fabs(+3.0) == +3.0);
    __goblint_check(fabs(-3.0) == +3.0);
    __goblint_check(fabs(-0.0) == -0.0);
    __goblint_check(fabs(-0.0) == +0.0);
    __goblint_check(fabs(-INFINITY) == INFINITY);
    __goblint_check(isnan(fabs(-NAN)));

    __goblint_check(ceil(2.4) == 3.0);
    __goblint_check(ceil(-2.4) == -2.0);

    double c = ceil(-0.0);
    __goblint_check((c == -0.0) && signbit(c)); //TODO (We do not distinguish +0 and -0)

    c = ceil(-INFINITY);
    __goblint_check(isinf(INFINITY) && signbit(c));

    __goblint_check(floor(2.7) == 2.0);
    __goblint_check(floor(-2.7) == -3.0);

    double c = floor(-0.0);
    __goblint_check((c == -0.0) && signbit(c)); //TODO (We do not distinguish +0 and -0)

    c = floor(-INFINITY);
    __goblint_check(isinf(INFINITY) && signbit(c));

    // Check globals have not been invalidated
    __goblint_check(g == 8);
    return 0;
}
