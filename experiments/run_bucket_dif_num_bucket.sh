declare -a size=(100 1000 10000 100000 500000 1000000 2000000 5000000 10000000 )
declare -a nParams=(10000 100000 1000000 10000000)
left=0
right=1000000

rm BucketStandart/*.csv
rm BucketInsertion/*.csv
for n in "${nParams[@]}"
do
	for s in "${size[@]}"
	do
		../bin/sample_lab -f ../experiments/BucketStandart/test_"$n" -s BucketStandart -n $s -l $left -r $right -b $n
		../bin/sample_lab -f ../experiments/BucketInsertion/test_"$n" -s BucketInsertion -n $s -l $left -r $right -b $n
	done 
done 