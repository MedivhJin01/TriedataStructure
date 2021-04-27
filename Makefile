
# List all the drivers
all: triedriver


# list the test program all classes (cpp files)
#  cpp files must use #include , to include *.h or *.hpp files

triedriver: trietest.cpp TrieTree.cpp TrieNode.cpp; g++ -std=c++11 -o triedriver trietest.cpp TrieTree.cpp TrieNode.cpp

# List all the executables under 'all:'
clean: rm *.o triedriver
