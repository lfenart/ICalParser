module Ast;

import std.core;

namespace ast {

void VEvent::accept(std::shared_ptr<Visitor> v) const
{
	v->visit_vevent(*this);
}

}
