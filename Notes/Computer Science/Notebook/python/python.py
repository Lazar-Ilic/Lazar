import math
from decimal import *
getcontext().prec=50

# Recall that there can exist floating point issues etc. etc. and that PARI GP is probably much faster for certain sorts of computations but much trickier to deal with overall unless executing simple C-style nested for loops and simple mathematical operations with simple vectors and the /p 10000 call or whatever.

answer=Decimal(12481359318529385298529485489564985624958264895+24589648562983561389513958631958+24582359823623895623958)
for a in range(blah):
	answer+=b.exp()
print(answer%136101521)

# Yadda yadda yadda blih blah native implementations on underlying mathematical functions.

# https://docs.python.org/3/library/decimal.html

b.sqrt()
b.log10()
b.ln()

# Blah blah blah... :

adjusted()
Return the adjusted exponent after shifting out the coefficient’s rightmost digits until only the lead digit remains: Decimal('321e+5').adjusted() returns seven. Used for determining the position of the most significant digit with respect to the decimal point.

as_integer_ratio()
Return a pair (n, d) of integers that represent the given Decimal instance as a fraction, in lowest terms and with a positive denominator:

>>>
Decimal('-3.14').as_integer_ratio()
(-157, 50)
The conversion is exact. Raise OverflowError on infinities and ValueError on NaNs.

New in version 3.6.

as_tuple()
Return a named tuple representation of the number: DecimalTuple(sign, digits, exponent).

canonical()
Return the canonical encoding of the argument. Currently, the encoding of a Decimal instance is always canonical, so this operation returns its argument unchanged.

compare(other, context=None)
Compare the values of two Decimal instances. compare() returns a Decimal instance, and if either operand is a NaN then the result is a NaN:

a or b is a NaN  ==> Decimal('NaN')
a < b            ==> Decimal('-1')
a == b           ==> Decimal('0')
a > b            ==> Decimal('1')
compare_signal(other, context=None)
This operation is identical to the compare() method, except that all NaNs signal. That is, if neither operand is a signaling NaN then any quiet NaN operand is treated as though it were a signaling NaN.

compare_total(other, context=None)
Compare two operands using their abstract representation rather than their numerical value. Similar to the compare() method, but the result gives a total ordering on Decimal instances. Two Decimal instances with the same numeric value but different representations compare unequal in this ordering:

>>>
Decimal('12.0').compare_total(Decimal('12'))
Decimal('-1')
Quiet and signaling NaNs are also included in the total ordering. The result of this function is Decimal('0') if both operands have the same representation, Decimal('-1') if the first operand is lower in the total order than the second, and Decimal('1') if the first operand is higher in the total order than the second operand. See the specification for details of the total order.

This operation is unaffected by context and is quiet: no flags are changed and no rounding is performed. As an exception, the C version may raise InvalidOperation if the second operand cannot be converted exactly.

compare_total_mag(other, context=None)
Compare two operands using their abstract representation rather than their value as in compare_total(), but ignoring the sign of each operand. x.compare_total_mag(y) is equivalent to x.copy_abs().compare_total(y.copy_abs()).

This operation is unaffected by context and is quiet: no flags are changed and no rounding is performed. As an exception, the C version may raise InvalidOperation if the second operand cannot be converted exactly.

conjugate()
Just returns self, this method is only to comply with the Decimal Specification.

copy_abs()
Return the absolute value of the argument. This operation is unaffected by the context and is quiet: no flags are changed and no rounding is performed.

copy_negate()
Return the negation of the argument. This operation is unaffected by the context and is quiet: no flags are changed and no rounding is performed.

copy_sign(other, context=None)
Return a copy of the first operand with the sign set to be the same as the sign of the second operand. For example:

>>>
Decimal('2.3').copy_sign(Decimal('-1.5'))
Decimal('-2.3')
This operation is unaffected by context and is quiet: no flags are changed and no rounding is performed. As an exception, the C version may raise InvalidOperation if the second operand cannot be converted exactly.

exp(context=None)
Return the value of the (natural) exponential function e**x at the given number. The result is correctly rounded using the ROUND_HALF_EVEN rounding mode.

