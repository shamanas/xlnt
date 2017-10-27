// Copyright (c) 2014-2017 Thomas Fussell
// Copyright (c) 2010-2015 openpyxl
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

#pragma once

#include <cstddef> // std::ptrdiff_t
#include <iterator>

#include <xlnt/xlnt_config.hpp>
#include <xlnt/worksheet/worksheet.hpp>

namespace xlnt {

class table;

/// <summary>
/// Alias the parent class of this iterator to increase clarity.
/// </summary>
using t_iter_type = std::iterator<std::bidirectional_iterator_tag,
    table, std::ptrdiff_t, table *, table>;

/// <summary>
/// A table iterator iterates over the tables in a worksheet.
/// </summary>
class XLNT_API table_iterator : public t_iter_type
{
public:
    /// <summary>
    /// Constructs a table_iterator from a worksheet and starting index.
    /// </summary>
    table_iterator(worksheet ws, std::size_t start_index);

    /// <summary>
    /// Constructs a table_iterator as a copy of an existing table_iterator.
    /// </summary>
    table_iterator(const table_iterator &other);

    /// <summary>
    /// Assigns this iterator to match the data in rhs.
    /// </summary>
    table_iterator &operator=(const table_iterator &rhs) = default;

    /// <summary>
    /// Dereferences this iterator to return the table it points to.
    /// </summary>
    table operator*();

    /// <summary>
    /// Returns true if this iterator is equivalent to other.
    /// </summary>
    bool operator==(const table_iterator &other) const;

    /// <summary>
    /// Returns true if this iterator isn't equivalent to other.
    /// </summary>
    bool operator!=(const table_iterator &other) const;

    /// <summary>
    /// Pre-decrements the iterator to point to the previous table and
    /// returns a reference to the iterator.
    /// </summary>
    table_iterator &operator--();

    /// <summary>
    /// Post-decrements the iterator to point to the previous table and
    /// return a copy of the iterator before the decrement.
    /// </summary>
    table_iterator operator--(int);

    /// <summary>
    /// Pre-increments the iterator to point to the next table and
    /// returns a reference to the iterator.
    /// </summary>
    table_iterator &operator++();

    /// <summary>
    /// Post-increments the iterator to point to the next table and
    /// return a copy of the iterator before the decrement.
    /// </summary>
    table_iterator operator++(int);

private:
    /// <summary>
    /// The worksheet this iterator will return tables from.
    /// </summary>
    worksheet ws_;

    /// <summary>
    /// The current table the iterator points to
    /// </summary>
    std::size_t table_index_;
};

/// <summary>
/// Alias the parent class of this iterator to increase clarity.
/// </summary>
using ct_iter_type = std::iterator<std::bidirectional_iterator_tag,
    const table, std::ptrdiff_t, const table *, const table>;

/// <summary>
/// A cell iterator iterates over a 1D range by row or by column.
/// </summary>
class XLNT_API const_table_iterator : public ct_iter_type
{
public:
    /// <summary>
    /// Constructs a table_iterator from a worksheet and starting index.
    /// </summary>
    const_table_iterator(worksheet ws, std::size_t start_index);

    /// <summary>
    /// Constructs a table_iterator as a copy of an existing table_iterator.
    /// </summary>
    const_table_iterator(const const_table_iterator &other);

    /// <summary>
    /// Assigns this iterator to match the data in rhs.
    /// </summary>
    const_table_iterator &operator=(const const_table_iterator &) = default;

    /// <summary>
    /// Dereferences this iterator to return the table it points to.
    /// </summary>
    const table operator*() const;

    /// <summary>
    /// Returns true if this iterator is equivalent to other.
    /// </summary>
    bool operator==(const const_table_iterator &other) const;

    /// <summary>
    /// Returns true if this iterator isn't equivalent to other.
    /// </summary>
    bool operator!=(const const_table_iterator &other) const;

    /// <summary>
    /// Pre-decrements the iterator to point to the previous table and
    /// returns a reference to the iterator.
    /// </summary>
    const_table_iterator &operator--();

    /// <summary>
    /// Post-decrements the iterator to point to the previous table and
    /// return a copy of the iterator before the decrement.
    /// </summary>
    const_table_iterator operator--(int);

    /// <summary>
    /// Pre-increments the iterator to point to the next table and
    /// returns a reference to the iterator.
    /// </summary>
    const_table_iterator &operator++();

    /// <summary>
    /// Post-increments the iterator to point to the next table and
    /// return a copy of the iterator before the decrement.
    /// </summary>
    const_table_iterator operator++(int);

private:
    /// <summary>
    /// The worksheet this iterator will return tables from.
    /// </summary>
    worksheet ws_;

    /// <summary>
    /// The current table the iterator points to
    /// </summary>
    std::size_t table_index_;
};

} // namespace xlnt
