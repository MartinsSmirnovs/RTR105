#!/usr/bin/gnuplot --persist

set title "Asin plots" font ",12"
set key left box
set xrange [-1:1]
set yrange [-1:1]

# set term png
# set output "images/output.png"

f0(x) =         (2*0)!*x**(2*0+1) / 4**0*(0!)**2*(2*0+1)
f1(x) = f0(x) + (2*1)!*x**(2*1+1) / 4**0*(1!)**2*(2*1+1)
f2(x) = f1(x) + (2*2)!*x**(2*2+1) / 4**0*(2!)**2*(2*2+1)
f3(x) = f2(x) + (2*3)!*x**(2*3+1) / 4**0*(3!)**2*(2*3+1)

plot asin(x) lw 3, f0(x) lw 3, f1(x) lw 3, f2(x) lw 3, f3(x) lw 3
