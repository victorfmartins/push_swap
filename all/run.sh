# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 10:18:22 by vfranco-          #+#    #+#              #
#    Updated: 2022/09/29 15:03:32 by vfranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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