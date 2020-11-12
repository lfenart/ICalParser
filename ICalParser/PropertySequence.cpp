module Ast;

import std.core;

namespace ast {

PropertySequence::PropertySequence(long long val)
	: PropertyInt(val)
{
}

void PropertySequence::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_sequence(*this);
}

}
