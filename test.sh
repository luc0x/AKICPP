arch=$1

make -C ./source debug ARCH=$arch
if [ "$?" != "0" ]; then
    echo "---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---"
    exit 1
fi

make -C ./source mount ARCH=$arch
if [ "$?" != "0" ]; then
    echo "---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---ERROR---"
    exit 1
fi
./run.sh debug