>>>
Decimal(1).exp()
Decimal('2.718281828459045235360287471')
Decimal(321).exp()
Decimal('2.561702493119680037517373933E+139')
classmethod from_float(f)
Alternative constructor that only accepts instances of float or int.

Note Decimal.from_float(0.1) is not the same as Decimal('0.1'). Since 0.1 is not exactly representable in binary floating point, the value is stored as the nearest representable value which is 0x1.999999999999ap-4. That equivalent value in decimal is 0.1000000000000000055511151231257827021181583404541015625.

Note From Python 3.2 onwards, a Decimal instance can also be constructed directly from a float.
>>>
Decimal.from_float(0.1)
Decimal('0.1000000000000000055511151231257827021181583404541015625')
Decimal.from_float(float('nan'))
Decimal('NaN')
Decimal.from_float(float('inf'))
Decimal('Infinity')
Decimal.from_float(float('-inf'))
Decimal('-Infinity')
New in version 3.1.

fma(other, third, context=None)
Fused multiply-add. Return self*other+third with no rounding of the intermediate product self*other.

>>>
Decimal(2).fma(3, 5)
Decimal('11')
is_canonical()
Return True if the argument is canonical and False otherwise. Currently, a Decimal instance is always canonical, so this operation always returns True.

is_finite()
Return True if the argument is a finite number, and False if the argument is an infinity or a NaN.

is_infinite()
Return True if the argument is either positive or negative infinity and False otherwise.

is_nan()
Return True if the argument is a (quiet or signaling) NaN and False otherwise.

is_normal(context=None)
Return True if the argument is a normal finite number. Return False if the argument is zero, subnormal, infinite or a NaN.

is_qnan()
Return True if the argument is a quiet NaN, and False otherwise.

is_signed()
Return True if the argument has a negative sign and False otherwise. Note that zeros and NaNs can both carry signs.

is_snan()
Return True if the argument is a signaling NaN and False otherwise.

is_subnormal(context=None)
Return True if the argument is subnormal, and False otherwise.

is_zero()
Return True if the argument is a (positive or negative) zero and False otherwise.

ln(context=None)
Return the natural (base e) logarithm of the operand. The result is correctly rounded using the ROUND_HALF_EVEN rounding mode.

log10(context=None)
Return the base ten logarithm of the operand. The result is correctly rounded using the ROUND_HALF_EVEN rounding mode.

logb(context=None)
For a nonzero number, return the adjusted exponent of its operand as a Decimal instance. If the operand is a zero then Decimal('-Infinity') is returned and the DivisionByZero flag is raised. If the operand is an infinity then Decimal('Infinity') is returned.

logical_and(other, context=None)
logical_and() is a logical operation which takes two logical operands (see Logical operands). The result is the digit-wise and of the two operands.

logical_invert(context=None)
logical_invert() is a logical operation. The result is the digit-wise inversion of the operand.

logical_or(other, context=None)
logical_or() is a logical operation which takes two logical operands (see Logical operands). The result is the digit-wise or of the two operands.

logical_xor(other, context=None)
logical_xor() is a logical operation which takes two logical operands (see Logical operands). The result is the digit-wise exclusive or of the two operands.

max(other, context=None)
Like max(self, other) except that the context rounding rule is applied before returning and that NaN values are either signaled or ignored (depending on the context and whether they are signaling or quiet).

max_mag(other, context=None)
Similar to the max() method, but the comparison is done using the absolute values of the operands.

min(other, context=None)
Like min(self, other) except that the context rounding rule is applied before returning and that NaN values are either signaled or ignored (depending on the context and whether they are signaling or quiet).

min_mag(other, context=None)
Similar to the min() method, but the comparison is done using the absolute values of the operands.

next_minus(context=None)
Return the largest number representable in the given context (or in the current thread’s context if no context is given) that is smaller than the given operand.

next_plus(context=None)
Return the smallest number representable in the given context (or in the current thread’s context if no context is given) that is larger than the given operand.

next_toward(other, context=None)
If the two operands are unequal, return the number closest to the first operand in the direction of the second operand. If both operands are numerically equal, return a copy of the first operand with the sign set to be the same as the sign of the second operand.

