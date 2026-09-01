# Test for state.c
add_executable(test_state test_state.c ../state.c)
add_test(NAME test_state COMMAND test_state)

# Test for peripheral.c
add_executable(test_peripheral test_peripheral.c ../peripheral.c)
add_test(NAME test_peripheral COMMAND test_peripheral)
