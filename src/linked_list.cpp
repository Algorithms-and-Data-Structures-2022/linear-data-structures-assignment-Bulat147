#include "assignment/linked_list.hpp"

namespace assignment {

  LinkedList::~LinkedList() {
    LinkedList::Clear();
  }

  void LinkedList::Add(int value) {
    if (size_ == 0) {
      front_ = new Node(value);
      back_ = front_;
      size_ = 1;
    } else {
      back_->next = new Node(value);
      back_ = back_->next;
      size_ += 1;
    }
  }
  bool LinkedList::Insert(int index, int value) {
    if (index < 0 or index >size_){
      return false;
    }
    if (index == 0){
      Node* last = front_;
      front_ = new Node(value);
      if (size_ == 0){
        back_ = front_;
      }
      front_->next = last;
      size_ += 1;
    }
    else if (index == size_){
      LinkedList::Add(value);
    }
    else{
      int i = 0;
      Node* nd = front_;
      while (i != index-1){
        nd = nd->next;
        i++;
      }
      Node* nxt = nd->next;
      nd->next = new Node(value);
      nd->next->next = nxt;
      size_ += 1;
    }
    return true;
  }

  bool LinkedList::Set(int index, int new_value) {
    if (index < 0 or index>=size_) {
      return false;
    }
    Node* nd = front_;
    int i = 0;
    while (i != index){
      nd = nd->next;
      i++;
    }
    nd->value = new_value;
    return true;
  }

  std::optional<int> LinkedList::Remove(int index) {
    if (size_ > 0) {
      if (index == 0) {
        Node* for_del = front_;
        front_ = front_->next;
        if (size_ == 1){
          back_ = nullptr;
        }
        size_ -= 1;
        return for_del->value;
      }
      if (index > 0 and index < size_) {
        int i = 0;
        Node* nd = front_;
        while (i != index - 1) {
          nd = nd->next;
          i++;
        }
        Node* for_del = nd->next;
        if (index == size_-1){
          back_ = nd;
        }
        nd->next = nd->next->next;
        size_ -= 1;
        return for_del->value;
      }
    }
  }

  void LinkedList::Clear() {
    while (front_ != nullptr){
      Node* for_del = front_;
      front_ = front_->next;
      delete for_del;
    }
    front_ = nullptr;
    back_ = nullptr;
    size_ = 0;
  }

  std::optional<int> LinkedList::Get(int index) const {
    if (index >= 0 and index < size_){
      Node* nd = front_;
      int i = 0;
      while (i != index){
        nd = nd->next;
        i++;
      }
      return nd->value;
    }
  }

  std::optional<int> LinkedList::IndexOf(int value) const {
    Node* nd = front_;
    int i = 0;
    while (nd != nullptr){
      if (nd->value == value){
        return i;
      }
      nd = nd->next;
      i++;
    }
  }

  bool LinkedList::Contains(int value) const {
    Node* nd = front_;
    while (nd != nullptr){
      if (nd->value == value){
        return true;
      }
      nd = nd->next;
    }
    return false;
  }

  bool LinkedList::IsEmpty() const {
    if (size_ == 0){
      return true;
    }
    return false;
  }

  int LinkedList::size() const {
    return size_;
  }

  std::optional<int> LinkedList::front() const {
    if (front_ != nullptr){
      return front_->value;
    }
  }

  std::optional<int> LinkedList::back() const {
    if (back_ != nullptr){
      return back_->value;
    }
  }

  Node* LinkedList::FindNode(int index) const {
    if (index >= 0 and index < size_){
      Node* nd = front_;
      int i = 0;
      while (i != index){
        nd = nd->next;
        i++;
      }
      return nd;
    }
    return nullptr;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  LinkedList::LinkedList(const std::vector<int>& values) {

    if (values.empty()) {
      return;
    }

    auto* curr_node = new Node(values.front());
    front_ = curr_node;

    for (int index = 1; index < values.size() - 1; ++index) {
      curr_node->next = new Node(values[index]);
      curr_node = curr_node->next;
    }

    if (values.size() == 1) {
      back_ = front_;
    } else {
      curr_node->next = new Node(values.back());
      back_ = curr_node->next;
    }

    size_ = static_cast<int>(values.size());
  }

  std::vector<int> LinkedList::toVector() const {

    if (front_ == nullptr || size_ == 0) {
      return {};
    }

    std::vector<int> array;
    array.reserve(size_);

    for (auto* node = front_; node != nullptr; node = node->next) {
      array.push_back(node->value);
    }

    return array;
  }

}  // namespace assignment