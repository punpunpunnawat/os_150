fileName="progA.c progB.c progC.c"
for i in $fileName
do
    prog_name=$(echo $i | cut -d'.' -f1)
    gcc -o $prog_name $i |& grep -i 'warning' $i 2>/dev/null
    if [ -f progA ]
    then
        ans=10
        rm $prog_name
    elif [ -f progB ]
    then
        ans=7
        rm $prog_name
    else 
        ans=5
    fi
    printf "%s\t\t%s\n" $i $ans
    ans=0

done