/*  Qt Model/View Templates
    Copyright (c) 2015 Luiz Romário Santana Rios <luizromario@gmail.com>
    All rights reserved.
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of the <organization> nor the
          names of its contributors may be used to endorse or promote products
          derived from this software without specific prior written permission.
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef TXTCRUNCH_HPP
#define TXTCRUNCH_HPP

#include <string>
#include <vector>

namespace txtcrunch
{

std::string uncompress(const std::string &in)
{
    std::vector<std::string> entries;
    std::string cur_entry;

    auto it = in.cbegin();
    for (; it != in.cend() && *it != '!'; ++it) {
        const auto ch = *it;

        if (ch == '\\') {
            ++it;
            cur_entry.push_back(*it);
            continue;
        }

        if (ch == '#') {
            entries.push_back(cur_entry);
            cur_entry.clear();
            continue;
        }

        cur_entry.push_back(ch);
    }

    entries.shrink_to_fit();

    const auto in_index = it - in.cbegin();
    std::string res;

    auto is_number = false;
    std::string number;
    for (const auto ch : in.substr(in_index + 1)) {
        if (ch == '#') {
            if (is_number) {
                auto index = std::stoi(number);
                number.clear();

                if (index >= 0 && index < entries.size())
                    res.append(entries[index]);
                else
                    res.append("#" + std::to_string(index) + "#");
            }

            is_number = !is_number;
            continue;
        }

        if (is_number) {
            number.push_back(ch);
            continue;
        }

        res.push_back(ch);
    }

    return res;
}

}

#endif

