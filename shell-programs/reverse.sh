read -p "Enter a Number: " n
r=0
a=$n
while [ $n -gt 0 ]
do
    d=`expr $n % 10`
    r=`expr $r \* 10 + $d`
    n=`expr $n / 10`
done
echo "The reverse of $a is $r"