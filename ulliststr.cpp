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
  // Item* current = head_;
  // while (current != NULL){
  //   delete current;
  //   current = current->next;
  // }
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
  // if inalid entry like a location number greater than number of possible values 
  // throw exception.
  if (loc > size_-1){
    throw std::invalid_argument("getValAtLoc: Bad location");
  }
  Item* current = head_;
  // getting location when head isn't null, if its in the node return
  // otherwise go to next one and keep looking
  while (current != NULL){
    if ( (current->last - current->first) > loc){
      return &(current->val[current->first + loc]);
    }
    else{
      loc = loc - (current->last - current->first);
      current = current->next;
    }
  }
   return temp;  
}

void ULListStr::push_back(const std::string& val){
    if (tail_ == NULL){
      // if empty, create item and push back
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
    }

    else{
      //if Item full create new node and push back
      if ( tail_->last >= 10){
        Item* item2 = new Item();
        Item* t_copy = tail_; 
        t_copy->next = item2;
        tail_ = item2;
        tail_->prev = t_copy; 
        tail_->val[0] = val;
        tail_->first = 0;
        tail_->last = 1;
        tail_->next = NULL;
        size_ = size_ + 1;
      }
      else{
        // push back with space
        tail_->val[tail_->last] = val;
        tail_->last = tail_->last+1;
        size_ = size_ + 1;
      }
    }
}


void ULListStr::push_front(const std::string& val){
  // if empty create Item and push front
  if (head_ == NULL){
    Item* item23 = new Item();
    head_ = item23;
    tail_ = item23;
    std::string temp = val;
    // do I need to redefine ARRSIZE in this file, thought it was global in .h imported file
    head_->val[10-1] = temp;
    head_->first = 10-1;
    head_->last = 10;
    head_->prev = NULL;
    head_->next = NULL;
    size_ = 1;
  }
  else{
    // if item array full, make new Item push front value there
    if ( head_->first <= 0) {
      Item* item3 = new Item();
      Item* h_copy = head_;
      h_copy->prev = item3;
      head_ = item3;
      head_->next = h_copy;
      head_->val[10-1] = val;
      head_->first = 9;
      head_->last = 10;
      head_->prev = NULL;
      size_ = size_ + 1;
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
    if ( (tail_->last - tail_->first) == 1 ){
      Item* temp = tail_->prev;
      tail_ = temp;
      size_ = size_ - 1;
    }
    else {
      if (tail_->last >= 1){
        tail_->last = tail_->last - 1;
      }
      if (size_ >= 0){
        size_ = size_ - 1;
      }
    }
  }
}

void ULListStr::pop_front(){
  if ( tail_ == NULL){
    throw std::invalid_argument("Bad location");
  }
  else {
    if ( (head_->last - head_->first) == 1) {
      Item* temp_h = head_->next;
      delete head_;
      head_ = temp_h;
      size_ = size_ - 1;
    }
    else {
      if (head_->first < 9){
        head_->first = head_->first + 1;
      }
      if (size_ >= 0){
        size_ = size_ - 1;
      }
    }
  }
}

std::string const & ULListStr::back() const {
  if(tail_== NULL){
    //throw exception
    throw std::invalid_argument("Bad location");
  }
  else{
    return (tail_->val[tail_->last-1]);
  }
}

std::string const & ULListStr::front() const {
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
