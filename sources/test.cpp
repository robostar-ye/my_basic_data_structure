//
// Created by robos on 2021/1/26.
//
#include "../headers/Complex.hpp"
#include "../headers/String.hpp"
#include <iostream>
#include <queue>
#include <string>

int main() {
  Complex<float> complex_test_1(1.23, -0.98);
  Complex<float> complex_test_2(3.87, 2.48);
  auto complex_test_3 = complex_test_1 + complex_test_2;
  std::cout << complex_test_1 << '+' << complex_test_2 << '=' << complex_test_3
            << std::endl;

  String str1("我是一条字符串");
  String str2("我也是一条字符串");
  std::cout << str1 << str2 << std::endl;

  char s[] = "测试字符串";
  //str1.get_a() = 1;
  //std::cout << str1.get_a() << std::endl;
  //str1.test(str1.get_a());
  //std::cout << str1.get_a() << std::endl;
  std::cout << s << std::endl;

  //Complex<float>* pc = new Complex<float>(1, 2);
//  Complex<float>* pc;
//  void* mem = operator new(sizeof(Complex<float>));
//  pc = static_cast<Complex<float>*>(mem);
//  pc->Complex<float>::Complex(1, 2);  //!这里MinGW编译会报错，MSVC正常
//  std::cout << *pc << std::endl;
//
//  delete pc;
  
  auto* ps = new String("hello");
  ps->~String();
  operator delete(ps);

  std::string str_;

  std::queue<float> A;
  
  return 0;
}