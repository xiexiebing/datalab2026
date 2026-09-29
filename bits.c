/* WARNING: Do not include any other libraries here,
 * otherwise you will get an error while running test.py
 * You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 *
 * Using printf will interfere with our script capturing the execution results.
 * At this point, you can only test correctness with ./btest.
 * After confirming everything is correct in ./btest, remove the printf
 * and run the complete tests with test.py.
 */

 /*
 * bitAnd - x & y using only ~ and |
 * Example: bitAnd(4, 5) = 4
 * Legal ops: ~ |
 * Max ops: 7
 * Difficulty: 1
 */
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

/*
 * bitXor - x ^ y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 7
 *   Difficulty: 1
 */
int bitXor(int x, int y) {
    return ~(x & y) & ~(~x & ~y);
}

/*
 * samesign - Determines if two integers have the same sign.
 *   0 is not positive, nor negative
 *   Example: samesign(0, 1) = 0, samesign(0, 0) = 1
 *            samesign(-4, -5) = 1, samesign(-4, 5) = 0
 *   Legal ops: >> << ! ^ && if else &
 *   Max ops: 12
 *   Difficulty: 2
 *
 * Parameters:
 *   x - The first integer.
 *   y - The second integer.
 *
 * Returns:
 *   1 if x and y have the same sign , 0 otherwise.
 */
int samesign(int x, int y) {
    if (!x)
        return !y;
    if (!y)
        return 0;
    return !((x >> 31) ^ (y >> 31));
}

/*
 * logtwo - Calculate the base-2 logarithm of a positive integer using bit
 *   shifting. (Think about bitCount)
 *   Note: You may assume that v > 0
 *   Example: logtwo(32) = 5
 *   Legal ops: > < >> << |
 *   Max ops: 25
 *   Difficulty: 4
 */
int logtwo(int v) {
    int result = 0;
    int shift;

    shift = (v > 0xFFFF) << 4;
    v >>= shift;
    result |= shift;

    shift = (v > 0xFF) << 3;
    v >>= shift;
    result |= shift;

    shift = (v > 0xF) << 2;
    v >>= shift;
    result |= shift;

    shift = (v > 0x3) << 1;
    v >>= shift;
    result |= shift;

    result |= v > 1;
    return result;
}

/*
 *  byteSwap - swaps the nth byte and the mth byte
 *    Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *              byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *    Note: You may assume that 0 <= n <= 3, 0 <= m <= 3
 *    Legal ops: ! ~ & ^ | + << >>
 *    Max ops: 17
 *    Difficulty: 2
 */
int byteSwap(int x, int n, int m) {
    int nshift = n << 3;
    int mshift = m << 3;
    int nbyte = (x >> nshift) & 0xFF;
    int mbyte = (x >> mshift) & 0xFF;
    int difference = nbyte ^ mbyte;

    return x ^ ((difference & 0xFFu) << nshift) ^
           ((difference & 0xFFu) << mshift);
}

/*
 * reverse - Reverse the bit order of a 32-bit unsigned integer.
 *   Example: reverse(0xFFFF0000) = 0x0000FFFF reverse(0x80000000)=0x1 reverse(0xA0000000)=0x5
 *   Note: You may assume that an unsigned integer is 32 bits long.
 *   Legal ops: << | & - + >> for while ! ~ (You can define unsigned in this function)
 *   Max ops: 30
 *   Difficulty: 3
 */
unsigned reverse(unsigned v) {
    v = ((v >> 1) & 0x55555555) |
        ((v & 0x55555555) << 1);

    v = ((v >> 2) & 0x33333333) |
        ((v & 0x33333333) << 2);

    v = ((v >> 4) & 0x0F0F0F0F) |
        ((v & 0x0F0F0F0F) << 4);

    v = ((v >> 8) & 0x00FF00FF) |
        ((v & 0x00FF00FF) << 8);

    return (v >> 16) | (v << 16);
}

/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Note: You can assume that 0 <= n <= 31
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Difficulty: 3
 */
int logicalShift(int x, int n) {
    int mask = ((0x7FFFFFFFu >> n) << 1) | 1;
    return (x >> n) & mask;
}

