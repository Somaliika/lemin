make
echo "error_room_name L"
./lem-in < ./errors/error_room_name1 > result
echo "\033[31;1mWrong room\x1b[0m" > right
diff result right
echo "error_room_name -"
./lem-in < ./errors/error_room_name2 > result
echo "\033[31;1mWrong link\x1b[0m" > right
diff result right
echo "error_room_name #"
./lem-in < ./errors/error_room_name3 > result
echo "\033[31;1mWrong link\x1b[0m" > right
diff result right
echo "error_ant negative"
./lem-in < ./errors/error_ant1 > result
echo "\033[31;1mWrong number of ants\x1b[0m" > right
diff result right
echo "error_ant plus"
./lem-in -r < ./errors/error_ant2 > result
echo 5 > right
diff result right
echo "error_ant zero"
./lem-in < ./errors/error_ant3 > result
echo "\033[31;1mWrong number of ants\x1b[0m" > right
diff result right
echo "error_ant space after"
./lem-in < ./errors/error_ant4 > result
echo "\033[31;1mWrong number of ants\x1b[0m" > right
diff result right
echo "error_ant large"
./lem-in < ./errors/error_ant5 > result
echo "\033[31;1mWrong number of ants\x1b[0m" > right
diff result right
echo "error_coord letters"
./lem-in < ./errors/error_coord1 > result
echo "\033[31;1mWrong room\x1b[0m" > right
diff result right
echo "error_coord space"
./lem-in < ./errors/error_coord2 > result
echo "\033[31;1mWrong room\x1b[0m" > right
diff result right
echo "error_coord letters within numbers"
./lem-in < ./errors/error_coord3 > result
echo "\033[31;1mWrong room\x1b[0m" > right
diff result right
echo "duplicate_room name"
./lem-in < ./errors/duplicate_room1 > result
echo "\033[31;1mRoom is not unique\x1b[0m" > right
diff result right
echo "duplicate_room coordinates"
./lem-in < ./errors/duplicate_room2 > result
echo "\033[31;1mRoom is not unique\x1b[0m" > right
diff result right
echo "error_command two starts"
./lem-in < ./errors/error_command1 > result
echo "\033[31;1mCommands are wrong\x1b[0m" > right
diff result right
echo "error_command no start"
./lem-in < ./errors/error_command2 > result
echo "\033[31;1mCommands are wrong\x1b[0m" > right
diff result right
echo "error_command two commands in row"
./lem-in < ./errors/error_command3 > result
echo "\033[31;1mCommands are wrong\x1b[0m" > right
diff result right
echo "error_command link after command"
./lem-in < ./errors/error_command4 > result
echo "\033[31;1mCommands are wrong\x1b[0m" > right
diff result right
echo "error_command comment after command"
./lem-in -r < ./errors/error_command5 > result
echo 5 > right
diff result right
echo "error_command duplicate command"
./lem-in < ./errors/error_command6 > result
echo "\033[31;1mCommands are wrong\x1b[0m" > right
diff result right
echo "error_end at start"
./lem-in < ./errors/error_end1 > result
echo "\033[31;1mWrong number of ants\x1b[0m" > right
diff result right
echo "error_end in the middle"
./lem-in < ./errors/error_end2 > result
echo "\033[31;1mCommands are wrong\x1b[0m" > right
diff result right
echo "error_link unexisting room"
./lem-in < ./errors/error_link1 > result
echo "\033[31;1mWrong link\x1b[0m" > right
diff result right
echo "error_link at itself"
./lem-in < ./errors/error_link2 > result
echo "\033[31;1mWrong link\x1b[0m" > right
diff result right
echo "error_link --"
./lem-in < ./errors/error_link3 > result
echo "\033[31;1mWrong link\x1b[0m" > right
diff result right
echo "error_link duplicate link"
./lem-in < ./errors/error_link4 > result
echo "\033[31;1mWrong link\x1b[0m" > right
diff result right
echo "error_absent_ways"
./lem-in < ./errors/error_absent_ways > result
echo "\033[31;1mThere are no connection between start and finish\x1b[0m" > right
diff result right
echo "short_path"
./lem-in -r < ./errors/short_path > result
echo 6 > right
diff result right
echo "absent_ants"
./lem-in -r < ./errors/absent_ants > result
echo "\033[31;1mWrong number of ants\x1b[0m" > right
diff result right
echo "absent_links"
./lem-in -r < ./errors/absent_links > result
echo "\033[31;1mThere are no connection between start and finish\x1b[0m" > right
diff result right
echo "absent_rooms"
./lem-in -r < ./errors/absent_rooms > result
echo "\033[31;1mWrong link\x1b[0m" > right
diff result right
echo "error_link_in_rooms"
./lem-in -r < ./errors/error_link_in_rooms > result
echo "\033[31;1mWrong link\x1b[0m" > right
diff result right
echo "error_room_in_links"
./lem-in -r < ./errors/error_room_in_links > result
echo "\033[31;1mWrong link\x1b[0m" > right
diff result right
rm result
rm right