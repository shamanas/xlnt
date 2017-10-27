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

#include <xlnt/worksheet/table.hpp>
#include <xlnt/worksheet/table_iterator.hpp>
#include <detail/implementations/worksheet_impl.hpp>

namespace xlnt {

table_iterator::table_iterator(worksheet ws, std::size_t start_index)
    : ws_(ws),
      table_index_(start_index)
{
}

const_table_iterator::const_table_iterator(worksheet ws, std::size_t start_index)
    : ws_(ws),
      table_index_(start_index)
{
}

table_iterator::table_iterator(const table_iterator &other)
{
    *this = other;
}

const_table_iterator::const_table_iterator(const const_table_iterator &other)
{
    *this = other;
}

bool table_iterator::operator==(const table_iterator &other) const
{
    return ws_ == other.ws_ && table_index_ == other.table_index_;
}

bool const_table_iterator::operator==(const const_table_iterator &other) const
{
    return ws_ == other.ws_ && table_index_ == other.table_index_;
}

bool table_iterator::operator!=(const table_iterator &other) const
{
    return !(*this == other);
}

bool const_table_iterator::operator!=(const const_table_iterator &other) const
{
    return !(*this == other);
}

table_iterator &table_iterator::operator--()
{
    table_index_--;
    return *this;
}


const_table_iterator &const_table_iterator::operator--()
{
    table_index_--;
    return *this;
}

table_iterator table_iterator::operator--(int)
{
    table_iterator old = *this;
    --*this;

    return old;
}

const_table_iterator const_table_iterator::operator--(int)
{
    const_table_iterator old = *this;
    --*this;

    return old;
}

table_iterator &table_iterator::operator++()
{
    table_index_++;
    return *this;
}

const_table_iterator &const_table_iterator::operator++()
{
    table_index_++;
    return *this;
}

table_iterator table_iterator::operator++(int)
{
    table_iterator old = *this;
    ++*this;

    return old;
}

const_table_iterator const_table_iterator::operator++(int)
{
    const_table_iterator old = *this;
    ++*this;

    return old;
}

table table_iterator::operator*()
{
    return table(&ws_.d_->tables_[table_index_]);
}

const table const_table_iterator::operator*() const
{
    return table(&ws_.d_->tables_[table_index_]);
}

} // namespace xlnt
