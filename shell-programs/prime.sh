read -p "Enter a Number: " n
i=2
c=1
while [ $i -lt $n ]
do
	b=`expr $n % $i`
	if [ $b -eq 0 ]
	then
		c=0
	fi
	i=`expr $i + 1`
done
if [ $c == 0 ]
then
	echo "$n is not a prime Number"
else
	echo "$n is a prime Number"
fi
