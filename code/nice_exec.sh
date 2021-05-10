#! /bin/sh

while true; do
    read -p "Fazer executável? [y/n] " yn
    case $yn in
        [Yy]* ) make exec; break;;
        [Nn]* ) break;;
    esac
done

echo Execução da Stack Machine...
echo
while true; do
    read -p "Depurar conteúdo? O resultado irá ser guardado nesta pasta no ficheiro 'memory_log.txt' [y/n] " yn
    echo
    printf "INPUT: "
    echo 
    case $yn in
        [Yy]* ) valgrind ./exec > ./memory_log.txt 2>&1; break;;
        [Nn]* ) ./exec; break;;
    esac
done

echo
echo ________ END ________
echo

while true; do
    read -p "Pretende limpar o ecrã? [y/n] " yn
    case $yn in
        [Yy]* ) clear; break;;
        [Nn]* ) exit;;
    esac
done