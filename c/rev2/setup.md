Setup
-----

This setup is only needed if you want to change the flag. Run `./generate.py`, type in the flag when prompted to, and the script will print out the encoded flag and the flag length. Replace these values in the `this_is_what_you_are_looking_for` variable and the `FLAG_LEN` define.

Then run `gcc -o rev2 rev2.c`

Description
-----------

The easiest way to solve the challenge is to use GDB to print out the string in `this_is_what_you_are_looking_for`.

Distribute just the binary.

Difficulty
----------

100 points for a beginner CTF, 50 points for a more advanced CTF.
