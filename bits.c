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
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return (~(x & y)) & (~((~x) & (~y)));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int a = x + 1;               // `a` нь `x + 1`
  int mask = !a;               // Хэрэв `a` нь 0 бол `mask` нь 1 болно (ингэснээр `x` нь -1 байгааг шалгана)

  x += a;                      // `x` нь `x + a`, энэ нь 0x7FFFFFFE эсвэл -1 болж хувирна

  return !(~x | mask);         // `x` нь 0x7FFFFFFE эсэхийг шалгана, `mask` нь 1 биш үед
}

/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int mask = (0xAA << 8) + 0xAA; // 0xAAAA (16 битийн маск: 1010101010101010)
  mask = (mask << 16) + mask;    // 0xAAAAAAAA (32 битийн маск: 10101010101010101010101010101010)

  // `x`-ийн сондгой битүүд нь 1 байвал `1` буцаана, эс бөгөөс `0`
  return !((x & mask) ^ mask);
}

/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
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
   int lowerBound = 0x30;
   int upperBound = 0x3a;
   return !((x + (~lowerBound + 1)) >> 31) & (x + (~upperBound + 1)) >> 31; 
}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // `mask` нь x үнэн бол 0xFFFFFFFF, эсвэл 0x0 болно
  int mask = ~(!x) + 1;

  // `y` эсвэл `z` утгыг mask-аар сонгоно
  return (y & ~mask) + (z & mask);
}

/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int signX = x >> 31; // x-ийн тэмдэгт бит (0: эерэг, 1: сөрөг)
  int signY = y >> 31; // y-ийн тэмдэгт бит (0: эерэг, 1: сөрөг)

  // `flag1`: y эерэг ба x сөрөг тохиолдолд (signY = 0, signX = 1), x нь үргэлж бага байна
  int flag1 = !signY & signX;

  // `flag2`: x болон y тэнцүү үед
  int flag2 = !(x ^ y);

  // `flag3`: x болон y нь ижил тэмдэгтэй үед, x <= y эсэхийг шалгах
  int flag3 = !(signX ^ signY) & (((x + (~y + 1)) >> 31) & 1);

  // flag1, flag2 эсвэл flag3-ийн аль нэг нь үнэн байвал `x <= y` гэж үзнэ
  return flag1 | flag2 | flag3;
}

//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int mask = ~x & (~(~x + 1));  // x болон түүний хоёртын нэмэлтийн үгүйсгэлүүдийг ашиглан бүх битийг үгүйсгэнэ
  return (mask >> 31) & 1;  // Хамгийн зүүн талын битийг авч, 1 эсвэл 0-г буцаана
}

/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int isZeroOrNegone = !x | (!(x + 1));  // x нь 0 эсвэл -1 бол энэ утга 1 болно
  int firstShift = 0;
  int secondShift = 0; 
  int thirdShift = 0;
  int fourthShift = 0;
  int fifthShift = 0;
  int total = 0;

  // x-г түүний тэмдэгт битээр оновчтой болгох
  x = x >> 31 ^ x;

  /*
   * Давталт ба хуваах арга
   * Хамгийн өндөр битийн 1-ийг олох
   */
  firstShift = !(!(x >> 16)) << 4;
  x >>= firstShift;

  secondShift = !(!(x >> 8)) << 3;
  x >>= secondShift;

  thirdShift = !(!(x >> 4)) << 2;
  x >>= thirdShift;

  fourthShift = !(!(x >> 2)) << 1;
  x >>= fourthShift;

  fifthShift = 1;
  x >>= fifthShift;

  // Хамгийн өндөр байрлалын 1-ийн нийт битийн тоог олох
  total = firstShift + secondShift + thirdShift + fourthShift + fifthShift + x + 1;

  // 0 эсвэл -1 тохиолдолд 1 буцаана, эс бөгөөс нийт битийн тоо
  return (isZeroOrNegone & (~((~(!isZeroOrNegone)) + 1))) + (total & ((~(!isZeroOrNegone)) + 1));
}

