#!/usr/bin/gnuplot --persist

set title "Asin plots" font ",12"
set key left box
set grid

set xrange [-2:2]

set xzeroaxis lt 1 lc rgb 'black' lw 2
set yzeroaxis lt 1 lc rgb 'black' lw 2
set tics scale 1
set grid ytics mytics
set grid xtics mxtics
set mytics 2
set mxtics 2

# set term png
# set output "images/asin.png"

plot asin(x) lw 3, asin(x)-1 lw 3, asin(x)+1
