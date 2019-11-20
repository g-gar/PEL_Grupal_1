/*
    MCPP LIBRARIES - match.hpp
    License: GPLv3 - https://www.gnu.org/licenses/gpl-3.0.html
    Author: Daniel G Vergel | daniel.gomez[at]universidadeuropea.es
    Last update: Oct 28, 2019
*/

#ifndef MCPP_LIBRARIES_MATCH_HPP
#define MCPP_LIBRARIES_MATCH_HPP

#include <utility>
#include <variant>

namespace mcpp {

   template<typename... Ts>
   struct overload : Ts... { using Ts::operator()...; };

   template<typename... Ts>
   overload(Ts...) -> overload<Ts...>;

   template<typename Variant, typename... Handlers>
   auto match(Variant&& var, Handlers&&... handlers)
   {
      return std::visit(overload{std::forward<Handlers>(handlers)...}, std::forward<Variant>(var));
   }

} // NAMESPACE mcpp

#endif // MCPP_LIBRARIES_MATCH_HPP