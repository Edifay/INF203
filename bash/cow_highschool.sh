if [ $# -lt 1 ]
then
    echo "Vous devez donner un nombre"
    exit -1
fi

for i in `seq 1 $(expr $1 - 1)`
do
    clear
    cowsay $(expr $i '*' $i)
    sleep 1
done
clear
cowsay -T U. $(expr $1 '*' $1)
