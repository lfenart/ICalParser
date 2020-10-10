module Ast;

import std.core;

namespace ast {

const std::vector<VCalendar::uptr>& ICal::get_calendars() const
{
	return calendars;
}

void ICal::add_calendar(VCalendar::uptr calendar)
{
	calendars.push_back(std::move(calendar));
}

}
