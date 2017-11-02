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

#include <string>
#include <vector>

#include <xlnt/xlnt_config.hpp>

namespace xlnt {

class xlsx_consumer;
class xlsx_producer;
class const_table_iterator;
class table_iterator;
class table_vector;
class range;

namespace detail {

class xlsx_consumer;
class xlsx_producer;

struct table_impl;

} // namespace detail

/// <summary>
/// Describes a table in a worksheet and its
/// associated properties.
/// </summary>
class XLNT_API table
{
public:
    /// <summary>
    /// Default copy constructor.
    /// </summary>
    table(const table &) = default;

    /// <summary>
    /// Returns the name of this table.
    /// </summary>
    std::string name() const;

    /// <summary>
    /// Returns the range referenced by this table.
    /// Column names are excluded or included based on the exlude_header_row flag.
    /// </summary>
    class range range(bool exclude_header_row = true);

    /// <summary>
    /// Returns the range referenced by this table.
    /// Column names are excluded or included based on the exlude_header_row flag.
    /// </summary>
    const class range range(bool exclude_header_row = true) const;

    /// <summary>
    /// Returns the number of columns this table has.
    /// </summary>
    std::size_t column_length() const;

    /// <summary>
    /// Returns a constant reference to the vector of the column names of this table.
    /// </summary>
    const std::vector<std::string>& columns() const;

    /// <summary>
    /// Modifies the name of this table.
    /// </summary>
    void rename(const std::string& new_name);
private:
    friend class detail::xlsx_consumer;
    friend class detail::xlsx_producer;
    friend class const_table_iterator;
    friend class table_iterator;
    friend class table_vector;
    friend struct detail::table_impl;

    /// <summary>
    /// Delete the default zero-argument constructor.
    /// </summary>
    table() = delete;

    /// <summary>
    /// Private constructor to create a table from its implementation.
    /// </summary>
    table(detail::table_impl *d);

    /// <summary>
    /// A pointer to this table's implementation.
    /// </summary>
    detail::table_impl *d_;
};

} // namespace xlnt
