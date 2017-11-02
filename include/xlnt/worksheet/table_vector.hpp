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

#pragma once

#include <iterator>

#include <xlnt/xlnt_config.hpp>
#include <xlnt/worksheet/table_iterator.hpp>
#include <xlnt/worksheet/worksheet.hpp>

namespace xlnt {

class table;
class table_iterator;
class const_table_iterator;

/// <summary>
/// A table vector is a collection of all tables of a specific worksheet.
/// </summary>
class XLNT_API table_vector
{
public:
    /// <summary>
    /// Iterate over tables in a table_vector with an iterator of this type.
    /// </summary>
    using iterator = table_iterator;

    /// <summary>
    /// Iterate over const tables in a const table_vector with an iterator of this type.
    /// </summary>
    using const_iterator = const_table_iterator;

    /// <summary>
    /// Iterate over tables in a table_vector in reverse oreder with an iterator
    /// of this type.
    /// </summary>
    using reverse_iterator = std::reverse_iterator<iterator>;

    /// <summary>
    /// Iterate over const tables in a const table_vector in reverse order with
    /// an iterator of this type.
    /// </summary>
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    /// <summary>
    /// Constructs a table vector pointing to tables of a given worksheet.
    /// </summary>
    table_vector(worksheet ws);

    /// <summary>
    /// Returns true if there are no tables in the vector.
    /// </summary>
    bool empty() const;

    /// <summary>
    /// Returns the first table in this vector.
    /// </summary>
    table front();

    /// <summary>
    /// Returns the first table in this vector.
    /// </summary>
    const table front() const;

    /// <summary>
    /// Returns the last table in this vector.
    /// </summary>
    table back();

    /// <summary>
    /// Returns the last table in this vector.
    /// </summary>
    const table back() const;

    /// <summary>
    /// Returns the distance between the first and last tables in this vector.
    /// </summary>
    std::size_t length() const;

    /// <summary>
    /// Creates a new table with the given attributes, returns a reference to it.
    /// </summary>
    table add(const std::string& name, std::initializer_list<std::string> column_names, const cell_reference& top_left, std::uint32_t rows);

    /// <summary>
    /// Creates a new table with the given attributes, returns a reference to it.
    /// </summary>
    table add(const std::string& name, std::vector<std::string>&& column_names, const cell_reference& top_left, std::uint32_t rows);

    /// <summary>
    /// Creates a new table with the given attributes, returns a reference to it.
    /// </summary>
    table add(const std::string& name, const std::vector<std::string>& column_names, const cell_reference& top_left, std::uint32_t rows);

    /// <summary>
    /// Returns an iterator to the first table in this vector.
    /// </summary>
    iterator begin();

    /// <summary>
    /// Returns an iterator to the first table in this vector.
    /// </summary>
    const_iterator begin() const;

    /// <summary>
    /// Returns an iterator to the first table in this vector.
    /// </summary>
    const_iterator cbegin() const;

    /// <summary>
    /// Returns an iterator to a table one-past-the-end of this vector.
    /// </summary>
    iterator end();

    /// <summary>
    /// Returns an iterator to a table one-past-the-end of this vector.
    /// </summary>
    const_iterator end() const;

    /// <summary>
    /// Returns an iterator to a table one-past-the-end of this vector.
    /// </summary>
    const_iterator cend() const;

    /// <summary>
    /// Returns a reverse iterator to the first table of this reversed vector.
    /// </summary>
    reverse_iterator rbegin();

    /// <summary>
    /// Returns a reverse iterator to to a table one-past-the-end of this reversed vector.
    /// </summary>
    reverse_iterator rend();

    /// <summary>
    /// Returns a reverse iterator to the first table of this reversed vector.
    /// </summary>
    const_reverse_iterator rbegin() const;

    /// <summary>
    /// Returns a reverse iterator to to a table one-past-the-end of this reversed vector.
    /// </summary>
    const_reverse_iterator rend() const;

    /// <summary>
    /// Returns a reverse iterator to the first table of this reversed vector.
    /// </summary>
    const_reverse_iterator crbegin() const;

    /// <summary>
    /// Returns a reverse iterator to to a table one-past-the-end of this reversed vector.
    /// </summary>
    const_reverse_iterator crend() const;

    /// <summary>
    /// Returns the table table_index distance away from the first table in this vector.
    /// </summary>
    table operator[](std::size_t table_index);

    /// <summary>
    /// Returns the table table_index distance away from the first table in this vector.
    /// </summary>
    const table operator[](std::size_t table_index) const;

    /// <summary>
    /// Returns the table named table_name in this vector.
    /// </summary>
    table operator[](const std::string& table_name);

    /// <summary>
    /// Returns the table named table_name in this vector.
    /// </summary>
    const table operator[](const std::string& table_name) const;
private:
    /// <summary>
    /// The worksheet this vector points to tables from.
    /// </summary>
    worksheet ws_;
};

} // namespace xlnt
