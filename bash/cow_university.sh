if [ $# -lt 1 ]
then
    echo "Vous devez donner un nombre"
    exit -1
fi

for i in `seq 2 $(expr $1)`
do
    
    flag=1
    for div in `seq 2 $(expr $i - 1)`
    do
        if [ $(expr $i % $div) -eq 0 ]
        then
            flag=0
        fi
    done
    if [ $flag -eq 1 ]
    then
        clear
        cowsay $i
        sleep 1
    fi
done