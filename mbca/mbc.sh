#!/bin/bash
printf "\E[H\E[J"
printf "\E[10;5H"
printf "\E(0"
printf "l"
for val in {6..14}
do
	printf "q"
done
printf "k"

for val2 in {11..18}
do
	printf "\E[$val2;15H"
	printf "x"
done

printf "\E[18;15H"
printf "j"
printf "\E[18;6H"

for val in {6..14}
do
	printf "q"
done

printf "\E[18;5H"
printf "m"

for val2 in {17..11}
do
	printf "\E[$val2;5H"
	printf "x"
done

for i in {1..9}
do
	printf "a"
done

for val2 in {17..11}
do
	printf "\E[$val2;14H"
	printf "a"
done

printf "\E[17;6H"

for i in {1..9}
do
	printf "a"
done

printf "\E[11;6H"

for val2 in {11..17}
do
	printf "\E[$val2;6H"
	printf "a"
done

printf "\E[14;6H"

for i in {1..9}
do
	printf "a"
done

printf "\E[25;1H"
printf "\E(B"