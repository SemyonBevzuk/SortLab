declare -a size=(100 1000 10000 100000 500000 1000000 2000000 5000000 10000000)
declare -a kParams=(2 4 8 10 16)
left=0
right=10

rm Merge/*.csv
for k in "${kParams[@]}"
do
	for s in "${size[@]}"
	do
		../bin/sample_lab -f ../experiments/Merge/test_"$k" -s Merge -n $s -l $left -r $right -k $k
	done 
done 