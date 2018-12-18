declare -a size=(100 1000 10000 100000 500000 1000000 5000000 10000000)
left=0
right=2147483646

#rm Distribution/*.csv

for s in "${size[@]}"
do
	#../bin/sample_lab -f ../experiments/Distribution/BucketStandartNormal -s BucketStandart -n $s -l $left -r $right -b 8192 -t normal
	#../bin/sample_lab -f ../experiments/Distribution/BucketInsertionNormal -s BucketInsertion -n $s -l $left -r $right -b 256 -t normal
	#../bin/sample_lab -f ../experiments/Distribution/BucketStandartUniform -s BucketStandart -n $s -l $left -r $right -b 8192 -t uniform
	#../bin/sample_lab -f ../experiments/Distribution/BucketInsertionUniform -s BucketInsertion -n $s -l $left -r $right -b 256 -t uniform
	../bin/sample_lab -f ../experiments/Distribution/BucketStandartNormalNormal -s BucketStandartNormal -n $s -l $left -r $right -b 8192 -t normal
	../bin/sample_lab -f ../experiments/Distribution/BucketInsertioNormalNormal -s BucketInsertioNormal -n $s -l $left -r $right -b 256 -t normal
done 