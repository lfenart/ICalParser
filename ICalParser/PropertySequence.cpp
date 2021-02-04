module Ast;

import std.core;

namespace ast {

PropertySequence::PropertySequence(long long val, const std::map<std::string, std::string>& params)
	: PropertyInt(val, params)
{
}

void PropertySequence::accept(std::shared_ptr<Visitor> visitor) const
{
	visitor->visit_sequence(*this);
}

}
