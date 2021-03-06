#pragma once

#include <string>
#include <typeinfo>

namespace Demangler {
    std::string demangle(const char* name);

    template <class T>
    std::string typeName(const T& t) {
        return demangle(typeid(t).name());
    }
}
