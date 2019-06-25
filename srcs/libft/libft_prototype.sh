for f in *.c; do egrep "^int|^void|^char|^size_t" >> prototype "$f"; done && sed -i -e 's/$/\;/' prototype && rm prototype-e && cat prototype >> libft.h && rm prototype
