#!/bin/bash
for i in {1..16}
do
	for j in {0..99}
	do
		printf -v t "%02d" $j
		wget -rk -e robots=off http://uva.onlinejudge.org/external/$i/$i$t.html
		sleep 5
		#echo http://uva.onlinejudge.org/external/$i/$i$t.html
	done
done
