declare -a size=(100 1000 10000 100000 500000 1000000 2000000 5000000 10000000 )
left=0
right=2147483646

rm BucketInsertionSortAdaptiv/*.csv
for s in "${size[@]}"
do
	../bin/sample_lab -f ../experiments/BucketInsertionSortAdaptiv/test -s BucketInsertionSortAdaptiv -n $s -l $left -r $right
	
done 