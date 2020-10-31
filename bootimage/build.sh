
include(){
  rm ../src/modules/$2.h
  cp ./$1/$2.velf ../modules/$2.velf
  xxd -i ../modules/$2.velf > ../src/modules/$2.h
  rm ../modules/$2.velf
}

if [ ! -d src/modules ]; then
  cd src
  mkdir modules
  cd ../
fi

if [ ! -d build ]; then
  mkdir build
fi

cd build

cmake ../modules/
make

include test_plugin test_plugin
include test_plugin2 test_plugin2

cd ../

if [ ! -d build2 ]; then
  mkdir build2
fi

cd build2

cmake ../
make
cd ..
