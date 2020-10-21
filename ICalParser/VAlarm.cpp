module Ast;

import std.core;

namespace ast {

void VAlarm::accept(std::shared_ptr<Visitor> v) const
{
	v->visit_valarm(*this);
}

}
