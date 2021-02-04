module Ast;

import std.core;

namespace ast {

PropertyAttendee::PropertyAttendee(const std::string& val, const std::map<std::string, std::string>& params)
	: PropertyString(val, params)
{
}

void PropertyAttendee::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_attendee(*this);
}

}
