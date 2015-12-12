#include <iostream>
#include <chrono>
#include <random>

using std::chrono::system_clock;
using namespace std;

unsigned int genRandMax(minstd_rand0& gen, int m) {
  return gen() % (m + 1);
}

int main () {
  unsigned seed = system_clock::now().time_since_epoch().count();
  minstd_rand0 generator (seed);
  for (int i = 0; i < 100; i++) {
    cout << genRandMax(generator, 100) << " "
         << genRandMax(generator, 100) << " "
         << genRandMax(generator, 100) << endl;
  }
  return 0;
}
