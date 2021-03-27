#include <bitset>
#include <unordered_map>
#include <iostream>
#include <string_view>
#include <cctype>
#include <iomanip>
#include <string>


// https://stackoverflow.com/a/56766138/9514052
template <typename T>
constexpr auto type_name() noexcept {
  std::string_view name = "Error: unsupported compiler", prefix, suffix;
#ifdef __clang__
  name = __PRETTY_FUNCTION__;
  prefix = "auto type_name() [T = ";
  suffix = "]";
#elif defined(__GNUC__)
  name = __PRETTY_FUNCTION__;
  prefix = "constexpr auto type_name() [with T = ";
  suffix = "]";
#elif defined(_MSC_VER)
  name = __FUNCSIG__;
  prefix = "auto __cdecl type_name<";
  suffix = ">(void) noexcept";
#endif
  name.remove_prefix(prefix.size());
  name.remove_suffix(suffix.size());
  return name;
}

const std::unordered_map<char, std::string> fm_str = {
  {'b', "binary"},
  {'h', "hex"},
  {'d', "decimal"},
  {'c', "char"},
};
const std::unordered_map<char, int> fm_idx = {
  {'b', 0},
  {'h', 1},
  {'d', 2},
  {'c', 3},
};

template<typename T>
void show_bytes(T x, std::string format="a", bool fill=true) {
  using std::cout, std::setw, std::string;
  std::ios_base::fmtflags f(cout.flags());
  cout << std::left;
  cout << type_name<decltype(x)>();
  cout << " value: " << x << '\n';
  int w = fill ? 8 : 0;

  // state
  std::bitset<4> fm;
  if (format.find('a') != string::npos) format = "bhdc";
  string new_format = "";
  auto status = [&](char ch, bool change=false) {
    int idx = fm_idx.at(ch);
    if (change) fm[idx] = !fm[idx];
    return fm[idx];
  };
  for (auto ch : format) {
    if (!status(ch)) {
      new_format += ch;
      status(ch, true);
    }
  }

  // print
  for (auto ch : new_format) {
    bool start = true;
    cout << setw(8) << fm_str.at(ch);
    for (int i = 0; i < sizeof(T); ++i) {
      if (start) {
        start = false;
      }
      else {
        cout << " ";
      }
      auto p  = (char*)&x;
      std::bitset<8> bs(p[i]);
      if (ch == 'b') { // binary
        cout << bs;
      }
      else if (ch == 'h') { // hex
        cout << std::hex << setw(w) << bs.to_ulong() << std::dec;
      }
      else if (ch == 'd') { // dec
        cout << setw(w);
        cout << bs.to_ulong();
      }
      else if (ch == 'c') { // char
        cout << setw(w);
        if (std::isprint(p[i])) cout << p[i];
        else cout << '.';
      }
      else {
        cout << "unkown format " << format;
        break;
      }
    }
    cout << '\n';
  }
  cout << '\n';
  cout.flags(f);
}
