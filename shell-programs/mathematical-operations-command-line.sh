add=`expr $1 + $2`
echo "Addtion Value is $add"
sub=`expr $1 - $2`
echo "Subtraction Value is $sub"
mul=`expr $1 \* $2`
echo "Multiplication Value is $mul"
div=`expr $1 / $2`
echo "Division Value is $div"
mod=`expr $1 % $2`
echo "Modulus Value is $mod"
f=`echo "scale = 5; $1 / $2" | bc`
echo "Floating Value is $f"
