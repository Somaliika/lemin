make
echo "test"
./lem-in -r < ./examples/test > result
echo 5 > right
diff result right
echo "test1_paralel"
./lem-in -r < ./examples/test1_paralel > result
echo 3 > right
diff result right
echo "small_circle"
./lem-in -r < ./examples/small_circle > result
echo 9 > right
diff result right
echo "small_t"
./lem-in -r < ./examples/small_t > result
echo 9 > right
diff result right
echo "test_links"
./lem-in -r < ./examples/test_links > result
echo 8 > right
diff result right
echo "middle_t1"
./lem-in -r < ./examples/middle_t1 > result
echo 15 > right
diff result right
echo "middle_t2"
./lem-in -r < ./examples/middle_t2 > result
echo 14 > right
diff result right
echo "small_best"
./lem-in -r < ./examples/small_best > result
echo 14 > right
diff result right
echo "small_best2"
./lem-in -r < ./examples/small_best2 > result
echo 13 > right
diff result right
echo "flow_one"
./lem-in -r < ./examples/flow_one > result
echo 36 > right
diff result right
echo "flow_ten"
./lem-in -r < ./examples/flow_ten > result
echo 33 > right
diff result right
echo "flow_thousand"
./lem-in -r < ./examples/flow_thousand > result
echo 36 > right
diff result right
echo "big"
./lem-in -r < ./examples/big > result
echo 71 > right
diff result right
rm result
rm right