normalize(context=None)
Normalize the number by stripping the rightmost trailing zeros and converting any result equal to Decimal('0') to Decimal('0e0'). Used for producing canonical values for attributes of an equivalence class. For example, Decimal('32.100') and Decimal('0.321000e+2') both normalize to the equivalent value Decimal('32.1').

number_class(context=None)
Return a string describing the class of the operand. The returned value is one of the following ten strings.

"-Infinity", indicating that the operand is negative infinity.

"-Normal", indicating that the operand is a negative normal number.

"-Subnormal", indicating that the operand is negative and subnormal.

"-Zero", indicating that the operand is a negative zero.

"+Zero", indicating that the operand is a positive zero.

"+Subnormal", indicating that the operand is positive and subnormal.

"+Normal", indicating that the operand is a positive normal number.

"+Infinity", indicating that the operand is positive infinity.

"NaN", indicating that the operand is a quiet NaN (Not a Number).

"sNaN", indicating that the operand is a signaling NaN.

quantize(exp, rounding=None, context=None)
Return a value equal to the first operand after rounding and having the exponent of the second operand.

>>>
Decimal('1.41421356').quantize(Decimal('1.000'))
Decimal('1.414')
Unlike other operations, if the length of the coefficient after the quantize operation would be greater than precision, then an InvalidOperation is signaled. This guarantees that, unless there is an error condition, the quantized exponent is always equal to that of the right-hand operand.

Also unlike other operations, quantize never signals Underflow, even if the result is subnormal and inexact.

If the exponent of the second operand is larger than that of the first then rounding may be necessary. In this case, the rounding mode is determined by the rounding argument if given, else by the given context argument; if neither argument is given the rounding mode of the current thread’s context is used.

An error is returned whenever the resulting exponent is greater than Emax or less than Etiny().

radix()
Return Decimal(10), the radix (base) in which the Decimal class does all its arithmetic. Included for compatibility with the specification.

remainder_near(other, context=None)
Return the remainder from dividing self by other. This differs from self % other in that the sign of the remainder is chosen so as to minimize its absolute value. More precisely, the return value is self - n * other where n is the integer nearest to the exact value of self / other, and if two integers are equally near then the even one is chosen.

If the result is zero then its sign will be the sign of self.

>>>
Decimal(18).remainder_near(Decimal(10))
Decimal('-2')
Decimal(25).remainder_near(Decimal(10))
Decimal('5')
Decimal(35).remainder_near(Decimal(10))
Decimal('-5')
rotate(other, context=None)
Return the result of rotating the digits of the first operand by an amount specified by the second operand. The second operand must be an integer in the range -precision through precision. The absolute value of the second operand gives the number of places to rotate. If the second operand is positive then rotation is to the left; otherwise rotation is to the right. The coefficient of the first operand is padded on the left with zeros to length precision if necessary. The sign and exponent of the first operand are unchanged.

same_quantum(other, context=None)
Test whether self and other have the same exponent or whether both are NaN.

This operation is unaffected by context and is quiet: no flags are changed and no rounding is performed. As an exception, the C version may raise InvalidOperation if the second operand cannot be converted exactly.

scaleb(other, context=None)
Return the first operand with exponent adjusted by the second. Equivalently, return the first operand multiplied by 10**other. The second operand must be an integer.

shift(other, context=None)
Return the result of shifting the digits of the first operand by an amount specified by the second operand. The second operand must be an integer in the range -precision through precision. The absolute value of the second operand gives the number of places to shift. If the second operand is positive then the shift is to the left; otherwise the shift is to the right. Digits shifted into the coefficient are zeros. The sign and exponent of the first operand are unchanged.

sqrt(context=None)
Return the square root of the argument to full precision.

to_eng_string(context=None)
Convert to a string, using engineering notation if an exponent is needed.

Engineering notation has an exponent which is a multiple of 3. This can leave up to 3 digits to the left of the decimal place and may require the addition of either one or two trailing zeros.

For example, this converts Decimal('123E+1') to Decimal('1.23E+3').

to_integral(rounding=None, context=None)
Identical to the to_integral_value() method. The to_integral name has been kept for compatibility with older versions.

to_integral_exact(rounding=None, context=None)
Round to the nearest integer, signaling Inexact or Rounded as appropriate if rounding occurs. The rounding mode is determined by the rounding parameter if given, else by the given context. If neither parameter is given then the rounding mode of the current context is used.

