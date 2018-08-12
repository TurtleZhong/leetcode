cmake_minimum_required(VERSION 2.8.1)
project(leetcode)

#find_package(Boost)
find_package(Boost REQUIRED COMPONENTS)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

set(CMAKE_CXX_STANDARD 11)
include_directories(${PROJECT_SOURCE_DIR}/array)
include_directories(${PROJECT_SOURCE_DIR}/binary_search)
include_directories(${PROJECT_SOURCE_DIR}/linked_list)
include_directories(${PROJECT_SOURCE_DIR}/string)
include_directories(${PROJECT_SOURCE_DIR}/sort)
include_directories(${PROJECT_SOURCE_DIR}/boost_thread)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${Boost_INCLUDE_DIRS})


add_executable(561_array_partition1 array/561_array_partition1.cpp)
add_executable(766_Toeplitz_Matrix array/766_Toeplitz_Matrix.cpp)
add_executable(566_Reshape_the_Matrix array/566_Reshape_the_Matrix.cpp)
add_executable(485_Max_Consecutive_Ones array/485_Max_Consecutive_Ones.cpp)
add_executable(695_Max_Area_of_Island array/695_Max_Area_of_Island.cpp)
add_executable(283_Move_Zeroes array/283_Move_Zeroes.cpp)
add_executable(448_Find_All_Numbers_Disappeared_in_an_Array array/448_Find_All_Numbers_Disappeared_in_an_Array.cpp)
add_executable(717_1-bit_and_2-bit_Characters array/717_1-bit_and_2-bit_Characters.cpp)
add_executable(169_Majority_Element array/169_Majority_Element.cpp)
add_executable(167_Two_Sum_II_Input_array_is_sorted array/167_Two_Sum_II_Input_array_is_sorted.cpp)
add_executable(217_Contains_Duplicate array/217_Contains_Duplicate.cpp)
add_executable(697_Degree_of_an_Array array/697_Degree_of_an_Array.cpp)
add_executable(661_Image_Smoother array/661_Image_Smoother.cpp)
add_executable(268_Missing_Number array/268_Missing_Number.cpp)
add_executable(628_Maximum_Product_of_Three_Numbers array/628_Maximum_Product_of_Three_Numbers.cpp)
add_executable(746_Min_Cost_Climbing_Stairs array/746_Min_Cost_Climbing_Stairs.cpp)
add_executable(121_Best_Time_to_Buy_and_Sell_Stock array/121_Best_Time_to_Buy_and_Sell_Stock.cpp)
add_executable(674_Longest_Continuous_Increasing_Subsequence array/674_Longest_Continuous_Increasing_Subsequence.cpp)
add_executable(747_Largest_Number_At_Least_Twice_of_Others array/747_Largest_Number_At_Least_Twice_of_Others.cpp)
add_executable(27_Remove_Element array/27_Remove_Element.cpp)
add_executable(53_Maximum_Subarray array/53_Maximum_Subarray.cpp)
add_executable(118_Pascals_Triangle array/118_Pascals_Triangle.cpp)
add_executable(119_Pascals_Triangle_II array/119_Pascals_Triangle_II.cpp)
add_executable(35_Search_Insert_Position array/35_Search_Insert_Position.cpp)
add_executable(1_Two_Sum array/1_Two_Sum.cpp)
add_executable(643_Maximum_Average_Subarray_I array/643_Maximum_Average_Subarray_I.cpp)
add_executable(26_Remove_Duplicates_from_Sorted_Array array/26_Remove_Duplicates_from_Sorted_Array.cpp)
add_executable(219_Contains_Duplicate_II array/219_Contains_Duplicate_II.cpp)
add_executable(88_Merge_Sorted_Array array/88_Merge_Sorted_Array.cpp)
add_executable(605_Can_Place_Flowers array/605_Can_Place_Flowers.cpp)
add_executable(alibaba_test array/alibaba_test.cpp)
add_executable(cainiao_test array/cainiao_test.cpp)



add_executable(657_Judge_Route_Circle string/657_Judge_Route_Circle.cpp)
add_executable(344_Reverse_String string/344_Reverse_String.cpp)
add_executable(557_Reverse_Words_in_a_String_III string/557_Reverse_Words_in_a_String_III.cpp)
add_executable(520_Detect_Capital string/520_Detect_Capital.cpp)
add_executable(find_how_many_words string/find_how_many_words.cpp)
add_executable(reserve_string string/reserve_string.cpp)
add_executable(find_first_one_only_once string/find_first_one_only_once.cpp)

#add_executable(list_node_test array/list_node_test.cpp)
#add_executable(206_Reverse_Linked_List linked_list/206_Reverse_Linked_List.cpp)
#add_executable(92_Reverse_Linked_List_II linked_list/92_Reverse_Linked_List_II.cpp)


add_executable(classical_binary_search binary_search/classical_binary_search.cpp)


add_executable(bubbleSort sort/bubbleSort.cpp)
add_executable(mergeSort sort/mergeSort.cpp)
add_executable(mergeSortedArray sort/mergeSortedArray.cpp)
add_executable(quickSort sort/quickSort.cpp)
add_executable(findKthElement sort/findKthElement.cpp)


set(LIBS
        ${Boost_LIBRARIES}
        -lboost_system
        -lboost_thread
        )

add_executable(boost_thread boost_thread/boost_thread.cpp)
target_link_libraries(boost_thread ${LIBS})

add_executable(fusion_demo boost_thread/fusion_demo.cpp)
target_link_libraries(fusion_demo ${LIBS})