#!/usr/bin/gnuplot --persist

set grid

set term png
set output "images/integral.png"

set xzeroaxis lt 1 lc rgb 'black' lw 1
set yzeroaxis lt 1 lc rgb 'black' lw 1
set tics scale 1
set grid ytics mytics
set grid xtics mxtics
set mytics 2
set mxtics 2
set xtics axis
set ytics axis

plot [-0.2:1] asin(x) with filledcurves above y1=0 fc "cyan" title "[-0.2:1] asin(x) area", [-0.2:1] asin(x) lw 3
