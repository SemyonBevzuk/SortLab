declare -a size=(100 1000 10000 100000 1000000 10000000)
declare -a nParams=(32 64 128 256 512 1024 2048 4096 8192 16384)
left=0
right=2147483646

rm BucketStandart/*.csv
rm BucketInsertion/*.csv
for s in "${size[@]}"
do
	for n in "${nParams[@]}"
	do
		../bin/sample_lab -f ../experiments/BucketStandart/test_"$n" -s BucketStandart -n $s -l $left -r $right -b $n
		../bin/sample_lab -f ../experiments/BucketInsertion/test_"$n" -s BucketInsertion -n $s -l $left -r $right -b $n
	done
done 