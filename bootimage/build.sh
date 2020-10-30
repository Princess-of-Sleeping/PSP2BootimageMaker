
cd ./modules/test_plugin
./build.sh
cd ../../

cd ./modules/test_plugin2
./build.sh
cd ../../

rm ./src/test_plugin.h
cp ./modules/test_plugin/build/test_plugin.velf ./modules/test_plugin.velf
xxd -i ./modules/test_plugin.velf > ./src/test_plugin.h
rm ./modules/test_plugin.velf

rm ./src/test_plugin2.h
cp ./modules/test_plugin2/build/test_plugin2.velf ./modules/test_plugin2.velf
xxd -i ./modules/test_plugin2.velf > ./src/test_plugin2.h
rm ./modules/test_plugin2.velf

if [ ! -d build ]; then
  mkdir build
fi

cd build
cmake ../
make
cd ..
