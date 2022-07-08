# TODO
from cs50 import get_int

card_number = get_int("what's your card number? ")

if card_number < 0 or len(str(card_number)) not in [13, 15, 16]:
    print("INVALID")
    exit(1)

sum_odd = 0
sum_even = 0
n = card_number
unit_digit = 0
tens_digit = 0
mod = 0
total = 0

while n > 0:
    sum_odd += n % 10

    n //= 10

    mod = n % 10
    unit_digit = (mod * 2) % 10
    tens_digit = (mod * 2) // 10
    sum_even += unit_digit + tens_digit

    n //= 10

total = sum_even + sum_odd


if total % 10 != 0:
    print("INVALID")
    exit(2)

start_digit = card_number

while start_digit > 99:
    start_digit //= 10

if start_digit in [51, 52, 53, 54, 55]:
    print("MASTERCARD")

elif start_digit in [34, 37]:
    print("AMEX")

elif start_digit // 10 == 4:
    print("VISA")

else:
    print("INVALID")

































