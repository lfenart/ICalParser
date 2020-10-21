module Ast;

import std.core;

namespace ast {

void VJournal::accept(std::shared_ptr<Visitor> v) const
{
	v->visit_vjournal(*this);
}

}
