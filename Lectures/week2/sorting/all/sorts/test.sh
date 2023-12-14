#!/bin/sh

N=1000

for sorter in selectionSort bubbleSort insertionSort shellSort mergeSort naiveQuickSort medianOfThreeQuickSort randomisedQuickSort
do
	echo "Testing $sorter"

	for order in random sorted reversed
	do
		for i in {1..100}
		do
			case "$order" in
				random)   seq $N | sort -R > in.txt ;;
				sorted)   seq $N > in.txt ;;
				reversed) seq $N -1 1 > in.txt ;;
			esac

			./$sorter < in.txt > out.txt
			sort -n < in.txt > exp.txt

			if ! diff exp.txt out.txt > /dev/null
			then
				echo "$sorter gave an incorrect output"
				break
			fi
		done
	done
done

rm -f in.txt exp.txt out.txt

