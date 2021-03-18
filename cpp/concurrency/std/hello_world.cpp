#include <iostream>
#include <thread>

using namespace std;

void hello() {
  cout << "Hello world\n";
}

int main() {
  thread t(hello);
  t.join();
}
