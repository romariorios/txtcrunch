#include "txtcrunch.hpp"

#include <iostream>

using namespace std;
using namespace txtcrunch;

void show_uncompression(const string &compressed)
{
    const auto uncompressed = uncompress(compressed);

    cout
        << "Uncompressed string: " << uncompressed << " (" << uncompressed.size() << ")\n"
        << "Compressed string: " << compressed << " (" << compressed.size() << ")\n\n";
}

int main()
{
    show_uncompression("I love !#0cats, #0dogs, #0you, #0your life");
    show_uncompression(
        " vencimento #mente no banco Itaú!Até#0preferencial#1; Após#0so#1");
    show_uncompression(
        " require#ments# on the # type !"
        "The#0#1 that are imposed#2ele#1 depend#2actual operations performed#2"
        "container. Generally, it is required that element#3is a complete#3and meets "
        "the#0#1 of Erasable, but many member functions impose stricter#0#1");
    show_uncompression(R"( an exclamation mark (\!)!This text has#0)");
    show_uncompression(R"(HAH\! !#0This text references a non-existing entry: #1)");
    show_uncompression(R"( (of course) !Testing separation between reference and an actual number#0\123)");

    return 0;
}
