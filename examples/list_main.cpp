#include <iostream>
#include "forward_list.hpp"

int main() {
  strukdat::ForwardList<int> l;
  l.push_front(5);
  l.push_front(6);
  l.push_front(7);
  for (const auto e : l) {
    std::cout << e << ' ';
  }
}