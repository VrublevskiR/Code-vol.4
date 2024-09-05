unsigned int sum_ternary(unsigned int a) {
  unsigned int sum = 0;
  while (a > 0) {
    sum += a % 3;
    a /= 3;
  }
  return sum;
}