#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

auto date(const short unsigned int year, const short unsigned int month) {
  namespace gr = boost::gregorian;

  gr::date d{year, month, 1};

  while (d.day_of_week() != gr::Tuesday) {
    d += gr::days(1);
  }
  d += gr::weeks(1);

  return d.day();
}

int main() {
  std::cout << date(2019, 3);  // second tuesday of march 2019 -> 12
}