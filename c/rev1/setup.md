Setup
-----

This setup is only needed if you want to change the flag. Run `./generate.py`, type in a secret key and the flag when prompted to, and the script will print out the base64 encoding of the secret key and the encrypted flag. Replace these values in `rev1.c` for `SECRET_KEY` and `ENCRYPTED_FLAG`.

Then run `gcc -o rev1 rev1.c`

Description
-----------

This is a simple challenge that involves the player running `strings` on the binary, noticing a base64 string, and decoding the string.

Distribute just the binary.

Difficulty
----------

50 points.