//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int sign = uf & 0x80000000;        // Тэмдэгт бит (31-р бит)
  int exp = (uf & 0x7F800000) >> 23; // Экспонент (8 бит)
  int frac = uf & 0x007FFFFF;         // Бутархай хэсэг (23 бит)

  int final_exp = 0;

  // Хэрэв экспонент нь 0xFF байвал, энэ нь NaN эсвэл хязгааргүй утгыг илэрхийлнэ, иймээс эхний утгыг буцаана
  if (exp == 0xFF) {
    return uf;
  }

  // Хэрэв өгөгдөл нь 0 бол (экспонент болон бутархай хэсэг нь 0), эхний утгыг буцаана
  if ((uf & 0x7FFFFFFF) == 0) {
    return uf;
  }

  // Хэрэв экспонент нь 0 бол denormalized (жижиг тоо), бутархай хэсгийг 2 дахин өсгөнө
  if (!exp) {
    // Бутархай хэсгийг зүүн тал руу шилжүүлж, үр дүнд нь тэмдэгт битийг нэмнэ
    if (uf << 9 >> 31) {
      return (uf << 9 >> 8) + sign;
    } else {
      return (uf << 1) + sign;
    }
  } else {
    // Экспонентыг 1-ээр нэмэгдүүлж, шинэ утгыг тооцоолно
    final_exp = (exp + 1) << 23;
    // Хэрэв экспонент нь хязгааргүйг илэрхийлэх болсон бол бутархай хэсгийг 0 болгоно
    if (final_exp == 0x7F800000) {
      frac = 0;
    }
    // Экспонент, бутархай хэсэг, тэмдэгт битийг нийлүүлж үр дүнг буцаана
    return final_exp + frac + sign;
  }
}

/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned sign = uf >> 31;       // Тэмдэгт бит (1 бол сөрөг, 0 бол эерэг)
  unsigned exp = (uf >> 23) & 0xFF;  // Экспонент (8 бит)
  unsigned frac = (uf & 0x7FFFFF);   // Бутархай хэсэг (23 бит)
  unsigned bias = 0x7F;           // Экспонентийн bias утга (127)
  unsigned res = frac;

  // Хэрэв экспонент нь 0xFF байвал, утга нь NaN эсвэл хязгааргүй байна, иймээс 0x80000000u-г буцаана
  if (exp == 0xFF) {
    return 0x80000000u;
  }

  // Хэрэв экспонент нь bias-аас бага байвал бүхэл тоо утгагүй (0-д ойрхон), иймээс 0-г буцаана
  if (exp < bias) {
    return 0x0;
  }

  // Экспонентийн bias-ыг хасаж бодит экспонентыг олно
  exp -= bias;

  // Хэрэв экспонент нь 31 буюу түүнээс их байвал бүхэл тооны мужид багтахгүй, иймээс 0x80000000u-г буцаана
  if (exp >= 31) {
    return 0x80000000u;
  }

  // Экспонент 23-аас их байвал бутархай хэсгийг зүүн тал руу шилжүүлнэ
  if (exp > 22) {
    res = frac << (exp - 23);
  } else {
    // Экспонент 23-аас бага байвал бутархай хэсгийг баруун тал руу шилжүүлнэ
    res = frac >> (23 - exp);
  }

  // Бутархай хэсэг дээр 1-ийг нэмнэ (энэ нь хөвөгч цэгийн тооны 1.XXXX форматыг илэрхийлэхтэй холбоотой)
  res += 1 << exp;

  // Хэрэв тэмдэгт бит нь 1 байвал үр дүнг сөрөг болгож буцаана
  if (sign) {
    res = -res;
  }

  return res;
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
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    int exp;
    // Хэрэв x нь -126-аас бага байвал 0-г буцаана
    if (x < -126) {
        return 0;
    }
    // Хэрэв x нь 127-оос их байвал infinity илэрхийлэх 0x7F800000-г буцаана
    if (x > 127) {
        return 0x7F800000;
    }
    // 23 битээр зүүн талд шилжүүлнэ
    exp = x + 127;
    return exp << 23;
}
