
if [ ! -d build ]; then
  mkdir build
fi

cd build

cmake ../modules/
make

rm ../src/test_plugin.h
cp ./test_plugin/test_plugin.velf ../modules/test_plugin.velf
xxd -i ../modules/test_plugin.velf > ../src/test_plugin.h
rm ../modules/test_plugin.velf

rm ../src/test_plugin2.h
cp ./test_plugin2/test_plugin2.velf ../modules/test_plugin2.velf
xxd -i ../modules/test_plugin2.velf > ../src/test_plugin2.h
rm ../modules/test_plugin2.velf

cd ../

if [ ! -d build2 ]; then
  mkdir build2
fi

cd build2

cmake ../
make
cd ..
