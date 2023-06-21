cmake_minimum_required(VERSION 3.9)
project(LeetCode)
set(CMAKE_CXX_STANDARD 11)

#链接库
aux_source_directory(leetcode/editor/cn/include LEETCODE)
add_library(leetcode ${LEETCODE})
LINK_LIBRARIES(leetcode)


add_executable(94-binary-tree-inorder-traversal leetcode/editor/cn/94-binary-tree-inorder-traversal.cpp)
add_executable(144-binary-tree-preorder-traversal leetcode/editor/cn/144-binary-tree-preorder-traversal.cpp)
add_executable(145-binary-tree-postorder-traversal leetcode/editor/cn/145-binary-tree-postorder-traversal.cpp)
add_executable(100-same-tree leetcode/editor/cn/100-same-tree.cpp)
add_executable(102-binary-tree-level-order-traversal leetcode/editor/cn/102-binary-tree-level-order-traversal.cpp)
add_executable(104-maximum-depth-of-binary-tree leetcode/editor/cn/104-maximum-depth-of-binary-tree.cpp)