to_integral_value(rounding=None, context=None)
Round to the nearest integer without signaling Inexact or Rounded. If given, applies rounding; otherwise, uses the rounding method in either the supplied context or the current context.

Logical operands
The logical_and(), logical_invert(), logical_or(), and logical_xor() methods expect their arguments to be logical operands. A logical operand is a Decimal instance whose exponent and sign are both zero, and whose digits are all either 0 or 1.

Context objects
Contexts are environments for arithmetic operations. They govern precision, set rules for rounding, determine which signals are treated as exceptions, and limit the range for exponents.

Each thread has its own current context which is accessed or changed using the getcontext() and setcontext() functions:

decimal.getcontext()
Return the current context for the active thread.

decimal.setcontext(c)
Set the current context for the active thread to c.

You can also use the with statement and the localcontext() function to temporarily change the active context.

decimal.localcontext(ctx=None, \*\*kwargs)
Return a context manager that will set the current context for the active thread to a copy of ctx on entry to the with-statement and restore the previous context when exiting the with-statement. If no context is specified, a copy of the current context is used. The kwargs argument is used to set the attributes of the new context.

For example, the following code sets the current decimal precision to 42 places, performs a calculation, and then automatically restores the previous context:

from decimal import localcontext

with localcontext() as ctx:
    ctx.prec = 42   # Perform a high precision calculation
    s = calculate_something()
s = +s  # Round the final result back to the default precision
Using keyword arguments, the code would be the following:

from decimal import localcontext

with localcontext(prec=42) as ctx:
    s = calculate_something()
s = +s
Raises TypeError if kwargs supplies an attribute that Context doesn’t support. Raises either TypeError or ValueError if kwargs supplies an invalid value for an attribute.

Changed in version 3.11: localcontext() now supports setting context attributes through the use of keyword arguments.

New contexts can also be created using the Context constructor described below. In addition, the module provides three pre-made contexts:

class decimal.BasicContext
This is a standard context defined by the General Decimal Arithmetic Specification. Precision is set to nine. Rounding is set to ROUND_HALF_UP. All flags are cleared. All traps are enabled (treated as exceptions) except Inexact, Rounded, and Subnormal.

Because many of the traps are enabled, this context is useful for debugging.

class decimal.ExtendedContext
This is a standard context defined by the General Decimal Arithmetic Specification. Precision is set to nine. Rounding is set to ROUND_HALF_EVEN. All flags are cleared. No traps are enabled (so that exceptions are not raised during computations).

Because the traps are disabled, this context is useful for applications that prefer to have result value of NaN or Infinity instead of raising exceptions. This allows an application to complete a run in the presence of conditions that would otherwise halt the program.

class decimal.DefaultContext
This context is used by the Context constructor as a prototype for new contexts. Changing a field (such a precision) has the effect of changing the default for new contexts created by the Context constructor.

This context is most useful in multi-threaded environments. Changing one of the fields before threads are started has the effect of setting system-wide defaults. Changing the fields after threads have started is not recommended as it would require thread synchronization to prevent race conditions.

In single threaded environments, it is preferable to not use this context at all. Instead, simply create contexts explicitly as described below.

The default values are Context.prec=28, Context.rounding=ROUND_HALF_EVEN, and enabled traps for Overflow, InvalidOperation, and DivisionByZero.

In addition to the three supplied contexts, new contexts can be created with the Context constructor.

class decimal.Context(prec=None, rounding=None, Emin=None, Emax=None, capitals=None, clamp=None, flags=None, traps=None)
Creates a new context. If a field is not specified or is None, the default values are copied from the DefaultContext. If the flags field is not specified or is None, all flags are cleared.

prec is an integer in the range [1, MAX_PREC] that sets the precision for arithmetic operations in the context.

The rounding option is one of the constants listed in the section Rounding Modes.

The traps and flags fields list any signals to be set. Generally, new contexts should only set traps and leave the flags clear.

The Emin and Emax fields are integers specifying the outer limits allowable for exponents. Emin must be in the range [MIN_EMIN, 0], Emax in the range [0, MAX_EMAX].

