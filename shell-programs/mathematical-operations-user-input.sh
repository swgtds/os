read -p "Enter a Value : " a
read -p "Enter a value : " b
add=`expr $a + $b`
echo "Addtion Value is $add"
sub=`expr $a - $b`
echo "Subtraction Value is $sub"
mul=`expr $a \* $b`
echo "Multiplication Value is $mul"
div=`expr $a / $b`
echo "Division Value is $div"
mod=`expr $a % $b`
echo "Modulus Value is $mod"
f=`echo "scale = 5; $a / $b" | bc`
echo "Floating Value is $f"
