import collections
def is_letter_constructible(letter_text, magzine_text):
    return (not collections.Counter(letter_text) - collections.Counter(magzine_text))

    