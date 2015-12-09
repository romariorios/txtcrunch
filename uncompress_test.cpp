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
    show_uncompression("I love #!#0#cats, #0#dogs, #0#you, #0#your life");
    show_uncompression(
        " vencimento #mente no banco Itaú#!Até#0#preferencial#1#; Após#0#so#1#");
    show_uncompression(
        " require#ments# on the # type #!"
        "The#0##1# that are imposed#2#ele#1# depend#2#actual operations performed#2#"
        "container. Generally, it is required that element#3#is a complete#3#and meets "
        "the#0##1# of Erasable, but many member functions impose stricter#0##1#");
    show_uncompression(" an exclamation mark (\\!)#!This text has#0#");
    show_uncompression("HAH\\! #!#0#This text references a non-existing entry: #1#");

    return 0;
}
