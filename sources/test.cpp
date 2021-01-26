//
// Created by robos on 2021/1/26.
//
#include "../headers/Complex.hpp"
#include "../headers/String.hpp"
#include <iostream>

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
  std::cout << s << std::endl;

  //Complex<float>* pc = new Complex<float>(1, 2);
  void* mem = operator new(sizeof(Complex<float>));
  Complex<float>* pc;
  pc = static_cast<Complex<float>*>(mem);
  //pc->Complex::Complex(1, 2);
  //pc->real(1);
  pc->Complex<float>::Complex(1, 2);
  std::cout << *pc << std::endl;

  delete pc;
  
  auto* ps = new String("hello");
  ps->~String();
  operator delete(ps);
  
  return 0;
}