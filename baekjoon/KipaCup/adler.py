from zlib import adler32

s = b'q' * 50007

print(adler32(s, 0), adler32(s, 1))
