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
#include <locale>

#include <xlnt/worksheet/range_reference.hpp>

namespace xlnt {

range_reference range_reference::make_absolute(const xlnt::range_reference &relative)
{
    range_reference copy = relative;

    copy.top_left_.make_absolute(true, true);
    copy.bottom_right_.make_absolute(true, true);

    return copy;
}

range_reference::range_reference()
    : range_reference("A1")
{
}

range_reference::range_reference(const char *range_string)
    : range_reference(std::string(range_string))
{
}

range_reference::range_reference(const std::string &range_string)
    : top_left_("A1"), bottom_right_("A1")
{
    auto colon_index = range_string.find(':');

    if (colon_index != std::string::npos)
    {
        top_left_ = cell_reference(range_string.substr(0, colon_index));
        bottom_right_ = cell_reference(range_string.substr(colon_index + 1));
    }
    else
    {
        top_left_ = cell_reference(range_string);
        bottom_right_ = cell_reference(range_string);
    }
}

range_reference::range_reference(const cell_reference &top_left,
    const cell_reference &bottom_right)
    : top_left_(top_left),
      bottom_right_(bottom_right)
{
}

range_reference::range_reference(column_t column_index_start,
    row_t row_index_start,
    column_t column_index_end,
    row_t row_index_end)
    : top_left_(column_index_start, row_index_start),
      bottom_right_(column_index_end, row_index_end)
{
}

range_reference range_reference::make_offset(int column_offset, int row_offset) const
{
    auto top_left = top_left_.make_offset(column_offset, row_offset);
    auto bottom_right = bottom_right_.make_offset(column_offset, row_offset);

    return top_left, bottom_right; // lol
        
}

std::size_t range_reference::height() const
{
    return 1 + bottom_right_.row() - top_left_.row();
}

std::size_t range_reference::width() const
{
    return 1 + (bottom_right_.column() - top_left_.column()).index;
}

bool range_reference::is_single_cell() const
{
    return width() == 1 && height() == 1;
}

bool range_reference::contains(const range_reference& other) const
{
    return top_left_.row() <= other.top_left_.row()             &&
           top_left_.column() <= other.top_left_.column()       &&
           bottom_right_.row() >= other.bottom_right_.row()     &&
           bottom_right_.column() >= other.bottom_right_.column();
}

bool range_reference::contains(const cell_reference& c) const
{
    return c.column() >= top_left_.column()     &&
           c.column() <= bottom_right_.column() &&
           c.row() >= top_left_.row()           &&
           c.row() <= bottom_right_.row();
}

bool range_reference::overlaps_with(const range_reference& other) const
{
    return bottom_right_.row() >= other.top_left_.row() &&
           top_left_.row() <= other.bottom_right_.row() &&
           bottom_right_.column() >= other.top_left_.column() &&
           top_left_.column() <= other.bottom_right_.column();
}

optional<range_reference> range_reference::overlap(const range_reference& other) const
{
    if (!overlaps_with(other))
    {
        return {};
    }

    auto max = [](auto left, auto right) {
        return left >= right ? left : right;
    };

    auto min = [](auto left, auto right) {
        return left <= right ? left : right;
    };

    cell_reference top_left { max(top_left_.column(), other.top_left_.column()),
                              max(top_left_.row(), other.top_left_.row()) };

    cell_reference bottom_right { min(bottom_right_.column(), other.bottom_right_.column()),
                                  min(bottom_right_.row(), other.bottom_right_.row()) };
    return optional<range_reference>({ top_left, bottom_right });
}

std::string range_reference::to_string() const
{
    return top_left_.to_string() + ":" + bottom_right_.to_string();
}

bool range_reference::operator==(const range_reference &comparand) const
{
    return comparand.top_left_ == top_left_ && comparand.bottom_right_ == bottom_right_;
}

bool range_reference::operator!=(const range_reference &comparand) const
{
    return comparand.top_left_ != top_left_ || comparand.bottom_right_ != bottom_right_;
}

cell_reference range_reference::top_left() const
{
    return top_left_;
}

cell_reference range_reference::top_right() const
{
    return cell_reference(bottom_right_.column(), top_left_.row());
}

cell_reference range_reference::bottom_left() const
{
    return cell_reference(top_left_.column(), bottom_right_.row());
}

cell_reference range_reference::bottom_right() const
{
    return bottom_right_;
}

bool range_reference::operator==(const std::string &reference_string) const
{
    return *this == range_reference(reference_string);
}

bool range_reference::operator==(const char *reference_string) const
{
    return *this == std::string(reference_string);
}

bool range_reference::operator!=(const std::string &reference_string) const
{
    return *this != range_reference(reference_string);
}

bool range_reference::operator!=(const char *reference_string) const
{
    return *this != std::string(reference_string);
}

XLNT_API bool operator==(const std::string &reference_string, const range_reference &ref)
{
    return ref == reference_string;
}

XLNT_API bool operator==(const char *reference_string, const range_reference &ref)
{
    return ref == reference_string;
}

XLNT_API bool operator!=(const std::string &reference_string, const range_reference &ref)
{
    return ref != reference_string;
}

XLNT_API bool operator!=(const char *reference_string, const range_reference &ref)
{
    return ref != reference_string;
}

} // namespace xlnt