The capitals field is either 0 or 1 (the default). If set to 1, exponents are printed with a capital E; otherwise, a lowercase e is used: Decimal('6.02e+23').

The clamp field is either 0 (the default) or 1. If set to 1, the exponent e of a Decimal instance representable in this context is strictly limited to the range Emin - prec + 1 <= e <= Emax - prec + 1. If clamp is 0 then a weaker condition holds: the adjusted exponent of the Decimal instance is at most Emax. When clamp is 1, a large normal number will, where possible, have its exponent reduced and a corresponding number of zeros added to its coefficient, in order to fit the exponent constraints; this preserves the value of the number but loses information about significant trailing zeros. For example:

>>>
Context(prec=6, Emax=999, clamp=1).create_decimal('1.23e999')
Decimal('1.23000E+999')
A clamp value of 1 allows compatibility with the fixed-width decimal interchange formats specified in IEEE 754.

The Context class defines several general purpose methods as well as a large number of methods for doing arithmetic directly in a given context. In addition, for each of the Decimal methods described above (with the exception of the adjusted() and as_tuple() methods) there is a corresponding Context method. For example, for a Context instance C and Decimal instance x, C.exp(x) is equivalent to x.exp(context=C). Each Context method accepts a Python integer (an instance of int) anywhere that a Decimal instance is accepted.

clear_flags()
Resets all of the flags to 0.

clear_traps()
Resets all of the traps to 0.

New in version 3.3.

copy()
Return a duplicate of the context.

copy_decimal(num)
Return a copy of the Decimal instance num.

create_decimal(num)
Creates a new Decimal instance from num but using self as context. Unlike the Decimal constructor, the context precision, rounding method, flags, and traps are applied to the conversion.

This is useful because constants are often given to a greater precision than is needed by the application. Another benefit is that rounding immediately eliminates unintended effects from digits beyond the current precision. In the following example, using unrounded inputs means that adding zero to a sum can change the result:

>>>
getcontext().prec = 3
Decimal('3.4445') + Decimal('1.0023')
Decimal('4.45')
Decimal('3.4445') + Decimal(0) + Decimal('1.0023')
Decimal('4.44')
This method implements the to-number operation of the IBM specification. If the argument is a string, no leading or trailing whitespace or underscores are permitted.

create_decimal_from_float(f)
Creates a new Decimal instance from a float f but rounding using self as the context. Unlike the Decimal.from_float() class method, the context precision, rounding method, flags, and traps are applied to the conversion.

>>>
context = Context(prec=5, rounding=ROUND_DOWN)
context.create_decimal_from_float(math.pi)
Decimal('3.1415')
context = Context(prec=5, traps=[Inexact])
context.create_decimal_from_float(math.pi)
Traceback (most recent call last):
    ...
decimal.Inexact: None
New in version 3.1.

Etiny()
Returns a value equal to Emin - prec + 1 which is the minimum exponent value for subnormal results. When underflow occurs, the exponent is set to Etiny.

Etop()
Returns a value equal to Emax - prec + 1.

The usual approach to working with decimals is to create Decimal instances and then apply arithmetic operations which take place within the current context for the active thread. An alternative approach is to use context methods for calculating within a specific context. The methods are similar to those for the Decimal class and are only briefly recounted here.

abs(x)
Returns the absolute value of x.

add(x, y)
Return the sum of x and y.

canonical(x)
Returns the same Decimal object x.

compare(x, y)
Compares x and y numerically.

compare_signal(x, y)
Compares the values of the two operands numerically.

compare_total(x, y)
Compares two operands using their abstract representation.

compare_total_mag(x, y)
Compares two operands using their abstract representation, ignoring sign.

copy_abs(x)
Returns a copy of x with the sign set to 0.

copy_negate(x)
Returns a copy of x with the sign inverted.

copy_sign(x, y)
Copies the sign from y to x.

divide(x, y)
Return x divided by y.

divide_int(x, y)
Return x divided by y, truncated to an integer.

divmod(x, y)
Divides two numbers and returns the integer part of the result.

exp(x)
Returns e ** x.

fma(x, y, z)
Returns x multiplied by y, plus z.

is_canonical(x)
Returns True if x is canonical; otherwise returns False.

