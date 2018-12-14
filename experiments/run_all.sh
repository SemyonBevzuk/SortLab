declare -a size=(100 1000 10000 100000 500000 1000000 5000000 10000000 25000000 50000000 100000000)
left=0
right=1000000

rm Bubble/run.csv
rm BucketInsertion/run.csv
rm BucketStandart/run.csv
rm Heap/run.csv
rm Merge/run.csv
rm Quick/run.csv
rm QuickLomuto/run.csv
#rm SearchTree/run.csv
rm Standart/run.csv
rm Counting/run.csv

for s in "${size[@]}"
do
	#../bin/sample_lab -f ../experiments/Bubble/run -s Bubble -n $s -l $left -r $right
	../bin/sample_lab -f ../experiments/BucketStandart/run -s BucketStandart -n $s -l $left -r $right -b 10000
	../bin/sample_lab -f ../experiments/BucketInsertion/run -s BucketInsertion -n $s -l $left -r $right -b 1000000
	../bin/sample_lab -f ../experiments/Heap/run -s Heap -n $s -l $left -r $right -d 8
	../bin/sample_lab -f ../experiments/Merge/run -s Merge -n $s -l $left -r $right -k 10
	../bin/sample_lab -f ../experiments/Quick/run -s Quick -n $s -l $left -r $right
	../bin/sample_lab -f ../experiments/QuickLomuto/run -s QuickLomuto -n $s -l $left -r $right
	#../bin/sample_lab -f ../experiments/SearchTree/run -s SearchTree -n $s -l $left -r $right
	../bin/sample_lab -f ../experiments/Standart/run -s Standart -n $s -l $left -r $right
	../bin/sample_lab -f ../experiments/Counting/run -s Counting -n $s -l $left -r $right
done 