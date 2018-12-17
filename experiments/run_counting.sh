declare -a size=(100 1000 10000 100000 500000 1000000 5000000 10000000)
left=0
right=1000000

rm Counting/*.csv
for s in "${size[@]}"
do
	../bin/sample_lab -f ../experiments/Counting/test -s Counting -n $s -l $left -r $right
done 