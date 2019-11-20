#ifndef INCLUDE_NLOHMANN_JSON_HPP_
   #include <nlohmann/json.hpp>
#endif

#ifndef _BASIC_STRING_H
   #include <string.h>
#endif

#ifndef _GLIBCXX_CSTDLIB
   #include <cstdlib>
#endif

#ifndef _GLIBCXX_IOSTREAM
   #include <iostream>
#endif

#ifdef _GLIBCXX_EXPERIMENTAL_VECTOR
   #include <vector>
#endif

#ifndef _GLIBCXX_FSTREAM
   #include <fstream>
#endif

#ifndef FMT_CORE_H_
   #include <fmt/format.h>
#endif

#ifndef _LIBPEL_H
   #define _LIBPEL_H 1
#endif

////////////////////////////////////////////////////////////////////////////////////// JSON FUNCTIONS

namespace PEL {
   namespace JSON {
      template<typename T, typename L>
      auto loadJSON(std::string const& src, std::ios_base::openmode open_mode, L lambda) -> std::vector<T>
      {
         auto data = std::vector<T>{};
         if (auto ifs = std::fstream{src, open_mode}) 
         {
            auto json_line = std::string{};

            while (std::getline(ifs, json_line)) {
                  auto j = nlohmann::json::parse(json_line);
                  data.push_back(lambda(j));
            }
            return data;
         } else {
            throw std::ios::failure{fmt::format("Unable to open JSON file {}", src)};
         }
      }
   }
}

////////////////////////////////////////////////////////////////////////////////////// MATH FUNCTIONS

namespace math {
   using namespace std;
   auto computeSlope(double x1, double y1, double x2, double y2) -> double {
      return (x2-x1)/(y2-y1);
   }
}

