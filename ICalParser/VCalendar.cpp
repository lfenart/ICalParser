module Ast;

import std.core;

namespace ast {

void VCalendar::accept(std::shared_ptr<Visitor> v) const
{
	v->visit_vcalendar(*this);
}

}
