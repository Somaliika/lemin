make
echo "test2_merge"
./lem-in -r < ./examples/test2_merge > result
echo 6 > right
diff result right
echo "test3"
./lem-in -r < ./examples/test3 > result
echo 5 > right
diff result right
echo "small_sp"
./lem-in -r < ./examples/small_sp > result
echo 3 > right
diff result right
echo "sp_subject"
./lem-in -r < ./examples/sp_subject > result
echo 5 > right
diff result right
echo "bhandari"
./lem-in -r < ./examples/bhandari > result
echo 5 > right
diff result right
echo "sp"
./lem-in -r < ./examples/sp > result
echo 68 > right
diff result right
rm result
rm right