is_finite(x)
Returns True if x is finite; otherwise returns False.

is_infinite(x)
Returns True if x is infinite; otherwise returns False.

is_nan(x)
Returns True if x is a qNaN or sNaN; otherwise returns False.

is_normal(x)
Returns True if x is a normal number; otherwise returns False.

is_qnan(x)
Returns True if x is a quiet NaN; otherwise returns False.

is_signed(x)
Returns True if x is negative; otherwise returns False.

is_snan(x)
Returns True if x is a signaling NaN; otherwise returns False.

is_subnormal(x)
Returns True if x is subnormal; otherwise returns False.

is_zero(x)
Returns True if x is a zero; otherwise returns False.

ln(x)
Returns the natural (base e) logarithm of x.

log10(x)
Returns the base 10 logarithm of x.

logb(x)
Returns the exponent of the magnitude of the operand’s MSD.

logical_and(x, y)
Applies the logical operation and between each operand’s digits.

logical_invert(x)
Invert all the digits in x.

logical_or(x, y)
Applies the logical operation or between each operand’s digits.

logical_xor(x, y)
Applies the logical operation xor between each operand’s digits.

max(x, y)
Compares two values numerically and returns the maximum.

max_mag(x, y)
Compares the values numerically with their sign ignored.

min(x, y)
Compares two values numerically and returns the minimum.

min_mag(x, y)
Compares the values numerically with their sign ignored.

minus(x)
Minus corresponds to the unary prefix minus operator in Python.

multiply(x, y)
Return the product of x and y.

next_minus(x)
Returns the largest representable number smaller than x.

next_plus(x)
Returns the smallest representable number larger than x.

next_toward(x, y)
Returns the number closest to x, in direction towards y.

normalize(x)
Reduces x to its simplest form.

number_class(x)
Returns an indication of the class of x.

plus(x)
Plus corresponds to the unary prefix plus operator in Python. This operation applies the context precision and rounding, so it is not an identity operation.

power(x, y, modulo=None)
Return x to the power of y, reduced modulo modulo if given.

With two arguments, compute x**y. If x is negative then y must be integral. The result will be inexact unless y is integral and the result is finite and can be expressed exactly in ‘precision’ digits. The rounding mode of the context is used. Results are always correctly rounded in the Python version.

Decimal(0) ** Decimal(0) results in InvalidOperation, and if InvalidOperation is not trapped, then results in Decimal('NaN').

Changed in version 3.3: The C module computes power() in terms of the correctly rounded exp() and ln() functions. The result is well-defined but only “almost always correctly rounded”.

With three arguments, compute (x**y) % modulo. For the three argument form, the following restrictions on the arguments hold:

all three arguments must be integral

y must be nonnegative

at least one of x or y must be nonzero

modulo must be nonzero and have at most ‘precision’ digits

The value resulting from Context.power(x, y, modulo) is equal to the value that would be obtained by computing (x**y) % modulo with unbounded precision, but is computed more efficiently. The exponent of the result is zero, regardless of the exponents of x, y and modulo. The result is always exact.

quantize(x, y)
Returns a value equal to x (rounded), having the exponent of y.

radix()
Just returns 10, as this is Decimal, :)

remainder(x, y)
Returns the remainder from integer division.

The sign of the result, if non-zero, is the same as that of the original dividend.

remainder_near(x, y)
Returns x - y * n, where n is the integer nearest the exact value of x / y (if the result is 0 then its sign will be the sign of x).

rotate(x, y)
Returns a rotated copy of x, y times.

same_quantum(x, y)
Returns True if the two operands have the same exponent.

scaleb(x, y)
Returns the first operand after adding the second value its exp.

shift(x, y)
Returns a shifted copy of x, y times.

sqrt(x)
Square root of a non-negative number to context precision.

subtract(x, y)
Return the difference between x and y.

to_eng_string(x)
Convert to a string, using engineering notation if an exponent is needed.

Engineering notation has an exponent which is a multiple of 3. This can leave up to 3 digits to the left of the decimal place and may require the addition of either one or two trailing zeros.

to_integral_exact(x)
Rounds to an integer.

to_sci_string(x)
Converts a number to a string using scientific notation.