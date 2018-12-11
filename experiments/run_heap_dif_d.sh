declare -a size=(100 1000 10000 100000 500000 1000000 5000000  10000000 )
declare -a dParams=(2 4 8 16 32)
left=0
right=1000000

rm Heap/*.csv
for d in "${dParams[@]}"
do
	for s in "${size[@]}"
	do
		../bin/sample_lab -f ../experiments/Heap/test_"$d" -s Heap -n $s -l $left -r $right -d $d
	done 
done 