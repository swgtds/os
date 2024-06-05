read -p "Enter first Number : " a
read -p "Enter Second Number : " b
res=0
i="y"
while [ $i = "y" ]
do
    echo "Enter Your choice"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    read ch
    case $ch in
    1)echo " Addition:" `expr $a + $b`
    ;;
    2)echo " Subtraction:" `expr $a - $b`
    ;;
    3)echo " Multiplication:" `expr $a \* $b`
    ;;
    4)echo " Division:" `expr $a / $b`
    ;;
    *)echo "Invalid Choice"
    ;;
    esac
    echo "Do You want to continue?"
    read i
done