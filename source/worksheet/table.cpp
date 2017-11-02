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

#include <detail/implementations/table_impl.hpp>
#include <xlnt/worksheet/table.hpp>
#include <xlnt/worksheet/worksheet.hpp>
#include <xlnt/worksheet/range.hpp>

namespace xlnt {

table::table(detail::table_impl *d)
    : d_(d)
{
}

std::string table::name() const
{
    return d_->name_;
}

range table::range(bool exclude_header_row)
{
    worksheet ws { d_->parent_ };
    if (exclude_header_row)
    {
        return ws.range({ d_->ref_.top_left().make_offset(0, 1), d_->ref_.bottom_right() });
    }

    return ws.range(d_->ref_);
}

const range table::range(bool exclude_header_row) const
{
    worksheet ws { d_->parent_ };
    if (exclude_header_row)
    {
        return ws.range({ d_->ref_.top_left().make_offset(0, 1), d_->ref_.bottom_right() });
    }

    return ws.range(d_->ref_);
}

std::size_t table::column_length() const
{
    return d_->column_names_.size();
}

const std::vector<std::string>& table::columns() const
{
    return d_->column_names_;
}

void table::rename(const std::string& new_name)
{
    d_->name_ = new_name;
}

} // namespace xlnt
