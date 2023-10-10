cd build

cmake --build . 

ctest
if [ $? -ne 0 ]; then
    ctest --rerun-failed -V
fi

 cd ..
