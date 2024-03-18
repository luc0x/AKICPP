arch=$1

make -C ./source debug ARCH=$arch
make -C ./source mount ARCH=$arch
./run.sh debug