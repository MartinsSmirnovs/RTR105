#!/usr/bin/gnuplot --persist

set grid

# set term png
# set output "images/statistics.png"

set yrange [0:*]
set format y "%0.0f"
set ytics 1

plot '< ./preprocess.sh' using 1:xtic(2) with histograms notitle
