/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically and a negative shift value results in zero.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES, FOLLOW THE DIRECTIONS in README.md
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * bitOr - x|y using only ~ and & 
 *   Example: bitOr(6, 5) = 7
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitOr(int x, int y) {
  return ~(~x & ~y);
}
/*
 * isZero - returns 1 if x == 0, and 0 otherwise 
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
  return !x;
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  return ~(1 << 31); // ~(1000 0000 0000 0000 0000 0000 0000 0000) = 0111 1111 1111 1111 1111 1111 1111 1111 = 0x7FFFFFFF
}
/* 
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) {
    int mask = 0xAA; //in binary = 1010 1010
    // go through each byte to find 1 in an odd-numbered bit
    int result = (x & mask) + ((x >> 8) & mask) + ((x >> 16) & mask) + ((x >> 24) & mask); 
    return !!result; // convert non-zero to 1 and 0 to 0
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int shift = 32 + (~n+1); //32 - n
  return !(x^((x<<shift)>>shift)); 
  // shift the values in n-bits to the left, then back to the LSB (to allow comparison with the original x). 
  // If x does not fit in n-bits, then it will change. If it does fit, then it stays the same.
  // use x xor to compare with possibly changed value. If it didn't change, then the result is zero. Else, it will return 1.
  // finally, apply ! to return 0 if the value does not fit (x ^ ... = 1) or return 1 if it stayed the same.
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  int x_neg = ~x + 1; // negative x
  return (x & x_neg); // will be 0&1 (or vice versa) except for the last 1 (which will be 1&1) 
}
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  return !(((0x39 + (~x + 1)) >> 31) | (((x + (~0x30 + 1)) >> 31)));
  // (0x39 - x) and (x - 0x30) will test if x is inside the required range. If it is not, then one of these will return a negative number (sign bit = 1)
  // If x is inside the range, both of the equations will return a positive number or zero (sign bit = 0)
  // The sign bit is shifted to the LSB for comparison purposes
  // Using the or operator, 1 will be returned if x is outside the range and 0 if inside.
  // Finally, ! will switch the final output to align with the function's return requirements.
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int mask = 1 << 31; // mask for sign bit
  int xMask = mask & x; // x sign bit
  int yMask = mask & y; // y sign bit
  int signCompare = ((xMask ^ yMask) >> 31) & 1; // 1 if different sign (risk of overflow), 0 if same sign

  int diff = y + (~x+1); // y-x
  int diffSign = (diff >> 31) & 1; // shift sign bit

  return ((signCompare & (xMask >> 31)) | !(diffSign | signCompare));
  // 4 cases that should return 1: x = y, +x < +y, -x < +y, -x < -y
  // if x and y signs are different and x is negative, then y must be greater -> return 1 (case 3)
  // if y-x is positive (or zero) and x and y are the same sign, y is greater (distribute ! to use 1 less operation) -> return 1 (case 1, 2, 4)
}
/* 
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
  int mask = 0xFF; // 00..00 1111 1111

  // extract each byte into seperate variables using the mask
  int b1 = x & mask;
  int b2 = (x >> 8) & mask;
  int b3 = (x >> 16) & mask;
  int b4 = (x >> 24) & mask;

  // put back together in reverse order
  return(b4 + (b3 << 8) + (b2 << 16) + (b1 << 24));
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int mask = 0x1 | (0x1 << 8) | (0x1 << 16) | (0x1 << 24); // mask that has 1 at the end of each byte
  int count = (x & mask) + ((x>>1) & mask) + ((x>>2) & mask) + ((x>>3) & mask) + ((x>>4) & mask) + ((x>>5) & mask) + ((x>>6) & mask) + ((x>>7) & mask);
  // go through each bit in every byte (by checking the last one then shifting) and count how many 1's are there
  int mask2 = 0xFF; // 1111 1111
  return ((count & mask2) + ((count >> 8) & mask2) + ((count >> 16) & mask2) + ((count >> 24) & mask2));
  // add the # of 1's in each byte together

}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  return (( ((x | (~x+1)) >> 31) & 1) ^ 1); 
  // check if x or -x has 1 in its sign place (thus x != 0), then arithmetically shift sign place to LSB
  // then & with 1 to make bit mask to leave only LSB (everything else is 0).
  // xor with 1 to return 0 if x != 0 and return 1 if x == 0
}
/*
 * trueFiveEighths - multiplies by 5/8 rounding toward 0,
 *  avoiding errors due to overflow
 *  Examples: trueFiveEighths(11) = 6
 *            trueFiveEighths(-9) = -5
 *            trueFiveEighths(0x30000000) = 0x1E000000 (no overflow)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 4
 */
int trueFiveEighths(int x)
{
    int q = x >> 3; // divide x by 8 
    int r = x & 7; // x % 8
    int q_ans = (q << 2) + q; // multiply q by 5
    int r5 = (r << 2) + r; // multiply remainder by 5
    // for rounding purposes, add 7 to remainder if x is negative and 0 if positive, then divide by 8
    int r_ans = (r5 + ((x >> 31) & 7)) >> 3;
    return (q_ans + r_ans); // add final q and r together
    
}
/*
 * Extra credit
 */
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  int expMask = 0x0FF << 23; // a mask for the exponent bits
  int fractional = 0x7FFFFF & uf; // use a mask to store fractional bits

  //check for NaN. If all exponent bits are one, that is out of normal exponent range (special case, +128) 
  // So, if the fraction is not zero then it is NaN (if they are all 0, then it's infinity whose sign can be flipped)
  if(((expMask & uf) == expMask) && fractional){
    return uf;
  }

  return uf ^ (1 << 31); // otherwise, use mask to flip the sign bit
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  
  int exp = (uf >> 23) & 0xFF; // move exponent bits is LSBs and make anything else (sign bit) zero

  if(!exp) // if all exponent bits are zero (out of range of normal acting exponents, special case -127)
  {
    // preserve the 0.fraction case by adding sign bit to 2*uf
    // without that, 0 would turn into 1.fraction if multiplying uf by 2 by adding 1 to the exponent
    return (uf & 0x80000000) + (uf << 1); 
  }
  // if exponent bits are 1111 1110, then on the brink of being out of normal exponent range in positive direction (entering all 1's special case +128)
  if(!(exp ^ 0xFE))
  {
    return (uf & 0x80000000) + (0xFF << 23); // returns infinity
    // isolate sign bit (so + or - infinity is returned) then add all 1's for exponent bits
    // infinity = sign bit + all 1's for exp bits + all 0's for fractional bits
    // input number is not NaN, so it should go to infinity
  }
  if(exp ^ 0xFF) // regular case where exponent bits contain at least one 0 (wont enter if all 0's b/c of first if-statement)
  {
    return uf + (1 << 23); // multiply by 2 by adding 1 to the exponent bits (2^exp)
  }
  return uf; // if argument is infinity or NaN, return it
}
