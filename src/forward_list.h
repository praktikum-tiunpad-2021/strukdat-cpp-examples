#pragma once

#include <iterator>

namespace strukdat {

template<typename ValueType>
class ForwardList {
 private:
  struct Node {
    ValueType value;
    Node *next;
  };

 public:
  ForwardList() : m_size(0) {
    m_l_sentinel = new Node{.next = nullptr};
    m_f_sentinel = new Node{.next = m_l_sentinel};
  }

  ~ForwardList() {
    auto help_ptr = m_f_sentinel;
    while (help_ptr != nullptr) {
      auto tmp = help_ptr;
      help_ptr = help_ptr->next;
      delete tmp;
    }
  }

  class iterator : public std::iterator<std::forward_iterator_tag, ValueType> {
   public:
    explicit iterator(Node *ptr) : m_node_ptr(ptr) {}
    ValueType &operator*() const { return m_node_ptr->value; }
    ValueType *operator->() const { return &(m_node_ptr->value); };
    iterator operator++() {
      m_node_ptr = m_node_ptr->next;
      return *this;
    }
    iterator operator++(int) {
      iterator ret = *this;
      m_node_ptr = m_node_ptr->next;
      return ret;
    }
    bool operator==(const iterator &other) const {
      return m_node_ptr == other.m_node_ptr;
    }
    bool operator!=(const iterator &other) const {
      return m_node_ptr != other.m_node_ptr;
    }
   private:
    Node *m_node_ptr;
  };

  void push_front(const ValueType &value) {
    Node *new_node = new Node{.value = value, .next = m_f_sentinel->next};
    m_f_sentinel->next = new_node;
    m_size++;
  }

  size_t size() const {
    return m_size;
  }

  bool empty() const {
    return m_size == 0;
  }

  iterator begin() const {
    return iterator(m_f_sentinel->next);
  }

  iterator end() const {
    return iterator(m_l_sentinel);
  }

 private:
  // Pointer to a hypothetical element _before_ the first element.
  // It is not supposed to be de-referenced and does not hold a value.
  Node *m_f_sentinel;

  // Pointer to a hypothetical element _after_ the first element.
  // It is not supposed to be de-referenced and does not hold a value.
  Node *m_l_sentinel;

  size_t m_size;
};

}

