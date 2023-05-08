if [ $# -lt 1 ]
then
    echo "Ecrivez un calcul par exemple 3+11"
    exit -1
fi

operator='empty'

if [[ "$1" == *'+'* ]]
then
    operator='+'
elif [[ "$1" == *'-'* ]]
then
    operator='-'
elif [[ "$1" == *'*'* ]]
then
    operator='*'
elif [[ "$1" == *'/'* ]]
then
    operator='/'
fi

if [ "$operator" == "empty" ]
then
    echo "Operateur non trouvé !"
    exit -1
fi

first=$(echo "$1" | cut -d "$operator" -f 1)
second=$(echo "$1" | cut -d "$operator" -f 2)

cowsay -T U. -e $(expr $first "$operator" $second) "$1"
