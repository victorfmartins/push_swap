#!/bin/bash
for i in {0..9..1}
do
	N=$((2 ** $i))
	echo $N >> output.txt
	ARG=$(seq 1 $N | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l >> output.txt
	ARG=$(seq 1 $N | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l >> output.txt
	ARG=$(seq 1 $N | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l >> output.txt
	ARG=$(seq 1 $N | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l >> output.txt
	ARG=$(seq 1 $N | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l >> output.txt
	ARG=$(seq 1 $N | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l >> output.txt
	ARG=$(seq 1 $N | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l >> output.txt
	ARG=$(seq 1 $N | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l >> output.txt
	ARG=$(seq 1 $N | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l >> output.txt
	ARG=$(seq 1 $N | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l >> output.txt
done