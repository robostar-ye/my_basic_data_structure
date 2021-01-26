//
// Created by robos on 2021/1/26.
//

#ifndef MY_BASIC_DATA_STRUCTURE_COMPLEX_HPP
#define MY_BASIC_DATA_STRUCTURE_COMPLEX_HPP
#include <ostream>

template <typename T> class Complex {
public:
  explicit Complex(const T &real = 0, const T &image = 0)
      : real_(real), image_(image){};

  void real(const T &real) { real_ = real; }
  void image(const T &image) { image_ = image; }

  T real() const { return real_; }
  T image() const { return image_; }

  // TODO 其他类型在左边二复数型在右边的
  // +=,-=,/=,*=,但是这样做似乎或涉及到类型转换的问题，考虑一下还是不做了
  Complex<T> &operator+=(const Complex<T> &r);
  Complex<T> &operator+=(const T &r);
  Complex<T> &operator-=(const Complex<T> &r);
  Complex<T> &operator-=(const T &r);
  Complex<T> &operator*=(const Complex<T> &r);
  Complex<T> &operator*=(const T &r);
  Complex<T> &operator/=(const Complex<T> &r);
  Complex<T> &operator/=(const T &r);

private:
  T real_, image_;
  template <typename U> // TODO 为什么_doapl函数不能直接使用T模板？
  friend Complex<U> &_doapl(Complex<U> *ths, const Complex<U> &r);
};

template <typename U>
inline Complex<U> &_doapl(Complex<U> *ths, const Complex<U> &r) {
  ths->real_ += r.real_;
  ths->image_ += r.image_;

  return *ths;
}

template <typename T>
inline Complex<T> &Complex<T>::operator+=(const Complex<T> &r) {

  return _doapl(this, r);
}

template <typename T> Complex<T> &Complex<T>::operator+=(const T &r) {
  this->real_ += r;

  return *this;
}

// template<typename T>
// Complex<T>& operator+=(const T& x, const Complex<T>& y){
//
//}

template <typename T> Complex<T> &Complex<T>::operator-=(const Complex<T> &r) {
  this->real_ += r.real_;
  this->image_ += r.image_;

  return *this;
}

template <typename T> Complex<T> &Complex<T>::operator-=(const T &r) {
  this->real_ -= r;

  return *this;
}

template <typename T> Complex<T> &Complex<T>::operator*=(const Complex<T> &r) {
  this->real_ = this->real_ * r.real_ - this->image_ * r.image_;
  this->image_ = this->real_ * r.image_ + this->image_ * r.real_;

  return *this;
}

template <typename T> Complex<T> &Complex<T>::operator*=(const T &r) {
  this->real_ *= r;
  this->image_ *= r;

  return *this;
}

template <typename T> Complex<T> &Complex<T>::operator/=(const Complex<T> &r) {
  this->real_ = (this->real_ * r.real_ + this->image_ * r.image_) /
                (r.image_ * r.image_ + r.real_ * r.real_);
  this->image_ = (this->image_ * r.real_ - this->real_ * r.image_) /
                 (r.image_ * r.image_ + r.real_ * r.real_);

  return *this;
}

template <typename T> Complex<T> &Complex<T>::operator/=(const T &r) {
  this->real_ /= r;
  this->image_ /= r;

  return *this;
}

template <typename T>
inline Complex<T> operator+(const Complex<T> &x, const Complex<T> &y) {

  return Complex<T>(x.real() + y.real(), x.image() + y.image());
}

template <typename T>
inline Complex<T> operator+(const T &x, const Complex<T> &y) {

  return Complex<T>(x + y.real(), y.image());
}

template <typename T>
inline Complex<T> operator+(const Complex<T> &x, const T &y) {

  return Complex<T>(x.real() + y, x.image());
}

template <typename T>
inline bool operator==(const Complex<T> &x, const Complex<T> &y) {

  return (x.real() == y.real()) && (x.image() == y.image());
}

template <typename T> inline bool operator==(const Complex<T> &x, const T &y) {

  return (x.real() == y) && (x.image() == T());
}

template <typename T> inline bool operator==(const T &x, const Complex<T> &y) {

  return (x = y.real()) && (y.image() == T());
}

template <typename T>
inline Complex<T> operator-(const Complex<T> &x, const Complex<T> &y) {

  return Complex<T>(x.real() - y.real(), x.image() - y.image());
}

template <typename T>
inline Complex<T> operator-(const T &x, const Complex<T> &y) {

  return Complex<T>(x + y.real(), y.image());
}

template <typename T>
inline Complex<T> operator-(const Complex<T> &x, const T &y) {

  return Complex<T>(x.real() + y, x.image());
}

template <typename T>
inline Complex<T> operator*(const Complex<T> &x, const Complex<T> &y) {

  return Complex<T>(x.real() * y.real() - x.image() * y.image(),
                    x.real() * y.image() + x.image_ * y.real());
}

template <typename T>
inline Complex<T> operator*(const Complex<T> &x, const T &y) {

  return Complex<T>(x.real() * y, x.image() * y);
}

template <typename T>
inline Complex<T> operator*(const T &x, const Complex<T> &y) {

  return Complex<T>(x * y.real(), x * y.image());
}

template <typename T>
inline Complex<T> operator/(const Complex<T> &x, const Complex<T> &y) {

  return Complex<T>((x.real() * y.real() + x.image() * y.image()) /
                        (y.real() * y.real() + y.image() * y.image()),
                    (x.image() * y.image() - x.real() * y.image()) /
                        (y.real() * y.real() + y.image() * y.image()));
}

template <typename T>
inline Complex<T> operator/(const Complex<T> &x, const T &y) {

  return Complex<T>(x.real() / y, x.image() / y);
}

template <typename T>
inline Complex<T> operator/(const T &x, const Complex<T> &y) {

  return Complex<T>(
      (x * y.real()) / (y.real() * y.real() + y.image() * y.image()),
      (-x * y.image()) / (y.real() * y.real() + y.image() * y.image()));
}

template <typename T> inline Complex<T> conj(const Complex<T> &x) {

  return Complex<T>(x.real(), -x.image());
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Complex<T> x) {

  return os << '(' << x.real() << ',' << x.image() << ')';
}
#endif // MY_BASIC_DATA_STRUCTURE_COMPLEX_HPP