/*
 * leftBitCount - returns count of number of consective 1's in left-hand (most) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12,
 *             leftBitCount(0xFE00FF0F) = 7
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Difficulty: 4
 */
int leftBitCount(int x) {
    int b16, b8, b4, b2, b1, b0;

    x = ~x;

    b16 = !(x >> 16) << 4;
    x = (x | 0u) << b16;

    b8 = !(x >> 24) << 3;
    x = (x | 0u) << b8;

    b4 = !(x >> 28) << 2;
    x = (x | 0u) << b4;

    b2 = !(x >> 30) << 1;
    x = (x | 0u) << b2;

    b1 = !(x >> 31);
    x = (x | 0u) << b1;

    b0 = !(x >> 31);

    return b16 + b8 + b4 + b2 + b1 + b0;
}

/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but it is to be interpreted as
 *   the bit-level representation of a single-precision floating point values.
 *   Legal ops: if else while for & | ~ + - >> << < > ! ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned float_i2f(int x) {
    unsigned sign;
    unsigned magnitude;
    unsigned mantissa;
    unsigned remainder;
    unsigned halfway;
    unsigned round;
    int highest = 31;
    int extra;

    if (x == 0)
        return 0;

    sign = x & 0x80000000u;
    magnitude = x;

    if (sign)
        magnitude = ~magnitude + 1;

    while (!(magnitude >> highest))
        highest = highest - 1;

    if (highest > 23) {
        extra = highest - 23;
        mantissa = magnitude >> extra;

        remainder = magnitude & ((1u << extra) - 1);
        halfway = 1u << (extra - 1);
        round = 0;

        if (remainder > halfway)
            round = 1;
        else if (remainder == halfway)
            round = mantissa & 1;

        mantissa = mantissa + round;
    } else {
        mantissa = magnitude << (23 - highest);
    }

    return sign | (((highest + 126) << 23) + mantissa);
}

/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: & >> << | if > < >= <= ! ~ else + ==
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatScale2(unsigned uf) {
    unsigned exponent = uf & 0x7F800000;

    if (exponent == 0x7F800000)
        return uf;

    if (!exponent)
        return (uf & 0x80000000) |
               ((uf & 0x7FFFFFFF) << 1);

    if (exponent == 0x7F000000)
        return (uf & 0x80000000) | 0x7F800000;

    return uf + 0x00800000;
}

/*
 * float64_f2i - Convert a 64-bit IEEE 754 floating-point number to a 32-bit signed integer.
 *   The conversion rounds towards zero.
 *   Note: Assumes IEEE 754 representation and standard two's complement integer format.
 *   Parameters:
 *     uf1 - The lower 32 bits of the 64-bit floating-point number.
 *     uf2 - The higher 32 bits of the 64-bit floating-point number.
 *   Returns:
 *     The converted integer value, or 0x80000000 on overflow, or 0 on underflow.
 *   Legal ops: >> << | & ~ ! + - > < >= <= if else
 *   Max ops: 60
 *   Difficulty: 3
 */
int float64_f2i(unsigned uf1, unsigned uf2) {
    unsigned sign = uf2 >> 31;
    unsigned exponent = (uf2 >> 20) & 0x7FF;
    unsigned value;

    if (exponent < 1023)
        return 0;

    if (exponent > 1054)
        return 0x80000000u;

    value = 0x80000000u |
            ((uf2 & 0xFFFFF) << 11) |
            (uf1 >> 21);

    value = value >> (1054 - exponent);

    if (sign) {
        if (value > 0x80000000u)
            return 0x80000000u;
        return -value;
    }

    if (value > 0x7FFFFFFF)
        return 0x80000000u;

    return value;
}

/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: < > <= >= << >> + - & | ~ ! if else &&
 *   Max ops: 30
 *   Difficulty: 4
 */
unsigned floatPower2(int x) {
    if (x < -149)
        return 0;

    if (x < -126)
        return 1u << (x + 149);

    if (x > 127)
        return 0x7F800000;

    return (x + 127) << 23;
}
