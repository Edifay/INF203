if [ $# -lt 1 ]
then
    echo "Vous devez donner un nombre"
    exit -1
fi


u0=0
u1=1
while [ $(expr $u0 + $u1) -lt $1 ]
do
    sleep 1
    clear
    temp=$u1
    u1=$(expr $u0 + $u1)
    u0=$temp
    cowsay $u1
done
clear
cowsay -T U. $u1