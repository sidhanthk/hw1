#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"


ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  
  clear();
  Item* current = head_;
  while (current != NULL){
    delete current;
    current = current->next;
  }
  //delete this;
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

std::string* ULListStr::getValAtLoc(size_t loc) const{
  std::string* temp = NULL;
  if (loc > size_-1){
    // throw an exception
    throw std::invalid_argument("getValAtLoc: Bad location");
  }
  Item* current = head_;
  while (current != NULL){
    if ( (current->last - current->first) >= loc){
      return &(current->val[current->first + loc]);
    }
    else{
      loc = loc - (current->last - current->first);
      current = current -> next;
    }
  }
   return temp;
   
  // std::string* temp = NULL;
  // if (loc > size_-1){
  //   return temp;
  // }
  // Item* current = head_;
  // while (current != NULL){
  //   for (int i = 0; i < 10; i++){
  //     unsigned int counter = 0;
  //     if ( !(current->val[i] == " ")){
  //       counter ++;
  //       if (counter == loc){
  //         return &current->val[i];
  //       }
  //     }
  //   }
  //   current = current->next;
  // }
  // return temp;

  
}

void ULListStr::push_back(const std::string& val){
    if (tail_ == NULL){
      Item* item1 = new Item();
      head_ = item1;
      tail_ = item1;
      std::string temp = val;
      item1->val[0] = temp;
      item1->first = 0;
      item1->last = 1;
      item1->prev = NULL;
      item1->next = NULL;
      size_ = 1;
      //delete item1;
    }

    else{
      //!(tail_->val[tail_->last-1].empty())
      if ( tail_->last >= 10){
        Item* item2 = new Item();
        // do I have to dynamically alocate this Item* as well?
        Item* t_copy = tail_; 
        //t_copy = tail_;
        // if (tail_ == head_){
        //   head_ = t_copy;
        //   t_copy->prev = NULL;
        // }
        
        t_copy->next = item2;
        tail_ = item2;
        tail_->prev = t_copy;
        // how do I make the previous tail nodes next point to new node
        // woudl I have to do deep copy, 
        //t_copy->next = item2;
        tail_->val[0] = val;
        tail_->first = 0;
        tail_->last = 1;
        tail_->next = NULL;
        size_ = size_ + 1;
        //delete item2;
        //delete t_copy;
      }
      else{
        tail_->val[tail_->last] = val;
        tail_->last = tail_->last+1;
        size_ = size_ + 1;
      }
    }
}


void ULListStr::push_front(const std::string& val){
  if (head_ == NULL){
    Item* item_1 = new Item();
    head_ = item_1;
    tail_ = item_1;
    // do I need to redefine ARRSIZE in this file, thought it was global in .h imported file
    item_1->val[10-1] = val;
    item_1->first = 10-1;
    item_1->last = 10;
    item_1->prev = NULL;
    item_1->next = NULL;
    size_ = 1;
    //delete item_1;
  }

  else{
    if ( !(head_->val[head_->first-1].empty())) {
      Item* item3 = new Item();
      // should I do deep copy to like Item(head_) or something else with dynamic memory?
      Item* h_copy = head_;
      h_copy->prev = item3;
      head_ = item3;
      item3->first = 9;
      item3->last = 10;
      item3->prev = NULL;
      item3->next = h_copy;
      item3->val[10-1] = val;
      size_ = size_ + 1;
      //delete item3;
    }
    else{
      head_->val[head_->first - 1] = val;
      head_->first = head_->first - 1;
      size_ = size_ + 1;
    }
  }
}

void ULListStr::pop_back(){
  if((tail_ == NULL)){
    throw std::invalid_argument("Bad location");
  }
  else{
    //tail_->val[tail_->last-1] = " ";
    if (tail_->last >= 1){
      tail_->last = tail_->last - 1;
    }
    if (size_ >= 1){
      size_ = size_ - 1;
    }
  }
}

void ULListStr::pop_front(){
  if ( tail_ == NULL){
    throw std::invalid_argument("Bad location");
  }
  else {
    head_->first = head_->first + 1;
    // how to deal with head->first going over
    if (size_ >= 1){
      size_ = size_ - 1;
    }   
  }
}

std::string const & ULListStr::back() const {
  // std::string* ptr;
  // ptr = NULL;
  if(tail_== NULL){
    //throw exception
    throw std::invalid_argument("Bad location");
  }
  else{
    return (tail_->val[tail_->last-1]);
  }
}

std::string const & ULListStr::front() const {
  //std::string* ptr;
  //ptr = NULL;
  if(head_==NULL){
    // throw exception
    throw std::invalid_argument("Bad location");
  }
  else{
    return (head_->val[head_->first]);
    
  }
}

// End of my code

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
