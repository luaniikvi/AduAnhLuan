import sys
from time import sleep
# import time


def print_lyrics():
    lines = [
       ("you can't fight it, you can breathe", 0.04),
        ("now you say something so loving,   but", 0.04),
        ("now I gotta let you go", 0.04),
        ("you will be better off with someone new", 0.06),
        ("I don't wanna be alone", 0.06),
        ("you look it hurt me too", 0.05),
        ("you look so broken when you cry", 0.04),
        ("One more and then I say goodbye", 0.04),
        ("Sometimes, all I think about is you", 0.05),
        ("late night in the middle of June", 0.05),
        ("Heat waves been fakin' me out", 0.06),
        ("Can't make you happier now", 0.07),
    ]

    delays = [0.4, 0.7, 1.6, 1, 1.6, 0.7, 0.6, 0.6, 0.8, 1, 0.5, 0.5]
    
    for i, (line, char_delay) in enumerate(lines):
        for char in line:
            print(char, end='')
            sys.stdout.flush()
            sleep(char_delay)
        sleep(delays[i])  
        print('')

print_lyrics()