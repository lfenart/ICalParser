module Exception;

import std.core;

namespace exception {

UnknownPropertyError::UnknownPropertyError(std::string prop)
	: std::runtime_error("Unknown property: " + prop)
{
}

}
