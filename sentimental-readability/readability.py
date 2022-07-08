# TODO
from cs50 import get_string

text = get_string("text: ")

letters_count = 0
words_count = 1
sentence_count = 0
index = 0

for c in text:
    if c.isalpha():
        letters_count += 1

    if c == " ":
        words_count += 1

    if c in ["!", ".", "?"]:
        sentence_count += 1

L = letters_count / words_count * 100
S = sentence_count / words_count * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")