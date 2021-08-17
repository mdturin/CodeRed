/** ax + by = c
    finding any x, y that state the equ.
    if there is a solution (c%gcd(a,b) == 0)
        as, ax0 + by0 = gcd(a,b);
        so, c = gcd(a,b) * k;
            k = c / gcd(a,b);
        when we find x0, y0,
            x = x0 * k; y = y0 * k;
*/


/**
    Geting all solutions;

    If there is a solution,
    then there exist infinite solutions
        as if, ax + by = c;

        lets, add x with b/g & substract y with a/g, so,
            a(x+(b/g)) + b(y-(a/g)) = c;
            ax + ab/g + by - ab/g = c
            ax + by + ab/g - ab/g = c;
            ax + by = c;

        or, adding b/g with x and substracting a/g with y
            gives us the same result

            a(x-(b/g)) + b(y+(a/g)) = c;
            ax - ab/g + by + ab/g = c
            ax + by + ab/g - ab/g = c;
            ax + by = c;
*/

/**
    Find the soluton with minimum (x+y)
    as,
        x' = x + k * b/g;
        y' = y - k * a/g;
    so,
        x' + y' = x + k * b/g + y - k * a/g;
                = x + y + k * (b-a) / g
    so if,
        a < b, k must be smallest &
        a > b, k must be largest & also
        a = b, all solution will have the same sum x+y
*/