read -p "Enter a Number: " n
f=1
k=$n
while [ $n -gt 1 ]
do
	f=`expr $f \* $n`
	n=`expr $n - 1`
done
echo "Factorial of $k is $f"
