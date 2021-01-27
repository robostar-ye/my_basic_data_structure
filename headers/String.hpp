//
// Created by robos on 2021/1/26.
//

#ifndef MY_BASIC_DATA_STRUCTURE_STRING_HPP
#define MY_BASIC_DATA_STRUCTURE_STRING_HPP
#include <cstring>
#include <ostream>
class String {
public:
  explicit String(const char *cstr = nullptr);
  String(const String &str);
  String &operator=(const String &str);
  ~String();
  char *get_char_str() const { return this->m_data_; }
  /*static int test(int &a) { return a += 1; }
  int& get_a() { return a_test_; }*/

private:
   /* int a_test_;*/
  char *m_data_;
};

inline String::String(const char *cstr) {
  if (cstr) {
    this->m_data_ = new char[strlen(cstr) + 1];
    strcpy(this->m_data_, cstr);
  } else {
    m_data_ = new char[1];
    *m_data_ = '\0';
  }
}

inline String::String(const String &str) {
  this->m_data_ = new char[strlen(str.m_data_) + 1];
  strcpy(this->m_data_, str.m_data_);
}

inline String::~String() { delete[] this->m_data_; }

String &String::operator=(const String &str) {
  //!检测自我赋值 check self assignment
  if (this == &str)
    return *this;

  delete[] this->m_data_;
  this->m_data_ = new char[strlen(str.m_data_) + 1];
  strcpy(this->m_data_, str.m_data_);

  return *this;
}

inline std::ostream &operator<<(std::ostream &os, const String &str) {

  return os << str.get_char_str();
}
#endif // MY_BASIC_DATA_STRUCTURE_STRING_HPP
