// Copyright (c) 2014-2017 Thomas Fussell
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, WRISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE
//
// @license: http://www.opensource.org/licenses/mit-license.php
// @author: see AUTHORS file

#include <algorithm> // std::find_if

#include <xlnt/worksheet/table.hpp>
#include <xlnt/worksheet/table_iterator.hpp>
#include <xlnt/worksheet/table_vector.hpp>
#include <detail/implementations/worksheet_impl.hpp>
#include <xlnt/utils/exceptions.hpp>

namespace xlnt {

table_vector::table_vector(worksheet ws)
    : ws_(ws)
{
}

table_vector::iterator table_vector::begin()
{
    return iterator(ws_, 0);
}

table_vector::iterator table_vector::end()
{
    return iterator(ws_, ws_.d_->tables_.size());
}

table_vector::const_iterator table_vector::cbegin() const
{
    return const_iterator(ws_, 0);
}

table_vector::const_iterator table_vector::cend() const
{
    return const_iterator(ws_, ws_.d_->tables_.size());
}

bool table_vector::empty() const
{
    return begin() == end();
}

table table_vector::front()
{
    return *begin();
}

const table table_vector::front() const
{
    return *cbegin();
}

table table_vector::back()
{
    return *(--end());
}

const table table_vector::back() const
{
    return *(--cend());
}

std::size_t table_vector::length() const
{
    return ws_.d_->tables_.size();
}

table_vector::const_iterator table_vector::begin() const
{
    return cbegin();
}
table_vector::const_iterator table_vector::end() const
{
    return cend();
}

table_vector::reverse_iterator table_vector::rbegin()
{
    return reverse_iterator(end());
}

table_vector::reverse_iterator table_vector::rend()
{
    return reverse_iterator(begin());
}

table_vector::const_reverse_iterator table_vector::crbegin() const
{
    return const_reverse_iterator(cend());
}

table_vector::const_reverse_iterator table_vector::rbegin() const
{
    return crbegin();
}

table_vector::const_reverse_iterator table_vector::crend() const
{
    return const_reverse_iterator(cbegin());
}

table_vector::const_reverse_iterator table_vector::rend() const
{
    return crend();
}

table table_vector::operator[](std::size_t table_index)
{
    return table(&ws_.d_->tables_[table_index]);
}

const table table_vector::operator[](std::size_t table_index) const
{
    return table(&ws_.d_->tables_[table_index]);
}

table table_vector::operator[](const std::string& table_name)
{
    auto& vec = ws_.d_->tables_;
    auto it = std::find_if(vec.begin(), vec.end(), [&table_name](auto& impl) {
        return impl.name_ == table_name;
    });

    if (it != vec.end()) {
        return table(&*it);
    }

    throw key_not_found();
}

const table table_vector::operator[](const std::string& table_name) const
{
    auto& vec = ws_.d_->tables_;
    auto it = std::find_if(vec.begin(), vec.end(), [&table_name](auto& impl) {
        return impl.name_ == table_name;
    });

    if (it != vec.end()) {
        return table(&*it);
    }

    throw key_not_found();
}

} // namespace xlnt
