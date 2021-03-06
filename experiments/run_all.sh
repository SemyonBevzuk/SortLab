declare -a size=(100 1000 10000 100000 500000 1000000 5000000 10000000)
left=0
right=2147483646

rm BucketInsertion/run.csv
rm BucketStandart/run.csv
rm Heap/run.csv
rm HeapStandart/run.csv
rm Merge/run.csv
rm Quick/run.csv
rm QuickLomuto/run.csv
#rm SearchTree/run.csv
rm Standart/run.csv
rm Shell/run.csv
#rm Counting/run.csv
rm Radix/run.csv

for s in "${size[@]}"
do
	../bin/sample_lab -f ../experiments/BucketStandart/run -s BucketStandart -n $s -l $left -r $right -b 8192
	../bin/sample_lab -f ../experiments/BucketInsertion/run -s BucketInsertion -n $s -l $left -r $right -b 256
	../bin/sample_lab -f ../experiments/Heap/run -s Heap -n $s -l $left -r $right -d 8
	../bin/sample_lab -f ../experiments/HeapStandart/run -s HeapStandart -n $s -l $left -r $right
	../bin/sample_lab -f ../experiments/Merge/run -s Merge -n $s -l $left -r $right -k 100
	../bin/sample_lab -f ../experiments/Quick/run -s Quick -n $s -l $left -r $right
	../bin/sample_lab -f ../experiments/QuickLomuto/run -s QuickLomuto -n $s -l $left -r $right
	#../bin/sample_lab -f ../experiments/SearchTree/run -s SearchTree -n $s -l $left -r $right
	../bin/sample_lab -f ../experiments/Standart/run -s Standart -n $s -l $left -r $right
	#../bin/sample_lab -f ../experiments/Counting/run -s Counting -n $s -l $left -r $right
	../bin/sample_lab -f ../experiments/Shell/run -s Shell -n $s -l $left -r $right
	../bin/sample_lab -f ../experiments/Radix/run -s Radix -n $s -l $left -r $right
done 