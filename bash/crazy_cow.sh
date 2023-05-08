if  [ $# -ne 3 ]
then
  echo "Vous devez rentrez les 3 coefficients de votre polynome : a b c."
  exit 10
fi

delta=$(bc <<< "scale=4; ($2*$2)-(4*$1*$3)")

if [ "$delta" -lt 0 ]
then
  cowsay "Le polynome $1x² + $2x + $3 n'as pas de racines !"
elif [ "$delta" -gt 0 ]
then
  echo "Le polynome $1x² + $2x + $3 a 2 racines."
  delta=$(bc <<< "scale=4; sqrt($delta)")
  cowsay "r1 = $(bc <<< "scale=4; ((-($2))+$delta)/(2*$1)")  et    r2 = $(bc <<< "scale=4; ((-($2))-$delta)/(2*$1)")"
else
  echo "Le polynome $1x² + $2x + $3 a 1 racines."
  cowsay "r = $(bc <<< "scale=4; (-($2))/(2*$1)")"
fi
