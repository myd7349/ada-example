// clang-format off
#include <iostream>

#include <Windows.h>

#include <ada.h>
// clang-format on

int main(int argc, char *argv[]) {
#if defined(_WIN32)
  auto console_cp = GetConsoleCP();
  auto console_output_cp = GetConsoleOutputCP();

  SetConsoleCP(CP_UTF8);
  SetConsoleOutputCP(CP_UTF8);
#endif

  auto res = ada::unicode::percent_encode("测试", ada::character_sets::QUERY_PERCENT_ENCODE);
  std::cout << res << std::endl;
  res = ada::unicode::percent_decode(res, 0);
  std::cout << res << std::endl;

#if defined(_WIN32)
  SetConsoleCP(console_cp);
  SetConsoleOutputCP(console_output_cp);
#endif

  return 0;
}


// References:
// https://github.com/microsoft/vcpkg-tool/blob/main/src/vcpkg.cpp
