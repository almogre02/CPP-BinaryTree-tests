#include "doctest.h"
#include "BinaryTree.hpp"
#include <stdexcept>
#include <map>

using namespace ariel;
using namespace std;


BinaryTree<string> string_tree;

TEST_CASE("check add_root function") {
    CHECK_NOTHROW(string_tree.add_root("1"));
    CHECK_NOTHROW(string_tree.add_root("root"));
    CHECK_NOTHROW(string_tree.add_root(""));
    CHECK_NOTHROW(string_tree.add_root("2././"));
    CHECK_NOTHROW(string_tree.add_root("Almog"));
}

TEST_CASE("check add_left function") {
    
CHECK_NOTHROW(string_tree.add_left("Almog","cat"));
CHECK_NOTHROW(string_tree.add_left("Almog","dog"));
CHECK_THROWS(string_tree.add_left("omer","cat"));
CHECK_NOTHROW(string_tree.add_left("dog","cat"));
CHECK_NOTHROW(string_tree.add_left("dog","lion"));
CHECK_THROWS(string_tree.add_left("ant","apple"));
CHECK_THROWS(string_tree.add_left("apple","ant"));
CHECK_NOTHROW(string_tree.add_left("cat","ant"));
CHECK_NOTHROW(string_tree.add_left("ant","apple"));

}

TEST_CASE("check add_right function") {
    
CHECK_NOTHROW(string_tree.add_right("Almog","omer"));
CHECK_NOTHROW(string_tree.add_right("Almog","hadar"));
CHECK_NOTHROW(string_tree.add_right("hadar","shir"));
CHECK_NOTHROW(string_tree.add_right("apple","lemon"));
CHECK_THROWS(string_tree.add_right("shira","Almog"));
CHECK_THROWS(string_tree.add_right("ben","omer"));
CHECK_THROWS(string_tree.add_right("omer","dog"));
CHECK_NOTHROW(string_tree.add_right("hadar","dog"));
CHECK_NOTHROW(string_tree.add_right("apple","omer"));
CHECK_NOTHROW(string_tree.add_right("dog","dog"));

}

