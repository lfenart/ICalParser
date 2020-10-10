module Ast;

import std.core;

namespace ast {

const std::vector<std::unique_ptr<VCalendar>>& ICal::get_calendars() const
{
	return calendars;
}

void ICal::add_calendar(std::unique_ptr<VCalendar> calendar)
{
	calendars.push_back(std::move(calendar));
}

}
