#!/usr/bin/gnuplot --persist

set grid

# set term png
# set output "images/derivative.png"

plot [-1.5:1.5] "derivative.dat" using 1:2 with lines title "asin(x) (from file)", \
                "derivative.dat" using 1:3 with lines title "asin'(x) (from file)", \
                "derivative.dat" using 1:4 with lines title "asin''(x) (finite difference)"

